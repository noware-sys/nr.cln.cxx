/*
	constructors
*/

//noware::any::any (void)
//{
//}

noware::any::any (const any & other)
{
	*this = other;
}
/*
noware::any::any (const noware::container::text & other)
{
	*this = other;
}
*/
noware::any::any (const std::string & other)
{
	*this = other;
}

noware::any::any (const char other [])
{
	*this = std::string (other);
}
/*
noware::any::any (const signed char other [])
{
	*this = std::string (other);
}

noware::any::any (const unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::any::any (const char *& other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::any::any (const signed char *& other)
{
	*this = std::string (other);
}

noware::any::any (const unsigned char *& other)
{
	*this = std::string (other);
}
*/
noware::any::any (const char & other)
{
	*this = noware::tool::string (other);
}

noware::any::any (const signed char & other)
{
	*this = noware::tool::string (char (other));
}

noware::any::any (const unsigned char & other)
{
	*this = noware::tool::string (char (other));
}

noware::any::any (const nr & other)
{
	*this = other;
}

noware::any::any (const long double & other)
{
	*this = other;
}

noware::any::any (const double & other)
{
	*this = other;
}

noware::any::any (const float & other)
{
	*this = other;
}

noware::any::any (const signed long long int & other)
{
	*this = other;
}

noware::any::any (const unsigned long long int & other)
{
	*this = other;
}

noware::any::any (const signed long int & other)
{
	*this = other;
}

noware::any::any (const unsigned long int & other)
{
	*this = other;
}

noware::any::any (const signed int & other)
{
	*this = other;
}

noware::any::any (const unsigned int & other)
{
	*this = other;
}

noware::any::any (const signed short int & other)
{
	*this = other;
}

noware::any::any (const unsigned short int & other)
{
	*this = other;
}

noware::any::any (const bool & other)
{
	*this = other;
}

const noware::any::container::type & noware::any::type (void) const
{
	return content.t;
}

