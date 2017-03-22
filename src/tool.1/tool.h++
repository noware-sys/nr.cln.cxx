#pragma once
//#ifndef __TOOLS
//#define __TOOLS

#include <string>
#include <iostream>
#include <fstream>

//#include <boost/any.hpp>
#include <boost/random/random_device.hpp>

#include "value.h++"
#include "mathematics.h++"

//#include "Any.h"

namespace LIB
{
	namespace tool
	{
		static boost::random::random_device random_number_generator;
		
		// Determines if a string is numeric (in base 10):
		const bool is_numeric	(const std::string &);
		const bool is_number	(const std::string &);
		//long double (const std::string &);	// Converts a string to a number.

		//mathematics::number::integer	digits		(mathematics::number::integer);
		//mathematics::number::integer	digits		(mathematics::number::real);
		// mathematics::numbers::natural	digits		(mathematics::numbers::natural);
		const LIB::mathematics::numbers::natural	digits		(const LIB::mathematics::numbers::integer &);
		const LIB::mathematics::numbers::natural	digits		(const LIB::mathematics::numbers::real &);
		//const LIB::mathematics::numbers::natural	integers	(const mathematics::numbers::real &);
		const LIB::mathematics::numbers::natural	fractions	(const LIB::mathematics::numbers::real &);
		
		const LIB::mathematics::numbers::integer	integers	(const /*mathematics::numbers::real*/cln::cl_R &);
		
		const LIB::mathematics::numbers::real modulus (const LIB::mathematics::numbers::real &);
		const LIB::mathematics::numbers::real complement (const LIB::mathematics::numbers::real &, const LIB::mathematics::numbers::natural & /* Radix. */ = 10);
		const LIB::mathematics::numbers::real exponentiation (const LIB::mathematics::numbers::real &, LIB::mathematics::numbers::natural);
		
		// Converts to string:
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
		const std::string string	(const LIB::mathematics::numbers::integer &);
		const std::string string	(const LIB::mathematics::numbers::real &);
		const std::string string	(const LIB::mathematics::number &);
		//std::string String	(const signed char);
		//std::string String	(const unsigned char);

		const std::string	reverse		(const std::string &);
		const std::string	toggle_case	(const std::string);
		const char		toggle_case	(const char &);

		// Multiply a string:
		const std::string multiply (const std::string &, const LIB::mathematics::numbers::real &);
		//stoa (const std::string); // std::string to ASCII.

		const bool is_palindrome (const std::string &); // Determines if a string is a palindrome.
		//void randomize (void);
		//mathematics::numbers::natural random (const mathematics::numbers::natural & = RAND_MAX /* Maximum. */, const mathematics::numbers::natural & = 0 /* Minimum. */);
		void clear_screen (void);
		
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			void pause (const std::string & = "Press any key to continue . . . ");
		#else
			void pause (const std::string & = "Press [Enter] to continue . . . ");
		#endif
		//Call ();
			
		const std::string lower (std::string);
		const std::string upper (std::string);
		
		//void sleep (const mathematics::numbers::real &/* seconds*/);
		
		const LIB::mathematics::numbers::real random (const LIB::mathematics::numbers::natural & /* Maximum. */, const LIB::mathematics::numbers::natural & = 0 /* Minimum. */);
		const LIB::mathematics::numbers::natural random (void);
		
		/*
			Pseudo-random number generator.
			Returns natural numbers from 0 to RAND_MAX, both by default.

			The only reason to encapsulate it into a class, is to automatically initialize the seed in the constructor.
		*/	
		class randomizer
		{
			protected:
				unsigned long long int _min, _max;
				
			public:
				randomizer (const unsigned long long int & = RAND_MAX /* Maximum. */, const unsigned long long int & = 0 /* Minimum. */);
				//~randomizer (void);
				
				const unsigned long long int generate (const unsigned long long int & = RAND_MAX /* Maximum. */, const unsigned long long int & = 0 /* Minimum. */);
				//unsigned long long int generate (void);
				
				// Getters:
				const unsigned long long int min (void);
				const unsigned long long int max (void);
				
				// Setters (these return the currently/previously set value):
				const unsigned long long int min (const unsigned long long int &);
				const unsigned long long int max (const unsigned long long int &);
		};
		
		//boost::any run ();
		
		// For range-based for loops:
		class iterator
		{
			public:
				//virtual iterator begin (void) const = 0;
				//virtual iterator end (void) const = 0;
				virtual void * operator * (void) const = 0;
				virtual bool operator != (const iterator & other) = 0;
				virtual const iterator & operator ++ (void) = 0;
		};
	}
}

//#include "utilities.tpp"

//#endif
