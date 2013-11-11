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

#ifndef _MODULARCH_MODULE_HPP_
#define _MODULARCH_MODULE_HPP_

#include "config.hpp"

#include <queue>
#include <vector>


namespace ModulArch {

class EventManager;

class EXPORT Module {
public:
	Module(EventManager &eventManager);

	/**
	 * The data is allocated here when needed, and deleted here once used. FIXME: move to an allocator.
	 * Return true when data were processed.
	 */
	virtual std::vector<char*>& process(std::vector<char*> &in) = 0;
	virtual bool handles(const std::string &url) = 0;
	
	EventManager& getEventManager() const;

private:
	EventManager &eventManager;
	//std::queue<void/*Romain: FIXME*/> input; //TODO: change process above
};

}

#endif
