// operator +=

const noware::math::number noware::math::number::operator += (const number & other) const
{
	content += other.content;
	return *this;
}
/*
const noware::math::number noware::math::number::operator += (const text & other) const
{
	return *this += number (other);
}
*/
const noware::math::number noware::math::number::operator += (const std::string & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const char other []) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned char other []) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed char other []) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const char & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed char & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned char & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_N & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_RA & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_I & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_SF & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_FF & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_DF & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const cln::cl_LF & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const long double & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const double & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const float & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed long long int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned long long int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed long int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned long int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const signed short int & other) const
{
	return *this += number (other);
}

const noware::math::number noware::math::number::operator += (const unsigned short int & other) const
{
	return *this += number (other);
}

