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


#include<config.h>

#include<libmnetutil/StreamSocket.h>
#include<libmnetutil/IPAddress.h>

using namespace std;

StreamSocket::~StreamSocket(){
}

bool StreamSocket::matchesPeer(IPAddress& address, int32_t port){
	#ifdef DEBUG_OUTPUT
// 	cerr << "StreamSocket:matchesPeer: 1 - " << address.getString() << ":" << port << endl;
// 	cerr << "StreamSocket:matchesPeer: 2 - " << getPeerAddress()->getString() << ":" << getPeerPort() << endl;
	#endif
	return **peerAddress == address && port == peerPort;
}

bool StreamSocket::matchesPeer(string address, int32_t port){
	#ifdef DEBUG_OUTPUT
// 	cerr << "StreamSocket:matchesPeer: 1 - " << address.getString() << ":" << port << endl;
// 	cerr << "StreamSocket:matchesPeer: 2 - " << getPeerAddress()->getString() << ":" << getPeerPort() << endl;
	#endif
	if (remoteHostUnresolved.size()>0){
		return remoteHostUnresolved==address && port==peerPort;
	}else{
		return **peerAddress == **(IPAddress::create(address)) && port==peerPort;
	}
}

MRef<IPAddress *> StreamSocket::getPeerAddress(){
	return peerAddress;
}

int32_t StreamSocket::getPeerPort(){
	return peerPort;
}

