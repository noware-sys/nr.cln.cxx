// friend operator <

namespace noware
{
	//namespace container
	//{
	/*	const bool operator < (const text & other, const nr & self)
		{
			return nr (other) < self;
		}
	*/	
		const bool operator < (const std::string & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const char other [], const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const char *& other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const char & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const signed char & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const unsigned char & other, const nr & self)
		{
			return nr (other) < self;
		}
		/*
		const bool operator < (const nr & other, const nr & self)
		{
			return nr (other) < self;
		}
		*/
		const bool operator < (const long double & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const double & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const float & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const signed long long int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const unsigned long long int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const signed long int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const unsigned long int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const signed int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const unsigned int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const signed short int & other, const nr & self)
		{
			return nr (other) < self;
		}
		
		const bool operator < (const unsigned short int & other, const nr & self)
		{
			return nr (other) < self;
		}
	//}
}

