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
// #include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>

// Poco:
//#include <Poco\Net\SocketStream.h>

// This library:
// #include "../../math.h++"
#include "../container/content/value.h++"
//#include "endpoint.h++"
#include "_mpi.h++"
#include "ip/mpi.h++"
#include "../container/array.h++"
//#include "../container/variable.h++"
//#include "../communication/messaging.h++"

//#include "NoWare/Network/TCP.hpp"
//#include "NoWare/Network/UDP.hpp"

namespace LIB
{
	//namespace machine
	//{
		//namespace devices
		//{
			namespace net
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
					class mpi : public noware::net::_mpi // socket	// messenger, messaging	// interface, mpi
					{
						protected:
						//public:
							// Available connections.
							LIB::container::NAME_A <noware::net::_mpi */*, unsigned short int*/> _connections;
							
							// Keep track of the number of instances, to avoid multiple instantiation.
							// 
							// Multiple instantiation needs to be avoided,
							// because a machine's resources (network address and port combinations)
							// can only used by one software at one time.
							//static LIB::math::numbers::natural instances;
							
							//// Polling thread.
							//// It will check for the best available connection.
							//boost::thread * connection_search;
							
							//// The best available connection, which will be the preferred one.
							//// This is the index for the "_connections" array from above.
							//unsigned int connection;
							
							LIB::container::NAME_A <boost::thread *, unsigned long int> handlers;
						public:
							//const bool transmit (const std::string & /* message */);
							///const bool transmit (const std::string & /* message */, LIB::container::NTT <> /* address */);
							//
							//const bool broadcast (const std::string & /* message */);
							//const bool broadcast (const std::string & /* message */, LIB::container::NTT <> /* addresses */);
							//
							//const std::string receive (void);
							//const std::string receive (LIB::container::NTT <> &/* remote_endpoint*/, LIB::container::NTT <> /* address */);
							//
							//const std::string listen (void);
							//const std::string listen (LIB::container::NTT <> &/* remote_endpoint*/, LIB::container::NTT <> /* address*/);
							
							// Get the connections.
							const LIB::container::NAME_A <noware::net::_mpi */*, unsigned short int*/> & connections (void) const;
						protected:
							//LIB::container::NAME_A <NAME_A <boost::asio::io_service, unsigned long long int>, unsigned long int> handlers;
							// LIB::container::NAME_A <boost::thread *, unsigned long int> handlers;
							//LIB::container::NAME_A <handlers, unsigned long int> handlers;
							//LIB::container::NAME_A <boost::shared_ptr <boost::asio::io_service>, math::numbers::natural> receivers;	// The last spawned threads for receiving TCP.
							//LIB::container::NAME_A <boost::shared_ptr <boost::asio::io_service>, unsigned long int> receivers;	// The last spawned threads for receiving TCP.
							//LIB::container::NAME_A <NAME_A <math::numbers::natural, unsigned long int>, unsigned long int> listeners;	// The last spawned threads for UDP listening.

							//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
							//std::string local;	// The local host's address.

							//std::exception error;	// The last error.

							// Common to all of the functions.
							// boost::asio::io_service io/*, io_udp*/;
							//LIB::container::NAME_A <> sockets_udp_receive;
							//boost::asio::ip::tcp::socket * socket_tcp_receive;
							//boost::asio::ip::udp::socket * socket_udp_receive;
							//boost::asio::ip::tcp::acceptor * receive_acceptor;

							//void noware::net::mpi::receive_accept (boost::shared_ptr <boost::asio::ip::tcp::acceptor>, void (*/* handler*/) (std::string), const bool & /*cycle*/ = true);
							// void receive_accept (/*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*/* handler function */) (std::string), const bool &/* cycle*/);
						//	void listen_accept (void (*/* handler function*/) (std::string), const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool &/* cycle*/ = default_cycle);
							// void receive_accept_handler (const boost::system::error_code & error, /*boost::shared_ptr <*/boost::asio::ip::tcp::socket/*>*/, /*boost::shared_ptr <*/boost::asio::ip::tcp::acceptor/*>*/, void (*) (std::string)/*, const boost::system::error_code &*/, const bool &);

						//	void noware::net::mpi::receive_async_handler (void (*) (std::string), const connection &, const bool &);
							//void listen_accept (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
							//void listen_accept_handler (boost::shared_ptr <boost::asio::ip::udp::socket>, boost::asio::ip::udp::endpoint *, void (*) (std::string), const std::string &, const unsigned short int &);
							
							// void receive_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							// void listen_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							void receive_async_handler (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &/* handler*/, LIB::container::NTT <> &/* address*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							void listen_async_handler (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &/* handler*/, LIB::container::NTT <> &/* address*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
						public:
							//const statuc std::string DEFAULT_ADDRESS = "0.0.0.0";
							//const static unsigned short int DEFAULT_IP_ADDRESS_VERSION = 4;
							static const bool default_cycle = true;
							
							// std::string multicast_group_listen;
							// std::string multicast_group_broadcast;
							
							//address addresses;
							
							// For point-to-point (both sending and receiving):
							// Default: Connection tcp ("localhost", 13);
							//static Connection tcp;
							// noware::net::endpoint tcp_receive;	// Binding endpoint.
							// noware::net::endpoint tcp_transmit;	// Destination endpoint.
							
							// For multicasting (both sending and receiving):
							// Default: Connection udp ("239.255.0.1", 30001);
							//static Connection udp;
							// noware::net::endpoint udp_listen;	// Binding endpoint.
							// noware::net::endpoint udp_broadcast;	// Sending endpoint.

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
							
							
							//const bool receive_async (const boost::function <void (const LIB::container::NTT <> &/* remote_endpoint*/, const std::string &/* address*/)> &/* handler*/);
							const bool receive_async (const boost::function <void (const LIB::container::NTT <> &/* remote_endpoint*/, const std::string &/* address*/)> &/* handler*/);
							const bool receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, LIB::container::NTT <> &/* address*/);
							const bool receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const bool &/* cycle*/);
							const bool receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, LIB::container::NTT <> &/* address*/, const bool &/* cycle*/);
							const bool receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const bool &/* cycle*/, LIB::container::NTT <> &/* address*/);
							
							const bool receive_async_stop (void);
							const bool receive_async_stop (const LIB::container::NTT <> &/* address*/);
							//const bool receive_async_stop (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const LIB::container::NTT <> &/* address*/);
							
							const bool listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &);
							const bool listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const LIB::container::NTT <> &/* address*/);
							const bool listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const bool &/* cycle*/);
							const bool listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const LIB::container::NTT <> &/* address*/, const bool &/* cycle*/);
							const bool listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const bool &/* cycle*/, const LIB::container::NTT <> &/* address*/);
							
							const bool listen_async_stop (void);
							const bool listen_async_stop (const LIB::container::NTT <> &/* address*/);
							//const bool listen_async_stop (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> &, const LIB::container::NTT <> &/* address*/);
							
							
							using noware::net::_mpi::transmit;
							using noware::net::_mpi::broadcast;
							using noware::net::_mpi::receive;
							
							const bool transmit (const std::string & /* message */, LIB::container::NTT <> /* address */, const bool &/* reliable*//* = default_reliable*/)/* = 0*/;
							const bool broadcast (const std::string &/* message*/, LIB::container::NTT <>/* address/addresses */, const bool &/* reliable */);
							const std::string receive (LIB::container::NTT <> & /* remote endpoint */, LIB::container::NTT <> /* address */, const bool &/* reliable*//* = default_reliable*/)/* = 0*/;
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
