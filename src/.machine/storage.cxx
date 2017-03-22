//#pragma once

//#include "storage.hdr.cxx"
//#include <cstring>

const noware::var noware::machine::storage::group_default = "storage";

noware::machine::storage::storage (void)
{
//	node.initialize ();
//	node.start ();
	node.join (noware::machine::storage::group_default);
//	node.reception_set (boost::bind (boost::mem_fn (&noware::machine::storage::receive), this, _1));
	//node.reception_set (boost::mem_fn (&noware::machine::storage::receive));
	//node.reception_set (&noware::machine::storage::receive);
}

noware::machine::storage::~storage (void)
{
//	node.reception_unset ();
	node.leave (noware::machine::storage::group_default);
//	node.stop ();
//	node.finalize ();
}

//const noware::var noware::machine::storage::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

const noware::var noware::machine::storage::aggregate (const noware::var & result, const noware::var & response, const noware::tree <> & expression)
{
	if (expression ["subject"] == "magnitude")
	{
		return result + response;
	}
	
	return response;
}

const bool noware::machine::storage::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::machine::storage::respond()::called" << std::endl;
	
	noware::tree <> response;
	bool result;
	
	result = false;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::machine::storage::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "presence")
		//{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::machine::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			//unicast_local (zmsg_popstr (zmq_msg));
			result = unicast_local (message);
			std::cout << "noware::machine::storage::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		std::cout << "noware::machine::storage::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "presence")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["key"] = message ["key"];
			response ["value"] = data.exist (message ["key"]);
		}
		else if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			response ["value"] = data.size ();
		}
		else if (message ["subject"] == "obtainment")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["key"] = message ["key"];
			response ["value.present"] = data.exist (message ["key"]);
			if (response ["value.present"].get_value ())
				response ["value"] = data.get (message ["key"]);
		}
		else if (message ["subject"] == "settlement")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["key"] = message ["key"];
			response ["presence"] = data.exist (message ["key"]);
			if (response ["presence"].get_value ())
				response ["success"] = data.set (message ["key"], message ["value"]);
			else
				response ["success"] = false;
		}
		else if (message ["subject"] == "removal")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.unset (message ["key"]);
		}
		else if (message ["subject"] == "resettal")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.clear ();
		}
		else
		{
			return false;
		}
		
		// Send back the answer.
		result = node.unicast (response, zyre_event_peer_uuid (event));
		std::cout << "noware::machine::storage::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::machine::storage::search (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::machine::storage::search()::called" << std::endl;
	
	if (message ["subject"] == "presence")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		//result += data.size ();
		result += message ["value"];
		
		return false;
	}
	else if (message ["subject"] == "obtainment")
	{
		if (!(message ["value.present"].get_value ()))
		{
			return false;
		}
		
		result = message ["value"];
		
		return true;
	}
	else if (message ["subject"] == "settlement")
	{
		result = message ["success"];
		
		return result;
	}
	else if (message ["subject"] == "removal")
	{
		result = message ["success"];
		
		return !result;
	}
	else if (message ["subject"] == "resettal")
	{
		result = message ["success"];
		
		return !result;
	}
	
	return false;
}

const bool noware::machine::storage::search_local (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::machine::storage::search_local()::called" << std::endl;
	
	std::cout << "noware::machine::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//bool result;
	
	if (message ["subject"] == "presence")
	{
		result = data.exist (message ["key"]);
		
		//return true;
		return result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		result += data.size ();
		
		return false;
	}
	else if (message ["subject"] == "obtainment")
	{
		if (!data.exist (message ["key"]))
		{
			return false;
		}
		
		result = data.get (message ["key"]);
		
		return true;
	}
	else if (message ["subject"] == "settlement")
	{
		if (data.exist (message ["key"]))
		{
			result = data.set (message ["key"], message ["value"]);
			
			return true;
		}
		else if (!present (message ["key"]))
		{
			result = data.set (message ["key"], message ["value"]);
			
			return true;
		}
	}
	else if (message ["subject"] == "removal")
	{
		std::cout << "noware::machine::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::pre" << std::endl;
		if (data.exist (message ["key"]))
		{
			std::cout << "noware::machine::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::data.exists(" << message ["key"] << ")==true" << std::endl;
			
			result = data.unset (message ["key"]);
			
			return true;
		}
		std::cout << "noware::machine::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::post" << std::endl;
	}
	else if (message ["subject"] == "resettal")
	{
		result = data.clear ();
		
		return !result;
	}
	
	return false;
}

const bool noware::machine::storage::present (const noware::var & key) const
{
	
	//if (data.exists (name))
	//	return true;
	
	noware::tree <> expression;
	
	expression ["subject"] = "presence";
	expression ["key"] = key;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	
	return evaluate (expression, noware::machine::storage::group_default);
	//return evaluate ("/presence/" + name);
}

const noware::var noware::machine::storage::get (const noware::var & key) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "obtainment";
	expression ["key"] = key;
	
	return evaluate (expression, noware::machine::storage::group_default);
}

const bool noware::machine::storage::set (const noware::var & key, const noware::var & value)
{
	noware::tree <> expression;
	
	expression ["subject"] = "settlement";
	expression ["key"] = key;
	expression ["value"] = value;
	
	return evaluate (expression, noware::machine::storage::group_default);
}

//const noware::number::natural noware::machine::storage::magnitude (void) const
const noware::number noware::machine::storage::magnitude (void) const
//const unsigned int noware::machine::storage::magnitude (void) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "magnitude";
	
	return evaluate (expression, noware::machine::storage::group_default);
}
/*
const bool noware::machine::storage::empty (void) const
{
	//return 0;
	noware::tree <> message;
	
	message ["subject"] = "empty";
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return data.size ();
	
	//return nodes.respond () + data.size ();
	//return node.evaluate (message) + data.size ();
	return data.empty () && multicast (message);
}
*/
const bool noware::machine::storage::remove (const noware::var & key)
{
	noware::tree <> expression;
	
	expression ["subject"] = "removal";
	expression ["key"] = key;
	
	return evaluate (expression, noware::machine::storage::group_default);
}

const bool noware::machine::storage::reset (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "resettal";
	
	return evaluate (expression, noware::machine::storage::group_default);
}
