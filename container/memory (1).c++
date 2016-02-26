#include "memory.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

// Memory: Iterator:

/*LIB::memory::iterator::iterator (void)
{
}

LIB::memory::iterator::iterator (const memory & other)
{
	operator = (other);
}

LIB::memory::iterator::~iterator (void)
{
}

const LIB::memory::iterator & LIB::memory::iterator::operator = (const iterator & other)
{
	return *this;
}*/

const bool LIB::memory::iterator::operator == (const iterator & other) const
{
	return true;
}

const bool LIB::memory::iterator::operator != (const iterator & other) const
{
	return !operator == (other);
}

const LIB::memory::iterator & LIB::memory::iterator::operator ++ (void)
{
	return *this;
}

const LIB::memory::iterator & LIB::memory::iterator::operator -- (void)
{
	return *this;
}

// Memory:

LIB::memory::memory (void)
{
}

LIB::memory::memory (const memory & other)
{
}

LIB::memory::~memory (void)
{
}

template <typename archive>
void LIB::memory::save (archive & arch, const unsigned int & version) const
{}

template <typename archive>
void LIB::memory::load (archive & arch, const unsigned int & version)
{}

const LIB::memory::value LIB::memory::get (const LIB::memory::key & name, const LIB::memory::key & group) const
{}

const bool LIB::memory::set (const LIB::memory::value &, const LIB::memory::key & name, const LIB::memory::key & group)
{
	return true;
}

const bool LIB::memory::unset (const LIB::memory::key & name, const LIB::memory::key & group)
{
	return true;
}

const bool LIB::memory::rename (const LIB::memory::key & old_name, const LIB::memory::key & new_name, const LIB::memory::key & old_group, const LIB::memory::key & new_group)
{
	return true;
}

const bool LIB::memory::exists (const LIB::memory::key & name, const LIB::memory::key & group) const
{
	return true;
}

const bool LIB::memory::operator == (const LIB::memory & other) const
{}

const bool LIB::memory::operator != (const LIB::memory & other) const
{
	return ! operator == (other);
}

const LIB::memory & LIB::memory::operator = (const LIB::memory::memory & other)
{
	return * this;
}

const LIB::mathematics::numbers::natural LIB::memory::size (void) const
{}

const bool LIB::memory::clear (void) const
{
	return true;
}

const bool LIB::memory::empty (void) const
{
	return false;
}

const bool LIB::memory::full (void) const
{
	return false;
}

const LIB::memory LIB::memory::operator + (const LIB::memory::value & val) const
{}

const LIB::memory LIB::memory::operator + (const LIB::memory & other) const
{}

const LIB::memory & LIB::memory::operator += (const LIB::memory::value & val)
{}

const LIB::memory & LIB::memory::operator += (const LIB::memory & other)
{}

const bool LIB::memory::add (const LIB::memory::value & val)
{}

const bool LIB::memory::add (const LIB::memory::value & val, LIB::memory::key & used_key)
{}

const bool LIB::memory::add (const LIB::memory & other)
{}

const bool LIB::memory::append (const LIB::memory::value & val)
{}

const bool LIB::memory::append (const LIB::memory::value & val, LIB::memory::key & key_used)
{}

const bool LIB::memory::append (const LIB::memory & other)
{}

const LIB::memory::key LIB::memory::least_key (void) const
{}

const LIB::memory::key LIB::memory::greatest_key (void) const
{}

const bool LIB::memory::enqueue (const LIB::memory::value & val)
{}

const bool LIB::memory::enqueue (const LIB::memory::value & val, LIB::memory::key & used_key)
{}

const bool LIB::memory::dequeue (void)
{}

const LIB::memory::value & LIB::memory::beginning (void) const
{}

const LIB::memory::value & LIB::memory::ending (void) const
{}

const bool LIB::memory::push (const LIB::memory::value & val)
{}

const bool LIB::memory::push (const LIB::memory::value & val, LIB::memory::key & used_key)
{}

const bool LIB::memory::pop (void)
{}

//const bool LIB::memory::numeric_key (void) const
//{}

const LIB::memory::key LIB::memory::sequence_next_available (void) const
{}

const LIB::memory::key LIB::memory::sequence_next (void) const
{}

const LIB::memory::iterator & LIB::memory::begin (void) const
{}

const LIB::memory::iterator & LIB::memory::end (void) const
{}

const LIB::memory::iterator & LIB::memory::begin (void)
{}

const LIB::memory::iterator & LIB::memory::end (void)
{}

const std::string LIB::memory::serialize (void) const
{
	return "";
}

const bool LIB::memory::deserialize (const std::string & serial)
{
	return true;
}

operator const std::string (void) const
{
	return serialize ();
}

const LIB::memory & operator = (const std::string & serial)
{
	return * this;
}
