#include <iostream>
#include "derivative.hxx"

derivative::derivative (void)
{
	std::cout << "derivative()" << std::endl;
}

derivative::~derivative (void)
{
	std::cout << "~derivative()" << std::endl;
}

const std::string derivative::get (void) const
{
	return "derivative.get(" + base::get () + ")";
}
