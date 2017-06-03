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

#include "var.hxx"

//#include "../Utilities.h"
//using namespace ::std;

// #include "text.cxx"
//#include "serial.cxx"
//#include "tool.cxx"
#include "tool/.cxx"
#include "nr.cxx"
//#include "content/value.h++"

// var :: container
//#include ".var/contnr.cxx"

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
/*
	var
	serialization
*/
template <typename archive> 
void noware::var::serialize (archive & arch, const unsigned int & version)
{
	arch & _t;
	arch & text;
	arch & nr;
}

const std::string noware::var::serialize (void) const
{
	return noware::serialize <noware::var> (*this);
}

const bool noware::var::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::var> (*this, serial);
}

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

/**/
const noware::nr noware::var::length (void) const
{
	if (t == _type::nr)
		//return noware::tool::digits (content.number);
		return 0;
	else
		return text.length ();
}

std::istream & getline (std::istream & stream, noware::var & value, const char delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}

