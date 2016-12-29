#pragma once

#include <string>
#include <iostream>
#include <fstream>

//#include <boost/random/random_device.hpp>

//#include "container/content/value.h++"
//#include "math.h++"

namespace noware
{
	namespace tool
	{
		// Converions to string:
		const std::string string	(const signed int &);
		const std::string string	(const unsigned int &);
		const std::string string	(const signed long int &);
		const std::string string	(const unsigned long int &);
		const std::string string	(const signed long long int &);
		const std::string string	(const unsigned long long int &);
		const std::string string	(const float &);
		const std::string string	(const double &);
		const std::string string	(const long double &);
		const std::string string	(const char &);
		//const std::string string	(const char *&);
		// const std::string string	(const noware::math::numbers::integer &);
		// const std::string string	(const noware::math::numbers::real &);
		// const std::string string	(const noware::math::number &);
		//std::string String	(const signed char);
		//std::string String	(const unsigned char);
	}
}

