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

#ifndef _MODULARCH_MP4_SIMPLE_HPP_
#define _MODULARCH_MP4_SIMPLE_HPP_

#include <log.hpp>
#include <module.hpp>

extern "C" {
#include <gpac/tools.h>
#include <gpac/isomedia.h>
}


namespace ModulArch {

class MP4_Simple : public Module {
public:
	static MP4_Simple* create(const std::string &fn) ;
	std::vector<char*>& process(std::vector<char*> &in);
	static bool handles(const std::string &url);

private:
	MP4_Simple(GF_ISOFile *movie);
	~MP4_Simple();

	void deleteLastSample();

	GF_ISOFile *movie;
	u32 track_number;

	GF_ISOSample *iso_sample;
	u32 sample_index, sample_count;
};

}

#endif

