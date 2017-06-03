#pragma once

#include <fstream>
#include <sstream>
#include "file.hdr.cxx"

const bool noware::tool::file::content::get (const std::string & path, std::string & content)
{
	/*
	ifstream file;
	std::streampos size;
	char * _content;
	std::string content;
	
	file.open (filename);
	
	if (!file.is_open ())
		return "";
	
	file.seekg (0, file.end);
	size = file.tellg ();
	
	_content = new char [size];
	
	file.seekg (0, file.beg);
	file.read (_content, size);
	file.close ();
	
	content = _content;
	delete [] _content;
	return content;
	*/
	
	ifstream file;
	ostringstream oss;
	
	file.open (path);
	
	if (!file.is_open ())
		return false;
	
	// http://stackoverflow.com/questions/116038/what-is-the-best-way-to-read-an-entire-file-into-a-stdstring-in-c
	//static_cast <const ostringstream &> (ostringstream () << file.rdbuf ()).str ();
	oss << file.rdbuf ();
	file.close ();
	content = oss.str ();
	
	return true;
}

const bool noware::tool::file::content::set (const std::string & path, const std::string & content)
{
	return false;
}
