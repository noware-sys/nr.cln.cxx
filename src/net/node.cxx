#pragma once

#include "node.hxx"
//#include <boost/function_equal.hpp>
#include <boost/bind.hpp>
//#include "../tree.cxx"
//#include "../var.cxx"
#include <zmq/msg.cxx>

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
	fin ();
	//zclock_sleep (300);
}

const bool noware::net::node::init (void)
{
	if (!inited ())
	{
		_node = zyre_new (nullptr);
		reception = new boost::thread (boost::bind (boost::mem_fn (&noware::net::node::receive), this));
	}
	
	return inited ();
}

const bool noware::net::node::inited (void) const
{
	//std::cout << std::endl << "_node==[" << _node << ']' << std::endl;
	//return _node != nullptr;
	return _node != nullptr && reception != nullptr;
}

const bool noware::net::node::fin (void)
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
	if (!inited ())
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
	if (!inited ())
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
	if (!inited () || !status ())
		return false;
	
	zyre_leave (_node, group.c_str ());
	
	return true;
}

const bool noware::net::node::join (const std::string & group)
{
	if (!inited () || !status ())
		return false;
	
	zyre_join (_node, group.c_str ());
	
	return true;
}

const bool noware::net::node::unicast (const zmq::msg & msg, const std::string & peer/* peer id*/) const
{
	if (!inited () || !status ())
		return false;
	
	//zmsg_t * msg = zmsg_new ();
	//zmsg_addstr (msg, message.c_str ());
	
	//  0 == success
	// -1 == failure
	zmsg_t * zmsg;
	
	zmsg = &((zmsg_t) msg);
	
	return zyre_whisper (_node, peer.c_str (), &zmsg) == 0;
	
	//return true;
}

const bool noware::net::node::multicast (const zmq::msg & msg, const std::string & group) const
{
	std::cout << "noware::net::node::multicast()::called" << std::endl;
	
	if (!inited () || !status ())
		return false;
	
//	zmsg_t * msg = zmsg_new ();
	//std::cout << "noware::net::node::multicast()::2" << std::endl;
//	zmsg_addstr (msg, message.c_str ());
	//zmsg_addstr (msg, "Hello, World.");
	
//	signed short int result;
	//std::cout << "noware::net::node::multicast()::3" << std::endl;
//	std::cout << "noware::net::node::multicast::zyre_shout()==" << '[' << (result = zyre_shout (_node, group.c_str (), &msg)) << ']' << std::endl;
	//zyre_shout (_node, "storage", &msg);
	//zclock_sleep (250);
	
	//std::cout << "noware::net::node::multicast()::4(last)" << std::endl;
	/*
	zmsg_t * zmsg;
	
	zmsg = &((zmsg_t) msg);
	
	//assert (zframe_is (zmsg_first (zmsg)));
	zframe_t * frm;
	//char * cstr;
	
	frm = zmsg_first (zmsg);
	//str = zframe_strdup (frm);
	//std::string str ((char *) zframe_data (frm), zframe_size (frm));
	zframe_data (frm);
	zframe_size (frm);
	//std::cout << "noware::net::node::multicast::str==[" << str << ']' << std::endl;
	assert (zframe_is (frm));
	//assert (frm -> tag == ZFRAME_TAG);
	*/
	zmsg_t * zmsg;
	zframe_t * frame_p;
	zframe_t ** frame_pp;
	
	zmsg = zmsg_new ();
	//frame = zframe_new_empty ();
	
	for (const std::pair <const noware::nr, zmq::msg::frame> & _frame : msg.data)
	{
		//zframe_reset (_frame, );
		//frame_p = &((zframe_t) _frame.second);
		frame_p = zframe_new (_frame.second.data.data (), _frame.second.data.size ());
		frame_pp = &frame_p;
		
		assert (zframe_is (*frame_pp));
		//assert ((*frame_pp) -> tag == ZFRAME_TAG);
		
		zmsg_append (zmsg, frame_pp);
	}
	
	//return *zmsg;
	//printf ("noware::net::node::multicast::str==[%s]\n", cstr);
	//free (cstr);
	std::cout << "noware::net::node::multicast::zyre_shout()..." << std::endl;
	//  0 == success
	// -1 == failure
	//return true;
	//return zyre_shout (_node, group.c_str (), &(msg.operator const zmsg_t ())) == 0;
	return zyre_shout (_node, group.c_str (), &zmsg) == 0;
//	return result == 0;
}

const zyre_t * noware::net::node::operator * (void) const
{
	return _node;
}

const unsigned int noware::net::node::size (void) const
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

const unsigned int noware::net::node::size (const std::string & group) const
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
	while (inited ());
}
