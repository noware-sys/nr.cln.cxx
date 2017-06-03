/*
	operator *type*
	
	conversion operator functions
*/
/*
noware::var::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/

noware::var::operator const noware::nr (void) const
{
	return nr;
}

noware::var::operator const std::string (void) const
{
	if (t == type::nr)
		return nr;
	else
		return txt;
}

//noware::var::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}

/*
noware::var::operator const char * (void) const
{
	return operator const std::string ().c_str ();
}

noware::var::operator const char (void) const
{
	//std::string str = std::string (*this);
	std::string str = operator const std::string ();
	
	if (str.size () == 1)
		return str [0];
	else
		return '\0';
}
*/

//noware::var::operator const nrs::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

noware::var::operator const complex (void) const
{
	return nr;
}

noware::var::operator const real (void) const
{
	return nr;
}

noware::var::operator const rational (void) const
{
	return nr;
}

noware::var::operator const integer (void) const
{
	return nr;
}

noware::var::operator const _float (void) const
{
	return nr;
}

noware::var::operator const short_float (void) const
{
	return nr;
}

noware::var::operator const single_float (void) const
{
	return nr;
}

noware::var::operator const double_float (void) const
{
	return nr;
}

noware::var::operator const long_float (void) const
{
	return nr;
}

noware::var::operator const long double (void) const
{
	return nr;
}

noware::var::operator const double (void) const
{
	return nr;
}

noware::var::operator const float (void) const
{
	return nr;
}

/*
noware::var::operator const signed long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::var::operator const unsigned long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/

noware::var::operator const signed long int (void) const
{
	return nr;
}

noware::var::operator const unsigned long int (void) const
{
	return nr;
}

noware::var::operator const signed int (void) const
{
	return nr;
}

noware::var::operator const unsigned int (void) const
{
	return nr;
}

/*
noware::var::operator const signed short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::var::operator const unsigned short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/
/*
noware::var::operator const bool (void) const
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
