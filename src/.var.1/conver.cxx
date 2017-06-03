/*
	operator *type*
	
	conversion operator functions
*/
/*
noware::any::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/
/*
const std::string noware::var::to_text (void) const
{
	if (_t == t::nr)
	{
		//return noware::tool::complement (content.number);
		std::stringstream ss;
		ss << nr;
		return ss.str ();
		//return "";
	}
	else
		return text;
}

const noware::nr noware::var::to_nr (void) const
{
	//return noware::nr (long double (*this));
	if (_t == t::nr)
		return nr;
	else
		return 0;	// A default value.
}

const long double noware::var::to_long_double (void) const
{
	return (long double) *this;
}

const double noware::var::to_double (void) const
{
	return (double) *this;
}

const float noware::var::to_float (void) const
{
	return (float) *this;
}

const signed long long int noware::var::to_signed_long_long_int (void) const
{
	return (signed long long int) *this;
}

const unsigned long long int noware::var::to_unsigned_long_long_int (void) const
{
	return (unsigned long long int) *this;
}

const signed long int noware::var::to_signed_long_int (void) const
{
	return (signed long int) *this;
}

const unsigned long int noware::var::to_unsigned_long_int (void) const
{
	return (unsigned long int) *this;
}

const signed int noware::var::to_signed_int (void) const
{
	return (signed int) *this;
}

const unsigned int noware::var::to_unsigned_int (void) const
{
	return (unsigned int) *this;
}

const signed short int noware::var::to_signed_short_int (void) const
{
	return (signed short int) *this;
}

const unsigned short int noware::var::to_unsigned_short_int (void) const
{
	return (unsigned short int) *this;
}

const bool noware::var::to_bool (void) const
{
	return (bool) *this;
}
*/

noware::var::operator const std::string (void) const
{
	if (t == type::nr)
	{
		//return noware::tool::complement (content.number);
		/*
		std::stringstream ss;
		ss << nr;
		return ss.str ();
		*/
		return std::string (nr);
		//return "";
	}
	else
		return txt;
}

//noware::any::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}
//
//noware::any::operator const char * (void) const
//{
//	return std::string (*this).c_str ();
//}

noware::var::operator const noware::nr (void) const
{
	if (t == type::nr)
		return nr;
	else
		// A default value.
		return 0;
}
/*
noware::any::operator const math::numbers::natural (void) const
{
	if (content.t == container::type::numeric)
		return floor1 (content.nr);
	else
		return 0;	// A default value.
}
*/
noware::any::operator const long double (void) const
{
	if (t == type::nr)
		//return double_approx (nr);
		return long double (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const double (void) const
{
	if (t == type::nr)
		//return double_approx (nr);
		return double (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const float (void) const
{
	if (t == type::nr)
		//return float_approx (nr);
		return float (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const signed long long int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return signed long long int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const unsigned long long int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return unsigned long long int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const signed long int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return signed long int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const unsigned long int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return unsigned long int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const signed int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return signed int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const unsigned int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return unsigned int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const signed short int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return signed short int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const unsigned short int (void) const
{
	if (t == type::nr)
		//return double_approx (content.number);
		return unsigned short int (nr);
		//return 0;
	else
		return 0;	// A default value.
}

noware::var::operator const bool (void) const
{
	//std::cout << "noware::var::operator const bool() const::called" << std::endl;
	
	if (t == type::nr)
	{
		//std::cout << "noware::var::operator const bool() const::content.number != 0==[" << (content.number != 0) << ']' << std::endl;
		return nr != 0;
	}
	else
	{
		return txt == "true";
		//return txt.size () != 0;
	}
}
