#pragma once
//#ifndef __IP
//#define __IP

#include <string>
#include <ostream>

//#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>

#include "../default.h++"
#include "../mathematics.h++"
#include "../containers/array.h++"
//#include "endpoint.h++"

namespace LIB
{
	//namespace machine
	//{
		//namespace devices
		//{
			namespace network
			{
				namespace ip
				{
					//const std::string int_to_addr (const int &);
					const boost::asio::ip::address network (const boost::asio::ip::address &/* address*/, const boost::asio::ip::address &/* mask*/);
					
					// The networks which this machine is connected to.
					const LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks (void);
					
					//enum version {v6, v4};

					//static const version Default = version::v6;

					/*
						//Try to get the local host's network address,
						//in order of availability, unless specified as an argument.

						//Here is the order which the types of addresses are checked in (if the argument is DEFAULT):
						//- Latest version to the oldest version;
						//- Latest local version to the oldest local version;
					*/
					//const LIB::containers::NAME_A <address, LIB::mathematics::numbers::natural> addresses (const LIB::mathematics::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					//const LIB::containers::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> addresses (const LIB::mathematics::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> addresses (void); //(const LIB::mathematics::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					//const LIB::NAME_A <boost::asio::ip::address, LIB::mathematics::numbers::natural> addresses (const LIB::mathematics::numbers::natural &/* Device. */ = 0, const bool &/* Include local. */ = true);
					
					
					//namespace v4
					//{
					//	std::string address (void);	// Gets the local host's network IPv4 address.
					//}

					//namespace v6
					//{
					//	std::string address (void);	// Gets the local host's network IPv6 address.
					//}

					enum class /*type_transmission_*/protocol
					{
						tcp,
						udp
					};
					
					/*
					class connection
					{
						public:
							connection (void);
							
							LIB::network::endpoint endpt;
							protocol proto;
					};
					*/
				}
				/*
				class device
				{

				};
				*/
			}
		//}
	//}
}

//#endif
