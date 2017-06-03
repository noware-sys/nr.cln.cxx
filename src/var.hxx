#pragma once

//#ifndef __VARIABLE
//#define __VARIABLE

//#include <boost/any.hpp>
#include <string>
#include <iostream>
//#include <fstream>
#include <climits>
#include <cfloat>
#include <cmath>

//#include <sqlite3.h>
//#include "../../sqlite/3.h"
//#include "databases/sqlite.h"
//#include "../../sqlite/3.c"

//#include <algorithm>
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
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/string.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/operators.hpp>

//#include"../name.hxx"
// #include "text.hxx"
//#include "tool.hdr.cxx"
//#include "tool/.hxx"
//#include "content/value.hdr.cxx"
//#include "serial.hxx"
//#include "misc/serial.hxx"
#include "nr.hxx"
#include "serial.hxx"
#include "tool/string.hxx"

//#include ".var/incl.hxx"

//dynamic ~!= static
//constant ~!= variable

//#define BOOST_FORCE_SYMMETRIC_OPERATORS 1
/*
#ifndef NAME_V
	#define NAME_V var
#endif

#ifndef any
	#define any var
#endif
*/
namespace noware
{
	//class NAME_V;
	
	//typedef NAME_V var;
	// container cont ctn ctnr ctner
	//namespace container
	//{
		// type: fundamental primitive built-in intrinsic basic
		// (container of a value) all any/ne container/contnr val[ue] cat[egory] var[iable] [con]struct[ure] class obj[ect] it[e]m id[entifier]
		class var
			: protected serial
			, public nr
			, boost::equality_comparable <var>
			, boost::equality_comparable <var, nr>
			/*
			, boost::less_than_comparable <var>
			, boost::less_than_comparable <nr>
			*/
			, boost::addable <var>
			, boost::addable <var, nr>
			, boost::addable <var, char []>
			, boost::addable <var, int>
			, boost::subtractable <var>
			, boost::subtractable <var, nr>
			, boost::subtractable2_left <var, nr>
			, boost::multipliable <nr>
			, boost::multipliable <var, nr>
			, boost::dividable <var>
			, boost::dividable <var, nr>
			, boost::dividable2_left <var, nr>
			, boost::modable <var>
			, boost::modable <var, nr>
			, boost::modable2_left <var, nr>
			, boost::xorable <var>
			, boost::xorable <var, nr>
			, boost::incrementable <var>
			//, boost::incrementable <var, nr>
			, boost::decrementable <var>
			//, boost::decrementable <var, nr>
		//	, boost::equivalent <var>
		//	, boost::equivalent <var, nr>
			, boost::partially_ordered <var>
			, boost::partially_ordered <var, nr>
		{
			public:
				enum class type
				{
					txt,
					nr
				};
				
				#include ".var/.hxx"
				
				//#include ".var/container.hxx"
				//const std::string serialize (void) const;
				//const bool deserialize (const std::string &);
				
				//const t & type (void) const;
				//const bool is_text (void) const;
				//const bool is_nr (void) const;
				
				const nr size (void) const;
				
				/*
				#include ".var/constructor.hxx"
				#include ".var/destructor.hxx"
				
				#include ".var/set.hxx"
				
				#include ".var/conversion.hxx"
				
				#include ".var/comparison.hxx"
				
				#include ".var/addition.hxx"
				#include ".var/substraction.hxx"
				//
				#include ".var/multiplication.hxx"
				#include ".var/division.hxx"
				//
				#include ".var/exponentiation.hxx"
				#include ".var/modulo.hxx"
				
				#include ".var/special.hxx"
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
				
				//_type GetType (void);
				
				//bool		GetValueBoolean (void);
				//long double	GetValueNumeric (void);
				//::std::string	GetValueGeneric (void);
				
				//::std::istream	&	getline (::std::istream &, const ::std::string = "\n");
				//::std::istream	&	getline (::std::istream &, const unsigned int, const ::std::string = "\n");
				//::std::istream	&	getline (::std::istream &, const unsigned int);
				
				//bool	Is_Generic	(void);
				//bool	Is_Numeric	(void);
				//bool	Is_Boolean	(void);
				
				// Returns a string representation of the content, whatever type it may be.
				// const std::string to_string (void) const;
				
				// returns the numeric value if the content is a number, or the default numerical value, otherwise.
				//long double		to_nr	(void);
				//bool		to_boolean	(void);
				//noware::mathematics::numbers::natural	length		(void) const;
				// size length
				// const math::nr size (void) const;
				
				//std::ostream & operator << (std::ostream &) const;
				//std::istream & operator >> (std::istream &);
				
				//const var & operator += (const var &);
			protected:
			//private:
				friend class boost::serialization::access;
				
				template <typename archive>
				void serialize (archive &, const unsigned int &/* version*/);
				
				//container content;
				//boost::any content;
				
				// Default values:
				// type _type;	// The type of the value being stored.
				//::std::string value;
			
				//void Assign (/*Container &, */const ::std::string);
				//void Assign (/*Container &, */const long double);
			
				// const std::string &	to_string (void) const;
				
				//_type Determine (const any::any);
				// determine specify
			//	const type determine (const std::string &) const;
				//_type Determine (const long double);
				
				
				type t;
				
				std::string txt;
				nr nr;
		};
	//}
	
	//typedef any var;
	//typedef any any, var;
}

std::istream & getline (std::istream &, noware::var &, const char = '\n');

//std::string		tolower (const noware::any &);
//std::string		toupper (const noware::any &);

//#endif
