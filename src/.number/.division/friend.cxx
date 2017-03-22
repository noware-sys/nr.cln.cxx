// friend operator /

namespace noware
{
	//namespace container
	//{
	/*	const noware::number operator / (const text & other, const noware::number & self)
		{
			return number (other) / self;
		}
	*/	
		const noware::number operator / (const std::string & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const char other [], const noware::number & self)
		{
			return number (other) / self;
		}
		/*
		const noware::number operator / (const char *& other, const noware::number & self)
		{
			return number (other) / self;
		}
		*/
		const noware::number operator / (const char & other, const noware::number & self)
		{
			return number (other) / self;
		}
		/*
		const noware::number operator / (const signed char & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const unsigned char & other, const noware::number & self)
		{
			return number (other) / self;
		}
		*/
		//const noware::number operator / (const noware::math::number & other, const noware::number & self)
		//{
		//	return number (other) / self;
		//}
		
		const noware::number operator / (const long double & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const double & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const float & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const signed long long int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const unsigned long long int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const signed long int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const unsigned long int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const signed int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const unsigned int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const signed short int & other, const noware::number & self)
		{
			return number (other) / self;
		}
		
		const noware::number operator / (const unsigned short int & other, const noware::number & self)
		{
			return number (other) / self;
		}
	//}
}

