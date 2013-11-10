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

#ifndef _MODULARCH_GRAPH_HPP_
#define _MODULARCH_GRAPH_HPP_

#include "config.hpp"
#include "module.hpp"

#include <iostream>
#include <list>


namespace ModulArch {

class EXPORT Graph {
public:
	static Graph *create();
	~Graph();
	bool run(bool sync); //sync deserves an enum: event loop thread, theading model
	void stop();

	//TODO: since this is std graph management, move it in a separate class
	bool createModule(const std::string &url);

	//take module ownership //FIXME: leaks
	bool addModule(Module *module);

private:
	Graph();

	std::list<Module*> modules; //TODO: graph  +  provide an impl to remove the warning.
};

}

#endif
