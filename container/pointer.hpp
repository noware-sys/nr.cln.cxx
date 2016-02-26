#ifndef POINTER
#define POINTER

//#include <string>
//#include <iostream>
//#include <fstream>

#include "../default.hpp"
#include "../mathematics.hpp"

namespace LIB
{
	template <typename type> 
	class pointer
	{
		protected:
			type							*	container;		// The raw pointer.
			mathmetics::numbers::natural	*	references;		// References counter.
		public:
			// Default constructor.
			pointer (void);

			// Copy constructor for raw types.
			pointer (const type &);

			// Copy constructor for raw pointers.
			pointer (const type *&);

			// Copy constructor.
			pointer (const pointer &);

			// Default destructor.
			~ pointer (void);

			operator type (void) const throw (void);
			operator type * (void) const throw (void);

			type & operator * (void) const throw (void);
			type *& operator -> (void) const throw (void);
			
			pointer <type> & operator = (const type &);
			pointer <type> & operator = (const type *&);
			pointer <type> & operator = (const pointer <type> &);

			bool operator == (const type &) const;
			bool operator == (const type *&) const;
			bool operator == (const pointer <type> &) const;
	};
}

#include "pointer.tpp"

#endif POINTER
