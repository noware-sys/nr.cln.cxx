#pragma once

namespace noware
{
	namespace tool
	{
		// Determines if a string is numeric (in base 10):
		const bool is_numeric	(const std::string &);
		const bool is_numeric	(const char &);
		const bool is_numeric	(const unsigned char &);
		const bool is_numeric	(const signed char &);
		const bool is_number	(const std::string &);
		//long double (const std::string &);	// Converts a string to a number.
	}
}

