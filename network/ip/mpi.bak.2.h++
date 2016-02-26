#ifndef MPI
#define MPI

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
#include "./connection.hpp"
#include "./messaging.hpp"

//#include "NoWare/Network/TCP.hpp"
//#include "NoWare/Network/UDP.hpp"

namespace LIB
{
	namespace network
	{
		class mpi // socket //messaging	// interface, mpi
		{
			protected:
				// Used when receiving, both by point-to-point and by multicast communications:
				unsigned long long int message_size_listening, message_size_receiving;	// In bytes (characters).
				unsigned long long int message_size;

				/*
				bool send_internal (const std::string, const std::string, const unsigned short int);
				bool broadcast_internal (const std::string, const std::string, const unsigned short int);

				std::string receive_internal (const unsigned short int);
				std::string listen_internal (const std::string, const unsigned short int);
				*/
			public:
				//address addresses;

				// For point-to-point (both sending and receiving):
				// Default: Connection tcp ("localhost", 13);
				//static Connection tcp;
				//LIB::network::connection tcp;

				// For multicasting (both sending and receiving):
				// Default: Connection udp ("239.255.0.1", 30001);
				//static Connection udp;
				//LIB::network::connection udp;
				
				LIB::network::messaging::interface connection;	// Inter-face.
				
				//std::string broadcast_flag;
				//std::string service;
				mpi (void);	// Default constructor.
				~mpi (void);	// Default destructor.
				
				//void cancel (void);
				//void cancel_udp (void);
				//void cancel_tcp (void);

				bool send (const std::string);
				bool send (const std::string, const std::string);
				bool send (const std::string, const std::string, const unsigned short int);	// Base.
				bool send (const std::string, const unsigned short int);
				
				//bool Send (std::string /* message */, std::string = tcp.address, unsigned short int = tcp.port);
				//bool Broadcast (std::string /* message */, std::string = udp.address, unsigned short int = udp.port);
				//bool Send (const std::string /* message */, const std::string = tcp.address, const unsigned short int = tcp.port);
				// bool Send (const std::string /* message */, const std::string = LIB::Network::IP::v4::TCP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::TCP::PORT);
				// bool Broadcast (const std::string /* message */, const std::string = LIB::Network::IP::v4::UDP::ADDRESS, const unsigned short int = LIB::Network::IP::v4::UDP::PORT);
			
				bool broadcast (const std::string);
				bool broadcast (const std::string, const std::string);
				bool broadcast (const std::string, const std::string, const unsigned short int);	// Base.
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
				std::string receive (const unsigned short int);	// Base.
			
				std::string listen (void);
				std::string listen (const std::string);
				std::string listen (const std::string /* Broadcast address. */, const unsigned short int /* Port. */);	// Base.
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
}

#endif MPI
