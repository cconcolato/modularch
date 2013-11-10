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

#ifndef _MODULARCH_LIBAVFORMAT_55_HPP_
#define _MODULARCH_LIBAVFORMAT_55_HPP_

#include <modularch/log.hpp>
#include <modularch/module.hpp>

struct AVFormatContext;
struct AVPacket;


namespace ModulArch {

class Libavformat_55 : public Module {
public:
	static Libavformat_55* create(const std::string &url) ;
	std::vector<char*>& process(std::vector<char*> &in);
	static bool canHandle(const std::string &url);

private:
	Libavformat_55(struct AVFormatContext *formatCtx);
	~Libavformat_55();

  struct AVFormatContext *formatCtx;
  struct AVPacket *pkt;
};

}

#endif

