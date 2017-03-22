const noware::var noware::machine::storage::allocator::group_default = "allocator";

noware::machine::storage::allocator::allocator (void)
{
	//data.initialize ();
	data.initialize ("data.db");
	
	node.join (noware::machine::storage::allocator::group_default);
	node.join ("storage");
	//node.join ("storage.sqlite.persistent");
}

noware::machine::storage::allocator::~allocator (void)
{
	//node.leave ("storage.sqlite.persistent");
	node.leave ("storage");
	node.leave (noware::machine::storage::allocator::group_default);
	
	//data.finalize ();
}

/*
const bool noware::machine::storage::sqlite::finalize (void)
{
	if (!data.finalize ())
		return false;
	
	return true;
}

const bool noware::machine::storage::sqlite::initialize (void)
{
	if (!data.connect ("data.db"))
		return false;
	
	if (!data.query (query_sql_initial))
		return false;
	
	return true;
}
*/

const bool noware::machine::storage::allocator::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::machine::storage::sqlite::respond()::called" << std::endl;
	
	noware::tree <> response;
	bool result;
	
	result = false;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::machine::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "presence")
		//{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::machine::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			//unicast_local (zmsg_popstr (zmq_msg));
			result = unicast_local (message);
			std::cout << "noware::machine::storage::sqlite::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		std::cout << "noware::machine::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "presence")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value"] = data.exist (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			response ["value"] = data.magnitude ();
		}
		else if (message ["subject"] == "attainment")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value.present"] = data.exist (message ["group"], message ["key"]);
			if (response ["value.present"].get_value ())
				response ["value"] = data.get (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "settlement")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["presence"] = data.exist (message ["group"], message ["key"]);
			if (response ["presence"].get_value ())
				response ["success"] = data.set (message ["group"], message ["key"], message ["value"]);
			else
				response ["success"] = false;
		}
		else if (message ["subject"] == "removal")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.remove (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "resettal")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.reset ();
		}
		else
		{
			return false;
		}
		
		// Send back the answer.
		result = node.unicast (response, zyre_event_peer_uuid (event));
		std::cout << "noware::machine::storage::sqlite::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::machine::storage::allocator::search (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::machine::storage::sqlite::search()::called" << std::endl;
	
	if (message ["subject"] == "presence")
	{
		result = message ["value"];
		
		return !result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		//result += data.size ();
		result += message ["value"];
		
		return true;
	}
	else if (message ["subject"] == "attainment")
	{
		if (!(message ["value.present"].get_value ()))
		{
			return true;
		}
		
		result = message ["value"];
		
		return false;
	}
	else if (message ["subject"] == "settlement")
	{
		result = message ["success"];
		
		return !result;
	}
	else if (message ["subject"] == "removal")
	{
		result = message ["success"];
		//result = result && message ["success"];
		
		//if (!result)
		//{
			//result = true;
		//	return true;
		//}
		
		return result;
	}
	else if (message ["subject"] == "resettal")
	{
		result = message ["success"];
		//result = result && message ["success"];
		
		return result;
	}
	
	return false;
}

const bool noware::machine::storage::allocator::search_local (noware::var & result, const noware::tree <> & message)
{
	return false;
}

const noware::var noware::machine::storage::allocator::aggregate (const noware::var & result, const noware::var & response, const noware::tree <> & expression)
{
	if (expression ["subject"] == "magnitude")
	{
		return result + response;
	}
	
	return response;
}

const noware::nr noware::machine::storage::allocator::group_min (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "group.minimum";
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::group_max (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "group.maximum";
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::group_next (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "group.next";
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::group_avail (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "group.available";
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::key_min (const std::string & group)
{
	noware::tree <> expression;
	
	expression ["subject"] = "key.minimum";
	expression ["group"] = group;
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::key_max (const std::string & group)
{
	noware::tree <> expression;
	
	expression ["subject"] = "key.maximum";
	expression ["group"] = group;
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::key_next (const std::string & group)
{
	noware::tree <> expression;
	
	expression ["subject"] = "key.next";
	expression ["group"] = group;
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}

const noware::nr noware::machine::storage::allocator::key_avail (const std::string & group)
{
	noware::tree <> expression;
	
	expression ["subject"] = "key.available";
	expression ["group"] = group;
	
	return evaluate (expression, noware::machine::storage::allocator::group_default);
}
