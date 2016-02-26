#pragma once

#include <string>

#include "db/sql.h++"

namespace noware
{
	namespace container
	{
		//typedef std::string text;
		
		class text
		{
			public:
				text (void);
			protected:
				db:sql::sqlite db;
		};
	}
}

