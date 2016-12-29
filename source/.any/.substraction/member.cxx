// operator -

const noware::any noware::any::operator - (void) const
{
	switch (content.t)
	{
		case container::type::numeric:
			return -content.number;
		//case container::type::generic:
		default:
			return *this;
			//return text ();
	}
}

const noware::any noware::any::operator - (const any & other) const
{
	switch (content.t)
	{
		case container::type::numeric:
			switch (other.content.t)
			{
				case container::type::numeric:
					return content.number - other.content.number;
				case container::type::generic:
				default:
					return *this;
					//return text () - other.text ();
			}
		//case container::type::generic:
		default:
			return *this;
			//return text () - other.text ();
	}
}
/*
const noware::any noware::any::operator - (const text & other) const
{
	return *this - any (other);
}
*/
const noware::any noware::any::operator - (const std::string & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const char other []) const
{
	return *this - any (other);
}
/*
const noware::any noware::any::operator - (const char *& other) const
{
	return *this - any (other);
}
*/
const noware::any noware::any::operator - (const char & other) const
{
	return *this - any (other);
}
/*
const noware::any noware::any::operator - (const signed char & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const unsigned char & other) const
{
	return *this - any (other);
}
*/
const noware::any noware::any::operator - (const number & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const long double & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const double & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const float & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const signed long long int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const unsigned long long int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const signed long int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const unsigned long int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const signed int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const unsigned int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const signed short int & other) const
{
	return *this - any (other);
}

const noware::any noware::any::operator - (const unsigned short int & other) const
{
	return *this - any (other);
}

