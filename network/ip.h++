#ifndef IP
#define IP

#include <string>

#include <boost/asio.hpp>

#include "../default.h++"
#include "../mathematics.h++"
#include "../containers/array.h++"

namespace LIB
{
	namespace network
	{
		namespace ip
		{
			class address
			{
				protected:
					boost::system::error_code error_code_;
					boost::asio::ip::address value_, value_test;
					std::string val;
					unsigned short int version_;
				public:
					address (void);
					address (const address &);
					address (const std::string &);
					
					address & operator = (const address &);
					const std::string operator = (const std::string &);
					
					boost::asio::ip::address & value (void);
					const std::string to_string (void) const;
					operator std::string (void);
					
					//operator unsigned short int (void);
					unsigned short int version (void);
					
					//operator boost::system::error_code (void);
					boost::system::error_code & error_code (void);
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
			LIB::NAME_A <address, LIB::mathematics::numbers::natural> addresses (const LIB::mathematics::numbers::natural &/* Device. */ = 0);
			
			
			
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
		}
		/*
		class device
		{
			
		};
		*/
	}
}

#endif
