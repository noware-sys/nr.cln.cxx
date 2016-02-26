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

#include "serial.t++"

//#endif
