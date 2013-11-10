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

#include "graph.hpp"

//FIXME: hardcoded -> module manager needed
#include "modules/in/file.hpp"
#include "modules/demux/gpac_mp4_simple.hpp"
#include "modules/demux/libavformat_55.hpp"


namespace ModulArch {
	
Graph::Graph() {
}
	
Graph::~Graph() {
	for (auto module=modules.begin(); module!=modules.end(); ++module) {
		delete (*module);
	}
}

Graph* Graph::create() {
	return new Graph();
}

bool Graph::run(const bool sync) {
	if (!sync) {
		//TODO
		return false;
	} else {
		std::vector<char*> data;
		do {
			data.clear();
			for (auto module=modules.begin(); module!=modules.end(); ++module) {
				data = (*module)->process(data);
			}
		} while (data.size());
	}

	return true;
}

void Graph::stop() {
}

bool Graph::createModule(const std::string &url) {
	if (GPAC_MP4_Simple::canHandle(url)) {
		return addModule(GPAC_MP4_Simple::create(url));
	} else if (Libavformat_55::canHandle(url)) {
		return addModule(Libavformat_55::create(url));
	} else if (File::canHandle(url)) {
		return addModule(File::create(url));
	} else {
		return false;
	}
}

bool Graph::addModule(Module *module) {
	modules.push_back(module);
	return true;
}

}
