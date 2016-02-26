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
LIB::NAME_A <value, key>::link::link (void)
{
	next = previous = NULL;
}

template <typename value, typename key> 
LIB::NAME_A <value, key>::link::~link (void)
{
	//if (next != NULL)
	//	delete next;

	//if (previous != NULL)
	//	delete previous;
}

template <typename value, typename key> 
template <typename Archive>
void LIB::NAME_A <value, key>::link::serialize (Archive & archive, const unsigned int version)
{
	archive & key;
	archive & value;
	//archive & previous;
	//archive & next;
}

template <typename value, typename key> 
LIB::NAME_A <value, key>::NAME_A (const bool _strict)
{
	_size = 0;
	strict = _strict;

	begin ();
}

// Copy constructor:
template <typename value, typename key> 
LIB::NAME_A <value, key>::NAME_A (/*const */LIB::NAME_A <value, key> & val)
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

template <typename value, typename key> 
template <typename Archive>
void LIB::NAME_A <value, key>::serialize (Archive & archive, const unsigned int version)
{
/*
	LIB::mathematics::numbers::natural n, i;
	key __key;

	for (begin (), n = size (), i = 0; i < n; ++ *this, ++ i)
	{
		// Will this work?
		__key = current_key ();
		archive & __key;
		archive & operator [] (__key);

		//archive & current_key ();
		//archive & current ();
		//archive & operator [] ();
	}
*/
}
/*
// Getter:
// Get the value of a key:
template <typename value, typename key>
const value & LIB::NAME_A <value, key>::operator [] (const key & _key) const
{
	link * temp;

	if (search (_key, temp))
	{
		return temp -> _value;
	}
	else //if (strict)
	{
		// Do not add when in strict mode; just return any value.
		//value val;
		//return val;
		return NULL;
	}
//	else
//	{
//		// If we reached this point, then the key was not found (and that we are not in strict mode); so, we need to add it.
//		return New (_key);
//	}
}
*/
// Get the key of a value:
//template <typename value, typename key> 
//const key & LIB::NAME_A <value, key>::operator [] (const value & val) const
//{
//}
//
// Setter:
template <typename value, typename key> 
//value & LIB::NAME_A::<value, key>::operator [] (const key key)
value & LIB::NAME_A <value, key>::operator [] (const key & _key)
{
	// Look for the key (Getter):
	//Link <value, key> * current = values;
	//Link * current = values;

	//#pragma omp parallel private (current) num_threads (2)
	//{
	//	LIB::Mathematics::Number::Natural half = size () / 2;

	//	if (omp_get_thread_num () == 0)
	//	{
	//		for (LIB::Mathematics::Number::Natural index = 0; index < half; ++ index)
	//		{
	//			if (current -> key == key)
	//			{
	//				return current -> value;
	//			}

	//			current = current -> next;
	//		}
	//	}
	//	else
	//	{
	//		for (LIB::Mathematics::Number::Natural index = half; index > 0; -- index)
	//		{
	//			if (current -> key == key)
	//			{
	//				return current -> value;
	//			}

	//			current = current -> previous;
	//		}
	//	}
	//}

	link * temp;

	//
	//strict = strict;
	//

	if (search (_key, temp))
	{
		return temp -> _value;
	}
	else if (strict)
	{
		// Do not add when in strict mode; just return any value.
		value val;
		return val;
		//return NULL;
	}
	else
		return New (_key);
}

template <typename value, typename key> 
value & LIB::NAME_A <value, key>::New (const key & key)
{
	if (empty ())
	{
		//Link * current = values;
		/*try
		{
		*/	values = new link;

			values -> next = values;
			values -> previous = values;

			values -> _key = key;

			++ _size;
				
			//memory = true;

			return values -> _value;
		/*}
		catch (...)
		{
			memory = false;

			return * (new value);
		}*/
	}
	else
	{
		link * current;
		/*
		try
		{
		*/	current = values;
	
			// Start at the last element:
			current = values -> previous;

			// Add a new element:
			current -> next = new link;

			// Adjust the position of the new element:
			current -> next -> previous = current;
			current -> next -> next = values;

			// From the initial point (list), link to its previous element (the new element):
			values -> previous = current -> next;
	
			current -> next -> _key = key;

			++ _size;
				
			// memory = true;

			return current -> next -> _value;
		/*}
		catch (...)
		{
			current -> next = values;

			memory = false;

			return * (new value);
		}*/
	}

	////current -> next = new Link;

	//// Adjust the position of the new element:
	//current -> next -> previous = current;
	//current -> next -> next = values;

	//// From the initial point (list), link to its previous element (the new element):
	//values -> previous = current -> next;

	//// Advance to the next/new element.
	////current = current -> next;
	//++ _size;
	////current -> element = i + 1;
	//return current -> next -> value;
}

template <typename value, typename key> 
void LIB::NAME_A <value, key>::clear (void)
{
	//LIB::NAME_A<value, key>::~NAME_A ();
		
	while (size () > 0)
	{
		//current = values;
		Delete (values -> _key);

		//current = current -> next;
	}
}

template <typename value, typename key> 
LIB::mathematics::numbers::natural LIB::NAME_A <value, key>::size (void) const
{
	return _size;
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::search (const key & _key, link *& val) const
{
	if (empty ())
		return false;

	link * current = values;

	LIB::mathematics::numbers::natural n = size ();

	for (LIB::mathematics::numbers::natural index = 0; index < n; ++ index, /*operator ++ ()*/current = current -> next)
	{
		if (current -> _key == _key)
		{
			val = current;

			return true;
		}
	}

	return false;
	//bool found = false;
	//current = values;

	//#pragma omp parallel num_threads (2) private (current)
	//{
	//	LIB::mathematics::numbers::natural half = size () / 2;
	//	//current = values;
	//	//unsigned short int id = omp_get_thread_num ();

	//	switch (omp_get_thread_num ())
	//	{
	//		case 0:
	//			current = values;

	//			for (LIB::mathematics::numbers::natural index = 0; index < half; ++ index, current = current -> next)
	//			{
	//				if (current -> _key == _key)
	//				{
	//					val = current;
	//					//return true;
	//					found = true;

	//					break;
	//				}
	//			}

	//			break;
	//		default:
	//			//current = values;
	//
	//			if (size () % 2 != 0)	// If there are odd number of elements.
	//			{
	//				++ half;
	//			}

	//			current = values -> previous;

	//			for (LIB::mathematics::numbers::natural index = half; index > 0; -- index, current = current -> previous)
	//			{
	//				if (current -> _key == _key)
	//				{
	//					val = current;
	//					//return true;
	//					found = true;
	//					break;
	//				}
	//			}
	//	}
	//}

	//return found;
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::exists (const key & _key) const
{
	link * temp;

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
bool LIB::NAME_A <value, key>::Delete (const key & _key)
{
	link * target;
		
	if (search (_key, target))
	{
		value * element, * first;
		
		first = & (values -> _value);
		
		// Save the value of the element to be removed.
		element = & (target -> _value);
		
		// Start one position before the element to be removed (cannot remove self).
		target = target -> previous;
		
		// Remove the element (current -> next):
		target -> next = target -> next -> next;
		delete target -> next -> previous;
		
		-- _size;	// Update the _size.
		
		if (size () > 0)	// Only if there is something in the list, set the next element's previous value to the current.
			target -> next -> previous = target;
		
		if (element == first && size () > 0) // If it's the first element of the list which is being removed.
		{
			// Make the starting of the list point to the next valid element in the list.
			values = target -> next;
		}
		
		//if (size () > 0)
		//	start = target -> next -> element;	// Prepare for the next iteration (set the starting point to the next valid element).

		return true;
	}
	else
	{
		return false;
	}
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::rename (const key & current, const key & val)
{
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
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::empty (void) const
{
	return size () <= 0;
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::full (void) const
{
	//return !memory;
	return false;
}

// Prefix
template <typename value, typename key> 
//key LIB::NAME_A<value, key>::Next (void)
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator ++ (void)
{
	current_index = current_index -> next;
	//return current_index -> previous -> key;

	return *this;
}

template <typename value, typename key> 
//key LIB::NAME_A<value, key>::Previous (void)
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator -- (void)
{
	current_index = current_index -> previous;
	//return current_index -> next -> key;
	return *this;
}

// Postfix / Suffix
template <typename value, typename key> 
//key LIB::NAME_A<value, key>::Next (void)
LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator ++ (signed int val)
{
	//current_index = current_index -> next;
	NAME_A <value, key> temp (*this);

	++ (*this);

	return temp;
	//return current_index -> previous -> key;
}

template <typename value, typename key> 
//key LIB::NAME_A<value, key>::Previous (void)
LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator -- (signed int val)
{
	NAME_A <value, key> temp (*this);

	-- (*this);

	return temp;
}

//template <typename value, typename key> 
////key LIB::NAME_A<value, key>::Previous (void)
//void LIB::NAME_A <value, key>::operator -- (void)
//{
//	current_index = current_index -> previous;
//	//return current_index -> next -> key;
//}

template <typename value, typename key> 
key & LIB::NAME_A <value, key>::operator * (void) const
{
	//current_index = current_index -> previous;
	return current_key ();
}

template <typename value, typename key> 
key & LIB::NAME_A <value, key>::current_key (void) const
{
	if (empty ())
	{
		key k;
		
		return k;
	}
	else
	{
		//current_index = current_index -> previous;
		return current_index -> _key;
	}
}

template <typename value, typename key> 
value & LIB::NAME_A <value, key>::current (void) const
{
	if (empty ())
	{
		value v;
		
		return v;
	}
	else
	{
		//current_index = current_index -> previous;
		return current_index -> _value;
	}
}

//template <typename value, typename key> 
//key LIB::NAME_A <value, key>::operator top (void) const
//{
//	//current_index = current_index -> previous;
//	return current_index -> key;
//}

//template <typename value, typename key> 
//void LIB::NAME_A<value, key>::Set (LIB::Mathematics::Number::Natural index, bool loop)
//{
//	current_index = values;

//	if (!Empty ())
//	{
//		if (loop)
//		{
//			while (index -- > 0)
//			{
//				current_index = current_index -> next;
//			}
//		}
//		else
//		{
//			if (index > 0)
//				current_index = current_index -> next;

//			while (index -- > 0 && current_index != values)
//			{
//				current_index = current_index -> next;
//			}
//		}
//	}
//}

template <typename value, typename key> 
void LIB::NAME_A <value, key>::begin (void)
{
	current_index = values;
}

template <typename value, typename key> 
void LIB::NAME_A <value, key>::end (void)
{
	current_index = values -> previous;
}

template <typename value, typename key> 
LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (LIB::NAME_A <value, key> & val)
{
	//LIB::NAME_A <value, key>::Clear ();
	clear ();
	
	key _key;
	
	val.begin ();
	
	for (mathematics::numbers::natural index = val.size (); index > 0; -- index)
	//for (auto index : val)
	{
		try
		{
			//temp = boost::lexical_cast <key> (val.Next ());
			//temp = static_cast <key> (val.Next ());
			//temp = dynamic_cast <key> (val.Next ());
			//temp = reinterpret_cast <key> (val.Next ());
			//temp = (key) (val.Next ());
			
			_key = val.current_key ();
			
			//*this [temp] = boost::lexical_cast <value> (val [temp]);
			//*this [temp] = static_cast <value> (val [temp]);
			//*this [temp] = dynamic_cast <value> (val [temp]);
			//*this [temp] = reinterpret_cast <value> (val [temp]);
			//*this [temp] = (value) (val [temp]);
			//*this [temp] = val [temp];

			//*this [_key] = val [_key];
			operator [] (_key) = val.operator [] (_key);
		}
		catch (...)
		{
			break;
		}

		++ val;
	}
		
	return *this;
}
	
template <typename value, typename key> 
bool LIB::NAME_A <value, key>::operator == (const NAME_A & val)
{
	if (size () == val.size ())
	{
		key k1, k2;
		value v1, v2;
		//_size = size ();
			
		begin ();
		val.begin ();
			
		for (mathematics::numbers::natural index = 0; index < size (); ++ index)
		{
			k1 = current_key ();
			k2 = val.current_key ();
				
			if (! val.exists (k1))
				return false;
				
			try
			{
				//if (k1 != boost::lexical_cast <key> (k2))
				if (k1 != k2)
					return false;
					
				//if (*this [k1] != boost::lexical_cast <value> (val [k2]))
				if (*this [k1] != val [k2])
					return false;
			}
			catch (...)
			{
				return false;
			}
		}
			
		return true;
		//return false;
	}
	else
	{
		return false;
	}
		
	//return true;
}	


// Helper functions used by the queue and the stack functionality:

// Get the minimum value of any present keys which types are `LIB::mathematics::numbers::integer`.
template <typename value, typename key> 
LIB::mathematics::numbers::integer LIB::NAME_A <value, key>::minimum (void)
{
	LIB::mathematics::numbers::integer min = 0;

	if
	(
		!empty () && 
		(
			typeid (key) == typeid (signed short int) || 
			typeid (key) == typeid (unsigned short int) || 
			typeid (key) == typeid (signed int) || 
			typeid (key) == typeid (unsigned int) || 
			typeid (key) == typeid (signed long int) || 
			typeid (key) == typeid (unsigned long int) || 
			typeid (key) == typeid (signed long long int) || 
			typeid (key) == typeid (unsigned long long int)
			// || typeid (key) == typeid (LIB::NAME_V)
		)
	)
	{
		key the_key, * _key;

		begin ();

		the_key = current_key ();
		_key = & the_key;

		min = (* _key);

		++ (*this);
		//operator ++ ();

		// Get the key (as a reference).
		//_key = & ((* this) [value]);
		//the_key = current_key ();
		//_key = & the_key;

		for (mathematics::numbers::natural index = 1; index < size (); ++ index, ++ (*this))
		{
			if ((* _key) < min)
				min = (* _key);
		}
	}

	return min;
}

// Get the maximum value of any present keys which types are `LIB::mathematics::numbers::integer`.
template <typename value, typename key> 
LIB::mathematics::numbers::integer LIB::NAME_A <value, key>::maximum (void)
{

	LIB::mathematics::numbers::integer max = 0;

	if
	(
		!empty () && 
		(
			typeid (key) == typeid (signed short int) || 
			typeid (key) == typeid (unsigned short int) || 
			typeid (key) == typeid (signed int) || 
			typeid (key) == typeid (unsigned int) || 
			typeid (key) == typeid (signed long int) || 
			typeid (key) == typeid (unsigned long int) || 
			typeid (key) == typeid (signed long long int) || 
			typeid (key) == typeid (unsigned long long int)
			// || typeid (key) == typeid (LIB::NAME_V)
		)
	)
	{
		key /*the_key, */* _key;

		begin ();

		//the_key = current_key ();
		//_key = & the_key;
		_key = & current_key ();

		max = * _key;

		operator ++ ();

		// Get the key (as a reference).
		//_key = & ((* this) [value]);

		for (mathematics::numbers::natural index = 1; index < size (); ++ index, operator ++ ())
		{
			//the_key = current_key ();
			//_key = & the_key;
			
			_key = & current_key ();

			if ((* _key) > max)
				max = (* _key);

			//the_key = current_key ();
			//_key = & the_key;
		}
	}

	return max;
}


// Queue functionality:

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::enqueue (const value val)
{
	return push (val);
	//if
	//(
	//	typeid (key) == typeid (signed short int) || 
	//	typeid (key) == typeid (unsigned short int) || 
	//	typeid (key) == typeid (signed int) || 
	//	typeid (key) == typeid (unsigned int) || 
	//	typeid (key) == typeid (signed long int) || 
	//	typeid (key) == typeid (unsigned long int) || 
	//	typeid (key) == typeid (signed long long int) || 
	//	typeid (key) == typeid (unsigned long long int)
	//	// || typeid (key) == typeid (LIB::NAME_V)
	//)
	//{
	//	//std::cout << typeid (*this [maximum () + 1]).name () << std::endl;
	//	//std::cout << typeid (operator [] (maximum () + 1)).name () << std::endl;
	//	//*this [maximum () + 1] = val;
	//	operator [] (maximum () + 1) = val;

	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::dequeue (void)
{
	if (Delete (minimum ()))
	{
		// Decrement all the other integer keys (by 1) if the key has an appropriate operator:
		if
		(
			!empty () && 
			(
				typeid (key) == typeid (signed short int) || 
				typeid (key) == typeid (unsigned short int) || 
				typeid (key) == typeid (signed int) || 
				typeid (key) == typeid (unsigned int) || 
				typeid (key) == typeid (signed long int) || 
				typeid (key) == typeid (unsigned long int) || 
				typeid (key) == typeid (signed long long int) || 
				typeid (key) == typeid (unsigned long long int)
				// || typeid (key) == typeid (LIB::NAME_V)
			)
		)
		{
			key the_key/*, * _key*/;

			begin ();
			//the_key = current_key ();
			//_key = & the_key;

			for
			(
				mathematics::numbers::natural index = 0
				;
			
				index < size ()
				;
			
				++ index,
				operator ++ ()
			)
			{
				//the_key = current_key ();
				the_key = minimum ();
				//_key = & the_key;

				if (!rename (the_key, the_key - 1))
					return false;
				
				//-- (* _key);
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
		return false;

		//try
		//{
		//	++ ((* this) [value]);
		//}
		//catch (...)
		//{
		//	// Do not do anything.
		//}
/*
	switch (type)
	{
		case NAME_V:
			key _key;

			for (auto & value : * this)
			{
				_key = (* this) [value];
		/*
				try
				{
					++ ((* this) [value]);
				}
				catch (...)
				{
					// Do not do anything.
				}
		*/

				//if (typeid (_key))
//			}
//	}

}

template <typename value, typename key> 
key LIB::NAME_A <value, key>::front_key (void) const
{
	if (empty ())
	{
		key k;

		return k;
	}
	else
	{
		return values -> _key;
	}
}

template <typename value, typename key> 
value LIB::NAME_A <value, key>::front (void) const
{
	if (empty ())
	{
		value v;

		return v;
	}
	else
	{
		return values -> _value;
	}
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::push (const value _value)
{
	if
	(
		!full () && 
		(
			typeid (key) == typeid (signed short int) || 
			typeid (key) == typeid (unsigned short int) || 
			typeid (key) == typeid (signed int) || 
			typeid (key) == typeid (unsigned int) || 
			typeid (key) == typeid (signed long int) || 
			typeid (key) == typeid (unsigned long int) || 
			typeid (key) == typeid (signed long long int) || 
			typeid (key) == typeid (unsigned long long int)
			// || typeid (key) == typeid (LIB::NAME_V)
		)
	)
	{
		//*this [maximum () + 1] = _value;
		operator [] (maximum () + 1) = _value;

		return true;
	}
	else
	{
		return false;
	}
}

template <typename value, typename key> 
bool LIB::NAME_A <value, key>::pop (void)
{
	if
	(
		!empty () && 
		(
			typeid (key) == typeid (signed short int) || 
			typeid (key) == typeid (unsigned short int) || 
			typeid (key) == typeid (signed int) || 
			typeid (key) == typeid (unsigned int) || 
			typeid (key) == typeid (signed long int) || 
			typeid (key) == typeid (unsigned long int) || 
			typeid (key) == typeid (signed long long int) || 
			typeid (key) == typeid (unsigned long long int)
			// || typeid (key) == typeid (LIB::NAME_V)
		)
	)
	{
		return Delete (maximum ());
	}
	else
	{
		return false;
	}
}

template <typename value, typename key> 
key LIB::NAME_A <value, key>::top_key (void) const
{
	if (empty ())
	{
		key k;

		return k;
	}
	else
	{
		return values -> previous -> _key;
	}
}

template <typename value, typename key> 
value LIB::NAME_A <value, key>::top (void) const
{
	if (empty ())
	{
		value v;

		return v;
	}
	else
	{
		return values -> previous -> _value;
	}
}

//template <typename value, typename key> 
//bool LIB::NAME_A <value, key>::operator != (const NAME_A <value, key> & val)
//{
//	return !(*this == val);
//}	

//const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator  ++ (viod)
//{
//	Next ();
//}

//signed int LIB::NAME_A <value, key>::operator * () const
//{


template <typename value, typename key> 
key & LIB::NAME_A <value, key>::get_key (const LIB::mathematics::numbers::natural & index)
{
	//if (empty ())
	//{
	//	key k;

	//	return k;
	//}
	//else
	if (index < 1)
	{
		/*
			If the user specified an element beyond the number of minimum logical elements that can be present in the array,
			then return the first element.
		*/

		begin ();

		return current_key ();
	}
	else if (index > size ())
	{
		/*
			If the user specified an element beyond the number of current elements present in the array,
			then return the last element.
		*/

		end ();

		return current_key ();
	}
	// Start at the end closest to the element (index).
	else if (index <= size () / 2)
	{
		begin ();

		for (LIB::mathematics::numbers::natural i = 1; i < index; ++ i)
		{
			operator ++ ();
			//++ *this;
		}

		return current_key ();
	}
	else
	{
		LIB::mathematics::numbers::natural remainder = size () - index;

		end ();

		for (LIB::mathematics::numbers::natural i = 1; i <= remainder; ++ i)
		{
			operator -- ();
			//-- *this;
		}

		return current_key ();
	}
}

template <typename value, typename key> 
value & LIB::NAME_A <value, key>::get_value (const LIB::mathematics::numbers::natural & index)
{
	//key k = get_key (index);
	return operator [] (get_key (index));
	//return *this [const_cast <const key *> (k)];
}
