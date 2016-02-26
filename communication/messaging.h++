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
#include "../network/mpi.h++"
//#include "../network/ip.h++"

namespace LIB
{
	namespace communication
	{
		//public:
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
					LIB::entity <> content;
					
					
					friend class boost::serialization::access;
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
					
					operator const std::string (void) const;
					const bool operator = (const std::string &);
					
					const bool operator = (const message &);
					const bool operator == (const message &) const;
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
			
			class messaging
			{
				public:
					friend class boost::serialization::access;
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
					
					operator const std::string (void) const;
					const bool operator = (const std::string &);
					
					const bool operator = (const messaging &);
					const bool operator == (const messaging &);
					
					class path
					{
						public:
							friend class boost::serialization::access;

							template <typename archive>
							void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);

							const std::string serialize (void) const;
							const bool deserialize (const std::string &);
							
							operator const std::string (void) const;
							const bool operator = (const std::string &);

							const bool operator = (const path &);
							const bool operator == (const path &) const;

							path (void);
							path (const path &);
							//~path (void);
							
							// Current location in the path.
							// The most completed step.
							//LIB::mathematics::numbers::natural location;
							
							// Direction of travel in the path.
							// true = forward/ascending
							// false = return/response/reverse/descending
							enum direction
							{
								forward,
								backward
							};
							
							direction _direction;
							
							// The path itself.
							LIB::NAME_A <LIB::NTT <>, LIB::mathematics::numbers::natural> _path;
					};
					
					messaging (void);
					virtual ~messaging (void);
					
					const static unsigned short int default_udp_port = 4;
					const static unsigned short int default_tcp_port = 5;
					
					LIB::network::mpi mpi;
					
					//virtual void manage (LIB::NTT <>/* remote_endpoint*/, const std::string &/* message*/);
					virtual void manage (LIB::NTT <>/* remote_endpoint*/, const message &/* message*/);
					//virtual void receive (LIB::NTT <>/* remote_endpoint*/, const std::string &/* message*/);
					void __receive (LIB::NTT <>/* remote_endpoint*/, const std::string &/* message*/);
					
					// Manage outbound point-to-point message.
					const bool transmit (const message &, const path &/* Machine. */) const;
					//const bool transmit (const std::string &, const mathematics::numbers::natural /* ID. */&) const;
					//const bool transmit (const std::string &, const LIB::NTT <> /* Endpoint. */&) const;
					// Manage outbound point-to-multipoint message.
					//const bool broadcast (const std::string &) const;
					// Broadcast.
					// const bool broadcast/*transmit*/ (const message &) const;
					//const bool broadcast (const std::string &, const LIB::NAME_A <machine, mathematics::numbers::natural> &) const;
				//	const bool transmit (const message &, const LIB::NAME_A <path, LIB::mathematics::numbers::natural> &/* The list of the paths to the machines. */) const;
					//const bool broadcast (const std::string &, const LIB::NTT <mathematics::numbers::natural /* ID. */, mathematics::numbers::natural/* key*/> &) const;
					// const bool broadcast (const communication::message &, const LIB::NAME_A <std::string, mathematics::numbers::natural> /* Addresses. */&) const;
					//const bool broadcast (const communication::message &, const LIB::NAME_A <LIB::network::ip::address, mathematics::numbers::natural> /* Addresses. */&) const;
					
					//const LIB::communication::message communicate (const LIB::communication::message &) const;	// Broadcast.
					//const LIB::communication::message communicate (const LIB::communication::message &, const LIB::mathematics::numbers::natural &/* The ID of the Machine. */) const;
					const std::string communicate (const message &, const path &/* The path to the machine.*/, const LIB::mathematics::numbers::natural &/* timeout per hop (in milliseconds)*/ = 300000);
					
					//const LIB::communication::message & prepare (/*const*/ LIB::communication::message &/* message*/) const;
					const message & prepare (/*const*/ message &/* message*/) const;
					const bool validate (const message &) const;
				protected:
					LIB::NAME_A <transmission, LIB::mathematics::numbers::natural> transmissions;
					//LIB::NAME_A <LIB::NAME_A <transmission, LIB::NTT <>>, LIB::mathematics::numbers::natural> transmissions;
					//LIB::NAME_A <LIB::NAME_A <transmission, LIB::mathematics::numbers::natural>, path> transmissions;
					
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
