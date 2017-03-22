// operator =

const noware::number & noware::number::operator = (const number & other)
{
	content = other.content;
	
	return other;
}
/*
const noware::number & noware::number::operator = (const text & other)
{
	content.text = other;
	content.number = 0;
	
	content.t = container::type::generic;
	
	return *this;
}
*/
const noware::number & noware::number::operator = (const std::string & other)
{
	try
	{
		content = other.c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::number & noware::number::operator = (const char other [])
{
	try
	{
		content = other;
	}
	catch (...)
	{
	}
	
	return *this;
}
/*
const noware::number & noware::number::operator = (const unsigned char other [])
{
	content = cln::cl_N (other);
	
	return *this;
}

const noware::number & noware::number::operator = (const signed char other [])
{
	content = cln::cl_N (other);
	
	return *this;
}
*/
/*
const noware::number & noware::number::operator = (const signed char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
const noware::number & noware::number::operator = (const char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::number & noware::number::operator = (const signed char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned char *& other)
{
	*this = std::string (other);
	
	return *this;
}
*/

const noware::number & noware::number::operator = (const char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		content = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::number & noware::number::operator = (const signed char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		content = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		content = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::number & noware::number::operator = (const complex & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const real & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const rational & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const integer & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const _float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const short_float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const single_float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const double_float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const long_float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const long double & other)
{
	content = noware::tool::string (other).c_str ();
	
	return *this;
}

const noware::number & noware::number::operator = (const double & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const float & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const signed long long int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned long long int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const signed long int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned long int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const signed int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const signed short int & other)
{
	content = other;
	
	return *this;
}

const noware::number & noware::number::operator = (const unsigned short int & other)
{
	content = other;
	
	return *this;
}

