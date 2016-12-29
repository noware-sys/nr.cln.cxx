#pragma once

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
#include "any.hxx"

//#include "../Utilities.h"
//using namespace ::std;

#include "text.cxx"
#include "number.cxx"
//#include "serial.cxx"
//#include "tool.cxx"
#include "tool/*.cxx"
//#include "content/value.h++"

// any :: container
#include ".any/container.cxx"

#include ".any/constructor.cxx"
#include ".any/destructor.cxx"

#include ".any/set.cxx"
#include ".any/conversion.cxx"
#include ".any/comparison.cxx"

#include ".any/addition.cxx"
#include ".any/substraction.cxx"
//
#include ".any/multiplication.cxx"
#include ".any/division.cxx"
//
#include ".any/exponentiation.cxx"
#include ".any/modulo.cxx"

#include ".any/special.cxx"

/*
	any
	serialization
*/
template <typename archive> 
void noware::any::serialize (archive & arch, const unsigned int & version)
{
	arch & content;
}

const std::string noware::any::serialize (void) const
{
	return noware::serialize <noware::any> (*this);
}

const bool noware::any::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::any> (serial, *this);
}

const std::string noware::any::text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::string (content.number);
		return "";
	else
		return content.text;
}

/**/
const noware::number noware::any::length (void) const
{
	if (content.t == container::type::generic)
		return content.text.length ();
	else
		//return noware::tool::digits (content.number);
		return 0;
}

std::istream & getline (std::istream & stream, noware::any & value, const char delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}

