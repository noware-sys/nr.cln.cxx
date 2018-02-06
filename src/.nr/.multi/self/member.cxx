// operator *=

cln::nr const cln::nr::operator *= (nr const & other)
{
	val *= other.val;
	return *this;
}
cln::nr const cln::nr::operator *= (std::string const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (char const * const other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (char const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (complex const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (real const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (rational const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (integer const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (_float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (short_float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (single_float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (double_float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (long_float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (long double const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (double const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (float const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (signed long long int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (unsigned long long int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (signed long int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (unsigned long int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (signed int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (unsigned int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (signed short int const & other)
{
	return *this *= nr (other);
}

cln::nr const cln::nr::operator *= (unsigned short int const & other)
{
	return *this *= nr (other);
}
