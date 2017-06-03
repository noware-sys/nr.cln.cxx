// operator +=

const noware::var & noware::var::operator += (const var & other)
{
	//contnt += other.contnt;
	if (t == type::nr && other.t == type::nr)
	{
		nr += other.nr;
	}
	else //if (t == type::txt || other.t == type::txt)
	{
		txt = operator const std::string () + other.operator const std::string ();
		t = type::txt;
	}
	
	return *this;
}

const noware::var & noware::var::operator += (const noware::nr & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const char other [])
{
	*this += var (other);
	return *this;
}

/*
const noware::var noware::var::operator += (const unsigned char other [])
{
	return *this += var (other);
}

const noware::var noware::var::operator += (const signed char other [])
{
	return *this += var (other);
}
*/
const noware::var & noware::var::operator += (const char & other)
{
	*this += var (other);
	return *this;
}
/*
const noware::var noware::var::operator += (const signed char & other)
{
	return *this += var (other);
}

const noware::var noware::var::operator += (const unsigned char & other)
{
	return *this += var (other);
}
*/
const noware::var & noware::var::operator += (const complex & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const real & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const rational & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const integer & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const _float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const short_float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const single_float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const double_float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const long_float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const long double & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const double & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const float & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const signed long long int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const unsigned long long int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const signed long int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const unsigned long int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const signed int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const unsigned int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const signed short int & other)
{
	*this += var (other);
	return *this;
}

const noware::var & noware::var::operator += (const unsigned short int & other)
{
	*this += var (other);
	return *this;
}
