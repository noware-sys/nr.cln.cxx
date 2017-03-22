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
		return "";
	//else
	//	return content.text;
}

//noware::nr::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}
//
//noware::nr::operator const char * (void) const
//{
//	return std::string (*this).c_str ();
//}

//noware::nr::operator const nrs::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

noware::nr::operator const long double (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const double (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const float (void) const
{
	//if (content.t == container::type::numeric)
	//	return float_approx (content);
	//else
		return 0;	// A default value.
}

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

noware::nr::operator const signed long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const unsigned long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const signed int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::nr::operator const unsigned int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

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

