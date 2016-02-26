#pragma once
//#ifndef __ENTITY
//#define __ENTITY

#include <string>

//#include <boost/any.hpp>

#include "content/value.h++"
#include "../serial.h++"
#include "array.h++"
#include "any.h++"
//#include "entity_container.h++"

//#include "../machine/resources/memory.h++"

#include "../math.h++"
//#include "../machine/resource.h++"

// group [multi]set r[ecursive[_]]array m[ulti[_]]array matrix obj[ect]
#ifndef NTT
	//#define NTT entity
	#define NTT object
	//#define NTT matrix
#endif
//#include "entity-pre.h++"

namespace LIB
{
	namespace container
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
//				LIB::container::any literal;
//				
//				LIB::array <LIB::container::NTT, LIB::container::any> group;
//		};
		
		template <typename value = LIB::container::any, typename key = LIB::container::any>
		class NTT
		{
			public:
				//friend class LIB::machine::resources::memory::key;
				//friend class LIB::machine::resources::memory::NTT;
				
				class container
				{
					public:
						//friend class LIB::machine::resources::memory::NTT::container;
						
						//typedef LIB::container::any value, key;
						//typedef LIB::container::any key;
						
						container (void);
						container (const container &);
						container (const LIB::container::NTT <value, key> &);
						container (const LIB::container::NAME_A <value, key> &);
						container (const value &);
						~container (void);
						
						container & operator = (const container &);
						container & operator = (const value &);
						container & operator = (const LIB::container::NTT <value, key> &);
						container & operator = (const LIB::container::NAME_A <value, key> &);
						
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
						const bool operator == (const LIB::container::NTT <value, key> &) const;
						const bool operator != (const LIB::container::NTT <value, key> &) const;
						const bool operator == (const LIB::container::NAME_A <value, key> &) const;
						const bool operator != (const LIB::container::NAME_A <value, key> &) const;
						
						const std::string serialize (void) const;
						const bool deserialize (const std::string &);
						
						friend class NTT;
					protected:
						type t;
						
						value lit;
						
						LIB::container::NAME_A <NTT <value, key> *, key> grp;
						
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
						//const iterator & operator -- (void);
						NTT <value, key> & operator * (void) const;
						//LIB::container::NAME_A <NTT <value, key> *, key> & operator * (void) const;
						
						const key & k (void) const;
						//NTT <value, key> ** reference;
						
						typename LIB::container::NAME_A <NTT <value, key> *, key>::iterator iter;
						//NTT <value, key> * parent;
				};
				/*
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
						
						typename LIB::container::NAME_A <NTT <value, key> *, key>::const_iterator iter;
						//NTT <value, key> * parent;
				};
				*/
				
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
				NTT (const LIB::container::NAME_A <value, key> &);
				NTT (const value &);
				//NTT (const machine::resources::memory::key &);
				
				const NTT <value, key> & operator = (const NTT <value, key> &);
				const NTT <value, key> & operator = (const LIB::container::NAME_A <value, key> &);
				const NTT <value, key> & operator = (const value &);
				//const NTT <value, key> & operator = (const machine::resources::memory::key &);
				
				friend class boost::serialization::access;
				//friend class container;
				
				template <typename archive>
				void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				//const iterator_const & begin (void) const;
				//const iterator_const & end (void) const;
				
				const iterator begin (void);
				const iterator end (void);
				const /*const_*/iterator begin (void) const;
				const /*const_*/iterator end (void) const;
				
				//const LIB::container::any & operator = (const LIB::container::any);
				//operator = (const std::string &);
				// const LIB::container::NAME_A <NTT *, container::key> & operator = (const LIB::container::NAME_A <NTT *, container::key> &);
				NTT <value, key> & operator [] (const key &);
				const NTT <value, key> & operator [] (const key &) const;
				
				const bool unset (const key &);
				const bool exists (const key &, const bool &/* recursive*/ = false) const;
				const bool exist (const key &, const bool &/* recursive*/ = false) const;
				const bool clear (void);
				const bool empty (void) const;
				const bool full (void) const;
				const LIB::math::numbers::natural size (const bool &/* recursive*/ = false, const bool &/* grouped/inclusive (consider a group as an item, in addition to its children) (only considered if recursive == true)*/ = false) const;
				const bool rename (const key &/* old*/, const key &/* new*/);
				
				//const key * & get_key (void);
				
				operator const LIB::container::NAME_A <value, key> (void) const;
				//operator value & (void);
				operator const value & (void);
				operator const value & (void) const;
				const value & operator * (void);
				const value & operator * (void) const;
				const value & operator -> (void);
				const value & operator -> (void) const;
				const value & operator () (void);
				const value & operator () (void) const;
				//const value & value (void);
				//const value & value (void) const;
				const value & get_value (void);
				const value & get_value (void) const;
				
				const bool operator == (const NTT <value, key> &) const;
				const bool operator != (const NTT <value, key> &) const;
				const bool operator == (const value &) const;
				const bool operator != (const value &) const;
				const bool operator == (const LIB::container::NAME_A <value, key> &) const;
				const bool operator != (const LIB::container::NAME_A <value, key> &) const;
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
	
	template <typename value, typename key>
	using NTT = container::NTT <value, key>;
}

//#include "../machine/resources/memory.h++"

#include "object.t++"

//#endif

