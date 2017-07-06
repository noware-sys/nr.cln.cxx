#pragma once

#include <string>
//#include <iostream>
//#include <fstream>

namespace noware
{
	#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__))
		void pause (const std::string & = "Press any key to continue . . . ");
	#else
		void pause (const std::string & = "Press [Enter] to continue . . . ");
	#endif
}
