#pragma once
//#ifndef __IP
//#define __IP

#include <string>
#include <ostream>

//#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>

#include "../container/content/value.h++"
#include "../math.h++"
#include "../container/array.h++"
//#include "endpoint.h++"

namespace noware
{
	//namespace machine
	//{
		//namespace devices
		//{
			namespace net
			{
				namespace ip
				{
					//const std::string int_to_addr (const int &);
					const boost::asio::ip::address network (const boost::asio::ip::address &/* address*/, const boost::asio::ip::address &/* mask*/);
					
					// The networks which this machine is connected to.
					const noware::container::array <std::string, noware::math::numbers::natural> networks (void);
					
					//enum version {v6, v4};

					//static const version Default = version::v6;

					/*
						//Try to get the local host's network address,
						//in order of availability, unless specified as an argument.

						//Here is the order which the types of addresses are checked in (if the argument is DEFAULT):
						//- Latest version to the oldest version;
						//- Latest local version to the oldest local version;
					*/
					//const noware::container::array <address, noware::math::numbers::natural> addresses (const noware::math::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					//const noware::container::array <boost::asio::ip::address, noware::math::numbers::natural> addresses (const noware::math::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					const noware::container::array <noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>, std::string> addresses (void); //(const noware::math::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
					//const noware::array <boost::asio::ip::address, noware::math::numbers::natural> addresses (const noware::math::numbers::natural &/* Device. */ = 0, const bool &/* Include local. */ = true);
					
					
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
							
							noware::network::endpoint endpt;
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
