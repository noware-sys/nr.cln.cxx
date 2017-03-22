//#include "library.h++"
#include "array.h++"

namespace LIB
{
	namespace container
	{
		// http://stackoverflow.com/questions/6907194/how-to-typedef-a-template-class
		
		template <typename value = NAME_V, typename key = NAME_V>
		using set = NAME_A <value, key>;
		/*
		template <typename value = containers::NAME_V, typename key = containers::NAME_V>
		class NAME_A
		{
			typedef containers::NAME_A <typename value, typename key> type;
		};
		*/
	}
}

