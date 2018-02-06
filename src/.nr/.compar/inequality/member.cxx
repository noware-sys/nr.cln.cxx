// operator !=

const bool noware::nr::operator != (const nr & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const text & other) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (const std::string & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (char other const * const) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const unsigned char other []) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed char other []) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (const char & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const signed char & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned char & other) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (complex const & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (real const & other) const
{
	return content != other;
}
*/
const bool noware::nr::operator != (rational const & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (integer const & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (_float const & other) const
{
	return content != other;
}
*/
const bool noware::nr::operator != (short_float const & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (single_float const & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (double_float const & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (long_float const & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const long double & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const double & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const float & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed long long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned long long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed short int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned short int & other) const
{
	return !(*this == other);
}
