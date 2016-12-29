//#ifndef UTILITIES
//#define UTILITIES
#include <sstream>
#include <ctime>
#include <random>
#include <unistd.h>	// For read (,,) in tool::pause ().
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

//#include "name.h++"
#include "tool.hxx"
//#include "containers/variable.h++"

namespace noware
{
	namespace tool
	{
		const bool is_numeric (const std::string & value)
		{
			if (value.empty ())
				return false;

			/*unsigned int*/noware::math::numbers::natural length = value.length ();
			bool decimal_found = false;
			bool sign_found = false;
			bool digit_found = false;

			//if (s[0] != '+' || s[0] != '-' || !isdigit(s[0]))
				//return false;

			for
			(
				///*unsigned long long int*/math::numbers::natural i = 0;
				unsigned long long int i = 0;
				i < length;
				++ i
			)
			{
				//if (isdigit (value [i]))
				//{
				//	/*continue*/;
				//}
				//else 
					if (value [i] == '.'/* && ! decimal_found*/)
				{
					if (decimal_found)
						return false;
					
					decimal_found = true;
				}
				else if ((value [i] == '+' || value [i] == '-')/* && ! sign_found*/)
				{
					sign_found = true;
				}
				else if (! isdigit (value [i]))
				{
					return false;
				}
				else
				{
					digit_found = true;
				}
			}
			
			return digit_found;
		}
		
		const bool is_number (const std::string & value)
		{
			return is_numeric (value);
		}
		
		const bool is_numeric (const char & value)
		{
			switch (other)
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					return true;
				default:
					return false;
			}
		}
		
		const bool is_numeric (const unsigned char & value)
		{
			switch (other)
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					return true;
				default:
					return false;
			}
		}
		
		const bool is_numeric (const signed char & value)
		{
			switch (other)
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					return true;
				default:
					return false;
			}
		}
		
		/*
		math::numbers::natural	digits		(math::numbers::natural n)
		{
			if (n == 0)
				return 1;

			math::numbers::natural digits = 0;

			//std::cout << n << std::endl;

			while (n != 0)
			{
				n /= 10;
				++ digits;
			}

			return digits;
		}
		*/
		
		const noware::math::numbers::natural	digits		(const noware::math::numbers::integer & n)
		{
			if (n == 0)
				return 1;	// Needed for complement ().

			noware::math::numbers::natural digits = 0;

			//std::cout << n << std::endl;

			while (n != 0)
			{
				// Finish implementation! : n = n / 10
				//n /= (math::numbers::integer) 10;
				// n = n / (math::numbers::real) 10;
				++ digits;
			}

			return digits;
		}
		
		const noware::math::numbers::natural	digits		(const noware::math::numbers::real & n)
		{
			if (n == 0)
				return 1;	// Needed for complement ().
			
			//std::cout << n << std::endl;
			
			/*
			if (n < 0)	// Allow the complete range of integer numbers and of natural numbers.
				return digits ((math::numbers::integer) n) + fractions (n);
			else
				return digits ((math::numbers::natural) n) + fractions (n);
			return digits (n) + fractions (n);
			*/
			
			
			noware::math::numbers::natural digits = 0;
			
			//std::cout << n << std::endl;
			
			// Convert the number to a string and count the characters, except the fraction delimiter.
			std::string no = noware::tool::string (n);
			unsigned long long int i = 0, count = no.size ();
			
			for (; i < count; ++ i)
			{
				//n /= 10;
				//n /= 10.0;
				//n /= (math::numbers::integer) 10;
				//n = n / 10;
				switch (no [i])
				{
					case '.':
					case ',':
					case ':':
					case '+':
					case '-':
					case '_':
					case '|':
					case ' ':
						break;
					default:
						++ digits;
				}
				
				
				//++ digits;
			}
			 
			return digits;
			
		}
		
		/*
		math::numbers::natural	integers	(math::numbers::real n)
		{
			//return digits ((math::numbers::integer) n);
			
			if (n == 0)
				return 1;	// Needed for complement ().
			
			//std::cout << n << std::endl;
			
			/ *
			if (n < 0)	// Allow the complete range of integer numbers and of natural numbers.
				return digits ((math::numbers::integer) n) + fractions (n);
			else
				return digits ((math::numbers::natural) n) + fractions (n);
			return digits (n) + fractions (n);
			* /
			
			
			math::numbers::natural digits = 0;
			
			//std::cout << n << std::endl;
			
			while (n > 0)
			{
				//n /= 10;
				//n /= (math::numbers::integer) 10;
				n = n / 10;
				++ digits;
			}
			
			return digits;
		}
		*/
		
		// TODO: Implement (incomplete!).
		const noware::math::numbers::integer	integers	(const /*math::numbers::real*/cln::cl_R & n)
		{
			//if (n == 0)
			//	return 0;	// Needed for complement ().
			
			//std::cout << n << std::endl;
			
			/*
			if (n < 0)	// Allow the complete range of integer numbers and of natural numbers.
				return digits ((math::numbers::integer) n) + fractions (n);
			else
				return digits ((math::numbers::natural) n) + fractions (n);
			return digits (n) + fractions (n);
			*/
			
			
			noware::math::numbers::integer integer = 0;
			
			//std::cout << n << std::endl;
			
			while (n > 0)
			{
				//n /= 10;
				//n /= (math::numbers::integer) 10;
				//n = n / 10;
				
				//integer = ;
				//++ digits;
			}
			
			return integer;
		}
		
		// TODO: Implement (incomplete!).
		const noware::math::numbers::natural	fractions	(const noware::math::numbers::real & n /* example: 3.2548 */)
		{
			if (n == 0)
				return 1;	// Needed for complement ().
			
			noware::math::numbers::natural digits = 0;
			// n = n - (math::numbers::integer) n;	// 0.2548
			
			while (n > 0)
			{
				// n *= 10;	// 2.548
				// n = n - (math::numbers::integer) n;	//	0.548
				
				++ digits;
			}
			
			return digits;	// 4
		}
		
		const noware::math::numbers::real modulus (const noware::math::numbers::real & value)
		{
			return value < 0 ? -value : value;
		}
		
		const noware::math::numbers::real complement (const noware::math::numbers::real & value, const noware::math::numbers::natural & radix)
		{
			/*
				The radix complement of an n digit, positive number y, in radix b is
				b ^ n - y
			 
			*/
			
			//math::numbers::real val = 
			// return std::pow ((long double) radix, (long double) digits ((math::numbers::real) modulus (value))) - value;
			return 0;
			//return val;
		}
		
		const noware::math::numbers::real exponentiation (const noware::math::numbers::real & base, noware::math::numbers::natural exponent)
		{
			noware::math::numbers::real result = 1;
			
			if (exponent > 0)
			{
				while (exponent > 0)
				{
					result *= base;
					
					-- exponent;
				}
			}
			else if (exponent < 0)
			{
				while (exponent < 0)
				{
					result *= base;
					
					++ exponent;
				}
				
				result = 1 / result;
			}
			//if (exponent == 0)
			else
			{
				return 1;
			}
			
			return result;
		}
		
		const std::string string (const signed short int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned short int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed long long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned long long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const float & value)
		{
			return string ((double) value);
		}
		
		const std::string string (const double & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const long double & value)
		{
			std::stringstream ss;
			ss << value;
			return ss.str ();
		}
		
		const std::string string (const noware::math::numbers::integer & value)
		{
			std::stringstream ss;
			ss << value;
			return ss.str ();
		}
	/*	
		const std::string string (const noware::math::numbers::real & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str();
			return ss.str ();
		}
	*/	
		const std::string string (const noware::math::number & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str();
			return ss.str ();
		}
		
		const std::string string (const char & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		
		// Just use std::string (value)
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
		
		const std::string string (const char *& value)
		{
			std::string txt = value;
			
			return txt;
		}
		
		const std::string reverse (const std::string & input)
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

		const char toggle_case (const char & input)
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
		
		const std::string toggle_case (std::string value)
		{
			//math::numbers::natural	index,
			unsigned long long int			index,
											length = value.length ();
			
			for (index = 0; index < length; ++ index)
			{
				value [index] = toggle_case (value [index]);
			}
			
			return value;
		}
		
		const std::string multiply (const std::string & input, const noware::math::numbers::real & length)
		{
			std::string output = "";
			//math::numbers::natural	i,
			unsigned long long int			i,
											length_i,
											remainder;

			// length_i = length;	// get the floor (integer) of the input's length;
			// remainder = input.length () * (length - length_i /* decimal part of length */);	// get the number of characters to append.

			for (i = 0; i < length_i; ++ i)
			{
				output += input;
			}

			for (/*math::numbers::natural*/unsigned long long int j = 0; j < remainder; ++ j)
			{
				output += input [j];
			}

			return output;
		}

		const bool is_palindrome (const std::string & s)
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

		unsigned long long int random (const math::numbers::natural & max, const math::numbers::natural & min)
		{
			// incomplete.

			// initialize random seed:
			//srand ((unsigned) time (null));

			return min + math::numbers::natural ((max - min + 1) * rand () / (RAND_MAX + 1.0));
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
			//std::string input;
			
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
				
				
				signed long int i;
				char c;
				do
				{
					i = read (0, &c, 1);
				}
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

		const std::string lower (std::string value)
		{
			unsigned long long int length = value.length ();

			for (unsigned long long int i = 0; i < length; ++ i)
			{
				value [i] = ::tolower (value [i]);
			}

			return value;
		}

		const std::string upper (std::string value)
		{
			unsigned long long int length = value.length ();

			for (unsigned long long int i = 0; i < length; ++ i)
			{
				value [i] = ::toupper (value [i]);
			}

			return value;
		}
		
		/*
		void sleep (const math::numbers::real & seconds)
		{
			
			boost::int64_t nanoseconds = ;
			
			timer.expires_from_now (boost::posix_time::nanoseconds (nanoseconds));
			
			io.run ();
		}
		*/
		
		const noware::math::numbers::real random (const noware::math::numbers::natural & maximum, const noware::math::numbers::natural & minimum)
		{
			//boost::random::random_device generator;
//			noware::math::numbers::real numerator, denominator, quotient, preparation, preparation_2, preparation_3, result;
//			
//			numerator = random_number_generator ();
//			denominator = random_number_generator.max ();
//			denominator =  + 1;
//			quotient = numerator / denominator;
//			
//			preparation_3 = maximum;
//			preparation_3 = preparation_3 - minimum;
//			preparation_3 = preparation_3 + 1;
//			
//			preparation_2 = preparation_3;
//			preparation_2 = preparation_2 * ;
//			
//			//preparation = minimum;
//			//preparation = preparation + preparation_2;
			
			//result = minimum + preparation_2;
			
			//return minimum + ((maximum - minimum + 1) * random_number_generator () / (random_number_generator.max () + 1.0));
			
			return minimum + ((maximum - minimum + 1) * (noware::math::numbers::real) random_number_generator () / ((noware::math::numbers::real) random_number_generator.max () + 1));
			//return minimum + ((maximum - minimum + 1) * random_number_generator () / (random_number_generator.max () + 1));
			
			//return minimum + ((prep 3) * random_number_generator () / (random_number_generator.max () + 1.0));
			//return  + ((maximum - minimum + 1) * quotient);
			//return result;
		}
		
		const noware::math::numbers::natural random (void)
		{
			//boost::random::random_device generator;
			
			return random_number_generator ();
		}
		
		randomizer::randomizer (const unsigned long long int & maximum, const unsigned long long int & minimum)
		{
			_min = minimum;
			_max = maximum;

			//srand ((unsigned) time (NULL));
			//srand ((unsigned long long int) time (NULL));
			srand (time (NULL));
		}

		const unsigned long long int randomizer::generate (const unsigned long long int & maximum, const unsigned long long int & minimum)
		{
			//return minimum + math::numbers::natural ((maximum - minimum + 1) * rand () / (RAND_MAX + 1.0));
			return minimum + ((maximum - minimum + 1) * rand () / (RAND_MAX + 1.0));
		}
		
		/*
		unsigned long long int randomizer::generate (void)
		{
			return generate (_max, _min);
			//return noware::random (_max, _min);
		}
		*/
		
		// Getters:
		const unsigned long long int randomizer::min (void)
		{
			return _min;
		}
		
		const unsigned long long int randomizer::max (void)
		{
			return _max;
		}
		
		// Setters:
		const unsigned long long int randomizer::min (const unsigned long long int & minimum)
		{
			unsigned long long int temp_val = _min;
			_min = minimum;
			
			return temp_val;
		}
		
		const unsigned long long int randomizer::max (const unsigned long long int & maximum)
		{
			unsigned long long int temp_val = _max;
			_max = maximum;

			return temp_val;
		}

		//boost::any noware::run ()
		//{
		//	return "something";
		//}
	}
}

//#endif UTILITIES
