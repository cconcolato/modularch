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

#ifndef _MODULARCH_EVENT_HPP_
#define _MODULARCH_EVENT_HPP_

#include "config.hpp"
#include "graph.hpp"
#include "module.hpp"

#include <cassert> //TODO: remove when no code in the header anymore...
#include <cstdint>
#include <list>
#include <string>


namespace ModulArch {

//TODO: I could have named it "attribute", was it for the enum Type...
template<typename T>
class Event {
public:
	enum Type {
		Connection = 0, /*request a connection*/
		Dispatch,       /*dispatch data to its connections*/
		Process         /*process the data*/
	};
	
	Event(Type type, const std::string &name, const T &value)
	: type(type), name(name), value(value) {
		uid = EventManager::g_uid++;
	}

	Type getType() const {
		return type;
	}

	std::string getName() const {
		return name;
	}

private:
	Event();
	uint64_t uid;
	Type type;
	std::string name;
	T value;
};

typedef uint64_t UID;

//TODO: really looks like a module
class EXPORT EventManager {
public:
	static EventManager* create() {
		return new EventManager();
	}

	void addModule(Module *module) {
		modules.push_back(module);
	}

	template<typename T>
	bool process(const Event<T> &e) {
		switch (e.getType()) {
			case Event<T>::Connection:
				return connectInternal(e);
			case Event<T>::Dispatch:
				return dispatchInternal(e);
			case Event<T>::Process:
				return processInternal(e);
		}

		return false;
	}

	static UID g_uid;//TODO: improve

private:
	EventManager() {
	}

	template<typename T>
	bool connectInternal(const Event<T> &e) {
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

	template<typename T>
	bool dispatchInternal(const Event<T> &e) {
		assert(0); //TODO
		return true;
	}

	template<typename T>
	bool processInternal(const Event<T> &e) {
		assert(0); //TODO
		return true;
	}

	/**
	 * Events to be processed by this event manager.
	 */
	//Romain: std::queue<> events;

	/**
	 * Modules managed by this event manager.
	 */
	std::list<Module*> modules;
};

}

#endif
