#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
//#include <stdio.h>
#include <sqlite3.h>

//#include "../../../name.h++"
//#include "../../content/value.h++"
//#include "../../../math.h++"
#include "../var.hxx"
#include "../array.hxx"
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

//#include "sqlite.h++"
// #include "../../../mathematics.h++"

// #include <iostream>
// #include <assert.h>

namespace noware
{
	//namespace container
	//{
		namespace db
		{
			class sqlite
			{
				public:
					//sqlite (const std::string & = ":memory:");
					sqlite (void);
					//sqlite (const std::string &);
					~sqlite (void);
					
					const bool connect (const std::string &);
					const bool disconnect (void);
					// get the connected state
					const bool connected (void) const;
					
					const bool query (noware::array <noware::array <>> &/* result*/, const std::string &/* query*/, const noware::array <std::string, int> &/* arguments*/, const noware::nr::integer &/* tries*/ = tries_default);
					const bool query (noware::array <noware::array <>> &/* result*/, const std::string &/* query*/, const noware::nr::integer &/* tries*/ = tries_default);
					const bool query (const std::string &/* query*/, const noware::array <std::string, int> &/* arguments*/, const noware::nr::integer &/* tries*/ = tries_default);
					const bool query (const std::string &/* query*/, const noware::nr::integer &/* tries*/ = tries_default);
					
					const noware::nr::integer effect (void) const;	// Affected rows
					
					//static const unsigned short int tries_default= 3;
					static const noware::nr::integer tries_default;
					//math::nr::integer tries;
					
					//const sqlite & operator = (const sqlite &);
					const bool operator == (const sqlite &) const;
				protected:
					//#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
					//	const bool effect/*_set*/ (const int &/* = 0*/);
					//#endif
					
					sqlite3 * db;
					//noware::methematics::nr::integer success;
					
					// set the connected state
					//const bool connected (const bool &/* new_value*/);
					bool _connected;
			};
		}
	//}
}
