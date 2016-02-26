#pragma once
//#ifndef __SERIALIZATION
//#define __SERIALIZATION

#include <string>
// #include <iostream>
// #include <fstream>

// This library:
#include "default.h++"
//#include "mathematics.hpp"

//#include "Any.h"

namespace LIB
{
	//namespace tools
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

#include "serialization.t++"

//#endif
