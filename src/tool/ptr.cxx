#include "ptr.hxx"

#include <string>
#include <sstream>

const std::string noware::ptr::str (const void * ptr)
{
	std::stringstream ss;
	
	ss << static_cast <const void *> (ptr);
	
	return ss.str ();
}

const void * noware::ptr::val (const std::string & addr)
{
	void * ptr;
	std::stringstream ss;
	
	ss << addr;
	ss >> ptr;
	
	//return static_cast <const void *> (ptr);
	return ptr;
}

template <typename type>
constexpr bool noware::ptr::is_lvalue (const type &&)
{
	return std::is_lvalue_reference <type> {};
}
