/*
	operator *type*
	
	conversion operator functions
*/
/*
noware::nr::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/
noware::nr::operator const std::string (void) const
{
	//if (content.t == container::type::numeric)
	//	//return noware::tool::complement (content.nr);
	//	return "";
	//else
	//	return content.text;
	std::stringstream ss;
	ss << contnt;
	return ss.str ();
}

//noware::nr::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}

noware::nr::operator const char (void) const
{
	//std::string str = std::string (*this);
	std::string str = operator const std::string ();
	
	if (str.size () == 1)
		return str [0];
	else
		return '\0';
}

noware::nr::operator const char * (void) const
{
	return operator const std::string ().c_str ();
}

//noware::nr::operator const nrs::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

noware::nr::operator const complex (void) const
{
	return contnt;
}

noware::nr::operator const real (void) const
{
	try
	{
		return cln::the <real> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const rational (void) const
{
	try
	{
		return cln::the <rational> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const integer (void) const
{
	try
	{
		return cln::the <integer> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const _float (void) const
{
	try
	{
		return cln::the <_float> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return _float (float (0));
}

noware::nr::operator const short_float (void) const
{
	try
	{
		return cln::the <short_float> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return short_float ("0");
}

noware::nr::operator const single_float (void) const
{
	try
	{
		return cln::the <single_float> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return single_float (float (0));
}

noware::nr::operator const double_float (void) const
{
	try
	{
		return cln::the <double_float> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return double_float (double (0));
}

noware::nr::operator const long_float (void) const
{
	try
	{
		return cln::the <long_float> (contnt);
	}
	catch (...)
	{
	}
	
	// A default value.
	return long_float ("0");
}

noware::nr::operator const long double (void) const
{
	return double (*this);
}

noware::nr::operator const double (void) const
{
	try
	{
		return cln::double_approx (cln::the <real> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const float (void) const
{
	try
	{
		return cln::float_approx (cln::the <real> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

/*
noware::nr::operator const signed long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const unsigned long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/

noware::nr::operator const signed long int (void) const
{
	try
	{
		return cln::cl_I_to_long (cln::the <integer> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const unsigned long int (void) const
{
	try
	{
		return cln::cl_I_to_ulong (cln::the <integer> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const signed int (void) const
{
	try
	{
		return cln::cl_I_to_int (cln::the <integer> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

noware::nr::operator const unsigned int (void) const
{
	try
	{
		return cln::cl_I_to_uint (cln::the <integer> (contnt));
	}
	catch (...)
	{
	}
	
	// A default value.
	return 0;
}

/*
noware::nr::operator const signed short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const unsigned short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/
/*
noware::nr::operator const bool (void) const
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
