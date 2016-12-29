// friend operator +=

namespace noware
{
	namespace math
	{
	/*	const noware::math::number operator += (text & other, const noware::math::number & self)
		{
			return other = other + self;
		}
	*/	
		const noware::math::number operator += (std::string & other, const noware::math::number & self)
		{
			//return other = (other + self).text ();
			return other = other + self;
		}
		/*
		const noware::math::number operator += (char [] other, const noware::math::number & self)
		{
			return other = other + self;
		}
		
		const noware::math::number operator += (char *& other, const noware::math::number & self)
		{
			return number (other) += self;
		}
		*/
		const noware::math::number operator += (char & other, const noware::math::number & self)
		{
			// noware::math::number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::math::number operator += (signed char & other, const noware::math::number & self)
		{
			// noware::math::number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::math::number operator += (unsigned char & other, const noware::math::number & self)
		{
			// noware::math::number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_N & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_RA & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_I & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_SF & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_FF & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_DF & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (cln::cl_LF & other, const noware::math::number & self)
		{
			//if (self.content.t == noware::math::number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const noware::math::number operator += (long double & other, const noware::math::number & self)
		{
			noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= noware::math::number (LDBL_MIN) && tmp.content.number <= noware::math::number (LDBL_MAX))
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (double & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= DBL_MIN && tmp.content.number <= DBL_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (float & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= FLT_MIN && tmp.content.number <= FLT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (signed long long int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= LLONG_MIN && tmp.content.number <= LLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (unsigned long long int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (signed long int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= LONG_MIN && tmp.content.number <= LONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (unsigned long int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (signed int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= INT_MIN && tmp.content.number <= INT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (unsigned int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= UINT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (signed short int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= SHRT_MIN && tmp.content.number <= SHRT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::math::number operator += (unsigned short int & other, const noware::math::number & self)
		{
			//noware::math::number tmp = other + self;
			
			//if (tmp.content.t == noware::math::number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= USHRT_MAX)
			//	other = tmp;
			
			return other;
		}
	}
}

