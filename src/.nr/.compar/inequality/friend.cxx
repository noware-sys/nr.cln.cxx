// friend operator !=

namespace noware
{
	//namespace container
	//{
	/*	const bool operator != (const text & other, const noware::nr & self)
		{
			return self != other;
		}
	*/	
		const bool operator != (const std::string & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const char other [], const noware::nr & self)
		{
			return self != other;
		}
		/*
		const bool operator != (const unsigned char other [], const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const signed char other [], const noware::nr & self)
		{
			return self != other;
		}
		*/
		const bool operator != (const char & other, const noware::nr & self)
		{
			return self != other;
		}
		/*
		const bool operator != (const signed char & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const unsigned char & other, const noware::nr & self)
		{
			return self != other;
		}
		*/
		const bool operator != (const cln::cl_N & other, const noware::nr & self)
		{
			return self != other;
		}
		/*
		const bool operator != (const cln::cl_R & other, const noware::nr & self)
		{
			return self != other;
		}
		*/
		const bool operator != (const cln::cl_RA & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const cln::cl_I & other, const noware::nr & self)
		{
			return self != other;
		}
		/*
		const bool operator != (const cln::cl_F & other, const noware::nr & self)
		{
			return self != other;
		}
		*/
		const bool operator != (const cln::cl_SF & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const cln::cl_FF & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const cln::cl_DF & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const cln::cl_LF & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const long double & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const double & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const float & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const signed long long int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const unsigned long long int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const signed long int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const unsigned long int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const signed int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const unsigned int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const signed short int & other, const noware::nr & self)
		{
			return self != other;
		}
		
		const bool operator != (const unsigned short int & other, const noware::nr & self)
		{
			return self != other;
		}
	//}
}

