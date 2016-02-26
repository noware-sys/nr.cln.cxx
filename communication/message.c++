#include "message.h++"

LIB::communication::message::message (void)
{
}

LIB::communication::message::message (const LIB::communication::message & other)
{
	*this = other;
}

template <typename archive>
void LIB::communication::message::serialize (archive & _archive, const unsigned int & version)
{
	//archive & action;
	_archive & content;
}

//template <typename value, typename key>
const std::string LIB::communication::message::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const bool LIB::communication::message::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::communication::message> (serial, * this);
}

//template <typename value, typename key>
const std::string & LIB::communication::message::operator = (const std::string & serial)
{
	deserialize (serial);
	
	//return *this;
	return serial;
}

//template <typename value, typename key>
LIB::communication::message::operator const std::string (void) const
{
	return serialize ();
}

const LIB::communication::message & LIB::communication::message::operator = (const message & other)
{
	content = other.content;
	
	//return * this;
	return other;
}

const bool LIB::communication::message::operator == (const message & other) const
{
	return content == other.content;
}
