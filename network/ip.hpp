#ifndef IP
#define IP

#include <string>

#include "../default.hpp"
#include "../mathematics.hpp"

namespace LIB
{
	namespace network
	{
		namespace ip
		{
			//enum version {v6, v4};

			//static const version Default = version::v6;

			/*
				//Try to get the local host's network address,
				//in order of availability, unless specified as an argument.

				//Here is the order which the types of addresses are checked in (if the argument is DEFAULT):
				//- Latest version to the oldest version;
				//- Latest local version to the oldest local version;
			*/
			std::string address (const LIB::mathematics::numbers::natural /* Interface. */ = 0);
			
			//namespace v4
			//{
			//	std::string address (void);	// Gets the local host's network IPv4 address.
			//}

			//namespace v6
			//{
			//	std::string address (void);	// Gets the local host's network IPv6 address.
			//}
		}
	}
}

#endif IP
