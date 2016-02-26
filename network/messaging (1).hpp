#ifndef MESSAGING
#define MESSAGING

// Standard library:
#include <string>
#include <map>

#include <iostream>

// Boost:
#include <boost/asio.hpp>

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>

// Poco:
//#include <Poco\Net\SocketStream.h>

// This library:
#include "../default.hpp"
#include "../mathematics.hpp"
#include "connection.hpp"

//#include "NoWare/Network/TCP.hpp"
//#include "NoWare/Network/UDP.hpp"

namespace LIB
{
	namespace network
	{
		//namespace messaging
		//{
			//std::string localhost;
			// Common to all of the functions.
			//boost::asio::io_service io;
			
			// Used when receiving, both by point-to-point and by multicast communications:
			//static const unsigned int MESSAGE_SIZE = 128;	// In bytes (characters).
/*
			class address
			{
				protected:
					std::string _value;
				public:
					address (void);
					
					bool refresh (void);
					std::string value (void);
			}
*/			
			/*
			class handlers
			{
				public:
					enum class type
					{
						tcp,
						udp
					};
					
					type protocol;
					//void (* handler) (std::string);
					//boost::asio::io_service;
					NAME_A <boost::asio::io_service, unsigned long int> services;
			};
			*/
			
			enum class /*type_transmission_*/protocol
			{
				tcp,
				udp
			};
			
			//std::string service;
			class mpi // socket //messaging	// interface, mpi
			{
				protected:
					NAME_A <NAME_A <boost::asio::io_service, unsigned long long int>, unsigned long int> handlers;
					//NAME_A <handlers, unsigned long int> handlers;
					//NAME_A <boost::shared_ptr <boost::asio::io_service>, mathematics::numbers::natural> receivers;	// The last spawned threads for receiving TCP.
					//NAME_A <boost::shared_ptr <boost::asio::io_service>, unsigned long int> receivers;	// The last spawned threads for receiving TCP.
					//NAME_A <NAME_A <mathematics::numbers::natural, unsigned long int>, unsigned long int> listeners;	// The last spawned threads for UDP listening.
					
					//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
					//std::string local;	// The local host's address.
					
					//std::exception error;	// The last error.
					
					// Common to all of the functions.
					//boost::asio::io_service io, io_udp;
					//LIB::NAME_A <> sockets_udp_receive;
					//boost::asio::ip::tcp::socket * socket_tcp_receive;
					//boost::asio::ip::udp::socket * socket_udp_receive;
					//boost::asio::ip::tcp::acceptor * receive_acceptor;
					
					//void LIB::network::mpi::receive_accept (boost::shared_ptr <boost::asio::ip::tcp::acceptor>, void (*/* handler*/) (std::string), const bool & /*cycle*/ = true);
					void receive_accept (/*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*/* handler function */) (std::string), const bool &/* cycle*/);
					void receive_accept_handler (const boost::system::error_code & error, /*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*) (std::string)/*, const boost::system::error_code &*/, const bool &);
					
					//void listen_accept (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
					//void listen_accept_handler (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
				public:
					const static unsigned short int DEFAULT_IP_ADDRESS_VERSION = 4;
					const static bool DEFAULT_CYCLE = true;
					
					//address addresses;
					
					// For point-to-point (both sending and receiving):
					// Default: Connection tcp ("localhost", 13);
					//static Connection tcp;
					LIB::network::connection tcp;
					
					// For multicasting (both sending and receiving):
					// Default: Connection udp ("239.255.0.1", 30001);
					//static Connection udp;
					LIB::network::connection udp;
					
					// Used when receiving, both by point-to-point and by multicast communications:
					unsigned short int message_size;	// In bytes (characters).
					//unsigned long long int message_size;
					
					//std::string broadcast_flag;
					//std::string service;
					mpi (void);	// Default constructor.
					~mpi (void);	// Default destructor.
					
					void cancel (void);
					void cancel_udp (void);
					void cancel_tcp (void);
					
					void stop (void);
					
					bool transmit (const std::string);
					bool transmit (const std::string, const std::string);
					bool transmit (const std::string, const std::string, const unsigned short int);
					bool transmit (const std::string, const unsigned short int);
					
					//bool Send (std::string /* message */, std::string = tcp.address, unsigned short int = tcp.port);
					//bool Broadcast (std::string /* message */, std::string = udp.address, unsigned short int = udp.port);
					//bool Send (const std::string /* message */, const std::string = tcp.address, const unsigned short int = tcp.port);
					// bool Send (const std::string /* message */, const std::string = LIB::Network::IP::v4::TCP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::TCP::PORT);
					// bool Broadcast (const std::string /* message */, const std::string = LIB::Network::IP::v4::UDP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::UDP::PORT);
					
					bool broadcast (const std::string);
					bool broadcast (const std::string, const std::string);
					bool broadcast (const std::string, const std::string, const unsigned short int);
					bool broadcast (const std::string, const unsigned short int);
					
					////std::string Receive (void);
					//std::string Receive (unsigned short int = tcp.port);
					//	
					//// When receiving a broadcast.
					////std::string Listen (void);
					//std::string Listen (std::string = udp.address, unsigned short int = udp.port);

					//std::string Receive (unsigned short int = tcp.port);
					//std::string Listen (std::string = upd.address, unsigned short int = udp.port);
					std::string receive (void);
					std::string receive (const unsigned short int &/* port*/, const unsigned short int &/* version*/ = DEFAULT_IP_ADDRESS_VERSION);
					void receive_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
					void receive_async (void (*/* handler function*/) (std::string), const unsigned short int & /* Port. */, unsigned short int /* Version.*/ = DEFAULT_IP_ADDRESS_VERSION, const bool &/* cycle*/ = DEFAULT_CYCLE);
					
					bool receive_async_stop (void (*) (std::string), const bool & /* cycle */ = DEFAULT_CYCLE, const unsigned short int & = DEFAULT_IP_ADDRESS_VERSION);
					bool receive_async_stop (void (*) (std::string), const unsigned short int & /* Port. */, const unsigned short int & = DEFAULT_IP_ADDRESS_VERSION, const bool & /* cycle */ = DEFAULT_CYCLE);
					
					//
					
					std::string listen (void);
					std::string listen (const std::string);
					std::string listen (const std::string /* Broadcast address. */, const unsigned short int /* Port. */);
					std::string listen (const unsigned short int);
					
					void listen_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
					void listen_async (void (*/* handler function*/) (std::string), const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool &/* cycle*/ = DEFAULT_CYCLE);
					
					bool listen_async_stop (void (*/* handler function*/) (std::string), const bool & /* cycle */ = DEFAULT_CYCLE);
					bool listen_async_stop (void (*/* handler function*/) (std::string), const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool & /* cycle */ = DEFAULT_CYCLE);
					//
					
					//bool Port (unsigned int);	// Set the port.
					//unsigned int Port (void);	// Get the port.
			
					// Multicast.
					//bool MulticastAddress (std::string);
					//std::string MulticastAddress (std::string);
			
					//bool MulticastPort (unsigned int);
					//unsigned int MulticastPort (void);

					//std::exception Error (void);	// Returns last error.
					
					//std::string address (void);	// Return one of the the local ip addresses.
					//void refresh_address (void);	// Reload one of the local ip address.
			};
		//}
		/*
			Broadcast my IP // If possible
		*/
	}
}

#endif
