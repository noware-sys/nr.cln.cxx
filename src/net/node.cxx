#include "node.hdr.cxx"
//#include <boost/function_equal.hpp>
#include <boost/bind.hpp>
#include "../tree.cxx"
#include "../var.cxx"

noware::net::node::node (void)
{
	running = false;
	_node = nullptr;
	reception = nullptr;
	//exoreception = nullptr;
}

noware::net::node::~node (void)
{
	//stop ();
	finalize ();
	//zclock_sleep (300);
}

const bool noware::net::node::initialize (void)
{
	if (!initialized ())
	{
		_node = zyre_new (nullptr);
		reception = new boost::thread (boost::bind (boost::mem_fn (&noware::net::node::receive), this));
	}
	
	return initialized ();
}

const bool noware::net::node::initialized (void) const
{
	//std::cout << std::endl << "_node==[" << _node << ']' << std::endl;
	//return _node != nullptr;
	return _node != nullptr && reception != nullptr;
}

const bool noware::net::node::finalize (void)
{
	stop ();
	
	//if (reception_is_set ())
		reception_unset ();
	
	std::cout << "noware::net::node::finalize()::reception::deletion" << std::endl;
	if (reception != nullptr)
	{
		std::cout << "noware::net::node::finalize()::reception::deleting" << std::endl;
		//reception -> join ();
		delete reception;
		std::cout << "noware::net::node::finalize()::reception::deleted" << std::endl;
		reception = nullptr;
	}
	
	//stop ();
	
	std::cout << "noware::net::node::finalize()::zyre_destroy()::pre" << std::endl;
	if (_node != nullptr)
	{
		std::cout << "noware::net::node::finalize()::zyre_destroy()::destroying" << std::endl;
		//zyre_stop (_node);
		zyre_destroy (&_node);
		std::cout << "noware::net::node::finalize()::zyre_destroy()::destroyed" << std::endl;
		_node = nullptr;
	}
	
	return _node == nullptr && reception == nullptr;
}

const bool noware::net::node::status (void) const
{
	return running;
}

const bool noware::net::node::stop (void)
{
	if (!initialized ())
		return true;
	
	std::cout << "noware::net::node::stop()::called" << std::endl;
	if (running)
	{
		std::cout << "noware::net::node::stop()::stopping zyre node" << std::endl;
		zyre_stop (_node);
		std::cout << "noware::net::node::stop()::stopped zyre node" << std::endl;
		
		running = false;
	}
	
	return !running;
}

const bool noware::net::node::start (void)
{
	if (!initialized ())
		return false;
	
	if (!running)
	{
		zyre_start (_node);
		
		//std::cout << "Started Zyre Node" << std::endl;
		running = true;
	}
	
	return running;
}

const bool noware::net::node::leave (const std::string & group)
{
	if (!initialized () || !status ())
		return false;
	
	zyre_leave (_node, group.c_str ());
	
	return true;
}

const bool noware::net::node::join (const std::string & group)
{
	if (!initialized () || !status ())
		return false;
	
	zyre_join (_node, group.c_str ());
	
	return true;
}

const bool noware::net::node::unicast (const noware::tree <> & message, const std::string & peer/* peer id*/) const
{
	if (!initialized () || !status ())
		return false;
	
	zmsg_t * msg = zmsg_new ();
	zmsg_addstr (msg, message.serialize ().c_str ());
	
	//  0 == success
	// -1 == failure
	return zyre_whisper (_node, peer.c_str (), &msg) == 0;
	
	//return true;
}

const bool noware::net::node::multicast (const noware::tree <> & message, const std::string & group) const
{
	//std::cout << "noware::net::node::multicast()::called" << std::endl;
	
	if (!initialized () || !status ())
		return false;
	
	zmsg_t * msg = zmsg_new ();
	//std::cout << "noware::net::node::multicast()::2" << std::endl;
	zmsg_addstr (msg, message.serialize ().c_str ());
	//zmsg_addstr (msg, "Hello, World.");
	
	signed short int result;
	//std::cout << "noware::net::node::multicast()::3" << std::endl;
	std::cout << "noware::net::node::multicast::zyre_shout()==" << '[' << (result = zyre_shout (_node, group.c_str (), &msg)) << ']' << std::endl;
	//zyre_shout (_node, "storage", &msg);
	//zclock_sleep (250);
	
	//std::cout << "noware::net::node::multicast()::4(last)" << std::endl;
	
	//  0 == success
	// -1 == failure
	//return true;
	return result == 0;
}

const zyre_t * noware::net::node::zyre (void) const
{
	return _node;
}

const unsigned int noware::net::node::peers_count (void) const
{
	unsigned int result;
	zlist_t * peers;
	
	result = 0;
	peers = zyre_peers (_node);
	
	if (peers == nullptr)
	{
		std::cout << "noware::net::node::peers_count::peers==nullptr" << std::endl;
		
		return result;
	}
	
	result = zlist_size (peers);
	std::cout << "noware::net::node::peers_count::result=zlist_size(peers)==[" << result << ']' << std::endl;
	zlist_destroy (&peers);
	
	return result;
}

const unsigned int noware::net::node::peers_count (const std::string & group) const
{
	unsigned int result;
	zlist_t * peers;
	
	result = 0;
	peers = zyre_peers_by_group (_node, group.c_str ());
	
	if (peers == nullptr)
	{
		std::cout << "noware::net::node::peers_count::peers==nullptr" << std::endl;
		
		return result;
	}
	
	result = zlist_size (peers);
	std::cout << "noware::net::node::peers_count::result=zlist_size(peers)==[" << result << ']' << std::endl;
	zlist_destroy (&peers);
	
	return result;
}

const bool noware::net::node::reception_is_set (void) const
{
	//return exoreception != nullptr;
	return !exoreception.empty ();
	//return !exoreception.empty () && reception != nullptr;
}

const bool noware::net::node::reception_unset (void)
{
	std::cout << "noware::net::node::reception_unset()::called" << std::endl;
	if (reception_is_set ())
	{
		//std::cout << "noware::net::node::reception_unset()::reception::deleting" << std::endl;
		//delete reception;
		//std::cout << "noware::net::node::reception_unset()::reception::deleted" << std::endl;
		//reception = nullptr;
		
		//delete exoreception;
		std::cout << "noware::net::node::reception_unset()::exoreception.clear()" << std::endl;
		exoreception.clear ();
	}
	
	return !reception_is_set ();
}

const bool noware::net::node::reception_set (const boost::function <void (const zyre_event_t */* zyre_event*/)>	& exomanager)
{
	if (reception_is_set ())
		return false;
	
	// http://www.boost.org/doc/libs/1_63_0/doc/html/function/tutorial.html :
	// "Note that the & isn't really necessary unless you happen to be using Microsoft Visual C++ version 6."
	//exoreception = &exomanager;
	exoreception = exomanager;
	
	//reception = new boost::thread (boost::bind (boost::mem_fn (&noware::net::node::receive), this));
	
	//return exoreception == &exomanager;
	return reception_is_set ();
}

void noware::net::node::receive (void)
{
	zyre_event_t * event;
	
	do
	{
		std::cout << "noware::net::node::receive()::waiting for an event" << std::endl;
		event = zyre_event_new (_node);
		std::cout << "noware::net::node::receive()::received an event" << std::endl;
		
		 // Interrupted.
		//if (event == nullptr)
		//	break;
		
		if (!exoreception.empty () && event != nullptr)
		{
			std::cout << "noware::net::node::receive()::delegating the event to the external handler" << std::endl;
			
			// Delegate to the external handler.
			exoreception (event);
		}
		else
		{
			std::cout << "noware::net::node::receive()::not delegating the event to the external handler::" << std::endl;
			
			std::cout << "noware::net::node::receive()::not delegating the event to the external handler::(exoreception.empty())==" << (exoreception.empty () ? "True" : "False") << std::endl;
			std::cout << "noware::net::node::receive()::not delegating the event to the external handler::(event==nullptr)==" << (event == nullptr ? "True" : "False") << std::endl;
		}
		
		//if (verbose)
		//		zyre_event_print (event);
		
		/*
		if (streq (zyre_event_type (event), "ENTER")) {
				//  If new peer, say hello to it and wait for it to answer us
				zsys_info ("[%s] peer entered", zyre_event_peer_name (event));
				zyre_whispers (zyre, zyre_event_peer_uuid (event), "Hello");
		}
		else
		if (streq (zyre_event_type (event), "EXIT")) {
				zsys_info ("[%s] peer exited", zyre_event_peer_name (event));
		}
		else
		if (streq (zyre_event_type (event), "WHISPER")) {
				zsys_info ("[%s] received ping (WHISPER)", zyre_event_peer_name (event));
				zyre_shouts (zyre, "GLOBAL", "Hello");
		}
		else
		if (streq (zyre_event_type (event), "SHOUT")) {
				zsys_info ("[%s](%s) received ping (SHOUT)",
				           zyre_event_peer_name (event), zyre_event_group (event));
		}
		*/
		
		zyre_event_destroy (&event);
	}
	//while (true);
	//while (event != nullptr);
	while (initialized ());
}

