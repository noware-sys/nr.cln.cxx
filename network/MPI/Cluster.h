//#include <boost/any.hpp>
#include <string>

//#include <algorithm>
//#include <cstdlib>
//#include <deque>
//#include <iostream>
//#include <list>
//#include <set>
#include <map>
//#include <boost/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>

//#include <boost/array.hpp>
#include <boost/asio.hpp>

//#include "Memory.h"
//#include "HPC.h"

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0610
#endif _WIN32_WINNT

#ifndef _Cluster
#define _Cluster

namespace Cluster	// Unit, Computer, Machine, Host, Node, Processor
{
	namespace Network // Connectivity // Communication
	{
		namespace Protocols
		{
			namespace IP
			{
				std::string Value (void);	// Gets the local host's network IP address.
				
				namespace v4
				{

				}

				namespace v6
				{

				}
			}

			namespace TCP
			{
				static const std::string HOST	= "localhost";
				static const unsigned int PORT	= 13;
			}

			namespace UDP
			{
				static const std::string HOST	= "239.255.0.1";
				static const unsigned int PORT	= 30001;
			}

			//static const std::map <unsigned int, std::string> PORTS =	// Valid communication ports. 
			//{
			//	{13, "daytime"},
			//	{21, "ftp"},
			//	{22, "ssh"},
			//	{23, "telnet"},
			//	{25, "smtp"},
			//	{110, "pop3"}
			//};
		}

		#ifndef _Connection
		#define _Connection
			class Connection
			{
				private:
					std::string host;
					unsigned int port;
				public:
					//static const std::string HOST = "localhost";
					//static const unsigned int PORT = 0;
					
					Connection (std::string = Protocols::TCP::HOST, unsigned int = Protocols::TCP::PORT);

					std::string Host (void);
					bool Host (std::string);

					unsigned int Port (void);
					bool Port (unsigned int);
			};
		#endif Connection

		namespace Messaging
		{
//			#ifndef _Messaging
//			#define _Messaging

//			#ifndef _Map
//			#define _Map
				//std::map <unsigned int, std::string> ports;	// Valid communication ports. 
//			#endif _Map

//			#ifndef _TCP
//			#define _TCP
				// For point-to-point (sending and receiving):
				//Connection tcp;
//			#endif _TCP

//			#ifndef _UDP
//			#define _UDP
				// For multicasting (sending and receiving):
				//Connection udp;
//			#endif _UDP
				
//			#endif _Messaging
			//std::exception error;	// The last error.

			// Common to all of the functions.
			//boost::asio::io_service io;
			
			// Used when receiving, both by point-to-point and by multicast communications:
			static const unsigned int MESSAGE_SIZE = 128;	// In bytes (characters).
			
			//std::string service;
			#ifndef _Interface
			#define _Interface
				class Interface // Socket //Messaging	// Interface, MPI
				{
					private:
						std::map <unsigned int, std::string> ports;	// Valid communication ports. 

					
						std::exception error;	// The last error.

						// Common to all of the functions.
						boost::asio::io_service io;
					public:
						//Connection tcp ("localhost", 13);
						//Connection udp ("239.255.0.1", 30001);
						Connection tcp;
						Connection udp;

						// For point-to-point (sending and receiving):
						//Connection tcp;
						// For multicasting (sending and receiving):
						//Connection udp;

						// Used when receiving, both by point-to-point and by multicast communications:
						unsigned int message_size;	// In bytes (characters).

						//std::string broadcast_flag;
						//std::string service;
						Interface (void);	// Constructor.
					
						bool Send (std::string /* message */);
						bool Broadcast (std::string /* message */);

						//bool Send (std::string /* message */, std::string = tcp.Host () /* host */, std::string = ports.at (tcp.Port ()) /* port */);
						//bool Broadcast (std::string /* message */, std::string = udp.Host (), unsigned int = udp.Port ());
				
						std::string Receive (void);
						//std::string Receive (/*std::string & error = "None"*/ unsigned int = udp.Port ());
						
						// When receiving a broadcast.
						std::string Listen (void);
						//std::string Listen (/*std::string & error = "None"*/ std::string = udp.Host (), unsigned int = udp.Port ());

						//bool Port (unsigned int);	// Set the port.
						//unsigned int Port (void);	// Get the port.
			
						// Multicast.
						//bool MulticastAddress (std::string);
						//std::string MulticastAddress (std::string);
			
						//bool MulticastPort (unsigned int);
						//unsigned int MulticastPort (void);
				};
			#endif _Interface
		}
		/*
			Broadcast my IP // If possible
		*/
	}

	namespace Memory
	{
		// Memory memory;

		namespace Synchronization
		{

		}
	}

	namespace Processor
	{

	}
}

#endif _Cluster