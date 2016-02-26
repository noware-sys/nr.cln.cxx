namespace LIB
{
	// Default constructor.
	template <typename type> 
	pointer <type>::pointer (void)
	{
		internal_pointer = NULL;

		// Create a new reference
		references = new mathemetics::numbers::natural;

		// Increment the reference count
		++ (*references);
	}
			
	template <typename type> 
	pointer <type>::pointer (const type * pointer)
	{
		internal_pointer = pointer;

		// Create a new reference
		references = new Mathemetics::Number::Natural;

		// Increment the reference count
		++ (*references);
	}

	// Copy constructor.
	template <typename type> 
	pointer <type>::pointer (const LIB::pointer & other)
	{
		// Copy the data and reference pointer

		// and increment the reference count
		++ (*references);
	}

	template <typename type> 
	pointer <type>::~pointer (void)
	{
		// Destructor
		// Decrement the reference count
		// if the number of references becomes zero delete the data
		if (-- (* references) <= 0)
		{
			delete internal_pointer;
			delete references;
		}
	}

	template <typename type> 
	type pointer <type>::operator & (void)
	{
		return internal_pointer;
	}

	template <typename type> 
	type & pointer <type>::operator * (void)
	{
		return * internal_pointer;
	}

	template <typename type> 
	type * pointer <type>::operator -> (void)
	{
		return internal_pointer;
	}

	template <typename type> 
	pointer <type> & pointer <type>::operator = (const pointer <type> & other)
	{
		// Assignment operator
		if (this != & other) // Avoid self assignment
		{
			// Decrement the old reference count
			// if the number of references becomes zero, then delete the old data
			if (-- (* reference) == 0)
			{
				delete internal_pointer;
				delete references;
			}

			// Copy the data and reference pointer
			// and increment the reference count
			internal_pointer = other.internal_pointer;
			references = internal_pointer.references;
			-- (reference);
		}

		return *this;
	}
}
