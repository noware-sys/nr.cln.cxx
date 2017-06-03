// operator =

const noware::nr & noware::nr::operator = (const nr & other)
{
	contnt = other.contnt;
	
	return *this;
}
/*
const noware::nr & noware::nr::operator = (const text & other)
{
	contnt.text = other;
	contnt.nr = 0;
	
	contnt.t = container::type::generic;
	
	return *this;
}
*/
const noware::nr & noware::nr::operator = (const std::string & other)
{
	try
	{
		contnt = other.c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::nr & noware::nr::operator = (const char * other)
{
	try
	{
		contnt = other;
	}
	catch (...)
	{
	}
	
	return *this;
}
/*
const noware::nr & noware::nr::operator = (const unsigned char other [])
{
	contnt = cln::cl_N (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed char other [])
{
	contnt = cln::cl_N (other);
	
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
		contnt = noware::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}
/*
const noware::nr & noware::nr::operator = (const signed char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::tool::string (other).c_str ();
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
		contnt = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}
*/
const noware::nr & noware::nr::operator = (const complex & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const real & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const rational & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const integer & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const _float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const short_float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const single_float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const double_float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const long_float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const long double & other)
{
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const double & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const float & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed long long int & other)
{
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned long long int & other)
{
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed long int & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned long int & other)
{
	contnt = other;
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed int & other)
{
	//contnt = signed long int (other);
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned int & other)
{
	//contnt = unsigned long int (other);
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed short int & other)
{
	contnt = noware::string (other).c_str ();
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned short int & other)
{
	contnt = noware::string (other).c_str ();
	
	return *this;
}
