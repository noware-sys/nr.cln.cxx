// friend operator /

namespace noware
{
	//namespace container
	//{
	/*	const any operator / (const text & other, const any & self)
		{
			return any (other) / self;
		}
	*/	
		const any operator / (const std::string & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const char other [], const any & self)
		{
			return any (other) / self;
		}
		/*
		const any operator / (const char *& other, const any & self)
		{
			return any (other) / self;
		}
		*/
		const any operator / (const char & other, const any & self)
		{
			return any (other) / self;
		}
		/*
		const any operator / (const signed char & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const unsigned char & other, const any & self)
		{
			return any (other) / self;
		}
		*/
		const any operator / (const nr & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const long double & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const double & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const float & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const signed long long int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const unsigned long long int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const signed long int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const unsigned long int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const signed int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const unsigned int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const signed short int & other, const any & self)
		{
			return any (other) / self;
		}
		
		const any operator / (const unsigned short int & other, const any & self)
		{
			return any (other) / self;
		}
	//}
}

