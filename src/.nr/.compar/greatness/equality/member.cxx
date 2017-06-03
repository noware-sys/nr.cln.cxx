// operator >=

const bool noware::nr::operator >= (const nr & other) const
{
	return false;
}
/*
const bool noware::nr::operator >= (const text & other) const
{
	return *this >= nr (other);
}
*/
const bool noware::nr::operator >= (const std::string & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const char other []) const
{
	return *this >= nr (other);
}
/*
const bool noware::nr::operator >= (const char *& other) const
{
	return *this >= nr (other);
}
*/
const bool noware::nr::operator >= (const char & other) const
{
	return *this >= nr (other);
}
/*
const bool noware::nr::operator >= (const signed char & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const unsigned char & other) const
{
	return *this >= nr (other);
}
*/
const bool noware::nr::operator >= (const nr::complex & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::real & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::rational & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::integer & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::_float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::short_float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::single_float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::double_float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const nr::long_float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const long double & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const double & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const float & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const signed long long int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const unsigned long long int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const signed long int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const unsigned long int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const signed int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const unsigned int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const signed short int & other) const
{
	return *this >= nr (other);
}

const bool noware::nr::operator >= (const unsigned short int & other) const
{
	return *this >= nr (other);
}

