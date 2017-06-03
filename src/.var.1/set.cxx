// operator =

const noware::var & noware::var::operator = (const var & other)
{
	nr = other.nr;
	text = other.text;
	
	_t = other._t;
	
	return other;
}
/*
const noware::var & noware::var::operator = (const text & other)
{
	content.text = other;
	content.number = 0;
	
	content.t = container::type::generic;
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const std::string & other)
{
	if (tool::is_nr (other))
	{
		//nr = other;
		nr = std::stold (other);
		text = "";
		
		_t = t::nr;
	}
	else
	{
		nr = 0;
		text = other;
		
		_t = t::text;
	}
	
	return *this;
}

const noware::var & noware::var::operator = (const char other [])
{
	*this = std::string (other);
	
	return *this;
}
/*
const noware::var & noware::var::operator = (const signed char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
const noware::var & noware::var::operator = (const char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const signed char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned char *& other)
{
	*this = std::string (other);
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const char & other)
{
	*this = noware::tool::string (other);
	
	return *this;
}
/*
const noware::var & noware::var::operator = (const signed char & other)
{
	*this = noware::tool::string (char (other));
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned char & other)
{
	*this = noware::tool::string (char (other));
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const noware::nr & other)
{
	t = type::nr;
	
	txt = "";
	nr = other;
	
	return *this;
}
/*
const noware::var & noware::var::operator = (const long double & other)
{
	//*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const double & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const float & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const signed long long int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned long long int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const signed long int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned long int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const signed int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const signed short int & other)
{
	*this = nr (other);
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned short int & other)
{
	*this = nr (other);
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const bool & other)
{
	t = type::nr;
	
	txt = "";
	nr = other ? 1 : 0;
	
	return *this;
}
