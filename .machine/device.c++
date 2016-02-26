/*
//#include <vector>
#include <sstream>
//#include <fstream>
#include <sstream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
//#include <boost/thread/exceptions.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
*/

//#include "device.h++"
#include ".device/index.c++"

LIB::machine::device::device (void)
{
	//_active = false;
	
	l = location::literal;
	t = type::other;
}
/*
LIB::machine::device::device (const device & other)
{
	* this = other;
}
*/

const bool LIB::machine::device::operator== (const LIB::machine::device & other) const
{
	if (t != other.t)
	{
		return false;
	}
	
	return true;
}

const LIB::machine::device::type & LIB::machine::device::get_type (void) const
{
	return t;
}

const LIB::machine::device::location & LIB::machine::device::get_location (void) const
{
	return l;
}
/*
const bool LIB::machine::device::run (const bool & state)
{
	if (state && !_active)
	{
		_active = state;
	}
	else if (!state && _active)
	{
		_active = state;
	}
	else
	{
		return true;
	}
	
	return false;
}

const bool LIB::machine::device::active (void) const
{
	return _active;
}
*/
