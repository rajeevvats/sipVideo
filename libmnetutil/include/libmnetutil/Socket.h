/*
  Copyright (C) 2005, 2004 Erik Eliasson, Johan Bilien
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
 * Authors: Erik Eliasson <eliasson@it.kth.se>
 *          Johan Bilien <jobi@via.ecp.fr>
*/


#ifndef SOCKET_H
#define SOCKET_H

//#include<config.h>


#define SOCKET_TYPE_STREAM	0x10
#define SOCKET_TYPE_TCP		0x11
#define SOCKET_TYPE_TLS		0x12

#define SOCKET_TYPE_UDP		0x20

#include<stdint.h>
#include<libmutil/MemObject.h>

class Socket : public MObject{
	public:
		virtual int32_t getFd();
		int32_t getType();

		void close();
		virtual std::string getMemObjectType(){return "Socket";};
	
	protected:
		int32_t type;
		int32_t fd;
};

#endif
