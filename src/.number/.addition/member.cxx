// operator +

const noware::number noware::number::operator + (const number & other) const
{
	number tmp;
	tmp.content = content + other.content;
	return tmp;
}
/*
const noware::number noware::number::operator + (const text & other) const
{
	return *this + number (other);
}
*/
const noware::number noware::number::operator + (const std::string & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const char other []) const
{
	return *this + number (other);
}
/*
const noware::number noware::number::operator + (const unsigned char other []) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed char other []) const
{
	return *this + number (other);
}
*/
const noware::number noware::number::operator + (const char & other) const
{
	return *this + number (other);
}
/*
const noware::number noware::number::operator + (const unsigned char & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed char & other) const
{
	return *this + number (other);
}
*/
/*
const noware::number noware::number::operator + (const signed char & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const unsigned char & other) const
{
	return *this + number (other);
}
*/
/*const noware::number noware::number::operator + (const number & other) const
{
	return *this + number (other);
}
*/
const noware::number noware::number::operator + (const long double & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const double & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const float & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed long long int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const unsigned long long int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed long int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const unsigned long int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const unsigned int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const signed short int & other) const
{
	return *this + number (other);
}

const noware::number noware::number::operator + (const unsigned short int & other) const
{
	return *this + number (other);
}

