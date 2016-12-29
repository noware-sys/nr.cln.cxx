/*
	operator *type*
	
	conversion operator functions
*/
/*
noware::number::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/
noware::number::operator const std::string (void) const
{
	//if (content.t == container::type::numeric)
	//	//return noware::tool::complement (content.number);
		return "";
	//else
	//	return content.text;
}

//noware::number::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}
//
//noware::number::operator const char * (void) const
//{
//	return std::string (*this).c_str ();
//}

//noware::number::operator const numbers::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

noware::number::operator const long double (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const double (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const float (void) const
{
	//if (content.t == container::type::numeric)
	//	return float_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const signed long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const unsigned long long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const signed long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const unsigned long int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const signed int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const unsigned int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const signed short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::number::operator const unsigned short int (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
/*
noware::number::operator const bool (void) const
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

