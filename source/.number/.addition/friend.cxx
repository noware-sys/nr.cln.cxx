// friend operator +

namespace noware
{
	//namespace math
	//{
	/*	const number operator + (const text & other, const number & self)
		{
			return number (other) + self;
		}
	*/	
		const number operator + (const std::string & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const char other [], const number & self)
		{
			return number (other) + self;
		}
		/*
		const number operator + (const unsigned char other [], const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed char other [], const number & self)
		{
			return number (other) + self;
		}
		*/
		const number operator + (const char & other, const number & self)
		{
			return number (other) + self;
		}
		/*
		const number operator + (const unsigned char & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed char & other, const number & self)
		{
			return number (other) + self;
		}
		*/
	/*	
		const number operator + (const signed char & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const unsigned char & other, const number & self)
		{
			return number (other) + self;
		}
	*/	
		const number operator + (const cln::cl_N & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_RA & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_I & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_SF & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_FF & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_DF & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const cln::cl_LF & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const long double & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const double & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const float & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed long long int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const unsigned long long int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed long int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const unsigned long int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const unsigned int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const signed short int & other, const number & self)
		{
			return number (other) + self;
		}
		
		const number operator + (const unsigned short int & other, const number & self)
		{
			return number (other) + self;
		}
	//}
}

