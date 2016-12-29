// operator =

const noware::any & noware::any::operator = (const any & other)
{
	content.text = other.content.text;
	content.number = other.content.number;
	
	content.t = other.content.t;
	
	return other;
}
/*
const noware::any & noware::any::operator = (const text & other)
{
	content.text = other;
	content.number = 0;
	
	content.t = container::type::generic;
	
	return *this;
}
*/
const noware::any & noware::any::operator = (const std::string & other)
{
	if (tool::is_numeric (other))
	{
		content.text = "";
		//content.number = other;
		content.number = std::stold (other);
		
		content.t = container::type::numeric;
	}
	else
	{
		content.text = other;
		content.number = 0;
		
		content.t = container::type::generic;
	}
	
	return *this;
}

const noware::any & noware::any::operator = (const char other [])
{
	*this = std::string (other);
	
	return *this;
}
/*
const noware::any & noware::any::operator = (const signed char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
const noware::any & noware::any::operator = (const char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const signed char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned char *& other)
{
	*this = std::string (other);
	
	return *this;
}
*/
const noware::any & noware::any::operator = (const char & other)
{
	*this = noware::tool::string (other);
	
	return *this;
}
/*
const noware::any & noware::any::operator = (const signed char & other)
{
	*this = noware::tool::string (char (other));
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned char & other)
{
	*this = noware::tool::string (char (other));
	
	return *this;
}
*/
const noware::any & noware::any::operator = (const number & other)
{
	content.text = "";
	content.number = other;
	
	content.t = container::type::numeric;
	
	return *this;
}

const noware::any & noware::any::operator = (const long double & other)
{
	//*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const double & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const float & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const signed long long int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned long long int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const signed long int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned long int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const signed int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const signed short int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const unsigned short int & other)
{
	*this = number (other);
	
	return *this;
}

const noware::any & noware::any::operator = (const bool & other)
{
	content.text = "";
	content.number = other/* ? 1 : 0*/;
	
	content.t = container::type::numeric;
	
	return *this;
}

