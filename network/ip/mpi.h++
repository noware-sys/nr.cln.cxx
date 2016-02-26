#pragma once
//#ifndef __MPI
//#define __MPI

// Standard library:
#include <string>
#include <map>

#include <iostream>

// Boost:
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
// #include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>

// Poco:
//#include <Poco\Net\SocketStream.h>

// This library:
#include "../../value.h++"
#include "../../mathematics.h++"
// #include "../ip.h++"
//#include "../endpoint.h++"
#include "../_mpi.h++"
#include "../../container/entity.h++"

//#include "NoWare/Network/TCP.hpp"
//#include "NoWare/Network/UDP.hpp"

//#ifndef NTT
//	#define NTT entity
//#endif

namespace LIB
{
	//template <typename value = LIB::container::NAME_V, typename key = LIB::container::NAME_V>
	//class NTT;
	
	//namespace machine
	//{
		//namespace devices
		//{
			namespace network
			{
				//namespace messaging
				namespace ip
				{
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
					class mpi : protected LIB::network::_mpi // socket //messaging	// interface, mpi
					{
						protected:
							// Keep track of the number of instances, to avoid multiple instantiation.
							// 
							// Multiple instantiation needs to be avoided,
							// because a machine's resources (the combinations of network address, network port, and network protocol)
							// can only used by one software at one time.
							// This prevents this software to use the same resource more than once.
							// static LIB::mathematics::numbers::natural instances;
							
							//LIB::container::NAME_A <NAME_A <boost::asio::io_service, unsigned long long int>, unsigned long int> handlers;
							// LIB::container::NAME_A <boost::thread *, unsigned long int> handlers;
							//LIB::container::NAME_A <handlers, unsigned long int> handlers;
							//LIB::container::NAME_A <boost::shared_ptr <boost::asio::io_service>, mathematics::numbers::natural> receivers;	// The last spawned threads for receiving TCP.
							//LIB::container::NAME_A <boost::shared_ptr <boost::asio::io_service>, unsigned long int> receivers;	// The last spawned threads for receiving TCP.
							//LIB::container::NAME_A <NAME_A <mathematics::numbers::natural, unsigned long int>, unsigned long int> listeners;	// The last spawned threads for UDP listening.

							//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
							//std::string local;	// The local host's address.

							//std::exception error;	// The last error.

							// Common to all of the functions.
							boost::asio::io_service io/*, io_udp*/;
							//LIB::container::NAME_A <> sockets_udp_receive;
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
							// // void receive_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
							// // void listen_async_handler (const boost::function <void (std::string)> &/* handler*/, const std::string &/* address*/, const unsigned short int &/* port*/, const bool &/* cycle*/, const unsigned long int &/* hash*/);
						public:
							using LIB::network::_mpi::transmit;
							using LIB::network::_mpi::broadcast;
							using LIB::network::_mpi::receive;
							
							template <typename archive>
							void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);

							/*virtual */const mpi & operator = (const mpi &);
							/*virtual */const bool operator == (const mpi &) const;
							
							//static const std::string DEFAULT_ADDRESS = "0.0.0.0";
							//static const unsigned short int DEFAULT_IP_ADDRESS_VERSION = 6;	// 4, 6
							// static const bool DEFAULT_CYCLE = true;
							static const unsigned short int default_udp_port;
							static const unsigned short int default_tcp_port;
							//static const unsigned short int default_udp_port = 1;	// 2
							//static const unsigned short int default_tcp_port = 1;	// 3
							
							//static const bool default_reliable = true;
							static const bool default_reliable;
							static const bool default_receive_self;
							
							bool receive_self;
							
							//static const unsigned short int default_message_size = 100;
							static const unsigned short int default_message_size;
							// std::string multicast_group_listen;
							// std::string multicast_group_broadcast;

							//address addresses;

							// For point-to-point (both sending and receiving):
							// Default: Connection tcp ("localhost", 13);
							//static Connection tcp;
							// LIB::network::endpoint tcp_receive;	// Binding endpoint.
							// LIB::network::endpoint tcp_transmit;	// Destination endpoint.
							
							/*// Getters:
							const LIB::container::NTT <> get_transmit (void) const;
							const LIB::container::NTT <> get_receive (void) const;
							const LIB::container::NTT <> get_broadcast (void) const;
							//const LIB::container::NAME_A <LIB::container::NTT <>, LIB::mathematics::numbers::natural> get_broadcast_multiple (void);
							const LIB::container::NTT <> get_listen (void) const;
							// Setters:
								// Whole endpoint.
							const bool set_transmit (const LIB::container::NTT <> &);
							const bool set_receive (const LIB::container::NTT <> &);
							const bool set_broadcast (const LIB::container::NTT <> &);
							const bool set_listen (const LIB::container::NTT <> &);
							*//*	// Address:
							const bool set_transmit (const std::string &);
							const bool set_receive (const std::string &);
							const bool set_broadcast (const std::string &);
							const bool set_listen (const std::string &);
								// Port:
							const bool set_transmit (const unsigned short int &);
							const bool set_receive (const unsigned short int &);
							const bool set_broadcast (const unsigned short int &);
							const bool set_listen (const unsigned short int &);
							*/
							// For multicasting (both sending and receiving):
							// Default: Connection udp ("239.255.0.1", 30001);
							//static Connection udp;
							// LIB::network::endpoint udp_listen;	// Binding endpoint.
							// LIB::network::endpoint udp_broadcast;	// Sending endpoint.

							// Used when receiving, both by point-to-point and by multicast communications:
							unsigned short int message_size;	// In bytes (characters).
							//unsigned long long int message_size;
							
							// Use TCP for transmitting to block-wait for confirmation of reception.
							//bool reliable;
							
							//std::string broadcast_flag;
							//std::string service;
							mpi (void);		// Default constructor.
							~ mpi (void);	// Default destructor.

							// void stop (void);
							// void stop_udp (void);
							// void stop_tcp (void);

							//void stop (void);
							// Getter.
							//unsigned short int tcp_port (void);
							// Setter.
							const bool tcp_port (const unsigned short int &/* port*/);
							// Getter.
							//unsigned short int udp_port (void);
							// Setter.
							const bool udp_port (const unsigned short int &/* port*/);

							// std::string multicast_group (const std::string &);
							
							// const bool transmit (const std::string &/* message*/);
							// const bool transmit (const std::string &/* message*/, const bool &/* reliable */);
							// const bool transmit (const std::string &/* message*/, LIB::container::NTT <>/* address*/);
							const bool transmit (const std::string &/* message*/, LIB::container::NTT <>/* address*/, const bool &/* reliable */);
							// const bool transmit (const std::string &/* message*/, const unsigned short int &/* port*/);
							// const bool transmit (const std::string &/* message*/, const std::string &/* address*/, const unsigned short int &/* port*/);
							// const bool transmit (const std::string &/* message*/, const unsigned short int &/* port*/, const std::string &/* address*/);
							
							//bool Send (std::string /* message */, std::string = tcp.address, unsigned short int = tcp.port);
							//bool Broadcast (std::string /* message */, std::string = udp.address, unsigned short int = udp.port);
							//bool Send (const std::string /* message */, const std::string = tcp.address, const unsigned short int = tcp.port);
							// bool Send (const std::string /* message */, const std::string = LIB::Network::IP::v4::TCP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::TCP::PORT);
							// bool Broadcast (const std::string /* message */, const std::string = LIB::Network::IP::v4::UDP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::UDP::PORT);

							// const bool broadcast (const std::string &/* message*/);
							// const bool broadcast (const std::string &/* message*/, const bool &/* reliable */);
							////const bool broadcast (const std::string &/* message*/, const std::string &/* address*/);
							// const bool broadcast (const std::string &/* message*/, LIB::container::NTT <>/* address/addresses */);
							const bool broadcast (const std::string &/* message*/, LIB::container::NTT <>/* address/addresses */, const bool &/* reliable */);
							// const bool broadcast (const std::string &/* message*/, const LIB::container::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural> &/* addresses */);
							// const bool broadcast (const std::string &/* message*/, const unsigned short int &/* port*/);
							// const bool broadcast (const std::string &/* message*/, const std::string &/* address*/, const unsigned short int &/* port*/);
							// const bool broadcast (const std::string &/* message*/, const unsigned short int &/* port*/, const std::string &/* address*/);

							////std::string Receive (void);
							//std::string Receive (unsigned short int = tcp.port);
							//	
							//// When receiving a broadcast.
							////std::string Listen (void);
							//std::string Listen (std::string = udp.address, unsigned short int = udp.port);
							
							// std::string Receive (unsigned short int = tcp.port);
							// std::string Listen (std::string = upd.address, unsigned short int = udp.port);
							// const std::string receive (void);
							// const std::string receive (const bool &/* reliable */);
							// const std::string receive (LIB::container::NTT <> & /* remote_endpoint */, const LIB::container::NTT <> &/* address*/);
							const std::string receive (LIB::container::NTT <> & /* remote_endpoint */, LIB::container::NTT <>/* address*/, const bool &/* reliable */);
							// std::string receive (const unsigned short int &/* port*/);
							// std::string receive (const std::string &/* address*/, const unsigned short int &/* port*/);
							// std::string receive (const unsigned short int &/* port*/, const std::string &/* address*/);
							
//							bool receive_async (const boost::function <void (std::string)> &);
//							bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/);
//							bool receive_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
//							bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/);
//							bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
//							bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
//							bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
//							bool receive_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
//							bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
//							bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
//							//bool receive_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
//							bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
//							bool receive_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
//							bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
//							bool receive_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
//							bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
//							bool receive_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
//							
//							bool receive_async_stop (const boost::function <void (std::string)> &);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
//							bool receive_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
							
							//
							
							// *** Previously in use:
							// const std::string listen (void);
							// const std::string listen (LIB::container::NTT <> & /* remote_endpoint */, LIB::container::NTT <> /* address */);
							// *** Previously in use.
							
							// std::string listen (const unsigned short int &/* port*/);
							// std::string listen (const std::string &/* address*/, const unsigned short int &/* port*/);
							// std::string listen (const unsigned short int &/* port*/, const std::string &/* address*/);
							//std::string listen (void);
							//std::string listen (const std::string/* address*/);
							//std::string listen (const std::string &/* address*/, const unsigned short int &/* Port. *//*, boost::function <void (std::string)> = 0, const bool & cycle = DEFAULT_CYCLE, const unsigned long int & = 0*/);
							//std::string listen (const unsigned short int/* port*/);

							//bool listen_async (const boost::function <void (std::string)> &, const bool/* cycle*/ = DEFAULT_CYCLE);
							//bool listen_async (const boost::function <void (std::string)> &, const std::string & /* Broadcast address. */, const unsigned short int & /* Port. */, const bool/* cycle*/ = DEFAULT_CYCLE);
							//void LIB::network::mpi::listen_async_internal (void (*/*handler*/) (std::string), const std::string &/*broadcast_address*/, const unsigned short int & /*port*/, const bool &/*cycle*/, unsigned long int /*hash*/ = 0, unsigned long long int/* handler_index*/ = 0);
							
//							bool listen_async (const boost::function <void (std::string)> &);
//							bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/);
//							bool listen_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
//							bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/);
//							bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
//							bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
//							bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
//							bool listen_async (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
//							bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
//							bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
//							//bool receive_async (void (*/* handler function*/) (std::string), const bool &/* cycle*/ = DEFAULT_CYCLE);
//							bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
//							bool listen_async (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
//							bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
//							bool listen_async (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
//							bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
//							bool listen_async (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
//
//							//bool listen_async_stop (const boost::function <void (std::string)> &, const bool/* cycle */ = DEFAULT_CYCLE);
//							//bool listen_async_stop (const boost::function <void (std::string)> &, const std::string & /* address*/, const unsigned short int & /* Port. */, const bool/* cycle */ = DEFAULT_CYCLE);
//							bool listen_async_stop (const boost::function <void (std::string)> &);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port*/, const std::string &/* address*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int &/* port*/, const bool &/* cycle*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int &/* port*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const unsigned short int & /* port. */, const bool &/* cycle*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const std::string &/* address*/, const bool &/* cycle*/, const unsigned short int & /* port. */);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const std::string &/* address*/, const bool &/* cycle*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const unsigned short int & /* port. */, const bool &/* cycle*/, const std::string &/* address*/);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const std::string &/* address*/, const unsigned short int & /* port. */);
//							bool listen_async_stop (const boost::function <void (std::string)> &, const bool &/* cycle*/, const unsigned short int & /* port. */, const std::string &/* address*/);
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
				}
				/*
					Broadcast my IP // If possible
				*/
			}
		//}
	//}
}

//#include "../../container/entity.h++"
//#endif
