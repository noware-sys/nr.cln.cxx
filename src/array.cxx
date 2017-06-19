#pragma once

#include "contnr/array.cxx"
#include <type_traits>
#include ".array/.cxx"

//#include "serial.cxx"
//#include "nr.cxx"
//#include "var.cxx"

// #include <typeinfo>
//#include <iostream>
// Array.CPP:
// Standard library:
//#include <utility>	// For "std::swap ()".

/*
// Static constants.
template <typename value_t, typename key_t>
value noware::array <value_t, key_t>::value;

template <typename value_t, typename key_t>
key noware::array <value_t, key_t>::key;
*/

//
// For array functionality
//
//const std::string noware::array::group_default = "array";

//template <typename value_t, typename key_t>
//const std::string noware::array <value_t, key_t>::srv_id = "srv";

template <typename value_t, typename key_t>
noware::array <value_t, key_t>::array (void)
{
	ctx = new zmq::context_t (1);
	
	//sock_rx = new zmq::socket_t (context, ZMQ_SUB);
	//sock_tx = new zmq::socket_t (context, ZMQ_PUB);
	
	sock_rx = new zmq::socket_t (*ctx, ZMQ_ROUTER);
	//sock_rx = new zmq::socket_t (*ctx, ZMQ_DEALER);
	sock_tx_all = new zmq::socket_t (*ctx, ZMQ_PUB);
	sock_tx_any = new zmq::socket_t (*ctx, ZMQ_DEALER);
	
	nodes_count = 0;
	
	sock_rx -> bind ("tcp://*:5500");
	sock_tx_all -> bind ("tcp://*:5550");
	sock_tx_any -> bind ("tcp://*:5551");
	/*
		// For SQLite
		_connected = false;
		connect (":memory:");
		
		// For ZeroMQ
		//node.initialize ();
		//node.start ();
		//node.reception_set (boost::bind (boost::mem_fn (&noware::array::receive), this, _1));
	*/
	
	_node = new node ();
	_node -> connect ("/root/Projects/NoWare/noware.cxx/src/.array/entity.db");
	
	//zclock_sleep (200);
	
	zmq_setsockopt (*sock_rx, ZMQ_IDENTITY, srv_id.c_str (), srv_id.size ());
	zmq_setsockopt (*sock_tx_any, ZMQ_IDENTITY, srv_id.c_str (), srv_id.size ());
	
	/*
	char * id;
	//size_t id_size = sizeof id;
	size_t id_size;
	std::cout << "noware::array::array()::id_size==[" << id_size << ']' << std::endl;
	zmq_getsockopt (*sock_tx_any, ZMQ_IDENTITY, id, &id_size);
	//id [3] = '\0';
	std::cout << "noware::array::array()::id_size==[" << id_size << ']' << std::endl;
	std::cout << "noware::array::array()::id==[" << id << ']' << std::endl;
	//std::cout << "noware::array::array()::id==[" << std::string (id, id_size) << ']' << std::endl;
	
	for (int i = 0; i < id_size; ++i)
	{
		std::cout << i << ". ";
		std::cout << id [i];
		std::cout << std::endl;
	}
	
	*/
	//node -> sock -> connect ("tcp://0.0.0.0:5550");
	//sock_rx -> connect ("tcp://0.0.0.0:5551");
	
	
	/*
	void * ptr;
	unsigned short int i = 123;
	ptr = static_cast <const void *> (&i);
	std::cout << "void * test: ";
	std::cout << *(static_cast <const unsigned short int *> (ptr)) << std::endl;
	*/
}

template <typename value_t, typename key_t>
noware::array <value_t, key_t>::~array (void)
{
	delete _node;
	
	delete sock_tx_all;
	delete sock_tx_any;
	delete sock_rx;
	delete ctx;
	
	// For SQLite
	//disconnect ();
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::set (const key_t & key, const value_t & value)
{
	/*
	bool is_ref;
	value_t * value_ptr;
	
	if (get_ptr (key, value_ptr))
	{
		*value_ptr = value;
		
		return true;
	}
	
	
	is_ref = noware::is_lvalue <value_t> (value);
	
	if (!s_sendmore (*sock_tx_any, "set"))
		return false;
	
	if (!s_sendmore (*sock_tx_any, std::string (key)))
		return false;
	
	if (is_ref)
	{
		value_t * value_ptr = &value;
	}
	else
	{
		value_t * value_ptr = new value_t (value);
	}
	
	if (!s_send (*sock_tx_any, noware::ptr::str (value_ptr)))
	{
		if (!is_ref)
			delete value_ptr;
		
		return false;
	}
	
	s_recv (*sock_rx);
	if (s_recv (*sock_rx) != "1")
	{
		if (!is_ref)
			delete value_ptr;
		
		return false;
	}
	
	return true;
	*/
	
	//return false;
	
	std::cout << "noware::array::set()::0" << std::endl;
	zmq::message_t msg_key (sizeof key), msg_value (sizeof value);
	/*
	std::cout << "noware::array::get()::1" << std::endl;
	if (!s_sendmore (*sock_tx_all, "all"))
	{
		std::cout << "noware::array::get()::1.0" << std::endl;
		return false;
		//std::cout << "noware::array::get()::1.1" << std::endl;
	}
	*/
	std::cout << "noware::array::set()::1" << std::endl;
	if (!s_sendmore (*sock_tx_any, "set"))
	{
		std::cout << "noware::array::set()::1.0" << std::endl;
		return false;
	}
	
	//if (!s_send (*sock_tx_all, std::string (key)))
	//	return false;
	std::cout << "noware::array::set()::2" << std::endl;
	memcpy (msg_key.data (), static_cast <const void *> (&key), sizeof key);
	std::cout << "noware::array::set()::3" << std::endl;
	memcpy (msg_value.data (), static_cast <const void *> (&value), sizeof value);
	
	std::cout << "noware::array::set()::3::  key==[" << *(static_cast <const key_t *> (msg_key.data ())) << ']' << std::endl;
	std::cout << "noware::array::set()::3::value==[" << *(static_cast <const value_t *> (msg_value.data ())) << ']' << std::endl;
	
	std::cout << "noware::array::set()::4" << std::endl;
	sock_tx_any -> send (msg_key, ZMQ_SNDMORE);
	std::cout << "noware::array::set()::5" << std::endl;
	sock_tx_any -> send (msg_value);
	
	std::cout << "noware::array::set()::6" << std::endl;
	s_recv (*sock_rx);
	std::cout << "noware::array::set()::7" << std::endl;
	if (s_recv (*sock_rx) != "1")
	{
		std::cout << "noware::array::set()::7.0" << std::endl;
		return false;
	}
	
	////sock_rx -> recv (&msg_value);
	
	////value = static_cast <const value_t *> (noware::ptr::val (s_recv (*sock_rx)));
	//value = *(static_cast <const value_t *> (msg_value.data ()));
	
	std::cout << "noware::array::set()::8" << std::endl;
	return true;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::get (const key_t & key, value_t & value) const
{
	std::cout << "noware::array::get()::0" << std::endl;
	zmq::message_t msg_key (sizeof key), msg_value (sizeof value);
	
	/*
	std::cout << "noware::array::get()::1" << std::endl;
	if (!s_sendmore (*sock_rx, "client"))
	{
		std::cout << "noware::array::get()::1.0" << std::endl;
		//return false;
		//std::cout << "noware::array::get()::1.1" << std::endl;
	}
	
	std::cout << "noware::array::get()::1" << std::endl;
	if (!s_send (*sock_rx, "test"))
	{
		std::cout << "noware::array::get()::1.0" << std::endl;
		//return false;
		//std::cout << "noware::array::get()::1.1" << std::endl;
	}
	*/
	
	/*
	std::cout << "noware::array::get()::1:1" << std::endl;
	s_send (*sock_tx_any, "test");
	std::cout << "noware::array::get()::1:2" << std::endl;
	return false;
	*/
	
	/*
	std::cout << "noware::array::get()::1" << std::endl;
	if (!s_sendmore (*sock_tx_all, "all"))
	{
		std::cout << "noware::array::get()::1.0" << std::endl;
		return false;
		//std::cout << "noware::array::get()::1.1" << std::endl;
	}
	*/
	
	std::cout << "noware::array::get()::2" << std::endl;
	if (!s_sendmore (*sock_tx_any, "get"))
	{
		std::cout << "noware::array::get()::2.0" << std::endl;
		return false;
		//std::cout << "noware::array::get()::2.1" << std::endl;
	}
	
	//if (!s_send (*sock_tx_all, std::string (key)))
	//	return false;
	std::cout << "noware::array::get()::2" << std::endl;
		std::cout << "noware::array::get()::2::key==[" << key << ']' << std::endl;
	memcpy (msg_key.data (), static_cast <const void *> (&key), sizeof key);
	
	std::cout << "noware::array::get()::3" << std::endl;
	sock_tx_any -> send (msg_key);
	
	std::cout << "noware::array::get()::4" << std::endl;
	/*client_id = */s_recv (*sock_rx);
	std::cout << "noware::array::get()::5" << std::endl;
	if (s_recv (*sock_rx) != "1")
	{
		std::cout << "noware::array::get()::5.0" << std::endl;
		return false;
		//std::cout << "noware::array::get()::5.1" << std::endl;
	}
	
	std::cout << "noware::array::get()::6" << std::endl;
	sock_rx -> recv (&msg_value);
	
	std::cout << "noware::array::get()::7" << std::endl;
	//value = static_cast <const value_t *> (noware::ptr::val (s_recv (*sock_rx)));
	value = *(static_cast <const value_t *> (msg_value.data ()));
	
	std::cout << "noware::array::get()::8" << std::endl;
	return true;
}

/*
template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::get (const key_t & key, value_t & value) const
{
	value_t * value_ptr;
	
	if (get_ptr (key, value_ptr))
	{
		value = *value_ptr;
		
		return true;
	}
	
	return false;
}
*/

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::clear (void)
{
	if (!s_send (*sock_tx_all, "clear"))
		return false;
	
	s_recv (*sock_rx);
	return s_recv (*sock_rx) == "1";
}

template <typename value_t, typename key_t>
const noware::nr noware::array <value_t, key_t>::size (void) const
{
	if (!s_send (*sock_tx_any, "size"))
		return 0;
	
	s_recv (*sock_rx);
	return s_recv (*sock_rx);
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::remove (const key_t & k)
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::rename (const key_t & old_k, const key_t & new_k)
{
	return false;
}

/*
template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::is_full (void) const
{
	//return size () <= 0;
	return false;
}
*/
