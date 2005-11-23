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

#include<libmutil/MemObject.h>
#include<libmutil/Mutex.h>
#include<string>

#include<typeinfo>

using namespace std;

#ifdef MDEBUG
#include<libmutil/itoa.h>
Mutex global;
minilist<MObject *> objs;
int ocount=0;
bool outputOnDestructor=false;
#endif

MObject::MObject() : refCount(0){
#ifdef MDEBUG
	global.lock();
	ocount++;
	//cerr << "MObject:: SipSMCommand created; ptr=" << itoa((int)this) << endl;
	objs.push_front(this);
	global.unlock();
#endif
}

MObject::~MObject(){
#ifdef MDEBUG
	global.lock();
	for (int i=0; i<objs.size(); i++){
		if (this == objs[i]){
			objs.remove(i);
			ocount--;
			break;
		}
	}
	global.unlock();
#endif
}

int MObject::decRefCount(){
	int refRet;
#ifdef MDEBUG
	global.lock();
#else
	refLock.lock();
#endif
	
	refCount--;
	refRet = refCount;
	
#ifdef MDEBUG
	global.unlock();
	if (refRet==0 && outputOnDestructor){
		string output = "MO (--):"+getMemObjectType()+ "; count=" + itoa(refRet) + "; ptr=" + itoa((int)this);
		cerr << output << endl;
	}
#else
	refLock.unlock();
#endif
	return refRet;
}

void MObject::incRefCount(){
#ifdef MDEBUG
	global.lock();
#else
	refLock.lock();
#endif
	
	refCount++;
	
#ifdef MDEBUG
	global.unlock();
	//if (outputOnDestructor ){
	if (refCount == 1 && outputOnDestructor ){
		string output = "MO (++):"+getMemObjectType()+ "; count=" + itoa(refCount);
		cerr << output << endl;
	}
#else
	refLock.unlock();
#endif
}

int MObject::getRefCount(){
	return refCount;
}

string MObject::getMemObjectType(){
#ifdef MDEBUG
	return (typeid(*this)).name();
#else
	return "(unknown)";
#endif
}

minilist<string> getMemObjectNames(){
#ifdef MDEBUG
	minilist<string> ret;
	global.lock();
	for (int i=0; i< objs.size(); i++){
		int count = objs[i]->getRefCount();
		string countstr = count?itoa(count):"on stack"; 
		ret.push_back(objs[i]->getMemObjectType()+"("+countstr+")" + "; ptr=" + itoa((int)objs[i]) );
	}
	global.unlock();
	return ret;
#else
	minilist<string> ret;
	return ret;
#endif
}

int getMemObjectCount(){
#ifdef MDEBUG
	return ocount;
#else
	return -1;
#endif
}

bool setDebugOutput(bool on){
#ifdef MDEBUG
	outputOnDestructor=on;
	return true;
#else
	return false;
#endif
}

bool getDebugOutputEnabled(){
#ifdef MDEBUG
	return outputOnDestructor;
#else
	return false;
#endif
}

