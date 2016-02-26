#pragma once
//#ifndef __IP
//#define __IP

#include <string>

#include <boost/asio.hpp>

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
					class address
					{
						protected:
							boost::system::error_code error_code_;
							boost::asio::ip::address value_/*, value_test*/;
							//std::string val;
							//unsigned short int version_;
						public:
							address (void);
							address (const address &);
							address (const std::string &);
							address (const char []);
							
							const address & operator = (const address &);
							const address & operator = (const std::string &);
							const address & operator = (const char []);
							//const std::string operator = (char []);
							
							const boost::asio::ip::address & value (void) const;
							const std::string to_string (void) const;
							operator const std::string (void) const;
							
							const bool is_loopback (void) const;
							const bool is_multicast (void) const;
							const bool is_unspecified (void) const;
							
							//operator unsigned short int (void);
							const unsigned short int version (void) const;
							
							//operator boost::system::error_code (void);
							const boost::system::error_code & error_code (void) const;
							
							const std::string convert (const unsigned short int &);
					};
					//enum version {v6, v4};

					//static const version Default = version::v6;

					/*
						//Try to get the local host's network address,
						//in order of availability, unless specified as an argument.

						//Here is the order which the types of addresses are checked in (if the argument is DEFAULT):
						//- Latest version to the oldest version;
						//- Latest local version to the oldest local version;
					*/
					const LIB::NAME_A <address, LIB::mathematics::numbers::natural> addresses (const LIB::mathematics::numbers::natural &/* Device. */ = 0, const bool &/* Include loopback addresses. */ = true);
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
