// friend operator +=

namespace noware
{
	//namespace math
	//{
	/*	const noware::nr operator += (text & other, const noware::nr & self)
		{
			return other = other + self;
		}
	*/	
		const noware::nr operator += (std::string & other, const noware::nr & self)
		{
			//return other = (other + self).text ();
			return other = other + self;
		}
		/*
		const noware::nr operator += (char [] other, const noware::nr & self)
		{
			return other = other + self;
		}
		
		const noware::nr operator += (char *& other, const noware::nr & self)
		{
			return nr (other) += self;
		}
		*/
		const noware::nr operator += (char & other, const noware::nr & self)
		{
			// noware::nr tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::nr operator += (signed char & other, const noware::nr & self)
		{
			// noware::nr tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::nr operator += (unsigned char & other, const noware::nr & self)
		{
			// noware::nr tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_N & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_RA & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_I & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_SF & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_FF & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_DF & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (cln::cl_LF & other, const noware::nr & self)
		{
			//if (self.content.t == noware::nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::nr operator += (long double & other, const noware::nr & self)
		{
			noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= noware::nr (LDBL_MIN) && tmp.content.number <= noware::nr (LDBL_MAX))
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (double & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= DBL_MIN && tmp.content.number <= DBL_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (float & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= FLT_MIN && tmp.content.number <= FLT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (signed long long int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= LLONG_MIN && tmp.content.number <= LLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (unsigned long long int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (signed long int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= LONG_MIN && tmp.content.number <= LONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (unsigned long int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (signed int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= INT_MIN && tmp.content.number <= INT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (unsigned int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= UINT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (signed short int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= SHRT_MIN && tmp.content.number <= SHRT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::nr operator += (unsigned short int & other, const noware::nr & self)
		{
			//noware::nr tmp = other + self;
			
			//if (tmp.content.t == noware::nr::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= USHRT_MAX)
			//	other = tmp;
			
			return other;
		}
	//}
}

