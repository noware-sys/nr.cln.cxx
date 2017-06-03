// friend operator ^

namespace noware
{
	//namespace container
	//{
	/*	const nr operator ^ (const text & other, const nr & self)
		{
			return nr (other) ^ self;
		}
	*/	
		const nr operator ^ (const std::string & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const char other [], const nr & self)
		{
			return nr (other) ^ self;
		}
		/*
		const nr operator ^ (const char *& other, const nr & self)
		{
			return nr (other) ^ self;
		}
		*/
		const nr operator ^ (const char & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		/*
		const nr operator ^ (const signed char & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const unsigned char & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		*/
		/*const nr operator ^ (const nr & other, const nr & self)
		{
			return nr (other) ^ self;
		}*/
		
		const nr operator ^ (const long double & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const double & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const float & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const signed long long int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const unsigned long long int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const signed long int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const unsigned long int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const signed int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const unsigned int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const signed short int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
		
		const nr operator ^ (const unsigned short int & other, const nr & self)
		{
			return nr (other) ^ self;
		}
	//}
}

