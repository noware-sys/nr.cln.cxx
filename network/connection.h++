#pragma once

#include <string>

#include <boost/any.hpp>
#include <boost/asio.hpp>

#include "../default.h++"
//#include "../containers/array.h++"
#include "../mathematics.h++"
#include "../containers/entity.h++"

//#include "../containers/entity-pre.h++"

namespace LIB
{
	//template <typename value = LIB::NAME_V, typename key = LIB::NAME_V>
	//class NTT;
	
	namespace network
	{
		enum communication
		{
			single,
			multiple
		};
		
		class connection
		{
			public:
				friend class boost::serialization::access;
				
				template <typename archive>
				virtual void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				operator const std::string (void) const;
				const bool operator = (const std::string &);
				
				virtual const bool operator = (const connection &);
				virtual const bool operator == (const connection &);
				
				class addresses
				{
					public:
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
						
						const std::string serialize (void) const;
						const bool deserialize (const std::string &);
						
						operator const std::string (void) const;
						const bool operator = (const std::string &);
						
						const bool operator = (const addresses &);
						const bool operator == (const addresses &);
						
						//boost::any
						LIB::NTT <>
						//std::string
							transmission, broadcast, reception, listen;
							//transmit, broadcast, receive, listen;
						//LIB::NAME_A <boost::any, mathematics::numbers::natural> broadcast;
				};
				
				//connection (void);
				connection (const connection &);
				//connection (const std::string &);
				virtual ~ connection (void);
				
				//connection & operator = (const connection &);
				//const std::string operator = (const std::string &);
				
				addresses addrs;
				
				virtual const bool transmit (const std::string & /* message */);
				// Transmit to this address.
				virtual const bool transmit (const std::string & /* message */, LIB::NTT <> /* address */) = 0;
				//virtual const bool transmit (const std::string &/* message */, const unsigned short int &/* port */);
				//virtual const bool transmit (const std::string &/* message */, const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual const bool transmit (const std::string &/* message */, const unsigned short int &/* port */, const std::string &/* address */);
				
				virtual const bool broadcast (const std::string & /* message */) = 0;
				// Broadcast only to these addresses.
				virtual const bool broadcast (const std::string & /* message */, LIB::NTT <> /* addresses */) = 0;
				//virtual const bool broadcast (const std::string &/* message */, const std::string &/* address */) = 0;
				//virtual const bool broadcast (const std::string &/* message */, const unsigned short int &/* port */);
				//virtual const bool broadcast (const std::string &/* message */, const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual const bool broadcast (const std::string &/* message */, const unsigned short int &/* port */, const std::string &/* address */);
				
				// Use defaults.
				virtual const std::string receive (void) = 0;
				// Give back information about remote endpoint.
				//virtual const std::string receive (LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> & /* remote endpoint */) = 0;
				// Receive only from this address.
				//virtual const std::string receive (LIB::entity <> /* address */) = 0;
				// Receive only from this address; Give back information about remote endpoint.
				virtual const std::string receive (LIB::NTT <> & /* remote endpoint */, LIB::NTT <> /* address */) = 0;
				//virtual std::string receive (const unsigned short int &/* port */);
				//virtual std::string receive (const std::string &/* address */, const unsigned short int &/* port */) = 0;
				//virtual std::string receive (const unsigned short int &/* port */, const std::string &/* address */);
				
				// Use defaults.
				virtual const std::string listen (void) = 0;
				// Give back information about remote endpoint.
				//virtual const std::string listen (LIB::entity <> & /* remote endpoint */) = 0;
				// Listen only to this address.
				//virtual const std::string listen (LIB::entity <> /* address */) = 0;
				// Listen only to this address; Give back information about the remote endpoint.
				virtual const std::string listen (LIB::NTT <> & /* remote endpoint */, LIB::NTT <> /* address */) = 0;
				//virtual std::string listen (const unsigned short int &/* port*/);
				//virtual std::string listen (const std::string &/* address*/, const unsigned short int &/* port*/) = 0;
				//virtual std::string listen (const unsigned short int &/* port*/, const std::string &/* address*/);
		};
	}
}

//#include "../containers/entity.h++"
