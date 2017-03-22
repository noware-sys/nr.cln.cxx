#pragma once

#include "number.hdr.cxx"

const bool noware::tool::is_numeric (const std::string & value)
{
	if (value.empty ())
		return false;

	unsigned long long int length = value.length ();
	bool decimal_found = false;
	bool sign_found = false;
	bool digit_found = false;

	//if (s[0] != '+' || s[0] != '-' || !isdigit(s[0]))
		//return false;

	for
	(
		///*unsigned long long int*/math::numbers::natural i = 0;
		unsigned long long int i = 0;
		i < length;
		++ i
	)
	{
		//if (isdigit (value [i]))
		//{
		//	/*continue*/;
		//}
		//else 
			if (value [i] == '.'/* && ! decimal_found*/)
		{
			if (decimal_found)
				return false;
			
			decimal_found = true;
		}
		else if ((value [i] == '+' || value [i] == '-')/* && ! sign_found*/)
		{
			sign_found = true;
		}
		else if (! isdigit (value [i]))
		{
			return false;
		}
		else
		{
			digit_found = true;
		}
	}
	
	return digit_found;
}

const bool noware::tool::is_number (const std::string & value)
{
	return is_numeric (value);
}

const bool noware::tool::is_numeric (const char & value)
{
	switch (value)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
	}
}

const bool noware::tool::is_numeric (const unsigned char & value)
{
	switch (value)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
	}
}

const bool noware::tool::is_numeric (const signed char & value)
{
	switch (value)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
	}
}

