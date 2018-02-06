// operator ==

bool const cln::nr::operator == (nr const & other) const
{
	return val == other.val;
}
/*
bool const cln::nr::operator == (text const & other) const
{
	return *this == nr (other);
}
*/
bool const cln::nr::operator == (std::string const & other) const
{
	return *this == nr (other);
	//return val == nr (other);
}

bool const cln::nr::operator == (char const * const other) const
{
	return *this == nr (other);
	//return val == nr (other);
}
/*
bool const cln::nr::operator == (unsigned char other []) const
{
	//return *this == nr (other);
	return val == nr (other);
}

bool const cln::nr::operator == (signed char other []) const
{
	//return *this == nr (other);
	return val == nr (other);
}
*/
//bool const cln::nr::operator == (char const * const other) const
//{
//	return *this == nr (other);
//}

bool const cln::nr::operator == (char const & other) const
{
	return *this == nr (other);
}
/*
bool const cln::nr::operator == (signed char const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (unsigned char const & other) const
{
	return *this == nr (other);
}
*/

bool const cln::nr::operator == (complex const & other) const
{
	return *this == nr (other);
}


bool const cln::nr::operator == (real const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (rational const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (integer const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (_float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (short_float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (single_float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (double_float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (long_float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (long double const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (double const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (float const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (signed long long int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (unsigned long long int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (signed long int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (unsigned long int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (signed int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (unsigned int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (signed short int const & other) const
{
	return *this == nr (other);
}

bool const cln::nr::operator == (unsigned short int const & other) const
{
	return *this == nr (other);
}
