#pragma once

#include <string>
#include "base.hxx"

class derivative : public base
{
	public:
		derivative (void);
		~derivative (void);
		
		const std::string get (void) const;
};
