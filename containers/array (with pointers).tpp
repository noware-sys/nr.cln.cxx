// #include <typeinfo>
//#include <iostream>
// Array.CPP:
// Standard library:
#include <utility>	// For "std::swap ()".


template <typename value, typename key>
bool LIB::NAME_A <value, key>::package::operator == (const package & other) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	// The type of value may not have the operator == defined, so comparing them may fail:
	try
	{
		return (ky == other.ky && * val == * (other.val));
		//return (ky == other.ky && val == other.val);
	}
	catch (...)
	{
		// Should the pointers be compared instead?
		return false;
	}
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::package & LIB::NAME_A <value, key>::package::operator = (const package & other)
{
	
	// The type of value may not have the operator = defined, so comparing them may fail:
	try
	{
		ky = other.ky;
		* val = * (other.val);
		//val = other.val;
	}
	catch (...)
	{
		// Should the pointers be used instead?
	}
	
	return * this;
}

template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::package::serialize (Archive & archive, const unsigned int & version)
//LIB::NAME_A<value, key>::NAME_A (void)
{
	//value temp_value;
	
	archive & ky;
	archive & (* val);
	
	//if (Archive::is_loading::value)
	//{
		//if (val != NULL)
		//{
			/*
			try
			{
				//value * v2 = new value ();
				
				val ->;
			}
			catch (...)
			{
				val = new value ();
//			}
			*/
		//}
	//}
	
	/*
	try
	{
		//value * v2 = new value ();

		val ->;
	}
	catch (...)
	{
		val = new value ();
	}
	archive & (* val);
	*/
	//archive & val;
	//archive & v;
	//boost::serialization::split_member (archive, * this, version);
}

//template <typename value, typename key>
//template <typename Archive>
//void LIB::NAME_A <value, key>::package::save (Archive & archive, const unsigned int & version) const
////LIB::NAME_A<value, key>::NAME_A (void)
//{
//	archive << ky;
//	archive << (* val);
//	//archive & val;
//	//archive & v;
//}
//
//template <typename value, typename key>
//template <typename Archive>
//void LIB::NAME_A <value, key>::package::load (Archive & archive, const unsigned int & version)
////LIB::NAME_A<value, key>::NAME_A (void)
//{
//	value temp_value;
//	
//	archive >> ky;
//	archive >> temp_value;
//	//* val;
//	
//	try
//	{
//		(* val) = temp_value;
//	}
//	catch (...)
//	{
//		val = new value ();
//	}
//	
//	archive >> (* val);
//	
//	//(* val) = value_temp;
//	//* val = value_temp;
//	//std::swap (* val, value_temp);
//	/*
//	try
//	{
//		delete val;
//	}
//	catch (...)
//	{
//	}
//	
//	val = new value (value_temp);
//	*/
//	//archive & val;
//	//archive & v;
//}

template <typename value, typename key>
std::string LIB::NAME_A <value, key>::package::serialize (void) const
{
	return LIB::serialize <LIB::NAME_A <value, key>::package> (* this);
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::package::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NAME_A <value, key>::package> (serial, * this);
}

template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::serialize (Archive & archive, const unsigned int & version)
//LIB::NAME_A<value, key>::NAME_A (void)
{
	archive & container;
	archive & tolerant;
	
	//boost::serialization::split_member (archive, * this, version);
}

/*
template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::save (Archive & archive, const unsigned int & version) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	//archive << container;
	//archive << tolerant;
	try
	{
		for (auto element : *this)
		{
			archive << element;
		}
		
		archive << tolerant;
		
		/*
		reset ();
		LIB::mathematics::numbers::natural size = this -> size ();
		
		for (LIB::mathematics::numbers::natural i = 0; i < size; ++ i)
		{
			//archive << current_key ();
			//archive << current_value ();
			archive << current_package ();
			
			next ();
		}
		
		archive << tolerant;
		//return true;
		* /
	}
	catch (...)
	{
		//return false;
	}
}

template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::load (Archive & archive, const unsigned int & version)
//LIB::NAME_A <value, key>::NAME_A (void)
{
	//archive >> container;
	//archive >> tolerant;
	try
	{
		LIB::NAME_A <value, key> temp;
		//reset ();
		//temp.clear ();
		//LIB::mathematics::numbers::natural size = size ();
		// Input archive:
		//boost::archive::text_iarchive iarchive (archive);
		
		//for (LIB::mathematics::numbers::natural i = 0; i < size; ++ i)
		//{
			//archive & current_key ();
			//archive & current_value ();
			//archive & operator[] ();
			//archive & current_value ();
			
		//	next ();
		//}
		
		//key k;
		//value v;
		package pack;
		
		//archive >> k;
		//archive >> v;
		
		if (archive >> temp.tolerant)
		{
			// !(archive >> temp.tolerant) does not work.
		}
		else
		{
			return/* false* /;
		}
		
		//while (! /*i* /archive.eof ())
		while (archive >> pack)
		{
			///*i* /archive >> k;
			///*i* /archive >> v;
			
			if (! temp.set (pack.ky, * (pack.val)))
				return/* false* /;
		}
		
		*this = temp;
		
		//return true;
	}
	catch (...)
	{
		//return false;
	}
}
*/

template <typename value, typename key>
std::string LIB::NAME_A <value, key>::serialize (void) const
{
	return LIB::serialize <LIB::NAME_A <value, key>> (* this);
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NAME_A <value, key>> (serial, * this);
}

template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (const bool & _tolerant)
{
	//_size = 0;
	tolerant = _tolerant;

	// Add a default value to be returned when one is searched by a key which does not exist.
	//std::pair <key, value> _pair;
	//container.insert (_pair);
}

// Copy constructor:

template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (const LIB::NAME_A <value, key> & other)
{
	*this = other;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::package::package (void)
{
	//val = NULL;
	val = new value ();
}

template <typename value, typename key>
LIB::NAME_A <value, key>::package::~ package (void)
{
	if (val != NULL)
	{
		try
		{
			delete val;
		}
		catch (...)
		{
		}
	}
}


// Default destructor:

template <typename value, typename key>
LIB::NAME_A <value, key>::~ NAME_A (void)
{
	//Link * current;
	//tempSize = size ();
	//LIB::NAME_A<value, key>::Clear ();
	//clear ();
	//_size = 0;
}

// Setter
//template <typename value, typename key>
//value & LIB::NAME_A<value, key>::operator [] (const key key)
//{
//	//return values;
//}

// Setter.

template <typename value, typename key>
/*value &*/ bool LIB::NAME_A <value, key>::/*operator []*/ append (const value & _value_, key & _key_)
{
	/*
	switch (typeid (key))
	{
		case typeid (signed short int):
		case typeid (unsigned short int):
		case typeid (signed int):
		case typeid (unsigned int):
		case typeid (signed long int):
		case typeid (unsigned long int):
		case typeid (signed long long int):
		case typeid (LIB::mathematics::numbers::integer):
		case typeid (unsigned long long int):
		case typeid (LIB::mathematics::numbers::natural):
			//ULLONG_MAX
			for ( key i = 0; i < size () && i < ULLONG_MAX; ++ i)
			{
				if (! exists (i))
				{
					if (_key_ != NULL)
						_key_ = i;
					
					return add (i, _value_);
					//return add (i, _value_) == _value_;
				}
			}
	}
	 */
	if
		(
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed int)
			||
			typeid (key) == typeid (unsigned int)
			||
			typeid (key) == typeid (signed long int)
			||
			typeid (key) == typeid (unsigned long int)
			||
			typeid (key) == typeid (signed long long int)
			||
			typeid (key) == typeid (LIB::mathematics::numbers::integer)
			||
			typeid (key) == typeid (unsigned long long int)
			||
			typeid (key) == typeid (LIB::mathematics::numbers::natural)
			)
	{
		//ULLONG_MAX
		for (key i = 1; i < size () && i < ULLONG_MAX; ++ i)
		{
			if (! exists (i))
			{
				if (_key_ != NULL)
					_key_ = i;

				return add (i, & _value_);
				//return add (i, _value_) == _value_;
			}
		}
	}

	//return _value;
	return false;
}

// Getter and Setter.

template <typename value, typename key>
value & LIB::NAME_A <value, key>::operator [] (const key & _key)
//value & LIB::NAME_A <value, key>::operator [] (const value & val)
{
	//std::unordered_map <key, value>::const_iterator found = container.find (_key);
	//std::unordered_map <key, value>::iterator found = container.find (_key);

	//return get (_key/*, tolerant*/);	// Not necessarily a setter in all cases.
	value * temp = NULL;

	if (search (_key, temp))
	{
		return * temp;
	}
	else if (tolerant)
	{
		value * _value_ = new value ();
		//const value * _value_ = new value ();

		//if (add (_key, & _value_))
		if (add (_key, _value_))
			//if (add (_key, const_cast <const value * &> (_value_)))
		{
			return * _value_;
			//return get (_key);
			//return const_cast <value> (* _value_);
		}
		else
		{
			delete _value_;

			return _value;
		}
	}
	else
	{
		return _value;
	}

	/*
	value * temp;

	if (search (_key, temp))
	{
		return * temp;
	}
	else if (tolerant)
	{
		return & _value;
	}
	else
	{
		return add (_key);
	}
	 */

	/*
	value * temp;

	//
	//tolerant = tolerant;
	//

	if (search (_key, temp))
	{
		return temp;
	}
	else if (tolerant)
	{
		// Do not add when in tolerant mode; just return any value.
		value val;
		return val;
		//return NULL;
	}
	else
		return create (val);
	 */
}

// Getter:
template <typename value, typename key>
value LIB::NAME_A <value, key>::operator [] (const key & _key) const
//value & LIB::NAME_A <value, key>::operator [] (const value & val)
{
	value * temp = NULL;
	
	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
	}
}

//template <typename value, typename key>
//value & LIB::NAME_A <value, key>::operator [] (const key & _key, const bool & tolerant)
////value & LIB::NAME_A <value, key>::operator [] (const value & val)
//{
//	bool strict_local = tolerant;
//	tolerant = ! tolerant;
//
//	value val = operator [] (_key);
//
//	tolerant = strict_local;
//	
//	return val;
//}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::search (const key & key_, value *& value_) const
{
	//for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
	//	std::cout << ' ' << *it;
	
	for (auto element : *this)
	{
		if (element.ky == key_)
		{
			value_ = element.val;
			//value_ = & element.val;
			
			return true;
		}
	}
	
	return false;
//	reset ();
//
//	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == _key)
//		{
//			_value_ = & current_value ();
//
//			return true;
//		}
//
//		next ();
//	}
//
//	return false;
}

template <typename value, typename key>
/*value &*/ bool LIB::NAME_A <value, key>::add (const key & key_, /*const */value *& value_)
{
	//(* _value_) = "TEMP";
	
	//package * temp = new package ();
	package temp;
	
	//temp -> ky = key_;
	//temp -> val = /** */value_;
	temp.ky = key_;
	* (temp.val) = * value_;
	
	//container.push_back (* temp);
	container.push_back (temp);
	
	//return temp -> v;
	return true;
	//return container.back ().v;
}

template <typename value, typename key>
/*value &*/ bool LIB::NAME_A <value, key>::add (const key & _key)
{
	value * _value_ = new value ();

	return add (_key, _value_);
}

//template <typename value, typename key>
///*value & */bool LIB::NAME_A <value, key>::set (const key & _key, const value *& _value_/*, const bool & _tolerant*/)
//{
///*
//	value * temp;
//	
//	if (search (_key, temp))	// This condition (also) works as a getter (it considers only the first parameter).
//	{
//		return * temp;
//	}
//	else if (! _tolerant)
//	{
//		return _value;
//	}
//	else
//	{
//		return add (_key, _value_);
//	}
//*/
//	value * temp;
//	
//	//std::cout << "search ()" << std::endl;
//	if (search (_key, temp))	// This condition (also) works as a getter (it considers only the first parameter).
//	{
//		//std::cout << "\"temp = & value\"" << std::endl;
//		//* temp = _value_;
//		temp = const_cast <value *&> (/*& */_value_);
//		
//		return true;
//	}
//	else //if (_tolerant)
//	{
//		//std::cout << "add ()" << std::endl;
//		return add (_key, _value_);
//	}
//	/*else
//	{
//		return false;
//	}*/
//}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::set (const key & _key, const value & _value_)
{
	value * temp;

	//std::cout << "search ()" << std::endl;
	if (search (_key, temp)) // This condition (also) works as a getter (it considers only the first parameter).
	{
		//std::cout << "\"temp = & value\"" << std::endl;
		* temp = _value_;
		//temp = const_cast <value *&> (/*& */_value_);

		return true;
	}
	else //if (_tolerant)
	{
		temp = & _value_;
		//std::cout << "add ()" << std::endl;
		return add (_key, temp);
	}
	/*else
	{
		return false;
	}*/
}

template <typename value, typename key>
value & LIB::NAME_A <value, key>::get (const key & _key/*, const bool & _tolerant*/)
{
	value * temp = NULL;

	/*
	std::cout << "set (...)" << std::endl;
	set (_key, temp, _tolerant);
	
	std::cout << "return temp" << std::endl;
	return temp;*/


	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
		//return temp;
	}

	//value _value_;
	//
	//return set (_key, _value_, tolerant);

}

template <typename value, typename key>
value LIB::NAME_A <value, key>::get (const key & _key) const
{
	value * temp = NULL;
	
	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
		//return temp;
	}
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::clear (void)
{
	container.clear ();

	return true;
}

template <typename value, typename key>
LIB::mathematics::numbers::natural LIB::NAME_A <value, key>::size (void) const
{
	return container.size ();
}

/*
template <typename value, typename key>
bool LIB::NAME_A <value, key>::search (const key & _key, package::_value & val) const
{
	//package current;

	LIB::mathematics::numbers::natural n = size ();
	std::list <key>::iterator it;

	//for (LIB::mathematics::numbers::natural index = 0; index < n; ++ index, current = current -> next)
	for (it = container.begin(); it != contaienr.end (); ++it)
	{
		if ((*it) -> _key == _key)
		{
			val = (* it) -> _value;;

			return true;
		}
	}

	return false;
}
 */
template <typename value, typename key>
bool LIB::NAME_A <value, key>::exists (const key & _key) const
{
	//std::unordered_map <key, value>::const_iterator found = container.find (_key);

	//return found != container.end ();
	//return container.count (_key) > 0;
	// return false;
	value * temp;

	return search (_key, temp);
}

//template <typename value, typename key>
//bool LIB::NAME_A<value, key>::New (const key, const value)
//{
//	if (Exists (key))
//	{
//		return false;
//	}
//	else
//	{
//		// Add it:
//		return true;
//	}
//}
//

template <typename value, typename key>
bool LIB::NAME_A <value, key>::unset (const key & key_)
{
	auto it = begin ();
	
	for (auto & element : * this)
	{
		if (element.ky == key_)
		{
			//_value = & current_value ();
			container.erase (it);
			//container.erase (&& element);
			
			return true;
		}
		
		++ it;
	}
	
	//container.remove (_key);
	return false;
	
//	reset ();
//	
//	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == _key)
//		{
//			//_value = & current_value ();
//			container.erase (list_iterator);
//
//			return true;
//		}
//
//		next ();
//	}
//
//	//container.remove (_key);
//	return false;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::rename (const key & current, const key & val /* New name. */, const bool & _tolerant)
{
	if (! exists (current) || (! _tolerant /* If not permitted to overwrite the new value... */ && exists (val) /* ...and if the new value exists. */))
		return false;
	
	// Clear the position.
	unset (val);
	
	for (auto element : * this)
	{
		if (element.ky == current)
		{
			element.ky = current;
			
			return true;
		}
	}

	return false;
	
//	reset ();
//
//	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == current)
//		{
//			current_key_internal () = val;
//			//_value = & current_value ();
//			//container.erase (list_iterator);
//
//			return true;
//		}
//
//		next ();
//	}
//
//	return false;
	/*
		link * target;

		if (search (current, target))
		{
			if (search (val, target))
				return false;
			else
				target -> _key = val;

			return true;
		}
		else
		{
			return false;
		}
	 */
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::rename (const key & current, const key & val /* New name. */)
{
	return rename (current, val, tolerant /* Use the externally-settable variable. */);
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::empty (void) const
{
	//return size () <= 0;
	return container.empty ();
}

template <typename value, typename key>
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const LIB::NAME_A <value, key> & other)
{
	//return container = val.container;
	if (this != & other)
		container = other.container;

	return * this;
}

/*
template <typename value, typename key>
key & LIB::NAME_A <value, key>::current_key_internal (void)
{
	return list_iterator -> k;
}

template <typename value, typename key>
key LIB::NAME_A <value, key>::current_key (void)
{
	return current_key_internal ();
}

template <typename value, typename key>
value & LIB::NAME_A <value, key>::current_value (void)
{
	return * (list_iterator -> v);
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator & LIB::NAME_A <value, key>::current_package (void)
{
	return list_iterator;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::next (void)
{
	if (list_iterator == container.end ())
	{
		reset ();
	}
	else
	{
		++ list_iterator;
	}

	return true;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::previous (void)
{
	if (list_iterator == container.begin ())
	{
		list_iterator = container.end ();
	}
	else
	{
		-- list_iterator;
	}

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::previous (const iterator & it)
{
	if (it == container.begin ())
	{
		it = container.end ();
	}
	else
	{
		-- it;
	}

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::previous (const iterator & it) const
{
	if (it == container.begin ())
	{
		it = container.end ();
	}
	else
	{
		-- it;
	}

	return it;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::reset (void)
{
	list_iterator = container.begin ();

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::reset (void/*const iterator & it* /) const
{
	return container.begin ();
}
*/
/*
template <typename value, typename key>
void LIB::NAME_A <value, key>::start (void)
{
	list_iterator = container.begin ();
}

template <typename value, typename key>
void LIB::NAME_A <value, key>::end (void)
{
	list_iterator = container.end ();
}
 */

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::begin (void)
{
	return container.begin ();
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::end (void)
{
	return container.end ();
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator_const LIB::NAME_A <value, key>::begin (void) const
{
	return container.cbegin ();
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator_const LIB::NAME_A <value, key>::end (void) const
{
	return container.cend ();
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::operator == (const NAME_A <value, key> & other) const
{
	if (this == other)
		return true;
	
	if (size () != other.size ())
		return false;
	
	// std::begin is a free function in C++11.
	//auto iterator_this = begin ();	//std::begin (* this);
	auto iterator_other = other.begin ();	//std::begin (other);
	
	for (auto & element : * this)
	{
		if (* element != * iterator_other)
		{
			return false;
		}
		
		++ iterator_other;
		//++ iterator_this;
	}
	
//	return true;
//	
//	mathematics::numbers::natural n = other.size ();
//
//	if (size () != n)
//		return false;
//
//	reset ();
//	other.reset ();
//
//	for (mathematics::numbers::natural i = 0; i < n; ++ i)
//	{
//		if (current_key () != other.current_key () || current_value () != other.current_value ())
//		{
//			return false;
//		}
//
//		next ();
//		other.next ();
//	}
//
//	return true;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::operator != (const NAME_A <value, key> & other) const
{
	return ! operator == (other);
}
