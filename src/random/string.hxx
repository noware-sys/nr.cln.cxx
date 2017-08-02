#pragma once

namespace noware
{
	namespace random
	{
		// default /character set/string/
		const std::string str_dft =
			#include "str_dft.txt"
		;
		//const std::string str_size_dft = 1;
		
		const std::string string (const noware::nr &/* size*//* = str_size_dft*/, const std::string &/* char_set*/ = str_dft);
	}
}
