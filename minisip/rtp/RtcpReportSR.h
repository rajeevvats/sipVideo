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

#ifndef RTCPREPORTSR_H
#define RTCPREPORTSR_H

#include"RtcpReport.h"
#include"RtcpReportReceptionBlock.h"
#include"RtcpReportSenderInfo.h"
#include<vector>
#include<config.h>

using namespace std;

class RtcpReportSR : public RtcpReport{
	public:
		RtcpReportSR(unsigned ssrc);
		
		RtcpReportSR(void * build_from, int max_length);
		virtual ~RtcpReportSR();
//		virtual vector<unsigned char> get_packet_bytes();
		virtual int size();
		
#ifdef DEBUG_OUTPUT
		virtual void debug_print();
#endif

		RtcpReportSenderInfo &get_sender_info();

		int get_n_report_blocks();
		
		RtcpReportReceptionBlock &get_reception_block(int i);
		
		
		
	private:
		unsigned sender_ssrc;
		//----------------
//		unsigned ntp_msw;
//		unsigned ntp_lsw;
//		unsigned rtp_timestamp;
//		unsigned sender_packet_count;
//		unsigned sender_octet_count;
		RtcpReportSenderInfo sender_info;
		vector<RtcpReportReceptionBlock>reception_blocks;

		
};

#endif
