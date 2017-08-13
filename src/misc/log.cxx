#pragma once

#include "log.hxx"

#include <string>
#include <ofstream>

const bool noware::log (const std::string & file_name, const std::string & value)
{
	std::ofstream file;
	file.open (file_name);
	return log (file, value);
}

const bool noware::log (const std::ofstream & file, const std::string & value)
{
	if (!file.is_open ())
		return false;
	
}
