#pragma once
////#ifndef __MACHINE
////#define __MACHINE
//
//// Standard:
#include <string>
#include <iostream>
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
#include "any.hxx"
//#include "../containers/memory.h++"
#include "db/sqlite.hxx"

// #include "container/entity_2.h++"

//#include "../mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "machine.h++" file.
//#include "../machine/resource.h++"
////#include "../machine/resources.h++"
//#include "../machine/resources/memory.h++"
//#include "../machine/resources/processor.h++"
////#include "members.h++"
//// #include "../containers/entity.h++"
////#include "../network/ip/mpi.h++"
// #include "net/mpi.hxx"
////#include "../language/interpreter.h++"
//#include "../communication/messaging.h++"
//#include "../cluster/members.h++"
////#include "../cluster.h++"
//#include "network.h++"
// #include ".machine/preindex.h++"
//
////#ifndef NTT
////	#define NTT entity
////#endif

namespace noware
{
	// aware[ness] consc[iousness] [(artificial/synthetic) ]intel[ligence]
	// calculator comp[uter][pc] mach[ine] rob[ot]
	// device
	class computer
	{
		/*
			Do not hurt.
			~Do not lie.
			Protect.
			Help.
			[The 10 Commandments]
		*/
		
		/*
			1. Resource Sharing (Server)	--Machine
			2. Virtual Machine (Client)		--Machine
			3. Logic (Applied Usage)			--Computer
			
			
			OR?
			
			1. Logic
			2. Resource
			3. VM
			
		*/
		
		public:
			//#include ".machine/index.h++"
			
			computer (void);
			~computer (void);
			
			// do evaluate compute solve perform process execute query enqueue go ok request demand command input
			//const LIB::containers::NAME_V query (const LIB::containers::NAME_V &);
			//const bool evaluate (const LIB::containers::NAME_V &);
			const any evaluate (const any &/* expression*/);
			//const bool good (/*action?*/);	// determine good(?) judge
			
			// The initial SQL query.
			static const std::string query_sql_initial;
			//static const std::string sql1;
		// protected:
		public:
		//	/*LIB::machine::*/device::processor processor;
				//LIB::container::memory memory;
			//	LIB::container::entity_2 memory;
			//LIB::network::mpi mpi;
			//db::sqlite memory {"science.db"};
			db::sqlite knowledge;	// knowledge science memory storage
		//public:
			//#include ".machine/postinnerindex.h++"
	};
}

//#include ".machine/postindex.h++"

