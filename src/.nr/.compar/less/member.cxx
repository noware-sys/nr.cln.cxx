// operator <

const bool cln::nr::operator < (const nr & other) const
{
	// for now, ignore the imaginary part
	//return false;
	return realpart (val) < realpart (other.val);
}
/*
const bool cln::nr::operator < (const text & other) const
{
	return *this < nr (other);
}
*/
const bool cln::nr::operator < (const std::string & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (char const * const other) const
{
	return *this < nr (other);
}
/*
const bool cln::nr::operator < (const char *& other) const
{
	return *this < nr (other);
}
*/
const bool cln::nr::operator < (const char & other) const
{
	return *this < nr (other);
}
/*
const bool cln::nr::operator < (const signed char & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const unsigned char & other) const
{
	return *this < nr (other);
}
*/
const bool cln::nr::operator < (const complex & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const real & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const rational & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const integer & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const _float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const short_float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const single_float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const double_float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const long_float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const long double & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const double & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const float & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const signed long long int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const unsigned long long int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const signed long int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const unsigned long int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const signed int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const unsigned int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const signed short int & other) const
{
	return *this < nr (other);
}

const bool cln::nr::operator < (const unsigned short int & other) const
{
	return *this < nr (other);
}
