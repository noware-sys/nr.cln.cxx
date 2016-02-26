//#ifndef IP_CPP
//#define IP_CPP

//#include <iostream>
//#include <ostream>

#include "../containers/variable.h++"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <Winsock2.h>
	#include <windows.h>
	#include <stdio.h>

	#include <winsock2.h>
	#include <iphlpapi.h>
	#include <stdlib.h>
#else
	//#include <sys/types.h>
	//#include <ifaddrs.h>
	#include <net/if.h>
	#include <netinet/in.h>
	#include <sys/ioctl.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	/*
	#define INT_TO_ADDR (_addr) \
	(_addr & 0xFF), \
	(_addr >> 8 & 0xFF), \
	(_addr >> 16 & 0xFF), \
	(_addr >> 24 & 0xFF)
	*/
#endif

#include "ip.h++"

const std::string LIB::network::ip::int_to_addr (const int & addr)
{
	return (LIB::containers::NAME_V) (addr & 0xFF) + '.' + (LIB::containers::NAME_V) (addr >> 8 & 0xFF) + '.' + (LIB::containers::NAME_V) (addr >> 16 & 0xFF) + '.' + (LIB::containers::NAME_V) (addr >> 24 & 0xFF);
}

//const LIB::containers::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device, const bool & loopback_include)
//const LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device, const bool & loopback_include)
const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> LIB::network::ip::addresses (/*const LIB::mathematics::numbers::natural & device, const bool & loopback_include*/void)
{
	//LIB::mathematics::numbers::natural i;
	//address address_test;
	boost::asio::ip::address _address;
	//LIB::containers::NAME_A <address, LIB::mathematics::numbers::natural> addresses_;
	//LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> _addresses;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> _addresses;
	
	LIB::mathematics::numbers::natural version;
	int family;
	
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
/*
	// Init WinSock:
	WSADATA wsa_Data;
	int wsa_ReturnCode = WSAStartup (0x101, &wsa_Data);
	
	// Get the local hostname 
	char szHostName [255];
	gethostname (szHostName, 255);
	struct hostent *host_entry;
	host_entry = gethostbyname (szHostName);
	char * szLocalIP;
	szLocalIP = inet_ntoa (* (struct in_addr *) * host_entry -> h_addr_list);
	WSACleanup ();
	
	
	addresses_ [i ++] = (std::string) szLocalIP;
	// return (std::string) szLocalIP;
*/
#else
	struct ifconf ifc;
	struct ifreq ifr [10];
	int sd, ifc_num, address, broadcast, mask, network, i;
	
	// Create a socket then use ioctl on the file descriptor to retrieve the interface information.
	sd = socket (PF_INET, SOCK_DGRAM, 0);
	
	if (sd > 0)
	{
		ifc.ifc_len = sizeof(ifr);
		ifc.ifc_ifcu.ifcu_buf = (caddr_t)ifr;

		if (ioctl(sd, SIOCGIFCONF, &ifc) == 0)
		{
			ifc_num = ifc.ifc_len / sizeof (struct ifreq);
			//printf("%d interfaces found.\n", ifc.ifc_len);
			printf("%d interfaces found.\n", ifc_num);

			for (i = 0; i < ifc_num; ++ i)
			{
				family = ifr [i].ifr_addr.sa_family;
				if (family != AF_INET && family != AF_INET6)
				{
					continue;
				}

				/* display the interface name */
				//printf("%d) Interface Name: %s\n", i+1, ifr [i].ifr_name);

				/* Retrieve the IP address, broadcast address, and subnet mask. */
				if (ioctl (sd, SIOCGIFADDR, & ifr [i]) == 0)
				{
					address = ((struct sockaddr_in *) (& ifr [i].ifr_addr)) -> sin_addr.s_addr;
					//printf("%d) Interface address: %d.%d.%d.%d\n", i+1, INT_TO_ADDR (address));
				}
				if (ioctl (sd, SIOCGIFBRDADDR, & ifr [i]) == 0)
				{
					broadcast = ((struct sockaddr_in *) (& ifr [i].ifr_broadaddr)) -> sin_addr.s_addr;
					//printf("%d) Broadcast: %d.%d.%d.%d\n", i+1, INT_TO_ADDR (broadcast));
				}
				if (ioctl (sd, SIOCGIFNETMASK, & ifr [i]) == 0)
				{
					mask = ((struct sockaddr_in *) (& ifr [i].ifr_netmask)) -> sin_addr.s_addr;
					//printf("%d) Netmask: %d.%d.%d.%d\n", i+1, INT_TO_ADDR (mask));
				}

				/* Compute the current network value from the address and netmask. */
				network = address & mask;
				//printf("%d) Current Network: %d.%d.%d.%d\n", i+1, INT_TO_ADDR (network));
				
				version = family == AF_INET6 ? 6 : 4;
				
				_addresses [ifr [i].ifr_name] [version] ["address"] = int_to_addr (address);
				_addresses [ifr [i].ifr_name] [version] ["mask"] = int_to_addr (mask);
				_addresses [ifr [i].ifr_name] [version] ["broadcast"] = int_to_addr (broadcast);
				_addresses [ifr [i].ifr_name] [version] ["network"] = int_to_addr (network);
			}
		}

		close (sd);
	}
#endif
	//std::cout << "addresses_.size (): " << addresses_.size () << std::endl;
	
	return _addresses;
	//return "localhost";
	//return "127.0.0.1";
}

//std::string LIB::Network::IP::v4::Address (void)
//{
//	return "";
//}
//
//std::string LIB::Network::IP::v6::Address (void)
//{
//	return "";
//}

//#endif IP_CPP

//LIB::network::ip::connection::connection (void)
//{
//	proto = protocol::tcp;
//}

//std::ostream & /*LIB::containers::NAME_A <value, key>::*/operator << (std::ostream & stream, const LIB::network::ip::address & address/*, const std::string & indentation*/)
//{
//	return stream << address.to_string ();
//}
