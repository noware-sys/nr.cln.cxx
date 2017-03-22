// operator <

const bool noware::number::operator < (const number & other) const
{
	return false;
}
/*
const bool noware::number::operator < (const text & other) const
{
	return *this < number (other);
}
*/
const bool noware::number::operator < (const std::string & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const char other []) const
{
	return *this < number (other);
}
/*
const bool noware::number::operator < (const char *& other) const
{
	return *this < number (other);
}
*/
const bool noware::number::operator < (const char & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const signed char & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const unsigned char & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::complex & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::real & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::rational & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::integer & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::_float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::short_float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::single_float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::double_float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const number::long_float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const long double & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const double & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const float & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const signed long long int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const unsigned long long int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const signed long int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const unsigned long int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const signed int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const unsigned int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const signed short int & other) const
{
	return *this < number (other);
}

const bool noware::number::operator < (const unsigned short int & other) const
{
	return *this < number (other);
}

