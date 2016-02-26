//#ifndef IP_CPP
//#define IP_CPP

//#include <iostream>
//#include <ostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <Winsock2.h>
	#include <windows.h>
	#include <stdio.h>

	#include <winsock2.h>
	#include <iphlpapi.h>
	#include <stdlib.h>
#else
	#include <sys/types.h>
	#include <ifaddrs.h>
#endif

#include "ip.h++"

//const LIB::containers::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device, const bool & loopback_include)
//const LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device, const bool & loopback_include)
const LIB::containers::NAME_A <LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural>, std::string> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device, const bool & loopback_include)
{
	//LIB::mathematics::numbers::natural i;
	//address address_test;
	boost::asio::ip::address _address;
	//LIB::containers::NAME_A <address, LIB::mathematics::numbers::natural> addresses_;
	//LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> _addresses;
	LIB::containers::NAME_A <LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural>, std::string> _addresses;
	
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
	/*struct */ifaddrs *ifaddr, *ifa;
	int family, s/*, n*/;
	int mask, broadcast, network;
	char host [NI_MAXHOST];
	//char mask [INET_ADDRSTRLEN];
	//void * mask_ptr;
	
	//address adr;
	
	//std::cout << "Trying to get network devices:" << std::endl;
	
	if (getifaddrs (& ifaddr) == 0)
	{
		//std::cout << "getifaddrs (&ifaddr) == 0" << std::endl;
		
		for (ifa = ifaddr/*, i = 1*/; ifa != NULL; ifa = ifa -> ifa_next/*, ++ i*/)
		{
			//std::cout << i << ". Network device" << std::endl;
			
			if (ifa -> ifa_addr == NULL)
			{
				continue;
			}
			
			family = ifa -> ifa_addr -> sa_family;
			
			if (family == AF_INET || family == AF_INET6)
			{
				s = getnameinfo (ifa -> ifa_addr, (family == AF_INET) ? sizeof (struct sockaddr_in) : sizeof (struct sockaddr_in6), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
				
				if (s == 0)
				{
					//address_test = host;
					_address = _address.from_string (/*(std::string) */host);
					
					//std::cout << "_address.to_string ():[" << _address.to_string () << ']' << std::endl;
					
					if (loopback_include || (! loopback_include && ! _address.is_loopback ()))
					{
						
						// http://stackoverflow.com/questions/4139405/how-to-know-ip-address-for-interfaces-in-c
						
						if (ioctl (sd, SIOCGIFBRDADDR, & ifr [i]) == 0)
						{
							broadcast = ((sockaddr_in *) (& ifr [i].ifr_broadaddr)) -> sin_addr.s_addr;
							//printf ("%d) broadcast: %d.%d.%d.%d\n", i+1, INT_TO_ADDR(bcast));
						}
						if (ioctl (sd, SIOCGIFNETMASK, & ifr [i]) == 0)
						{
							mask = ((sockaddr_in *) (& ifr [i].ifr_netmask)) -> sin_addr.s_addr;
							//printf("%d) netmask: %d.%d.%d.%d\n", i+1, INT_TO_ADDR (mask));
						}
						
						network = addr & mask;
						//addresses_.add (host);
						//_addresses.add (_address);
						//addresses_ [i] = host;
						//_addresses [ifa -> ifa_name] [family == AF_INET6 ? 6 : 4] = _address;
						_addresses [ifa -> ifa_name] [family == AF_INET6 ? 6 : 4] ["address"] = _address;
						_addresses [ifa -> ifa_name] [family == AF_INET6 ? 6 : 4] ["mask"] = INT_TO_ADDR (mask);
						_addresses [ifa -> ifa_name] [family == AF_INET6 ? 6 : 4] ["broadcast"] = INT_TO_ADDR (broadcast);
						_addresses [ifa -> ifa_name] [family == AF_INET6 ? 6 : 4] ["network"] = INT_TO_ADDR (network);
						//adr = host;
						//++ i;
						
					}
				}
				//else
				//{
				//	printf("getnameinfo() failed: %s\n", gai_strerror(s));
				//	exit(EXIT_FAILURE);
				//}
				
				//printf("\t\taddress: <%s>\n", host);

			}
			
			//addresses_ [i ++] = boost::asio::ip::address (boost::asio::ip::address::from_string ("127.0.0.1"));
			//addresses_ [i ++] = "127.0.0.1";
		}
	}
	//else
	//{
		//perror ("getifaddrs");
		//exit(EXIT_FAILURE);
	//}
	
	freeifaddrs (ifaddr);
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

std::ostream & /*LIB::containers::NAME_A <value, key>::*/operator << (std::ostream & stream, const LIB::network::ip::address & address/*, const std::string & indentation*/)
{
	return stream << address.to_string ();
}
