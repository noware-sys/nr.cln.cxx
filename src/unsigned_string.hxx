#pragma once

#include <string>
//#include <bits/basic_string.h>
//#include <bits/basic_string.tcc>

namespace noware
{
	typedef std::basic_string <unsigned char> unsigned_string;
	
	std::ostream & operator << (std::ostream &, const unsigned_string &)/* const*/;
}
