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
#include "data.hpp"

#include <cassert> //TODO: remove when no code in the header anymore...
#include <cstdint>
#include <list>
#include <string>


namespace ModulArch {

//TODO: I could have named it "attribute", was it for the enum Type...
class Event {
public:
	enum Type {
		Connection = 0, /*request a connection*/
		Dispatch,       /*dispatch data to its connections*/
		Process         /*process the data*/
	};
	
	Event(Type type, const std::string &name, Data &value);

	Type getType() const;
	std::string getName() const;

private:
	Event();
	uint64_t uid;
	Type type;
	std::string name;
	Data &value;
};

typedef uint64_t UID;

//TODO: really looks like a module
class EXPORT EventManager {
public:
	static EventManager* create();

	void addModule(Module *module);

	bool process(const Event &e);

	static UID g_uid;//TODO: improve

private:
	EventManager();

	bool connectInternal(const Event &e);
	bool dispatchInternal(const Event &e);
	bool processInternal(const Event &e);

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
