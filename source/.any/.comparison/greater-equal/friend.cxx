// friend operator >=

namespace noware
{
	//namespace container
	//{
	/*	const noware::any operator >= (const text & other, const noware::any & self)
		{
			return any (other) >= self;
		}
	*/	
		const noware::any operator >= (const std::string & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const char other [], const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const char *& other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const char & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const signed char & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const unsigned char & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const noware::number & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const long double & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const double & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const float & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const signed long long int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const unsigned long long int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const signed long int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const unsigned long int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const signed int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const unsigned int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const signed short int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
		
		const noware::any operator >= (const unsigned short int & other, const noware::any & self)
		{
			return any (other) >= self;
		}
	//}
}

