#ifndef SERIALIZATION
#define SERIALIZATION

#include <string>
#include <iostream>
#include <fstream>

//#include "default.hpp"
//#include "mathematics.hpp"

//#include "Any.h"

namespace LIB
{
	//template <typename type>
	//bool parse (const std::string &, type &);
	
	template <typename type>
	bool parse (std::string, type &);

	//template <typename type>
	//std::string serialize (const type &);

	template <typename type>
	std::string serialize (type);
}

#include "serialization.tpp"

#endif SERIALIZATION
