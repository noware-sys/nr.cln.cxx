// operator =

const noware::nr & noware::nr::operator = (const nr & other)
{
	content = other.content;
	
	return other;
}
/*
const noware::nr & noware::nr::operator = (const text & other)
{
	content.text = other;
	content.nr = 0;
	
	content.t = container::type::generic;
	
	return *this;
}
*/
const noware::nr & noware::nr::operator = (const std::string & other)
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

const noware::nr & noware::nr::operator = (const char other [])
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
const noware::nr & noware::nr::operator = (const unsigned char other [])
{
	content = cln::cl_N (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed char other [])
{
	content = cln::cl_N (other);
	
	return *this;
}
*/
/*
const noware::nr & noware::nr::operator = (const signed char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
const noware::nr & noware::nr::operator = (const char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned char *& other)
{
	*this = std::string (other);
	
	return *this;
}
*/

const noware::nr & noware::nr::operator = (const char & other)
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

const noware::nr & noware::nr::operator = (const signed char & other)
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

const noware::nr & noware::nr::operator = (const unsigned char & other)
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

const noware::nr & noware::nr::operator = (const complex & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const real & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const rational & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const integer & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const _float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const short_float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const single_float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const double_float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const long_float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const long double & other)
{
	content = noware::tool::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const double & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const float & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed long long int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned long long int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed long int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned long int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed short int & other)
{
	content = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned short int & other)
{
	content = other;
	
	return *this;
}

