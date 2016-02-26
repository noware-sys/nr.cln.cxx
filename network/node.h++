#pragma once

#include <string>
#include <map>
//#include <list>
//#include <omp.h>

//#include <boost/any.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/system/error_code.hpp>
//#include <boost/system/system_error.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
#include <boost/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

#include "../value.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
//#include "machine.h++"
//#include ".node/preindex.h++" 
//#include "../machine/device.h++"
//#include "../machine/resource.h++"
//#include "../machine/resources.h++"
#include "../container/array.h++"
//#include "../container/variable.h++"
//#include "../container/entity.h++"
//#include "../cluster.h++"

//#include "../communication/messaging.h++"
// #include "../network/mpi.h++"
#include "ip.h++"
#include ".node/preindex.h++" 

namespace LIB
{
	namespace network
	{
			class node
			{
				public:
					friend class boost::serialization::access;
					
					#include ".node/index.h++"
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename archive>
					//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename archive>
					//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					node (void);
					node (const node &);
					~node (void);
					
					const node & operator = (const node &);
					const bool operator == (const node &) const;
					// Get the ID.
					//const LIB::mathemathics::numbers::natural & id (void) const;
					
					//LIB::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> addresses;
					LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> addresses;
					LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;
					//LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural> paths;
					//LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> paths;
					path paths;
					//LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> network_paths;
					
					/*
						State of availability :
						true : available
						false : unresponsive, timing out
					*/
					//bool available;	// available availability state
					static const unsigned short int/*LIB::mathematics::numbers::natural*/ default_keepalive;
					
					// Use this!:
					//LIB::mathematics::numbers::natural keepalive;
					// Not this! (Temporary only!):
					unsigned int keepalive;
					
					void function_timeout (LIB::container::NAME_A <node, LIB::mathematics::numbers::natural> &/*nodes*/, const LIB::mathematics::numbers::natural &/* key*/, const LIB::mathematics::numbers::natural &/* timeout (total)*/) const;
					//LIB::tools::randomizer randomizer;
			//	protected:
					boost::thread * thread_timeout;
					//LIB::mathematics::numbers::natural _id;
					
					// Generate unique ID.
					//const LIB::mathemathics::numbers::natural generate_id/*distinguish/uniquify*/ (void) const;
			};
	}
}

//#include "../cluster.h++"
//#include "machine.h++"
