#include <typeinfo.h>
#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
//#include <sstream>
//#include <iostream>
#include "../default.hpp"
#include "any.hpp"
#include "array.hpp"
//#include "../Utilities.h"
//using namespace ::std;

namespace boost
{
	namespace serialization
	{

		template <class Archive>
		void serialize (Archive & destination, boost::any & object, const unsigned int version)
		{
			//destination & object.degrees;
			//destination & object.minutes;
			//destination & object.seconds;
			//object.
			//destination & object;
		}
	}
}

LIB::NAME_NE::NAME_NE (void)
{
	//_type = NULL;
	//_type;
	//type = NULL;
	//type (,);
	//*this ->

	content.clear ();
}

//LIB::NAME_NE::~NAME_NE (void)
//{
//	//& container;
//	//delete _type;
//	//delete content;
//}

LIB::NAME_NE & LIB::NAME_NE::operator = (const boost::any & value)
//LIB::NAME_NE & LIB::NAME_NE::operator = (const void *& value)
{
	//type = 
/*		if (container.empty ())
		return container = value;
	else
		return
*/	
	//*this -> content = ;
	//return container = & value;
	//return *this;
	//* _type = typeid (value);
	//content = value;
	
	//std::string s;
	//std::stringstream ss;
	//s = "";
	//s = *this;

	//ss.clear ();	// Make sure that there is nothing in the stream.

	content.clear ();	// Reset the placeholder.

	// Put the instruction's members into an output stream:
	boost::archive::text_oarchive a (content);
	a << value;
	//content << value;

	// Get the string representation:
	//std::getline (ss, s, '\n');

	return *this;
}

//template <typename type>
int LIB::NAME_NE::get_int (void)
{
	int variable;

	try
	{
		// Get the instruction's members from the input stream:
		boost::archive::text_iarchive a (content);
		//a >> ss;
		//std::getline (content, s, '\n');
		//a >> s;
		a >> variable;

	}
	catch (...)
	{

	}

	return variable;

}

//LIB::NAME_NE::operator std::stringstream (void) const
//{
//	return content;
//}

std::string LIB::NAME_NE::get (void)
{
	std::string s;
	//std::stringstream ss;

	//content >> s;

	//return s;

	//ss.clear ();	// Make sure that there is nothing in the stream.

	// Convert the string into a string stream:
	//ss << content;

	try
	{
		// Get the instruction's members from the input stream:
		boost::archive::text_iarchive a (content);
		//a >> ss;
		std::getline (content, s, '\n');
		//a >> s;

		return s;
	}
	catch (...)
	{
		return "";
	}
}

//bool LIB::NAME_NE::get (LIB::NAME_NE &, ...)
//{
//	va_list vl;
//	//va_start (vl, 1);
//
//	//va_arg (vl, typeid (int));
//
//	va_end(vl);
//}

//LIB::NAME_NE::operator void *& (void) const
//{
//	//
//	////std::string s;
//	////std::stringstream ss;
//	////s = "";
//	////s = *this;
//	//void * temp;
//	////ss.clear ();	// Make sure that there is nothing in the stream.
//
//	////content.clear ();
//
//	//// Convert the string into a string stream:
//	//ss << _instruction;
//
//	//try
//	//{
//	//	// Get the instruction's members from the input stream:
//	//	boost::archive::text_iarchive a (ss);
//	//	a >> *this;
//
//	//	return true;
//	//}
//	//catch (...)
//	//{
//	//	return false;
//	//}
//
//	////return content;
//	//return "";
//}

//template <typename T>
//LIB::NAME_NE::operator void * (void)
//LIB::NAME_NE::operator boost::any (void)
////NAME_NE::operator T (void)
////T LIB::NAME_NE::get (void)
//{
//	//return boost::any_cast <content.type ()> (content);
//	//return boost::any_cast <(reinterpret_cast <const (content.type ().name ())> (content.type ()) content.type ()> (content);
//
//	//return boost::any_cast <T> (content);
//	//return boost::any_cast <const_cast <const content> (content)> (content);
//	//return const_cast <typeid (content)> (content);
//
//	//NAME_V		operator	-	(const NAME_V &);
//	//NAME_V		operator	-	(const signed short int &);
//	//NAME_V		operator	-	(const unsigned short int &);
//	//NAME_V		operator	-	(const signed int &);
//	//NAME_V		operator	-	(const unsigned int &);
//	//NAME_V		operator	-	(const signed long int &);
//	//NAME_V		operator	-	(const unsigned long int &);
//	//NAME_V		operator	-	(const signed long long int &);
//	//NAME_V		operator	-	(const unsigned long long int &);
//	//NAME_V		operator	-	(const float &);
//	//NAME_V		operator	-	(const double &);
//	//NAME_V		operator	-	(const mathematics::numbers::real &);
//	//NAME_V		operator	-	(const char &);
//	////NAME_V		operator	-	(const char);
//	////NAME_V		operator	-	(const signed char);
//	////NAME_V		operator	-	(const unsigned char);
//	//NAME_V		operator	-	(const ::std::string &);
//
//	//if (content.type () == typeid (void *))
//	//{
//	//	return boost::any_cast <void *> (content);
//	//}
//	//else if (content.type () == typeid (bool))
//	//{
//	//	return boost::any_cast <bool> (content);
//	//}
//	//else if (content.type () == typeid (signed short int))
//	//{
//	//	return boost::any_cast <signed short int> (content);
//	//}
//	//else if (content.type () == typeid (unsigned short int))
//	//{
//	//	return boost::any_cast <unsigned short int> (content);
//	//}
//	//else if (content.type () == typeid (signed int))
//	//{
//	//	return boost::any_cast <signed int> (content);
//	//}
//	//else if (content.type () == typeid (unsigned int))
//	//{
//	//	return boost::any_cast <unsigned int> (content);
//	//}
//	//else if (content.type () == typeid (signed long int))
//	//{
//	//	return boost::any_cast <signed long int> (content);
//	//}
//	//else if (content.type () == typeid (unsigned long int))
//	//{
//	//	return boost::any_cast <unsigned long int> (content);
//	//}
//	//else if (content.type () == typeid (signed long long int))
//	//{
//	//	return boost::any_cast <signed long long int> (content);
//	//}
//	//else if (content.type () == typeid (unsigned long long int))
//	//{
//	//	return boost::any_cast <unsigned long long int> (content);
//	//}
//	//else if (content.type () == typeid (float))
//	//{
//	//	return boost::any_cast <float> (content);
//	//}
//	//else if (content.type () == typeid (double))
//	//{
//	//	return boost::any_cast <double> (content);
//	//}
//	//else if (content.type () == typeid (long double))
//	//{
//	//	return boost::any_cast <long double> (content);
//	//}
//	//else if (content.type () == typeid (char))
//	//{
//	//	return boost::any_cast <char> (content);
//	//}
//	//else if (content.type () == typeid (signed char))
//	//{
//	//	return boost::any_cast <signed char> (content);
//	//}
//	//else if (content.type () == typeid (unsigned char))
//	//{
//	//	return boost::any_cast <unsigned char> (content);
//	//}
//	//else if (content.type () == typeid (std::string))
//	//{
//	//	return boost::any_cast <std::string> (content);
//	//}
//	////else if (content.type () == typeid (LIB::NAME_A <>))
//	////{
//	////	return boost::any_cast <LIB::NAME_A <>> (content);
//	////}
//	//else
//	//{
//	//	return content;
//	//}
//
//	return content;
//}
//
//LIB::NAME_NE::operator void * (void)
//{
//	return boost::any_cast <void *> (content);
//}
//
//LIB::NAME_NE::operator bool (void)
//{
//	return boost::any_cast <bool> (content);
//}
//
//LIB::NAME_NE::operator unsigned short int (void)
//{
//	return boost::any_cast <unsigned short int> (content);
//}
//
//LIB::NAME_NE::operator signed short int (void)
//{
//	return boost::any_cast <signed short int> (content);
//}
//
//LIB::NAME_NE::operator unsigned int (void)
//{
//	return boost::any_cast <unsigned int> (content);
//}
//
//LIB::NAME_NE::operator signed int (void)
//{
//	return boost::any_cast <signed int> (content);
//}
//
//LIB::NAME_NE::operator unsigned long int (void)
//{
//	return boost::any_cast <unsigned long int> (content);
//}
//
//LIB::NAME_NE::operator signed long int (void)
//{
//	return boost::any_cast <signed long int> (content);
//}
//
//LIB::NAME_NE::operator unsigned long long int (void)
//{
//	return boost::any_cast <unsigned long long int> (content);
//}
//
//LIB::NAME_NE::operator signed long long int (void)
//{
//	return boost::any_cast <signed long long int> (content);
//}
//
//LIB::NAME_NE::operator float (void)
//{
//	return boost::any_cast <float> (content);
//}
//
//LIB::NAME_NE::operator double (void)
//{
//	return boost::any_cast <double> (content);
//}
//
//LIB::NAME_NE::operator long double (void)
//{
//	return boost::any_cast <long double> (content);
//}
//
//LIB::NAME_NE::operator char (void)
//{
//	return boost::any_cast <char> (content);
//}
//
//LIB::NAME_NE::operator unsigned char (void)
//{
//	return boost::any_cast <unsigned char> (content);
//}
//
//LIB::NAME_NE::operator signed char (void)
//{
//	return boost::any_cast <signed char> (content);
//}
//
//LIB::NAME_NE::operator std::string (void)
//{
//	return boost::any_cast <std::string> (content);
//}

//void * NAME_NE::operator -> (void)
//{

//}
//void NAME_NE::f (void * v, int i)
//{

//}

//NAME_NE & NAME_NE::set (boost::any val)
//{
//	content = val;

//	return *this;
//}

//NAME_NE & NAME_NE::set (void * ne, ...)
//{
//	va_list arguments;

//	va_start (arguments, ne);

//	va_arg (arguments, void *);

//	va_end (arguments);
//}

//  template <typename ValueType>
//  ValueType get (void) //(any * operand)
//  {
	//return boost::any_cast <ValueType> (content);
//      //return & static_cast <any::holder <ValueType> *> (operand -> content) -> held;
//  }
//virtual const std::type_info & NAME_NE::type (void) const
//{
//	return typeid (_type);
//}
