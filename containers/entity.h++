#pragma once
//#ifndef __ENTITY
//#define __ENTITY

#include <string>

//#include <boost/any.hpp>

#include "../default.h++"
#include "../serialization.h++"
#include "array.h++"
#include "variable.h++"
//#include "entity_container.h++"

//#include "../machine/resources/memory.h++"

#include "../mathematics.h++"
//#include "../machine/resource.h++"

#ifndef NTT
	#define NTT entity
#endif
//#include "entity-pre.h++"

namespace LIB
{
	/*
	namespace machine
	{
		namespace resources
		{
			//typedef std::string key, value;
			
			//class processor;
			//class memory;
			
			//template <typename Value = std::string, Key = std::string>
			//class memory : public resource
			class memory
			{
				public:
					class keys;
					
					typedef keys key;
			};
		}
	}
	*/
	//namespace machine
	//{
		//class NTT;
		
//		class container
//		{
//			public:
//				container (void);
//				~ container (void);
//				
//				//std::string text;
//				//bool reference;
//				LIB::NAME_V literal;
//				
//				LIB::array <LIB::NTT, LIB::NAME_V> group;
//		};
		
		template <typename value = LIB::NAME_V, typename key = LIB::NAME_V>
		class NTT
		{
			public:
				//friend class LIB::machine::resources::memory::key;
				//friend class LIB::machine::resources::memory::NTT;
				
				class container
				{
					public:
						//friend class LIB::machine::resources::memory::NTT::container;
						
						//typedef LIB::NAME_V value, key;
						//typedef LIB::NAME_V key;
						
						container (void);
						container (const container &);
						container (const LIB::NTT <value, key> &);
						container (const LIB::NAME_A <value, key> &);
						container (const value &);
						~ container (void);
						
						container & operator = (const container &);
						container & operator = (const value &);
						container & operator = (const LIB::NTT <value, key> &);
						container & operator = (const LIB::NAME_A <value, key> &);
						
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
						
						//template <typename archive>
						//void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
						
						//template <typename archive>
						//void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
						
						enum /*class */type
						{
							literal,
							group
						};
						
						const type get_type (void) const;
						// Determine if this container is empty.
						const bool empty (void) const;
						// Determine if this container is full.
						const bool full (void) const;
						
						//std::string text;
						//bool reference;
						const bool operator == (const container &) const;
						const bool operator != (const container &) const;
						const bool operator == (const value &) const;
						const bool operator != (const value &) const;
						const bool operator == (const LIB::NTT <value, key> &) const;
						const bool operator != (const LIB::NTT <value, key> &) const;
						const bool operator == (const LIB::NAME_A <value, key> &) const;
						const bool operator != (const LIB::NAME_A <value, key> &) const;
						
						const std::string serialize (void) const;
						const bool deserialize (const std::string &);
						
						friend class NTT;
					protected:
						type t;
						
						value lit;
						
						LIB::NAME_A <NTT <value, key> *, key> grp;
						
						const bool content_clear_literal (void);
						const bool content_clear_group (void);
				};
				
				
				class iterator
				{
					public:
						iterator (void);
						iterator (const iterator &);
						
						const bool operator == (const iterator &) const;
						const bool operator != (const iterator &) const;
						const iterator & operator ++ (void);
						NTT <value, key> & operator * (void) const;
						
						//NTT <value, key> ** reference;
						
						typename LIB::NAME_A <NTT <value, key> *, key>::iterator iter;
						//NTT <value, key> * parent;
				};
				
				class const_iterator
				{
					public:
						const_iterator (void);
						const_iterator (const const_iterator &);
						
						const bool operator == (const const_iterator &) const;
						const bool operator != (const const_iterator &) const;
						const const_iterator & operator ++ (void);
						NTT <value, key> & operator * (void) const;
						
						//NTT <value, key> ** reference;
						
						typename LIB::NAME_A <NTT <value, key> *, key>::const_iterator iter;
						//NTT <value, key> * parent;
				};
				
				
				//class const_iterator
				//{};
				
				//typedef typename NTT <value, key>::iterator iterator;
				//typedef typename NTT <value, key>::const_iterator iterator_const;
			protected:
				container content;
				
				//key * k;
			public:
				NTT (void);
				NTT (const NTT <value, key> &);
				NTT (const LIB::NAME_A <value, key> &);
				NTT (const value &);
				//NTT (const machine::resources::memory::key &);
				
				const NTT <value, key> & operator = (const NTT <value, key> &);
				const NTT <value, key> & operator = (const LIB::NAME_A <value, key> &);
				const NTT <value, key> & operator = (const value &);
				//const NTT <value, key> & operator = (const machine::resources::memory::key &);
				
				friend class boost::serialization::access;
				
				template <typename archive>
				void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				//const iterator_const & begin (void) const;
				//const iterator_const & end (void) const;
				
				const iterator begin (void);
				const iterator end (void);
				const const_iterator begin (void) const;
				const const_iterator end (void) const;
				
				//const LIB::NAME_V & operator = (const LIB::NAME_V);
				//operator = (const std::string &);
				// const LIB::NAME_A <NTT *, container::key> & operator = (const LIB::NAME_A <NTT *, container::key> &);
				NTT <value, key> & operator [] (const key &);
				const NTT <value, key> & operator [] (const key &) const;
				
				const bool unset (const key &);
				const bool exists (const key &, const bool &/* recursive*/ = false) const;
				const bool exist (const key &, const bool &/* recursive*/ = false) const;
				const bool clear (void);
				const bool empty (void) const;
				const bool full (void) const;
				const LIB::mathematics::numbers::natural size (const bool &/* recursive*/ = false, const bool &/* grouped/inclusive (consider a group as an item, in addition to its children) (only considered if recursive == true)*/ = false) const;
				const bool rename (const key &/* old*/, const key &/* new*/);
				
				//const key * & get_key (void);
				
				operator value & (void);
				operator const value & (void) const;
				const value & operator * (void);
				const value & operator * (void) const;
				const value & operator -> (void);
				const value & operator -> (void) const;
				const value & operator () (void);
				const value & operator () (void) const;
				const value & value (void);
				const value & value (void) const;
				const value & get_value (void);
				const value & get_value (void) const;
				
				const bool operator == (const NTT <value, key> &) const;
				const bool operator != (const NTT <value, key> &) const;
				const bool operator == (const value &) const;
				const bool operator != (const value &) const;
				const bool operator == (const LIB::NAME_A <value, key> &) const;
				const bool operator != (const LIB::NAME_A <value, key> &) const;
				//const bool operator == (const machine::resources::memory::key &);
				//const bool operator != (const machine::resources::memory::key &);
				//const value & operator ++ (void);
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				const bool is_group (void) const;
				const bool is_literal (void) const;
		};
	//}
}

//#include "../machine/resources/memory.h++"

#include "entity.t++"

//#endif
