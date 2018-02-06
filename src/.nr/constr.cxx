// constructors

cln::nr::nr (void)
{
	//_exact = true;
}

cln::nr::nr (cln::nr const & other)
{
	*this = other;
}
/*
cln::nr::nr (noware::container::text const & other)
{
	*this = other;
}
*/
cln::nr::nr (std::string const & other)
{
	*this = other;
}

cln::nr::nr (char const other [])
{
	//*this = std::string (other);
	*this = other;
}
/*
cln::nr::nr (unsigned char other [])
{
	*this = other;
}

cln::nr::nr (signed char other [])
{
	*this = other;
}
*/

/*
cln::nr::nr (signed char other [])
{
	*this = std::string (other);
}

cln::nr::nr (unsigned char other [])
{
	*this = std::string (other);
}
*/
//cln::nr::nr (char *const & other)
//{
//	*this = noware::tool::string (other);
//}
/*
cln::nr::nr (signed char *const & other)
{
	*this = std::string (other);
}

cln::nr::nr (unsigned char *const & other)
{
	*this = std::string (other);
}
*/
cln::nr::nr (char const & other)
{
	//*this = noware::tool::string (other);
	*this = other;
}
/*
cln::nr::nr (signed char const & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

cln::nr::nr (unsigned char const & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}
*/
cln::nr::nr (complex const & other)
{
	*this = other;
}

cln::nr::nr (real const & other)
{
	*this = other;
}

cln::nr::nr (rational const & other)
{
	*this = other;
}

cln::nr::nr (integer const & other)
{
	*this = other;
}

cln::nr::nr (_float const & other)
{
	*this = other;
}

cln::nr::nr (short_float const & other)
{
	*this = other;
}

cln::nr::nr (single_float const & other)
{
	*this = other;
}

cln::nr::nr (double_float const & other)
{
	*this = other;
}

cln::nr::nr (long_float const & other)
{
	*this = other;
}

cln::nr::nr (long double const & other)
{
	*this = other;
}

cln::nr::nr (double const & other)
{
	*this = other;
}

cln::nr::nr (float const & other)
{
	*this = other;
}

cln::nr::nr (unsigned long long int const & other)
{
	*this = other;
}

cln::nr::nr (unsigned long int const & other)
{
	*this = other;
}

cln::nr::nr (unsigned int const & other)
{
	*this = other;
}

cln::nr::nr (unsigned short int const & other)
{
	*this = other;
}

cln::nr::nr (signed long long int const & other)
{
	*this = other;
}

cln::nr::nr (signed long int const & other)
{
	*this = other;
}

cln::nr::nr (signed int const & other)
{
	*this = other;
}

cln::nr::nr (signed short int const & other)
{
	*this = other;
}
