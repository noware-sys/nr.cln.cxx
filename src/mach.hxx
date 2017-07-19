#pragma once
////#ifndef __MACHINE
////#define __MACHINE
//
//// Standard:
//#include <string>
//#include <sstream>
//
//// Boost:
////#include <boost/any.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread.hpp>
//#include <boost/thread/mutex.hpp>
//#include <boost/thread/condition_variable.hpp>
//
//// This library:
////#include "Lexical_Analyzer"
//#include "../default.h++"
// #include "name.h++"
// #include "cotainer/null.h++"
////#include "peers.h++"
//#include "../containers/array.h++"
// #include "container/any.hxx"
//#include "../containers/memory.h++"
// #include "container/entity_2.hxx"
//#include "../mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "machine.h++" file.
//#include "../machine/resource.h++"
////#include "../machine/resources.h++"
//#include "../machine/resources/memory.h++"
//#include "../machine/resources/processor.h++"
////#include "members.h++"
//// #include "../containers/entity.h++"
////#include "../network/ip/mpi.h++"
// #include "net/mpi.hxx"
// #include "computer.hxx"
////#include "../language/interpreter.h++"
//#include "../communication/messaging.h++"
//#include "../cluster/members.h++"
////#include "../cluster.h++"
//#include "network.h++"
//#include ".machine/header.hxx"
//
////#ifndef NTT
////	#define NTT entity
////#endif

//#include "list.hdr.cxx"

/*
// For device.
#include "var.hxx"
#include "net/node.hxx"
#include "nr.hxx"
//// For devices.
//#include <zmqpp/zmqpp.hpp>
*/

/*
// For storage
#include <imatix/zyre/zyre.h>
#include <zmq.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//#include <boost/function_equal.hpp>
#include <boost/thread/mutex.hpp>
#include <cstring>	// For std::memcpy()
*/
//// For storage::sqlite
//#include "container/list/sqlite.hdr.cxx"

#include ".mach/.incl.hxx"

namespace noware
{
	// calculator computer mach[ine] robot
	// dev[ice]
	class mach
	{
		/*
			1. Resource Presentation/Aggregation/Sharing (Server) -- Machine (Physical Machine)
			2. Virtual Machine (Client) -- Machine (Software/Virtual Machine/OS)
			3. Logic (Applied Usage) -- Calculator/Computer (Software/OS/Application)
		*/
		
		public:
			#include ".mach/.hxx"
			
			mach (void);
			~mach (void);
			
			// do evaluate calculate compute solve perform process execute query enqueue go ok request demand command input
			//const LIB::containers::NAME_V query (const LIB::containers::NAME_V &);
			//const bool evaluate (const LIB::containers::NAME_V &);
		//	const LIB::container::NAME_V evaluate (const LIB::container::NAME_V &);
			
			const bool enqueue (const std::string &/* file_name*/);
			
			// copies copy redundancy
			//const noware::nr redundancy (void) const;
			//const bool redundancy (const noware::nr);
			
			//computer computer;
			
		// protected:
		public:
			store store;
			queue queue;
			cpu cpu;
			
			//std::map <std::string, thread *> trd;
			//thread trd;
			
			//array <device> device;
		//	/*LIB::machine::*//*device::*/processor processor;
				//LIB::container::memory memory;
			//	LIB::container::entity_2 memory;
			//LIB::network::mpi mpi;
			
			//manager mngr;
			//noware::list <manager> mngr;
			//noware::list <storage::sqlite> memory;
			//noware::list <processor> cpu;
			// display sight vision view
			//noware::list <display> view;
			// net network
			//noware::list <net> network;
			
		//public:
		//	#include ".machine/inner footer.hxx"
	};
}

//#include ".machine/footer.hxx"
