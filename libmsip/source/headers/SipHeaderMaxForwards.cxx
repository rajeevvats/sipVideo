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
 * 	SipHeaderMaxForwards.cxx
 * Author
 * 	Erik Eliasson, eliasson@it.kth.se
 * Purpose
 * 
*/

#include<config.h>

#include<libmsip/SipHeaderMaxForwards.h>

#include<libmutil/itoa.h>
#include<libmutil/trim.h>


SipHeaderMaxForwards::SipHeaderMaxForwards(const string &build_from)
		: SipHeader(SIP_HEADER_TYPE_MAXFORWARDS),
		max(-1)
{
	max = atoi( trim( build_from.substr(13) ).c_str()); //strlen("max-forwards:")==13
}

SipHeaderMaxForwards::SipHeaderMaxForwards(int32_t mf)
		: SipHeader(SIP_HEADER_TYPE_MAXFORWARDS),
		max(mf)
{
}

SipHeaderMaxForwards::~SipHeaderMaxForwards(){
}

string SipHeaderMaxForwards::getString(){
	return "Max-Forwards: "+itoa(max);
}

int32_t SipHeaderMaxForwards::getMaxForwards(){
	return max;
}
		
void SipHeaderMaxForwards::setMaxForwards(int32_t m){
	max=m;
}

