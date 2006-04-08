/*
  Copyright (C) 2006, Erik Eliasson
  
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
*/


#ifndef SIPLAYERTRANSACTION 
#define SIPLAYERTRANSACTION 

#include<libmsip/libmsip_config.h>

#include<libmsip/SipSMCommand.h>

#include<list>
#include<libmutil/Mutex.h>
#include<libmutil/MemObject.h>
#include<libmutil/minilist.h>
//#include<libmsip/SipTransaction.h>

class SipCommandDispatcher;
class SipTransaction;
class SipLayerTransport;

class LIBMSIP_API SipLayerTransaction: public SipSMCommandReceiver{
	public:
		SipLayerTransaction(MRef<SipCommandDispatcher*> dispatcher, MRef<SipLayerTransport*> transp);

		void doHandleAck(bool b){handleAck=b;}
		
		void removeTransaction(MRef<SipTransaction*> t);
		MRef<SipTransaction*> findTransaction(std::string branch);

		void removeTerminatedTransactions();
		
		std::list<MRef<SipTransaction*> > getTransactionsWithCallId(std::string callid);
		
//#ifdef DEBUG_OUTPUT
		virtual std::string getMemObjectType() {return "SipLayerTransaction";}
//#endif
		
		virtual bool handleCommand(const SipSMCommand &cmd);
		

		//void sendToTU(const SipSMCommand &cmd);
		
	private:
		void addTransaction(MRef<SipTransaction*> t);

		bool defaultCommandHandler(const SipSMCommand &cmd);
		
		bool handleAck;
		
		minilist<MRef<SipTransaction*> > transactions;

		MRef<SipCommandDispatcher*> dispatcher;
		MRef<SipLayerTransport*> transportLayer;
		
		//Mutex transactionListLock;
};

#endif
