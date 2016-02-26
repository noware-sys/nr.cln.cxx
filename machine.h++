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
#include "name.h++"
////#include "peers.h++"
//#include "../containers/array.h++"
#include "../container/variable.h++"
//#include "../containers/memory.h++"
#include "../container/entity_2.h++"
//#include "../mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "machine.h++" file.
//#include "../machine/resource.h++"
////#include "../machine/resources.h++"
//#include "../machine/resources/memory.h++"
//#include "../machine/resources/processor.h++"
////#include "members.h++"
//// #include "../containers/entity.h++"
////#include "../network/ip/mpi.h++"
#include "network/mpi.h++"
////#include "../language/interpreter.h++"
//#include "../communication/messaging.h++"
//#include "../cluster/members.h++"
////#include "../cluster.h++"
//#include "network.h++"
#include ".machine/index-pre.h++"
//
////#ifndef NTT
////	#define NTT entity
////#endif

namespace LIB
{
	class machine
	{
		/*
			Do not hurt.
			~Do not lie.
			Protect.
			Help.
			[The 10 Commandments]
		*/
		
		/*
			Resource Sharing
			Virtual Machine
			Logic
		*/
		
		public:
			#include ".machine/index.h++"
			
			machine (void);
			~machine (void);
			
			// do evaluate compute solve perform process execute query enqueue go ok request demand command input
			//const LIB::containers::NAME_V query (const LIB::containers::NAME_V &);
			//const bool evaluate (const LIB::containers::NAME_V &);
			const LIB::container::NAME_V evaluate (const LIB::container::NAME_V &);
			
		protected:
			/*LIB::machine::*/resource::processor processor;
				//LIB::container::memory memory;
			//	LIB::container::entity_2 memory;
			//LIB::network::mpi mpi;
	};
}

