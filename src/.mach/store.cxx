#pragma once

#include "storage.hxx"
//#include <cstring>

const noware::var noware::mach::storage::group_default = "storage";

noware::mach::storage::storage (void)
{
//	node.initialize ();
//	node.start ();
	node.join (noware::mach::storage::group_default);
//	node.reception_set (boost::bind (boost::mem_fn (&noware::mach::storage::receive), this, _1));
	//node.reception_set (boost::mem_fn (&noware::mach::storage::receive));
	//node.reception_set (&noware::mach::storage::receive);
}

noware::mach::storage::~storage (void)
{
//	node.reception_unset ();
	node.leave (noware::mach::storage::group_default);
//	node.stop ();
//	node.finalize ();
}

//const noware::var noware::mach::storage::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

const noware::var noware::mach::storage::aggregate (const noware::var & result, noware::nr::natural & responses_count, const noware::var & response, const noware::tree <> & expression)
{
	if (expression ["subject"] == "magnitude")
	{
		return result + response;
	}
	else if (expression ["subject"] == "removal" || expression ["subject"] == "clearance")
	{
		std::cout << "noware::mach::storage::respond()::if::expression[subject]==" << expression ["subject"] << "::in scope" << std::endl;
		std::cout << "noware::mach::storage::respond()::if::expression[subject]==" << expression ["subject"] << "::in scope::reponses_count==[" << responses_count << "]" << std::endl;
		
		if (responses_count > noware::nr::natural (0))
		{
			std::cout << "noware::mach::storage::respond()::if::(responses_count > noware::nr::natural (0))" << "::in scope" << std::endl;
			
			return result && response;
		}
		else
		{
			std::cout << "noware::mach::storage::respond()::if::(responses_count > noware::nr::natural (0))" << "::else::in scope" << std::endl;
			
			return result;
		}
	}
	
	return response;
}

const bool noware::mach::storage::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::mach::storage::respond()::called" << std::endl;
	
	noware::tree <> response;
	bool result;
	
	result = false;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::mach::storage::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::mach::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			//unicast_local (zmsg_popstr (zmq_msg));
			result = unicast_local (message);
			std::cout << "noware::mach::storage::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		std::cout << "noware::mach::storage::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "existence")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
				response ["value"] = data.exist (message ["group"]) && data [message ["group"]].exist (message ["key"]);
		}
		else if (message ["subject"] == "existence.group")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
				response ["value"] = data.exist (message ["group"]);
		}
		else if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			if (message.exist ("group"))
			{
				if (!data.exist (message ["group"]))
					response ["value"] = 0;
				else
					response ["value"] = data [message ["group"]].size ();
			}
			else
			{
				response ["value"] = data.size ();
			}
		}
		else if (message ["subject"] == "obtainment")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			
			if (!data.exist (message ["group"]))
				response ["value.exist"] = false;
			else if (!data [message ["group"]].exist (message ["key"]))
				response ["value.exist"] = false;
			else
				response ["value.exist"] = true;
			//response ["value.exist"] = data.exist (message ["key"]);
			
			if (response ["value.exist"].get_value ())
				response ["value"] = data.get (message ["group"]).get (message ["key"]);
		}
		else if (message ["subject"] == "settlement")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
			if (response ["existence"].get_value ())
				response ["value"] = data.get (message ["group"]).set (message ["key"], message ["value"]);
			else
				response ["value"] = false;
		}
		else if (message ["subject"] == "removal")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			std::cout << "noware::mach::storage::respond()::message[group]==" << message ["group"] << "" << std::endl;
			std::cout << "noware::mach::storage::respond()::message[key]==" << message ["key"] << "" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			if (!data.exist (message ["group"]))
			{
				std::cout << "noware::mach::storage::respond()::if::(!data.exist (message [group]))==true::in scope" << std::endl;
				response ["value"] = true;
			}
			else
			{
				std::cout << "noware::mach::storage::respond()::if::(!data.exist (message [group]))==false::in scope" << std::endl;
				
				if (!data.get (message ["group"]).exist (message ["key"]))
				{
					std::cout << "noware::mach::storage::respond()::if::(!data.get (message [group]).exist (message [key]))==true::in scope" << std::endl;
					//std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
					response ["value"] = true;
				}
				else
				{
					response ["value"] = data.get (message ["group"]).unset (message ["key"]);
				}
				
				if (data.get (message ["group"]).empty ())
					response ["value"] = response ["value"].get_value () && data.unset (message ["group"]);
			}
		}
		else if (message ["subject"] == "clearance")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["value"] = data.clear ();
		}
		else
		{
			return false;
		}
		
		// Send back the answer.
		result = node.unicast (response, zyre_event_peer_uuid (event));
		std::cout << "noware::mach::storage::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::mach::storage::search (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::mach::storage::search()::called" << std::endl;
	
	if (message ["subject"] == "existence")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "existence.group")
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
		if (!(message ["value.exist"].get_value ()))
		{
			return false;
		}
		
		result = message ["value"];
		
		return true;
	}
	else if (message ["subject"] == "settlement")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "removal")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "clearance")
	{
		result = message ["value"];
		
		return result;
	}
	
	return false;
}

const bool noware::mach::storage::search_local (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::mach::storage::search_local()::called" << std::endl;
	
	std::cout << "noware::mach::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//bool result;
	
	if (message ["subject"] == "existence")
	{
		//result = data [message ["group"]].exist (message ["key"]);
		if (!data.exist (message ["group"]))
			result = false;
		else if (!data [message ["group"]].exist (message ["key"]))
			result = false;
		else
			result = true;
		
		//return true;
		return result;
	}
	else if (message ["subject"] == "existence.group")
	{
		//result = data [message ["group"]].exist (message ["key"]);
		if (!data.exist (message ["group"]))
			result = false;
		//else if (!data [message ["group"]].exist (message ["key"]))
		//	result = false;
		else
			result = true;
		
		//return true;
		return result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		if (message.exist ("group"))
		{
			if (data.exist (message ["group"]))
			{
				result += data [message ["group"]].size ();
			}
			//else
			//{
			//	result += 0;
			//}
		}
		else
		{
			//for (item : data)
			//{
			//	
			//}
			result += data.size ();
		}
		
		return false;
	}
	else if (message ["subject"] == "obtainment")
	{
		if (!data.exist (message ["group"]))
		{
			return false;
		}
		
		if (!data [message ["group"]].exist (message ["key"]))
		{
			return false;
		}
		
		result = data [message ["group"]].get (message ["key"]);
		
		return true;
	}
	else if (message ["subject"] == "settlement")
	{
		/*
		if (data.exist (message ["group"]))
		{
			result = data.set (message ["key"], message ["value"]);
			
			return true;
		}
		*/
		
		if (data.exist (message ["group"]) && data [message ["group"]].exist (message ["key"]))
		{
			result = data [message ["group"]].set (message ["key"], message ["value"]);
			
			return true;
		}
		else if (!exist (message ["group"], message ["key"]))
		{
			result = data [message ["group"]].set (message ["key"], message ["value"]);
			
			return true;
		}
		else
		{
			result = false;
			
			return false;
		}
	}
	else if (message ["subject"] == "removal")
	{
		/*
			"result" represents the success if the request was fulfilled.
		*/
		
		std::cout << "noware::mach::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::pre" << std::endl;
		std::cout << "noware::mach::storage::search_local()::message[group]==[" << message ["group"] << ']' << "::pre" << std::endl;
		std::cout << "noware::mach::storage::search_local()::message[key]==[" << message ["key"] << ']' << "::pre" << std::endl;
		/*
		if (!exist (message ["group"], message ["key"]))
		{
			result = true;
			
			return true;
		}
		*/
		if (!data.exist (message ["group"])/* && !data [message ["group"]].exist (message ["key"])*/)
		{
			std::cout << "noware::mach::storage::search_local()::if::(!data.exist (message [group]))::in scope" << std::endl;
			
			result = true;
			
			//return !result;
			return false;
		}
		else //if (!exist (message ["group"], message ["key"]))
		{
			std::cout << "noware::mach::storage::search_local()::if::(!data.exist (message [group]))::else::in scope" << std::endl;
			
			//std::cout << "noware::mach::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::data [message[\"group\"]==" << message ["group"] << "].exist(message[\"key\"]==" << message ["key"] << ")==true" << std::endl;
			
			if (!data [message ["group"]].exist (message ["key"]))
			{
				std::cout << "noware::mach::storage::search_local():if::(!data [message [\"group\"]].exist (message [\"key\"]))::in scope" << std::endl;
				result = true;
				
				return false;
			}
			else
			{
				std::cout << "noware::mach::storage::search_local():if::(!data [message [\"group\"]].exist (message [\"key\"]))::else::in scope" << std::endl;
				result = data [message ["group"]].unset (message ["key"]);
			}
			
			if (data [message ["group"]].empty ())
			{
				std::cout << "noware::mach::storage::search_local():if::data [message [\"group\"]].empty ()::in scope" << std::endl;
				result = result && data.unset (message ["group"]);
			}
			
			std::cout << "noware::mach::storage::search_local():return::result::[" << result << "]" << std::endl;
			//return !result;
			//return result;
			return false;
		}
		std::cout << "noware::mach::storage::search_local()::message[subject]==[" << message ["subject"] << ']' << "::post" << std::endl;
		//
		//std::cout << "noware::mach::storage::search_local():return::result::[" << result << "]" << std::endl;
		////return !result;
		//return result;
	}
	else if (message ["subject"] == "clearance")
	{
		result = data.clear ();
		
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

const bool noware::mach::storage::exist_group (const noware::var & group) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "existence.group";
	expression ["group"] = group;
	//expression ["key"] = key;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	
	return evaluate (expression, noware::mach::storage::group_default);
	//return evaluate ("/existence/" + name);
}

const bool noware::mach::storage::exist (const noware::var & key) const
{
	return exist (noware::array <>::sqlite::group_default, key);
}

const bool noware::mach::storage::exist (const noware::var & group, const noware::var & key) const
{
	
	//if (data.exists (name))
	//	return true;
	
	noware::tree <> expression;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	
	return evaluate (expression, noware::mach::storage::group_default);
	//return evaluate ("/existence/" + name);
}

const noware::var noware::mach::storage::get (const noware::var & key) const
{
	return get (noware::array <>::sqlite::group_default, key);
}

const noware::var noware::mach::storage::get (const noware::var & group, const noware::var & key) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	return evaluate (expression, noware::mach::storage::group_default);
}

const bool noware::mach::storage::set (const noware::var & key, const noware::var & value)
{
	return set (noware::array <>::sqlite::group_default, key, value);
}

const bool noware::mach::storage::set (const noware::var & group, const noware::var & key, const noware::var & value)
{
	noware::tree <> expression;
	
	expression ["subject"] = "settlement";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	return evaluate (expression, noware::mach::storage::group_default);
}

//const noware::nr::natural noware::mach::storage::size (void) const
const noware::nr noware::mach::storage::size (void) const
//const unsigned int noware::mach::storage::size (void) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "magnitude";
	
	return evaluate (expression, noware::mach::storage::group_default);
}

const noware::nr noware::mach::storage::size (const noware::var & group) const
//const unsigned int noware::mach::storage::size (void) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "magnitude";
	expression ["group"] = group;
	
	return evaluate (expression, noware::mach::storage::group_default);
}
/*
const bool noware::mach::storage::empty (void) const
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
const bool noware::mach::storage::remove (const noware::var & group, const noware::var & key)
{
	noware::tree <> expression;
	
	expression ["subject"] = "removal";
	expression ["group"] = group;
	expression ["key"] = key;
	
	return evaluate (expression, noware::mach::storage::group_default);
}

const bool noware::mach::storage::remove (const noware::var & key)
{
	return remove (noware::array <>::sqlite::group_default, key);
}

const bool noware::mach::storage::clear (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "clearance";
	
	return evaluate (expression, noware::mach::storage::group_default);
}
/*
template <typename value>
virtual const iterator <value> noware::mach::storage::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::operator -- (void)
{
}

template <typename value>
virtual const bool noware::mach::storage::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::mach::storage::operator * (void) const
{
}
*/