/*
#pragma once

//#include <string>
//#include <map>
//#include <list>
//#include <omp.h>

//#include <boost/any.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/system/error_code.hpp>
//#include <boost/system/system_error.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

#include "../default.h++"
//#include "../mathematics.h++"
//#include "../serialization.h++"
//#include "machine.h++"
//#include "../machine/device.h++"
//#include "../machine/resource.h++"
//#include "../machine/resources.h++"
//#include "../containers/array.h++"
//#include "../containers/variable.h++"
//#include "../containers/entity.h++"
#include "../containers/databases/sqlite.h++"
//#include "../cluster.h++"

//#include "../communication/messaging.h++"
// #include "../network/mpi.h++"
//#include "../network/ip.h++"
*/

/*
namespace LIB
{
	namespace cluster
	{
*/			class path
			{
				public:
					friend class boost::serialization::access;
					
					//BOOST_SERIALIZATION_SPLIT_MEMBER ();
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename archive>
					//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					
					//template <typename archive>
					//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					path (void);
					path (const path &);
					~path (void);
					
					const path & operator = (const path &);
					const bool operator == (const path &) const;
					
					const LIB::mathematics::numbers::natural size (const std::string &/* endpoint*/) const;
					const bool add (const std::string &/* endpoint*/, const LIB::mathematics::numbers::natural &/* latency*/);
					//const std::string optimum (void) const;
					const std::string average (void) const;
					const std::string minimum (void) const;
					
					//const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural> all (void) const;
					const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> all (void) const;
					
					// Limits
					static const bool default_journal_limit_maximum;
					static const unsigned short int/*LIB::mathematics::numbers::natural*/ default_journal_maximum;
					
					bool journal_limit_maximum;
					// This designates the maximum entries per endpoint.
					LIB::mathematics::numbers::natural journal_maximum;
				protected:
					LIB::container::database::sql::sqlite db;
					
					const bool reduce (const std::string &/* endpoint*/);
			};
/*	}
}
*/
//#include "../cluster.h++"
//#include "machine.h++"
