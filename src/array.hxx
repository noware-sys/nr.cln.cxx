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

/*
#if (!defined (LIB))
	#define LIB noware
#endif
*/

#include <zmq.hpp>
#include <zhelpers.hxx>

// This library:
//#include "../default.h++"
//#include "../name.hxx"
//#include "../math.hxx"
//#include "serial.hxx"
//#include "var.hxx"
//#include "nr.hxx"
#include "contnr/array.hxx"

#include ".array/.incl.hxx"


// group set [a[ssociative][_]]array list
//#ifndef NAME_A
//	#define NAME_A array
//#endif

namespace noware
{
	//namespace container
	//{
	//template <typename Value = any, Key = any>
	//struct Link
	//{
	//	Key key;
	//	Value value;
	//	Link * next;
	//	Link * previous;
	//};
	
	/*
		Limitations:
		
		key == key
	*/
	//template <typename value, key> 
	template <typename value_t = var, typename key_t = var>
	class array
		//: public mach::dev
		//: public net::node
		: public contnr::array <value_t, key_t>
	{
		public:
			#include ".array/.hxx"
		protected:
			//
			// ZeroMQ functionality
			//
			//std::string group;
			
			//const bool/* success*/ respond (const std::string &/* message*/, const zyre_event_t */* (zyre) event*/);
			//const bool/* success*/ search (std::string &/* result*/, const std::string &/* message/expression*/);// const
			//const bool/* success*/ search_local (std::string &/* result*/, const std::string &/* message/expression*/);// const
			//const std::string/* result*/ aggregate (const std::string &/* result*/, nr &/* responses_count*//* number of peers who answered*/, const std::string &/* response*/, //const std::string &/* expression*/);
			
			
			zmq::context_t * ctx;
			zmq::socket_t * sock_rx;
			zmq::socket_t * sock_tx_all;
			zmq::socket_t * sock_tx_any;
		protected:
			//
			// For array functionality
			//
		//	const bool _search_local (const key_t &, value_t &) const;
			//const bool add (const key_t &, value_t &) const;
			//const bool search_key (const key &, key *&) const;
			unsigned short int nodes_count;
			node * _node;
		public:
			static const std::string srv_id;
			
			array (void);
			~array (void);
			
			virtual const noware::nr size (void) const;
			//virtual const bool/* success*/ exist (const key_t &/* key*/) const;
			//virtual const bool/* success*/ is_full (void) const;
			//virtual const bool/* success*/ is_empty (void) const;
			virtual const bool/* success*/ set (const key_t &/* key*/, const value_t &/* value*/);
			virtual const bool/* success*/ get (const key_t &/* key*/, value_t &/* value*/) const;
			////const key & get_key (const key &) const;
			virtual const bool/* success*/ clear (void);
			virtual const bool/* success*/ remove (const key_t &/* key*/);
			virtual const bool/* success*/ rename (const key_t &/* old_k*/, const key_t &/* new_k*/);
			//virtual value_t &/* value*/ operator [] (const key_t &/* key*/);
			//virtual value_t &/* value*/ operator [] (const std::nullptr_t &/* null*/);
	};
	
	// http://stackoverflow.com/questions/6907194/how-to-typedef-a-template-class
	
	//typedef array <> array;
	//}
	
	//template <typename value = noware::var, typename key = noware::var>
	//using NAME_A = container::NAME_A <value, key>;
	
	template <typename value_t = var, typename key_t = var>
	using array = array <value_t, key_t>;
}

//#include "array.txx"
//#include "list.cxx"
#include "array.cxx"

//#endif
