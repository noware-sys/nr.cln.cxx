// constructors

noware::number::number (void)
{
	//_exact = true;
}

noware::number::number (const number & other)
{
	*this = other;
}
/*
noware::number::number (const noware::container::text & other)
{
	*this = other;
}
*/
noware::number::number (const std::string & other)
{
	*this = other;
}

noware::number::number (const char other [])
{
	//*this = std::string (other);
	*this = other;
}
/*
noware::number::number (const unsigned char other [])
{
	*this = other;
}

noware::number::number (const signed char other [])
{
	*this = other;
}
*/

/*
noware::number::number (const signed char other [])
{
	*this = std::string (other);
}

noware::number::number (const unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::number::number (const char *& other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::number::number (const signed char *& other)
{
	*this = std::string (other);
}

noware::number::number (const unsigned char *& other)
{
	*this = std::string (other);
}
*/
noware::number::number (const char & other)
{
	//*this = noware::tool::string (other);
	*this = other;
}

noware::number::number (const signed char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

noware::number::number (const unsigned char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

noware::number::number (const complex & other)
{
	*this = other;
}

noware::number::number (const real & other)
{
	*this = other;
}

noware::number::number (const rational & other)
{
	*this = other;
}

noware::number::number (const integer & other)
{
	*this = other;
}

noware::number::number (const _float & other)
{
	*this = other;
}

noware::number::number (const short_float & other)
{
	*this = other;
}

noware::number::number (const single_float & other)
{
	*this = other;
}

noware::number::number (const double_float & other)
{
	*this = other;
}

noware::number::number (const long_float & other)
{
	*this = other;
}

noware::number::number (const long double & other)
{
	*this = other;
}

noware::number::number (const double & other)
{
	*this = other;
}

noware::number::number (const float & other)
{
	*this = other;
}

noware::number::number (const signed long long int & other)
{
	*this = other;
}

noware::number::number (const unsigned long long int & other)
{
	*this = other;
}

noware::number::number (const signed long int & other)
{
	*this = other;
}

noware::number::number (const unsigned long int & other)
{
	*this = other;
}

noware::number::number (const signed int & other)
{
	*this = other;
}

noware::number::number (const unsigned int & other)
{
	*this = other;
}

noware::number::number (const signed short int & other)
{
	*this = other;
}

noware::number::number (const unsigned short int & other)
{
	*this = other;
}

