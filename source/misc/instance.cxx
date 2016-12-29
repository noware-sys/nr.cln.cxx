#include "instance.hxx"

//unsigned int noware::misc::instance::cout = 0;

noware::misc::instance::instance (void)
{
	//++ count;
}

noware::misc::instance::~instance (void)
{
	//-- count;
}

const unsigned int noware::misc::instance::id (void) const
{
	return _id;
}

const unsigned int noware::misc::instance::count (void) const
{
	return 0;
}
