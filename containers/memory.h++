#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#define OTL_ODBC
//#define ODBCVER 0x0250
//#define OTL_ODBC_UNIX // uncomment this line if UnixODBC is used
//#include <otlv4.h> // include the OTL 4.0 header file

#include <cstdarg>
#include <string>
//#include <map>
#include <mutex>

//#include <stdio.h>
//#include <sqlite3.h>

// Intel Treading Bulding Blocks:
//#include <tbb/tbb.h>

// Boost:
//#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
//#include <boost/thread/detail/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

/*
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/Socket.h>
#include <Poco/Data/DataException.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Util/TimerTaskAdapter.h>
*/

#include "../../default.h++"
#include "../../mathematics.h++"
#include "../../containers/array.h++"
#include "../../containers/variable.h++"
#include "../../containers/entity.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
#include "../../cluster/machine.h++"
#include "../resource.h++"
#include "../containers/database/sqlite.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	class memory
	{
		public:
			/*
			class container
			{
				public:
					container (void);
					container (const container &);
					~container (void);
					
					bool reference;
					LIB::NAME_V value;
			};
			*/
			
			class iterator
			{
				public:
					iterator (void);
					//iterator (const iterator &);
					//~iterator (void);
					
					//const interator & operator = (const iterator &);
					const bool operator == (const iterator &) const;
					const bool operator != (const iterator &) const;
					const iterator & operator ++ (void);
					const iterator & operator -- (void);
					LIB::memory operator * (void) const;
					
					LIB::NAME_A <LIB::memory, LIB::memory::key> list;
					bool set;
					
					typename LIB::NAME_A <LIB::memory, LIB::memory::key>::iterator iter;
			};
			
			
			friend class boost::serialization::access;
			
			//template <typename archive>
			//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			template <typename archive>
			void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
			
			template <typename archive>
			void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
			
			
			typedef LIB::NAME_V key, value;
			//typedef container value;
			
			memory (const LIB::database::sqlite *& = NULL, const LIB::memory::key &/* current_group*/ = default_group, const LIB::memory::key &/* previous_group*/ = default_previous_group, const LIB::memory::key &/* previous_name*/ = default_name);
			memory (const memory &);
			~memory (void);
			
			//const bool query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> &/* arguments*/ = NULL);
			
			const bool operator == (const memory &) const;
			const bool operator != (const memory &) const;
			const bool operator == (const value &) const;
			const bool operator != (const value &) const;
			const memory & operator = (const memory &);
			const memory & operator = (const value &);
			
			const memory list (void) const;
			
			//const bool set (const key &/* name*/, const value &);
			// Set a literal value.
			const bool set/*_literal*/ (const value &/* value*//* = default_value*/);
			const bool set/*_literal*/ (const LIB::memory &/* other*/);
			// Set a undefined grouped value.
			const bool set_group (void);
			// Set a defined, named grouped value.
			const bool set_group (const key &/* name*//* = default_value*/);
			const bool set_group (const key &/* name*//* = default_value*/, const key &);
			
			// Gets the literal value.
			value get (void) const;
			// Gets the value from the named group.
			memory get (const key &/* name*/) const;
			//const memory & get (const key &/* name*/) const;
			
			operator const value/* &*/ (void) const;
			//operator const LIB::NAME_A <value, key>/* &*/ (void) const;
			
			// Getter and setter.
			memory operator [] (const key &/* name*/);
			// Getter.
			//const memory & operator [] (const key &/* name*/) const;
			
			//const bool content_clear_literal (const key &/* name*/);
			//const bool content_clear_group (const key &/* name*/ = default_name);
			
			const LIB::mathematics::numbers::natural size (const bool &/* recursive*/ = false, const bool &/* inclusive*/ = true) const;
			const bool clear (void) const;
			const bool empty (void) const;
			const bool full (void) const;
			const bool exist (const key &/* name*/) const;
			const bool exists (const key &/* name*/) const;
			const bool rename (const key &/* old_name*/, const key &/* new_name*/, const key &/* old_group*/ = default_group, const key &/* new_group*/ = default_group) const;
			const bool unset (const key &/* name*/, const key &/* group*/ = default_group);
			
			const bool is_group (void) const;
			const bool is_literal (void) const;
			
			// These use "add ()":
			const memory operator + (const value &) const;
			const memory operator + (const memory &) const;
			const memory & operator += (const value &);
			const memory & operator += (const memory &);
			
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
			
			const key least_numeric_key (void) const;
			const key greatest_numeric_key (void) const;
			
			// Queue functionality:
			const bool enqueue (const value &);
			const bool enqueue (const value &, key &);
			const bool dequeue (void);
			//const key front_key (void) const;
			const memory beginning (void)/* const*/;
			//const key rear_key (void) const;
			const memory ending (void)/* const*/;
			
			// Stack functionality:
			const bool push (const value &);
			const bool push (const value &, key &);
			const bool pop (void);
			//const key top_key (void) const;
			//const value top (void) const;
			//const key bottom_key (void) const;
			//const value bottom (void) const;
			
			//// Is the type of the key numeric?
			//const bool numeric_key (void) const;
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
			const iterator begin (void) const;
			const iterator end (void) const;
			//const const_iterator & begin (void) const;
			//const const_iterator & end (void) const;
			// Allow external modifications:
			//const iterator begin (void);
			//const iterator end (void);
			
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
			
			//// Serialize.
			//operator const std::string (void) const;
			//// Deserialize.
			//const memory & operator = (const std::string &);
			LIB::database::sqlite & database (void);
			
			const static key default_group = "";
			const static key default_previous_group = 0;
			const static key default_name = "";
			const static value default_value = "";
		protected:
			LIB::database::sqlite * db;
			
			// The group in the table that an instance of this object represents.
			key group;
			// The group and the name from the previous entity which were used to get to this entity.
			key previous_name;
			key previous_group;
	};
}
