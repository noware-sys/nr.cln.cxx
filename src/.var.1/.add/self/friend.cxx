// friend operator +=

namespace noware
{
	//namespace container
	//{
	/*	const noware::any operator += (text & other, const noware::any & self)
		{
			return other = other + self;
		}
	*/	
		const noware::any operator += (std::string & other, const noware::any & self)
		{
			return other = (other + self).text ();
		}
		/*
		const noware::any operator += (char [] other, const noware::any & self)
		{
			return other = other + self;
		}
		
		const noware::any operator += (char *& other, const noware::any & self)
		{
			return any (other) += self;
		}
		*/
		const noware::any operator += (char & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::any operator += (signed char & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::any operator += (unsigned char & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			// Only one unsigned numeric digit can be contained in one character.
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= 9)
			//	other = tmp.text () [0];
			
			return other;
		}
		
		const noware::any operator += (noware::nr & other, const noware::any & self)
		{
			if (self.content.t == noware::any::container::type::numeric)
				other = other + self.content.number;
			
			return other;
		}
		
		const noware::any operator += (long double & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= noware::math::nr (LDBL_MIN) && tmp.content.number <= noware::math::nr (LDBL_MAX))
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (double & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= DBL_MIN && tmp.content.number <= DBL_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (float & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= FLT_MIN && tmp.content.number <= FLT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (signed long long int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= LLONG_MIN && tmp.content.number <= LLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (unsigned long long int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULLONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (signed long int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= LONG_MIN && tmp.content.number <= LONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (unsigned long int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= ULONG_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (signed int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= INT_MIN && tmp.content.number <= INT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (unsigned int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= UINT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (signed short int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= SHRT_MIN && tmp.content.number <= SHRT_MAX)
			//	other = tmp;
			
			return other;
		}
		
		const noware::any operator += (unsigned short int & other, const noware::any & self)
		{
			noware::any tmp = other + self;
			
			//if (tmp.content.t == noware::any::container::type::numeric && tmp.content.number >= 0 && tmp.content.number <= USHRT_MAX)
			//	other = tmp;
			
			return other;
		}
	//}
}

