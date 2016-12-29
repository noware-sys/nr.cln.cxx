#pragma once
//#ifndef __TOOLS
//#define __TOOLS

#include <string>
#include <iostream>
#include <fstream>

//#include <boost/any.hpp>
#include <boost/random/random_device.hpp>

//#include "container/content/value.h++"
//#include "math.h++"

//#include "Any.h"

namespace noware
{
	namespace tool
	{
		static boost::random::random_device random_number_generator;
		
		// Determines if a string is numeric (in base 10):
		const bool is_numeric	(const std::string &);
		const bool is_numeric	(const char &);
		const bool is_numeric	(const unsigned char &);
		const bool is_numeric	(const signed char &);
		const bool is_number	(const std::string &);
		//long double (const std::string &);	// Converts a string to a number.
		/*
		//math::number::integer	digits		(math::number::integer);
		//math::number::integer	digits		(math::number::real);
		// math::numbers::natural	digits		(math::numbers::natural);
		const noware::math::numbers::natural	digits		(const noware::math::numbers::integer &);
		const noware::math::numbers::natural	digits		(const noware::math::numbers::real &);
		//const noware::math::numbers::natural	integers	(const math::numbers::real &);
		const noware::math::numbers::natural	fractions	(const noware::math::numbers::real &);
		
		const noware::math::numbers::integer	integers	(const /*math::numbers::real* /cln::cl_R &);
		
		const noware::math::numbers::real modulus (const noware::math::numbers::real &);
		const noware::math::numbers::real complement (const noware::math::numbers::real &, const noware::math::numbers::natural & /* Radix. * / = 10);
		const noware::math::numbers::real exponentiation (const noware::math::numbers::real &, noware::math::numbers::natural);
		*/
		//math::number::integer	digits		(math::number::integer);
		//math::number::integer	digits		(math::number::real);
		// math::numbers::natural	digits		(math::numbers::natural);
		const noware::number	digits		(const noware::number &);
		const noware::number	digits		(const noware::number &);
		//const noware::number	integers	(const number &);
		const noware::number	fractions	(const noware::number &);
		
		const noware::number	integers	(const /*number::real*/cln::cl_R &);
		
		const noware::number modulus (const noware::number &);
		const noware::number complement (const noware::number &, const noware::number & /* Radix. */ = 10);
		const noware::number exponentiation (const noware::number &, noware::number);
		/*
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
		const std::string string	(const char *&);
		const std::string string	(const noware::math::numbers::integer &);
		const std::string string	(const noware::math::numbers::real &);
		const std::string string	(const noware::math::number &);
		//std::string String	(const signed char);
		//std::string String	(const unsigned char);
		*/
		
		const std::string	reverse		(const std::string &);
		const std::string	toggle_case	(const std::string);
		const char		toggle_case	(const char &);
		
		// Multiply a string:
		const std::string multiply (const std::string &, const noware::math::numbers::real &);
		//stoa (const std::string); // std::string to ASCII.

		const bool is_palindrome (const std::string &); // Determines if a string is a palindrome.
		//void randomize (void);
		//math::numbers::natural random (const math::numbers::natural & = RAND_MAX /* Maximum. */, const math::numbers::natural & = 0 /* Minimum. */);
		void clear_screen (void);
		
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			void pause (const std::string & = "Press any key to continue . . . ");
		#else
			void pause (const std::string & = "Press [Enter] to continue . . . ");
		#endif
		//Call ();
			
		const std::string lower (std::string);
		const std::string upper (std::string);
		
		//void sleep (const math::numbers::real &/* seconds*/);
		
		const noware::math::numbers::real random (const noware::math::numbers::natural & /* Maximum. */, const noware::math::numbers::natural & = 0 /* Minimum. */);
		const noware::math::numbers::natural random (void);
		
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
		
	/*	// For range-based for loops:
		class iterator
		{
			public:
				//virtual iterator begin (void) const = 0;
				//virtual iterator end (void) const = 0;
				virtual void * operator * (void) const = 0;
				virtual bool operator != (const iterator & other) = 0;
				virtual const iterator & operator ++ (void) = 0;
		};
	*/}
}

//#include "utilities.tpp"

//#endif

