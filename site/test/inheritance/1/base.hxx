#pragma once

#include <string>

class base
{
	public:
		base (void);
		virtual ~base (void);
	//protected:
		static unsigned short int instance_count;
		
		virtual const std::string get (void) const;
		virtual const bool set (const std::string &/* value*/);
	protected:
		std::string value;
};
