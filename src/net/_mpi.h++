#pragma once

#include <string>

//#include <boost/any.hpp>
#include <boost/asio.hpp>

#include "../container/content/value.h++"
//#include "../container/array.h++"
#include "../math.h++"
#include "../container/object.h++"
//#include "../communication/message.h++"

//#include "../container/entity-pre.h++"

namespace LIB
{
	//template <typename value = LIB::container::NAME_V, typename key = LIB::container::NAME_V>
	//class NTT;
	
	namespace net
	{
		enum communication
		{
			single,
			multiple
		};
		
		class _mpi	// mpi, messenger, connection.
		{
			public:
				friend class boost::serialization::access;
				
				template <typename archive>
				void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				operator const std::string (void) const;
				const _mpi & operator = (const std::string &);
				
				virtual const _mpi & operator = (const _mpi &);
				virtual const bool operator == (const _mpi &) const;
				
				class address
				{
					public:
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
						
						const std::string serialize (void) const;
						const bool deserialize (const std::string &);
						
						operator const std::string (void) const;
						const address & operator = (const std::string &);
						
						const address & operator = (const address &);
						const bool operator == (const address &) const;
						
						//boost::any
						LIB::container::NTT <>
						//std::string
							//transmission, broadcast, reception, listen
							//transmission, reception
							reliable, unreliable
						;
						//LIB::container::NAME_A <boost::any, math::numbers::natural> broadcast;
				};
				
				static const bool default_reliable = true;
				
				//connection (void);
				_mpi (void);
				_mpi (const _mpi &/* other*/);
				//connection (const std::string &);
				virtual ~_mpi (void);
				
				// Prepare a message:
				// Add the necessary headers.
				//static const LIB::communication::message prepare (LIB::communication::message /* message*/);
				static const noware::container::object <> prepare (noware::container::object <> /* message*/);
				
				//connection & operator = (const connection &);
				//const std::string operator = (const std::string &);
				
				//addresses addrs;
				//addresses reliable, unreliable;
				address transmission, reception, multicast;
				
				// Use defaults.
				const bool transmit (const std::string &/* message*/);
				const bool transmit/* unicast*/ (const std::string & /* message */, const bool &/* reliable*//* = default_reliable*/);
				// Transmit to this address(/to these addresses?).
				const bool transmit (const std::string &/* message*/, const LIB::container::NTT <> &/* address*/);
				virtual const bool transmit (const std::string & /* message */, LIB::container::NTT <> /* address */, const bool &/* reliable*//* = default_reliable*/)/* = 0*/;
				//virtual const bool transmit (const std::string &/* message */, const unsigned short int &/* port */);
				//virtual const bool transmit (const std::string &/* message */, const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual const bool transmit (const std::string &/* message */, const unsigned short int &/* port */, const std::string &/* address */);
				
				// Broadcast only to these addresses.
				// virtual const bool multicast (const std::string & /* message */, LIB::container::NTT <> /* addresses */, const bool &/* reliable*/ = default_reliable) = 0;
				// Transmit to every receiver.
				const bool broadcast (const std::string &/* message*/);
				const bool broadcast (const std::string & /* message */, const bool &/* reliable*//* = default_reliable*/)/* = 0*/;
				const bool broadcast (const std::string &/* message*/, const LIB::container::NTT <> &/* address/addresses */);
				virtual const bool broadcast (const std::string &/* message*/, LIB::container::NTT <>/* address/addresses */, const bool &/* reliable */);
				//virtual const bool broadcast (const std::string &/* message */, const std::string &/* address */) = 0;
				//virtual const bool broadcast (const std::string &/* message */, const unsigned short int &/* port */);
				//virtual const bool broadcast (const std::string &/* message */, const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual const bool broadcast (const std::string &/* message */, const unsigned short int &/* port */, const std::string &/* address */);
				
				// Use defaults.
				const std::string receive (void);
				const std::string receive (const bool &/* reliable*//* = default_reliable*/);
				// Give back information about remote endpoint.
				//virtual const std::string receive (LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> & /* remote endpoint */) = 0;
				// Receive only from this address.
				//virtual const std::string receive (LIB::container::NTT <> /* address */) = 0;
				const std::string receive (LIB::container::NTT <> /* address */, const bool &/* reliable*//* = default_reliable*/);
				// Receive only from this address.
				// Give back information about the remote endpoint.
				const std::string receive (LIB::container::NTT <> & /* remote_endpoint */, const LIB::container::NTT <> &/* address*/);
				virtual const std::string receive (LIB::container::NTT <> & /* remote endpoint */, LIB::container::NTT <> /* address */, const bool &/* reliable*//* = default_reliable*/)/* = 0*/;
				//virtual std::string receive (const unsigned short int &/* port */);
				//virtual std::string receive (const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual std::string receive (const unsigned short int &/* port */, const std::string &/* address */);
				
				//// Use defaults.
				// virtual const std::string listen (void) = 0;
				
				// Give back information about remote endpoint.
				//virtual const std::string listen (LIB::container::NTT <> & /* remote endpoint */) = 0;
				// Listen only to this address.
				//virtual const std::string listen (LIB::container::NTT <> /* address */) = 0;
				
				//// Listen only to this address; Give back information about the remote endpoint.
				// virtual const std::string listen (LIB::container::NTT <> & /* remote endpoint */, LIB::container::NTT <> /* address */) = 0;
				
				//virtual std::string listen (const unsigned short int &/* port*/);
				//virtual std::string listen (const std::string &/* address*/, const unsigned short int &/* port*/) = 0;
				//virtual std::string listen (const unsigned short int &/* port*/, const std::string &/* address*/);
			protected:
				bool reliable;
		};
	}
}

//#include "../container/entity.h++"
