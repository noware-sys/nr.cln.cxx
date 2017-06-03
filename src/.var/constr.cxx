// constructors

noware::var::var (void)
{
	////txt = "";
	////var = 0;
	//t = type::txt;
	
	//_exact = true;
	//*this = other;
}

noware::var::var (const var & other)
{
	*this = other;
}

noware::var::var (const noware::nr & other)
{
	//txt = "";
	//var = other;
	//t = type::var;
	*this = other;
}

/*
noware::var::var (const noware::container::text & other)
{
	*this = other;
}
*/

noware::var::var (const std::string & other)
{
	*this = other;
}

noware::var::var (const char * other)
{
	//*this = std::string (other);
	*this = other;
}

/*
noware::var::var (const unsigned char other [])
{
	*this = other;
}

noware::var::var (const signed char other [])
{
	*this = other;
}
*/

/*
noware::var::var (const signed char other [])
{
	*this = std::string (other);
}

noware::var::var (const unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::var::var (const char *& other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::var::var (const signed char *& other)
{
	*this = std::string (other);
}

noware::var::var (const unsigned char *& other)
{
	*this = std::string (other);
}
*/

noware::var::var (const char & other)
{
	//*this = noware::tool::string (other);
	*this = other;
}

/*
noware::var::var (const signed char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

noware::var::var (const unsigned char & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}
*/

noware::var::var (const complex & other)
{
	*this = other;
}

noware::var::var (const real & other)
{
	*this = other;
}

noware::var::var (const rational & other)
{
	*this = other;
}

noware::var::var (const integer & other)
{
	*this = other;
}

noware::var::var (const _float & other)
{
	*this = other;
}

noware::var::var (const short_float & other)
{
	*this = other;
}

noware::var::var (const single_float & other)
{
	*this = other;
}

noware::var::var (const double_float & other)
{
	*this = other;
}

noware::var::var (const long_float & other)
{
	*this = other;
}

noware::var::var (const long double & other)
{
	*this = other;
}

noware::var::var (const double & other)
{
	*this = other;
}

noware::var::var (const float & other)
{
	*this = other;
}

noware::var::var (const unsigned long long int & other)
{
	*this = other;
}

noware::var::var (const unsigned long int & other)
{
	*this = other;
}

noware::var::var (const unsigned int & other)
{
	*this = other;
}

noware::var::var (const unsigned short int & other)
{
	*this = other;
}

noware::var::var (const signed long long int & other)
{
	*this = other;
}

noware::var::var (const signed long int & other)
{
	*this = other;
}

noware::var::var (const signed int & other)
{
	*this = other;
}

noware::var::var (const signed short int & other)
{
	*this = other;
}
