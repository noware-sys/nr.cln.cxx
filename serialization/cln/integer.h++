//#include <string>
//#include <sstream>
#include <cln/integer.h>

BOOST_SERIALIZATION_SPLIT_FREE (cln::cl_I)

namespace boost
{
	namespace serialization
	{
		template <typename archive>
		void save (archive & arch, const cln::cl_I & number, const unsigned int & version);
		
		template <typename archive>
		void load (archive & arch, cln::cl_I & number, const unsigned int & version);
	}	// namespace serialization
}	// namespace boost
/*
namespace LIB
{
	namespace tool
	{
		template <typename archive>
		void deserialize_number (const archive &, std::string &);
	}
}
*/

#include "integer.c++"

