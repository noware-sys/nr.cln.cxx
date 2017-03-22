//#include "library.h++"
#include "container/array.h++"

namespace LIB
{
	// http://stackoverflow.com/questions/6907194/how-to-typedef-a-template-class
	
	template <typename value = container::NAME_V, typename key = container::NAME_V>
	using NAME_A = container::NAME_A <value, key>;
	/*
	template <typename value = containers::NAME_V, typename key = containers::NAME_V>
	class NAME_A
	{
		typedef containers::NAME_A <typename value, typename key> type;
	};
	*/
}
