#ifndef MESSAGING
#define MESSAGING

// Standard library:
#include <string>
#include <map>

// Boost:
#include <boost/asio.hpp>

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
		namespace messaging
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
			//std::string service;
			class interface // socket //messaging	// interface, mpi
			{
				protected:
					//std::map <unsigned short int, std::string> ports;	// Valid communication ports.
					//std::string local;	// The local host's address.
					
					//std::exception error;	// The last error.
			
					// Common to all of the functions.
					boost::asio::io_service io;
					boost::asio::ip::tcp::socket * socket_tcp_receive;
					boost::asio::ip::udp::socket * socket_udp_receive;
				public:
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
					
					//std::string broadcast_flag;
					//std::string service;
					interface (void);	// Default constructor.
					~interface (void);	// Default destructor.
					
					void cancel (void);
					void cancel_udp (void);
					void cancel_tcp (void);

					bool send (const std::string);
					bool send (const std::string, const std::string);
					bool send (const std::string, const std::string, const unsigned short int);
					bool send (const std::string, const unsigned short int);
					
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
					std::string receive (const unsigned short int);
					
					std::string listen (void);
					std::string listen (const std::string);
					std::string listen (const std::string, const unsigned short int);
					std::string listen (const unsigned short int);
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
}

#endif MESSAGING
