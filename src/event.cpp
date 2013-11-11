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
	
uint64_t EventManager::g_uid = 0;

#if 0
template <typename T>
Event<T>::Event(Type type, const std::string &name, const T &value)
	: type(type), name(name), value(value) {
  uid = EventManager::g_uid++;
}

template<typename T>
typename Event<T>::Type Event<T>::getType() const {
	return type;
}

template<typename T>
bool EventManager::dispatch(const Event<T> &e) {
	assert(0); //TODO
	return true;
}

template<typename T>
bool EventManager::connect(const Event<T> &e) {
	assert(0); //TODO
	return true;
}

template<typename T>
bool EventManager::process(const Event<T> &e) {
	switch (e.getType()) {
		case Event<T>::Connection:
			return connect(e);
		case Event<T>::Dispatch:
			return dispatch(e);
	}

	return false;
}
#endif

}

