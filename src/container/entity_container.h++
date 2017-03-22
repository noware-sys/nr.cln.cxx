#ifndef __ENTITY_CONTAINER
#define __ENTITY_CONTAINER

#include <string>

#include "array.h++"
#include "entity.h++"

namespace LIB
{
	//namespace machine
	//{
		//class entity;
		
		class entity_container
		{
			public:
				entity_container (void);
				~ entity_container (void);
				
				//std::string text;
				//bool reference;
				LIB::NAME_V literal;
				
				LIB::array <LIB::entity, LIB::NAME_V> group;
		};
	//}
}

#endif