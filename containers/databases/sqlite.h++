#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
//#include <stdio.h>
#include <sqlite3.h>

#include "../../default.h++"
#include "../../mathematics.h++"
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
//#include "../../../sqlite/3.h"

// Custom SQLite.
//#include "sqlite.h"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace containers
	{
		namespace databases
		{
			class sqlite
			{
				public:
					//sqlite (const std::string & = ":memory:");
					sqlite (void);
					sqlite (const std::string &);
					~sqlite (void);
					
					const bool connect (const std::string &);
					const bool disconnect (void);
					const bool connected (void) const;
					
					const bool query (LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> &/* arguemnts*/, const LIB::mathematics::numbers::natural &/* tries*/ = default_tries);
					const bool query (LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::mathematics::numbers::natural &/* tries*/ = default_tries);
					const bool query (const std::string &/* the query*/, const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> &/* arguemnts*/, const LIB::mathematics::numbers::natural &/* tries*/ = default_tries);
					const bool query (const std::string &/* the query*/, const LIB::mathematics::numbers::natural &/* tries*/ = default_tries);
					
					const LIB::mathematics::numbers::natural effect (void) const;
					
					//static const unsigned short int default_tries = 3;
					static const LIB::mathematics::numbers::natural default_tries;
					//mathematics::numbers::natural tries;
					
					//const sqlite & operator = (const sqlite &);
					const bool operator == (const sqlite &) const;
				protected:
					#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
						const bool effect/*_set*/ (const int &/* = 0*/);
					#endif

					sqlite3 * db;
					//LIB::methematics::numbers::natural success;
					
					bool _connected;
			};
		}
	}
	
	namespace databases = containers::databases;
}
