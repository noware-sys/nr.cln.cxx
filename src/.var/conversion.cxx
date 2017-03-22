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
noware::any::operator const std::string (void) const
{
	if (content.t == container::type::numeric)
	{
		//return noware::tool::complement (content.number);
		std::stringstream ss;
		ss << content.number;
		return ss.str ();
		//return "";
	}
	else
		return content.text;
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

noware::any::operator const number (void) const
{
	if (content.t == container::type::numeric)
		return content.number;
	else
		return 0;	// A default value.
}
/*
noware::any::operator const math::numbers::natural (void) const
{
	if (content.t == container::type::numeric)
		return floor1 (content.number);
	else
		return 0;	// A default value.
}
*/
noware::any::operator const long double (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const double (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const float (void) const
{
	if (content.t == container::type::numeric)
		//return float_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const signed long long int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const unsigned long long int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const signed long int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const unsigned long int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const signed int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const unsigned int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const signed short int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const unsigned short int (void) const
{
	if (content.t == container::type::numeric)
		//return double_approx (content.number);
		return 0;
	else
		return 0;	// A default value.
}

noware::any::operator const bool (void) const
{
	//std::cout << "noware::var::operator const bool() const::called" << std::endl;
	
	if (content.t == container::type::numeric)
	{
		//std::cout << "noware::var::operator const bool() const::content.number != 0==[" << (content.number != 0) << ']' << std::endl;
		return content.number != 0;
	}
	else
	{
		return content.text.length () != 0;
	}
}
