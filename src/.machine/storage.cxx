//#include "storage.hdr.cxx"
//#include <cstring>

const noware::var noware::machine::storage::group_default = "";

noware::machine::storage::storage (void)
{
	node.initialize ();
	node.start ();
	node.join ("storage");
	node.reception_set (boost::bind (boost::mem_fn (&noware::machine::storage::receive), this, _1));
	//node.reception_set (boost::mem_fn (&noware::machine::storage::receive));
	//node.reception_set (&noware::machine::storage::receive);
}

noware::machine::storage::~storage (void)
{
	node.reception_unset ();
	node.leave ("storage");
	node.stop ();
	node.finalize ();
}

//const noware::var noware::machine::storage::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

const bool noware::machine::storage::exists (const noware::var & name) const
{
	if (data.exists (name))
		return true;
	
	noware::tree <> message;
	
	message ["subject"] = "exists";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const noware::var noware::machine::storage::get (const noware::var & name) const
{
	if (data.exists (name))
		return data [name];
	else if (!exists (name))
		return "";
	
	noware::tree <> message;
	
	message ["subject"] = "get";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return "";
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const bool noware::machine::storage::set (const noware::var & name, const noware::var & content)
{
	if (!data.exists (name) && exists (name))
	{
		noware::tree <> message;
	
		message ["subject"] = "set";
		message ["name"] = name;
		message ["content"] = content;
		
		
		return multicast (message);
	}
	else //if (data.exists (name))
		return data.set (name, content);
	
	/*
	noware::tree <> message;
	
	message ["subject"] = "set";
	message ["name"] = name;
	message ["content"] = content;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
	*/
}

//const noware::number::natural noware::machine::storage::magnitude (void) const
const noware::number noware::machine::storage::magnitude (void) const
//const unsigned int noware::machine::storage::magnitude (void) const
{
	//return 0;
	noware::tree <> message;
	
	message ["subject"] = "magnitude";
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return data.size ();
	
	//return nodes.respond () + data.size ();
	//return node.evaluate (message) + data.size ();
	
  noware::var result = multicast (message);
  std::cout << "noware::machine::storage::magnitude()::data.size()==[" << data.size () << ']' << std::endl;
  std::cout << "noware::machine::storage::magnitude()::multicast(message)==[" << result << ']' << std::endl;
  std::cout << "noware::machine::storage::magnitude()::multicast(message)+data.size()==[" << result + data.size () << ']' << std::endl;
  
  result += data.size ();
  std::cout << "noware::machine::storage::magnitude()::multicast(message)+=data.size()==[" << result << ']' << std::endl;
	//return ((noware::number::natural) (multicast (message).text ().c_str ())) + data.size ();
	//return multicast (message) + data.size ();
	//return result + data.size ();
	return result;
}

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

const bool noware::machine::storage::remove (const noware::var & name)
{
	if (data.exists (name))			// Only local (this zyre node).
		return data.unset (name);
	else if (!exists (name))		// Entire cluster.
		return true;
	
	noware::tree <> message;
	
	message ["subject"] = "remove";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const bool noware::machine::storage::clear (void)
{
	if (!data.clear ())
		return false;
	
	noware::tree <> message;
	
	message ["subject"] = "clear";
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const noware::var noware::machine::storage::unicast (const noware::tree <> & message, const std::string & peer)
{
	return "";
}

const noware::var noware::machine::storage::multicast (noware::tree <> message, const std::string & group)
{
	std::cout << "noware::machine::storage::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	
	std::string filter;
	
	filter = "";
	filter += (noware::var) '/' + "response";
	
	//if (message.exists ("subject"))
		filter += (noware::var) '/' + message ["subject"];
	
	//filter += (noware::var) '/' + message ["type"];
	
	//if (message.exists ("name"))
		filter += (noware::var) '/' + message ["name"];
	
	//if (message.exists ("content"))
	//	filter += '/' + message ["content"];
	
	// Data, collapsed into a string.
	//message ["filter"] = filter;
	
	if (!node.multicast (/*filter + */message, group))
	{
		std::cout << "noware::machine::storage::multicast()::node.multicast()::failure" << std::endl;
		return "";
	}
	
	std::cout << "noware::machine::storage::multicast()::node.multicast()::success" << std::endl;
	return receive_local (message ["subject"].get_value (), filter);
	
	/*
	// Prepare for reception.
	zmq::context_t context (1);
	zmq::socket_t receiver (context, ZMQ_SUB);
	receiver.connect ("tcp://127.0.0.1:5555");
	
	// Subscribe only to the answer we asked for.
	receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), filter.length ());
	
	noware::tree <> response;
	//std::stringstream ss;
	zmq::message_t response_zmq;
	for (;;)
	{
		receiver.recv (&response_zmq);
		//ss << static_cast <char *> (response_zmq.data ());
		// Parse the message into a tree object.
		//response.deserialize (ss.to_string ());
		//response.deserialize (static_cast <char *> (response_zmq.data ()));
		//if ()
		//ss.clear ();
	}
	*/
}

void noware::machine::storage::receive (const zyre_event_t * event)
{
  std::cout << "noware::machine::storage::receive()::called" << std::endl;
  
	std::string event_type = zyre_event_type (event);
	//noware::tree <> message_zyre;
	//noware::tree <> message;
	
  std::cout << "noware::machine::storage::receive()::event_type==[" << event_type << ']' << std::endl;
  
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
	  std::cout << "noware::machine::storage::receive()::event_type==(WHISPER||SHOUT)==[" << event_type << ']' << "::in scope" << std::endl;
	  
		zmsg_t * zmq_msg;
	
		if (zmq_msg != nullptr)
		{
		  std::cout << "noware::machine::storage::receive()::zmq_msg!=nullptr" << std::endl;
			//std::string msg;
			noware::tree <> msg;
			
			// First, get the message from the zyre peer.
			zmq_msg = zyre_event_msg (event);
			
			//msg = zmsg_popstr (zmq_msg);
			msg.deserialize (zmsg_popstr (zmq_msg));
			
			//std::cout << "*zmq_msg==" << '[' << (const char *) zmq_msg << ']' << std::endl;
			//std::cout << "zmsg_popstr(zmq_msg)==" << '[' << zmsg_popstr (zmq_msg) << ']' << std::endl;
			std::cout << "msg.serialize()==" << '[' << msg.serialize () << ']' << std::endl;
			
			
		  bool result;
		  std::cout << "noware::machine::storage::receive()::msg[subject]==[" << msg ["subject"] << ']' << std::endl;
		  
			if (msg ["subject"] == "exists")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
			  
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "exists";
				response ["zyre.uuid"] = zyre_uuid (node.zyre ());
				response ["content"] = data.exists (msg ["name"]);
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "get")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "get";
				response ["zyre.uuid"] = zyre_uuid (node.zyre ());
				response ["metacontent"] = data.exists (msg ["name"]);
				response ["content"] = data [msg ["name"]];
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "set")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "set";
				//response ["zyre.uuid"] = zyre_uuid (node.get_zyre ());
				response ["content"] = (data.set (msg ["name"], msg ["content"]) ? 1 : 0);
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "magnitude")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "magnitude";
				response ["content"] = data.size ();
				
			  std::cout << "noware::machine::storage::receive()::msg[subject]::respone[content]==[" << response ["content"] << ']' << std::endl;
				std::cout << "noware::machine::storage::receive()::msg[subject]::respone[content].get_value ().text()==[" << response ["content"].get_value ().text () << ']' << std::endl;
				std::cout << "noware::machine::storage::receive()::msg[subject]::respone[content].get_value ().type()==[" << response ["content"].get_value ().type () << ']' << std::endl;
				
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "remove")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "magnitude";
				response ["zyre.uuid"] = zyre_uuid (node.zyre ());
				response ["content"] = (data.unset (msg ["name"]) ? 1 : 0);
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "empty")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "empty";
				response ["content"] = (data.empty () ? 1 : 0);
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else if (msg ["subject"] == "clear")
			{
			  std::cout << "noware::machine::storage::receive()::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				//return data.exists (msg ["name"]);
				
				noware::tree <> response;
				
				// Formulate a reponse.
				response ["subject"] = "response";
				response ["type"] = "clear";
				response ["content"] = (data.clear () ? 1 : 0);
				
				// Send back the answer.
				result = node.unicast (response, zyre_event_peer_uuid (event));
			  std::cout << "noware::machine::storage::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else	// ...we are being answered => if (msg ["subject"] == "response")
			{
			  std::cout << "noware::machine::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::in scope" << std::endl;
				
				//std::cout << "noware::machine::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
				//zclock_sleep (1500);
				
				std::cout << "noware::machine::storage::receive()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
				std::cout << "noware::machine::storage::receive()::msg[content].get_value ().type ()==[" << msg ["content"].get_value ().type () << ']' << std::endl;
				
				// Redirect the message to the function which asked for it.
				//unicast_local (zmsg_popstr (zmq_msg));
				result = unicast_local (msg);
			  std::cout << "noware::machine::storage::receive()::unicast_local (msg)==" << (result ? "Success" : "Failure") << std::endl;
			}
		}
		else
		{
			std::cout << "noware::machine::storage::receive()::zmq_msg==nullptr" << std::endl;
		}
	}
}

const std::string noware::machine::storage::receive_local (const std::string & response_type, const std::string & filter) const
{
	std::cout << "noware::machine::storage::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::called" << std::endl;
	
	int bind_return_code;
	
	std::string conn;	// Connection string.
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cout << "noware::machine::storage::receive_local()::conn==[" << conn << ']' << std::endl;
	
	zmq::context_t context (1);
	//  Socket to talk to server
	//std::cout << "Collecting updates from weather server...\n" << std::endl;
	//zmq::socket_t receiver (context, ZMQ_SUB);
	//zmq::socket_t receiver (context, ZMQ_PAIR);
	zmq::socket_t receiver (context, ZMQ_REP);
	receiver.bind ("tcp://127.0.0.1:3210");
	//receiver.bind (conn.c_str ());
	//receiver.bind ("tcp://0.0.0.0:5555");
	
	//std::cout << "noware::machine::storage::receive_local()::receiver.bind()==[" << bind_return_code << ']' << std::endl;
	
	
	// Subscribe to the filter.
	//receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), sizeof (filter));
	
	
	// zlist_t * peers;
	
	//assert (zlist_size (peers) == 1);
	//zlist_destroy (&peers);
	
	noware::tree <> message_tree;
	noware::var result;
	//noware::number::natural n;
	zmq::message_t message_filter;
	zmq::message_t message_content;
	boost::function <const bool/* search* */ (const noware::tree <> &/* response_type*/, noware::var &/* filter*/)> search;
	
	result = "";
	// Decide which search function should be used.
	std::cout << "noware::machine::storage::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::pre-if" << std::endl;
	if (response_type == "exists")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_exists), this, _1, _2);
	}
	else if (response_type == "get")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_get), this, _1, _2);
		//search = &noware::machine::storage::search_get;
	}
	else if (response_type == "remove")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_remove), this, _1, _2);
		//search = &noware::machine::storage::search_remove;
	}
	else if (response_type == "set")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_set), this, _1, _2);
		//search = &noware::machine::storage::search_set;
	}
	else if (response_type == "empty")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_empty), this, _1, _2);
		//search = &noware::machine::storage::search_empty;
	}
	else if (response_type == "magnitude")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_magnitude), this, _1, _2);
		//search = &noware::machine::storage::search_magnitude;
	  std::cout << "noware::machine::storage::receive_local()::result=0::pre ==[" << result << ']' << std::endl;
		result = 0;
	  std::cout << "noware::machine::storage::receive_local()::result=0::post==[" << result << ']' << std::endl;
	}
	else if (response_type == "clear")
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::storage::search_clear), this, _1, _2);
		//search = &noware::machine::storage::search_clear;
	}
	else
	{
	  std::cout << "noware::machine::storage::receive_local()::response_type::if-else::in scope" << std::endl;
		return "";
	}
	
	std::cout << "noware::machine::storage::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::node.peers_count()==[" << node.peers_count () << ']' << std::endl;
	
	/*
	//zlist_t * peers;
	peers = zyre_peers (node.zyre ());
	if (peers == nullptr);
	{
		std::cout << "noware::machine::storage::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::peers==nullptr" << std::endl;
		
		return result;
	}
	*/
	// Ensure that all (relevant) peers respond.
	//n = 0;
	//result = "";
  std::cout << "noware::machine::storage::receive_local()::pre-loop" << std::endl;
	for (noware::number::natural n = 0; n < /*zlist_size (peers)*/ node.peers_count (); ++n)
	{
	  std::cout << "noware::machine::storage::receive_local()::while::n==[" << n << ']' << std::endl;
	  
		//zmq::message_t message_filter;
		//zmq::message_t message_content;
		
	  std::cout << "noware::machine::storage::receive_local()::loop::receiving::filter" << std::endl;
		receiver.recv (&message_filter);
	  std::cout << "noware::machine::storage::receive_local()::loop:: received::filter" << std::endl;
	  
	  std::cout << "noware::machine::storage::receive_local()::loop::receiving::message" << std::endl;
		receiver.recv (&message_content);
	  std::cout << "noware::machine::storage::receive_local()::loop:: received::message" << std::endl;
		
	  std::cout << "noware::machine::storage::receive_local()::message_tree.deserialize()::pre-call" << std::endl;
		
		std::cout << "noware::machine::storage::receive_local()::message_filter.data()==[" << static_cast <const char *> (message_filter.data ()) << ']' << std::endl;
		
		std::cout << "noware::machine::storage::receive_local()::message_content.data()==[" << static_cast <const char *> (message_content.data ()) << ']' << std::endl;
		
		if (!message_tree.deserialize (static_cast <const char *> (message_content.data ())))
		{
		  std::cout << "noware::machine::storage::receive_local()::message_tree.deserialize()==False" << std::endl;
			return result;
		}
		
		std::cout << "noware::machine::storage::receive_local()::message_tree.deserialize()==True" << std::endl;
		// Refresh the list of peers,
		// in case any of them departed the cluster since our previous iteration(s),
		// even if it is improbable.
		/*
		zlist_destroy (&peers);
		//zlist_t * peers;
		peers = zyre_peers (node.zyre ());
		
		if (peers == nullptr)
		{
		  std::cout << "noware::machine::storage::receive_local()::in-while::peers==nullptr" << std::endl;
			return "";
		}
		*/
		// React to/Parse the message.
		// search() returns bool if we have found the answer.
		// we could then short-circuit the loop (stop looping).
  	std::cout << "noware::machine::storage::receive_local()::if(search())::pre-call" << std::endl;
		if (search (message_tree, result))
		{
	  	std::cout << "noware::machine::storage::receive_local()::if(search())::break" << std::endl;
			break;
		}
		
		//++n;
	}
  std::cout << "noware::machine::storage::receive_local()::post-loop" << std::endl;
	
	//zlist_destroy (&peers);
	
  std::cout << "noware::machine::storage::receive_local()::return result==[" << result << ']' << std::endl;
	return result;
	
	//std::istringstream iss(static_cast<char*>(update.data()));
	//std::cout << "Message=" << '[' << static_cast <char *> (update.data ()) << ']' << std::endl;
}

const bool noware::machine::storage::unicast_local (const noware::tree <> & msg) const
{
	std::string filter;
	std::string msg_serial;
	std::string conn;	// Connection string.
	//noware::tree <> msg_tree;
	bool result;
	
	filter = "";
	//filter += (noware::var) '/' + "response";
	//msg_tree.deserialize (msg);
	
	//if (msg_tree.exists ("subject"))
		filter += (noware::var) '/' + msg ["subject"];
	
	filter += (noware::var) '/' + msg ["type"];
	
	//if (msg_tree.exists ("name"))
		filter += (noware::var) '/' + msg ["name"];
	
	//if (msg_tree.exists ("content"))
	//	filter += '/' + msg_tree ["content"];
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cout << "noware::machine::storage::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	std::cout << "noware::machine::storage::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	
	
	std::cout << "noware::machine::storage::unicast_local()::conn==[" << conn << ']' << std::endl;
	
	msg_serial = msg.serialize ();
	
	zmq::context_t context (1);
	//zmq::socket_t transmitter (context, ZMQ_PUB);
	//zmq::socket_t transmitter (context, ZMQ_PAIR);
	zmq::socket_t transmitter (context, ZMQ_REQ);
	transmitter.connect ("tcp://127.0.0.1:3210");
	//transmitter.connect (conn.c_str ());
	//transmitter.bind ("tcp://*:5555");
	
	
	//zmq::message_t filter_msg (sizeof (filter.c_str ()));
	zmq::message_t filter_msg (filter.length ());
	//zmq::message_t message (sizeof (msg_serial.c_str ()));
	zmq::message_t message (msg_serial.length ());

	//snprintf ((char *) message.data(), 20 ,
	//	"%05d %d %d", zipcode, temperature, relhumidity);
	//std::memcpy (filter_msg.data (), filter.c_str (), sizeof (filter.c_str ()));
	std::memcpy (filter_msg.data (), filter.c_str (), filter.length ());
	//std::memcpy (message.data (), msg_serial.c_str (), sizeof (msg_serial.c_str ()));
	std::memcpy (message.data (), msg_serial.c_str (), msg_serial.length ());
	
	std::cout << "message==" << '[' << static_cast <char *> (message.data ()) << ']' << std::endl;
	
	
  std::cout << "noware::machine::storage::unicast_local()::send()" << std::endl;
	//return
	result =
		transmitter.send (filter_msg, ZMQ_SNDMORE)
		&&
		transmitter.send (message)
	;
	
	//zclock_sleep (1500);
	
  std::cout << "noware::machine::storage::unicast_local()::send()==[" << (result ? "Success" : "Failure") << ']' << std::endl;
	
	//return true;
	return result;
}

const bool noware::machine::storage::search_exists (const noware::tree <> & message, noware::var & result)// const
{
	if (message ["content"].get_value ())
	{
		result = message ["content"];
		//result = true;
		
		return message ["content"].get_value ();
		//return true;
	}
	
	return false;
}

// Short-circuit (triggered by success).
const bool noware::machine::storage::search_get (const noware::tree <> & message, noware::var & result)// const
{
	if (message ["metacontent"].get_value ())
	{
		result = message ["content"];
		
		return true;
	}
	
	/*
		Do not worry about conflicts (yet).
		Just return the first peer who answered.
		
			We may always return that we found the value,
		because the peer who has the requested value
		should normally (when ignoring conflicts) be the only one who responded.
		
		? [TODO]	If there is no peer who has the requested value, the timeout in the parent
		should resolve this issue.
			No:
				Solution: all peers should answer if they have the value.
	*/
	return false;
}

// Short-circuit (triggered by failure).
const bool noware::machine::storage::search_set (const noware::tree <> & message, noware::var & result)// const
{
	// The peer which replied did Not have the value which we asked for.
	// We are not interested in these peers, for the "set" request.
	if (!(message ["metacontent"].get_value ()))
	{
		// We did not find an answer yet.
		// By default, it will be unsuccessful, established by our parent caller,
		// and further returned upward in the function calling hierarchy by it.
		return false;
	}
	
	//// Success or failure.
	// The peer which replied Did have the value which we asked for,
	// but was not successful in applying the new value.
	// By default, we then fail the entire "set" request.
	else if (!(message ["content"].get_value ()))
	{
		result = message ["content"];
		
		//return message ["content"];
		//// We found the result we were looking for, whether it is successful or unsuccessful.
		// We found the result we were looking for, it being unsuccessful, in this case.
		return true;
	}
	
	// We found the answer we were looking for, it being successful, ...
	result = message ["content"];
	
	//// The same comment, from search_get, about conflicts, applies to search_set.
	// ... but we did not find the entire result:
	// we must read the answers of all peers to conclude to a final result;
	// so, continue with the loop.
	return false;
}

// Short-circuit (triggered by failure).
const bool noware::machine::storage::search_remove (const noware::tree <> & message, noware::var & result)// const
{
	// The peer which replied did Not have the value which we asked for.
	// We are not interested in these peers, for the "set" request.
	if (!(message ["metacontent"].get_value ()))
	{
		// We did not find an answer yet.
		// By default, it will be unsuccessful, established by our parent caller,
		// and further returned upward in the function calling hierarchy by it.
		return false;
	}
	
	//// Success or failure.
	// The peer which replied Did have the value which we asked for,
	// but was not successful in applying the new value.
	// By default, we then fail the entire "set" request.
	else if (!(message ["content"].get_value ()))
	{
		result = message ["content"];
		
		//return message ["content"];
		//// We found the result we were looking for, whether it is successful or unsuccessful.
		// We found the result we were looking for, it being unsuccessful, in this case.
		return true;
	}
	
	// We found the answer we were looking for, it being successful, ...
	result = message ["content"];
	
	//// The same comment, from search_get, about conflicts, applies to search_set.
	// ... but we did not find the entire result:
	// we must read the answers of all peers to conclude to a final result;
	// so, continue with the loop.
	return false;
}

const bool noware::machine::storage::search_magnitude (const noware::tree <> & message, noware::var & result)// const
{
	std::cout << "noware::machine::storage::search_magnitude()::in scope" << std::endl;
	
	std::cout << "noware::machine::storage::search_magnitude()::result [pre]==[" << result << ']' << std::endl;
	
	std::cout << "noware::machine::storage::search_magnitude()::result==[" << result << ']' << std::endl;
	//std::cout << "noware::machine::storage::search_magnitude()::result.get_value ()==[" << result.get_value () << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::result.text ()==[" << result.text () << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::result.text ().c_str ()==[" << result.text ().c_str () << ']' << std::endl;
	
	std::cout << "noware::machine::storage::search_magnitude()::message[content]==[" << message ["content"] << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::message[content].get_value ()==[" << message ["content"].get_value () << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::message[content].get_value ().text ()==[" << message ["content"].get_value ().text () << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::message[content].get_value ().type ()==[" << message ["content"].get_value ().type () << ']' << std::endl;
	std::cout << "noware::machine::storage::search_magnitude()::message[content].get_value ().text ().c_str ()==[" << message ["content"].get_value ().text ().c_str () << ']' << std::endl;
	
  result += message ["content"];
	//result = ((noware::number::natural) (result.text ().c_str ())) + ((noware::number::natural) (message ["content"].get_value ().text ().c_str ()));
	//result = ((noware::number::natural) (result.text ().c_str ())) + ((noware::number::natural) (message ["content"].get_value ().text ().c_str ()));
	
  std::cout << "noware::machine::storage::search_magnitude()::result[post]==[" << result << ']' << std::endl;
  
	/*
		In the scope of this function, we do not know if the current call
		(the last peer who answered) is the last one,
		because we do not know how many iterations remain,
		in the caller's/parent's loop.
		
		Thus, always assume that this call is Not the last one,
		so that the parent loop does not end (at the first time)
		when this function is called.
	*/
	return false;
}

const bool noware::machine::storage::search_clear (const noware::tree <> & message, noware::var & result)// const
{
	return false;
}

const bool noware::machine::storage::search_empty (const noware::tree <> & message, noware::var & result)// const
{
	return false;
}
