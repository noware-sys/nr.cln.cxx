//#pragma once
//#ifndef _DEVICE_HPP
//#define _DEVICE_HPP

/*
// Standard:
#include <string>
#include <queue>
#include <stack>

// Boost:
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
#include <boost/date_time/posix_time/posix_time.hpp>
*/
// This class:

// #include "../default.h++"
//#include "resource/index-pre.h++"

/*#include "../mathematics.h++"
#include "../containers/array.h++"
#include "../containers/variable.h++"
#include "../tools.h++"
#include "memory.h++"
#include "../serialization.h++"
*/
//#include "../cluster/machine.h++"
/*
namespace LIB
{
	namespace machine
	{
		//namespace devices
		//{
*/			class device
			{
				public:
					#include ".device/index.h++"
					//friend class LIB::cluster::machine;
					
					device (void);
					//resource (const device &);
					//virtual ~resource (void);
					
					//virtual const device & operator= (const device &);
					
					enum location	// location, distance
					{
						literal,	// literal, local
						reference	// reference, remote
					};
					
					enum type
					{
						memory,		// memory, storage
						processor,	// processor, process, processing
						network,
						in,			// in, detector, sensor
						out,
						other
					};
					
					//type t;
					//location loc;
					
					virtual const location & get_location (void) const;
					virtual const type & get_type (void) const;
					virtual const bool operator== (const device &/* other*/) const/* = 0*/;
					//virtual const bool run (const bool &/* active(_running)_state*/ = true)/* = 0*/;
					//virtual const bool active/*ning*/ (void) const;
				protected:
					type t;
					location l;
					
					//bool _active;
					// LIB::cluster::machine * machine;	// Needed?
				public:
					#include ".device/postinnerindex.h++"
			};
/*		//}
	}
}
*/
//#include "device.c++"
/*
#ifndef _DEVICE_CPP
#define _DEVICE_CPP

LIB::machine::device::device (void)
{
}

LIB::machine::device::device (const device & other)
{
	* this = other;
}

const LIB::machine::device & LIB::machine::device::operator = (const device & other)
{
	t = other.t;
	
	return * this;
}

#endif
*/

#include "postindex.h++"

//#endif

