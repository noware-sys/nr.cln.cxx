#ifndef ARRAY
#define ARRAY

//#include <boost/any.hpp>
//#include <string>
//#include <iostream>
//#include <fstream>
#include <algorithm>
#include <omp.h>
#include <list>

//#include <algorithm>
//#include <cstdlib>
//#include <cmath>
//#include <deque>
//#include <iostream>
//#include <list>
//#include <set>
//#include <map>
//#include <boost/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>

//#include <boost/array.hpp>
//#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include "../default.hpp"
//#include "../Utilities.h"
#include "variable.hpp"
#include "../mathematics.hpp"

#ifndef NAME_A
#define NAME_A array
#endif NAME_A

namespace LIB
{
	//template <typename Value = NAME_V, Key = NAME_V>
	//struct Link
	//{
	//	Key key;
	//	Value value;
	//	Link * next;
	//	Link * previous;
	//};
	//template <typename value, key> 
	template <typename value = NAME_V, typename key = NAME_V> 
	class NAME_A
	{
		public:
			class package
			{
				public:
					key _key;
					value _value;
			}
			
			std::list <key> container;

		protected:
			//friend class boost::serialization::access;

			//template <typename Archive>
			//void serialize (Archive & /* Archive (stream). */, const unsigned int /* Version. */);

			bool search (const key &, value &) const;
			value & create (const key &);	// Setter helper.

			//bool free;
			//bool memory;	// If there is any more memory available for allocation. Determined after trying to add a new element.
		public:
			//NAME_A (void);
			NAME_A (const bool = false);
			NAME_A (/*const */NAME_A &);
			~NAME_A (void);
			
			/*
				This parameter allows run-time configuration of the behaviour of this object.
				This behavious applies only during a getter operation.

				When strict, trying to retrieve inexistent variables does not add a new, uninitialized variable by that key; a random value is returned.
				When loose, trying to retrieve inexistent variables saves a new, uninitialized variable by that key, returning its uninitialized value.

				//The default is to be strict/true.
				The default is to be loose/false.
			*/
			bool strict;

		//	//Value	operator [] (Key) const;	// Getter
		//	Value	operator [] (const Key);	// Getter
		//	//T &	operator [] (const T);		// Setter

			value &	operator [] (const key &);				// Getter and Setter.
			
			NAME_A <value, key> & operator = (NAME_A <value, key> &);
			bool operator == (const NAME_A &);
			bool operator != (const NAME_A &);

			void clear (void);
			
			LIB::mathematics::numbers::natural size (void) const;	// Returns the number of elements present.
			//LIB::mathematics::numbers::integer minimum (void);	// .
			//LIB::mathematics::numbers::integer maximum (void);	// .
			bool unset (const key &);	// Removes an existing element.
			bool rename (const key &/* Current Name */, const key &/* New Name */);	// Renames an existing element.
			bool exists (const key &) const; // Determines if a element exists named by the key provided.
			bool empty (void) const;
			bool full (void) const;
			//void Set (LIB::Mathematics::Number::Natural, bool = false);
			
			// Get the N'th element from the array, regardless of the type of the key.
			// Indexing starts at 1.
			//key & get_key (const LIB::mathematics::numbers::natural &);
			//value & get_value (const LIB::mathematics::numbers::natural &);

			// Functionality common to stack and to queue:
			//key & current_key (void) const;
			//value & current (void) const;
			
			// Queue functionality:
			//bool enqueue (const value);
			//bool dequeue (void);
			//key front_key (void) const;
			//value front (void) const;
			
			// Stack functionality:
			//bool push (const value);
			//bool pop (void);
			//key top_key (void) const;
			//value top (void) const;
			
			
			// For range-based (for) looping:
			/*
				Next:		++
				Previous:	--
			*/
			
			//void begin (void);
			//void end (void);			
			
			// Prefix:
			//NAME_A <value, key> & operator ++ (void);
			//NAME_A <value, key> & operator -- (void);
			
			// Postfix / Suffix:
			//NAME_A <value, key> operator ++ (signed int);
			//NAME_A <value, key> operator -- (signed int);
			
			//signed int		operator	*	(void);
			//key & operator * (void) const;
	};
}

#include "array.tpp"

#endif ARRAY
