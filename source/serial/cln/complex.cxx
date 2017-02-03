#include <sstream>
#include <string>
#include <cln/string.h>
//#include <cln/cln.h>

#include "complex.hdr.cxx"

template <typename archive>
void boost::serialization::save (archive & arch, const cln::cl_N & number, const unsigned int & version)
{
	std::stringstream ss;
	std::string s;
	
	ss << number;
	ss >> s;
	arch << s;
}

template <typename archive>
void boost::serialization::load (archive & arch, cln::cl_N & number, const unsigned int & version)
{
	std::string s;
	
	arch >> s;
	//LIB::tool::deserialize_number <archive> (arch, s);
	number = s.c_str ();
	
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

