#ifndef MESSAGE
#define MESSAGE

#include <string>
#include <sstream>

//#include "Lexical_Analyzer"
//#include "peers.h++"

#include "../containers/array.h++"
#include "../containers/variable.h++"
//#include "memory.hpp"
//#include "processor.hpp"
//#include "interpreter.hpp"

namespace LIB
{
	namespace cluster
	{
		class message
		{
			public:
				//message (void);
				//~message (void);
				
				enum class content {address, action, data};
				enum class action {respond, ask, answer, get, got, set, unset, exists, rename};
				
				LIB::NAME_V id;	// Identifier for the member.
				//std::string address;
				
				action act;
				
				
		};
	}
}

#endif
