//#ifndef UTILITIES
//#define UTILITIES
#include <sstream>
#include <ctime>
#include <random>

#include "utilities.hpp"
#include "containers/variable.hpp"

namespace LIB
{
	bool is_numeric (const std::string & value)
	{
		if (value.empty ())
			return false;

		unsigned int length = value.length ();
		bool decimal_found = false;

		//if (s[0] != '+' || s[0] != '-' || !isdigit(s[0]))
			//return false;

		for
		(
			unsigned int i = 0;
			i < length;
			++ i
		)
		{
			//if (isdigit (value [i]))
			//{
			//	/*continue*/;
			//}
			//else 
				if (value [i] == '.' && !decimal_found)
			{
				decimal_found = true;
			}
			else if (!isdigit (value [i]))
			{
				return false;
			}
		}

		return true;
	}

	mathematics::numbers::natural	digits		(mathematics::numbers::natural n)
	{
		if (n == 0)
			return 1;

		mathematics::numbers::natural digits = 0;

		std::cout << n << std::endl;

		while (n != 0)
		{
		   n  /= 10;
		   ++ digits;
		}

		return digits;
	}

	mathematics::numbers::natural	digits		(mathematics::numbers::integer n)
	{
		if (n == 0)
			return 1;	// Needed for complement ().

		mathematics::numbers::natural digits = 0;

		std::cout << n << std::endl;

		while (n != 0)
		{
		   n  /= 10;
		   ++ digits;
		}

		return digits;
	}

	mathematics::numbers::natural	digits		(const mathematics::numbers::real & n)
	{
		if (n == 0)
			return 1;	// Needed for complement ().

		std::cout << n << std::endl;

		if (n < 0)	// Allow the full range of integer numbers and of natural numbers.
			return digits ((mathematics::numbers::integer) n) + fractions (n);
		else
			return digits ((mathematics::numbers::natural) n) + fractions (n);
		//return digits (n) + fractions (n);
	}
	
	mathematics::numbers::natural	integers	(const mathematics::numbers::real & n)
	{
		return digits ((mathematics::numbers::integer) n);
	}
	
	mathematics::numbers::natural	fractions	(mathematics::numbers::real n /* example: 3.2548 */)
	{
		if (n == 0)
			return 1;	// Needed for complement ().

		mathematics::numbers::natural digits = 0;
		n = n - (mathematics::numbers::integer) n;	// 0.2548

		while (n > 0)
		{
			n *= 10;	// 2.548
			n = n - (mathematics::numbers::integer) n;	//	0.548

			++ digits;
		}

		return digits;
	}

	mathematics::numbers::real modulus (const mathematics::numbers::real & value)
	{
		return value < 0 ? -value : value;
	}

	mathematics::numbers::real complement (const mathematics::numbers::real & value, const mathematics::numbers::natural & radix)
	{
		/*
			The radix complement of an n digit, positive number y, in radix b is
			b ^ n - y

		*/

		mathematics::numbers::real val = std::pow ((long double) radix, (long double) LIB::digits ((mathematics::numbers::real) LIB::modulus (value))) - value;

		return val;
	}

	std::string string (const signed short int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const unsigned short int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const signed int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const unsigned int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const signed long int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const unsigned long int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const signed long long int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const unsigned long long int & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const float & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const double & value)
	{
		return string ((mathematics::numbers::real) value);
	}

	std::string string (const mathematics::numbers::real & value)
	{
		//int i = 5;
		//std::string s;
		std::stringstream ss;
		ss << value;
		//s = ss.str();
		return ss.str ();
	}

	std::string string (const char & value)
	{
		//int i = 5;
		//std::string s;
		std::stringstream ss;
		ss << value;
		//s = ss.str  ();
		return ss.str ();
	}

	//std::string string (const signed char value)
	//{
	//	//int i = 5;
	//	//std::string s;
	//	std::stringstream ss;
	//	ss << value;
	//	//s = ss.str();
	//	return ss.str ();
	//}

	//std::string string (const unsigned char value)
	//{
	//	//int i = 5;
	//	//std::string s;
	//	std::stringstream ss;
	//	ss << value;
	//	//s = ss.str();
	//	return ss.str ();
	//}

	std::string reverse (const std::string & input)
	{
		std::string output = "";
		unsigned long long int	index,
								length = input.length ();

		for (index = length - 1; index >= 0; -- index)
		{
			output += input [index];
		}

		return output;
	}

	char toggle_case (const char & input)
	{
		if (isupper (input))
		{
			return ::tolower (input);
		}
		else
		{
			return ::toupper (input);
		}
	}

	std::string toggle_case (std::string value)
	{
		mathematics::numbers::natural	index,
										length = value.length ();

		for (index = 0; index < length; ++ index)
		{
			value [index] = toggle_case (value [index]);
		}

		return value;
	}

	std::string multiply (const std::string & input, const mathematics::numbers::real & length)
	{
		std::string output = "";
		mathematics::numbers::natural	i,
										length_i,
										remainder;

		length_i = length;	// get the floor (integer) of the input's length;
		remainder = input.length () * (length - length_i /* decimal part of length */);	// get the number of characters to append.

		for (i = 0; i < length_i; ++ i)
		{
			output += input;
		}

		for (mathematics::numbers::natural j = 0; j < remainder; ++ j)
		{
			output += input [j];
		}

		return output;
	}

	bool is_palindrome (const std::string & s)
	{
		if (s.empty ())
			return false;
		else
		{
			unsigned int length = s.length ();

			if (length == 1)
				return true;
			else
			{
				for (unsigned int i = 0; i < length / 2; ++ i)
					if (s [i] != s [length - i - 1])
						return false;

				return true;
			}
		}
	}

	void randomize (void)
	{
		//srand ((unsigned) time (NULL));
	}

	unsigned long long int random (const mathematics::numbers::natural & max, const mathematics::numbers::natural & min)
	{
		// incomplete.

		// initialize random seed:
		//srand ((unsigned) time (null));
		
		return min + mathematics::numbers::natural ((max - min + 1) * rand () / (RAND_MAX + 1.0));
	}

	#ifdef __cplusplus__

		#include <iostream>
		#include <string>

		void clear_screen (void)
		{
			std::cout << string (100, '\n');
		}

	#else

		#include <stdio.h>
		#include <iostream>

		void clear_screen (void)
		{
			for (unsigned short int n = 0; n < 100; ++ n)
				std::cout << std::endl;
		}

	#endif
	
	// intended to be portable. 
	void pause (const std::string & prompt)
	{
		std::cout << prompt;

		std::cout.flush ();
		std::cin.ignore ();
	}

	std::string lower (std::string value)
	{
		unsigned long long int length = value.length ();

		for (unsigned long long int i = 0; i < length; ++ i)
		{
			value [i] = ::tolower (value [i]);
		}

		return value;
	}

	std::string upper (std::string value)
	{
		unsigned long long int length = value.length ();

		for (unsigned long long int i = 0; i < length; ++ i)
		{
			value [i] = ::toupper (value [i]);
		}

		return value;
	}

	LIB::randomizer::randomizer (const mathematics::numbers::natural & maximum, const mathematics::numbers::natural & minimum)
	{
		_min = minimum;
		_max = maximum;

		//srand ((unsigned) time (NULL));
		//srand ((unsigned long long int) time (NULL));
		srand (time (NULL));
	}

	LIB::mathematics::numbers::natural LIB::randomizer::generate (const mathematics::numbers::natural & maximum, const mathematics::numbers::natural & minimum)
	{
		return LIB::random (maximum, minimum);
	}

	LIB::mathematics::numbers::natural LIB::randomizer::generate (void)
	{
		return LIB::random (_max, _min);
	}

	// Getters:
	LIB::mathematics::numbers::natural LIB::randomizer::min (void)
	{
		return _min;
	}

	LIB::mathematics::numbers::natural LIB::randomizer::max (void)
	{
		return _max;
	}
			
	// Setters:
	LIB::mathematics::numbers::natural LIB::randomizer::min (const mathematics::numbers::natural & minimum)
	{
		LIB::mathematics::numbers::natural temp_val = _min;
		_min = minimum;
		
		return temp_val;
	}

	LIB::mathematics::numbers::natural LIB::randomizer::max (const mathematics::numbers::natural & maximum)
	{
		LIB::mathematics::numbers::natural temp_val = _max;
		_max = maximum;

		return temp_val;
	}
}

//#endif UTILITIES
