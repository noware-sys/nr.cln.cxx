#pragma once
//#ifndef __ARRAY
//#define __ARRAY

//#include <boost/any.hpp>
//#include <string>
//#include <iostream>
#include <ostream>
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
//#include "../default.h++"
#include "../name.h++"
#include "../math.h++"
#include "../serial.h++"
#include "any.h++"

// group set [a[ssociative][_]]array
#ifndef NAME_A
	#define NAME_A array
#endif

namespace LIB
{
	namespace container
	{
	//template <typename Value = any, Key = any>
	//struct Link
	//{
	//	Key key;
	//	Value value;
	//	Link * next;
	//	Link * previous;
	//};
	//template <typename value, key> 
	template <typename value = noware::container::any, typename key = noware::container::any>
	class NAME_A
	{
		public:
			class container
			{
				public:
					key k;
					//value * val;
					value v;
					//value v;
					
					container (void);
					container (const NAME_A <value, key>::container &);
					container (const key &, const value &);
					~container (void);
					
					const bool operator == (const container &/* other*/) const;
					const bool operator == (const value &/* other*/) const;
					const container & operator = (const container &/* other*/);
					const value & operator = (const value &/* other*/);
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
					
					//operator const std::string (void) const;
					//const NAME_A <value, key> & operator = (const std::string &);
					//const container & operator = (const std::string &);
					operator const value (void) const;
					//const value & operator = (const value &);
					
					friend class boost::serialization::access;
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename Archive>
					//void save (Archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename Archive>
					//void load (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			};
		protected:
			std::list <container> content;
			//std::list <container *> content_pointer;
			
			//std::unordered_map <key, value> container;
		public:
			typedef typename std::list <container>::iterator iterator;
			//typedef typename std::list <container>::const_iterator const_iterator;
			
			
			friend class boost::serialization::access;
			
			template <typename archive>
			void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			//template <typename archive>
			//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
			
			//template <typename archive>
			//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			
		protected:
			const bool search (const key &, value *&) const;
			const bool search_key (const key &, key *&) const;
			//bool search (const key &, value &) const;
			//value & create (const key &);	// Setter helper.
			
			// bool add (const key &);	// Add a new element.
			const bool insert (const key &, /*const */value *&);	// Add a new element.
			//bool add (const key &, /*const */value &);	// Add a new element.
			
			
			//iterator list_iterator;
			//typename std::list <container>::const_iterator list_iterator_constant;
			//bool free;
			//bool memory;	// If there is any more memory available for allocation. Determined after trying to add a new element.
			
			// Only allow modifications of keys from the inside:
			// key & current_key_internal (void);
			
			// Do not allow external modifications:
			//iterator begin (void);
			//iterator end (void);
			
			static /*const */value _value;	// To be returned when no element is found when searching for a particular key.
			static /*const */key _k;	// To be returned when no element is found when searching for a particular key.
		public:
			// Member functions:
			NAME_A (void);
			//NAME_A (const bool = true /* Tolerant. */);
			NAME_A (const NAME_A <value, key> &);	// List.
			//NAME_A (const value &);		// Single value.
			NAME_A (const std::string &);	// List.
			//NAME_A (const std::initializer_list &);
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
			
		//	//Value	operator [] (Key) const;	// Getter
		//	Value	operator [] (const Key);	// Getter
		//	//T &	operator [] (const T);		// Setter
			
			
			
			// Returns the number of present elements.
			// Number of present elements (cardinality?):
			//const LIB::math::numbers::natural cardinality (void) const;
			//const LIB::math::numbers::natural count (void) const;
			//const LIB::math::numbers::natural maginitude (void) const;
			//const LIB::math::numbers::natural quantity (void) const;
			const LIB::math::numbers::natural size (void) const;
			//LIB::math::numbers::integer minimum (void);	// .
			//LIB::math::numbers::integer maximum (void);	// .
			
			// Iterators:
			//// Element access:
			// Element lookup:
			const bool exists (const key &) const; // Determines if the element exists named by the key provided.
			const bool exist (const key &) const; // Determines if the elements exist named by the keys provided.
			//// Tests if the container is full.
			const bool full (void) const;
			//// Tests if the container is empty.
			const bool empty (void) const;
			const bool operator == (const NAME_A <value, key> &) const;
			const bool operator != (const NAME_A <value, key> &) const;
			
			// These use "add ()":
			const NAME_A <value, key>	operator + (const value &) const;
			const NAME_A <value, key>	operator + (const NAME_A <value, key> &) const;
			//const NAME_A <value, key>	operator - (const value &) const;
			const NAME_A <value, key>	operator - (const NAME_A <value, key> &) const;
			
			// Modifiers.
			
			const bool add (const value &);
			// This gives back the key that was used.
			const bool add (const value &, key &);
			// This overwrites any existing keys with the provided values.
			const bool add (const NAME_A <value, key> &);
			
			// These are used as "add", as "enqueue" and as "push".
			const bool append (const value &);
			// Gives back the key that was used.
			const bool append (const value &, key &);
			// Uses new keys for any existing ones rather than the provided values.
			const bool append (const NAME_A <value, key> &);
			
			// These use "add ()":
			// Setter (append) (one value).
			/*value &*/ const NAME_A <value, key> &	/*operator []*/operator +=/*enqueue*//*add*//*append*/ (/*void*/ const value &/*, key & = NULL*/);
			// Setter (append) (another array (of the same type)).
			const NAME_A <value, key> &	operator += (const NAME_A <value, key> &);
			//const NAME_A <value, key> &	operator -= (const value &);
			const NAME_A <value, key> &	operator -= (const NAME_A <value, key> &);
			
			//const bool	add (const NAME_A <value, key> &);				// Setter (append): another array (of the same type).
			//value &	operator [] (void);				// Setter (Append).
			value &	operator [] (const key &);				// Getter and Setter.
			const value & operator [] (const key &) const;				// Getter.
			//value &	operator [] (const key &, const bool /* Tolerant. */);				// Getter and Setter.
			//value & set (const key &/*, const bool = false*/);	// Add a new element.
			//value *& get (const key &, const bool /* tolerant */= false);	// Returns an element.
			value & get (const key &);	// Returns an element to be potentially modified.
			const value & get (const key &) const;	// Returns an element.
			const key & get_key (const key &) const;	// Returns an element.
			//bool set (const key &, const value *&, const bool /* tolerant */= true);	// Adds a new element.
			
			// Get all the matching keys.
			//const NAME_A <value, key> get_all (const value &) const;
			
			//bool set (const key &, const value *&);	// Adds a new element.
			const bool set (const key &, const value &);	// Adds a new element.
			
			const bool clear (void);	// Remove all the elements from the container.
			const bool unset (const key &);	// Removes the element specified by that key, if it exists.
			const bool rename (const key &/* Current name. */, const key &/* New name. */, const bool/* tolerant*/);	// Renames an existing element.
			const bool rename (const key &/* Current name. */, const key &/* New name. */);	// Renames an existing element, using the default value for "tolerant".
			const NAME_A <value, key> & operator = (const NAME_A <value, key> &);
			//friend const NAME_A <value, key> & operator = (const NAME_A <value, key> &, const NAME_A <value, key> &);
			//friend const NAME_A & operator = (const NAME_A &, const NAME_A &);
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
			//key & get_key (const LIB::math::numbers::natural &);
			//value & get_value (const LIB::math::numbers::natural &);
			
			// Common functionality to the stack and to the queue:
			//key & current_key (void) const;
			//value & current (void) const;
			// "append/add ()" replaces "enqueue ()" and "push ()".
			//const bool append (const value &);
			//const bool append (const value &, key &);
			
			const key key_numeric_min (void) const;
			const key key_numeric_max (void) const;
			
			// Queue functionality:
			const bool enqueue (const value &);
			const bool enqueue (const value &, key &);
			const bool dequeue (void);
			//const key front_key (void) const;
			const container & beginning (void)/* const*/;
			//const key rear_key (void) const;
			const container & ending (void)/* const*/;
			
			// Stack functionality:
			const bool push (const value &);
			const bool push (const value &, key &);
			const bool pop (void);
			//const key top_key (void) const;
			//const value top (void) const;
			//const key bottom_key (void) const;
			//const value bottom (void) const;
			
			// Is the type of the key numeric?
			const bool key_numeric (void) const;
			// Return the next available unique value in the sequence (ID).
			const key sequence_next_available (void) const;
			// Return the next greatest unique value in the sequence (ID).
			const key sequence_next (void) const;
			
			// For range-based (for) looping:
			/*
				Next:		++
				Previous:	--
			*/
			
			//void begin (void);
			//void end (void);
			//const iterator begin (void) const;
			//const iterator end (void) const;
			//const const_iterator cbegin (void) const;
			//const const_iterator cend (void) const;
			// Allow external modifications:
			const iterator begin (void);
			const iterator end (void);
			
			// Prefix:
			//NAME_A <value, key> & operator ++ (void);
			//NAME_A <value, key> & operator -- (void);
			
			// Postfix / Suffix:
			//NAME_A <value, key> operator ++ (signed int);
			//NAME_A <value, key> operator -- (signed int);
			
			//signed int		operator	*	(void);
			//key & operator * (void) const;
			
			const std::string serialize (void) const;
			const bool deserialize (const std::string &);
			
			// Deserialize
			operator const std::string (void) const;
			// Serialize
			const NAME_A <value, key> & operator = (const std::string &);
			//inline friend const NAME_A <value, key> & operator = (const std::string &);
			
			//friend std::ostream & operator << (std::ostream &, const LIB::NAME_A <value, key> &, const std::string &/* indentation*/ = "")/* const*/;
		//	friend std::ostream & operator << (std::ostream &, const LIB::container::NAME_A <value, key> &)/* const*/;
			std::ostream & operator << (std::ostream &) const;
			//friend std::ostream & operator << (std::ostream & os, const LIB::NAME_A <LIB::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> & val);
			//friend	::std::istream &	operator	>>	(::std::istream &, LIB::NAME_A &);
	
	};
	}
	
	//template <typename value, typename key>
	//using NAME_A = container::NAME_A <value, key>;
}

#include "array.t++"

//#endif
