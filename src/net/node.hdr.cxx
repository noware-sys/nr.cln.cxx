#pragma once

#include <zyre/zyre.h>
#include <boost/function.hpp>
//#include <boost/function_equal.hpp>
#include <boost/thread.hpp>
#include <string>
//#include "cluster.hxx"
#include "../tree.hdr.cxx"
#include "../var.hdr.cxx"

namespace noware
{
	namespace net
	{
			class node// : virtual cluster
			{
				public:
					node (void);
					~node (void);
					
					const bool finalize (void);
					const bool initialized (void) const;
					const bool initialize (void);
					
					const bool stop (void);
					const bool status (void) const;
					const bool start (void);
					
					const bool leave (const std::string &);
					const bool join (const std::string &);
					
					const bool unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/) const;
					const bool multicast (const noware::tree <> &/* message*/, const std::string &/* group*/) const;
					
					const zyre_t * zyre (void) const;
					
					// units count cluster_size peers_count
					const unsigned int peers_count (void) const;
					
					// These three functions (internally) refer to "exoreception".
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
					const bool reception_is_set (void) const;
					const bool reception_unset (void);
				protected:
					zyre_t * _node;
					bool running;
					boost::thread * reception;	// For running "void receive (void)".
					boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> exoreception;	// External (for the object) event handler.
					
					// Manager of incoming messages.
					void receive (void);
			};
	}
}

