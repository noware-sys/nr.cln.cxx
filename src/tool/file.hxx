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
				const std::string get (const std::string &/* path of file*/);
				const bool set (const std::string &/* path*/, const std::string &/* content*/);
			}	
		}
	}
}
