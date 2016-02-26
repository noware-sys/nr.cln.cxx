#pragma once
//#ifndef NUMBER
//#define NUMBER
/*
//#include <boost/any.hpp>
#include <string>
#include <iostream>
#include <fstream>
*/
/*
	// The- GNU Multiple Precision Arithmetic Library:
	#include <stdio.h>
	#include <stdarg.h>
	#include <obstack.h>
	#include <gmp.h>
*/

#include <cln/cln.h>
/*
///#include <algorithm>
//#include <cstdlib>
//#include <cmath>
//#include <deque>
//#include <iostream>
//#include <list>
//#include <set>
//#include <map>
//#include <boost/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>

//#include <boost/array.hpp>
//#include <boost/asio.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "../default.h++"
#include "../tools.h++"
*/
/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
namespace noware
{
	//class NAME_V;

	//typedef NAME_V var;
	namespace math
	{
		typedef cln::cl_R number;
		/*
		class number
		{
			public:
				// An abstract class.
				typedef cln::cl_R real;	// To be removed.
			
				// Initial/Non-recomputed/Non-"lazy recomputation",
				// Unlimited-precision,
				// Long,
				// Floating-point
				// numbers:
				//typedef cln::cl_LF double long float;
				typedef cln::cl_LF d;
			
				// Floating-point numbers.
				// An abstract class.
				// float
				typedef cln::cl_F f;
			
			
				// Exact Real numbers:
				typedef cln::cl_RA rational;
			
				typedef cln::cl_I integer;
			
				typedef cln::cl_I natural;	// To be removed.
			
				//static const unsigned short int DEFAULT = 0;
				//static const natural _default = 0;	// false, 0;
			protected:
		};
		*/
	}
}

//#endif

