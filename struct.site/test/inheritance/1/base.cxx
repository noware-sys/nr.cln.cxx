#include <iostream>
#include "base.hxx"

static unsigned short int base::instance_count = 0;

base::base (void)
{
	std::cout << "base()" << std::endl;
	
	++instance_count;
}

base::~base (void)
{
	std::cout << "~base()" << std::endl;
	
	--instance_count;
}
