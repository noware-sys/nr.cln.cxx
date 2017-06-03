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
#include "serial.hxx"
//#include "tool.hdr.cxx"
#include "tool/.hxx"
#include "nr.hxx"
//#include "content/value.hdr.cxx"

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
		// (container of a value) all any container value category var[iable] struct[ure] class obj[ect] it[e]m id[entifier] var[iable]
		class var
		{
			public:
				friend class boost::serialization::access;
				
				//#include ".var/container.hxx"
				enum class t
				{
					text,
					nr
				};
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				const t & type (void) const;
				const bool is_text (void) const;
				const bool is_nr (void) const;
				
				const nr size (void) const;
				
				
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
			protected:
			//private:
				template <typename archive>
				void serialize (archive &, const unsigned int &);
				
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
				
				
				t tp;
				
				std::string text;
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

