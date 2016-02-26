/*
	friend operator !=
*/

namespace noware
{
	namespace container
	{
	/*	const noware::container::any operator != (const text & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
	*/	
		const noware::container::any operator != (const std::string & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const char other [], const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const char *& other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const char & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const signed char & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const unsigned char & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const noware::math::number & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const long double & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const double & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const float & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const signed long long int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const unsigned long long int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const signed long int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const unsigned long int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const signed int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const unsigned int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const signed short int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const unsigned short int & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
		
		const noware::container::any operator != (const bool & other, const noware::container::any & self)
		{
			return any (other) != self;
		}
	}
}

