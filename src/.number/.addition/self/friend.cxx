// friend operator +=

namespace noware
{
	//namespace math
	//{
	/*	const number operator += (text & other, const number & self)
		{
			return other = other + self;
		}
	*/	
		const std::string operator += (std::string & other, const number & self)
		{
			//return other = (other + self).text ();
			if (tool::is_numeric (other))
				return other = std::string (number (other) + self);
			else
				return other = other + std::string (self);
		}
		/*
		const number operator += (char [] other, const number & self)
		{
			return other = other + self;
		}
		
		const number operator += (char *& other, const number & self)
		{
			return number (other) += self;
		}
		*/
		const char operator += (char & other, const number & self)
		{
			// number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		/*
		const number operator += (signed char & other, const number & self)
		{
			// number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const number operator += (unsigned char & other, const number & self)
		{
			// number tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		*/
		const number operator += (cln::cl_N & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_RA & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_RA (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_I & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_I (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_SF & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_SF (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_FF & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_FF (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_DF & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_DF (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (cln::cl_LF & other, const number & self)
		{
			//if (self.content.t == number::container::type::numeric)
			//	other = cln::cl_LF (number (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const number operator += (long double & other, const number & self)
		{
			number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= number (LDBL_MIN) && tmp.content.number <= number (LDBL_MAX))
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (double & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= DBL_MIN && tmp.content.number <= DBL_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (float & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= FLT_MIN && tmp.content.number <= FLT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (signed long long int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= LLONG_MIN && tmp.content.number <= LLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (unsigned long long int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (signed long int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= LONG_MIN && tmp.content.number <= LONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (unsigned long int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (signed int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= INT_MIN && tmp.content.number <= INT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (unsigned int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= UINT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (signed short int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= SHRT_MIN && tmp.content.number <= SHRT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const number operator += (unsigned short int & other, const number & self)
		{
			//number tmp = other + self;
			
			//if (tmp.content.t == number::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= USHRT_MAX)
			//	other = tmp;
			
			return other;
		}
	//}
}

