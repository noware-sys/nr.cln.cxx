// #include <typeinfo>
#include <iostream>
// Array.CPP:
// Default constructor:
//template <typename value, typename key> 
//LIB::NAME_A<value, key>::NAME_A (void)
//{
//	_size = 0;
//	tolerant = true;
//	//Reset ();
//	//free = true;
//}

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
LIB::NAME_A <value, key>::NAME_A (const LIB::NAME_A <value, key> & val)
{
	*this = val;
}

// Default detructor:
template <typename value, typename key> 
LIB::NAME_A <value, key>::~NAME_A (void)
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
		typeid (key) ==  typeid (signed long long int)
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
					
					return add (i, _value_);
					//return add (i, _value_) == _value_;
				}
			}
	}
	
	//return _value;
	return false;
}

// Setter.
template <typename value, typename key> 
value & LIB::NAME_A <value, key>::operator [] (const key & _key)
//value & LIB::NAME_A <value, key>::operator [] (const value & val)
{
	//std::unordered_map <key, value>::const_iterator found = container.find (_key);
	//std::unordered_map <key, value>::iterator found = container.find (_key);
	
	// return * (get (_key/*, tolerant*/));	// Not necessarily a setter in all cases.
	
	value temp;
	
	if (search (_key, temp))
	{
		return temp;
	}
	else if (tolerant)
	{
		return add (_key);
	}
	else
	{
		return temp;
	}
	
	
	/*
	value * temp;
	 * 
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

//// Getter.
//template <typename value, typename key> 
//const value & LIB::NAME_A <value, key>::operator [] (const key & _key) const
////value & LIB::NAME_A <value, key>::operator [] (const value & val)
//{
//	//std::unordered_map <key, value>::const_iterator found = container.find (_key);
//	//std::unordered_map <key, value>::iterator found = container.find (_key);
//	
//	// return * (get (_key/*, tolerant*/));	// Not necessarily a setter in all cases.
//	
//	//value * temp = NULL;
//	value temp;
//	
//	search (_key, temp);
//	
//	return temp;
//	/*
//	value * temp;
//	
//	//
//	//tolerant = tolerant;
//	//
//	
//	if (search (_key, temp))
//	{
//		return temp;
//	}
//	else if (tolerant)
//	{
//		// Do not add when in tolerant mode; just return any value.
//		value val;
//		return val;
//		//return NULL;
//	}
//	else
//		return create (val);
//	*/
//}

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
bool LIB::NAME_A <value, key>::search (const key & _key, value & _value_)
{
	//for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
	//	std::cout << ' ' << *it;
	reset ();
	
	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
	{
		if (current_key () == _key)
		{
			_value_ = current_value ();
			
			return true;
		}
		
		next ();
	}
	
	return false;
}

template <typename value, typename key> 
value &/* bool */LIB::NAME_A <value, key>::add (const key & _key, const value & _value_)
{
	/*
	package * temp = new package ();
	temp -> k = _key;
	temp -> v = _value_;
	
	container.push_back (* temp);
	*/
	
	package temp;
	temp.k = _key;
	temp.v = _value_;
	
	container.push_back (temp);
	
	//return temp -> v;
	//return true;
	return container.back ().v;
}

template <typename value, typename key>
value &/* bool */LIB::NAME_A <value, key>::add (const key & _key)
{
	value _value_;
	
	return add (_key, _value_);
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
bool LIB::NAME_A <value, key>::exists (const key & _key)
{
	//std::unordered_map <key, value>::const_iterator found = container.find (_key);

	//return found != container.end ();
	//return container.count (_key) > 0;
	// return false;
	value temp;

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
bool LIB::NAME_A <value, key>::unset (const key & _key)
{
	reset ();

	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
	{
		if (current_key () == _key)
		{
			//_value = & current_value ();
			container.erase (list_iterator);

			return true;
		}

		next ();
	}
	
	//container.remove (_key);
	return false;

}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::rename (const key & current, const key & val /* New name. */, const bool & _tolerant)
{
	if (! exists (current) || (! _tolerant /* If not permitted to overwrite the new value... */ && exists (val) /* ...and if the new value exists. */))
		return false;
	
	// Clear the spot.
	unset (val);

	reset ();
	
	for (LIB::mathematics::numbers::natural i = 0; i < size (); ++ i)
	{
		if (current_key () == current)
		{
			current_key_internal () = val;
			//_value = & current_value ();
			//container.erase (list_iterator);

			return true;
		}
		
		next ();
	}
	
	return false;
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
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const LIB::NAME_A <value, key> & val)
{
	//return container = val.container;
	if (this != & val)
		container = val.container;
	
	return *this;
}

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
	return list_iterator -> v;
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
bool LIB::NAME_A <value, key>::reset (void)
{
	list_iterator = container.begin ();
	
	return true;
}

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
bool LIB::NAME_A <value, key>::operator == (const NAME_A <value, key> & other)
{
	if (this == other)
		return true;
	
	mathematics::numbers::natural n = other.size ();
	
	if (size () != n)
		return false;
	
	reset ();
	other.reset ();
	
	for (mathematics::numbers::natural i = 0; i < n; ++ i)
	{
		if (current_key () != other.current_key () || current_value () != other.current_value ())
		{
			return false;
		}
		
		next ();
		other.next ();
	}
	
	return true;
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::operator != (const NAME_A <value, key> & other)
{
	return !operator == (other);
}
