// operator %=

const noware::nr noware::nr::operator %= (const nr & other)
{
	//return content.number %= other.content.number;
	return 0;
}
/*
const noware::nr noware::nr::operator %= (const text & other)
{
	return *this %= nr (other);
}
*/
const noware::nr noware::nr::operator %= (const std::string & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const char * other)
{
	*this %= nr (other);
	return *this;
}
/*
const noware::nr noware::nr::operator %= (const char *& other)
{
	return *this %= nr (other);
}
*/
const noware::nr noware::nr::operator %= (const char & other)
{
	*this %= nr (other);
	return *this;
}
/*
const noware::nr noware::nr::operator %= (const signed char & other)
{
	return *this %= nr (other);
}

const noware::nr noware::nr::operator %= (const unsigned char & other)
{
	return *this %= nr (other);
}
*/
//const noware::nr noware::nr::operator %= (const math::nr & other)
//{
//	return *this %= nr (other);
//}

const noware::nr noware::nr::operator %= (const complex & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const real & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const rational & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const integer & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const _float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const short_float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const single_float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const double_float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const long_float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const long double & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const double & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const float & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const signed long long int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const unsigned long long int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const signed long int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const unsigned long int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const signed int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const unsigned int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const signed short int & other)
{
	*this %= nr (other);
	return *this;
}

const noware::nr noware::nr::operator %= (const unsigned short int & other)
{
	*this %= nr (other);
	return *this;
}
