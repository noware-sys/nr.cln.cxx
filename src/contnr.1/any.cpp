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


//LIB::NAME_NE::NAME_NE (void)
//{
//	//_type = NULL;
//	//_type;
//	//type = NULL;
//	//type (,);
//	//*this ->
//
//}
//
//LIB::NAME_NE::~NAME_NE (void)
//{
//	//& container;
//	//delete _type;
//	//delete content;
//}

LIB::NAME_NE & LIB::NAME_NE::operator = (const boost::any & value)
//LIB::NAME_NE & LIB::NAME_NE::operator = (void * value)
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
	content = value;

	return *this;
}

//template <typename T>
//LIB::NAME_NE::operator void * (void)
LIB::NAME_NE::operator boost::any (void)
//NAME_NE::operator T (void)
//T LIB::NAME_NE::get (void)
{
	//return boost::any_cast <content.type ()> (content);
	//return boost::any_cast <(reinterpret_cast <const (content.type ().name ())> (content.type ()) content.type ()> (content);

	//return boost::any_cast <T> (content);
	//return boost::any_cast <const_cast <const content> (content)> (content);
	//return const_cast <typeid (content)> (content);

	//NAME_V		operator	-	(const NAME_V &);
	//NAME_V		operator	-	(const signed short int &);
	//NAME_V		operator	-	(const unsigned short int &);
	//NAME_V		operator	-	(const signed int &);
	//NAME_V		operator	-	(const unsigned int &);
	//NAME_V		operator	-	(const signed long int &);
	//NAME_V		operator	-	(const unsigned long int &);
	//NAME_V		operator	-	(const signed long long int &);
	//NAME_V		operator	-	(const unsigned long long int &);
	//NAME_V		operator	-	(const float &);
	//NAME_V		operator	-	(const double &);
	//NAME_V		operator	-	(const mathematics::numbers::real &);
	//NAME_V		operator	-	(const char &);
	////NAME_V		operator	-	(const char);
	////NAME_V		operator	-	(const signed char);
	////NAME_V		operator	-	(const unsigned char);
	//NAME_V		operator	-	(const ::std::string &);

	if (content.type () == typeid (void *))
	{
		return boost::any_cast <void *> (content);
	}
	else if (content.type () == typeid (bool))
	{
		return boost::any_cast <bool> (content);
	}
	else if (content.type () == typeid (signed short int))
	{
		return boost::any_cast <signed short int> (content);
	}
	else if (content.type () == typeid (unsigned short int))
	{
		return boost::any_cast <unsigned short int> (content);
	}
	else if (content.type () == typeid (signed int))
	{
		return boost::any_cast <signed int> (content);
	}
	else if (content.type () == typeid (unsigned int))
	{
		return boost::any_cast <unsigned int> (content);
	}
	else if (content.type () == typeid (signed long int))
	{
		return boost::any_cast <signed long int> (content);
	}
	else if (content.type () == typeid (unsigned long int))
	{
		return boost::any_cast <unsigned long int> (content);
	}
	else if (content.type () == typeid (signed long long int))
	{
		return boost::any_cast <signed long long int> (content);
	}
	else if (content.type () == typeid (unsigned long long int))
	{
		return boost::any_cast <unsigned long long int> (content);
	}
	else if (content.type () == typeid (float))
	{
		return boost::any_cast <float> (content);
	}
	else if (content.type () == typeid (double))
	{
		return boost::any_cast <double> (content);
	}
	else if (content.type () == typeid (long double))
	{
		return boost::any_cast <long double> (content);
	}
	else if (content.type () == typeid (char))
	{
		return boost::any_cast <char> (content);
	}
	else if (content.type () == typeid (signed char))
	{
		return boost::any_cast <signed char> (content);
	}
	else if (content.type () == typeid (unsigned char))
	{
		return boost::any_cast <unsigned char> (content);
	}
	else if (content.type () == typeid (std::string))
	{
		return boost::any_cast <std::string> (content);
	}
	//else if (content.type () == typeid (LIB::NAME_A <>))
	//{
	//	return boost::any_cast <LIB::NAME_A <>> (content);
	//}
	else
	{
		return content;
	}

	//return content;
}

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
