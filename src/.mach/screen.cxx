#pragma once

/*
#include "screen.hxx"
#include "../serial.hxx"
#include <string>
#include <iostream>
*/

const std::string noware::mach::screen::grp_dft = "noware::mach::screen";

noware::mach::screen::screen (void)
{
	node.join (noware::mach::screen::grp_dft);
}

noware::mach::screen::~screen (void)
{
}

const bool noware::mach::screen::set (const std::string & value)
{
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "set";
	xpr ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, grp_dft) == "1";
}

const bool/* success*/ respond (const zyre_event_t * event, const std::string & event_type, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "set")
	{
		std::cout << request ["value"];
		msg_response = "1";
		//return true;
		return false;
	}
	
	msg_response = "0";
	return false;
}

const bool/* success*/ search (zmq::msg & msg_result, const zmq::msg & msg_response)
{
	std::map <std::string, std::string> response;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (response, std::string (msg_response)))
		return false;
	
	if (response ["subject"] == "set")
	{
		//std::cout << request ["value"];
		msg_result = response ["value"];
		//return msg_result == "1";
		return false;
	}
	
	msg_result = "0";
	return false;
}

const bool/* success*/ search_local (zmq::msg & msg_response, const zmq::msg & msg_request)
{
	std::map <std::string, std::string> request;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (request, std::string (msg_request)))
		return false;
	
	if (request ["subject"] == "set")
	{
		std::cout << request ["value"];
		msg_response = "1";
		//return true;
		return false;
	}
	
	msg_response = "0";
	return false;
}
