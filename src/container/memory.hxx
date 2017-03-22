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

// Intel Treading Building Blocks:
//#include <tbb/tbb.h>

// Boost:
//#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
//#include <boost/thread/detail/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/serialization/list.hpp>
//#include <boost/serialization/string.hpp>
//#include <boost/serialization/version.hpp>
//#include <boost/serialization/split_member.hpp>
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

#include "../value.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
#include "array.h++"
#include "variable.h++"
//#include "../container/entity.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
//#include "../cluster/machine.h++"
//#include "../machine/resource.h++"
#include "database/sql.h++"

//typedef std::string value, key;

//#include "../../container/entity-pre.h++"

namespace LIB
{
	namespace container
	{
		//namespace database
		//{
		class memory
		{
			public:
				typedef LIB::container::NAME_V key, value;
				//typedef container value;

				//#include "entity.h++"
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
						iterator (const iterator &);
						//~iterator (void);
						
						const iterator & operator = (const iterator &);
						const bool operator == (const iterator &) const;
						const bool operator != (const iterator &) const;
						const iterator & operator ++ (void);
						const iterator & operator -- (void);
						const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::container & operator * (void) const;
						
						//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> list;
						//bool set;	// If "this -> list" is already populated/set.
						
						typename LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::iterator iter;
				};
				/*
				// Relations used when dealing with the self object.
				enum relation
				{
					self,	// Note that this value also considers the entity.
					sibbling,
					descendant,
					ancestor,
					// Special cases:
					root,
					other
				};
				*/
				//// This returns the relationship of the other object: what does the other represent to this?
				//// If another object than self is passed to this function, "relation::other" is returned.
				//const relation relate (const memory &/* other*/) const;
				
				static const std::string default_database_name;
				
				static const key default_group;
				//static const key default_previous_group = 0;
				//static const key default_name = "";
				static const value default_value;
				
				friend class boost::serialization::access;
				
				//template <typename archive>
				//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				template <typename archive>
				void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
				
				template <typename archive>
				void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				BOOST_SERIALIZATION_SPLIT_MEMBER ();
				
				//memory (const LIB::database::sqlite *& = NULL, const LIB::memory::key &/* current_group*/ = default_group, const LIB::memory::key &/* previous_group*/ = default_previous_group, const LIB::memory::key &/* previous_name*/ = default_name, const std::string &/* _database_name*/ = default_database_name);
				//memory (void);
				memory (const std::string & = default_database_name);
				//memory (const memory &/* other*/, const std::string &/* _database_name*/ = default_database_name);
				~memory (void);

				//const bool query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> &/* arguments*/ = NULL);
				
				// const bool operator == (const memory &) const;
				// const bool operator != (const memory &) const;
				//const bool operator == (const value &) const;
				//const bool operator != (const value &) const;
				// const memory & operator = (const memory &);
				//const memory & operator = (const value &);

				const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> list (void) const;

				//const bool set (const key &/* name*/, const value &);
				// Set a value.
				//const bool set (const key &/* group*/, const key &/* name*/, const key &/* new group*/, const key &/* new name*/, const value &/* name: type*/ = 0, const value &/* content: type*/ = 0, const value *&/* value*/ = NULL);
				const bool set (const key &/* name*/, const LIB::container::NAME_A <LIB::container::NAME_V, value> &/* values*/, const key &/* group*/ = default_group);
				//const bool set (const LIB::container::NAME_A <LIB::container::NAME_V, value> &/* new values*/);
				const bool set (const key &/* name*/, const key &/* group*/ = default_group);	// Uses default values.
				//const bool set_value (const key &/* group*/, const key &/* name*/, const value &/* name: type*/ = 0, const value &/* content: type*/ = 0, const value *&/* value*/ = & default_value);
				// const bool set/*_literal*/ (const memory &/* other*/);
				//// Set a undefined grouped value.
				//const bool set_group (void);
				// Set a defined, named grouped value.
				//const bool set_group (const key &/* name*//* = default_value*/);
				//const bool set_group (const key &/* name*//* = default_value*/, const key &);

				// Get the columns.
				const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> get (const key &/* name*/, const key &/* group*/ = default_group) const;
				//// Get the value from the named group.
				//memory get (const key &/* name*/) const;
				//const memory & get (const key &/* name*/) const;
				
				// Getter.
				//operator const value/* &*/ (void) const;
				//operator const LIB::NAME_A <value, key>/* &*/ (void) const;
				
				// Getter and setter.
				//memory operator [] (const key &/* name*/);
				// Getter.
				//const memory & operator [] (const key &/* name*/) const;
				
				//const bool content_clear_literal (const key &/* name*/);
				//const bool content_clear_group (const key &/* name*/ = default_name);
				
				const LIB::mathematics::numbers::natural size (void) const;
				const LIB::mathematics::numbers::natural size_group (const key &/* group*/ = default_group) const;
				const bool clear (void);
				const bool clear_group (const key &/* group*/ = default_group);
				const bool empty (void) const;
				const bool empty_group (const key &/* group*/ = default_group) const;
				const bool full (void) const;
				//const bool exist (const key &/* name*/) const;
				const bool exists (const key &/* name*/, const key &/* group*/ = default_group) const;
				//const bool rename (const key &/* old_name*/, const key &/* new_name*/, const key &/* old_group*/ = default_group, const key &/* new_group*/ = default_group) const;
				const bool unset (const key &/* name*/, const key &/* group*/ = default_group);
				
				//const bool is_name_group (const key &/* name*/, const key &/* group*/ = default_group) const;
				const bool is_name_literal (const key &/* name*/, const key &/* group*/ = default_group) const;
				//const bool is_content_group (const key &/* name*/, const key &/* group*/ = default_group) const;
				const bool is_content_literal (const key &/* name*/, const key &/* group*/ = default_group) const;
				
				// These use "add ()":
				//const memory operator + (const value &) const;
				// const memory operator + (const memory &) const;
				//const memory & operator += (const value &);
				// const memory & operator += (const memory &);
				
				const bool add (const key &, const value & = default_value);
				// This gives back the key which was used.
				const bool add (key &/* used_group*/, const key &/* name*/, const value &/* content*/ = default_value);
				//// This overwrites any existing keys with the provided values.
				//const bool add (const LIB::container::NAME_A <value, key> &);
				// const bool add (const memory &);
				
				// These are used as "add", as "enqueue", and as "push".
				const bool append (const key &, const value & = default_value);
				// Gives back the key that was used.
				const bool append (key &, const key &, const value & = default_value);
				//// Uses new keys for any existing ones rather than the provided values.
				//const bool append (const NAME_A <value, key> &);
				// const bool append (const memory &);
				
				const LIB::mathematics::numbers::integer key_group_integral_min (void) const;
				const LIB::mathematics::numbers::integer key_group_integral_max (void) const;
				const LIB::mathematics::numbers::integer key_name_integral_min (const LIB::container::memory::key &/* group*/ = default_group) const;
				const LIB::mathematics::numbers::integer key_name_integral_max (const LIB::container::memory::key &/* group*/ = default_group) const;
				
				// Queue functionality:
				const bool enqueue (key &, const key &, const value & = default_value);
				const bool enqueue (const key &, const value & = default_value);
				const bool dequeue (void);
				
				// Stack functionality:
				const bool push (key &, const key &, const value & = default_value);
				const bool push (const key &, const value & = default_value);
				const bool pop (void);
				//const key top_key (void) const;
				//const value top (void) const;
				//const key bottom_key (void) const;
				//const value bottom (void) const;
				
				// Common functionality to queue and to stack.
				//const key front_key (void) const;
				const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> beginning (void) const;
				//const key rear_key (void) const;
				const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> ending (void) const;
				
				//// Is the type of the key numeric?
				//const bool integral_key (void) const;
				// Return the next available unique value in the sequence (ID).
				const mathematics::numbers::natural sequence_group_next_available (void) const;
				// Return the next greatest unique value in the sequence (ID).
				const mathematics::numbers::natural sequence_group_next (void) const;
				const mathematics::numbers::natural sequence_name_next_available (const LIB::container::memory::key &/* group*/ = default_group) const;
				const mathematics::numbers::natural sequence_name_next (const LIB::container::memory::key &/* group*/ = default_group) const;
				
				// For range-based (for) loop:
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
				
				const bool refresh_list (void);
				
				// Get the container.
				LIB::container::database::sql::sqlite & database (void);
				
				const std::string & database_name (void) const;
			protected:
				//const bool initialize (const LIB::database::sqlite *& = NULL, const LIB::memory::key &/* current_group*/ = default_group, const LIB::memory::key &/* previous_group*/ = default_previous_group, const LIB::memory::key &/* previous_name*/ = default_name, const std::string &/* _database_name*/ = default_database_name);
				const bool initialize (const std::string &/* _database_name*/ = default_database_name);
				const bool _set (const key &, const key &, const value & = default_value);
				const bool finalize (void);
				
				// The container.
				LIB::container::db::sqlite * db;
				
				//// The group in the table which is represented by the current instance of this object.
				//key group;
				//// The group and the name from the previous entity which were used to get to this entity.
				//key previous_name;
				//key previous_group;
				
				// The database which is used.
				std::string _database_name;
				
				LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> _list;
		};
		//}
	}
	
	//typedef container/*::database*/::memory memory;
}
