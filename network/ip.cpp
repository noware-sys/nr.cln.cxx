//#ifndef IP_CPP
//#define IP_CPP

#include <Winsock2.h>
#include <windows.h>
#include <stdio.h>

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdlib.h>

#include "ip.hpp"

std::string LIB::network::ip::address (const LIB::mathematics::numbers::natural iter_face)
{
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

	return (std::string) szLocalIP;
	//return "";
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
