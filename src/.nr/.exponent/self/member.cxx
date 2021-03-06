// operator ^=

cln::nr const cln::nr::operator ^= (nr const & other)
{
	//return content.number ^= other.content.number;
	val = expt (val, other.operator integer const ());
	//return 0;
	return *this;
}

cln::nr const cln::nr::operator ^= (std::string const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (char const * const other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (char const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (complex const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (real const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (rational const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (integer const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (_float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (short_float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (single_float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (double_float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (long_float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (long double const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (double const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (float const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (signed long long int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (unsigned long long int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (signed long int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (unsigned long int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (signed int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (unsigned int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (signed short int const & other)
{
	*this ^= nr (other);
	return *this;
}

cln::nr const cln::nr::operator ^= (unsigned short int const & other)
{
	*this ^= nr (other);
	return *this;
}
