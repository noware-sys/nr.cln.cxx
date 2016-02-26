/*
	constructors
*/

//noware::container::any::any (void)
//{
//}

noware::container::any::any (const any & other)
{
	*this = other;
}
/*
noware::container::any::any (const noware::container::text & other)
{
	*this = other;
}
*/
noware::container::any::any (const std::string & other)
{
	*this = other;
}

noware::container::any::any (const char other [])
{
	*this = std::string (other);
}
/*
noware::container::any::any (const signed char other [])
{
	*this = std::string (other);
}

noware::container::any::any (const unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::container::any::any (const char *& other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::container::any::any (const signed char *& other)
{
	*this = std::string (other);
}

noware::container::any::any (const unsigned char *& other)
{
	*this = std::string (other);
}
*/
noware::container::any::any (const char & other)
{
	*this = noware::tool::string (other);
}

noware::container::any::any (const signed char & other)
{
	*this = noware::tool::string (char (other));
}

noware::container::any::any (const unsigned char & other)
{
	*this = noware::tool::string (char (other));
}

noware::container::any::any (const math::number & other)
{
	*this = other;
}

noware::container::any::any (const long double & other)
{
	*this = other;
}

noware::container::any::any (const double & other)
{
	*this = other;
}

noware::container::any::any (const float & other)
{
	*this = other;
}

noware::container::any::any (const signed long long int & other)
{
	*this = other;
}

noware::container::any::any (const unsigned long long int & other)
{
	*this = other;
}

noware::container::any::any (const signed long int & other)
{
	*this = other;
}

noware::container::any::any (const unsigned long int & other)
{
	*this = other;
}

noware::container::any::any (const signed int & other)
{
	*this = other;
}

noware::container::any::any (const unsigned int & other)
{
	*this = other;
}

noware::container::any::any (const signed short int & other)
{
	*this = other;
}

noware::container::any::any (const unsigned short int & other)
{
	*this = other;
}

noware::container::any::any (const bool & other)
{
	*this = other;
}

const noware::container::any::container::type & noware::container::any::type (void) const
{
	return content.t;
}


