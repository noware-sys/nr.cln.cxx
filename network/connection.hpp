#ifndef CONNECTION
#define CONNECTION

#include <string>

#include "../default.hpp"
//#include "TCP.h"
//#include "IP.h"

namespace LIB
{
	namespace network
	{
		//class Connection
		//{
		//	private:
		//		std::string address;
		//		unsigned short int port; // Ranges exactly from 0 to 65535, inclusive.
		//	public:
		//		//static const std::string HOST = "localhost";
		//		//static const unsigned int PORT = 0;
		//		
		//		Connection (std::string = LIB::Network::Protocols::IP::v4::TCP::ADDRESS, unsigned short int = LIB::Network::Protocols::IP::v4::TCP::PORT);

		//		std::string Address (void);
		//		void Address (std::string);

		//		unsigned short int Port (void);
		//		void Port (unsigned short int);
		//};
		struct connection
		{
			connection (void);

			std::string address;
			unsigned short int port;
		};
	}
}

//LIB::Network::Connection::Connection (void)
//{
//	address = "";
//	port = 0;
//}

#endif CONNECTION
