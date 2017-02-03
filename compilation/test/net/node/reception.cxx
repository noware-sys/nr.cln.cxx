#pragma once

#include "reception.hdr.cxx"

void receive (zyre_event_t * event)
{
	std::cout << "receive()::called" << std::endl;

	std::string event_type = zyre_event_type (event);
	//noware::tree <> message_zyre;
	//noware::tree <> message;

	std::cout << "receive():event_type==[" << event_type <<']' << std::endl;
}
