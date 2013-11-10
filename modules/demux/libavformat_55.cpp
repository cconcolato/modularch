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

#include "libavformat_55.hpp"

#include <cassert>
#include <string>

extern "C" {
#include <libavformat/avformat.h>
}


namespace ModulArch {

Libavformat_55* Libavformat_55::create(const std::string &url) {
	std::ostream& errorLog = Log::get(Log::Error);
	struct AVFormatContext *formatCtx = NULL;

	av_register_all();
	//TODO: custom log: av_log_set_callback(avlog);

	if (!(formatCtx = avformat_alloc_context())) {
		errorLog << "[libavinput] Can't allocate format context" << std::endl;
		return NULL;
	}

	if (avformat_open_input(&formatCtx, url.c_str(), NULL, NULL))  {
		errorLog << "[libavinput] Error when initializing the format context" << std::endl;
		return NULL;
	}

	//find the first video stream
	//TODO: we should declare pins
	int videoIdx = formatCtx->nb_streams;
	for (unsigned i=0; i<formatCtx->nb_streams; i++) {
		if ((formatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) && (videoIdx == formatCtx->nb_streams)) {
			videoIdx = i;
		} else if (formatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
			//TODO
		}
	}

	return new Libavformat_55(formatCtx);
}

Libavformat_55::Libavformat_55(struct AVFormatContext *formatCtx)
	: formatCtx(formatCtx), pkt(new AVPacket) {
	av_init_packet(pkt);
	av_free_packet(pkt);
}

Libavformat_55::~Libavformat_55() {
	if (formatCtx) {
		avformat_close_input(&formatCtx);
	}
	delete pkt;
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

		//TODO: dispatch to the right pin
		in.resize(pkt->size);
		av_free_packet(pkt);
		break;
	}

	return in;
}

bool Libavformat_55::canHandle(const std::string &url) {
	AVProbeData pd;
	const size_t size = 4096;

	pd.buf = new unsigned char[size+AVPROBE_PADDING_SIZE];
	pd.filename = NULL;

	FILE *f = fopen(url.c_str(), "rb");
	if (!f) {
		Log::get(Log::Warning) << "[libavinput] Couldn't open URL " << url.c_str() << " for probing. Aborting." << std::endl;
		delete[] pd.buf;
		return false;
	}
	size_t bytesRead = fread(pd.buf, 1, size, f);
	pd.buf_size = (int)bytesRead;
	fclose(f);
	if (bytesRead<size) {
		Log::get(Log::Warning) << "[libavinput] Could only read " << bytesRead << "bytes (instead of " << size << ") for probing format." << std::endl;
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

