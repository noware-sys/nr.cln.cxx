#pragma once

// Standard library:
#include <sstream>
//#include <string>
//#include <iostream>
//#include <fstream>

/*
// Boost serialization:
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_member.hpp>	// For separating loading and saving.
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/bitset.hpp>
//#include <boost/serialization/hash_map.hpp>
//#include <boost/serialization/hash_set.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/slist.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
*/

//#include ".serial/cln/complex.cxx"
//#include ".serial/cln/real.cxx"
//#include ".serial/cln/integer.cxx"

#include "serial.hxx"

/*template <typename type>
bool noware::parse (std::string serial, type & object)
{
	return deserialize (serial, object);
}
*/

template <typename type>
const bool noware::serialize (std::string & serial, const type & object)
{
	try
	{
		//std::string s;
		std::ostringstream ss;
		//s = "";
		//s = *this;
		
		//ss.clear ();	// Make sure that there is nothing in the stream.
		
		
		// Put the obect's serializable members into an output stream:
		boost::archive::text_oarchive arch (ss);
		arch << object;
		
		// Get the string representation:
		//std::getline (ss, s/*, '\n'*/);
		serial = ss.str ();
		
		return true;
		//return s;
	}
	catch (...)
	{
		return false;
	}
}

template <typename type>
const bool noware::deserialize (type & object, const std::string & serial)
{
	try
	{
		//std::string s;
		std::istringstream ss (serial);
		//s = "";
		//s = *this;
		
		//s.clear ();
		//ss.clear ();	// Make sure that there is nothing in the stream.
		
		// Convert the string into a string stream:
		//ss << serial;
		
		// Get the obect's serializable members from the input stream:
		boost::archive::text_iarchive arch (ss);
		arch >> object;
		
		return true;
	}
	catch (...)
	{
		return false;
	}
}

/*template <typename type>
bool noware::unserialize (std::string serial, type & object)
{
	return deserialize (serial, object);
}*/

//template <typename type>
//bool noware::parse (std::string serial, type & object)
//{
//	return noware::parse (const_cast <const std::string> (serial), object);
//}

//template <typename type>
//std::string noware::serialize (type object)
//{
//	return noware::serialize (const_cast <const type> (object));
//}

/*
noware::serial::serial (void)
{
}

noware::serial::~serial (void)
{
}
*/

template <typename archive>
void noware::serial::serialize (archive &, const unsigned int &/* version*/)
{
}

const std::string noware::serial::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::serial> (serial, *this))
		return serial;
	else
		return "";
}

const bool noware::serial::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::serial> (*this, serial);
}
