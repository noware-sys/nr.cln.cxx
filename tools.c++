//#ifndef UTILITIES
//#define UTILITIES
#include <sstream>
#include <ctime>
#include <random>
//#include <cctype>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <conio.h>
//#else
////	#include <conio.h>
//	#include <fcntl.h>
#endif
/*
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/io.h>
#include <sys/types.h>
#include <fcntl.h>
*/
//#include "./nix/unistd.h"

#include "./tools.h++"
#include "./containers/variable.h++"

namespace LIB
{
	namespace tools
	{
		bool is_numeric (const std::string & value)
		{
			if (value.empty ())
				return false;

			/*unsigned int*/mathematics::numbers::natural length = value.length ();
			bool decimal_found = false;

			//if (s[0] != '+' || s[0] != '-' || !isdigit(s[0]))
				//return false;

			for
			(
				/*unsigned int*/mathematics::numbers::natural i = 0;
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

			mathematics::numbers::real val = std::pow ((long double) radix, (long double) digits ((mathematics::numbers::real) modulus (value))) - value;

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
		
		/*
		std::string string (const char value [])
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		*/
		
		std::string reverse (const std::string & input)
		{
			std::string output = "";
			signed long long int	index,
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
				unsigned long int length = s.length ();

				if (length == 1)
					return true;
				else
				{
					for (unsigned long int i = 0; i < length / 2; ++ i)
						if (s [i] != s [length - i - 1])
							return false;

					return true;
				}
			}
		}
	/*
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
	*/
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
			std::string input;
			
			std::cout << prompt;

			std::cout.flush ();

			//std::cout << "(" << std::cin.gcount () << ")";
			//::std::string in;
			
			//std::cin.ignore ();
			//::std::getline (::std::cin, in);
			
			//char c;
			//int n;
			//size_t n;
			//std::string s;
			//std::istream is (s);

			//char * buffer = new char [1];


			// Wait for a key to be pressed.
			//do
			//{
			//	// http://codewiki.wikidot.com/c:system-calls:read
			//	//n = read (0, & c, 1);
			//	//std::cin.read (& c, 1);
			//	//c = std::cin.get ();
			//	
			//	/*
			//		http://www.daniweb.com/software-development/cpp/threads/412657/needed-help-on-a-c-program
			//		http://stackoverflow.com/questions/6479286/check-whether-key-is-pressed
			//		http://www.cplusplus.com/forum/beginner/27947/
			//		http://answers.yahoo.com/question/index?qid=20121229092903AAdA5wl
			//		http://programming59.blogspot.ca/2011/07/getch-function-in-cc-language.html
			//	*/
			//}
			//while (::_kbhit () == 0);

			////std::cout << "PASS(1)";
			//
			//// Read all the pressed keys, so that the next loop is entered.
			//do
			//{
			//	::getch ();
			//}
			//while (::_kbhit () != 0);

			#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
				/*::*/_getch ();
			#else
				//getch ();
				
				
				signed short int i;
				char c;
				do
					i = read (0, &c, 1);
				while (i <= 0);
				
				//std::cout << "Pressed [" << i << "] (" << c << ")" << std::endl;
				
				
				////std::getchar ();
				//std::getline (std::cin, input);
			#endif
			// Wait for any keys to be released, if they are still pressed.
			//do
			//{
			//	//std::cout << ::_kbhit () << std::endl;
			//}
			//while (::_kbhit () != 0);

			//std::cout << "PASS(2)";
			//::std::cin >> c;
			//::std::cin.ignore ();

			//std::cout.flush ();
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

		randomizer::randomizer (const mathematics::numbers::natural & maximum, const mathematics::numbers::natural & minimum)
		{
			_min = minimum;
			_max = maximum;

			//srand ((unsigned) time (NULL));
			//srand ((unsigned long long int) time (NULL));
			srand (time (NULL));
		}

		LIB::mathematics::numbers::natural randomizer::generate (const mathematics::numbers::natural & maximum, const mathematics::numbers::natural & minimum)
		{
			return minimum + mathematics::numbers::natural ((maximum - minimum + 1) * rand () / (RAND_MAX + 1.0));
			//return LIB::random (maximum, minimum);
		}

		LIB::mathematics::numbers::natural randomizer::generate (void)
		{
			return generate (_max, _min);
			//return LIB::random (_max, _min);
		}

		// Getters:
		LIB::mathematics::numbers::natural randomizer::min (void)
		{
			return _min;
		}

		LIB::mathematics::numbers::natural randomizer::max (void)
		{
			return _max;
		}

		// Setters:
		LIB::mathematics::numbers::natural randomizer::min (const mathematics::numbers::natural & minimum)
		{
			LIB::mathematics::numbers::natural temp_val = _min;
			_min = minimum;

			return temp_val;
		}

		LIB::mathematics::numbers::natural randomizer::max (const mathematics::numbers::natural & maximum)
		{
			LIB::mathematics::numbers::natural temp_val = _max;
			_max = maximum;

			return temp_val;
		}

		//boost::any LIB::run ()
		//{
		//	return "something";
		//}
	}
}

//#endif UTILITIES
