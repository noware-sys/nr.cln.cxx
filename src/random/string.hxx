#pragma once

namespace noware
{
	namespace random
	{
		// default /char set/string/
		const std::string str_dft =
			#include "str_dft.txt"
		;
		
		const std::string string (const noware::nr &/* length*/, const std::string &/* char set*/ = str_dft);
	}
}
