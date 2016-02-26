#ifndef DEFAULT
#define DEFAULT

#include <string>
#include <cstddef>	// For NULL

/*
	Please define _WIN32_WINNT or _WIN32_WINDOWS appropriately. For example:
	- add -D_WIN32_WINNT=0x0501 to the compiler command line; or
	- add _WIN32_WINNT=0x0501 to your project's Preprocessor Definitions.
	Assuming _WIN32_WINNT=0x0501 (i.e. Windows XP target).
*/
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0610
#endif

//#define BOOST_EXCEPTION_DISABLE 1

#ifndef LIB
#define LIB noware
#endif

namespace LIB
{
	//namespace mathematics;

	//namespace math = mathematics;
	
	namespace default_
	{
		static const std::string			GENERIC	= "";
		static const char					CHARACTER	= '\0';
		static const unsigned short int		NUMERIC	= 0;
		//static const bool					BOOLEAN	= false;
	}
	
}

#endif
