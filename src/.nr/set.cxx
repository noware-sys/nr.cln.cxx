// operator =

cln::nr const & cln::nr::operator = (nr const & other)
{
	val = other.val;
	
	return *this;
}
/*
cln::nr const & cln::nr::operator = (text const & other)
{
	contnt.text = other;
	contnt.nr = 0;
	
	contnt.t = container::type::generic;
	
	return *this;
}
*/
cln::nr const & cln::nr::operator = (std::string const & other)
{
	try
	{
		val = other.data ();
	}
	catch (...)
	{
	}
	
	return *this;
}

cln::nr const & cln::nr::operator = (char const * const other)
{
	try
	{
		val = other;
	}
	catch (...)
	{
	}
	
	return *this;
}
/*
cln::nr const & cln::nr::operator = (unsigned char const other [])
{
	val = cln::cl_N (other);
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed char const other [])
{
	val = cln::cl_N (other);
	
	return *this;
}
*/
/*
cln::nr const & cln::nr::operator = (signed char const other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned char const other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
cln::nr const & cln::nr::operator = ( char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}
*/

cln::nr const & cln::nr::operator = (char const & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		val = noware::string (other).data ();
	}
	catch (...)
	{
	}
	
	return *this;
}
/*
cln::nr const & cln::nr::operator = (signed char const & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned char const & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}
*/
cln::nr const & cln::nr::operator = (complex const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (real const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (rational const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (integer const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (_float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (short_float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (single_float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (double_float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (long_float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (long double const & other)
{
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (double const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (float const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed long long int const & other)
{
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned long long int const & other)
{
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed long int const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned long int const & other)
{
	val = other;
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed int const & other)
{
	//val = signed long int (other);
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned int const & other)
{
	//val = unsigned long int (other);
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (signed short int const & other)
{
	val = noware::string (other).data ();
	
	return *this;
}

cln::nr const & cln::nr::operator = (unsigned short int const & other)
{
	val = noware::string (other).data ();
	
	return *this;
}
