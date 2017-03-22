#pragma once

#include "../any.hxx"
#include "../matrix.hxx"

namespace noware
{
	namespace net
	{
			class cluster
			{
				public:
					cluster (void);
					~cluster (void);
					
					const noware::any evaluate (const noware::matrix &/* message*/);
					//const noware::any respond (void);
			};
	}
}

