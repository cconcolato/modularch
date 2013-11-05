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

#include <modularch.hpp>
#include "printmodule.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	bool sync;
	std::string fn;

	//TODO: parse args
	sync = true;
	if (argc < 2) {
		ModulArch::Log::get(ModulArch::Log::Error) << "You must provide at least one argument" << std::endl;
		return 1;
	}
	fn = argv[0];

	//create a graph
	ModulArch::Graph *graph = ModulArch::Graph::create();
	if (!graph) {
		ModulArch::Log::get(ModulArch::Log::Error) << "Can't create graph" << std::endl;
		return 1;
	}

	//create modules from built-ins
	if (!graph->createModule(fn)) {
		ModulArch::Log::get(ModulArch::Log::Error) << "Can't create a module for " << fn.c_str() << std::endl;
		return 1;
	}

	//add custom module
	if (!graph->addModule(ModulArch::PrintModule::create())) {
		ModulArch::Log::get(ModulArch::Log::Error) << "Can't add PrintModule to the graph" << std::endl;
		return 1;
	}
	
	//resolve and run the graph
	if (!graph->run(sync)) {
		ModulArch::Log::get(ModulArch::Log::Error) << "Can't run the graph" << std::endl;
		return 1;
	}

	//synchronize and stop
	graph->stop();

	delete graph;

	return 0;
}