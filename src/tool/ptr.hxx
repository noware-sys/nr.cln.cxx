#pragma once

#include <string>
#include <type_traits>

namespace noware
{
	//namespace tool
	//{
		namespace ptr
		{
			// Convert the pointer to a string:
			const std::string str (const void */* pointer*/);
			
			// Convert the string to an pointer:
			const void * val (const std::string &/* address*/);
			
			
			template <typename type>
			constexpr bool is_lvalue (const type &&);
	//}
}
