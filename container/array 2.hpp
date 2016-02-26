#ifndef ARRAY
#define ARRAY

//#include <boost/any.hpp>
//#include <string>
//#include <iostream>
//#include <fstream>
#include <algorithm>
#include <omp.h>

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
//#include "variable.hpp"
#include "any.hpp"
#include "../mathematics.hpp"

#ifndef NAME_A2
#define NAME_A2 array2
#endif NAME_A2

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

	//template <typename value = NAME_V, typename key = NAME_V> 
	class NAME_A2
	{
		protected:
			typedef LIB::NAME_NE key, value;

		public:
			struct link
			{
				key _key;
				value _value;

				link * next, * previous;
			};

		protected:
			typedef LIB::NAME_NE key, value;

			LIB::mathematics::numbers::natural _size;

			link * values;
		//	Value values;
			link * current_index; // Used for iterating (by Next (), by Previous (), and by Reset ()).
		//	bool New (const Key, const Value); // Allocates a new element.
			bool search (const key &, link *&) const;
			value & New (const key &);	// Setter helper.

			//bool free;
			//bool memory;	// If there is any more memory available for allocation. Determined after trying to add a new element.
		public:
			//NAME_A (void);
			NAME_A2 (const bool = true);
			NAME_A2 (/*const */NAME_A2 &);
			~NAME_A2 (void);
			
			/*
				This parameter allows run-time configuration of the behaviour of this object.
				This behavious applies only during a getter operation.

				When strict, trying to retrieve inexistent variables does not add a new, uninitialized variable by that key; a random value is returned.
				When loose, trying to retrieve inexistent variables saves a new, uninitialized variable by that key, returning its uninitialized value.

				The default is to be strict/true.
			*/
			bool strict;

		//	//Value	operator [] (Key) const;	// Getter
		//	Value	operator [] (const Key);	// Getter
		//	//T &	operator [] (const T);		// Setter

			// Get the value of a key:
			//Value & operator [] (const Key &);			// Getter & Setter
			const value & operator [] (const key &) const;	// Getter
			value &	operator [] (const key &);				// Setter
			
			// Get the key of a value:
			//const key & operator [] (const value &) const;	// Getter

			NAME_A2 & operator = (NAME_A2 &);
			bool operator == (const NAME_A2 &);
			bool operator != (const NAME_A2 &);
			void clear (void);
			LIB::mathematics::numbers::natural size (void) const;	// Returns the number of elements present.
			LIB::mathematics::numbers::integer minimum (void);	// .
			LIB::mathematics::numbers::integer maximum (void);	// .
			bool Delete (const key &);	// Removes an existing element.
			bool rename (const key &/* Current Name */, const key &/* New Name */);	// Renames an existing element.
			bool exists (const key &) const; // Determines if a element exists named by the key provided.
			bool empty (void) const;
			bool full (void) const;
			//void Set (LIB::Mathematics::Number::Natural, bool = false);
			
			// Functionality common to stack and to queue:
			key & current_key (void) const;
			value & current (void) const;
			
			// Queue functionality:
			bool enqueue (const value);
			bool dequeue (void);
			key front_key (void) const;
			value front (void) const;
			
			// Stack functionality:
			bool push (const value);
			bool pop (void);
			key top_key (void) const;
			value top (void) const;
			
			
			// For range-based (for) looping:
			/*
				Next:		++
				Previous:	--
			*/
			
			void begin (void);
			void end (void);			
			
			// Prefix:
			NAME_A2 & operator ++ (void);
			NAME_A2 & operator -- (void);
			
			// Postfix / Suffix:
			NAME_A2 operator ++ (signed int);
			NAME_A2 operator -- (signed int);
			
			//signed int		operator	*	(void);
			key & operator * (void) const;
	};
}

//#include "array.tpp"

#endif ARRAY
