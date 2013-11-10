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

#include <modularch/log.hpp>

#include "file.hpp"


#define IOSIZE 16384


namespace ModulArch {
	
File::File(FILE *file)
	: file(file) {
}
	
File::~File() {
	fclose(file);
}

File* File::create(const std::string &fn) {
	FILE *f = fopen(fn.c_str(), "rb");
	if (!f) {
		Log::get(Log::Error) << "Can't open file: " << fn << std::endl;
		return NULL;
	} else {
		return new File(f);
	}
}

std::vector<char*>& File::process(std::vector<char*> &in) {
	if (in.size()) {
		//FIXME
		Log::get(Log::Error) << "Module File doesn't take any input!" << std::endl;
		in.clear();
	}

	std::vector<char*> &data = in;
	data.resize(IOSIZE);
	size_t read = fread(data.data(), 1, IOSIZE, file);
	if (read < IOSIZE) {
		data.resize(read);
	}

	return data;
}

bool File::handles(const std::string &url) {
	return true;
}

}

