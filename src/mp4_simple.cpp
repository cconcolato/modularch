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

#include "mp4_simple.hpp"

#include <string>


namespace ModulArch {

MP4_Simple::MP4_Simple() {
}

MP4_Simple* MP4_Simple::create() {
	return new MP4_Simple();
}

std::vector<char*>& MP4_Simple::process(std::vector<char*> &in) {
	//TODO
	return in;
}

bool MP4_Simple::handles(const std::string &url) {
	if (url.find_last_of("mp4")+1 == url.size()) {
		return true;
	} else {
		return false;
	}
}

}

