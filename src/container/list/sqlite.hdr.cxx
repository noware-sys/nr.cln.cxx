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

#if !defined (LIB)
	#define LIB noware
#endif

// This library:
//#include "../default.h++"
//#include "../name.hxx"
//#include "../math.hxx"
//#include "serial.hdr.cxx"
#include "var.hdr.cxx"
#include "number.hdr.cxx"
#include "../../db/sqlite.hdr.cxx"

// group set [a[ssociative][_]]array list
#ifndef NAME_A
	#define NAME_A list
#endif

namespace LIB
{
	namespace container
	{
	namespace list
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
	//template <typename value = noware::var, typename key = noware::var>
	class sqlite
	{
		public:
		protected:
			noware::db::sqlite data;
			//std::list <container *> content_pointer;
			
			//std::unordered_map <key, value> container;
		public:
			//typedef typename std::list <container>::iterator iterator;
			//typedef typename std::list <container>::const_iterator const_iterator;
			
			
			//friend class boost::serialization::access;
			
			//template <typename archive>
			//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			//template <typename archive>
			//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
			
			//template <typename archive>
			//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			
		protected:
			//const bool search (const key &, value *&) const;
			//const bool search_key (const key &, key *&) const;
			//bool search (const key &, value &) const;
			//value & create (const key &);	// Setter helper.
			
			// bool add (const key &);	// Add a new element.
			//const bool insert (const key &, /*const */value *&);	// Add a new element.
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
			
			//static /*const */value _value;	// To be returned when no element is found when searching for a particular key.
			//static /*const */key _k;	// To be returned when no element is found when searching for a particular key.
		public:
			// Member functions:
			sqlite (void);
			//NAME_A (const bool = true /* Tolerant. */);
			//NAME_A (const NAME_A <value, key> &);	// List.
			//NAME_A (const value &);		// Single value.
			//NAME_A (const std::string &);	// List.
			//NAME_A (const std::initializer_list &);
			~sqlite (void);
			
			static const noware::var group_default;
			static const std::string query_sql_initial_table;
			static const std::string query_sql_initial_index;
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
			//bool tolerant;
			
		//	//Value	operator [] (Key) const;	// Getter
		//	Value	operator [] (const Key);	// Getter
		//	//T &	operator [] (const T);		// Setter
			
			const bool finalize (void);
			const bool initialized (void) const;
			const bool initialize (const std::string &/* database*/ = ":memory:");
			
			// Returns the number of present elements.
			// Number of present elements (cardinality?):
			//const LIB::math::numbers::natural cardinality (void) const;
			//const LIB::math::numbers::natural count (void) const;
			//const LIB::math::numbers::natural magnitude (void) const;
			//const LIB::math::numbers::natural quantity (void) const;
			const LIB::number magnitude (void) const;
			//const LIB::number magnitude (const noware::var &/* group*/) const;
			//LIB::math::numbers::integer minimum (void);	// .
			//LIB::math::numbers::integer maximum (void);	// .
			
			// Determines if the element exists named by the group and by the key provided.
			const bool exist (const noware::var &/* group*/, const noware::var &/* key*/) const; // Determines if the elements exist named by the keys provided.
			// Determines if the element exists named by the key provided, using the default group.
			const bool exist (const noware::var &/* key*/) const; // Determines if the elements exist named by the keys provided.
			
			// Determines if the container is full.
			const bool full (void) const;
			
			// Determines if the container is empty.
			const bool empty (void) const;
			
			const noware::var get (const noware::var &/* group*/, const noware::var &/* key*/);
			const noware::var get (const noware::var &/* key*/);
			
			const bool set (const noware::var &/* group*/, const noware::var &/* key*/, const noware::var &/* value*/);
			const bool set (const noware::var &/* key*/, const noware::var &/* value*/);
			
				// Removes all the elements from the container.
			const bool reset (void);
			const bool remove (const noware::var &/* group*/, const noware::var &/* key*/);
			const bool remove (const noware::var &/* key*/);
			//const bool rename (const key &/* Current name. */, const key &/* New name. */, const bool/* tolerant*/);	// Renames an existing element.
			//const bool rename (const key &/* Current name. */, const key &/* New name. */);	// Renames an existing element, using the default value for "tolerant".
	};
	
	//typedef array <> array;
	}
	}
	
	//template <typename value, typename key>
	//using NAME_A = container::NAME_A <value, key>;
}

//#include "array.txx"
//#include "list.cxx"

//#endif
