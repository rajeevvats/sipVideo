/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* Copyright (C) 2004 
 *
 * Authors: Erik Eliasson <eliasson@it.kth.se>
 *          Johan Bilien <jobi@via.ecp.fr>
*/

/* Name
 * 	SipHeaderSubject.h
 * Author
 * 	Erik Eliasson, eliasson@it.kth.se
 * Purpose
 * 
*/

#ifndef SIPHEADERUNSUPPORTED_H
#define SIPHEADERUNSUPPORTED_H

#include<libmsip/SipHeader.h>

/**
 * @author Erik Eliasson
*/

class SipHeaderUnsupported: public SipHeader{
	public:
		SipHeaderUnsupported(const string &build_from);

		virtual ~SipHeaderUnsupported();

                virtual std::string getMemObjectType(){return "SipHeaderUnsupported";}
		
		/**
		 * returns string representation of the header
		 */
		string getString(); 

	private:
		string string_data;
};

#endif
