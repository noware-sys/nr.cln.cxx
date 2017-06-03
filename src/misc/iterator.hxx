#pragma once

namespace noware
{
	namespace misc
	{
		template <typename value>
		class iterator
		{
			public:
				// Necessary:
				// Should be implemented:
				virtual const iterator <value> begin (void) const;
				// Should be implemented:
				virtual const iterator <value> end (void) const;
				
				// Should be implemented:
				//virtual value & operator * (void);
				virtual const value operator * (void) const;
				virtual const bool operator != (const iterator <value> &/* other*/) const;
				// Should be implemented:
				virtual const iterator <value> operator ++ (void);
				
				
				// Additional:
				// Should be implemented:
				virtual const bool operator == (const iterator <value> &/* other*/) const;
				// Should be implemented:
				virtual const iterator <value> operator -- (void);
		};
	}
}

#include "iterator.cxx"
