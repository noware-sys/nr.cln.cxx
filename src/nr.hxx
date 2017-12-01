#pragma once

//#ifndef NUMBER
//#define NUMBER
#include <string>
/*
//#include <boost::/any.hpp>
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
//#include <boost::/bind.hpp>
//#include <boost::/shared_ptr.hpp>
//#include <boost::/enable_shared_from_this.hpp>

//#include <boost::/array.hpp>
//#include <boost::/asio.hpp>
#include <boost::/serialization/serialization.hpp>
#include <boost::/archive/text_oarchive.hpp>
#include <boost::/archive/text_iarchive.hpp>

#include "../default.h++"
*/
#include <boost/operators.hpp>

//#include "../text.hdr.cxx"
//#include "../array.hxx"

//#include "tool/nr.hxx"			// is_nr()
#include "tool/string.hxx"	// convert to string
//#include "misc/serial.hxx"	// serialization class
#include "serial.hxx"	// for serialization class
/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
#include ".nr/.incl.hxx"
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
		class nr
			: virtual public serial
			, boost::equality_comparable <nr>
			, boost::equality_comparable <nr, std::string>
			, boost::equality_comparable <nr, char *>
			, boost::equality_comparable <nr, char>
		//	, boost::equality_comparable <nr, unsigned char>
		//	, boost::equality_comparable <nr, signed char>
			, boost::equality_comparable <nr, cln::cl_N>
			, boost::equality_comparable <nr, cln::cl_R>
			, boost::equality_comparable <nr, cln::cl_RA>
			, boost::equality_comparable <nr, cln::cl_I>
			, boost::equality_comparable <nr, cln::cl_F>
			, boost::equality_comparable <nr, cln::cl_SF>
			, boost::equality_comparable <nr, cln::cl_FF>
			, boost::equality_comparable <nr, cln::cl_DF>
			, boost::equality_comparable <nr, cln::cl_LF>
			, boost::equality_comparable <nr, long double>
			, boost::equality_comparable <nr, double>
			, boost::equality_comparable <nr, float>
			, boost::equality_comparable <nr, unsigned long long int>
			, boost::equality_comparable <nr, unsigned long int>
			, boost::equality_comparable <nr, unsigned int>
			, boost::equality_comparable <nr, unsigned short int>
			, boost::equality_comparable <nr, signed long long int>
			, boost::equality_comparable <nr, signed long int>
			, boost::equality_comparable <nr, signed int>
			, boost::equality_comparable <nr, signed short int>
			/*
			, boost::less_than_comparable <nr>
			, boost::less_than_comparable <nr, std::string>
			, boost::less_than_comparable <nr, char *>
			, boost::less_than_comparable <nr, char>
		//	, boost::less_than_comparable <nr, unsigned char>
		//	, boost::less_than_comparable <nr, signed char>
			, boost::less_than_comparable <nr, cln::cl_N>
			, boost::less_than_comparable <nr, cln::cl_R>
			, boost::less_than_comparable <nr, cln::cl_RA>
			, boost::less_than_comparable <nr, cln::cl_I>
			, boost::less_than_comparable <nr, cln::cl_F>
			, boost::less_than_comparable <nr, cln::cl_SF>
			, boost::less_than_comparable <nr, cln::cl_FF>
			, boost::less_than_comparable <nr, cln::cl_DF>
			, boost::less_than_comparable <nr, cln::cl_LF>
			, boost::less_than_comparable <nr, long double>
			, boost::less_than_comparable <nr, double>
			, boost::less_than_comparable <nr, float>
			, boost::less_than_comparable <nr, unsigned long long int>
			, boost::less_than_comparable <nr, unsigned long int>
			, boost::less_than_comparable <nr, unsigned int>
			, boost::less_than_comparable <nr, unsigned short int>
			, boost::less_than_comparable <nr, signed long long int>
			, boost::less_than_comparable <nr, signed long int>
			, boost::less_than_comparable <nr, signed int>
			, boost::less_than_comparable <nr, signed short int>
			*/
			, boost::addable <nr>
			, boost::addable <nr, std::string>
			, boost::addable <nr, char *>
			, boost::addable <nr, char>
		//	, boost::addable <nr, unsigned char>
		//	, boost::addable <nr, signed char>
			, boost::addable <nr, cln::cl_N>
			, boost::addable <nr, cln::cl_R>
			, boost::addable <nr, cln::cl_RA>
			, boost::addable <nr, cln::cl_I>
			, boost::addable <nr, cln::cl_F>
			, boost::addable <nr, cln::cl_SF>
			, boost::addable <nr, cln::cl_FF>
			, boost::addable <nr, cln::cl_DF>
			, boost::addable <nr, cln::cl_LF>
			, boost::addable <nr, long double>
			, boost::addable <nr, double>
			, boost::addable <nr, float>
			, boost::addable <nr, unsigned long long int>
			, boost::addable <nr, unsigned long int>
			, boost::addable <nr, unsigned int>
			, boost::addable <nr, unsigned short int>
			, boost::addable <nr, signed long long int>
			, boost::addable <nr, signed long int>
			, boost::addable <nr, signed int>
			, boost::addable <nr, signed short int>
			, boost::subtractable <nr>
			, boost::subtractable <nr, std::string>
			, boost::subtractable <nr, char *>
			, boost::subtractable <nr, char>
		//	, boost::subtractable <nr, unsigned char>
		//	, boost::subtractable <nr, signed char>
			, boost::subtractable <nr, cln::cl_N>
			, boost::subtractable <nr, cln::cl_R>
			, boost::subtractable <nr, cln::cl_RA>
			, boost::subtractable <nr, cln::cl_I>
			, boost::subtractable <nr, cln::cl_F>
			, boost::subtractable <nr, cln::cl_SF>
			, boost::subtractable <nr, cln::cl_FF>
			, boost::subtractable <nr, cln::cl_DF>
			, boost::subtractable <nr, cln::cl_LF>
			, boost::subtractable <nr, long double>
			, boost::subtractable <nr, double>
			, boost::subtractable <nr, float>
			, boost::subtractable <nr, unsigned long long int>
			, boost::subtractable <nr, unsigned long int>
			, boost::subtractable <nr, unsigned int>
			, boost::subtractable <nr, unsigned short int>
			, boost::subtractable <nr, signed long long int>
			, boost::subtractable <nr, signed long int>
			, boost::subtractable <nr, signed int>
			, boost::subtractable <nr, signed short int>
			, boost::subtractable2_left <nr, std::string>
			, boost::subtractable2_left <nr, char *>
			, boost::subtractable2_left <nr, char>
		//	, boost::subtractable2_left <nr, unsigned char>
		//	, boost::subtractable2_left <nr, signed char>
			, boost::subtractable2_left <nr, cln::cl_N>
			, boost::subtractable2_left <nr, cln::cl_R>
			, boost::subtractable2_left <nr, cln::cl_RA>
			, boost::subtractable2_left <nr, cln::cl_I>
			, boost::subtractable2_left <nr, cln::cl_F>
			, boost::subtractable2_left <nr, cln::cl_SF>
			, boost::subtractable2_left <nr, cln::cl_FF>
			, boost::subtractable2_left <nr, cln::cl_DF>
			, boost::subtractable2_left <nr, cln::cl_LF>
			, boost::subtractable2_left <nr, long double>
			, boost::subtractable2_left <nr, double>
			, boost::subtractable2_left <nr, float>
			, boost::subtractable2_left <nr, unsigned long long int>
			, boost::subtractable2_left <nr, unsigned long int>
			, boost::subtractable2_left <nr, unsigned int>
			, boost::subtractable2_left <nr, unsigned short int>
			, boost::subtractable2_left <nr, signed long long int>
			, boost::subtractable2_left <nr, signed long int>
			, boost::subtractable2_left <nr, signed int>
			, boost::subtractable2_left <nr, signed short int>
			, boost::multipliable <nr>
			, boost::multipliable <nr, std::string>
			, boost::multipliable <nr, char *>
			, boost::multipliable <nr, char>
		//	, boost::multipliable <nr, unsigned char>
		//	, boost::multipliable <nr, signed char>
			, boost::multipliable <nr, cln::cl_N>
			, boost::multipliable <nr, cln::cl_R>
			, boost::multipliable <nr, cln::cl_RA>
			, boost::multipliable <nr, cln::cl_I>
			, boost::multipliable <nr, cln::cl_F>
			, boost::multipliable <nr, cln::cl_SF>
			, boost::multipliable <nr, cln::cl_FF>
			, boost::multipliable <nr, cln::cl_DF>
			, boost::multipliable <nr, cln::cl_LF>
			, boost::multipliable <nr, long double>
			, boost::multipliable <nr, double>
			, boost::multipliable <nr, float>
			, boost::multipliable <nr, unsigned long long int>
			, boost::multipliable <nr, unsigned long int>
			, boost::multipliable <nr, unsigned int>
			, boost::multipliable <nr, unsigned short int>
			, boost::multipliable <nr, signed long long int>
			, boost::multipliable <nr, signed long int>
			, boost::multipliable <nr, signed int>
			, boost::multipliable <nr, signed short int>
			, boost::dividable <nr>
			, boost::dividable <nr, std::string>
			, boost::dividable <nr, char *>
			, boost::dividable <nr, char>
		//	, boost::dividable <nr, unsigned char>
		//	, boost::dividable <nr, signed char>
			, boost::dividable <nr, cln::cl_N>
			, boost::dividable <nr, cln::cl_R>
			, boost::dividable <nr, cln::cl_RA>
			, boost::dividable <nr, cln::cl_I>
			, boost::dividable <nr, cln::cl_F>
			, boost::dividable <nr, cln::cl_SF>
			, boost::dividable <nr, cln::cl_FF>
			, boost::dividable <nr, cln::cl_DF>
			, boost::dividable <nr, cln::cl_LF>
			, boost::dividable <nr, long double>
			, boost::dividable <nr, double>
			, boost::dividable <nr, float>
			, boost::dividable <nr, unsigned long long int>
			, boost::dividable <nr, unsigned long int>
			, boost::dividable <nr, unsigned int>
			, boost::dividable <nr, unsigned short int>
			, boost::dividable <nr, signed long long int>
			, boost::dividable <nr, signed long int>
			, boost::dividable <nr, signed int>
			, boost::dividable <nr, signed short int>
			, boost::dividable2_left <nr, std::string>
			, boost::dividable2_left <nr, char *>
			, boost::dividable2_left <nr, char>
		//	, boost::dividable2_left <nr, unsigned char>
		//	, boost::dividable2_left <nr, signed char>
			, boost::dividable2_left <nr, cln::cl_N>
			, boost::dividable2_left <nr, cln::cl_R>
			, boost::dividable2_left <nr, cln::cl_RA>
			, boost::dividable2_left <nr, cln::cl_I>
			, boost::dividable2_left <nr, cln::cl_F>
			, boost::dividable2_left <nr, cln::cl_SF>
			, boost::dividable2_left <nr, cln::cl_FF>
			, boost::dividable2_left <nr, cln::cl_DF>
			, boost::dividable2_left <nr, cln::cl_LF>
			, boost::dividable2_left <nr, long double>
			, boost::dividable2_left <nr, double>
			, boost::dividable2_left <nr, float>
			, boost::dividable2_left <nr, unsigned long long int>
			, boost::dividable2_left <nr, unsigned long int>
			, boost::dividable2_left <nr, unsigned int>
			, boost::dividable2_left <nr, unsigned short int>
			, boost::dividable2_left <nr, signed long long int>
			, boost::dividable2_left <nr, signed long int>
			, boost::dividable2_left <nr, signed int>
			, boost::dividable2_left <nr, signed short int>
			, boost::modable <nr>
			, boost::modable <nr, std::string>
			, boost::modable <nr, char *>
			, boost::modable <nr, char>
		//	, boost::modable <nr, unsigned char>
		//	, boost::modable <nr, signed char>
			, boost::modable <nr, cln::cl_N>
			, boost::modable <nr, cln::cl_R>
			, boost::modable <nr, cln::cl_RA>
			, boost::modable <nr, cln::cl_I>
			, boost::modable <nr, cln::cl_F>
			, boost::modable <nr, cln::cl_SF>
			, boost::modable <nr, cln::cl_FF>
			, boost::modable <nr, cln::cl_DF>
			, boost::modable <nr, cln::cl_LF>
			, boost::modable <nr, long double>
			, boost::modable <nr, double>
			, boost::modable <nr, float>
			, boost::modable <nr, unsigned long long int>
			, boost::modable <nr, unsigned long int>
			, boost::modable <nr, unsigned int>
			, boost::modable <nr, unsigned short int>
			, boost::modable <nr, signed long long int>
			, boost::modable <nr, signed long int>
			, boost::modable <nr, signed int>
			, boost::modable <nr, signed short int>
			, boost::modable2_left <nr, std::string>
			, boost::modable2_left <nr, char *>
			, boost::modable2_left <nr, char>
		//	, boost::modable2_left <nr, unsigned char>
		//	, boost::modable2_left <nr, signed char>
			, boost::modable2_left <nr, cln::cl_N>
			, boost::modable2_left <nr, cln::cl_R>
			, boost::modable2_left <nr, cln::cl_RA>
			, boost::modable2_left <nr, cln::cl_I>
			, boost::modable2_left <nr, cln::cl_F>
			, boost::modable2_left <nr, cln::cl_SF>
			, boost::modable2_left <nr, cln::cl_FF>
			, boost::modable2_left <nr, cln::cl_DF>
			, boost::modable2_left <nr, cln::cl_LF>
			, boost::modable2_left <nr, long double>
			, boost::modable2_left <nr, double>
			, boost::modable2_left <nr, float>
			, boost::modable2_left <nr, unsigned long long int>
			, boost::modable2_left <nr, unsigned long int>
			, boost::modable2_left <nr, unsigned int>
			, boost::modable2_left <nr, unsigned short int>
			, boost::modable2_left <nr, signed long long int>
			, boost::modable2_left <nr, signed long int>
			, boost::modable2_left <nr, signed int>
			, boost::modable2_left <nr, signed short int>
			, boost::xorable <nr>
			, boost::xorable <nr, std::string>
			, boost::xorable <nr, char *>
			, boost::xorable <nr, char>
		//	, boost::xorable <nr, unsigned char>
		//	, boost::xorable <nr, signed char>
			, boost::xorable <nr, cln::cl_N>
			, boost::xorable <nr, cln::cl_R>
			, boost::xorable <nr, cln::cl_RA>
			, boost::xorable <nr, cln::cl_I>
			, boost::xorable <nr, cln::cl_F>
			, boost::xorable <nr, cln::cl_SF>
			, boost::xorable <nr, cln::cl_FF>
			, boost::xorable <nr, cln::cl_DF>
			, boost::xorable <nr, cln::cl_LF>
			, boost::xorable <nr, long double>
			, boost::xorable <nr, double>
			, boost::xorable <nr, float>
			, boost::xorable <nr, unsigned long long int>
			, boost::xorable <nr, unsigned long int>
			, boost::xorable <nr, unsigned int>
			, boost::xorable <nr, unsigned short int>
			, boost::xorable <nr, signed long long int>
			, boost::xorable <nr, signed long int>
			, boost::xorable <nr, signed int>
			, boost::xorable <nr, signed short int>
			, boost::incrementable <nr>
			, boost::decrementable <nr>
		//	, boost::equivalent <nr>
			
			, boost::partially_ordered <nr>
			, boost::partially_ordered <nr, std::string>
			, boost::partially_ordered <nr, char *>
			, boost::partially_ordered <nr, char>
		//	, boost::partially_ordered <nr, unsigned char>
		//	, boost::partially_ordered <nr, signed char>
			, boost::partially_ordered <nr, cln::cl_N>
			, boost::partially_ordered <nr, cln::cl_R>
			, boost::partially_ordered <nr, cln::cl_RA>
			, boost::partially_ordered <nr, cln::cl_I>
			, boost::partially_ordered <nr, cln::cl_F>
			, boost::partially_ordered <nr, cln::cl_SF>
			, boost::partially_ordered <nr, cln::cl_FF>
			, boost::partially_ordered <nr, cln::cl_DF>
			, boost::partially_ordered <nr, cln::cl_LF>
			, boost::partially_ordered <nr, long double>
			, boost::partially_ordered <nr, double>
			, boost::partially_ordered <nr, float>
			, boost::partially_ordered <nr, unsigned long long int>
			, boost::partially_ordered <nr, unsigned long int>
			, boost::partially_ordered <nr, unsigned int>
			, boost::partially_ordered <nr, unsigned short int>
			, boost::partially_ordered <nr, signed long long int>
			, boost::partially_ordered <nr, signed long int>
			, boost::partially_ordered <nr, signed int>
			, boost::partially_ordered <nr, signed short int>
			
		{
			public:
				enum class type
				{
					complex,
					lateral,
					imaginary,
					real,
					rational,
					irrational,
					integer,
					natural
				};
				
				enum class category
				{
					zero,
					infinitesimal,
					infinity,
					positive,
					negative,
					nonpositive,
					nonnegative,
					odd,
					even,
					prime
				};
				
				// abstract:
				typedef cln::cl_number number/*, nr*/, no, n;
				typedef cln::cl_N complex, c;
				// abstract:
				typedef cln::cl_R real, rea, re, r;
				typedef cln::cl_RA rational, ration, rat, ra;
				typedef cln::cl_I integer, i;
				//typedef cln::cl_I natural, nature, natur, nat, na;
				// abstract:
				typedef cln::cl_F _float/*, flt*/, f/*, f0*/;
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
				/*
				#include ".var/constr.hxx"
				#include ".var/destr.hxx"
				
				#include ".var/set.hxx"
				
				#include ".var/conver.hxx"
				
				#include ".var/compar.hxx"
				
				#include ".var/add.hxx"
				#include ".var/substr.hxx"
				//
				#include ".var/multi.hxx"
				#include ".var/div.hxx"
				//
				#include ".var/exponent.hxx"
				#include ".var/modulo.hxx"
				
				#include ".var/special.hxx"
				*/
				#include ".nr/.hxx"
				
			//	template <typename archive>
			//	void serialize (archive &, const unsigned int &);
				
				//const bool limit (const rule &);	// limit restrict
				//const noware::array <rule> & limits (void) const;	// rules limits restrictions
				//const bool limited (void) const;
				
				//operator const std::string (void) const;	// to_string
				//const noware::text text (void) const;	// to_text
				// const bool exact (void) const;
				
				// t[ype] class cat[egory] det[ermine] spec[ific] spec[ify]
				//const type kind (void) const;
				//const category cat (void) const;
				// typed categorized classified
				//const bool categorized (const type &/**/) const;
			protected:
				friend class boost::serialization::access;
				
				complex contnt;	// content value
				//noware::array <rule> rules;
				//bool _exact;	// exact precise approximated rounded consistent
				
				template <typename archive>
				void serialize (archive &, const unsigned int &/* version*/);
		};
	//}
}

//#endif

std::istream & getline (std::istream &, noware::nr &, const char = '\n');
