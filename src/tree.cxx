#pragma once

//#include "entity.h++"
#include <iostream>
//#include "../math.h++"

// Container
//LIB::container::container (void)
//{
//	//group = new LIB::array <NTT, key> ();
//}
//
//LIB::container::~ container (void)
//{
//	//delete group;
//}


template <typename value, typename key>
template <typename archive>
void LIB::NTT <value, key>::container::serialize (archive & arch, const unsigned int & version)
//LIB::NAME_A<container::value, container::key>::NAME_A (void)
{
	arch & t;
	arch & lit;
	arch & grp;
}

/*
template <typename value, typename key>
template <typename archive>
void LIB::NTT <value, key>::container::save (archive & arch, const unsigned int & version) const
{
	arch << t;
	arch << lit;
	arch << grp;
}

template <typename value, typename key>
template <typename archive>
void LIB::NTT <value, key>::container::load (archive & archive, const unsigned int & version)
{
	arch >> t;
	arch >> lit;
	arch >> grp;
}
*/

template <typename value, typename key>
const std::string LIB::NTT <value, key>::container::serialize (void) const
{
	return LIB::serialize <LIB::NTT <value, key>::container> (* this);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NTT <value, key>::container> (serial, * this);
}

template <typename value, typename key>
const std::string LIB::NTT <value, key>::serialize (void) const
{
	return LIB::serialize <LIB::NTT <value, key>> (* this);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NTT <value, key>> (serial, * this);
}

template <typename value, typename key>
template <typename archive>
void LIB::NTT <value, key>::serialize (archive & arch, const unsigned int & version)
//LIB::NAME_A<container::value, container::key>::NAME_A (void)
{
	arch & content;
}

/*
template <typename value, typename key>
const typename LIB::NTT <value, key>::iterator_const & LIB::NTT <value, key>::begin (void) const
{
	return content.grp.begin ();
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::iterator_const & LIB::NTT <value, key>::end (void) const
{
	return content.grp.end ();
}
*/

template <typename value, typename key>
LIB::NTT <value, key>::container::container (void)
{
	t = type::literal;
}

template <typename value, typename key>
LIB::NTT <value, key>::container::~container (void)
{
	if (t == type::group)
	{
		for (auto & element : grp)
		{
			if (element.v != NULL)
			{
				try
				{
					delete element.v;
					//element.v = NULL;
				}
				catch (...)
				{
				}
				
				element.v = NULL;
			}
		}
	}
}

template <typename value, typename key>
LIB::NTT <value, key>::container::container (const container & other)
{
	* this = other;
}

template <typename value, typename key>
LIB::NTT <value, key>::container::container (const LIB::NTT <value, key> & other)
{
	* this = other;
}

template <typename value, typename key>
LIB::NTT <value, key>::container::container (const LIB::NAME_A <value, key> & other)
{
	* this = other;
}

template <typename value, typename key>
LIB::NTT <value, key>::container::container (const value & other)
{
	* this = other;
}

template <typename value, typename key>
typename LIB::NTT <value, key>::container & LIB::NTT <value, key>::container::operator = (const LIB::NTT <value, key>::container & other)
{
	t = other.t;
	lit = other.lit;
	//group = other.group;	// Would be recursive.
	//content.content_clear_group ();
	for (const typename LIB::NAME_A <NTT <value, key> *, key>::container & element : grp)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	grp.clear ();
	
	NTT <value, key> * ntt;
	//LIB::NAME_A <NTT *, container::key>::package pack;
	for (const typename LIB::NAME_A <NTT <value, key> *, key>::container & element : other.grp)
	{
		grp [element.k] = ntt = new NTT <value, key> ();
		
		// Copy value, not pointer.
		/*
		if (element.v -> content.t == container::type::literal)
		{
			ntt -> content.lit = element.v -> content.lit;
			//* ntt = (* (element.v)).value.literal;
		}
		else
		{
			//group = (* element).value.group;
			ntt -> content.grp = element.v -> content.grp;	// Is this recursive? No.
		}
		*/
		*ntt = *element.v;
		
		//group [(*element).k] = ntt = new NTT ();
		//group [element.k] = ntt = new NTT ();
		//* ntt = * element;
	}
	
	return * this;
}

template <typename value, typename key>
typename LIB::NTT <value, key>::container & LIB::NTT <value, key>::container::operator = (const LIB::NTT <value, key> & other)
{
	// t = other.content.t;
	// lit = other.content.lit;
	//grp = other.content.grp;
	return *this = other.content;
	
//	
//	content_clear_literal ();
//	
//	t = type::group;
//	
//	content_clear_group ();
//	
	// NTT <value, key> * ntt/*, ntt2*/;
	/*
	other.content.content_clear_group ();
	
	for (const typename LIB::NAME_A <NTT <value, key> *, key>::container & element : other.content.grp)
	{
		// grp.operator [] (* (element.get_key ())) = ntt = new NTT <value, key> (element);
		grp.operator [] (element.k) = /*ntt = * /new NTT <value, key> (element.v);
		
		////* ntt = /*(LIB::NTT) * /element.v;
		////ntt -> k = grp.operator [] (* (element.get_key ())) -> grp.get_key (* (element.get_key ()));
		////ntt -> k = ntt -> get_key (* (element.get_key ()));
		
		// ntt -> k = grp.get_key (* (element.get_key ()));
	}
	*/
	// return * this;
}

template <typename value, typename key>
typename LIB::NTT <value, key>::container & LIB::NTT <value, key>::container::operator = (const LIB::NAME_A <value, key> & other)
{
	content_clear_literal ();
	
	t = type::group;
	
	content_clear_group ();
	
	NTT <value, key> * ntt/*, ntt2*/;
	
	for (auto & element : other)
	{
		grp.operator [] (element.k) = ntt = new NTT <value, key> (element.v);
		
		////* ntt = /*(LIB::NTT) */element.v;
		
		// ntt -> k = grp.get_key (element.k);
	}
	
	return * this;
}

template <typename value, typename key>
typename LIB::NTT <value, key>::container & LIB::NTT <value, key>::container::operator = (const value & other)
{
	content_clear_group ();
	
	lit = other;
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::container::type LIB::NTT <value, key>::container::get_type () const
{
	return t;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator == (const container & other) const
{
	if (t != other.t)
		return false;
	
	switch (t)
	{
		case type::literal:
			return lit == other.lit;
		default:
			return grp == other.grp;
	}
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator != (const container & other) const
{
	return !(*this == other);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator == (const LIB::NAME_A <value, key> & other) const
{
	if (t != type::group // We are comparing a single value to a list, which, normally, should be considered uncomparable.
			|| size () != other.size ())
	{
		return false;
	}
	else
	{
		for (auto & element : other)
		{
			if (! exist (element.k))
			{
				return false;
			}
			// TODO: double-check:
			else if (grp.operator [] (element.k).content.t != type::literal || grp.operator [] (element.k).content.lit != element.v)
			{
				return false;
			}
		}
		
		return true;
	}
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator == (const LIB::NTT <value, key> & other) const
{
	return * this == other.content;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator != (const LIB::NTT <value, key> & other) const
{
	return ! (operator == (other));
}

//template <typename value, typename key>
//const bool LIB::NTT <value, key>::container::operator == (const LIB::NAME_A <value, key> & other) const
//{
//	return ! (* this == other);
//}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator == (const value & other) const
{
	if (t != type::literal)
	{
		return false;
	}
	
	return lit == other;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::operator != (const value & other) const
{
	return ! (* this != other);
}

// Iterator
// Default constructor.
template <typename value, typename key>
LIB::NTT <value, key>::iterator::iterator (void)
{
	//reference = NULL;
	//iter = NULL;
}

// Copy constructor.
template <typename value, typename key>
LIB::NTT <value, key>::iterator::iterator (const iterator & other)
{
	iter = other.iter;
	//parent = other.parent;
	//reference = other.reference;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::iterator::operator == (const iterator & other) const
{
	//return reference == other.reference;
	return iter == other.iter;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::iterator::operator != (const iterator & other) const
{
	return !(*this == other);
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::iterator & LIB::NTT <value, key>::iterator::operator ++ (void)
{
	//++ reference;
	//if (iter != NULL && parent != NULL)
	//{
		//std::cout << **reference << std::endl;
		
		//iter = & (parent -> content.grp.begin ());
		//++ (* iter);
		++ iter;
		//iter = & (parent -> content.grp.begin ());
		// reference = & ((* iter) -> v);
		
		//std::cout << **reference << std::endl;
	//}
	
	return *this;
}

template <typename value, typename key>
const key & LIB::NTT <value, key>::iterator::k (void) const
{
	return iter -> k;
}

template <typename value, typename key>
LIB::NTT <value, key> & LIB::NTT <value, key>::iterator::operator * (void) const
{
	//return ** reference;
	return * (iter -> v);
	/*
	if (iter == NULL)
	{
		return NULL;
	}
	else
	{
		try
		{
			return iter -> v;
		}
		catch (...)
		{
			return NULL;
		}
	}
	*/
}
/**
// Constant Iterator
// Default constructor.
template <typename value, typename key>
LIB::NTT <value, key>::const_iterator::const_iterator (void)
{
	//reference = NULL;
	//iter = NULL;
}

// Copy constructor.
template <typename value, typename key>
LIB::NTT <value, key>::const_iterator::const_iterator (const const_iterator & other)
{
	iter = other.iter;
	//parent = other.parent;
	//reference = other.reference;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::const_iterator::operator == (const const_iterator & other) const
{
	//return reference == other.reference;
	return iter == other.iter;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::const_iterator::operator != (const const_iterator & other) const
{
	return !(*this == other);
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::const_iterator & LIB::NTT <value, key>::const_iterator::operator ++ (void)
{
	//++ reference;
	//if (iter != NULL && parent != NULL)
	//{
		//std::cout << **reference << std::endl;
		
		//iter = & (parent -> content.grp.begin ());
		//++ (* iter);
		++ iter;
		//iter = & (parent -> content.grp.begin ());
		// reference = & ((* iter) -> v);
		
		//std::cout << **reference << std::endl;
	//}
	
	return *this;
}

template <typename value, typename key>
LIB::NTT <value, key> & LIB::NTT <value, key>::const_iterator::operator * (void) const
{
	//return ** reference;
	return * (iter -> v);
	/*
	if (iter == NULL)
	{
		return NULL;
	}
	else
	{
		try
		{
			return iter -> v;
		}
		catch (...)
		{
			return NULL;
		}
	}
	* /
}
*/
// Entity
template <typename value, typename key>
LIB::NTT <value, key>::NTT (void)
{
	//k = NULL;
}

template <typename value, typename key>
LIB::NTT <value, key>::NTT (const LIB::NTT <value, key> & other)
{
	//k = NULL;
	
	*this = other;
}

template <typename value, typename key>
LIB::NTT <value, key>::NTT (const LIB::NAME_A <value, key> & other)
{
	//k = NULL;
	
	*this = other;
}

template <typename value, typename key>
LIB::NTT <value, key>::NTT (const value & other)
{
	*this = other;
}

/*template <typename value, typename key>
LIB::NTT <value, key>::NTT (const machine::resources::memory::key & key)
{
	* this = key;
}*/

template <typename value, typename key>
const typename LIB::NTT <value, key>::iterator LIB::NTT <value, key>::begin (void)
{
	NTT <value, key>::iterator iter;
	
	//iter.parent = this;
	iter.iter = content.grp.begin ();
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	return iter;
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::iterator LIB::NTT <value, key>::end (void)
{
	NTT <value, key>::iterator iter;
	
	//iter.parent = this;
	iter.iter = content.grp.end ();
	//-- (*iter);
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	return iter;
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::/*const_*/iterator LIB::NTT <value, key>::begin (void) const
{
	//NTT <value, key>::const_iterator iter;
	NTT <value, key>::iterator iter;
	
	//iter.parent = this;
	iter.iter = content.grp.begin ();
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	return iter;
}

template <typename value, typename key>
const typename LIB::NTT <value, key>::/*const_*/iterator LIB::NTT <value, key>::end (void) const
{
	//NTT <value, key>::const_iterator iter;
	NTT <value, key>::iterator iter;
	
	//iter.parent = this;
	iter.iter = content.grp.end ();
	//-- (*iter);
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	return iter;
}

template <typename value, typename key>
const LIB::NTT <value, key> & LIB::NTT <value, key>::operator = (const NTT <value, key> & other)
{
	content = other/*.content*/;
	
	return * this;
}

template <typename value, typename key>
const LIB::NTT <value, key> & LIB::NTT <value, key>::operator = (const LIB::NAME_A <value, key> & other)
{
	// content.t = container::type::group;
	
	// content.content_clear_literal ();
	
	//content.grp = other;
	content = other;
	
	return * this;
}

template <typename value, typename key>
const LIB::NTT <value, key> & LIB::NTT <value, key>::operator = (const value & other)
{
	// content.t = container::type::literal;
	
	// content.content_clear_group ();
	
	/*
	try
	{
		//container::value.literal = const_cast <LIB::NAME> (* (static_cast <const LIB::NAME_V *> (val)));
		value.literal = * (static_cast <const LIB::NAME_V *> (val));
	}
	catch (...)
	{
	}
	*/
	
	content = other;
	
	return * this;
	
	//return container::value.literal;
}
/*
const LIB::NAME_V & LIB::NTT::operator = (const LIB::NAME_V val)
{
	t = type::literal;
	
	content.content_clear_group ();
	
	return container::value.literal = val;
}
*/
/*
const LIB::NAME_A <LIB::NTT *, LIB::NTT::container::key> & LIB::NTT::operator = (const LIB::NAME_A <NTT *, container::key> & group)
{
	value.t = container::type::group;
	
	content.content_clear_literal ();
	
	return value.group.operator = (group);
}
*/
template <typename value, typename key>
LIB::NTT <value, key> & LIB::NTT <value, key>::operator [] (const key & _k)
{
	content.t = container::type::group;
	
	content.content_clear_literal ();
	
	NTT <value, key> * ntt/*, ntt2*/;
	
	if (content.grp.exist (_k))
	{
		ntt = content.grp.operator [] (_k);
	}
	else
	{
		content.grp.operator [] (_k) = ntt = new NTT <value, key> ();
		
		// ntt -> k = content.grp.get_key (_k);
	}
	
	return * ntt;
	//return * (content.group.operator [] (_k));
	
//	ntt = value.group.operator [] (_k);
//	
//	try
//	{
//		// ntt2 = * ntt;
//		
//		//return * ntt;
//	}
////	catch (std::exception & e)
////	{
////		std::cerr << "Exception occurred: " << e.what () << std::endl;
////		
////		container::value.group.operator [] (container::key) = ntt = new LIB::NTT ();
////		
////		return * ntt;
////	}
//	catch (...)
//	{
//		container::value.group.operator [] (container::key) = ntt = new LIB::NTT ();
//		
//		//return * ntt;
//	}
//	
//	return * ntt;
}

template <typename value, typename key>
const LIB::NTT <value, key> & LIB::NTT <value, key>::operator [] (const key & _k) const
{
	//content.t = container::type::group;
	
	//content.content_clear_literal ();
	
	//NTT <value, key> * ntt/*, ntt2*/;
	
	if (exist (_k))
	{
		return * (const_cast <const LIB::NTT <value, key> *> (content.grp.operator [] (_k)));
	}
	else
	{
		return * this;
	}
	//return * (content.group.operator [] (_k));
	
//	ntt = value.group.operator [] (_k);
//	
//	try
//	{
//		// ntt2 = * ntt;
//		
//		//return * ntt;
//	}
////	catch (std::exception & e)
////	{
////		std::cerr << "Exception occurred: " << e.what () << std::endl;
////		
////		container::value.group.operator [] (container::key) = ntt = new LIB::NTT ();
////		
////		return * ntt;
////	}
//	catch (...)
//	{
//		container::value.group.operator [] (container::key) = ntt = new LIB::NTT ();
//		
//		//return * ntt;
//	}
//	
//	return * ntt;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::unset (const key & _k)
{
	content.t = container::type::group;
	
	content.content_clear_literal ();
	
	return content.grp.unset (_k);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::exists (const key & _k, const bool & recursive) const
{
	return exist (_k, recursive);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::exist (const key & _k, const bool & recursive) const
{
	switch (content.t)
	{
		case container::type::literal:
			return false;
		//case container::type::group:
		default:
			if (recursive)
			{
				for (auto & element : * this)
				{
					if (element.exist (_k, recursive))
					{
						return true;
					}
				}
				
				return false;
			}
			else
			{
				return content.grp.exist (_k);
			}
	}
}

template <typename value, typename key>
const LIB/*::math*/::nr::natural LIB::NTT <value, key>::size (const bool & recursive, const bool & grouped) const
{
	switch (content.t)
	{
		case container::type::literal:
			return 0;
		default:
			if (recursive)
			{
				unsigned short int additional = grouped ? 1 : 0;
				//math::numbers::natural count = 0;
				nr::natural count = 0;
				
				for (auto & element : * this)
				{
					count += element.size (recursive, grouped) + additional;
				}
				
				return count;
			}
			else
			{
				return content.grp.size ();
			}
	}
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::clear (void)
{
	switch (content.t)
	{
		case container::type::literal:
			return true;
		default:
			return content.content_clear_group ();
	}
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::rename (const key & current, const key & _new)
{
	content.t = container::type::group;
	
	content.content_clear_literal ();
	
	return content.grp.rename (current, _new);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator == (const NTT <value, key> & other) const
{
	return content == other.content;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator != (const NTT <value, key> & other) const
{
	return !(* this == other);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator == (const value & other) const
{
	return content == other;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator != (const value & other) const
{
	return ! (* this == other);
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator == (const LIB::NAME_A <value, key> & other) const
{
	/*
	if (content.t == container::type::literal // We are comparing a single value to a list, which, normally, should be considered uncomparable.
			|| size () != other.size ())
	{
		return false;
	}
	else
	{
		for (auto & element : other)
		{
			if (! exist (element._k))
			{
				return false;
			}
			else if (operator [] (element._k).content.t != container::type::literal || operator [] (element._k).content.lit != element.v)
			{
				return false;
			}
		}
		
		return true;
	}
	*/
	
	return content == other;
	//return content == other.content;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator != (const LIB::NAME_A <value, key> & other) const
{
	return ! (* this == other);
}

/*template <typename value, typename key>
const LIB::NTT <value, key> & LIB::NTT <value, key>::operator = (const machine::resources::memory::key & key) const
{
	operator [] ("name") = key.name;
	operator [] ("group") = key.group;
	operator [] ("grouped") = key.grouped;
	
	return *this;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator == (const machine::resources::memory::key & key) const
{
	if (! exist ("name") || operator [] ("name") != key.name)
		return false;
	
	if (! exist ("group") || operator [] ("group") != key.group)
		return false;
	
	if (! exist ("grouped") || operator [] ("grouped") != key.grouped)
		return false;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::operator != (const machine::resources::memory::key & key) const
{
	return ! (operator == (key));
}*/

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator () (void)
{
	content.t = container::type::literal;
	
	content.content_clear_group ();
	
	return content.lit;
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator () (void) const
{
	//content.t = container::type::literal;
	
	//content.content_clear_group ();
	
	return content.lit;
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator * (void)
{
	return (* this) ();
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator * (void) const
{
	return (* this) ();
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator -> (void)
{
	return (* this) ();
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::operator -> (void) const
{
	return (* this) ();
}

template <typename value, typename key>
LIB::NTT <value, key>::operator const LIB::NAME_A <value, key> (void) const
{
	LIB::NAME_A <value, key> temp;
	
	if (is_literal ())
	{
		temp.add ((*this) ());
	}
	else
	{
		for (const auto & element : content.grp)
		{
			temp [element.k] = *(element.v);
		}
	}
	
	return temp;
}

template <typename value, typename key>
LIB::NTT <value, key>::operator const value & (void)
{
	return (* this) ();
}

template <typename value, typename key>
LIB::NTT <value, key>::operator const value & (void) const
{
	return (* this) ();
}
/*
template <typename value, typename key>
value & LIB::NTT <value, key>::value (void)
{
	return (* this) ();
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::value (void) const
{
	return (* this) ();
}
*/
template <typename value, typename key>
const value & LIB::NTT <value, key>::get_value (void)
{
	return (* this) ();
}

template <typename value, typename key>
const value & LIB::NTT <value, key>::get_value (void) const
{
	return (* this) ();
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::content_clear_literal (void)
{
	lit = "";
	
	return true;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::content_clear_group (void)
{
	for (auto & element : grp)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	
	return grp.clear ();
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::empty (void) const
{
	if (t == type::literal)
	{
		return false;
	}
	else
	{
		return grp.empty ();
	}
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::container::full (void) const
{
	return false;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::empty (void) const
{
	return content.empty ();
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::full (void) const
{
	return false;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::is_literal (void) const
{
	return content.t == container::type::literal;
}

template <typename value, typename key>
const bool LIB::NTT <value, key>::is_group (void) const
{
	return content.t == container::type::group;
}
