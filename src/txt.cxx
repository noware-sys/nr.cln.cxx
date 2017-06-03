//#ifndef VARIABLE_CPP
//#define VARIABLE_CPP
//#pragma once

#include "txt.hxx"

#include "seq.cxx"

/*
#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
#include <sstream>
//#include <iostream>
#include "../default.h++"
#include "text.h++"
#include "variable.h++"
//#include "../Utilities.h"
//using namespace ::std;

/*
LIB::text::text (void)
{
	
}

LIB::text::text (const text &)
{
	
}

LIB::text::text (const char *)
{
	
}* /

noware::container::text::operator char * (void) const
{
	return value;
}

noware::container::text noware::container::text::operator = (const char * other)
{
	/*
	try
	{
		while (true)
		{
			
		}
	}
	catch (...)
	{}
* /	
	value = other;
	return * this;
}
*/
