#pragma once

#include "serial.hxx"

//#include "../serial.cxx"

template <typename archive>
void noware::serial::serialize (archive &, const unsigned int &/* version*/)
{
}

const std::string noware::serial::serialize (void) const
{
	return noware::serialize <noware::serial> (*this);
}

const bool noware::serial::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::serial> (*this, serial);
}
