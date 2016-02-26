//#ifndef IP_CPP
//#define IP_CPP

//#include <iostream>

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

LIB::network::ip::address::address (void)
{
	val = "";
	//value_.from_string ("0.0.0.0");
	version_ = 0;
}

LIB::network::ip::address::address (const address & other)
{
	*this = other;
}

LIB::network::ip::address::address (const std::string & addr)
{
	*this = addr;
}

LIB::network::ip::address & LIB::network::ip::address::operator = (const LIB::network::ip::address & other)
{
	if (this != & other)
	{
		val = other.val;
		value_ = other.value_;
		version_ = other.version_;
	}
	
	return *this;
}

const std::string LIB::network::ip::address::operator = (const std::string & addr)
{
	value_test.from_string (addr, error_code_);
	
	if (error_code_.value () == 0)
	{
		//value_.from_string (addr);
		val = addr;
		
		if (value_.is_v6 ())
		{
			version_ = 6;
		}
		else //if (value_.is_v4 ())
		{
			version_ = 4;
		}
		//else
		//{
		//	version_ = 0;
		//}
	}
/*
	else
	{
		version = 0;
	}
*/
	return (*this).to_string ();
}

LIB::network::ip::address::operator std::string (void)
{
	//return value_.to_string ();
	return val;
}

boost::system::error_code & LIB::network::ip::address::error_code (void)
{
	return error_code_;
}

boost::asio::ip::address & LIB::network::ip::address::value (void)
{
	return value_;
}

const std::string LIB::network::ip::address::to_string (void) const
{
	//return value_.to_string ();
	return val;
}

unsigned short int LIB::network::ip::address::version (void)
{
	return version_;
}

LIB::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> LIB::network::ip::addresses (const LIB::mathematics::numbers::natural & device)
{
	LIB::mathematics::numbers::natural i = 0;
	LIB::NAME_A <address, LIB::mathematics::numbers::natural> addresses_;
	
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
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
#else
	struct ifaddrs *ifaddr, *ifa;
	int family, s/*, n*/;
	char host [NI_MAXHOST];
	
	//std::cout << "Trying to get network devices:" << std::endl;
	
	if (getifaddrs (&ifaddr) == 0)
	{
		//std::cout << "getifaddrs (&ifaddr) == 0" << std::endl;
		
		for (ifa = ifaddr, i = 0; ifa != NULL; ifa = ifa -> ifa_next/*, ++ i*/)
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
					addresses_ [i] = host;
					++ i;
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
	
	return addresses_;
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
