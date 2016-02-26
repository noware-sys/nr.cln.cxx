#pragma once
//#ifndef __MPI
//#define __MPI

// Standard library:
#include <string>
#include <map>

#include <iostream>

// Boost:
//#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>

// Poco:
//#include <Poco\Net\SocketStream.h>

// This library:
// #include "../../mathematics.h++"
#include "../default.h++"
#include "endpoint.h++"
#include "connection.h++"
#include "ip/mpi.h++"

//#include "NoWare/Network/TCP.hpp"
//#include "NoWare/Network/UDP.hpp"

namespace LIB
{
	//namespace machine
	//{
		//namespace devices
		//{
			namespace network
			{
				//namespace messaging
				//namespace ip
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
					class mpi : public LIB::network::connection // socket //messaging	// interface, mpi
					{
						protected:
						//public:
							// Available connections.
							LIB::NAME_A <LIB::network::connection *, unsigned short int> _connections;
							
							//// Polling thread.
							//// It will check for the best available connection.
							//boost::thread * connection_search;
							
							//// The best available connection, which will be the preferred one.
							//// This is the index for the "_connections" array from above.
							//unsigned int connection;
							
							LIB::NAME_A <boost::thread *, unsigned long int> handlers;
						public:
							const bool transmit (const std::string & /* message */);
							const bool transmit (const std::string & /* message */, LIB::entity <> /* address */);
							
							const bool broadcast (const std::string & /* message */);
							const bool broadcast (const std::string & /* message */, LIB::entity <> /* addresses */);
							
							const std::string receive (void);
							const std::string receive (LIB::entity <> &/* remote_endpoint*/, LIB::entity <> /* address */);
							
							const std::string listen (void);
							const std::string listen (LIB::entity <> &/* remote_endpoint*/, LIB::entity <> /* address*/);
							
							// Get the connections.
							const LIB::NAME_A <LIB::network::connection *, unsigned short int> & connections (void) const;
						protected:
							//LIB::NAME_A <NAME_A <boost::asio::io_service, unsigned long long int>, unsigned long int> handlers;
							// LIB::NAME_A <boost::thread *, unsigned long int> handlers;
							//LIB::NAME_A <handlers, unsigned long int> handlers;
							//LIB::NAME_A <boost::shared_ptr <boost::asio::io_service>, mathematics::numbers::natural> receivers;	// The last spawned threads for receiving TCP.
							//LIB::NAME_A <boost::shared_ptr <boost::asio::io_service>, unsigned long int> receivers;	// The last spawned threads for receiving TCP.
							//LIB::NAME_A <NAME_A <mathematics::numbers::natural, unsigned long int>, unsigned long int> listeners;	// The last spawned threads for UDP listening.

							//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
							//std::string local;	// The local host's address.

							//std::exception error;	// The last error.

							// Common to all of the functions.
							// boost::asio::io_service io/*, io_udp*/;
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
							
							// void receive_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							// void listen_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							void receive_async_handler (const boost::function <void (const LIB::entity <> &, const std::string &)> &/* handler*/, LIB::entity <> &/* address*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							void listen_async_handler (const boost::function <void (const LIB::entity <> &, const std::string &)> &/* handler*/, LIB::entity <> &/* address*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
						public:
							//const statuc std::string DEFAULT_ADDRESS = "0.0.0.0";
							//const static unsigned short int DEFAULT_IP_ADDRESS_VERSION = 4;
							const static bool DEFAULT_CYCLE = true;
							
							// std::string multicast_group_listen;
							// std::string multicast_group_broadcast;
							
							//address addresses;
							
							// For point-to-point (both sending and receiving):
							// Default: Connection tcp ("localhost", 13);
							//static Connection tcp;
							// LIB::network::endpoint tcp_receive;	// Binding endpoint.
							// LIB::network::endpoint tcp_transmit;	// Destination endpoint.
							
							// For multicasting (both sending and receiving):
							// Default: Connection udp ("239.255.0.1", 30001);
							//static Connection udp;
							// LIB::network::endpoint udp_listen;	// Binding endpoint.
							// LIB::network::endpoint udp_broadcast;	// Sending endpoint.

							// Used when receiving, both by point-to-point and by multicast communications:
							// unsigned short int message_size;	// In bytes (characters).
							//unsigned long long int message_size;

							//std::string broadcast_flag;
							//std::string service;
							mpi (void);		// Default constructor.
							~ mpi (void);	// Default destructor.
							
							// Stop all handlers.
							void stop (void);
							// void stop_udp (void);
							// void stop_tcp (void);
							
							
							bool receive_async (const boost::function <void (const LIB::entity <> &/* remote_endpoint*/, const std::string &/* address*/)> &);
							bool receive_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, LIB::entity <> &/* address*/);
							bool receive_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const bool &/* cycle*/);
							bool receive_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, LIB::entity <> &/* address*/, const bool &/* cycle*/);
							bool receive_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const bool &/* cycle*/, LIB::entity <> &/* address*/);
							
							bool receive_async_stop (void);
							bool receive_async_stop (const LIB::entity <> &/* address*/);
							
							bool listen_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &);
							bool listen_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const LIB::entity <> &/* address*/);
							bool listen_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const bool &/* cycle*/);
							bool listen_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const LIB::entity <> &/* address*/, const bool &/* cycle*/);
							bool listen_async (const boost::function <void (const LIB::entity <> &, const std::string &)> &, const bool &/* cycle*/, const LIB::entity <> &/* address*/);
							
							bool listen_async_stop (void);
							bool listen_async_stop (const LIB::entity <> &/* address*/);
					};
				//}
				/*
					Broadcast my IP // If possible
				*/
			}
		//}
	//}
}

//#endif
