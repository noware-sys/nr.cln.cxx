// constructors

noware::nr::nr (void)
{
	//_exact = true;
}

noware::nr::nr (const noware::nr & other)
{
	*this = other;
}
/*
noware::nr::nr (const noware::container::text & other)
{
	*this = other;
}
*/
noware::nr::nr (const std::string & other)
{
	*this = other;
}

noware::nr::nr (const char * other)
{
	//*this = std::string (other);
	*this = other;
}
/*
noware::nr::nr (const unsigned char other [])
{
	*this = other;
}

noware::nr::nr (const signed char other [])
{
	*this = other;
}
*/

/*
noware::nr::nr (const signed char other [])
{
	*this = std::string (other);
}

noware::nr::nr (const unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::nr::nr (const char *& other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::nr::nr (const signed char *& other)
{
	*this = std::string (other);
}

noware::nr::nr (const unsigned char *& other)
{
	*this = std::string (other);
}
*/
noware::nr::nr (const char & other)
{
	//*this = noware::tool::string (other);
	*this = other;
}
/*
noware::nr::nr (const signed char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

noware::nr::nr (const unsigned char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}
*/
noware::nr::nr (const complex & other)
{
	*this = other;
}

noware::nr::nr (const real & other)
{
	*this = other;
}

noware::nr::nr (const rational & other)
{
	*this = other;
}

noware::nr::nr (const integer & other)
{
	*this = other;
}

noware::nr::nr (const _float & other)
{
	*this = other;
}

noware::nr::nr (const short_float & other)
{
	*this = other;
}

noware::nr::nr (const single_float & other)
{
	*this = other;
}

noware::nr::nr (const double_float & other)
{
	*this = other;
}

noware::nr::nr (const long_float & other)
{
	*this = other;
}

noware::nr::nr (const long double & other)
{
	*this = other;
}

noware::nr::nr (const double & other)
{
	*this = other;
}

noware::nr::nr (const float & other)
{
	*this = other;
}

noware::nr::nr (const unsigned long long int & other)
{
	*this = other;
}

noware::nr::nr (const unsigned long int & other)
{
	*this = other;
}

noware::nr::nr (const unsigned int & other)
{
	*this = other;
}

noware::nr::nr (const unsigned short int & other)
{
	*this = other;
}

noware::nr::nr (const signed long long int & other)
{
	*this = other;
}

noware::nr::nr (const signed long int & other)
{
	*this = other;
}

noware::nr::nr (const signed int & other)
{
	*this = other;
}

noware::nr::nr (const signed short int & other)
{
	*this = other;
}
