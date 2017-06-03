// constructors

noware::any::container::container (void)
{
	text = "";
	number = 0;
	
	t = type::generic;
}
/*
noware::any::container::container (const container & other)
{
	*this = other;
}
*/

// seralization

template <typename archive>
void noware::any::container::serialize (archive & arch, const unsigned int & version)
{
	arch & text;
	arch & number;
	arch & t;
}

const std::string noware::any::container::serialize (void) const
{
	return noware::serialize <noware::any::container> (*this);
}

const bool noware::any::container::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::any::container> (serial, *this);
}
/*

// operator =

const any & noware::any::container::operator = (const container & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return other;
}

const bool & noware::any::container::operator = (const bool & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const text & noware::any::container::operator = (const text & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const std::string & noware::any::container::operator = (const std::string & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const math::nr & noware::any::container::operator = (const math::nr & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}
*/
