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

#include "event.hpp"

//FIXME: hardcoded -> module manager needed
#include "modules/in/file.hpp"
#include "modules/demux/gpac_mp4_simple.hpp"
#include "modules/demux/libavformat_55.hpp"


namespace ModulArch {
	
Graph::Graph() {
}
	
Graph::~Graph() {
	for (auto eventManager=eventManagers.begin(); eventManager!=eventManagers.end(); ++eventManager) {
		delete (*eventManager);
	}
}

Graph* Graph::create() {
	return new Graph();
}

bool Graph::run(const bool sync) {
	if (!sync) {
		//TODO: async
		return false;
	} else {
		Event<void*> e(Event<void*>::Process, "", NULL);
		for (auto eventManager=eventManagers.begin(); eventManager!=eventManagers.end(); ++eventManager) {
			bool res;
			do {
				res = (*eventManager)->process(e);
			} while (res);
		}
	}

	return true;
}

void Graph::stop() {
}

bool Graph::createModule(EventManager &eventManager, const std::string &url) {
	if (GPAC_MP4_Simple::canHandle(url)) {
		return addModule(GPAC_MP4_Simple::create(eventManager, url));
	} else if (Libavformat_55::canHandle(url)) {
		return addModule(Libavformat_55::create(eventManager, url));
	} else if (File::canHandle(url)) {
		return addModule(File::create(eventManager, url));
	} else {
		return false;
	}
}

bool Graph::addModule(Module *module) {
	eventManagers.insert(&module->getEventManager());
	return true;
}

}
