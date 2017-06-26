#pragma once

#include <zmq.hpp>
#include <zhelpers.hpp>
#include <zyre.h>

#include <boost/function.hpp>
//#include <boost/function_equal.hpp>
#include <boost/thread.hpp>
#include <boost/random/random_device.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <string>

//#include "cluster.hxx"
//#include "../tree.hxx"
//#include "../var.hxx"
#include <zmq/msg.hxx>

namespace noware
{
	namespace net
	{
		class node// : virtual cluster
		{
			public:
				node (void);
				~node (void);
				
				const bool fin (void);
				const bool inited (void) const;
				const bool init (void);
				
				const bool stop (void);
				const bool status (void) const;
				const bool start (void);
				
				const bool leave (const std::string &);
				const bool join (const std::string &);
				const bool joined (const std::string &) const;
				
				// Own groups.
				const std::map <const noware::nr, const std::string> groups_own (void) const;
				// Groups known via peers.
				const std::map <const noware::nr, const std::string> groups_peers (void) const;
				
				// All peers.
				const std::map <const noware::nr, const std::string> peers (void) const;
				// Peers belonging to a group.
				const std::map <const noware::nr, const std::string> peers (const std::string & group) const;
				
				// Transmit a message to one peer.
				const bool unicast (const zmq::msg &/* multipart message*/, const std::string &/* peer id*/) const;
				//const bool unicast (const zmsg_t */* multipart message*/, const std::string &/* peer id*/) const;
				
				// Transmit a message to any one peer amongst all peers.
				const bool anycast (const zmq::msg &/* multipart message*/) const;
				
				// Transmit a message to any one peer belonging to a group.
				const bool anycast (const zmq::msg &/* multipart message*/, const std::string &/* group*/) const;
				
				// Transmit a message to all peers belonging to a group.
				const bool multicast (const zmq::msg &/* multipart message*/, const std::string &/* group*/) const;
				//const bool multicast (const zmsg_t */* multipart message*/, const std::string &/* group*/) const;
				
				// Transmit a message to all peers.
				const bool broadcast (const zmq::msg &/* multipart message*/) const;
				
				
				const zyre_t * operator * (void) const;
				
				// units count cluster_size peers_count
				const unsigned int peers_size (void) const;
				const unsigned int peers_size (const std::string &/* group*/) const;
				// groups
				
				// These three functions (internally) refer to "exoreception".
				const bool reception_unset (void);
				const bool reception_is_set (void) const;
				const bool reception_set
				(
					const boost::function
					<
						void/* manage*/
						(
							const zyre_event_t */* zyre_event*/
						)
					>
					&/* manager*/
				);
			protected:
				zyre_t * _node;
				
				bool running;
				
				// For running "void receive (void)".
				boost::thread * reception;
				
				// External (for the object) event handler.
				boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> exoreception;
				
				// Manager of incoming messages.
				void receive (void);
				
				// Randomness
				//boost::random::random_device randev;
				//std::mt19937 gen(rd());
				//boost::random::mt19937 gentor {randev ()};
		};
	}
}
