#pragma once

#include <sstream>

#include "string.hdr.cxx"
//#include "containers/variable.h++"

#include "../number.cxx"

namespace noware
{
	namespace tool
	{
		const std::string string (const signed short int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned short int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const signed long long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const unsigned long long int & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const float & value)
		{
			return string ((double) value);
		}
		
		const std::string string (const double & value)
		{
			return string ((long double) value);
		}
		
		const std::string string (const long double & value)
		{
			std::stringstream ss;
			ss << value;
			return ss.str ();
		}
		/*
		const std::string string (const noware::math::numbers::integer & value)
		{
			std::stringstream ss;
			ss << value;
			return ss.str ();
		}
		*/
	/*	
		const std::string string (const noware::math::numbers::real & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str();
			return ss.str ();
		}
	*/	
		/*
		const std::string string (const noware::number & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str();
			return ss.str ();
		}
		*/
		const std::string string (const char & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		
		const std::string string (const unsigned char & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		
		const std::string string (const signed char & value)
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		
		// Just use std::string (value)
		//std::string string (const signed char value)
		//{
		//	//int i = 5;
		//	//std::string s;
		//	std::stringstream ss;
		//	ss << value;
		//	//s = ss.str();
		//	return ss.str ();
		//}

		//std::string string (const unsigned char value)
		//{
		//	//int i = 5;
		//	//std::string s;
		//	std::stringstream ss;
		//	ss << value;
		//	//s = ss.str();
		//	return ss.str ();
		//}
		
		/*
		std::string string (const char value [])
		{
			//int i = 5;
			//std::string s;
			std::stringstream ss;
			ss << value;
			//s = ss.str  ();
			return ss.str ();
		}
		*/
		/*
		const std::string string (const char *& value)
		{
			std::string txt = value;
			
			return txt;
		}
		*/
	}
}
