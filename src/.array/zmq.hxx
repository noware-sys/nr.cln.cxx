#pragma once
//#ifndef __ARRAY
//#define __ARRAY

/*
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
*/

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

/*
#if !defined (LIB)
	#define LIB noware
#endif
*/

/*
// This library:
//#include "../default.h++"
//#include "../name.hxx"
//#include "../math.hxx"
//#include "serial.hdr.cxx"
#include "var.hxx"
#include "nr.hxx"
#include "../../db/sqlite.hxx"
*/

/*
// group set [a[ssociative][_]]array list
#ifndef NAME_A
	#define NAME_A list
#endif
*/

/*
namespace LIB
{
	//namespace container
	//{
	namespace array
	{
	//template <typename Value = any, Key = any>
	//struct Link
	//{
	//	Key key;
	//	Value value;
	//	Link * next;
	//	Link * previous;
	//};
*/
	//template <typename value, key> 
	template <typename value = noware::var, typename key = noware::var>
	class zmq
	{
		public:
			#include ".zmq/.hxx"
			
			zmq (void);
			~zmq (void);
			
			const bool finalize (void);
			const bool initialized (void) const;
			const bool initialize (void);
			
			// Returns the number of present elements.
			// Number of present elements (cardinality?):
			// magnitude size
			//const LIB::math::numbers::natural cardinality (void) const;
			//const LIB::math::numbers::natural count (void) const;
			//const LIB::math::numbers::natural magnitude (void) const;
			//const LIB::math::numbers::natural quantity (void) const;
			const LIB::nr size (void) const;
			//const LIB::nr magnitude (const noware::var &/* group*/) const;
			//LIB::math::numbers::integer minimum (void);	// .
			//LIB::math::numbers::integer maximum (void);	// .
			
			// Determines if the element exists named by the group and by the key provided.
			// present exist
			const bool exist (const key &/* group*/, const key &/* key*/, std::string &/* owner*/ = "") const; // Determines if the elements exist named by the keys provided.
			// Determines if the element exists named by the key provided, using the default group.
			const bool exist (const key &/* key*/) const; // Determines if the elements exist named by the keys provided.
			
			const std::string owner (const key &/* group*/, const key &/* key*/) const;
			const std::string owner (const key &/* key*/) const;
			
			// Determines if the container is full.
			const bool full (void) const;
			
			// Determines if the container is empty.
			const bool empty (void) const;
			
			const value & get (const key &/* group*/, const key &/* key*/);
			const value & get (const key &/* key*/);
			
			const bool set (const key &/* group*/, const key &/* key*/, const value &/* value*/);
			const bool set (const key &/* key*/, const value &/* value*/);
			
			// Remove all elements.
			const bool clear (void);
			// Remove one element.
			const bool remove (const key &/* group*/, const key &/* key*/);
			const bool remove (const key &/* key*/);
			//const bool rename (const key &/* Current name. */, const key &/* New name. */, const bool/* tolerant*/);	// Renames an existing element.
			//const bool rename (const key &/* Current name. */, const key &/* New name. */);	// Renames an existing element, using the default value for "tolerant".
			//static const std::string group_default;
		protected:
			noware::net::node node;
			//container content;
			//const bool multicast (const std::string &/* message*/, const std::string &/* group*//* = noware::array <value, key>::zmq::group_default*/) const;
			const bool add ();
			
	};
/*	
	//typedef array <> array;
	//}
	}
}

//#include "array.txx"
//#include "list.cxx"

//#endif
*/
	
	template <typename value = noware::var, typename key = noware::var>
	using zmq = zmq <>;
	
//#include "zmq.cxx"
