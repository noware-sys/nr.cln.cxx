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
#include "../any.hxx"
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
					sqlite (const std::string &);
					~sqlite (void);
					
					const bool connect (const std::string &);
					const bool disconnect (void);
					const bool connected (void) const;
					
					const bool query (noware::array <noware::array <noware::any, noware::any>, noware::any> &/* result*/, const std::string &/* query*/, const noware::array <noware::any, noware::any> &/* arguments*/, const noware::number::integer &/* tries*/ = default_tries);
					const bool query (noware::array <noware::array <noware::any, noware::any>, noware::any> &/* result*/, const std::string &/* query*/, const noware::number::integer &/* tries*/ = default_tries);
					const bool query (const std::string &/* query*/, const noware::array <noware::any, noware::any> &/* arguments*/, const noware::number::integer &/* tries*/ = default_tries);
					const bool query (const std::string &/* query*/, const noware::number::integer &/* tries*/ = default_tries);
					
					const noware::number::integer effect (void) const;	// Affected rows
					
					//static const unsigned short int default_tries = 3;
					static const noware::number::integer default_tries;
					//math::number::integer tries;
					
					//const sqlite & operator = (const sqlite &);
					const bool operator == (const sqlite &) const;
				protected:
					#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
						const bool effect/*_set*/ (const int &/* = 0*/);
					#endif
					
					sqlite3 * db;
					//noware::methematics::number::integer success;
					
					bool _connected;
			};
		}
	//}
}

