//#ifndef VARIABLE_CPP
//#define VARIABLE_CPP

/*
#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
#include <sstream>
//#include <iostream>
//#include "../default.h++"
*/
#include "any.h++"

//#include "../Utilities.h"
//using namespace ::std;

//
// any :: container
//
#include ".any/container.c++"

#include ".any/constructor.c++"
#include ".any/destructor.c++"

#include ".any/set.c++"
#include ".any/conversion.c++"
#include ".any/comparison.c++"

#include ".any/addition.c++"
#include ".any/substraction.c++"
//
#include ".any/multiplication.c++"
#include ".any/division.c++"
//
#include ".any/exponentiation.c++"
#include ".any/modulo.c++"

#include ".any/special.c++"

/*
	any
	serialization
*/
template <typename archive> 
void noware::container::any::serialize (archive & arch, const unsigned int & version)
{
	arch & content;
}

const std::string noware::container::any::serialize (void) const
{
	return noware::serialize <noware::container::any> (*this);
}

const bool noware::container::any::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::container::any> (serial, *this);
}

const std::string noware::container::any::text (void) const
{
	if (content.t == container::type::numeric)
		return noware::tool::string (content.number);
	else
		return content.text;
}

/**/
const noware::math::number noware::container::any::length (void) const
{
	if (content.t == container::type::generic)
		return content.text.length ();
	else
		return noware::tool::digits (content.number);
}

std::istream & getline (std::istream & stream, noware::container::any & value, const char delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}

