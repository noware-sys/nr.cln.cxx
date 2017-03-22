//#pragma once

//#include "processor.hdr.cxx"

noware::machine::queue::queue (void)
{
}

noware::machine::queue::~queue (void)
{
}

const noware::var noware::machine::queue::next (void) const
{
	return "";
}

const bool noware::machine::queue::dequeue (void)
{
	return false;
}

const bool noware::machine::queue::enqueue (const noware::var & element)
{
	return false;
}
