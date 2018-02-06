/*
	operator *type*
	
	conversion operator functions
*/
/*
cln::nr::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/
cln::nr::operator std::string const (void) const
{
	//if (content.t == container::type::numeric)
	//	//return noware::tool::complement (content.nr);
	//	return "";
	//else
	//	return content.text;
	std::stringstream ss;
	ss << val;
	return ss.str ();
}

//cln::nr::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}

cln::nr::operator char const (void) const
{
	//std::string str = std::string (*this);
	std::string const str = operator std::string const ();
	
	if (str.size () == 1)
		return str [0];
	else
		return '\0';
}

cln::nr::operator char const * const (void) const
{
	return operator std::string const ().data ();
}

//cln::nr::operator const nrs::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

cln::nr::operator complex const (void) const
{
	return val;
}

cln::nr::operator real const (void) const
{
	try
	{
		return cln::the <real> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator rational const (void) const
{
	try
	{
		return cln::the <rational> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator integer const (void) const
{
	try
	{
		return cln::the <integer> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator _float const (void) const
{
	try
	{
		return cln::the <_float> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	//return 0;
	return _float (float (0));
}

cln::nr::operator short_float const (void) const
{
	try
	{
		return cln::the <short_float> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	//return 0;
	return short_float ("0");
}

cln::nr::operator single_float const (void) const
{
	try
	{
		return cln::the <single_float> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	//return 0;
	return single_float (float (0));
}

cln::nr::operator double_float const (void) const
{
	try
	{
		return cln::the <double_float> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	//return 0;
	return double_float (double (0));
}

cln::nr::operator long_float const (void) const
{
	try
	{
		return cln::the <long_float> (val);
	}
	catch (...)
	{
	}
	
	// A default value.
	//return 0;
	return long_float ("0");
}

/*
cln::nr::operator long double const (void) const
{
	return double (*this);
}
*/

cln::nr::operator double const (void) const
{
	try
	{
		return cln::double_approx (cln::the <real> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator float const (void) const
{
	try
	{
		return cln::float_approx (cln::the <real> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

/*
cln::nr::operator signed long long int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

cln::nr::operator unsigned long long int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/

cln::nr::operator signed long int const (void) const
{
	try
	{
		return cln::cl_I_to_long (cln::the <integer> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator unsigned long int const (void) const
{
	try
	{
		return cln::cl_I_to_ulong (cln::the <integer> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator signed int const (void) const
{
	try
	{
		return cln::cl_I_to_int (cln::the <integer> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

cln::nr::operator unsigned int const (void) const
{
	try
	{
		return cln::cl_I_to_uint (cln::the <integer> (val));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

/*
cln::nr::operator signed short int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

cln::nr::operator unsigned short int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/
/*
cln::nr::operator bool const (void) const
{
	if (content.t == container::type::numeric)
	{
		return content.number != 0;
	}
	else
	{
		return content.text.length () != 0;
	}
}
*/
