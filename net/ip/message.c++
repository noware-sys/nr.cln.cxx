#include <iostream>
#include <fstream>
//#include <string>

#include "message.h++"

LIB::network::message::message (void)
{
}

LIB::network::message::~message (void)
{
}

LIB::network::message::operator std::string (void)
{
	return "";
}

bool LIB::network::message::operator = (const std::string &)
{
	return false;
}
