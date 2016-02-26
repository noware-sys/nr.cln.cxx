#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <iostream>
#include <fstream>

#include <boost/any.hpp>

#include "default.h++"
#include "mathematics.h++"

//#include "Any.h"

namespace LIB
{
	namespace tools
	{
		// Determines if a string is numeric (in base 10):
		bool is_numeric	(const std::string &);
		//long double (const std::string &);	// Converts a string to a number.

		//mathematics::number::integer	digits		(mathematics::number::integer);
		//mathematics::number::integer	digits		(mathematics::number::real);
		mathematics::numbers::natural	digits		(mathematics::numbers::natural);
		mathematics::numbers::natural	digits		(mathematics::numbers::integer);
		mathematics::numbers::natural	digits		(const mathematics::numbers::real &);
		mathematics::numbers::natural	integers	(const mathematics::numbers::real &);
		mathematics::numbers::natural	fractions	(mathematics::numbers::real);

		mathematics::numbers::real modulus (const mathematics::numbers::real &);
		mathematics::numbers::real complement (const mathematics::numbers::real &, const mathematics::numbers::natural & /* Radix. */ = 10);

		// Converts to string:
		std::string string	(const signed int &);
		std::string string	(const unsigned int &);
		std::string string	(const signed long int &);
		std::string string	(const unsigned long int &);
		std::string string	(const signed long long int &);
		std::string string	(const unsigned long long int &);
		std::string string	(const float &);
		std::string string	(const double &);
		std::string string	(const long double &);
		std::string string	(const char &);
		//std::string String	(const signed char);
		//std::string String	(const unsigned char);

		std::string	reverse		(const std::string &);
		std::string	toggle_case	(const std::string);
		char		toggle_case	(const char &);

		// Multiply a string:
		std::string multiply (const std::string &, const mathematics::numbers::real &);
		//stoa (const std::string); // std::string to ASCII.

		bool is_palindrome (const std::string &); // Determines if a string is a palindrome.
		//void randomize (void);
		//mathematics::numbers::natural random (const mathematics::numbers::natural & = RAND_MAX /* Maximum. */, const mathematics::numbers::natural & = 0 /* Minimum. */);
		void clear_screen (void);
		
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			void pause (const std::string & = "Press any key to continue...");
		#else
			void pause (const std::string & = "Press [Enter] to continue...");
		#endif
		//Call ();

		std::string lower (std::string);
		std::string upper (std::string);

		/*
			Pseudo-random number generator.
			Returns natural numbers from 0 to RAND_MAX, both by default.

			The only reason to encapsulate it into a class, is to automatically initialize the seed in the constructor.
		*/	
		class randomizer
		{
			protected:
				LIB::mathematics::numbers::natural _min, _max;

			public:
				randomizer (const mathematics::numbers::natural & = RAND_MAX /* Maximum. */, const mathematics::numbers::natural & = 0 /* Minimum. */);
				//~randomizer (void);

				LIB::mathematics::numbers::natural generate (const mathematics::numbers::natural & /*= RAND_MAX*/ /* Maximum. */, const mathematics::numbers::natural &/* = 0*/ /* Minimum. */);
				LIB::mathematics::numbers::natural generate (void);

				// Getters:
				LIB::mathematics::numbers::natural min (void);
				LIB::mathematics::numbers::natural max (void);

				// Setters (these return the currently/previously set value):
				LIB::mathematics::numbers::natural min (const mathematics::numbers::natural &);
				LIB::mathematics::numbers::natural max (const mathematics::numbers::natural &);
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

#endif
