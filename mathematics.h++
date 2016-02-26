#pragma once
//#ifndef __MATHEMATICS__
//#define __MATHEMATICS__

#include <cln/cln.h>

//#include <string>
//#include <stddef.h>	// For NULL.

#include "default.h++"

namespace LIB
{
	namespace mathematics
	{
		namespace numbers
		{
			//using namespace LIB::mathematics::numbers;
			
			//typedef long double real;
			//typedef signed long long int integer;
			//typedef unsigned long long int natural;
			
			typedef cln::cl_RA rational;
			typedef cln::cl_R real;
			typedef cln::cl_I integer;
			typedef cln::cl_I natural;
			
			//static const unsigned short int DEFAULT = 0;
			//static const bool _default = false;	// false, 0;
		}
		
		//typedef int Integer, Number;
		//typedef numbers::real number;
		typedef cln::cl_N number;
	}
	
	namespace math = mathematics;
	
	
	namespace numbers
	{
		typedef mathematics::numbers::rational	rational;
		typedef mathematics::numbers::real		real;
		typedef mathematics::numbers::integer	integer;
		typedef mathematics::numbers::natural	natural;
	}
	
	typedef mathematics::number number;
}

//#endif
