#pragma once

//#ifndef NUMBER
//#define NUMBER
#include <string>
/*
//#include <boost/any.hpp>
#include <iostream>
#include <fstream>
*/
/*
	// The GNU Multiple Precision Arithmetic Library:
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
*/
//#include "../text.hdr.cxx"
//#include "../array.hxx"
#include "tool/number.hdr.cxx"
#include "tool/string.hdr.cxx"
/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
//#include ".number/header.hxx"

namespace noware
{
	//class NAME_V;

	//typedef NAME_V var;
	//namespace math
	//{
		//typedef cln::cl_N number;
		//typedef cln::cl_R number;
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
		class number
		{
			public:
				enum class type
				{
					complex,
					real,
					imaginary,
					rational,
					irrational,
					integer,
					natural,
					even,
					odd,
					prime
				};
				
				typedef cln::cl_number number, nr, no, n;						// abstract
				typedef cln::cl_N complex, c;
				typedef cln::cl_R real, rea, re;										// abstract
				typedef cln::cl_RA rational, rat, ra;
				typedef cln::cl_I integer, i;
				typedef cln::cl_I natural, natur;
				typedef cln::cl_F _float/*, flt*/, f, f0;									// abstract
				typedef cln::cl_SF short_float, sfloat, sf, f1;
				typedef cln::cl_FF single_float, ffloat, ff, f2;
				typedef cln::cl_DF double_float, dfloat, df, f3;
				typedef cln::cl_LF long_float, lfloat, lf, f4;
				
				/*
				#include ".number/rule.hxx"
				
				#include ".number/constructor.hxx"
				#include ".number/destructor.hxx"
				
				#include ".number/set.hxx"
				#include ".number/conversion.hxx"
				
				#include ".number/comparison.hxx"
				
				#include ".number/addition.hxx"
				#include ".number/substraction.hxx"
				//
				#include ".number/multiplication.hxx"
				#include ".number/division.hxx"
				//
				#include ".number/exponentiation.hxx"
				#include ".number/modulo.hxx"
				
				#include ".number/special.hxx"
				*/
				#include ".number/.hdr.cxx"
				
				template <typename archive>
				void serialize (archive &, const unsigned int &);
				
				//const bool limit (const rule &);	// limit restrict
				//const noware::array <rule> & limits (void) const;	// rules limits restrictions
				//const bool limited (void) const;
				
				const std::string string (void) const;	// to_string
				//const std::string text (void) const;	// to_string
				//const noware::text text (void) const;	// to_text
				// const bool exact (void) const;
				const type category (void) const;	// type category determine specific specify
				//const bool categorized (const type &/**/) const;	// typed categorized classified
			protected:
				complex content;	// content value
				//noware::array <rule> rules;
				//bool _exact;	// exact precise approximated rounded consistent
		};
	//}
}

//#endif
