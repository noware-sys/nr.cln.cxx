// friend operator %

namespace noware
{
	//namespace container
	//{
	/*	const noware::nr operator % (const text & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
	*/	
		const noware::nr operator % (const std::string & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const char other [], const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const char *& other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const char & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const signed char & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const unsigned char & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		//const noware::nr operator % (const noware::math::nr & other, const noware::nr & self)
		//{
		//	return nr (other) % self;
		//}
		
		const noware::nr operator % (const long double & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const double & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const float & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const signed long long int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const unsigned long long int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const signed long int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const unsigned long int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const signed int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const unsigned int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const signed short int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
		
		const noware::nr operator % (const unsigned short int & other, const noware::nr & self)
		{
			return nr (other) % self;
		}
	//}
}

