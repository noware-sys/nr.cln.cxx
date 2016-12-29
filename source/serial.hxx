#pragma once
//#ifndef __SERIALIZATION
//#define __SERIALIZATION

#include <string>
// #include <iostream>
// #include <fstream>

// This library:
//#include "value.h++"
//#include "mathematics.hpp"

//#include "Any.h"

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

#include "serial/cln/complex.hxx"
#include "serial/cln/real.hxx"
#include "serial/cln/integer.hxx"

namespace noware
{
	//namespace tool
	//{
		template <typename type>
		const std::string serialize (const type &);
		
		template <typename type>
		const bool deserialize (const std::string &, type &);
		
		//template <typename type>
		//bool unserialize (std::string, type &);
		
		//template <typename type>
		//bool parse (const std::string &, type &);
		
		// template <typename type>
		// bool parse (std::string, type &);
		
		//template <typename type>
		//std::string serialize (const type &);
	//}
}

#include "serial.txx"

//#endif

