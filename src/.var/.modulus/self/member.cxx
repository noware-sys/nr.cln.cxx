// operator %=

const noware::nr noware::nr::operator %= (const nr & other) const
{
	//return content.number %= other.content.number;
	return 0;
}
/*
const noware::nr noware::nr::operator %= (const text & other) const
{
	return *this %= nr (other);
}
*/
const noware::nr noware::nr::operator %= (const std::string & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const char other []) const
{
	return *this %= nr (other);
}
/*
const noware::nr noware::nr::operator %= (const char *& other) const
{
	return *this %= nr (other);
}
*/
const noware::nr noware::nr::operator %= (const char & other) const
{
	return *this %= nr (other);
}
/*
const noware::nr noware::nr::operator %= (const signed char & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned char & other) const
{
	return *this %= nr (other);
}
*/
//const noware::nr noware::nr::operator %= (const math::nr & other) const
//{
//	return *this %= nr (other);
//}

const noware::nr noware::nr::operator %= (const long double & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const double & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const float & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const signed long long int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned long long int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const signed long int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned long int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const signed int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const signed short int & other) const
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned short int & other) const
{
	return *this %= nr (other);
}

