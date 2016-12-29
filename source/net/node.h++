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

#include "../container/content/value.h++"
#include "../math.h++"
#include "../serial.h++"
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

namespace noware
{
	namespace net
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
					//const noware::mathemathics::numbers::natural & id (void) const;
					
					//noware::array <noware::network::ip::address, noware::math::numbers::natural> addresses;
					noware::container::array <noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>, std::string> addresses;
					noware::container::array <std::string, noware::math::numbers::natural> networks;
					//noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural> paths;
					//noware::container::array <std::string, noware::math::numbers::natural> paths;
					path paths;
					//noware::container::array <std::string, noware::math::numbers::natural> network_paths;
					
					/*
						State of availability :
						true : available
						false : unresponsive, timing out
					*/
					//bool available;	// available availability state
					static const unsigned short int/*noware::math::numbers::natural*/ default_keepalive;
					
					// Use this!:
					//noware::math::numbers::natural keepalive;
					// Not this! (Temporary only!):
					unsigned int keepalive;
					
					void function_timeout (noware::container::array <node, noware::math::numbers::natural> &/*nodes*/, const noware::math::numbers::natural &/* key*/, const noware::math::numbers::natural &/* timeout (total)*/) const;
					//void function_timeout (noware::container::array <node, noware::container::any> &/*nodes*/, const noware::container::any &/* key*/, const noware::math::numbers::natural &/* timeout (total)*/) const;
					
					//noware::tools::randomizer randomizer;
			//	protected:
					boost::thread * thread_timeout;
					//noware::math::numbers::natural _id;
					
					// Generate unique ID.
					//const noware::mathemathics::numbers::natural generate_id/*distinguish/uniquify*/ (void) const;
			};
	}
}

//#include "../cluster.h++"
//#include "machine.h++"
