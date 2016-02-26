#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
//#include <stdio.h>
// #include <sqlite3.h>

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
#include "sql/index-pre.h"

// Custom SQLite.
//#include "sqlite.h"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace container
	{
		namespace database
		{
			class sql
			{
				public:
					#include "sql/index.h"
					
					//sql (void);
					//~ sql (void);
			};
		}
	}
	
	//namespace database = container::database;
}
