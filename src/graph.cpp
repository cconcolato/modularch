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

#include "graph.hpp"

//FIXME: hardcoded
#include "mp4_simple.hpp"


namespace ModulArch {
	
Graph::Graph() {
}

Graph *Graph::create() {
	return new Graph();
}

bool Graph::run(const bool sync) {
	return true;
}

void Graph::stop() {
}

bool Graph::createModule(const std::string& url) {
	//TODO: if "is a file", then:
	return addModule(MP4_Simple::create());
}

bool Graph::addModule(Module *module) {
	//TODO
	return true;
}

}
