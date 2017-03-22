// operator +=

const noware::number noware::number::operator += (const number & other)
{
	content += other.content;
	return *this;
}
/*
const noware::number noware::number::operator += (const text & other)
{
	return *this += number (other);
}
*/
const noware::number noware::number::operator += (const std::string & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const char other [])
{
	return *this += number (other);
}
/*
const noware::number noware::number::operator += (const unsigned char other [])
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const signed char other [])
{
	return *this += number (other);
}
*/
const noware::number noware::number::operator += (const char & other)
{
	return *this += number (other);
}
/*
const noware::number noware::number::operator += (const signed char & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const unsigned char & other)
{
	return *this += number (other);
}
*/
const noware::number noware::number::operator += (const cln::cl_N & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_RA & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_I & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_SF & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_FF & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_DF & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const cln::cl_LF & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const long double & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const double & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const float & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const signed long long int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const unsigned long long int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const signed long int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const unsigned long int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const signed int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const unsigned int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const signed short int & other)
{
	return *this += number (other);
}

const noware::number noware::number::operator += (const unsigned short int & other)
{
	return *this += number (other);
}

