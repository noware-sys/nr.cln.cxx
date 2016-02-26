#ifndef ARRAY
#define ARRAY

//#include <boost/any.hpp>
//#include <string>
//#include <iostream>
//#include <fstream>
#include <algorithm>
#include <omp.h>
#include <list>
//#include <unordered_map>

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

// Boost:
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

//#include <boost/array.hpp>
//#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

/*
// Boost serialization:
#include <boost/serialization/serialization.hpp>
*///#include <boost/serialization/split_member.hpp>	// For separating reading and writing.
/*#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/bitset.hpp>
#include <boost/serialization/hash_map.hpp>
#include <boost/serialization/hash_set.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/slist.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
*/

// This library:
#include "../default.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
#include "variable.h++"

#ifndef NAME_A
#define NAME_A array
#endif

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
					key k;
					//value * val;
					value v;
					//value v;
					
					package ();
					package (const key &, const value &);
					~ package ();
					
					bool operator == (const package &/* other*/) const;
					package & operator = (const package &/* other*/);
					
					std::string serialize (void) const;
					bool deserialize (const std::string &);
				protected:
					friend class boost::serialization::access;
					
					template <typename Archive>
					void serialize (Archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename Archive>
					//void save (Archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename Archive>
					//void load (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			};
			
			std::list <package> container;
			
			//std::unordered_map <key, value> container;
			
			typedef typename std::list <package>::iterator iterator;
			typedef typename std::list <package>::const_iterator iterator_const;
		protected:
			friend class boost::serialization::access;
			
			template <typename Archive>
			void serialize (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			//template <typename Archive>
			//void save (Archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
			
			//template <typename Archive>
			//void load (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			
			bool search (const key &, value *&) const;
			//bool search (const key &, value &) const;
			//value & create (const key &);	// Setter helper.
			
			// bool add (const key &);	// Add a new element.
			bool add (const key &, /*const */value *&);	// Add a new element.
			//bool add (const key &, /*const */value &);	// Add a new element.
			
			
			//iterator list_iterator;
			//typename std::list <package>::const_iterator list_iterator_constant;
			//bool free;
			//bool memory;	// If there is any more memory available for allocation. Determined after trying to add a new element.
			
			// Only allow modifications of keys from the inside:
			// key & current_key_internal (void);
			
			// Do not allow external modifications:
			//iterator begin (void);
			//iterator end (void);
		public:
			// Member functions:
			//NAME_A (void);
			NAME_A (const bool & = true /* Tolerant. */);
			NAME_A (const NAME_A &);
			~NAME_A (void);
			
			/*
				This parameter allows run-time configuration of the behaviour of this object.
				This behaviour applies during getter and rename operations.
				
				When false, trying to retrieve inexistent variables does not add a new, uninitialized variable by that key; a random value is returned. You have to add alements by calling "set ()".
				When true, trying to retrieve inexistent variables saves a new, uninitialized variable by that key, returning its uninitialized value.
				
				It also applies when trying to rename (when the new name exists).
				
				
				Otherwise put, this variable answers both following questions, but in different contexts:
				
				In "operator [] (...)":
				"Do you accept adding a new item if it does not exist?"
				
				In "rename (...)":
				"Do you accept to overwrite an existing value if the provided index exists?"
				
				The default is to be true.
			*/
			bool tolerant;
			
			/*const */value _value;	// To be returned when no element is found when searching for a particular key.
		//	//Value	operator [] (Key) const;	// Getter
		//	Value	operator [] (const Key);	// Getter
		//	//T &	operator [] (const T);		// Setter
			
			
			
			// Number of elements present (cardinality?):
			LIB::mathematics::numbers::natural size (void) const;	// Returns the number of elements present.
			//LIB::mathematics::numbers::integer minimum (void);	// .
			//LIB::mathematics::numbers::integer maximum (void);	// .
			
			// Iterators:
			//// Element access:
			// Element lookup:
			bool exists (const key &) const; // Determines if a element exists named by the key provided.
			//bool full (void) const;
			bool empty (void) const;	// Tests if the container is empty.
			bool operator == (const NAME_A <value, key> &) const;
			bool operator != (const NAME_A <value, key> &) const;
			
			// Modifiers:
			/*value &*/ bool	/*operator []*/ enqueue/*append*/ (/*void*/ const value &/*, key & = NULL*/);				// Setter: Append.
			value &	operator [] (const key &);				// Getter and Setter.
			/*const */value operator [] (const key &) const;				// Getter.
			//value &	operator [] (const key &, const bool & /* Tolerant. */);				// Getter and Setter.
			//value & set (const key &/*, const bool & = false*/);	// Add a new element.
			//value *& get (const key &, const bool & /* tolerant */= false);	// Returns an element.
			value & get (const key &);	// Returns an element to be potentially modified.
			/*const */value get (const key &) const;	// Returns an element.
			//bool set (const key &, const value *&, const bool & /* tolerant */= true);	// Adds a new element.
			
			//bool set (const key &, const value *&);	// Adds a new element.
			bool set (const key &, const value &);	// Adds a new element.
			
			bool clear (void);	// Remove all the elements from the container.
			bool unset (const key &);	// Removes the element specified by that key, if it exists.
			bool rename (const key &/* Current name. */, const key &/* New name. */, const bool &/* tolerant*/);	// Renames an existing element.
			bool rename (const key &/* Current name. */, const key &/* New name. */);	// Renames an existing element, using the default value for "tolerant".
			NAME_A <value, key> & operator = (const NAME_A <value, key> &);
			//void Set (LIB::Mathematics::Number::Natural, bool = false);
			
			// iterator & current_package (void);
			// key /* Do not allow modifications of keys from the exterior: &. */ current_key (void);
			// value & current_value (void);
			
			//bool advance (void);
			//bool regress (void);
			// bool next (void);
			// bool previous (void);
			
			// bool reset (void);
			//bool end (void);
			
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
			iterator_const begin (void) const;
			iterator_const end (void) const;
			// Allow external modifications:
			iterator begin (void);
			iterator end (void);
			
			// Prefix:
			//NAME_A <value, key> & operator ++ (void);
			//NAME_A <value, key> & operator -- (void);
			
			// Postfix / Suffix:
			//NAME_A <value, key> operator ++ (signed int);
			//NAME_A <value, key> operator -- (signed int);
			
			//signed int		operator	*	(void);
			//key & operator * (void) const;
			
			std::string serialize (void) const;
			bool deserialize (const std::string &);
	};
}

#include "array.t++"

#endif
