/*
	constructors
*/

noware::var::var (void)
{
	t = type::txt;
}

noware::var::var (const var & other)
{
	*this = other;
}
/*
noware::any::any (const noware::container::text & other)
{
	*this = other;
}
*/
noware::var::var (const std::string & other)
{
	*this = other;
}

noware::var::var (const char other [])
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
noware::var::var (const char & other)
{
	*this = noware::string (other);
}
/*
noware::var::var (const signed char & other)
{
	*this = noware::tool::string (char (other));
}

noware::any::any (const unsigned char & other)
{
	*this = noware::tool::string (char (other));
}
*/
noware::var::var (const noware::nr & other)
{
	*this = other;
}

noware::any::any (const long double & other)
{
	*this = noware::nr (other);
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

noware::var::var (const bool & other)
{
	*this = other;
}
/*
const noware::any::container::type & noware::any::type (void) const
{
	return content.t;
}
*/
