/*
 *			Authors: Romain Bouqueau
 *			Copyright (c) Romain Bouqueau 2013
 *					All rights reserved
 *
 *  This file is part of Modularch
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *   
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *   
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 */

#include "gpac_mp4_simple.hpp"

#include <string>


namespace ModulArch {

GPAC_MP4_Simple* GPAC_MP4_Simple::create(const std::string &fn) {
	/* The ISO progressive reader */
	GF_ISOFile *movie;
	/* Number of bytes required to finish the current ISO Box reading */
	u64 missing_bytes;

	GF_Err e = gf_isom_open_progressive(fn.c_str(), 0, 0, &movie, &missing_bytes);
	if ((e != GF_OK && e != GF_ISOM_INCOMPLETE_FILE) || movie == NULL) {
		Log::get(Log::Error) << "Could not open file " << fn << " for reading (" << gf_error_to_string(e) << ")." << std::endl;
		return NULL;
	}

	return new GPAC_MP4_Simple(movie);
}

void GPAC_MP4_Simple::deleteLastSample() {
	if (iso_sample) {
		//invalidate the previous data and delete the sample.
		iso_sample->data = NULL;
		iso_sample->dataLength = 0;
		gf_isom_sample_del(&iso_sample);
	}
}

GPAC_MP4_Simple::GPAC_MP4_Simple(GF_ISOFile *movie)
  : movie(movie), iso_sample(NULL) {
	u32 track_id = gf_isom_get_track_id(movie, 1); //FIXME should be a parameter? hence not processed in create() but in a stateful process? or a control module?
	track_number = gf_isom_get_track_by_id(movie, track_id);
	if (track_number == 0) {
		Log::get(Log::Error) << "Could not find track ID=" << track_id << std::endl;
	}
	sample_count = gf_isom_get_sample_count(movie, track_number);
	sample_index = 1;
}

GPAC_MP4_Simple::~GPAC_MP4_Simple() {
	deleteLastSample();

	gf_isom_close(movie);
}

std::vector<char*>& GPAC_MP4_Simple::process(std::vector<char*> &in) {
	deleteLastSample();

	u32 sample_description_index;
	iso_sample = gf_isom_get_sample(movie, track_number, sample_index, &sample_description_index);
	if (iso_sample) {
		Log::get(Log::Error) << "Found sample #" << sample_index << "/" << sample_count << " of length " << iso_sample->dataLength << ", RAP: " << iso_sample->IsRAP << ", DTS: " << iso_sample->DTS << ", CTS: " << iso_sample->DTS+iso_sample->CTS_Offset << std::endl;
		in.resize(iso_sample->dataLength);
		memcpy(&in[0], iso_sample->data, iso_sample->dataLength);
		sample_index++;

		/*release the sample data, once you're done with it*/
		//FIXME: embed it in the allocator: gf_isom_sample_del(&iso_sample);
	} else {
		GF_Err e = gf_isom_last_error(movie);
		if (e == GF_ISOM_INCOMPLETE_FILE) {
			u64 missing_bytes = gf_isom_get_missing_bytes(movie, track_number);
			Log::get(Log::Error) << "Missing " << missing_bytes << " bytes on input file" << std::endl;
			//TODO: ask for a timer delay? gf_sleep(1000);
		}
	}
	return in;
}

bool GPAC_MP4_Simple::canHandle(const std::string &url) {
	if (url.find_last_of("mp4")+1 == url.size()) {
		return true;
	} else {
		return false;
	}
}

}

