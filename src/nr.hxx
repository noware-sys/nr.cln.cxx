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
#include <noware/tool/string.hxx>	// convert to string
#include <noware/misc/serial.hxx>	// serialization class
//#include <noware/serial.hxx>	// for the serialization class
/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
#include ".nr/.incl.hxx"
//#include ".number/header.hxx"

namespace cln
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
			: virtual public noware::serial
			, virtual public boost::equality_comparable <nr>
			, virtual public boost::equality_comparable <nr, std::string>
			, virtual public boost::equality_comparable <nr, char *>
			, virtual public boost::equality_comparable <nr, char>
		//	, virtual public boost::equality_comparable <nr, unsigned char>
		//	, virtual public boost::equality_comparable <nr, signed char>
			, virtual public boost::equality_comparable <nr, cln::cl_N>
			, virtual public boost::equality_comparable <nr, cln::cl_R>
			, virtual public boost::equality_comparable <nr, cln::cl_RA>
			, virtual public boost::equality_comparable <nr, cln::cl_I>
			, virtual public boost::equality_comparable <nr, cln::cl_F>
			, virtual public boost::equality_comparable <nr, cln::cl_SF>
			, virtual public boost::equality_comparable <nr, cln::cl_FF>
			, virtual public boost::equality_comparable <nr, cln::cl_DF>
			, virtual public boost::equality_comparable <nr, cln::cl_LF>
			, virtual public boost::equality_comparable <nr, long double>
			, virtual public boost::equality_comparable <nr, double>
			, virtual public boost::equality_comparable <nr, float>
			, virtual public boost::equality_comparable <nr, unsigned long long int>
			, virtual public boost::equality_comparable <nr, unsigned long int>
			, virtual public boost::equality_comparable <nr, unsigned int>
			, virtual public boost::equality_comparable <nr, unsigned short int>
			, virtual public boost::equality_comparable <nr, signed long long int>
			, virtual public boost::equality_comparable <nr, signed long int>
			, virtual public boost::equality_comparable <nr, signed int>
			, virtual public boost::equality_comparable <nr, signed short int>
			/*
			, virtual public boost::less_than_comparable <nr>
			, virtual public boost::less_than_comparable <nr, std::string>
			, virtual public boost::less_than_comparable <nr, char *>
			, virtual public boost::less_than_comparable <nr, char>
		//	, virtual public boost::less_than_comparable <nr, unsigned char>
		//	, virtual public boost::less_than_comparable <nr, signed char>
			, virtual public boost::less_than_comparable <nr, cln::cl_N>
			, virtual public boost::less_than_comparable <nr, cln::cl_R>
			, virtual public boost::less_than_comparable <nr, cln::cl_RA>
			, virtual public boost::less_than_comparable <nr, cln::cl_I>
			, virtual public boost::less_than_comparable <nr, cln::cl_F>
			, virtual public boost::less_than_comparable <nr, cln::cl_SF>
			, virtual public boost::less_than_comparable <nr, cln::cl_FF>
			, virtual public boost::less_than_comparable <nr, cln::cl_DF>
			, virtual public boost::less_than_comparable <nr, cln::cl_LF>
			, virtual public boost::less_than_comparable <nr, long double>
			, virtual public boost::less_than_comparable <nr, double>
			, virtual public boost::less_than_comparable <nr, float>
			, virtual public boost::less_than_comparable <nr, unsigned long long int>
			, virtual public boost::less_than_comparable <nr, unsigned long int>
			, virtual public boost::less_than_comparable <nr, unsigned int>
			, virtual public boost::less_than_comparable <nr, unsigned short int>
			, virtual public boost::less_than_comparable <nr, signed long long int>
			, virtual public boost::less_than_comparable <nr, signed long int>
			, virtual public boost::less_than_comparable <nr, signed int>
			, virtual public boost::less_than_comparable <nr, signed short int>
			*/
			, virtual public boost::addable <nr>
			, virtual public boost::addable <nr, std::string>
			, virtual public boost::addable <nr, char *>
			, virtual public boost::addable <nr, char>
		//	, virtual public boost::addable <nr, unsigned char>
		//	, virtual public boost::addable <nr, signed char>
			, virtual public boost::addable <nr, cln::cl_N>
			, virtual public boost::addable <nr, cln::cl_R>
			, virtual public boost::addable <nr, cln::cl_RA>
			, virtual public boost::addable <nr, cln::cl_I>
			, virtual public boost::addable <nr, cln::cl_F>
			, virtual public boost::addable <nr, cln::cl_SF>
			, virtual public boost::addable <nr, cln::cl_FF>
			, virtual public boost::addable <nr, cln::cl_DF>
			, virtual public boost::addable <nr, cln::cl_LF>
			, virtual public boost::addable <nr, long double>
			, virtual public boost::addable <nr, double>
			, virtual public boost::addable <nr, float>
			, virtual public boost::addable <nr, unsigned long long int>
			, virtual public boost::addable <nr, unsigned long int>
			, virtual public boost::addable <nr, unsigned int>
			, virtual public boost::addable <nr, unsigned short int>
			, virtual public boost::addable <nr, signed long long int>
			, virtual public boost::addable <nr, signed long int>
			, virtual public boost::addable <nr, signed int>
			, virtual public boost::addable <nr, signed short int>
			, virtual public boost::subtractable <nr>
			, virtual public boost::subtractable <nr, std::string>
			, virtual public boost::subtractable <nr, char *>
			, virtual public boost::subtractable <nr, char>
		//	, virtual public boost::subtractable <nr, unsigned char>
		//	, virtual public boost::subtractable <nr, signed char>
			, virtual public boost::subtractable <nr, cln::cl_N>
			, virtual public boost::subtractable <nr, cln::cl_R>
			, virtual public boost::subtractable <nr, cln::cl_RA>
			, virtual public boost::subtractable <nr, cln::cl_I>
			, virtual public boost::subtractable <nr, cln::cl_F>
			, virtual public boost::subtractable <nr, cln::cl_SF>
			, virtual public boost::subtractable <nr, cln::cl_FF>
			, virtual public boost::subtractable <nr, cln::cl_DF>
			, virtual public boost::subtractable <nr, cln::cl_LF>
			, virtual public boost::subtractable <nr, long double>
			, virtual public boost::subtractable <nr, double>
			, virtual public boost::subtractable <nr, float>
			, virtual public boost::subtractable <nr, unsigned long long int>
			, virtual public boost::subtractable <nr, unsigned long int>
			, virtual public boost::subtractable <nr, unsigned int>
			, virtual public boost::subtractable <nr, unsigned short int>
			, virtual public boost::subtractable <nr, signed long long int>
			, virtual public boost::subtractable <nr, signed long int>
			, virtual public boost::subtractable <nr, signed int>
			, virtual public boost::subtractable <nr, signed short int>
			, virtual public boost::subtractable2_left <nr, std::string>
			, virtual public boost::subtractable2_left <nr, char *>
			, virtual public boost::subtractable2_left <nr, char>
		//	, virtual public boost::subtractable2_left <nr, unsigned char>
		//	, virtual public boost::subtractable2_left <nr, signed char>
			, virtual public boost::subtractable2_left <nr, cln::cl_N>
			, virtual public boost::subtractable2_left <nr, cln::cl_R>
			, virtual public boost::subtractable2_left <nr, cln::cl_RA>
			, virtual public boost::subtractable2_left <nr, cln::cl_I>
			, virtual public boost::subtractable2_left <nr, cln::cl_F>
			, virtual public boost::subtractable2_left <nr, cln::cl_SF>
			, virtual public boost::subtractable2_left <nr, cln::cl_FF>
			, virtual public boost::subtractable2_left <nr, cln::cl_DF>
			, virtual public boost::subtractable2_left <nr, cln::cl_LF>
			, virtual public boost::subtractable2_left <nr, long double>
			, virtual public boost::subtractable2_left <nr, double>
			, virtual public boost::subtractable2_left <nr, float>
			, virtual public boost::subtractable2_left <nr, unsigned long long int>
			, virtual public boost::subtractable2_left <nr, unsigned long int>
			, virtual public boost::subtractable2_left <nr, unsigned int>
			, virtual public boost::subtractable2_left <nr, unsigned short int>
			, virtual public boost::subtractable2_left <nr, signed long long int>
			, virtual public boost::subtractable2_left <nr, signed long int>
			, virtual public boost::subtractable2_left <nr, signed int>
			, virtual public boost::subtractable2_left <nr, signed short int>
			, virtual public boost::multipliable <nr>
			, virtual public boost::multipliable <nr, std::string>
			, virtual public boost::multipliable <nr, char *>
			, virtual public boost::multipliable <nr, char>
		//	, virtual public boost::multipliable <nr, unsigned char>
		//	, virtual public boost::multipliable <nr, signed char>
			, virtual public boost::multipliable <nr, cln::cl_N>
			, virtual public boost::multipliable <nr, cln::cl_R>
			, virtual public boost::multipliable <nr, cln::cl_RA>
			, virtual public boost::multipliable <nr, cln::cl_I>
			, virtual public boost::multipliable <nr, cln::cl_F>
			, virtual public boost::multipliable <nr, cln::cl_SF>
			, virtual public boost::multipliable <nr, cln::cl_FF>
			, virtual public boost::multipliable <nr, cln::cl_DF>
			, virtual public boost::multipliable <nr, cln::cl_LF>
			, virtual public boost::multipliable <nr, long double>
			, virtual public boost::multipliable <nr, double>
			, virtual public boost::multipliable <nr, float>
			, virtual public boost::multipliable <nr, unsigned long long int>
			, virtual public boost::multipliable <nr, unsigned long int>
			, virtual public boost::multipliable <nr, unsigned int>
			, virtual public boost::multipliable <nr, unsigned short int>
			, virtual public boost::multipliable <nr, signed long long int>
			, virtual public boost::multipliable <nr, signed long int>
			, virtual public boost::multipliable <nr, signed int>
			, virtual public boost::multipliable <nr, signed short int>
			, virtual public boost::dividable <nr>
			, virtual public boost::dividable <nr, std::string>
			, virtual public boost::dividable <nr, char *>
			, virtual public boost::dividable <nr, char>
		//	, virtual public boost::dividable <nr, unsigned char>
		//	, virtual public boost::dividable <nr, signed char>
			, virtual public boost::dividable <nr, cln::cl_N>
			, virtual public boost::dividable <nr, cln::cl_R>
			, virtual public boost::dividable <nr, cln::cl_RA>
			, virtual public boost::dividable <nr, cln::cl_I>
			, virtual public boost::dividable <nr, cln::cl_F>
			, virtual public boost::dividable <nr, cln::cl_SF>
			, virtual public boost::dividable <nr, cln::cl_FF>
			, virtual public boost::dividable <nr, cln::cl_DF>
			, virtual public boost::dividable <nr, cln::cl_LF>
			, virtual public boost::dividable <nr, long double>
			, virtual public boost::dividable <nr, double>
			, virtual public boost::dividable <nr, float>
			, virtual public boost::dividable <nr, unsigned long long int>
			, virtual public boost::dividable <nr, unsigned long int>
			, virtual public boost::dividable <nr, unsigned int>
			, virtual public boost::dividable <nr, unsigned short int>
			, virtual public boost::dividable <nr, signed long long int>
			, virtual public boost::dividable <nr, signed long int>
			, virtual public boost::dividable <nr, signed int>
			, virtual public boost::dividable <nr, signed short int>
			, virtual public boost::dividable2_left <nr, std::string>
			, virtual public boost::dividable2_left <nr, char *>
			, virtual public boost::dividable2_left <nr, char>
		//	, virtual public boost::dividable2_left <nr, unsigned char>
		//	, virtual public boost::dividable2_left <nr, signed char>
			, virtual public boost::dividable2_left <nr, cln::cl_N>
			, virtual public boost::dividable2_left <nr, cln::cl_R>
			, virtual public boost::dividable2_left <nr, cln::cl_RA>
			, virtual public boost::dividable2_left <nr, cln::cl_I>
			, virtual public boost::dividable2_left <nr, cln::cl_F>
			, virtual public boost::dividable2_left <nr, cln::cl_SF>
			, virtual public boost::dividable2_left <nr, cln::cl_FF>
			, virtual public boost::dividable2_left <nr, cln::cl_DF>
			, virtual public boost::dividable2_left <nr, cln::cl_LF>
			, virtual public boost::dividable2_left <nr, long double>
			, virtual public boost::dividable2_left <nr, double>
			, virtual public boost::dividable2_left <nr, float>
			, virtual public boost::dividable2_left <nr, unsigned long long int>
			, virtual public boost::dividable2_left <nr, unsigned long int>
			, virtual public boost::dividable2_left <nr, unsigned int>
			, virtual public boost::dividable2_left <nr, unsigned short int>
			, virtual public boost::dividable2_left <nr, signed long long int>
			, virtual public boost::dividable2_left <nr, signed long int>
			, virtual public boost::dividable2_left <nr, signed int>
			, virtual public boost::dividable2_left <nr, signed short int>
			, virtual public boost::modable <nr>
			, virtual public boost::modable <nr, std::string>
			, virtual public boost::modable <nr, char *>
			, virtual public boost::modable <nr, char>
		//	, virtual public boost::modable <nr, unsigned char>
		//	, virtual public boost::modable <nr, signed char>
			, virtual public boost::modable <nr, cln::cl_N>
			, virtual public boost::modable <nr, cln::cl_R>
			, virtual public boost::modable <nr, cln::cl_RA>
			, virtual public boost::modable <nr, cln::cl_I>
			, virtual public boost::modable <nr, cln::cl_F>
			, virtual public boost::modable <nr, cln::cl_SF>
			, virtual public boost::modable <nr, cln::cl_FF>
			, virtual public boost::modable <nr, cln::cl_DF>
			, virtual public boost::modable <nr, cln::cl_LF>
			, virtual public boost::modable <nr, long double>
			, virtual public boost::modable <nr, double>
			, virtual public boost::modable <nr, float>
			, virtual public boost::modable <nr, unsigned long long int>
			, virtual public boost::modable <nr, unsigned long int>
			, virtual public boost::modable <nr, unsigned int>
			, virtual public boost::modable <nr, unsigned short int>
			, virtual public boost::modable <nr, signed long long int>
			, virtual public boost::modable <nr, signed long int>
			, virtual public boost::modable <nr, signed int>
			, virtual public boost::modable <nr, signed short int>
			, virtual public boost::modable2_left <nr, std::string>
			, virtual public boost::modable2_left <nr, char *>
			, virtual public boost::modable2_left <nr, char>
		//	, virtual public boost::modable2_left <nr, unsigned char>
		//	, virtual public boost::modable2_left <nr, signed char>
			, virtual public boost::modable2_left <nr, cln::cl_N>
			, virtual public boost::modable2_left <nr, cln::cl_R>
			, virtual public boost::modable2_left <nr, cln::cl_RA>
			, virtual public boost::modable2_left <nr, cln::cl_I>
			, virtual public boost::modable2_left <nr, cln::cl_F>
			, virtual public boost::modable2_left <nr, cln::cl_SF>
			, virtual public boost::modable2_left <nr, cln::cl_FF>
			, virtual public boost::modable2_left <nr, cln::cl_DF>
			, virtual public boost::modable2_left <nr, cln::cl_LF>
			, virtual public boost::modable2_left <nr, long double>
			, virtual public boost::modable2_left <nr, double>
			, virtual public boost::modable2_left <nr, float>
			, virtual public boost::modable2_left <nr, unsigned long long int>
			, virtual public boost::modable2_left <nr, unsigned long int>
			, virtual public boost::modable2_left <nr, unsigned int>
			, virtual public boost::modable2_left <nr, unsigned short int>
			, virtual public boost::modable2_left <nr, signed long long int>
			, virtual public boost::modable2_left <nr, signed long int>
			, virtual public boost::modable2_left <nr, signed int>
			, virtual public boost::modable2_left <nr, signed short int>
			, virtual public boost::xorable <nr>
			, virtual public boost::xorable <nr, std::string>
			, virtual public boost::xorable <nr, char *>
			, virtual public boost::xorable <nr, char>
		//	, virtual public boost::xorable <nr, unsigned char>
		//	, virtual public boost::xorable <nr, signed char>
			, virtual public boost::xorable <nr, cln::cl_N>
			, virtual public boost::xorable <nr, cln::cl_R>
			, virtual public boost::xorable <nr, cln::cl_RA>
			, virtual public boost::xorable <nr, cln::cl_I>
			, virtual public boost::xorable <nr, cln::cl_F>
			, virtual public boost::xorable <nr, cln::cl_SF>
			, virtual public boost::xorable <nr, cln::cl_FF>
			, virtual public boost::xorable <nr, cln::cl_DF>
			, virtual public boost::xorable <nr, cln::cl_LF>
			, virtual public boost::xorable <nr, long double>
			, virtual public boost::xorable <nr, double>
			, virtual public boost::xorable <nr, float>
			, virtual public boost::xorable <nr, unsigned long long int>
			, virtual public boost::xorable <nr, unsigned long int>
			, virtual public boost::xorable <nr, unsigned int>
			, virtual public boost::xorable <nr, unsigned short int>
			, virtual public boost::xorable <nr, signed long long int>
			, virtual public boost::xorable <nr, signed long int>
			, virtual public boost::xorable <nr, signed int>
			, virtual public boost::xorable <nr, signed short int>
			
			, virtual public boost::incrementable <nr>
			, virtual public boost::decrementable <nr>
		//	, virtual public boost::equivalent <nr>
			
			, virtual public boost::partially_ordered <nr>
			, virtual public boost::partially_ordered <nr, std::string>
			, virtual public boost::partially_ordered <nr, char *>
			, virtual public boost::partially_ordered <nr, char>
		//	, virtual public boost::partially_ordered <nr, unsigned char>
		//	, virtual public boost::partially_ordered <nr, signed char>
			, virtual public boost::partially_ordered <nr, cln::cl_N>
			, virtual public boost::partially_ordered <nr, cln::cl_R>
			, virtual public boost::partially_ordered <nr, cln::cl_RA>
			, virtual public boost::partially_ordered <nr, cln::cl_I>
			, virtual public boost::partially_ordered <nr, cln::cl_F>
			, virtual public boost::partially_ordered <nr, cln::cl_SF>
			, virtual public boost::partially_ordered <nr, cln::cl_FF>
			, virtual public boost::partially_ordered <nr, cln::cl_DF>
			, virtual public boost::partially_ordered <nr, cln::cl_LF>
			, virtual public boost::partially_ordered <nr, long double>
			, virtual public boost::partially_ordered <nr, double>
			, virtual public boost::partially_ordered <nr, float>
			, virtual public boost::partially_ordered <nr, unsigned long long int>
			, virtual public boost::partially_ordered <nr, unsigned long int>
			, virtual public boost::partially_ordered <nr, unsigned int>
			, virtual public boost::partially_ordered <nr, unsigned short int>
			, virtual public boost::partially_ordered <nr, signed long long int>
			, virtual public boost::partially_ordered <nr, signed long int>
			, virtual public boost::partially_ordered <nr, signed int>
			, virtual public boost::partially_ordered <nr, signed short int>
			
		{
			public:
				/*
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
				*/
				
				/*
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
				*/
				
				typedef cln::cl_number number/*, nr*/, no, n/*, gen*/; // abstract
				typedef cln::cl_N complex, c;
				typedef cln::cl_R real, rea, re, r; // abstract
				typedef cln::cl_RA rational, ration, rat, ra;
				typedef cln::cl_I integer, i;
				//typedef cln::cl_I natural, nature, natur, nat, na;
				typedef cln::cl_F _float/*, flt*/, f, f0; // abstract
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
				
				complex val;	// content value val
				//noware::array <rule> rules;
				//bool _exact;	// exact precise approximated rounded consistent
				
				template <typename arch>
				void serialize (arch &, unsigned int const &/* version*/);
		};
	//}
}

//#endif

std::istream & getline (std::istream &, cln::nr &, char const = '\n');
