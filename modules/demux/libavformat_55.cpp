/*
 *			Authors: Romain Bouqueau
 *			Copyright (c) Romain Bouqueau 2013
 *					All rights reserved
 *
 *  This file is part of Modularch
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *   
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *   
 *  You should have received a copy of the GNU General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 */

#include <modularch/data.hpp>
#include <modularch/event.hpp>
#include <modularch/utils.hpp>

#include "libavformat_55.hpp"

#include <cassert>
#include <string>

extern "C" {
#include <libavformat/avformat.h>
}


namespace ModulArch {

Libavformat_55* Libavformat_55::create(EventManager &eventManager, const std::string &url) {
	std::ostream& errorLog = Log::get(Log::Error);
	struct AVFormatContext *formatCtx = NULL;

	av_register_all();
	//TODO: custom log: av_log_set_callback(avlog);

	if (!(formatCtx = avformat_alloc_context())) {
		errorLog << "Module Libavformat_55: Can't allocate format context" << std::endl;
		return NULL;
	}

	if (avformat_open_input(&formatCtx, url.c_str(), NULL, NULL))  {
		errorLog << "Module Libavformat_55: Error when initializing the format context" << std::endl;
		return NULL;
	}

	return new Libavformat_55(eventManager, formatCtx);
}

void Libavformat_55::newAVPacketInternal() {
  pkt = new AVPacket;
	av_init_packet(pkt);
	av_free_packet(pkt);
}

Libavformat_55::Libavformat_55(EventManager &eventManager, struct AVFormatContext *formatCtx)
	: Module(eventManager), formatCtx(formatCtx) {
	newAVPacketInternal();

	for (unsigned i=0; i<formatCtx->nb_streams; i++) {
		switch (formatCtx->streams[i]->codec->codec_type) {
			case AVMEDIA_TYPE_VIDEO:
			case AVMEDIA_TYPE_AUDIO:
			case AVMEDIA_TYPE_DATA:
			case AVMEDIA_TYPE_SUBTITLE:
			case AVMEDIA_TYPE_ATTACHMENT:
			{
				AVCodec *codec = avcodec_find_decoder(formatCtx->streams[i]->codec->codec_id);
				Event<void*> e(Event<void*>::Connection, codec->name/*toStdString(i)*/, NULL);
				if (!getEventManager().process(e)) {
					Log::get(Log::Error) << "Module Libavformat_55: could not connect codec \"" << formatCtx->streams[i]->codec->codec_name << "\"." << std::endl;
				  //TODO: throw exception, or ignore, or ...
				}
				//FIXME: no way to remove it from libav API? avcodec_close(codec);
				break;
			}
			default:
				assert(0);
				continue;
		}
	}
}

Libavformat_55::~Libavformat_55() {
	if (formatCtx) {
		avformat_close_input(&formatCtx);
	}
	delete pkt;
}

void Libavformat_55::dispatchInternal() {
	typedef Data<AVPacket> T;
	T *data = new T(pkt->data, pkt->size, av_free_packet, pkt);
	Event<T*> e(Event<T*>::Dispatch, toStdString(pkt->stream_index), data);
	newAVPacketInternal();
}

std::vector<char*>& Libavformat_55::process(std::vector<char*> &in) {
	if (in.size()) {
		//FIXME
		Log::get(Log::Error) << "Module Libavformat_55 doesn't take any input buffer!" << std::endl;
		in.clear();
	}

	int status = 0;
	while (status >= 0) {
		if (!pkt->size) {
			//read data from media
			status = av_read_frame(formatCtx, pkt);
			if (status < 0) {
				if (status == (int)AVERROR_EOF || (formatCtx->pb && formatCtx->pb->eof_reached)) {
					Log::get(Log::Info) << "Module Libavformat_55: end of file reached" << std::endl;
					return in; //should return an error
				} else if (formatCtx->pb && formatCtx->pb->error) {
					Log::get(Log::Warning) << "Module Libavformat_55: stream contains an irrecoverable error - leaving" << std::endl;
					return in; //should return an error
				} else {
					continue;
				}
			}
		}

		//dispatch to the right pin
		dispatchInternal();
		break;
	}

	return in;
}

bool Libavformat_55::handles(const std::string &url) {
	return Libavformat_55::canHandle(url);
}

bool Libavformat_55::canHandle(const std::string &url) {
	AVProbeData pd;
	const size_t size = 4096;

	pd.buf = new unsigned char[size+AVPROBE_PADDING_SIZE];
	pd.filename = NULL;

	FILE *f = fopen(url.c_str(), "rb");
	if (!f) {
		Log::get(Log::Warning) << "Module Libavformat_55: Couldn't open URL " << url.c_str() << " for probing. Aborting." << std::endl;
		delete[] pd.buf;
		return false;
	}
	size_t bytesRead = fread(pd.buf, 1, size, f);
	pd.buf_size = (int)bytesRead;
	fclose(f);
	if (bytesRead<size) {
		Log::get(Log::Warning) << "Module Libavformat_55: Could only read " << bytesRead << "bytes (instead of " << size << ") for probing format." << std::endl;
	}
	memset(pd.buf+bytesRead, 0, AVPROBE_PADDING_SIZE);

	av_register_all();
	
	AVInputFormat *format = av_probe_input_format(&pd, 1);
	delete[] pd.buf;

	if (!format)
		return false;
	else
		return true;
}

}

