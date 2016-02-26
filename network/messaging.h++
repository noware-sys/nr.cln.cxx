#ifndef MESSAGING
#define MESSAGING

// Standard library:
#include <string>
#include <map>

#include <iostream>

// Boost:
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>

// Poco:
//#include <Poco\Net\SocketStream.h>

// This library:
#include "../default.h++"
#include "../mathematics.h++"
#include "connection.h++"

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
			
			//std::string service;
			class mpi // socket //messaging	// interface, mpi
			{
				protected:
					//NAME_A <NAME_A <boost::asio::io_service, unsigned long long int>, unsigned long int> handlers;
					NAME_A <boost::thread *, unsigned long int> handlers;
					//NAME_A <handlers, unsigned long int> handlers;
					//NAME_A <boost::shared_ptr <boost::asio::io_service>, mathematics::numbers::natural> receivers;	// The last spawned threads for receiving TCP.
					//NAME_A <boost::shared_ptr <boost::asio::io_service>, unsigned long int> receivers;	// The last spawned threads for receiving TCP.
					//NAME_A <NAME_A <mathematics::numbers::natural, unsigned long int>, unsigned long int> listeners;	// The last spawned threads for UDP listening.
					
					//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
					//std::string local;	// The local host's address.
					
					//std::exception error;	// The last error.
					
					// Common to all of the functions.
					boost::asio::io_service io/*, io_udp*/;
					//LIB::NAME_A <> sockets_udp_receive;
					//boost::asio::ip::tcp::socket * socket_tcp_receive;
					//boost::asio::ip::udp::socket * socket_udp_receive;
					//boost::asio::ip::tcp::acceptor * receive_acceptor;
					
					//void LIB::network::mpi::receive_accept (boost::shared_ptr <boost::asio::ip::tcp::acceptor>, void (*/* handler*/) (std::string), const bool & /*cycle*/ = true);
					// void receive_accept (/*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*/* handler function */) (std::string), const bool &/* cycle*/);
				//	void listen_accept (void (*/* handler function*/) (std::string), const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool &/* cycle*/ = DEFAULT_CYCLE);
					// void receive_accept_handler (const boost::system::error_code & error, /*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*) (std::string)/*, const boost::system::error_code &*/, const bool &);
					
				//	void LIB::network::mpi::receive_async_handler (void (*) (std::string), const connection &, const bool &);
					//void listen_accept (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
					//void listen_accept_handler (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
					void receive_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
					void listen_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
				public:
					//const statuc std::string DEFAULT_ADDRESS = "0.0.0.0";
					//const static unsigned short int DEFAULT_IP_ADDRESS_VERSION = 4;
					const static bool DEFAULT_CYCLE = true;
					
					std::string multicast_group_listen;
					std::string multicast_group_broadcast;
					
					//address addresses;
					
					// For point-to-point (both sending and receiving):
					// Default: Connection tcp ("localhost", 13);
					//static Connection tcp;
					LIB::network::connection tcp_receive;	// Binding endpoint.
					LIB::network::connection tcp_transmit;	// Destination endpoint.
					
					// For multicasting (both sending and receiving):
					// Default: Connection udp ("239.255.0.1", 30001);
					//static Connection udp;
					LIB::network::connection udp_listen;	// Binding endpoint.
					LIB::network::connection udp_broadcast;	// Sending endpoint.
					
					// Used when receiving, both by point-to-point and by multicast communications:
					unsigned short int message_size;	// In bytes (characters).
					//unsigned long long int message_size;
					
					//std::string broadcast_flag;
					//std::string service;
					mpi (void);	// Default constructor.
					~mpi (void);	// Default destructor.
					
					void stop (void);
					void stop_udp (void);
					void stop_tcp (void);
					
					//void stop (void);
					// Getter.
					//unsigned short int tcp_port (void);
					// Setter.
					unsigned short int tcp_port (const unsigned short int &/* port*/);
					// Getter.
					//unsigned short int udp_port (void);
					// Setter.
					unsigned short int udp_port (const unsigned short int &/* port*/);
					
					std::string multicast_group (const std::string &);
					
					bool transmit (const std::string &/* message*/);
					bool transmit (const std::string &/* message*/, const std::string &/* address*/);
					bool transmit (const std::string &/* message*/, const unsigned short int &/* port*/);
					bool transmit (const std::string &/* message*/, const std::string &/* address*/, const unsigned short int &/* port*/);
					bool transmit (const std::string &/* message*/, const unsigned short int &/* port*/, const std::string &/* address*/);
					
					//bool Send (std::string /* message */, std::string = tcp.address, unsigned short int = tcp.port);
					//bool Broadcast (std::string /* message */, std::string = udp.address, unsigned short int = udp.port);
					//bool Send (const std::string /* message */, const std::string = tcp.address, const unsigned short int = tcp.port);
					// bool Send (const std::string /* message */, const std::string = LIB::Network::IP::v4::TCP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::TCP::PORT);
					// bool Broadcast (const std::string /* message */, const std::string = LIB::Network::IP::v4::UDP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::UDP::PORT);
					
					bool broadcast (const std::string &/* message*/);
					bool broadcast (const std::string &/* message*/, const std::string &/* address*/);
					bool broadcast (const std::string &/* message*/, const unsigned short int &/* port*/);
					bool broadcast (const std::string &/* message*/, const std::string &/* address*/, const unsigned short int &/* port*/);
					bool broadcast (const std::string &/* message*/, const unsigned short int &/* port*/, const std::string &/* address*/);
					
					////std::string Receive (void);
					//std::string Receive (unsigned short int = tcp.port);
					//	
					//// When receiving a broadcast.
					////std::string Listen (void);
					//std::string Listen (std::string = udp.address, unsigned short int = udp.port);

					//std::string Receive (unsigned short int = tcp.port);
					//std::string Listen (std::string = upd.address, unsigned short int = udp.port);
					std::string receive (void);
					std::string receive (const std::string &/* address*/);
					std::string receive (const unsigned short int &/* port*/);
					std::string receive (const std::string &/* address*/, const unsigned short int &/* port*/);
					std::string receive (const unsigned short int &/* port*/, const std::string &/* address*/);
					
					bool receive_async (const boost::function <void (std::string)> &);
					bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/);
					bool receive_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
					bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/);
					bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
					bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
					bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
					bool receive_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
					bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
					bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
					//bool receive_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
					bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
					bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
					bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
					bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
					bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
					bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
					
					bool receive_async_stop (const boost::function <void (std::string)> &);
					bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
					bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
					bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
					bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
					
					//
					
					std::string listen (void);
					std::string listen (const std::string &/* address*/);
					std::string listen (const unsigned short int &/* port*/);
					std::string listen (const std::string &/* address*/, const unsigned short int &/* port*/);
					std::string listen (const unsigned short int &/* port*/, const std::string &/* address*/);
					//std::string listen (void);
					//std::string listen (const std::string/* address*/);
					//std::string listen (const std::string &/* address*/, const unsigned short int &/* Port. *//*, boost::function <void (std::string)> = 0, const bool & cycle = DEFAULT_CYCLE, const unsigned long int & = 0*/);
					//std::string listen (const unsigned short int/* port*/);
					
					//bool listen_async (const boost::function <void (std::string)> &, const bool/* cycle*/ = DEFAULT_CYCLE);
					//bool listen_async (const boost::function <void (std::string)> &, const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool/* cycle*/ = DEFAULT_CYCLE);
					//void LIB::network::mpi::listen_async_internal (void (*/*handler*/) (std::string), const std::string &/*broadcast_address*/, const unsigned short int & /*port*/, const bool &/*cycle*/, unsigned long int /*hash*/ = 0, unsigned long long int/* handler_index*/ = 0);
					bool listen_async (const boost::function <void (std::string)> &);
					bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/);
					bool listen_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
					bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/);
					bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
					bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
					bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
					bool listen_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
					bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
					bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
					//bool receive_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
					bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
					bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
					bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
					bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
					bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
					bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
					
					//bool listen_async_stop (const boost::function <void (std::string)> &, const bool/* cycle */ = DEFAULT_CYCLE);
					//bool listen_async_stop (const boost::function <void (std::string)> &, const std::string & /* address*/, const unsigned short int & /* Port. */, const bool/* cycle */ = DEFAULT_CYCLE);
					bool listen_async_stop (const boost::function <void (std::string)> &);
					bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
					bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
					bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
					bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
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
