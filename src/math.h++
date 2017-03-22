#pragma once
//#ifndef __MATHEMATICS__
//#define __MATHEMATICS__

#include <cln/cln.h>

//#include <string>
//#include <stddef.h>	// For NULL.

//#include "name.h++"
#include "math/number.h++"

namespace noware
{
	namespace math
	{
		namespace numbers
		{
			//using namespace LIB::mathematics::numbers;
			
			//typedef long double real;
			//typedef signed long long int integer;
			//typedef unsigned long long int natural;
			
			
			// An abstract class.
			typedef cln::cl_R real;	// To be removed.
			
			// Initial/Non-recomputed/Non-"lazy recomputation",
			// Unlimited-precision,
			// Long,
			// Floating-point
			// numbers:
			typedef cln::cl_LF d/*ouble*//* *//*long float*/;
			
			// Floating-point numbers.
			// An abstract class.
			typedef cln::cl_F f/*loat*/;
			
			
			// Exact Real numbers:
			typedef cln::cl_RA rational;
			
			typedef cln::cl_I integer;
			
			typedef cln::cl_I natural;	// To be removed.
			
			//static const unsigned short int DEFAULT = 0;
			//static const natural _default = 0;	// false, 0;
			
		}
		
		//namespace number = numbers;
		
		//typedef int Integer, Number;
		//typedef numbers::real number;
		
		// Complex
		// or
		// Real
		// numbers:
	//	typedef cln::cl_N number;
	}
	
	//namespace math = mathematics;
	
	
	namespace numbers
	{
		typedef math::numbers::rational	rational;
		 typedef math::numbers::real		real;
		typedef math::numbers::integer	integer;
		 typedef math::numbers::natural	natural;
	}
	
	typedef math::number number;
}

//#endif
