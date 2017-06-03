#pragma once

#include <string>

namespace noware
{
	namespace tool
	{
		namespace file
		{
			namespace content
			{
				const bool get (const std::string &/* path*/, std::string &/* content*/);
				const bool set (const std::string &/* path*/, const std::string &/* content*/);
			}	
		}
	}
}
