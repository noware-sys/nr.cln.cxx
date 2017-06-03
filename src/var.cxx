#pragma once

//#ifndef VARIABLE_CPP
//#define VARIABLE_CPP

/*
#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
//#include <iostream>
//#include "../default.h++"
*/
#include <sstream>

//#include "../Utilities.h"
//using namespace ::std;

// #include "text.cxx"
//#include "serial.cxx"
//#include "tool.cxx"
//#include "tool/.cxx"
//#include "content/value.h++"
//#include "misc/serial.cxx"

// var :: container
//#include ".var/contnr.cxx"

/*
#include ".var/constructor.cxx"
#include ".var/destructor.cxx"

#include ".var/set.cxx"
#include ".var/conversion.cxx"
#include ".var/comparison.cxx"

#include ".var/addition.cxx"
#include ".var/substraction.cxx"
//
#include ".var/multiplication.cxx"
#include ".var/division.cxx"
//
#include ".var/exponentiation.cxx"
#include ".var/modulo.cxx"

#include ".var/special.cxx"
*/

/*
#include ".var/constr.cxx"
#include ".var/destr.cxx"

#include ".var/set.cxx"
#include ".var/conver.cxx"
#include ".var/compar.cxx"

#include ".var/add.cxx"
#include ".var/substr.cxx"
//
#include ".var/multi.cxx"
#include ".var/div.cxx"
//
#include ".var/exponent.cxx"
#include ".var/modulo.cxx"

#include ".var/special.cxx"
*/

#include "var.hxx"

#include "nr.cxx"
#include "serial.cxx"
#include "tool/string.cxx"

#include ".var/.cxx"

/*
	var
	serialization
*/
template <typename archive> 
void noware::var::serialize (archive & arch, const unsigned int &/* version*/)
{
	arch & t;
	arch & txt;
	arch & nr;
}
/*
const std::string noware::var::serialize (void) const
{
	return noware::serialize <noware::var> (*this);
}

const bool noware::var::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::var> (*this, serial);
}
*/

/*
const std::string noware::var::to_str (void) const
{
	if (_t == t::nr)
	{
		//return noware::tool::string (content.number);
		std::stringstream ss;
		ss << nr;
		//s = ss.str();
		return ss.str ();
		
		//return "";
	}
	else
		return text;
}
*/
/**/
const noware::nr noware::var::size (void) const
{
	//return std::string (*this).size ();
	return operator const std::string ().size ();
}

std::istream & getline (std::istream & stream, noware::var & value, const char delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}

/*
const noware::var & noware::var::operator += (const var & other)
{
	//contnt += other.contnt;
	return *this;
}
*/
