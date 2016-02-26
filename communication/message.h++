#pragma once
//#ifndef __MESSAGE
//#define __MESSAGE

// Standard:
// #include <string>
// #include <queue>
// #include <stack>

// // Boost:
// #include <boost/thread/mutex.hpp>
// #include <boost/thread/condition_variable.hpp>
// #include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

// #include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/thread.hpp>	//
// #include <boost/date_time/posix_time/posix_time.hpp>

// // This class:
// #include "../default.h++"
// #include "../mathematics.h++"
#include "../containers/entity.h++"
//#include "../../../containers/array.h++"
// #include "../containers/variable.h++"
// #include "../tools.h++"
//#include "memory.h++"
#include "../serialization.h++"
// #include "resource.h++"
// #include "resources.h++"

namespace LIB
{
	namespace communication
	{
		//public:
			class message
			{
				public:
					// std::string name;
					
					//resources _resources;
					//LIB::NAME_A <> resources (void) const;
					
					/*
					// Analogous to a verb.
					// action, operation
					//enum class operation
					enum operation
					{
						ask,
						answer,
						get,
						got,
						set,
						unset,
						exists,
						rename
					};
					
					operation action;
					*/
					
					//// Analogous to nouns and to adjectives.
					//LIB::NAME_A <> content;
					LIB::entity <> content;
					
					
					friend class boost::serialization::access;
					
					template <typename Archive>
					void serialize (Archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
					
					operator const std::string (void) const;
					const bool operator = (const std::string &);
					
					const bool operator = (const message &);
			};
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
