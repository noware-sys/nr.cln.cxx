#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
//#include <stdio.h>
#include <sqlite3.h>

#include "../../default.h++"
//#include "../../mathematics.h++"
#include "../../containers/array.h++"
#include "../../containers/variable.h++"
//#include "../../containers/entity.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
//#include "../../cluster/machine.h++"
//#include "../resource.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace database
	{
		class sqlite
		{
			public:
				sqlite (const std::string & = ":memory:");
				~sqlite (void);
				
				const bool query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> &/* arguemnts*/ = NULL, const LIB::mathematics::numbers::natural &/* error_retries*/ = 3);
			protected:
				sqlite3 * db;
				//LIB::methematics::numbers::natural success;
		};
	}
}
