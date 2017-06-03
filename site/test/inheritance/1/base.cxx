#include <iostream>
#include "base.hxx"

unsigned short int base::instance_count = 0;

base::base (void)
{
	std::cout << "base()" << std::endl;
	value = "";
	
	++instance_count;
}

base::~base (void)
{
	std::cout << "~base()" << std::endl;
	
	--instance_count;
}

const std::string base::get (void) const
{
	return value;
}

const bool base::set (const std::string & value)
{
	this -> value = value;
	
	return this -> value == value;
}
