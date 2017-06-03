// operator *=

const noware::nr noware::nr::operator *= (const nr & other)
{
	contnt *= other.contnt;
	return *this;
}
const noware::nr noware::nr::operator *= (const std::string & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const char * other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const char & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const complex & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const real & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const rational & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const integer & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const _float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const short_float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const single_float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const double_float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const long_float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const long double & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const double & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const float & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const signed long long int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const unsigned long long int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const signed long int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const unsigned long int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const signed int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const unsigned int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const signed short int & other)
{
	return *this *= nr (other);
}

const noware::nr noware::nr::operator *= (const unsigned short int & other)
{
	return *this *= nr (other);
}
