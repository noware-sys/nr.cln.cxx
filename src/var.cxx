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
#include "nr.cxx"
//#include "serial.cxx"
//#include "tool.cxx"
#include "tool/.cxx"
//#include "content/value.h++"

// var :: container
#include ".var/container.cxx"

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
	var
	serialization
*/
template <typename archive> 
void noware::var::serialize (archive & arch, const unsigned int & version)
{
	arch & content;
}

const std::string noware::var::serialize (void) const
{
	return noware::serialize <noware::var> (*this);
}

const bool noware::var::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::var> (serial, *this);
}

const std::string noware::var::text (void) const
{
	if (content.t == container::type::numeric)
	{
		//return noware::tool::string (content.number);
		std::stringstream ss;
		ss << content.number;
		//s = ss.str();
		return ss.str ();
		
		//return "";
	}
	else
		return content.text;
}

/**/
const noware::nr noware::var::length (void) const
{
	if (content.t == container::type::generic)
		return content.text.length ();
	else
		//return noware::tool::digits (content.number);
		return 0;
}

std::istream & getline (std::istream & stream, noware::var & value, const char delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}

