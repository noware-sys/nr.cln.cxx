//#pragma once

#include <sstream>
#include <string>
#include <cln/string.h>
//#include <cln/cln.h>
#include <cln/complex_io.h>

//#include "complex.hxx"

template <typename archive>
void boost::serialization::save (archive & arch, const cln::cl_N & number, const unsigned int &/* version*/)
{
	std::stringstream ss;
	//std::string s;
	
	ss << number;
	//ss >> s;
	arch << ss.str ();
}

template <typename archive>
void boost::serialization::load (archive & arch, cln::cl_N & number, const unsigned int &/* version*/)
{
	std::string str;
	
	arch >> str;
	//LIB::tool::deserialize_number <archive> (arch, s);
	number = str.c_str ();
	
	//arch & number;
	//arch >> number;
}
/*
template <typename archive>
void LIB::tool::deserialize_number (const archive & arch, std::string & result)
{
	arch >> result;
}
*/
