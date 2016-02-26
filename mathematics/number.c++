//#ifndef VARIABLE_CPP
//#define VARIABLE_CPP

#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
#include <sstream>
//#include <iostream>
#include "../default.hpp"
#include "variable.hpp"
//#include "../Utilities.h"
//using namespace ::std;

namespace LIB
{
	//template <typename Archive>
	//void LIB::NAME_V::serialize (Archive & destination, const unsigned int version)
	//{
	//	destination & value;
	//	destination & _type;
	//}

	// LIB::default constructor:
	NAME_V::NAME_V (void)
	{
		value.Generic	= "";
		value.numeric	= 0;
		//value.Boolean	= LIB::default::BOOLEAN;

		_type			= type::GENERIC;
	}

	// Copy constructor:
	NAME_V::NAME_V (const NAME_V & val)
	{
		*this = val;
	}
	
	//NAME_V::NAME_V (const bool val)
	//{
	//	*this = (mathematics::numbers::real) val;
	//}

	NAME_V::NAME_V (const signed short int & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const unsigned short int & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const signed int & val)
	{
		//value.Generic	= LIB::default::GENERIC;
		//value.numeric	= val;
		////value.Boolean	= LIB::default::BOOLEAN;

		//_type	= type::NUMERIC;

		*this = (mathematics::numbers::real) val;

		//(NAME_V) (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const unsigned int & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const signed long int & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const unsigned long int & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const mathematics::numbers::integer & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const mathematics::numbers::natural & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const float & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const double & val)
	{
		*this = (mathematics::numbers::real) val;
	}

	NAME_V::NAME_V (const mathematics::numbers::real & val)
	{
		value.Generic	= LIB::default::GENERIC;
		value.numeric	= val;
		//value.Boolean	= LIB::default::BOOLEAN;

		_type	= type::NUMERIC;
	}

	NAME_V::NAME_V (const char & val)
	{
		*this = LIB::string (val);
	}

	//NAME_V::NAME_V (const signed char val)
	//{
	//	*this = LIB::string (val);
	//}

	//NAME_V::NAME_V (const unsigned char val)
	//{
	//	*this = LIB::string (val);
	//}
	
	NAME_V::NAME_V (const ::std::string & val)
	{
		*this = val;
		//value.Generic	= val;
		//value.numeric	= mathematics::numbers::default;

		//_type = type::GENERIC;
	}

/*
	NAME_V::NAME_V (const char val [])
	{
		*this = (std::string) val;
		//value.Generic	= val;
		//value.numeric	= mathematics::numbers::default;

		//_type = type::GENERIC;
	}
*/

//	// Destructors:
//	NAME_V::~NAME_V (void)
//	{
////		delete this;
//	}
	//::std::istream & NAME_V::getline (::std::istream & is, const ::std::string delimiter)
	//{
	//	getline (is, this, delimiter);
	//	//is.getline (,);

	//	return is;
	//}

	//::std::istream & NAME_V::getline (::std::istream & is, const unsigned int length, const ::std::string delimiter)
	//{
	//	is.getline (this, length, delimiter);
	//	//is.getline (,);

	//	return is;
	//}

	//::std::istream & NAME_V::getline (::std::istream & is, const unsigned int length)
	//{
	//	is.getline (this, length);
	//	//is.getline (,);

	//	return is;
	//}

	NAME_V::operator	::std::string	(void) const
	{
		//if (_type == BOOLEAN)
		//{
		//	return (value.Boolean ? "true" : "false");
		//}
		//else
		if (_type == type::NUMERIC)
		{
			std::string formatted;
			std::stringstream formatter;

			formatter << value.numeric;
			formatter >> formatted;

			//return ::std::to_string (value.numeric);
			return formatted;
		}
		else
		{
			return value.Generic;
		}
	}

	NAME_V::operator	mathematics::numbers::real	(void) const
	{
		if (_type == type::NUMERIC)
		{
			return value.numeric;
		}
		//else if (_type == BOOLEAN)
		//{
		//	return value.Boolean;
		//}
		// It's GENERIC:
		//else if (is_numeric (value.Generic))
		//{
		//	//if ()
		//	return stold (value.Generic);
		//}
		else
			// To ASCII?
			return mathematics::numbers::default;
	}

	NAME_V::operator	bool	(void) const
	{
		//return (bool) operator mathematics::numbers::real;

		switch (_type)
		{
			case type::NUMERIC:
				return value.numeric != 0;
				//break;
			default:
				return ! value.Generic.empty ();
		}
	}

	NAME_V::operator	NAME_V	(void) const
	{
		return *this;
	}

	mathematics::numbers::natural	NAME_V::length (void) const
	{
		switch (_type)
		{
			case type::NUMERIC:
				return LIB::digits ((mathematics::numbers::real) value.numeric);
			default:
				return value.Generic.length ();
		}
	}

	mathematics::numbers::natural	NAME_V::size (void) const
	{
		return length ();
	}

	/*
	bool NAME_V::NAME_V::To_Boolean	(void)
	{
		if (_type == BOOLEAN)
		{
			return value.Boolean;
		}
		else if (_type == NUMERIC)
		{
			return value.numeric;
		}
		else if (tolower (value.Generic) == "false")
			return false;
		else if (tolower (value.Generic) == "true")
			return true;
		else
		{
			return LIB::default::BOOLEAN;
		}
	}
	*/

	NAME_V::type NAME_V::determine (const ::std::string & val) const
	{
		if (LIB::is_numeric (val))
		{
			return type::NUMERIC;
		}
		//else if (is_boolean (val))
		//{
		//	return BOOLEAN;
		//}
		else
		{
			return type::GENERIC;
		}
	}

	NAME_V::type NAME_V::determine (void) const
	{
		return _type;
	}

	/*
	//NAME_V::NAME_V::type NAME_V::NAME_V::determine (const mathematics::numbers::real n)
	//{
	//	//type _type;
	//
	//	if (is_bool (n))
	//	{
	//		return BOOLEAN;
	//	}
	//	else
	//	{
	//		return NUMERIC;
	//	}
	//
	//
	//
	//	//return _type;
	//}
	*/

	//void NAME_V::Assign (const ::std::string val)
	//{
	//	type _type = determine (val);
	//	
	//	switch (_type)
	//	{
	//		case NUMERIC:
	//			value.Generic	= LIB::default::GENERIC;
	//			value.numeric	= stold (val);	// Check for possible errors for this line (for ston?).
	//			value.Boolean	= LIB::default::BOOLEAN;
	//
	//			_type = _type;
	//			break;
	//		case BOOLEAN:
	//			value.Generic	= LIB::default::GENERIC;
	//			value.numeric	= mathematics::numbers::default;
	//			value.Boolean	= stob (val);
	//
	//			_type = _type;
	//			break;
	//		case GENERIC:
	//		default:
	//			value.Generic	= val;
	//			value.numeric	= mathematics::numbers::default;
	//			value.Boolean	= LIB::default::BOOLEAN;
	//
	//			_type = _type;
	//	}
	//}

	/*
	//void NAME_V::NAME_V::Assign (const mathematics::numbers::real number)
	//{
	//	type _type = determine (number);
	//
	//	switch (_type)
	//	{
	//		case BOOLEAN:
	//			value.Boolean	= LIB::default::BOOLEAN;
	//			value.numeric	= mathematics::numbers::default;
	//
	//			_type = _type;
	//			break;
	//		case NUMERIC:
	//		default:
	//			value.Boolean	= LIB::default::BOOLEAN;
	//			value.numeric	= mathematics::numbers::default;
	//
	//			_type = _type;
	//	}
	//
	//	value.Generic	= LIB::default::GENERIC;
	//}

	//
	bool NAME_V::NAME_V::Is_Generic (void)
	{
		return _type == GENERIC;
	}

	bool NAME_V::NAME_V::Is_Numeric (void)
	{
		return _type == NUMERIC;
	}

	bool NAME_V::NAME_V::Is_Boolean (void)
	{
		return _type == BOOLEAN;
	}
	*/

	//NAME_V::type	NAME_V::GetType (void)
	//{
	//	return _type;
	//}

	//bool		NAME_V::GetValueBoolean (void)
	//{
	//	return value.Boolean;
	//}

	//mathematics::numbers::real	NAME_V::GetValueNumeric (void)
	//{
	//	return value.numeric;
	//}

	//::std::string	NAME_V::GetValueGeneric (void)
	//{
	//	return value.Generic;
	//}

/*
	bool NAME_V::is_generic (void) const
	{
		return _type == type::GENERIC;
	}

	bool NAME_V::is_numeric (void) const
	{
		return _type == type::NUMERIC;
	}
*/

	NAME_V				NAME_V::operator	+	(const NAME_V & val)
	{
		//NAME_V var;

		switch (_type)
		{
			case type::NUMERIC:
				switch (val._type)
				{
					case type::NUMERIC:
						//var = value.numeric + val.value.numeric;
						return value.numeric + val.value.numeric;
						//break;
					//case type::BOOLEAN:
					//	var = value.numeric + val.value.Boolean;
					//	break;
					default:
						//var = ::std::to_string (value.numeric) + val;
						// Test this case!
						return ::std::to_string (value.numeric) + val.value.Generic;

						// Gives string or number.
				}
				break;
			//case type::GENERIC:
			default:
				switch (val._type)
				{
					case type::NUMERIC:
						//var = *this + ::std::to_string (val.value.numeric);
						// Gives string or number.
						if (val.value.numeric < 0)	// string - number
							return value.Generic.substr (0, value.Generic.length () + val.value.numeric);
						else	// string + number
							return value.Generic + ::std::to_string (val.value.numeric);
						//break;
					//case type::BOOLEAN:
					//	if (value.Generic.length () == 1)
					//	{
					//		var = value.Generic [0] + val.value.Boolean;
					//	}
					//	else
					//	{
					//		//var = value.Generic;	// No need to determine the most specific _type from a string.
					//		var = this;				// Just assign.
					//	}
					//	break;
					default:
						//var = *this + val;
						return value.Generic + val.value.Generic;
						//if (value.Generic.length () == 1 && val.value.Generic.length () == 1)
						//{
						//	return value.Generic [0] + val.value.Generic [0];
						//}
						//else
						//{
						//	return value.Generic + val.value.Generic;
						//}
				}
				//break;
				//case type::BOOLEAN:
		}

		//return var;
	}

	//mathematics::numbers::real				NAME_V::operator	+	(const bool val)
	//{
	//	return *this + (mathematics::numbers::real) val;
	//}

	NAME_V				NAME_V::operator	+	(const signed short int & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const unsigned short int & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const signed int & val)
	{
		return *this + (NAME_V) val;
		//switch (_type)
		//{
		//case NAME_V::type::BOOLEAN:
		//	return value.Boolean + val;
		//case NAME_V::type::NUMERIC:
		//	return value.numeric + val;
		//default:
		//	return mathematics::numbers::default;
		//}
	}

	NAME_V				NAME_V::operator	+	(const unsigned int & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const signed long int & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const unsigned long int & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const mathematics::numbers::integer & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const mathematics::numbers::natural & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const float & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const double & val)
	{
		return *this + (NAME_V) val;
	}

	NAME_V				NAME_V::operator	+	(const mathematics::numbers::real & val)
	{
		return *this + (NAME_V) val;

		//switch (_type)
		//{
		//case NAME_V::type::NUMERIC:
		//	return value.numeric + val;
		////case NAME_V::type::BOOLEAN:
		////	return value.Boolean + val;
		//default:
		//	if (value.Generic.length () == 1)
		//	{
		//		return value.Generic [0] + val;
		//	}
		//	else
		//	{
		//		//var = String (val1) + val2.value.Generic;
		//		return val;
		//	}
		//}
	}

	NAME_V				NAME_V::operator	+	(const char & val)
	{
		////return (*this + (NAME_V) val).to_string ();
		////return to_string () + LIB::string (val);
		return *this + (NAME_V) val;

		////NAME_V var;

		////switch (_type)
		////{
		////case NAME_V::type::NUMERIC:
		////	var = value.numeric + val;
		//////case NAME_V::type::BOOLEAN:
		//////	return value.Boolean + val;
		////default:
		////	if (value.Generic.length () == 1)
		////	{
		////		var = value.Generic [0] + val;
		////	}
		////	else
		////	{
		////		//var = String (val1) + val2.value.Generic;
		////		var = val;
		////	}
		////}

		////return var;

		////return *this + (mathematics::numbers::real) val;
	}

	//NAME_V				NAME_V::operator	+	(const signed char val)
	//{
	//	return *this + (NAME_V) val;

	//	//NAME_V var;

	//	//switch (_type)
	//	//{
	//	//case NAME_V::type::NUMERIC:
	//	//	var = value.numeric + val;
	//	////case NAME_V::type::BOOLEAN:
	//	////	return value.Boolean + val;
	//	//default:
	//	//	if (value.Generic.length () == 1)
	//	//	{
	//	//		var = value.Generic [0] + val;
	//	//	}
	//	//	else
	//	//	{
	//	//		//var = String (val1) + val2.value.Generic;
	//	//		var = val;
	//	//	}
	//	//}

	//	//return var;

	//	//return *this + (mathematics::numbers::real) val;
	//}

	//NAME_V				NAME_V::operator	+	(const unsigned char val)
	//{
	//	return *this + (NAME_V) val;
	//	//NAME_V var;

	//	//switch (_type)
	//	//{
	//	//case NAME_V::type::NUMERIC:
	//	////	var = value.numeric + val;
	//	////case NAME_V::type::BOOLEAN:
	//	//	return value.numeric + val;
	//	//default:
	//	//	if (value.Generic.length () == 1)
	//	//	{
	//	//		//var = value.Generic + val;
	//	//		return value.Generic + val;
	//	//	}
	//	//	else
	//	//	{
	//	//		//var = val + value.Generic;
	//	//		return val + value.Generic;
	//	//		//var = val;
	//	//	}
	//	//}

	//	//return var;

	//	//return *this + (mathematics::numbers::real) val;
	//}

	NAME_V				NAME_V::operator	+	(const ::std::string & val)
	{
		////return (*this + (NAME_V) val).to_string ();
		//return to_string () + val;
		return *this + (NAME_V) val;
	}

	//mathematics::numbers::real		operator	+	(const bool val1, const NAME_V val2)
	//{
	//	return (mathematics::numbers::real) val1 + val2;
	//}

	// Friends: internal_type + NAME_V
	NAME_V		operator	+	(const signed short int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const unsigned short int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const signed int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const unsigned int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const signed long int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const unsigned long int & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const mathematics::numbers::integer & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const mathematics::numbers::natural & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const float & val1, const NAME_V & val2)
	{
		//return (mathematics::numbers::real) val1 + val2;
		return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const double & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 + val2;
		//return (mathematics::numbers::real) val1 + val2;
		//return (NAME_V) val1 + val2;
	}

	NAME_V		operator	+	(const mathematics::numbers::real & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 + val2;

		////switch (val2._type)
		////{
		////case NAME_V::type::NUMERIC:
		////	return val1 + val2.value.numeric;
		////default:
		////	return ::std::to_string (val1) + val2.value.Generic;
		////}

		//if (val2._type == LIB::NAME_V::type::NUMERIC)
		//	return val1 + val2.value.numeric;
		//else
		//	return val1;
	}
	
	NAME_V				operator	+	(const char & val1, const NAME_V & val2)
	{
		//return ((NAME_V) val1 + val2).to_string ();
		
		// return LIB::string (val1) + val2.to_string ();
		return (NAME_V) val1 + val2;
	}

	//NAME_V				operator	+	(const signed char val1, NAME_V val2)
	//{
	//	return val2 + val1;
	//}

	//NAME_V				operator	+	(const unsigned char val1, NAME_V val2)
	//{
	//	return val2 + val1;
	//}

	NAME_V				operator	+	(const ::std::string & val1, const NAME_V & val2)
	{
		//return ((NAME_V) val1 + val2)/* Expected to build a string. */.to_string ();
		//return val1 + val2.to_string ();
		return (NAME_V) val1 + val2;
	}

	// Negating:
	NAME_V 				NAME_V::operator	-	(void)
	{
		switch (_type)
		{
		case LIB::NAME_V::type::NUMERIC:
			return -value.numeric;
			//break;
		default:	// type::GENERIC	// More of an abnormal inversion:
			//if (value.Generic.length () == 1)
			//	return LIB::toggle_case (value.Generic [0]);
			//else	// Cannot "normally" negate/invert.
			//{
			//	// reverse the string (reading it from the end to the beginning instead of reading it from the beginning to the end):
				return LIB::reverse (value.Generic);
				//return *this;
			//}
		}

		//NAME_V var;

		//switch (val._type)
		//{
		//case NAME_V::type::NUMERIC:
		//	var = -val.value.numeric;
		//	break;
		//default:	// type::GENERIC
		//	if (val.value.Generic.length () == 1)
		//		var = -val.value.Generic [0];
		//	else	// Cannot invert.
		//		var = val;
		//}

		//return var;
	}

	// - Left side:
	NAME_V				NAME_V::operator	-	(const NAME_V & val)
	{
		//return *this + -val;

		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				return value.numeric - val.value.numeric;
			default:	// type::GENERIC
				return value.numeric;
				//if (val.value.Generic.length () == 1)
				//	return -val.value.Generic [0];
				//else	// Cannot invert.
				//	return val;
			}
		default:	// type::GENERIC
			switch (val._type)
			{
			case type::NUMERIC:
				return -val.value.numeric;
				if (val.value.numeric > 0)
					return value.Generic.substr (0, value.Generic.length () - (mathematics::numbers::natural) val.value.numeric);
				//"ABCDE" - 2 (2) = "ABC";
			default:	// type::GENERIC
				return value.Generic;
				//if (val.value.Generic.length () == 1)
				//	return -val.value.Generic [0];
				//else	// Cannot invert.
				//	return val;
			}
		}

		//return var;
	}

	//NAME_V				NAME_V::operator	-	(const NAME_V val)
	//{
	//	return	*this + (- val);
	//}

	NAME_V		NAME_V::operator	-	(const signed short int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const unsigned short int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const signed int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const unsigned int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const signed long int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const unsigned long int & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const mathematics::numbers::integer & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const mathematics::numbers::natural & val)
	{
		return	*this + -val;
	}

	NAME_V		NAME_V::operator	-	(const float & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const double & val)
	{
		return	*this - (NAME_V) val;
	}

	NAME_V		NAME_V::operator	-	(const mathematics::numbers::real & val)
	{
		return	*this - (NAME_V) val;

		//switch (_type)
		//{
		//case type::NUMERIC:
		//	return	*this - val;
		//default:
		//	if (value.Generic.length () == 1)
		//		return value.Generic [0] - val;
		//	else	// Cannot invert.
		//		return val;
		//}
	}

	NAME_V			NAME_V::operator	-	(const char & val)
	{
		*this = *this - (NAME_V) val;

		return *this;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
	}

	NAME_V			NAME_V::operator	-	(const ::std::string & val)
	{
		return	*this - (NAME_V) val;
		//*this = *this - (NAME_V) val;

		//return *this;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
	}

	// - Right side (friends):
	NAME_V		operator	-	(const signed short int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
	}

	NAME_V		operator	-	(const unsigned short int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const signed int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const unsigned int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const signed long int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const unsigned long int & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const mathematics::numbers::integer & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const mathematics::numbers::natural & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const float & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 + val2;
	}

	NAME_V		operator	-	(const double & val1, NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return (mathematics::numbers::real) val1 - val2;
	}

	NAME_V		operator	-	(const mathematics::numbers::real & val1, const NAME_V & val2)
	{
		return	(NAME_V) val1 - (NAME_V) val2;
		//return val2 + - val1;
	}

	// * Right.
	//NAME_V		NAME_V::operator	*	(NAME_V val)
	//{
	//	return *this * (const_cast <const NAME_V *> (&val));
	//}

	//NAME_V		NAME_V::operator	*	(/*const */NAME_V /*& */val)
	NAME_V		NAME_V::operator	*	(const NAME_V & val)
	{
		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				return value.numeric * val.value.numeric;
			default:
				//if (val.value.Generic.length () == 1)
				//{
				//	return value.numeric * val.value.Generic [0];
				//}
				//else
				//{
				//	::std::string tmp = "";
				//	for (mathematics::numbers::natural index = 0; index < value.numeric; ++ index)
				//		tmp = tmp + val.value.Generic;

				//	//tmp._type = type::GENERIC;

				//	return tmp;
				//	//return value.numeric;
				//}

				return LIB::multiply (val.value.Generic, value.numeric);
			}
		default:
			switch (val._type)
			{
			case type::NUMERIC:
				//if (value.Generic.length () == 1)
				//{
				//	return value.Generic [0] * val.value.numeric;
				//}
				//else
				//{
				//	return val.value.numeric;
				//}
				return LIB::multiply (value.Generic, val.value.numeric);
			default:
				return value.Generic;
				//return LIB::default::GENERIC;
				//if (value.Generic.length () == 1 && val.value.Generic.length () == 1)
				//{
				//	return value.Generic [0] * val.value.Generic [0];
				//}
				//else
				//{
				//	//return new NAME_V;
				//	return mathematics::numbers::default;
				//}
			}
		}
	}

	NAME_V		NAME_V::operator	*	(const signed short int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const unsigned short int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const signed int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const unsigned int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const signed long int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const unsigned long int & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const mathematics::numbers::integer & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const mathematics::numbers::natural & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const float & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const double & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const mathematics::numbers::real & val)
	{
		return *this * (NAME_V) val;
	}

	NAME_V		NAME_V::operator	*	(const char & val)
	{
		return *this * (NAME_V) val;
	}


	NAME_V		NAME_V::operator	*	(const ::std::string & val)
	{
		return *this * (NAME_V) val;
	}

	// * Left side:
	NAME_V		operator	*	(const signed short int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const unsigned short int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const signed int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const unsigned int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const signed long int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const unsigned long int & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V	operator	*	(const mathematics::numbers::integer & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const mathematics::numbers::natural & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const float & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const double & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	NAME_V		operator	*	(const mathematics::numbers::real & val1, NAME_V & val2)
	{
		return val2 * val1;
	}

	// / Right.
	NAME_V		NAME_V::operator	/	(const NAME_V & val)
	{
		//return *this * (*this / val);

		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				//if (val.value.numeric != 0)
				//	return value.numeric / val.value.numeric;
				//else
				//	return mathematics::numbers::default;
				return value.numeric / val.value.numeric;
			default:
				//return LIB::multiply (val.value.Generic, 1 / value.numeric);
				return value.numeric;
				//if (val.value.Generic.length () == 1 && val.value.Generic [0] != 0)
				//	return value.numeric / val.value.Generic [0];
				//else
				//	return mathematics::numbers::default;
			}
		default:
			switch (val._type)
			{
			case type::NUMERIC:
				return LIB::multiply (value.Generic, 1 / val.value.numeric);
				//if (value.Generic.length () == 1 && val.value.numeric != 0)
				//	return value.Generic [0] / val.value.numeric;
				//else
				//	return mathematics::numbers::default;
			default:
				//if (value.Generic.length () == 1 && val.value.Generic.length () == 1 && val.value.Generic [0] != 0)
				//	return value.Generic [0] / val.value.Generic [0];
				//else
				//	return mathematics::numbers::default;
				return value.Generic;
			}
		}
	}

	NAME_V		NAME_V::operator	/	(const signed short int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const unsigned short int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const signed int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const unsigned int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const signed long int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const unsigned long int & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const mathematics::numbers::integer & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const mathematics::numbers::natural & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const float & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const double & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const mathematics::numbers::real & val)
	{
		return *this / (NAME_V) val;
	}

	NAME_V		NAME_V::operator	/	(const char & val)
	{
		return *this / (NAME_V) val;
	}


	NAME_V		NAME_V::operator	/	(const ::std::string & val)
	{
		return *this / (NAME_V) val;
	}

	// / Left side:
	mathematics::numbers::real		operator	/	(const signed short int & val1 /* A */, const NAME_V & val2 /* B */)
	{
		/*
			A / B = A * 1 / B;
			v1 / v2 = v1 * 1 / v2;
		*/

		return (mathematics::numbers::real) val1 / val2;
		
	}

	mathematics::numbers::real		operator	/	(const unsigned short int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const signed int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const unsigned int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const signed long int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const unsigned long int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const mathematics::numbers::integer & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const mathematics::numbers::natural & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const float & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const double & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 / val2;
	}

	mathematics::numbers::real		operator	/	(const mathematics::numbers::real & val1, const NAME_V & val2)
	{
		switch (val2._type)
		{
		case LIB::NAME_V::type::NUMERIC:
			return val1 / val2.value.numeric;
		default:
			return val1;
			//return mathematics::numbers::default;
		}
	}

	// % Right.
	NAME_V		NAME_V::operator	%	(const NAME_V & val)
	{
		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				//	return value.numeric % val.value.numeric;
				//if (val.value.numeric != 0)
					return (mathematics::numbers::integer) value.numeric % (mathematics::numbers::integer) val.value.numeric;
				//else
				//	return mathematics::numbers::default;
			default:
				return value.numeric;
				//if (val.value.Generic.length () == 1 && val.value.Generic [0] != 0)
				//{
				//	return (mathematics::numbers::integer) value.numeric % val.value.Generic [0];
				//}
				//else
				//{
				//	return mathematics::numbers::default;
				//	//return value.numeric;
				//}
			}
		default:
			//return mathematics::numbers::default;
			switch (val._type)
			{
			case type::NUMERIC:
				if (val.value.numeric >= 0)
				{
					// Return a substring.
					//return value.Generic.substr (value.Generic.length () - value.Generic.length () % (mathematics::numbers::natural) val.value.numeric, value.Generic.length ());
					return value.Generic.substr (value.Generic.length () - val.value.numeric, value.Generic.length ());
				}
				else
				{
					// Return a substring.
					//return value.Generic.substr (0, value.Generic.length () % (mathematics::numbers::natural) -val.value.numeric);
					return value.Generic.substr (0, -val.value.numeric);
					//return value.Generic;
				}

				//return val.value.Generic;
				//if (value.Generic.length () == 1 && val.value.numeric != 0)
				//{
				//	return value.Generic [0] % (mathematics::numbers::integer) val.value.numeric;
				//}
				//else
				//{
				//	return mathematics::numbers::default;
				//	//return val.value.numeric;
				//}
			default:
				return value.Generic;
				//return LIB::default::GENERIC;

				//if (value.Generic.length () == 1 && val.value.Generic.length () == 1 && val.value.Generic [0] != 0)
				//{
				//	return value.Generic [0] % val.value.Generic [0];
				//}
				//else
				//{
				//	return mathematics::numbers::default;
				//}
			}
		}
	}
	
	NAME_V		NAME_V::operator	%	(const signed short int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const unsigned short int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const signed int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const unsigned int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const signed long int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const unsigned long int & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const mathematics::numbers::integer & val)
	{
		return *this % (LIB::NAME_V) val;

		//switch (_type)
		//{
		//	case type::NUMERIC:
		//		//if (val != 0)
		//			return (mathematics::numbers::integer) value.numeric % val;
		//		//else
		//		//	return mathematics::numbers::default;
		//	default:
		//		return mathematics::numbers::default;
		//		//if (value.Generic.length () == 1 && val != 0)
		//		//{
		//		//	return value.Generic [0] % val;
		//		//}
		//		//else
		//		//{
		//		//	return mathematics::numbers::default;
		//		//	//return val.value.numeric;
		//		//}
		//}
	}

	NAME_V		NAME_V::operator	%	(const mathematics::numbers::natural & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const float & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const double & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const mathematics::numbers::real & val)
	{
		return *this % (LIB::NAME_V) val;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const char & val)
	{
		//NAME_V tmp = val;	// Convert to number, if possible.

		//return *this % tmp;
		return *this % (LIB::NAME_V) val;
		//return *this % (LIB::NAME_V) tmp;
		//return *this % (mathematics::numbers::integer) val;
	}

	NAME_V		NAME_V::operator	%	(const ::std::string & val)
	{
		//NAME_V tmp = val;	// Convert to number, if possible.

		//return *this % (LIB::NAME_V) tmp;
		return *this % (LIB::NAME_V) val;
		//return *this % (LIB::NAME_V) tmp;
		//return *this % (mathematics::numbers::integer) val;
	}

	// % Left side:
	mathematics::numbers::integer		operator	%	(const signed short int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const unsigned short int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const signed int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const unsigned int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const signed long int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const unsigned long int & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	// Friends:
	mathematics::numbers::integer		operator	%	(const mathematics::numbers::integer & val1, const NAME_V & val2)
	{
		switch (val2._type)
		{
			case NAME_V::type::NUMERIC:
				//if (val2.value.numeric != 0)
					return val1 % (mathematics::numbers::integer) val2.value.numeric;
				//else
				//	return mathematics::numbers::default;
			default:
				//return val1;
				//if (val2.value.Generic.length () == 1 && val2.value.Generic [0] != 0)
				//	return val1 % val2.value.Generic [0];
				//else

				//	return mathematics::numbers::default;
				return val1;
		}
	}

	mathematics::numbers::integer		operator	%	(const mathematics::numbers::natural & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const float & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const double & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	mathematics::numbers::integer		operator	%	(const mathematics::numbers::real & val1, const NAME_V & val2)
	{
		return (mathematics::numbers::integer) val1 % val2;
	}

	// ^ Right.
	mathematics::numbers::real		NAME_V::operator	^	(const NAME_V & val)
	{
		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				return pow (value.numeric, val.value.numeric);
			default:
				return value.numeric;
			}
		default:
			switch (val._type)
			{
			case type::NUMERIC:
				return val.value.numeric;
			default:
				return mathematics::numbers::default;
			}
		}
	}

	mathematics::numbers::real		NAME_V::operator	^	(const signed short int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const unsigned short int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const signed int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const unsigned int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const signed long int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const unsigned long int & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const mathematics::numbers::integer & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const mathematics::numbers::natural & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const float & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const double & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const mathematics::numbers::real & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const char & val)
	{
		return *this ^ (NAME_V) val;
	}

	mathematics::numbers::real		NAME_V::operator	^	(const ::std::string & val)
	{
		return *this ^ (NAME_V) val;
	}

	// ^ Left side:
	mathematics::numbers::real		operator	^	(const signed short int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const unsigned short int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const signed int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const unsigned int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const signed long int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const unsigned long int & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real	operator	^	(const mathematics::numbers::integer & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const mathematics::numbers::natural & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const float & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const double & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const mathematics::numbers::real & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	mathematics::numbers::real		operator	^	(const char & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}
	mathematics::numbers::real		operator	^	(const ::std::string & val1, const NAME_V & val2)
	{
		return (NAME_V) val1 ^ val2;
	}

	NAME_V			NAME_V::operator	~ (void) const
	{
		switch (_type)
		{
			case type::NUMERIC:
				return LIB::complement (value.numeric);
			default:
				return LIB::toggle_case (value.Generic);
		}
	}

	//NAME_V			NAME_V::operator	| (void) const
	//{
	//	switch (_type)
	//	{
	//		case type::NUMERIC:
	//			return LIB::modulus (value.numeric);
	//		default:
	//			return *this;
	//	}
	//}

	bool			NAME_V::operator	! (void) const
	{
/*
		switch (_type)
		{
			case type::NUMERIC:
				return !value.numeric;
				//break;
			default:
				if (value.Generic.empty ())
				{
					return true;	// Return the opposite: note the negating operator '!'.
				}
				//else if (value.Generic.length () == 1)
				//{
				//	return !value.Generic [0];
				//}
				else
				{
					//return !mathematics::numbers::default;
					return false;	//!mathematics::numbers::default;	// Return the opposite: note the negating operator '!'.		// Considering that !string is equivalent !Empty ().
				}
		}
*/
		return ! operator bool ();
	}

	NAME_V &			NAME_V::operator	=	(const NAME_V & val)
	{
		//value.Boolean	= val.value.Boolean;
		value.numeric	= val.value.numeric;
		value.Generic	= val.value.Generic;

		_type = val._type;

		return *this;
	}

	//NAME_V &			NAME_V::operator	=	(const bool val)
	//{
	//	////value.Boolean	= val;
	//	//value.numeric	= val;
	//	//value.Generic	= LIB::default::GENERIC;

	//	//_type = type::NUMERIC;
	//	*this = (mathematics::numbers::real) val;

	//	return *this;
	//}

	NAME_V &			NAME_V::operator	=	(const signed short int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const unsigned short int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const signed int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const unsigned int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const signed long int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const unsigned long int & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const mathematics::numbers::integer & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const mathematics::numbers::natural & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const float & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const double & val)
	{
		*this = (mathematics::numbers::real) val;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const mathematics::numbers::real & val)
	{
		//value.Boolean	= LIB::default::BOOLEAN;
		value.numeric	= val;
		value.Generic	= LIB::default::GENERIC;

		_type = type::NUMERIC;

		return *this;
	}

	NAME_V &			NAME_V::operator	=	(const char & val)
	{
		*this = LIB::string (val);

		return *this;
	}

	//NAME_V &			NAME_V::operator	=	(const signed char val)
	//{
	//	*this = LIB::string (val);

	//	return *this;
	//}

	//NAME_V &			NAME_V::operator	=	(const unsigned char val)
	//{
	//	*this = LIB::string (val);

	//	return *this;
	//}

	NAME_V &			NAME_V::operator	=	(const ::std::string & val)
	{
		/*type */_type = determine (val);	// determine the most specific _type.
		//_type	= determine (val);

		switch (_type)
		{
		case type::NUMERIC:
			//value.Generic	= LIB::default::GENERIC;
			//value.numeric	= stold (val);	// Check for possible errors for this line (for stold?).
			//value.Boolean	= LIB::default::BOOLEAN;
			*this	= stold (val);	// Check for errors?

			// _type = _type;

			break;
		//case BOOLEAN:
			//value.Generic	= LIB::default::GENERIC;
			//value.numeric	= mathematics::numbers::default;
			//value.Boolean	= stob (val);
			//*this	= stob (val);

			//_type = _type;
			//break;
		//case GENERIC:
		default:
			value.Generic	= val;
			value.numeric	= mathematics::numbers::default;
			//value.Boolean	= LIB::default::BOOLEAN;

			//_type = type::GENERIC;	// Assign GENERIC, because it could have also been type::BOOLEAN (from default: case).
			//_type = _type;			// Not valid anymore, because type::BOOLEAN has been removed.
		}

		////value	= Assign (val);

		//value.numeric	= mathematics::numbers::default;
		//value.Generic	= val;

		//_type = type::GENERIC;

		return *this;
	}

	// < Right side
	bool			NAME_V::operator	<	(const NAME_V & val)
	{
		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				return value.numeric < val.value.numeric;
			default:
				return ::std::to_string (value.numeric) < val.value.Generic;
				//if (val.value.Generic.length () == 1)
				//	return value.numeric < val.value.Generic [0];
				//else
				//	return mathematics::numbers::default;
			}
		default:
			switch (val._type)
			{
			case type::NUMERIC:
				return value.Generic < ::std::to_string (val.value.numeric);
				//if (value.Generic.length () == 1)
				//	return value.Generic [0] < val.value.numeric;
				//else
				//	return mathematics::numbers::default;
			default:
				return value.Generic < val.value.Generic;
				//if (value.Generic.length () == 1 && val.value.Generic.length () == 1)
				//	return value.Generic [0] < val.value.Generic [0];
				//else
				//	//return strcmp (value.Generic.c_str (), val.value.Generic.c_str ()) < 0;
				//	return value.Generic < val.value.Generic;
				//	return true;
				//else
				//	return false;
			}
		}
	}

	bool			NAME_V::operator	<	(const signed short int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const unsigned short int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const signed int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const unsigned int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const signed long int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const unsigned long int & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const mathematics::numbers::integer & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const mathematics::numbers::natural & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const float & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const double & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const mathematics::numbers::real & val)
	{
		return *this < (NAME_V) val;
	}

	bool			NAME_V::operator	<	(const char & val)
	{
		return *this < (NAME_V) val;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	return value.numeric < val;
		//default:
		//	return strcmp (value.Generic.c_str (), LIB::string (val).c_str ()) < 0;
		//}
	}

	//bool			NAME_V::operator	<	(const signed char val)
	//{
	//	switch (_type)
	//	{
	//	case type::NUMERIC:
	//		return value.numeric < val;
	//	default:
	//		return strcmp (value.Generic.c_str (), LIB::string (val).c_str ()) < 0;
	//	}
	//}

	//bool			NAME_V::operator	<	(const unsigned char val)
	//{
	//	switch (_type)
	//	{
	//	case type::NUMERIC:
	//		return value.numeric < val;
	//	default:
	//		return strcmp (value.Generic.c_str (), LIB::string (val).c_str ()) < 0;
	//	}
	//}

	bool			NAME_V::operator	<	(const ::std::string & val)
	{
		return *this < (NAME_V) val;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	if (val.length () == 1)
		//		return value.numeric < val [0];
		//	else
		//		return mathematics::numbers::default;
		//default:
		//	return strcmp (value.Generic.c_str (), val.c_str ()) < 0;
		//}
	}

	// < Left side.
	bool			operator	<	(const signed short int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const unsigned short int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const signed int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const unsigned int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const signed long int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const unsigned long int & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const mathematics::numbers::integer & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const mathematics::numbers::natural & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const float & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const double & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const mathematics::numbers::real & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	bool			operator	<	(const char & val1, NAME_V & val2)
	{
		return val2 > val1;
	}

	//bool			operator	<	(const signed char val1, NAME_V val2)
	//{
	//	return val2 > val1;
	//}

	//bool			operator	<	(const unsigned char val1, NAME_V val2)
	//{
	//	return val2 > val1;
	//}

	bool			operator	<	(const ::std::string & val1, NAME_V & val2)
	{
		return val2 > val1;
	}
	
	// > Right side.
	bool			NAME_V::operator	>	(const NAME_V & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const signed short int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const unsigned short int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const signed int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const unsigned int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const signed long int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const unsigned long int & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const mathematics::numbers::integer & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const mathematics::numbers::natural & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const float & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const double & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const mathematics::numbers::real & val)
	{
		return !(*this <= val);
	}

	bool			NAME_V::operator	>	(const char & val)
	{
		return !(*this <= val);
	}

	//bool			NAME_V::operator	>	(const signed char val)
	//{
	//	return !(*this <= val);
	//}

	//bool			NAME_V::operator	>	(const unsigned char val)
	//{
	//	return !(*this <= val);
	//}

	bool			NAME_V::operator	>	(const ::std::string & val)
	{
		return !(*this <= val);
	}

	bool			operator	>	(const signed short int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const unsigned short int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const signed int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const unsigned int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const signed long int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const unsigned long int & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const mathematics::numbers::integer & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const mathematics::numbers::natural & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const float & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const double & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const mathematics::numbers::real & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	bool			operator	>	(const char & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	//bool			operator	>	(const signed char val1, NAME_V val2)
	//{
	//	return val2 < val1;
	//}

	//bool			operator	>	(const unsigned char val1, NAME_V val2)
	//{
	//	return val2 < val1;
	//}

	bool			operator	>	(const ::std::string & val1, NAME_V & val2)
	{
		return val2 < val1;
	}

	// += Right side
	NAME_V	&			NAME_V::operator	+=	(const NAME_V & val)
	{
		*this = *this + val;

		return *this;
	}

	//mathematics::numbers::real				NAME_V::operator	+	(const bool val)
	//{
	//	return *this + (mathematics::numbers::real) val;
	//}

	NAME_V	&			NAME_V::operator	+=	(const signed short int & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const unsigned short int & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const signed int & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const unsigned int & val)
	{
		*this =  *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const signed long int & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const unsigned long int & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const mathematics::numbers::integer & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const mathematics::numbers::natural & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const float & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const double & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const mathematics::numbers::real & val)
	{
		*this = *this + val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	+=	(const char & val)
	{
		*this = *this + val;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
		return *this;
	}

	//NAME_V				NAME_V::operator	+=	(const signed char val)
	//{
	//	*this = *this + val;

	//	return *this;
	//}

	//NAME_V				NAME_V::operator	+=	(const unsigned char val)
	//{
	//	*this = *this + val;

	//	return *this;
	//}

	NAME_V	&			NAME_V::operator	+=	(const ::std::string & val)
	{
		*this = *this + val;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
		return *this;
	}

	// Friends: _type += NAME_V:
	mathematics::numbers::real		operator	+=	(const signed short int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const unsigned short int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const signed int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const unsigned int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const signed long int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const unsigned long int & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const mathematics::numbers::integer & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const mathematics::numbers::natural & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(const float & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(double & val1, NAME_V & val2)
	{
		return (mathematics::numbers::real) val1 += val2;
	}

	mathematics::numbers::real		operator	+=	(mathematics::numbers::real val1, NAME_V val2)
	{
		if (val2._type == LIB::NAME_V::type::NUMERIC)
			val1 = val1 + val2.value.numeric;
		//else

		return val1;
	}
	
	//::std::string				operator	+=	(const char val1, const NAME_V val2)
	//{
	//	return LIB::string (val1) += val2;
	//}

	//NAME_V				operator	+=	(const signed char val1, const NAME_V val2)
	//{
	//	NAME_V tmp = val1 + val2;
	//	return tmp;
	//}

	//NAME_V				operator	+=	(const unsigned char val1, const NAME_V val2)
	//{
	//	NAME_V tmp = val1 + val2;
	//	return tmp;
	//}

	::std::string &				operator	+=	(::std::string & val1, const NAME_V & val2)
	{
		//val1 = ((NAME_V) val1 + val2)/* Expected to return a string _type. */.to_string ();
		//val1 = (val1 + val2).to_string ();
		val1 = val1 + val2;
		
		return val1;
	}
	
	// - Minus, Right Side:
	NAME_V	&			NAME_V::operator	-=	(const NAME_V & val)
	{
		*this = *this - val;

		return *this;
	}

	//mathematics::numbers::real				NAME_V::operator	+	(const bool val)
	//{
	//	return *this + (mathematics::numbers::real) val;
	//}

	NAME_V	&			NAME_V::operator	-=	(const signed short int val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const unsigned short int val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const signed int val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const unsigned int val)
	{
		*this =  *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const signed long int val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const unsigned long int val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const mathematics::numbers::integer val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const mathematics::numbers::natural val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const float val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const double val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const mathematics::numbers::real val)
	{
		*this = *this - val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const char val)
	{
		*this = *this - val;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
		return *this;
	}

	NAME_V	&			NAME_V::operator	-=	(const ::std::string val)
	{
		*this = *this - val;

		//// It is expected to become a string after the previous operation.
		//return value.Generic;
		return *this;
	}

	// Friends: _type -= NAME_V:
	mathematics::numbers::real		operator	-=	(const signed short int val1, NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const unsigned short int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const signed int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const unsigned int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const signed long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const unsigned long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const mathematics::numbers::integer val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const mathematics::numbers::natural val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(const float val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(double val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	-=	(mathematics::numbers::real val1, const NAME_V val2)
	{
		if (val2._type == LIB::NAME_V::type::NUMERIC)
			val1 = val1 - val2.value.numeric;
		//else

		return val1;
	}
		
	// *= Right side
	NAME_V	&			NAME_V::operator	*=	(const NAME_V val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const signed short int val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const unsigned short int val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const signed int val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const unsigned int val)
	{
		*this =  *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const signed long int val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const unsigned long int val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const mathematics::numbers::integer val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const mathematics::numbers::natural val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const float val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const double val)
	{
		*this = *this * val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	*=	(const mathematics::numbers::real val)
	{
		*this = *this * val;

		return *this;
	}

	//NAME_V				NAME_V::operator	+=	(const signed char val)
	//{
	//	*this = *this + val;

	//	return *this;
	//}

	//NAME_V				NAME_V::operator	+=	(const unsigned char val)
	//{
	//	*this = *this + val;

	//	return *this;
	//}

	// Friends: _type += NAME_V:
	mathematics::numbers::real		operator	*=	(const signed short int val1, NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const unsigned short int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const signed int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const unsigned int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const signed long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const unsigned long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const mathematics::numbers::integer val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const mathematics::numbers::natural val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const float val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(const double val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 *= val2;
	}

	mathematics::numbers::real		operator	*=	(mathematics::numbers::real val1, const NAME_V val2)
	{
		if (val2._type == LIB::NAME_V::type::NUMERIC)
			val1 = val1 * val2.value.numeric;
		//else

		return val1;
	}
	
	// /= Minus, Right Side:
	NAME_V	&			NAME_V::operator	/=	(const NAME_V val)
	{
		*this = *this / val;

		return *this;
	}

	//mathematics::numbers::real				NAME_V::operator	+	(const bool val)
	//{
	//	return *this + (mathematics::numbers::real) val;
	//}

	NAME_V	&			NAME_V::operator	/=	(const signed short int val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const unsigned short int val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const signed int val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const unsigned int val)
	{
		*this =  *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const signed long int val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const unsigned long int val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const mathematics::numbers::integer val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const mathematics::numbers::natural val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const float val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const double val)
	{
		*this = *this / val;

		return *this;
	}

	NAME_V	&			NAME_V::operator	/=	(const mathematics::numbers::real val)
	{
		*this = *this / val;

		return *this;
	}

	// Friends: _type -= NAME_V:
	mathematics::numbers::real		operator	/=	(const signed short int val1, NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	/=	(const unsigned short int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 -= val2;
	}

	mathematics::numbers::real		operator	/=	(const signed int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const unsigned int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const signed long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const unsigned long int val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const mathematics::numbers::integer val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const mathematics::numbers::natural val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(const float val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(double val1, const NAME_V val2)
	{
		return (mathematics::numbers::real) val1 /= val2;
	}

	mathematics::numbers::real		operator	/=	(mathematics::numbers::real val1, const NAME_V val2)
	{
		//if (val2._type == LIB::NAME_V::type::NUMERIC)
		//	val1 = val1 / val2.value.numeric;
		////else

		val1 = val1 / val2;

		return val1;
	}
	
	// %= Right
	NAME_V		NAME_V::operator	%=	(const NAME_V val)
	{
		*this = *this % val;

		// % sometimes returns a signed long long int (mathematics::numbers::integer)

		return *this;
		//return value.numeric;
	}
	
	NAME_V		NAME_V::operator	%=	(const signed short int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const unsigned short int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const signed int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const unsigned int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const signed long int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const unsigned long int val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const mathematics::numbers::integer val)
	{
		*this = *this % val;

		return *this;

		//switch (_type)
		//{
		//	case type::NUMERIC:
		//			*this = (mathematics::numbers::integer) value.numeric % val;
		//			return value.numeric;
		//	default:

		//		*this = mathematics::numbers::default;
		//		return value.numeric;
		//}
	}

	NAME_V		NAME_V::operator	%=	(const mathematics::numbers::natural val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const float val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const double val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(const mathematics::numbers::real val)
	{
		*this = *this % val;

		return *this;
	}

	NAME_V		NAME_V::operator	%=	(char val)
	{
		*this = *this % val;

		return *this;
		//NAME_V tmp = val;	// Convert to number if possible.

		////if (tmp._type = LIB::NAME_V::type::NUMERIC)
		//return *this %= tmp;

		////return to_number ();
	}

	NAME_V		NAME_V::operator	%=	(::std::string val)
	{
		*this = *this % val;

		return *this;
		//NAME_V tmp = val;	// Convert to number if possible.

		////if (tmp._type = LIB::NAME_V::type::NUMERIC)
		//return *this %= tmp;

		////return to_number ();
	}

	// %= Left side (friends):
	mathematics::numbers::integer		operator	%=	(signed short int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(unsigned short int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(signed int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(unsigned int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	 (signed long int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(unsigned long int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(mathematics::numbers::integer & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(mathematics::numbers::natural & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(float & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(double & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	mathematics::numbers::integer		operator	%=	(mathematics::numbers::real & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 % val2;

		return val1;
	}

	// ^= Right
	NAME_V		NAME_V::operator	^=	(const NAME_V val)
	{
		*this = *this ^ val;

		// % sometimes returns a signed long long int (mathematics::numbers::integer)

		return *this;
		//return value.numeric;
	}
	
	NAME_V		NAME_V::operator	^=	(const signed short int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const unsigned short int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const signed int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const unsigned int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const signed long int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const unsigned long int val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const mathematics::numbers::integer val)
	{
		*this = *this ^ val;

		return *this;

		//switch (_type)
		//{
		//	case type::NUMERIC:
		//			*this = (mathematics::numbers::integer) value.numeric % val;
		//			return value.numeric;
		//	default:

		//		*this = mathematics::numbers::default;
		//		return value.numeric;
		//}
	}

	NAME_V		NAME_V::operator	^=	(const mathematics::numbers::natural val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const float val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const double val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(const mathematics::numbers::real val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(char val)
	{
		*this = *this ^ val;

		return *this;
	}

	NAME_V		NAME_V::operator	^=	(::std::string val)
	{
		*this = *this ^ val;

		return *this;
	}

	// %= Left side (friends):
	mathematics::numbers::integer		operator	^=	(signed short int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(unsigned short int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(signed int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(unsigned int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	 (signed long int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(unsigned long int & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(mathematics::numbers::integer & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(mathematics::numbers::natural & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(float & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(double & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	mathematics::numbers::integer		operator	^=	(mathematics::numbers::real & val1, const NAME_V val2)
	{
		//if (val2._type = LIB::NAME_V::type::NUMERIC)
			val1 = val1 ^ val2;

		return val1;
	}

	//mathematics::numbers::integer		operator	%=	(char val1, NAME_V val2)
	//{
	//	return LIB::string (val1) %= val2;
	//	//NAME_V tmp = val1;

	//	//if (tmp._type = LIB::NAME_V::type::NUMERIC)
	//	//	tmp %= val2;

	//	//return tmp.to_number ();
	//}

	//mathematics::numbers::integer		operator	%=	(::std::string val1, NAME_V val2)
	//{
	//	NAME_V tmp = val1;

	//	if (tmp._type = LIB::NAME_V::type::NUMERIC)
	//		tmp %= val2;

	//	return tmp.to_number ();
	//}

	// Input and Output Streams:
	//::std::ostream &	NAME_V::NAME_V::operator	<<	(::std::ostream & os)
	::std::ostream &	operator	<<	(::std::ostream & os, const NAME_V val)
	{
		//switch (val.GetType ())
		//{
		//case NAME_V::type::BOOLEAN:
		//	os << val.GetValueBoolean ();
		//	break;
		//case NAME_V::type::NUMERIC:
		//	os << val.GetValueNumeric ();
		//	break;
		//default:
		//	os << val.GetValueGeneric ();
		//}

		switch (val._type)
		{
		//case NAME_V::type::BOOLEAN:
		//	os << val.value.Boolean;
		//	break;
		case NAME_V::type::NUMERIC:
			os << val.value.numeric;
			break;
		default:
			os << val.value.Generic;
		}

		//switch (_type)
		//{
		//case NAME_V::NAME_V::type::BOOLEAN:
		//	os << value.Boolean;
		//	break;
		//case NAME_V::NAME_V::type::NUMERIC:
		//	os << value.numeric;
		//	break;
		//default:
		//	os << value.Generic;
		//}

		return os;
	}
	
	::std::istream &	operator	>>	(::std::istream & is, NAME_V & val)
	{
		::std::string tmp;
		is >> tmp;
		//getline (is, tmp);
		val = tmp;

		return is;
	}

	// File Streams:
	//::std::ofstream &	operator	<<	(::std::ofstream & os, NAME_V val)
	//{
	//	switch (val._type)
	//	{
	//	case NAME_V::type::NUMERIC:
	//		os << val.value.numeric;
	//		break;
	//	default:
	//		os << val.value.Generic;
	//	}

	//	return os;
	//}

	//::std::ifstream &	operator	>>	(::std::ifstream & is, NAME_V val)
	//{
	//	::std::string tmp;
	//	is >> tmp;
	//	//getline (is, tmp);
	//	val = tmp;

	//	return is;
	//}

	// Inequality, right-hand side:
	bool			NAME_V::operator	==	(const NAME_V val)
	{
		if (_type == val._type)
		{
			switch (_type) // ...or val._type.
			{
				case type::NUMERIC:
					return value.numeric == val.value.numeric;
				default:
					return value.Generic == val.value.Generic;
			}
		}
		//else if (_type == GENERIC)
		//	if (is_numeric (value.Generic))
		//		;
		//else if (other._type == GENERIC)
		//	;
		else
			return false;
	}

	bool			NAME_V::operator	==	(const bool val)
	{
		//switch (_type)
		//{
		////case type::BOOLEAN:
		//	//return btos (value.Boolean) == val;	// Capitalization matters.
		////	return value.Boolean == stob (val);
		//case type::NUMERIC:
		//	return value.numeric == val;
		//default:
		//	//return value.Generic == val;
		//	return false;
		//}

		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;

		//if (_type == GENERIC)
		//	return value.Generic == val;
		//else
		//	return false;
	}

	bool			NAME_V::operator	==	(const signed short int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const unsigned short int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const signed int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const unsigned int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const signed long int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const unsigned long int val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const mathematics::numbers::integer val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const mathematics::numbers::natural val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const float val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const double val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;
	}

	bool			NAME_V::operator	==	(const mathematics::numbers::real val)
	{
		return *this == (NAME_V) val;
		//switch (_type)
		//{
		//	//case type::BOOLEAN:
		//		//return btos (value.Boolean) == val;	// Capitalization matters.
		//	//	return value.Boolean == stob (val);
		//	case type::NUMERIC:
		//		return value.numeric == val;
		//	default:
		//		//return value.Generic == val;
		//		return false;
		//}

		//if (_type == GENERIC)
		//	return value.Generic == val;
		//else
		//	return false;
	}

	bool			NAME_V::operator	==	(const char val)
	{
		return *this == (NAME_V) val;
		//return *this == (mathematics::numbers::real) val;

		//switch (_type)
		//{
		//case type::NUMERIC:
		//	return value.numeric == val;
		//default:
		//	if (value.Generic.length () == 1)
		//		return value.Generic [0] == val;
		//	else
		//		return false;
		//}
	}

	//bool			NAME_V::operator	==	(const signed char val)
	//{
	//	switch (_type)
	//	{
	//	case type::NUMERIC:
	//		return value.numeric == val;
	//	default:
	//		if (value.Generic.length () == 1)
	//			return value.Generic [0] == val;
	//		else
	//			return false;
	//	}
	//}

	//bool			NAME_V::operator	==	(const unsigned char val)
	//{
	//	//return *this == (mathematics::numbers::real) val;

	//	switch (_type)
	//	{
	//	case type::NUMERIC:
	//		return value.numeric == val;
	//	default:
	//		if (value.Generic.length () == 1)
	//			return value.Generic [0] == val;
	//		else
	//			return false;
	//	}
	//}

	bool			NAME_V::operator	==	(const ::std::string val)
	{
		return *this == (NAME_V) val;
		//switch (_type)
		//{
		////case type::BOOLEAN:
		//	//return btos (value.Boolean) == val;	// Capitalization matters.
		////	return value.Boolean == stob (val);
		//case type::NUMERIC:
		//	return LIB::string (value.numeric) == val;
		//default:
		//	return value.Generic == val;
		//}

		//if (_type == GENERIC)
		//	return value.Generic == val;
		//else
		//	return false;

	}

	// Equality, left-hand side:

	//bool			operator	==	(const NAME_V val1, const NAME_V val2)
	//{
	//	return val2 == val1;
	//}

	bool			operator	==	(const bool val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const signed short int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const unsigned short int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const signed int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const unsigned int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const signed long int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const unsigned long int val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const mathematics::numbers::integer val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const mathematics::numbers::natural val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const float val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const double val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool			operator	==	(const mathematics::numbers::real val1, NAME_V val2)
	{
		return val2 == val1;
	}

	bool				operator	==	(const char val1, NAME_V val2)
	{
		return val2 == val1;
	}

	//bool				operator	==	(const signed char val1, NAME_V val2)
	//{
	//	return val2 == val1;
	//}

	//bool				operator	==	(const unsigned char val1, NAME_V val2)
	//{
	//	return val2 == val1;
	//}

	bool				operator	==	(const ::std::string val1, NAME_V val2)
	{
		return val2 == val1;
	}

	// Inequality, right-hand side:
	bool			NAME_V::operator	!=	(const NAME_V val)
	{
		if (_type == val._type)
		{
			switch (_type)
			{
				case type::NUMERIC:
					return value.numeric != val.value.numeric;
				default:
					return value.Generic != val.value.Generic;
			}
		}
		else
			return true;

		//::std::string c = (::std::string) 'c';
		//return true;
		//return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const bool val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const signed short int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const unsigned short int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const signed int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const unsigned int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const signed long int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const unsigned long int val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const mathematics::numbers::integer val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const mathematics::numbers::natural val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const float val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const double val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const mathematics::numbers::real val)
	{
		return !(*this == val);
	}

	bool			NAME_V::operator	!=	(const char val)
	{
		return !(*this == val);
	}

	//bool			NAME_V::operator	!=	(const signed char val)
	//{
	//	return !(*this == val);
	//}

	//bool			NAME_V::operator	!=	(const unsigned char val)
	//{
	//	return !(*this == val);
	//}

	bool			NAME_V::operator	!=	(const ::std::string val)
	{
		return !(*this == val);
		//return false;
	}

	// Inequality, left-hand side:
	bool			operator	!=	(const bool val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const signed short int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const unsigned short int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const signed int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const unsigned int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const signed long int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const unsigned long int val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const mathematics::numbers::integer val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const mathematics::numbers::natural val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const float val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const double val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool			operator	!=	(const mathematics::numbers::real val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool				operator	!=	(const char val1, NAME_V val2)
	{
		return val2 != val1;
	}
/*
	bool				operator	!=	(const signed char val1, NAME_V val2)
	{
		return val2 != val1;
	}

	bool				operator	!=	(const unsigned char val1, NAME_V val2)
	{
		return val2 != val1;
	}
*/
	bool				operator	!=	(const ::std::string val1, NAME_V val2)
	{
		return val2 != val1;
	}
	
	// <= Right side:
	bool			NAME_V::operator	<=	(const NAME_V val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const signed short int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const unsigned short int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const signed int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const unsigned int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const signed long int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const unsigned long int val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const mathematics::numbers::integer val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const mathematics::numbers::natural val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const float val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const double val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const mathematics::numbers::real val)
	{
		return *this < val || *this == val;
	}

	bool			NAME_V::operator	<=	(const char val)
	{
		return *this < val || *this == val;
	}

	//bool			NAME_V::operator	<=	(const signed char val)
	//{
	//	return *this < val || *this == val;
	//}

	//bool			NAME_V::operator	<=	(const unsigned char val)
	//{
	//	return *this < val || *this == val;
	//}

	bool			NAME_V::operator	<=	(const ::std::string val)
	{
		return *this < val || *this == val;
	}

	// <= Left side:
	bool			operator	<=	(const signed short int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const unsigned short int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const signed int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const unsigned int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const signed long int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const unsigned long int val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const mathematics::numbers::integer val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const mathematics::numbers::natural val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const float val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const double val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const mathematics::numbers::real val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	bool			operator	<=	(const char val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	//bool			operator	<=	(const signed char val1, NAME_V val2)
	//{
	//	return val1 < val2 || val1 == val2;
	//	return !(val2 < val1);
	//}

	//bool			operator	<=	(const unsigned char val1, NAME_V val2)
	//{
	//	return val1 < val2 || val1 == val2;
	//	return !(val2 < val1);
	//}

	bool			operator	<=	(const ::std::string val1, NAME_V val2)
	{
		return val1 < val2 || val1 == val2;
		//return !(val2 < val1);
	}

	// >= Right side:
	bool			NAME_V::operator	>=	(const NAME_V val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const signed short int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const unsigned short int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const signed int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const unsigned int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const signed long int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const unsigned long int val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const mathematics::numbers::integer val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const mathematics::numbers::natural val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const float val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const double val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const mathematics::numbers::real val)
	{
		return *this > val || *this == val;
	}

	bool			NAME_V::operator	>=	(const char val)
	{
		return *this > val || *this == val;
	}

	//bool			NAME_V::operator	>=	(const signed char val)
	//{
	//	return *this > val || *this == val;
	//}

	//bool			NAME_V::operator	>=	(const unsigned char val)
	//{
	//	return *this > val || *this == val;
	//}

	bool			NAME_V::operator	>=	(const ::std::string val)
	{
		return *this > val || *this == val;
	}

	// >= Left side:
	bool			operator	>=	(const signed short int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const unsigned short int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const signed int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const unsigned int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const signed long int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const unsigned long int val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const mathematics::numbers::integer val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const mathematics::numbers::natural val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const float val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const double val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const mathematics::numbers::real val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	bool			operator	>=	(const char val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	//bool			operator	>=	(const signed char val1, NAME_V val2)
	//{
	//	return val1 > val2 || val1 == val2;
	//	//return !(val2 > val1);
	//}

	//bool			operator	>=	(const unsigned char val1, NAME_V val2)
	//{
	//	return val1 > val2 || val1 == val2;
	//	//return !(val2 > val1);
	//}

	bool			operator	>=	(const ::std::string val1, NAME_V val2)
	{
		return val1 > val2 || val1 == val2;
		//return !(val2 > val1);
	}

	// && AND
	bool			NAME_V::operator	&&	(const NAME_V val)
	{
		if (_type == type::NUMERIC && val._type == type::NUMERIC)
			return value.numeric && val.value.numeric;
		else
			return false;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	switch (val._type)
		//	{
		//	case type::NUMERIC:
		//		return value.numeric && val.value.numeric;
		//	default:
		//		//if (val.value.Generic.length () == 1)
		//		//	return value.numeric && val.value.Generic [0];
		//		//else
		//		//	return value.numeric;
		//		return false;
		//	}
		//default:
		//	switch (val._type)
		//	{
		//	case type::NUMERIC:
		//		if (value.Generic.length () == 1)
		//			return value.Generic [0] && val.value.numeric;
		//		else
		//			return val.value.numeric;
		//	default:
		//		if (value.Generic.length () == 1 && val.value.Generic.length () == 1)
		//			return value.Generic [0] && val.value.Generic [0];
		//		else
		//			return mathematics::numbers::default;
		//	}
		//}
	}

	bool			NAME_V::operator	&&	(const bool val)
	{
		return *this && (NAME_V) val;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	return value.numeric && val;
		//default:
		//	if (value.Generic.length () == 1)
		//		return value.Generic [0] && val;
		//	else
		//		return val;
		//}
	}

	bool			operator	&&	(const bool val1, NAME_V val2)
	{
		return val2 && val1;
	}

	// || OR
	bool			NAME_V::operator	||	(const NAME_V val)
	{
		switch (_type)
		{
		case type::NUMERIC:
			switch (val._type)
			{
			case type::NUMERIC:
				return value.numeric || val.value.numeric;
			default:
				//if (val.value.Generic.length () == 1)
				//	return value.numeric || val.value.Generic [0];
				//else
					return value.numeric == 0 ? false : true;
			}
		default:
			switch (val._type)
			{
			case type::NUMERIC:
				//if (value.Generic.length () == 1)
				//	return value.Generic [0] || val.value.numeric;
				//else
					return val.value.numeric == 0 ? false : true;
			default:
				//if (value.Generic.length () == 1 && val.value.Generic.length () == 1)
				//	return value.Generic [0] || val.value.Generic [0];
				//else
				//	return mathematics::numbers::default;
				return false;
			}
		}
	}

	bool			NAME_V::operator	||	(const bool val)
	{
		return *this || (NAME_V) val;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	return value.numeric || val;
		//default:
		//	if (value.Generic.length () == 1)
		//		return value.Generic [0] || val;
		//	else
		//		return val;
		//}
	}

	bool			operator	||	(const bool val1, NAME_V val2)
	{
		return val2 || val1;
	}

	// Prefix:
	// Incrementation
	NAME_V	&	NAME_V::operator	++	(void)
	{
		if (_type == type::NUMERIC)
			++ value.numeric;
		//switch (_type)
		//{
		//case type::NUMERIC:
		//	++ value.numeric;
		//	break;
		//default:
		//	if (value.Generic.length () == 1)
		//		++ value.Generic [0];
		//}

		return *this;
	}

	// Decrementation
	NAME_V	&	NAME_V::operator	--	(void)
	{
		switch (_type)
		{
		case type::NUMERIC:
			-- value.numeric;
			break;
		default:
			//if (value.Generic.length () == 1)
			//	-- value.Generic [0];
			//else if (value.Generic.length () > 0)
				value.Generic = value.Generic.substr (0, value.Generic.length () - 1);
		}

		return *this;
	}

	// Suffix / Postfix:
	// Incrementation
	NAME_V		NAME_V::operator	++	(int val)
	{
		NAME_V temp (*this);

		++ (*this);

		return temp;
	}

	// Decrementation
	NAME_V		NAME_V::operator	--	(int val)
	{
		NAME_V temp (*this);

		-- (*this);

		return temp;
	}
}

::std::string tolower (LIB::NAME_V & val)
{
	//::std::string _val = val.to_string ();
	//::std::string s = val.to_string ();
	::std::string s = val;
	LIB::mathematics::numbers::natural length = s.length ();

	for (LIB::mathematics::numbers::natural i = 0; i < length; ++ i)
	{
		s [i] = tolower (s [i]);
	}

	return s;
}

::std::string toupper (LIB::NAME_V & val)
{
	::std::string s = val;
	//::std::string s = "";
	LIB::mathematics::numbers::natural length = s.length ();

	for (LIB::mathematics::numbers::natural i = 0; i < length; ++ i)
	{
		s [i] = toupper (s [i]);
	}

	return s;
}

::std::istream & getline (::std::istream & is, LIB::NAME_V & val, const char delimiter)
{
	::std::string temp;
	::std::getline (is, temp, delimiter);
	val += temp;
	return is;
}

//#endif VARIABLE_CPP
