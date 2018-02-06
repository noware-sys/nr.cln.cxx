// friend operator ==

namespace noware
{
	//namespace container
	//{
	/*	const bool operator == (const text & other, const noware::nr & self)
		{
			return self == other;
		}
	*/	
		const bool operator == (const std::string & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (char other const * const, noware::nr const & self)
		{
			return self == other;
		}
		/*
		const bool operator == (const signed char other [], const noware::nr & self)
		{
			return self == nr (other);
		}
		
		const bool operator == (const unsigned char other [], const noware::nr & self)
		{
			return self == nr (other);
		}
		*/
		const bool operator == (const char & other, const noware::nr & self)
		{
			return self == other;
		}
		/*
		const bool operator == (const signed char & other, const noware::nr & self)
		{
			return self == nr (other);
		}
		
		const bool operator == (const unsigned char & other, const noware::nr & self)
		{
			return self == nr (other);
		}
		*/
		
		const bool operator == (const complex & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const real & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const rational & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const integer & other, const noware::nr & self)
		{
			return self == other;
		}
		/*
		const bool operator == (const _float & other, const noware::nr & self)
		{
			return self == other;
		}
		*/
		const bool operator == (const short_float & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const single_float & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const double_float & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const long_float & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const long double & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const double & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const float & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const signed long long int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const unsigned long long int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const signed long int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const unsigned long int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const signed int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const unsigned int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const signed short int & other, const noware::nr & self)
		{
			return self == other;
		}
		
		const bool operator == (const unsigned short int & other, const noware::nr & self)
		{
			return self == other;
		}
	//}
}
