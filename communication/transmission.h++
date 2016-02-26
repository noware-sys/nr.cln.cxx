#pragma once
//#ifndef __MESSAGE
//#define __MESSAGE

// Standard:
#include <string>
// #include <queue>
// #include <stack>
#include <mutex>

// // Boost:
// #include <boost/thread/mutex.hpp>
// #include <boost/thread/condition_variable.hpp>
// #include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/thread.hpp>	//
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/thread/detail/thread.hpp>

// // This class:
#include "../default.h++"
#include "../mathematics.h++"
#include "../containers/entity.h++"
//#include "../../../containers/array.h++"
// #include "../containers/variable.h++"
// #include "../tools.h++"
//#include "memory.h++"
// #include "../serialization.h++"
// #include "resource.h++"
// #include "resources.h++"
//#include "../network/mpi.h++"
//#include "../network/ip.h++"

namespace LIB
{
	namespace communication
	{
		/*
		class delays
		{
			public:
				delays (void);
				//~ delays (void);

				LIB::mathematics::numbers::natural
					request,	// Time to delay between requests (in microseconds).
					response,	// Time to wait for a peer to respond to a probing request, before it is considered offline (in microseconds).
					discovery	// Time to delay between discovery probes.
				;
		};
		*/
		class transmission
		{
			public:
				transmission (void);
				transmission (const transmission &);
				~transmission (void);

				std::mutex lock;
				//LIB::NTT <> data;
				std::string data;

				void terminate (LIB::NAME_A <transmission, LIB::mathematics::numbers::natural> &/* transmissions*/, const LIB::mathematics::numbers::natural &/* key*/, const LIB::mathematics::numbers::natural &/* timeout, total*/) const;
				boost::thread * terminator;
		};
	}
}

/*
LIB::Cluster::Platform::Platform (void)
{
	thread = NULL;
}

LIB::Cluster::Platform::Platform (void)
{
	delete thread;
}
*/

//#endif
