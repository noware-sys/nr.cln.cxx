// operator +=

const noware::nr noware::nr::operator += (const nr & other)
{
	content += other.content;
	return *this;
}
/*
const noware::nr noware::nr::operator += (const text & other)
{
	return *this += nr (other);
}
*/
const noware::nr noware::nr::operator += (const std::string & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const char other [])
{
	return *this += nr (other);
}
/*
const noware::nr noware::nr::operator += (const unsigned char other [])
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const signed char other [])
{
	return *this += nr (other);
}
*/
const noware::nr noware::nr::operator += (const char & other)
{
	return *this += nr (other);
}
/*
const noware::nr noware::nr::operator += (const signed char & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const unsigned char & other)
{
	return *this += nr (other);
}
*/
const noware::nr noware::nr::operator += (const cln::cl_N & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_RA & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_I & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_SF & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_FF & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_DF & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const cln::cl_LF & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const long double & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const double & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const float & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const signed long long int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const unsigned long long int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const signed long int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const unsigned long int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const signed int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const unsigned int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const signed short int & other)
{
	return *this += nr (other);
}

const noware::nr noware::nr::operator += (const unsigned short int & other)
{
	return *this += nr (other);
}

