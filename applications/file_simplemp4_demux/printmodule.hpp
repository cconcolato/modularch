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

#ifndef _MODULARCH_PRINTMODULE_HPP_
#define _MODULARCH_PRINTMODULE_HPP_

#include <modularch/modularch.hpp>


namespace ModulArch {

class PrintModule : public Module {
public:
	static PrintModule* create() {
		return new PrintModule();
	}

	std::vector<char*>& process(std::vector<char*> &in) {
		Log::get(Log::Error) << "PrintModule: received data of size: " << in.size() << std::endl;
		//FIXME: implicit passthru
		return in;
	}

	static bool handles(const std::string &url) {
		return true;
	}

private:
	PrintModule() {}
};

}

#endif
