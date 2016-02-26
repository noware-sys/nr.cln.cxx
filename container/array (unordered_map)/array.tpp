#include <typeinfo>

// Array.CPP:
// Default constructor:
//template <typename value, typename key> 
//LIB::NAME_A<value, key>::NAME_A (void)
//{
//	_size = 0;
//	strict = true;
//	//Reset ();
//	//free = true;
//}

template <typename value, typename key> 
LIB::NAME_A <value, key>::NAME_A (const bool & _strict)
{
	//_size = 0;
	strict = _strict;

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
	clear ();
	//_size = 0;
}

// Setter
//template <typename value, typename key> 
//value & LIB::NAME_A<value, key>::operator [] (const key key)
//{
//	//return values;
//}

// Getter and Setter.
template <typename value, typename key> 
value & LIB::NAME_A <value, key>::operator [] (const key & _key)
//value & LIB::NAME_A <value, key>::operator [] (const value & val)
{
	//std::unordered_map <key, value>::const_iterator found = container.find (_key);
	std::unordered_map <key, value>::iterator found = container.find (_key);

	if (found != container.end ())
	{
		return * & (found -> second);
	}
	else if (strict)
	{
		return _value;
	}
	else
	{
		std::pair <key, value> _pair;
		std::pair <std::unordered_map <key, value>::iterator, bool> insertion;
		_pair.first = _key;
		insertion = container.insert (_pair);

		if (insertion.second)	// If insertion succeeded.
		{

			//return insertion.first.second;
			//return _pair -> second;
			return * & (container.at (_key));
		}
		else
		{
			return _value;
		}
	}

	/*
	value * temp;

	//
	//strict = strict;
	//

	if (search (_key, temp))
	{
		return temp;
	}
	else if (strict)
	{
		// Do not add when in strict mode; just return any value.
		value val;
		return val;
		//return NULL;
	}
	else
		return create (val);
	*/
}

//template <typename value, typename key> 
//value & LIB::NAME_A <value, key>::operator [] (const key & _key, const bool & tolerant)
////value & LIB::NAME_A <value, key>::operator [] (const value & val)
//{
//	bool strict_local = strict;
//	strict = ! tolerant;
//
//	value val = operator [] (_key);
//
//	strict = strict_local;
//	
//	return val;
//}

template <typename value, typename key> 
value & LIB::NAME_A <value, key>::create (const key & key)
{
	package temp;
	temp._key = key;

	container.push_back (val);

	return temp._value;
}

template <typename value, typename key> 
void LIB::NAME_A <value, key>::clear (void)
{
	container.clear ();
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
	return container.count (_key) > 0;
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
	//container.remove (_key);
	return false;
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::rename (const key & current, const key & val)
{
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
bool LIB::NAME_A <value, key>::empty (void) const
{
	//return size () <= 0;
	return container.empty ();
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const LIB::NAME_A <value, key> & val)
{
	container = val.container;

	return *this;
}

/*
template <typename value, typename key> 
LIB::NAME_A <value, key>::key & LIB::NAME_A <value, key>::current_key (void)
{
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::current_value (void)
{
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::next (void)
{
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::previous (void)
{
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::start (void)
{
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::end (void)
{
}
*/
