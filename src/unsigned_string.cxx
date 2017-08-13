#pragma once

#include "unsigned_string.hxx"

namespace noware
{
	std::ostream & operator << (std::ostream & stream, const unsigned_string & self)
	{
		for (const unsigned char & c : self)
		{
			std::cout << c;
		}
		
		return stream;
	}
}
