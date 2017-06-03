// friend operator +=

namespace noware
{
	//namespace math
	//{
	/*	const nr operator += (text & other, const nr & self)
		{
			return other = other + self;
		}
	*/	
		const std::string operator += (std::string & other, const nr & self)
		{
			//return other = (other + self).text ();
			if (tool::is_nr (other))
				return other = std::string (nr (other) + self);
			else
				return other = other + std::string (self);
		}
		/*
		const nr operator += (char [] other, const nr & self)
		{
			return other = other + self;
		}
		
		const nr operator += (char *& other, const nr & self)
		{
			return nr (other) += self;
		}
		*/
		const char operator += (char & other, const nr & self)
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
		const nr operator += (cln::cl_N & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
				other = other + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_RA & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_RA (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_I & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_I (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_SF & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_SF (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_FF & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_FF (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_DF & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_DF (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (cln::cl_LF & other, const nr & self)
		{
			//if (self.content.t == nr::container::type::numeric)
			//	other = cln::cl_LF (nr (other) + self);
			//	other = cln::cl_N (other) + self.content;
			
			return other;
		}
		
		const nr operator += (long double & other, const nr & self)
		{
			nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= nr (LDBL_MIN) && tmp.content.nr <= nr (LDBL_MAX))
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (double & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= DBL_MIN && tmp.content.nr <= DBL_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (float & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= FLT_MIN && tmp.content.nr <= FLT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (signed long long int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= LLONG_MIN && tmp.content.nr <= LLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (unsigned long long int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= ULLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (signed long int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= LONG_MIN && tmp.content.nr <= LONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (unsigned long int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= ULONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (signed int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= INT_MIN && tmp.content.nr <= INT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (unsigned int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= UINT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (signed short int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= SHRT_MIN && tmp.content.nr <= SHRT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const nr operator += (unsigned short int & other, const nr & self)
		{
			//nr tmp = other + self;
			
			//if (tmp.content.t == nr::container::type::numeric && tmp.content.nr >= 0 && tmp.content.nr <= USHRT_MAX)
			//	other = tmp;
			
			return other;
		}
	//}
}

