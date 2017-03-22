// friend operator >

namespace noware
{
	namespace math
	{
	/*	const bool operator > (const text & other, const number & self)
		{
			return number (other) > self;
		}
	*/	
		const bool operator > (const std::string & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const char other [], const number & self)
		{
			return number (other) > self;
		}
		/*
		const bool operator > (const char *& other, const number & self)
		{
			return number (other) > self;
		}
		*/
		const bool operator > (const char & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const signed char & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const unsigned char & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::complex & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::real & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::rational & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::integer & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::_float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::short_float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::single_float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::double_float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const number::long_float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const long double & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const double & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const float & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const signed long long int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const unsigned long long int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const signed long int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const unsigned long int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const signed int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const unsigned int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const signed short int & other, const number & self)
		{
			return number (other) > self;
		}
		
		const bool operator > (const unsigned short int & other, const number & self)
		{
			return number (other) > self;
		}
	}
}

