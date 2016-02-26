#include <string>
#include <stddef.h>	// For NULL

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0610
#endif _WIN32_WINNT

#ifndef LIB
#define LIB NoWare
#endif LIB

#ifndef _Default
#define _Default

namespace LIB
{
	namespace Mathematics
	{
		namespace Algebra
		{
			namespace Elementary
			{
			}
		}
	}

	namespace Numbers
	{
		typedef long double Real;
		typedef signed long long int Integer;
		typedef unsigned long long int Natural;
	}
}

#endif _Default
