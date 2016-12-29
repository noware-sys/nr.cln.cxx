//
// constructors
//
noware::container::any::container::container (void)
{
	text = "";
	number = 0;
	
	t = type::generic;
}
/*
noware::container::any::container::container (const container & other)
{
	*this = other;
}
*/
//
// seralization
//
template <typename archive>
void noware::container::any::container::serialize (archive & arch, const unsigned int & version)
{
	arch & text;
	arch & number;
}

const std::string noware::container::any::container::serialize (void) const
{
	return noware::serialize <noware::container::any::container> (*this);
}

const bool noware::container::any::container::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::container::any::container> (serial, *this);
}
/*
//
// operator =
//
const any & noware::container::any::container::operator = (const container & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return other;
}

const bool & noware::container::any::container::operator = (const bool & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const text & noware::container::any::container::operator = (const text & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const std::string & noware::container::any::container::operator = (const std::string & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}

const math::number & noware::container::any::container::operator = (const math::number & other)
{
	text = other.text;
	number = other.number;
	
	t = other.t;
	
	return *this;
}
*/
