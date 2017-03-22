// operator !=

const bool noware::nr::operator != (const nr & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const text & other) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (const std::string & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const char other []) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const unsigned char other []) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed char other []) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (const char & other) const
{
	return !(*this == other);
}
/*
const bool noware::nr::operator != (const signed char & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned char & other) const
{
	return !(*this == other);
}
*/
const bool noware::nr::operator != (const cln::cl_N & other) const
{
	return content != other;
}
/*
const bool noware::nr::operator != (const cln::cl_R & other) const
{
	return content != other;
}
*/
const bool noware::nr::operator != (const cln::cl_RA & other) const
{
	return content != other;
}

const bool noware::nr::operator != (const cln::cl_I & other) const
{
	return content != other;
}
/*
const bool noware::nr::operator != (const cln::cl_F & other) const
{
	return content != other;
}
*/
const bool noware::nr::operator != (const cln::cl_SF & other) const
{
	return content != other;
}

const bool noware::nr::operator != (const cln::cl_FF & other) const
{
	return content != other;
}

const bool noware::nr::operator != (const cln::cl_DF & other) const
{
	return content != other;
}

const bool noware::nr::operator != (const cln::cl_LF & other) const
{
	return content != other;
}

const bool noware::nr::operator != (const long double & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const double & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const float & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed long long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned long long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned long int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const signed short int & other) const
{
	return !(*this == other);
}

const bool noware::nr::operator != (const unsigned short int & other) const
{
	return !(*this == other);
}

