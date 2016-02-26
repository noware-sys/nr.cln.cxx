/*
	operator ==
*/

const noware::container::any noware::container::any::operator == (const any & other) const
{
	switch (content.t)
	{
		case container::type::numeric:
			switch (other.content.t)
			{
				case container::type::numeric:
					return content.number == other.content.number;
				case container::type::generic:
				default:
					return false;
			}
		case container::type::generic:
		default:
			switch (other.content.t)
			{
				case container::type::numeric:
					return false;
				case container::type::generic:
				default:
					return content.text == other.content.text;
			}
			//return content.text == other.text ();
	}
}
/*
const noware::container::any noware::container::any::operator == (const text & other) const
{
	return *this == any (other);
}
*/
const noware::container::any noware::container::any::operator == (const std::string & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const char other []) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const char *& other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const char & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const signed char & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const unsigned char & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const math::number & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const long double & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const double & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const float & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const signed long long int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const unsigned long long int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const signed long int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const unsigned long int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const signed int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const unsigned int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const signed short int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const unsigned short int & other) const
{
	return *this == any (other);
}

const noware::container::any noware::container::any::operator == (const bool & other) const
{
	return *this == any (other);
}

