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
#include "text.hxx"
#include "number.hxx"
#include "serial.hxx"
//#include "tool.hxx"
#include "tool/*.hxx"
//#include "content/value.hxx"

//dynamic ~!= static
//constant ~!= variable

//#define BOOST_FORCE_SYMMETRIC_OPERATORS 1

namespace noware
{
	//class NAME_V;
	
	//typedef NAME_V var;
	// container cont ctn ctnr ctner
	//namespace container
	//{
		// type: fundamental primitive built-in intrinsic basic
		// (container of a value) all any container value category var[iable] struct[ure] class obj[ect] it[e]m id[entifier
		class any
		// id[entifier]
		{
			public:
				#include ".any/container.hxx"
				
				friend class boost::serialization::access;
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				const container::type & type (void) const;
				
				//const math::number size (void) const;
				const number length (void) const;
				
				// Return the textual representation of the content.
				const std::string text (void) const;
				
				#include ".any/constructor.hxx"
				#include ".any/destructor.hxx"
				
				#include ".any/set.hxx"
				#include ".any/conversion.hxx"
				#include ".any/comparison.hxx"
				
				#include ".any/addition.hxx"
				#include ".any/substraction.hxx"
				//
				#include ".any/multiplication.hxx"
				#include ".any/division.hxx"
				//
				#include ".any/exponentiation.hxx"
				#include ".any/modulo.hxx"
				
				#include ".any/special.hxx"
				
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
				//long double		to_number	(void);
				//bool		to_boolean	(void);
				//noware::mathematics::numbers::natural	length		(void) const;
				// size length
				// const math::number size (void) const;
				
				template <typename archive>
				void serialize (archive &, const unsigned int &);
				
				//std::ostream & operator << (std::ostream &) const;
				//std::istream & operator >> (std::istream &);
			protected:
			//private:
				container content;
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
			
		};
	//}
	
	//typedef any var;
	//typedef any any, var;
}

std::istream & getline (std::istream &, noware::any &, const char = '\n');

//std::string		tolower (const noware::any &);
//std::string		toupper (const noware::any &);

//#endif

