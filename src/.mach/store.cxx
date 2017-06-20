#pragma once

#include "store.hxx"
//#include <cstring>

const std::string noware::mach::store::grp_dft = "store";

noware::mach::store::store (void)
{
//	node.initialize ();
//	node.start ();
	node.join (noware::mach::store::grp_dft);
//	node.reception_set (boost::bind (boost::mem_fn (&noware::mach::store::receive), this, _1));
	//node.reception_set (boost::mem_fn (&noware::mach::store::receive));
	//node.reception_set (&noware::mach::store::receive);
}

noware::mach::store::~store (void)
{
//	node.reception_unset ();
	node.leave (noware::mach::store::grp_dft);
//	node.stop ();
//	node.finalize ();
}

//const noware::var noware::mach::store::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

const zmq::msg noware::mach::store::aggregate (const zmq::msg & result/* from search_local*/, noware::nr & responses_count, const zmq::msg & response/* from ...search*/, const zmq::msg & expression)
{
	//noware::tree <std::string, std::string> xpr;
	std::map <std::string, std::string> xpr;
	//noware::tree <std::string, std::string> resp_;
	//noware::tree <std::string, std::string> result_;
	noware::var resp;
	noware::var reslt;
	
	
	resp = std::string (response);
	reslt = std::string (result);
	
	//if (!xpr.deserialize (expression))
	if (!noware::deserialize <std::map <std::string, std::string>> (xpr, std::string (expression)))
		return response;
	
	if (xpr ["subject"] == "magnitude")
	{
		return (reslt + resp).operator const std::string ();
	}
	else if (xpr ["subject"] == "removal" || xpr ["subject"] == "clearance")
	{
		std::cout << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope" << std::endl;
		std::cout << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope::reponses_count==[" << responses_count << "]" << std::endl;
		
		//if (responses_count > noware::nr::natural (0))
		if (responses_count > 0)
		{
			std::cout << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::in scope" << std::endl;
			
			return zmq::msg ((result == "1" && response == "1") ? "1" : "0");
		}
		else
		{
			std::cout << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::else::in scope" << std::endl;
			
			return result;
		}
	}
	
	return response;
}

const bool noware::mach::store::respond (/*const zmsg_t * msg_rx*//* received message*//*, */const zyre_event_t * event)
{
	std::cout << "noware::mach::store::respond()::called" << std::endl;
	
	zmq::msg msg;
	zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	std::string event_type;
	
	zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	std::cout << "noware::mach::store::respond()::event==" << event_type << std::endl;
	if (zmsg == nullptr)
	{
		std::cout << "noware::mach::store::respond()::event_msg==nullptr" << std::endl;
		
		return false;
	}
	
	event_type = zyre_event_type (event);
	if (event_type != "WHISPER" && event_type != "SHOUT")
	{
		std::cout << "noware::mach::store::respond()::event not of interest" << std::endl;
	}
	std::cout << "noware::mach::store::respond()::event of interest" << std::endl;
	msg = zmsg;
	
	//noware::tree <std::string, std::string> response;
	std::map <std::string, std::string> response;
	//noware::tree <std::string, std::string> message;
	std::map <std::string, std::string> message;
	noware::var result_tmp;
	bool result;
	
//	zframe_t * frm;
	//noware::nr ndx;
	
	//data.clear ();
	//frm = zmsg_first (msg_rx);
//	frm = zmsg_first (zmsg);
	//ndx = 1;
	//while (frm != nullptr)
	//{
		// This makes a copy of the frame.
		//data [ndx] = *frm;
		
		//zframe_destroy (&f);
		
	//	frm = zmsg_next (&other);
	//	++ndx;
	//}
	
	//return other;
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
		return false;
	
	result = false;
	
	std::cout << "noware::mach::store::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::mach::store::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::mach::store::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg);
			std::cout << "noware::mach::store::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		//std::cout << "noware::mach::store::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "existence")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response = message;
			response ["type"] = "response";
			//response ["subject"] = message ["subject"];
			//response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
			try
			{
				data.at (message ["group"]).at (message ["key"]);
				response ["value"] = "1";
			}
			catch (...)
			{
				response ["value"] = "0";
			}
		}
		/*
		else if (message ["subject"] == "existence.group")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
				response ["value"] = data.exist (message ["group"]);
		}
		*/
		else if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			if (message.count ("group") > 0)
			{
				std::cout << "noware::mach::store::respond()::group[ed]" << std::endl;
				
				if (data.count (message ["group"]) > 0)
				{
					std::cout << "noware::mach::store::respond()::group::exist" << std::endl;
					response ["value"] = data [message ["group"]].size ();
				}
				else
				{
					std::cout << "noware::mach::store::respond()::group::not exist" << std::endl;
					response ["value"] = "0";
				}
			}
			else
			{
				std::cout << "noware::mach::store::respond()::not group[ed]" << std::endl;
				//response ["value"] = data.size ();
				//std::cout << "noware::mach::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
				result_tmp = 0;
				for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
				{
					result_tmp += group.second.size ();
				}
				response ["value"] = result_tmp.operator const std::string ();
				std::cout << "noware::mach::store::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
				std::cout << "noware::mach::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
			}
		}
		else if (message ["subject"] == "obtainment")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			
			try
			{
				response ["value"] = data.at (message ["group"]).at (message ["key"]);
				response ["value.exist"] = "1";
			}
			catch (...)
			{
				response ["value.exist"] = "0";
			}
		}
		else if (message ["subject"] == "settlement")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
			data [message ["group"]] [message ["key"]] = message ["value"];
			
			try
			{
				if (data.at (message ["group"]).at (message ["key"]) == message ["value"])
					response ["value"] = "1";
				else
					response ["value"] = "0";
			}
			catch (...)
			{
				response ["value"] = "0";
			}
		}
		else if (message ["subject"] == "removal")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			std::cout << "noware::mach::store::respond()::message[group]==" << message ["group"] << "" << std::endl;
			std::cout << "noware::mach::store::respond()::message[key]==" << message ["key"] << "" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			
			try
			{
				data.at (message ["group"]).erase (message ["key"]);
				response ["value"] = "1";
				
				if (data.at (message ["group"]).empty ())
					data.erase (message ["group"]);
			}
			catch (...)
			{
				// The group does not exist.
				response ["value"] = "1";
			}
		}
		else if (message ["subject"] == "clearance")
		{
			std::cout << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			data.clear ();
			response ["value"] = "1";
		}
		else
		{
			return false;
		}
		
		// Send back the answer.
		//result = node.unicast (zmq::msg (response.serialize ()), zyre_event_peer_uuid (event));
		std::string response_serial;
		if (!noware::serialize <std::map <std::string, std::string>> (response_serial, response))
			return false;
		result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
		
		//zmsg_response = zmsg_new ();
		//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
		//zmsg_append (zmsg_response, &zframe_response);
		
		//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
		std::cout << "noware::mach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::mach::store::search (zmq::msg & msg_result, const zmq::msg & msg_resp)
{
	std::cout << "noware::mach::store::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cout << "noware::mach::store::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cout << "noware::mach::store::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	if (resp ["subject"] == "existence")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	/*
	else if (message ["subject"] == "existence.group")
	{
		result = message ["value"];
		
		return result;
	}
	*/
	else if (resp ["subject"] == "magnitude")
	{
		std::cout << "noware::mach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.kind () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cout << "noware::mach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "obtainment")
	{
		if (resp ["value.exist"] == "0")
		{
			return false;
		}
		
		msg_result = resp ["value"];
		
		return true;
	}
	else if (resp ["subject"] == "settlement")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "removal")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	else if (resp ["subject"] == "clearance")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	
	return false;
}

const bool noware::mach::store::search_local (zmq::msg & msg_resp, const zmq::msg & msg_req)
{
	std::cout << "noware::mach::store::search_local()::called" << std::endl;
	
	//std::cout << "noware::mach::store::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//noware::tree <std::string, std::string> req;
	std::map <std::string, std::string> req;
	//noware::tree <std::string, std::string> resp;
	//noware::var resp;
	std::cout << "noware::mach::store::search_local()::req" << std::endl;
	noware::var result;
	//bool result;
	std::cout << "noware::mach::store::search_local()::result" << std::endl;
	
	//if (!req.deserialize (msg_req))
	if (!noware::deserialize <std::map <std::string, std::string>> (req, std::string (msg_req)))
	{
		std::cout << "noware::mach::store::search_local()::deserialize::false" << std::endl;
		return false;
	}
	
	std::cout << "noware::mach::store::search_local()::deserialize" << std::endl;
	
	//resp ["subject"] = req ["subject"];
	
	std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
	
	if (req ["subject"] == "existence")
	{
		std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
		
		try
		{
			std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::req.group" << std::endl;
			const std::string group_name = req.at ("group");
			std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::data.group" << std::endl;
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::data.key" << std::endl;
			//const std::string value = data.at (req.at ("group")).at (req.at ("key"));
			const std::string value = group.at (req.at ("key"));
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::msg_resp=\"1\"" << std::endl;
			msg_resp = "1";
			std::cout << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::return" << std::endl;
			return true;
		}
		catch (...)
		{
		}
		
		//resp ["value"] = "0";
		//msg_resp = resp.serialize ();
		msg_resp = "0";
		return false;
	}
	else if (req ["subject"] == "magnitude")
	{
		//if (result.type () != noware::var::container::type::numeric)
		result = 0;
		
		try
		{
			const std::string group_name = req.at ("group");
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			
			//result += data.at (req.at ("group")).size ();
			result += group.size ();
		}
		catch (...)
		{
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result += group.second.size ();
			}
		}
		
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		msg_resp = result;
		std::cout << "noware::mach::store::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cout << "noware::mach::store::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
	}
	else if (req ["subject"] == "obtainment")
	{
		try
		{
			const std::string group_name = req.at ("group");
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			//const std::string value = data.at (req.at ("group")).at (req.at ("key"));
			const std::string value = group.at (req.at ("key"));
			
			//resp ["value"] = value;
			//msg_resp = resp.serialize ();
			msg_resp = value;
			return true;
		}
		catch (...)
		{
		}
		
		//msg_resp = "0";
		return false;
	}
	else if (req ["subject"] == "settlement")
	{
		try
		{
			data [req.at ("group")] [req.at ("key")] = req.at ("value");
			//const std::map <std::string, std::string> & group = data.at (req.at ("group"));
			//std::string & value = data.at (req.at ("group")).at (req.at ("key"));
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			msg_resp = "1";
			return true;
		}
		catch (...)
		{
		}
		
		msg_resp = "0";
		return false;
	}
	else if (req ["subject"] == "removal")
	{
		try
		{
			data [req.at ("group")].erase (req.at ("key"));
			
			if (data [req.at ("group")].empty ())
				data.erase (req.at ("group"));
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			//return true;
		}
		catch (...)
		{
		}
		
		// The group/key was absent...
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		msg_resp = "1";
		
		return true;
	}
	else if (req ["subject"] == "clearance")
	{
		try
		{
			const std::string group_name = req.at ("group");
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			
			data.erase (req.at ("group"));
		}
		catch (...)
		{
			/*result = */data.clear ();
		}
		//resp ["subject"] = req ["subject"];
		
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		msg_resp = "1";
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		
		//return !result;
		return false;
	}
	/*
	else if (message ["subject"] == "iteration")
	{
		for (const noware::array <noware::array <>>::container & group : data)
		{
			for (const noware::array <>::container & key : group)
			{
				if (iterations >= message ["iterations"])
				{
					result = key.v;
					
					break;
				}
				
				++ iterations;
			}
			
			if (iterations >= message ["iterations"])
			{
				break;
			}
		}
		
		return false;
	}
	*/
	
	return false;
}

const bool noware::mach::store::exist (const std::string & key) const
{
	return exist (std::string (""), key);
}

const bool noware::mach::store::exist (const std::string & group, const std::string & key) const
{
	//return !get (group, key).empty ();
	
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const std::string noware::mach::store::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const std::string noware::mach::store::get (const std::string & group, const std::string & key) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft);
}

const bool noware::mach::store::set (const std::string & key, const std::string & value)
{
	return set ("", key, value);
}

const bool noware::mach::store::set (const std::string & group, const std::string & key, const std::string & value)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "settlement";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

//const noware::nr::natural noware::mach::store::size (void) const
const noware::nr noware::mach::store::size (void) const
//const unsigned int noware::mach::store::size (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "magnitude";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cout << "noware::mach::store::size()::serialize::failure" << std::endl;
		
		return 0;
	}
	std::cout << "noware::mach::store::size()::serialize::success" << std::endl;
	
	/*
	expression.clear ();
	std::cout << "noware::mach::store::size()::expression.size ()==[" << expression.size () << ']' << std::endl;
	
	std::cout << "noware::mach::store::size()::expression.deserialize()::..." << std::endl;
	if (!noware::deserialize <std::map <std::string, std::string>> (expression, expression_serial))
	{
		std::cout << "noware::mach::store::size()::deserialize::failure" << std::endl;
		return 0;
	}
	
	std::cout << "noware::mach::store::size()::deserialized:" << std::endl;
	std::cout << '[' << std::endl;
	std::cout << expression_serial << std::endl;
	std::cout << ']' << std::endl;
	std::cout << "noware::mach::store::size()::expression.size ()==[" << expression.size () << ']' << std::endl;
	
	std::cout << "noware::mach::store::size()::zmq::msg(str):" << std::endl;
	std::cout << '[' << std::endl;
	std::cout << std::string (zmq::msg (expression_serial)) << std::endl;
	//zmq::msg test (expression_serial);
	//std::cout << '}' << std::endl;
	//std::cout << test.data [1].operator const std::string ();
	std::cout << ']' << std::endl;
	
	std::cout << "noware::mach::store::size()::assert()..." << std::endl;
	assert (expression_serial == std::string (zmq::msg (expression_serial)));
	std::cout << "noware::mach::store::size()::assert()...OK" << std::endl;
	*/
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const noware::nr noware::mach::store::size (const std::string & group) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "magnitude";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const bool noware::mach::store::empty (void) const
{
	return size () <= 0;
}

const bool noware::mach::store::full (void) const
{
	return false;
}

const bool noware::mach::store::remove (const std::string & key)
{
	return remove ("", key);
}

const bool noware::mach::store::remove (const std::string & group, const std::string & key)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::store::clear (void)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::store::clear (const std::string & group)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

/*
template <typename value>
virtual const iterator <value> noware::mach::store::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::operator -- (void)
{
}

template <typename value>
virtual const bool noware::mach::store::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::mach::store::operator * (void) const
{
}
*/