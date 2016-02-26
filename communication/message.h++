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
		class message
		{
			public:
				message (void);
				message (const message &);
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
				LIB::containers::NTT <> content;


				friend class boost::serialization::access;

				template <typename archive>
				void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);

				const std::string serialize (void) const;
				const bool deserialize (const std::string &);

				operator const std::string (void) const;
				const std::string & operator = (const std::string &);

				const message & operator = (const message &);
				const bool operator == (const message &) const;
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
