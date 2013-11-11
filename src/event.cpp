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

#include "event.hpp"


namespace ModulArch {

Event::Event(Type type, const std::string &name, Data &value)
: type(type), name(name), value(value) {
	uid = EventManager::g_uid++;
}

Event::Type Event::getType() const {
	return type;
}

std::string Event::getName() const {
	return name;
}

	
uint64_t EventManager::g_uid = 0;

EventManager* EventManager::create() {
	return new EventManager();
}

void EventManager::addModule(Module *module) {
	modules.push_back(module);
}

bool EventManager::process(const Event &e) {
	switch (e.getType()) {
		case Event::Connection:
			return connectInternal(e);
		case Event::Dispatch:
			return dispatchInternal(e);
		case Event::Process:
			return processInternal(e);
	}

	return false;
}

EventManager::EventManager() {
}

bool EventManager::connectInternal(const Event &e) {
	Module *module = NULL;
	//Do we carry a module able to handle this type?
	for (auto m=modules.begin(); m!=modules.end(); ++m) {
		if ((*m)->handles(e.getName())) {
			module = *m;
			break;
		}
	}
	if (!module) {
#if 0 //Romain: TODO: don't have access right now, no module manager.
		//Look in buildtins modules
		module = Graph::createModule(*this, e.getName());
		if (!module) {
			Log::get(Log::Warning) << "Could not find any module for \"" << e.getName() << "\"." << std::endl;
			assert(0);//we should have a default sink to avoid to leak
			return false;
		}
#else
		return false;
#endif
	}
	return true;
}

bool EventManager::dispatchInternal(const Event &e) {
	assert(0); //TODO
	return true;
}

bool EventManager::processInternal(const Event &e) {
	assert(0); //TODO
	return true;
}

}

