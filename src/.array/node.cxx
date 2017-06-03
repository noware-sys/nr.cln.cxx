//#include "../net/node.cxx"

//#include <boost/bind.hpp>

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>
//#include <boost/thread/mutex.hpp>
//#include "../tool/ptr.cxx"

//const noware::nr noware::array::node::tries_dft = 1;
//template <typename value_t, typename key_t>
//const std::string noware::array <value_t, key_t>::node::srv_id = "srv";

template <typename value_t, typename key_t>
noware::array <value_t, key_t>::node::node (void)
{
	std::cout << "noware::array::node::node()::0" << std::endl;
	reception = new boost::thread (boost::bind (boost::mem_fn (&noware::array <value_t, key_t>::node::receive), this));
	
	std::cout << "noware::array::node::node()::1" << std::endl;
	ctx = new zmq::context_t (1);
	
	std::cout << "noware::array::node::node()::2" << std::endl;
	sock_tx = new zmq::socket_t (*ctx, ZMQ_ROUTER);
	std::cout << "noware::array::node::node()::3" << std::endl;
	sock_rx_any = new zmq::socket_t (*ctx, ZMQ_ROUTER);
	std::cout << "noware::array::node::node()::4" << std::endl;
	sock_rx_all = new zmq::socket_t (*ctx, ZMQ_SUB);
	
	sock_rx_any -> setsockopt (ZMQ_CONNECT_RID, srv_id.c_str (), srv_id.size ());
	sock_tx -> setsockopt (ZMQ_CONNECT_RID, srv_id.c_str (), srv_id.size ());
	
	std::cout << "noware::array::node::node()::5" << std::endl;
	sock_tx -> connect ("tcp://0.0.0.0:5500");
	std::cout << "noware::array::node::node()::6" << std::endl;
	sock_rx_all -> connect ("tcp://0.0.0.0:5550");
	std::cout << "noware::array::node::node()::7" << std::endl;
	sock_rx_any -> connect ("tcp://0.0.0.0:5551");
	
	//sock_rx_all -> setsockopt (ZMQ_SUBSCRIBE, "all", strlen ("all"));
	sock_rx_all -> setsockopt (ZMQ_SUBSCRIBE, "all", 3);
	//std::cout << "noware::array::node::node()::strlen(\"all\")==[" << strlen ("all") << ']' << std::endl;
	
	//zmq_setsockopt (*sock_tx, ZMQ_IDENTITY, "client", 6);
	
	std::cout << "noware::array::node::node()::8" << std::endl;
	_connected = false;
	
	std::cout << "noware::array::node::node()::9" << std::endl;
}

template <typename value_t, typename key_t>
noware::array <value_t, key_t>::node::~node (void)
{
	delete reception;
	
	delete sock_tx;
	delete sock_rx_all;
	delete sock_rx_any;
	delete ctx;
	
	disconnect ();
}

template <typename value_t, typename key_t>
void noware::array <value_t, key_t>::node::receive (void)
{
	std::cout << "noware::array::node::receive()::0" << std::endl;
	//std::string msg;
	//std::string node_id;
	zmq::message_t node_id;
	zmq::message_t filter;
	std::cout << "noware::array::node::receive()::1" << std::endl;
	zmq::pollitem_t socket [2];
	//zmq::pollitem_t socket [3];
	
	std::cout << "noware::array::node::receive()::2" << std::endl;
	socket [0].socket = *sock_rx_all;
	std::cout << "noware::array::node::receive()::3" << std::endl;
	socket [0].events = ZMQ_POLLIN;
	
	std::cout << "noware::array::node::receive()::4" << std::endl;
	socket [1].socket = *sock_rx_any;
	std::cout << "noware::array::node::receive()::5" << std::endl;
	socket [1].events = ZMQ_POLLIN;
	
	/*
	std::cout << "noware::array::node::receive()::4" << std::endl;
	socket [2].socket = *sock_tx;
	std::cout << "noware::array::node::receive()::5" << std::endl;
	socket [2].events = ZMQ_POLLIN;
	*/
	
	std::cout << "noware::array::node::receive()::6" << std::endl;
	//zclock_sleep (500);
	while (true)
	{
		std::cout << "noware::array::node::receive()::6.0" << std::endl;
		zmq::poll (socket, 2, -1);
		//zmq::poll (socket, 3, -1);
		
		/*
		std::cout << "noware::array::node::receive()::6.3" << std::endl;
		if (socket [2].revents & ZMQ_POLLIN)
		{
			std::cout << "noware::array::node::receive()::6.3.0" << std::endl;
			//sock_tx -> recv (&node_id);
			//msg = s_recv (*sock_rx_any);
			//manage (*sock_rx_any, node_id);
			
			std::cout << "noware::array::node::receive()::node_id==[" << s_recv (*sock_tx) << ']' << std::endl;
			std::cout << "noware::array::node::receive()::node_id==[" << s_recv (*sock_tx) << ']' << std::endl;
			//manage (*sock_rx_any);
			//manage (*(socket [1].socket));
			
			std::cout << "noware::array::node::receive()::6.3.2" << std::endl;
		}
		*/
		///*
		std::cout << "noware::array::node::receive()::6.1" << std::endl;
		if (socket [0].revents & ZMQ_POLLIN)
		{
			std::cout << "noware::array::node::receive()::6.1.0" << std::endl;
			//msg = s_recv (*sock_rx_all);
			sock_rx_all -> recv (&filter);
			
			std::cout << "noware::array::node::receive()::6.1.1" << std::endl;
			manage (*sock_rx_all);
			//manage (*(socket [0].socket));
			std::cout << "noware::array::node::receive()::6.1.2" << std::endl;
		}
		//*/
		std::cout << "noware::array::node::receive()::6.2" << std::endl;
		if (socket [1].revents & ZMQ_POLLIN)
		{
			std::cout << "noware::array::node::receive()::6.2.0" << std::endl;
			//sock_rx_any -> recv (&node_id);
			std::cout << "noware::array::node::receive()::srv_id==[" << s_recv (*sock_rx_any) << ']' << std::endl;
			/*
			char * id;
			int node_id_size;
			
			sock_rx_any -> recv (&node_id);
			node_id_size = node_id.size ();
			id = static_cast <char *> (node_id.data ());
			
			//std::cout << "noware::array::node::receive()::srv_id==[" << s_recv (*sock_rx_any) << ']' << std::endl;
			std::cout << "noware::array::node::receive()::srv_id==[" << node_id.data () << ']' << std::endl;
			//std::cout << "noware::array::node::receive()::srv_id==[" << id << ']' << std::endl;
			std::cout << "noware::array::node::receive()::srv_id==[" << std::string (static_cast <char *> (node_id.data ()), node_id.size ()) << ']' << std::endl;
			//msg = s_recv (*sock_rx_any);
			//manage (*sock_rx_any, node_id);
			
			std::cout << "noware::array::node::receive()::node_id_size==[" << node_id_size << ']' << std::endl;
			//c_str [3] = '\0';
			for (int i = 0; i < node_id_size; ++i)
			{
				std::cout << id [i];
			}
			std::cout << std::endl;
			*/
			std::cout << "noware::array::node::receive()::6.2.1" << std::endl;
			manage (*sock_rx_any);
			//manage (*(socket [1].socket));
			
			std::cout << "noware::array::node::receive()::6.2.2" << std::endl;
		}
		
		std::cout << "noware::array::node::receive()::6.3" << std::endl;
	}
	
	std::cout << "noware::array::node::receive()::7" << std::endl;
}
/*
template <typename value_t, typename key_t>
//void noware::array <value_t, key_t>::node::manage (const zmq::socket_t & sock, const std::string & msg, const std::string & node_id)
void noware::array <value_t, key_t>::node::manage (const zmq::socket_t & sock)
{
	const zmq::message_t node_id;
	
	return manage (sock, node_id);
}
*/
template <typename value_t, typename key_t>
//void noware::array <value_t, key_t>::node::manage (const zmq::socket_t & sock, const std::string & msg, const std::string & node_id)
//void noware::array <value_t, key_t>::node::manage (const zmq::socket_t & sock, const zmq::message_t & node_id)
void noware::array <value_t, key_t>::node::manage (zmq::socket_t & socket)
{
	std::cout << "noware::array::node::manage()::0" << std::endl;
	std::string msg_req_str;
	/*
	zmq::message_t msg_req;
	std::string msg_req_str;
	
	sock.recv (&msg_req);
	
	msg_req_str = static_cast <const char *> (msg_req.data ());
	*/
	
	std::cout << "noware::array::node::manage()::1" << std::endl;
	msg_req_str = s_recv (socket);
	//zmq::message_t message;
	//std::cout << "noware::array::node::manage()::1:2" << std::endl;
	//socket.recv (&message);
	//
	//std::cout << "noware::array::node::manage()::1:3" << std::endl;
	//msg_req_str = std::string (static_cast <char *> (message.data ()), message.size ());
	std::cout << "noware::array::node::manage()::msg_req_str==[" << msg_req_str << ']' << std::endl;
	
	std::cout << "noware::array::node::manage()::2" << std::endl;
	if (msg_req_str == "get")
	{
		std::cout << "noware::array::node::manage()::2.0" << std::endl;
		key_t * key;
		std::cout << "noware::array::node::manage()::2.1" << std::endl;
		value_t value;
		std::cout << "noware::array::node::manage()::2.2" << std::endl;
		zmq::message_t msg_key (sizeof key), msg_value (sizeof value);
		
		
		std::cout << "noware::array::node::manage()::2.3" << std::endl;
		socket.recv (&msg_key);
		
		std::cout << "noware::array::node::manage()::2.4" << std::endl;
		key = static_cast <const key_t *> (msg_key.data ());
		//key = s_recv (*sock);
		
		std::cout << "noware::array::node::manage()::2.5" << std::endl;
		std::cout << "noware::array::node::manage()::2.5::&key==[" << key << ']' << std::endl;
		std::cout << "noware::array::node::manage()::2.5::key==[" << *key << ']' << std::endl;
		s_sendmore (*sock_tx, srv_id);
		
		std::cout << "noware::array::node::manage()::2.6" << std::endl;
		if (!get (*key, value))
		{
			std::cout << "noware::array::node::manage()::2.6.0" << std::endl;
			s_send (*sock_tx, "0");
			std::cout << "noware::array::node::manage()::2.6.1" << std::endl;
			return;
		}
		
		std::cout << "noware::array::node::manage()::2.7" << std::endl;
		s_sendmore (*sock_tx, "1");
		
		std::cout << "noware::array::node::manage()::2.8" << std::endl;
		memcpy (msg_value.data (), static_cast <const void *> (&value), sizeof value);
		
		std::cout << "noware::array::node::manage()::2.9" << std::endl;
		//s_sendmore (*sock_tx, srv_id);
		sock_tx -> send (msg_value);
		
		std::cout << "noware::array::node::manage()::2.10" << std::endl;
	}
	/*
	else if (msg_req_str == "exist")
	{
		key_t key;
		zmq::message_t msg_key;
		
		
		socket.recv (&msg_key);
		
		key = *(static_cast <const key_t *> (msg_key.data ()));
		//key = s_recv (*sock);
		
		s_sendmore (*sock_tx, srv_id);
		
		if (!get (key, value))
			s_send (*sock_tx, "0");
		
		s_sendmore (*sock_tx, "1");
		
		memcpy (msg_value.data (), static_cast <const void *> (&value), sizeof value);
		
		//s_sendmore (*sock_tx, srv_id);
		sock_tx -> send (msg_value);
	}
	*/
	else if (msg_req_str == "set")
	{
		std::cout << "noware::array::node::manage()::3.0" << std::endl;
		key_t key;
		value_t value;
		zmq::message_t msg_key (sizeof key), msg_value (sizeof value);
		
		std::cout << "noware::array::node::manage()::3.2" << std::endl;
		socket.recv (&msg_key);
		std::cout << "noware::array::node::manage()::3.3" << std::endl;
		socket.recv (&msg_value);
		//key = s_recv (*sock);
		//value = noware::ptr::val (s_recv (*sock_rx_any));
		
		std::cout << "noware::array::node::manage()::3.4::  &key==[" << msg_key.data () << ']' << std::endl;
		std::cout << "noware::array::node::manage()::3.4::&value==[" << msg_value.data () << ']' << std::endl;
		
		std::cout << "noware::array::node::manage()::3.4" << std::endl;
		key = *(static_cast <const key_t *> (msg_key.data ()));
		std::cout << "noware::array::node::manage()::3.5" << std::endl;
		value = *(static_cast <const value_t *> (msg_value.data ()));
		
		std::cout << "noware::array::node::manage()::3.8::  key==[" << key << ']' << std::endl;
		std::cout << "noware::array::node::manage()::3.9::value==[" << value << ']' << std::endl;
		
		std::cout << "noware::array::node::manage()::3.10" << std::endl;
		s_sendmore (*sock_tx, srv_id);
		
		std::cout << "noware::array::node::manage()::3.11" << std::endl;
		if (!set (key, value))
		{
			std::cout << "noware::array::node::manage()::3.11.1" << std::endl;
			s_send (*sock_tx, "0");
		}
		
		std::cout << "noware::array::node::manage()::3.12" << std::endl;
		s_send (*sock_tx, "1");
		
		std::cout << "noware::array::node::manage()::3.13" << std::endl;
	}
	else if (msg_req_str == "size")
	{
		std::cout << "noware::array::node::manage()::4.0" << std::endl;
		s_sendmore (*sock_tx, srv_id);
		std::cout << "noware::array::node::manage()::4.1" << std::endl;
		s_send (*sock_tx, size ());
		std::cout << "noware::array::node::manage()::4.2" << std::endl;
	}
	/*
	else if (msg_req_str == "srv_id")
	{
		//s_send (*sock_tx, size ());
		srv_id = s_recv (*sock);
	}
	*/
	
	/*
	if (msg == "")
	{
	}
	*/
	
	std::cout << "noware::array::node::manage()::5" << std::endl;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::connected (void) const
{
	return _connected;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::disconnect (void)
{
	if (!connected ())
		return true;
	else if (sqlite3_close (db) == SQLITE_OK)
	{
		_connected = false;
		
		return true;
	}
	else
		return false;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::connect (const std::string & database_name)
{
	if (connected () && !disconnect ())
		return false;
	else if (sqlite3_open (database_name.c_str (), &db) == SQLITE_OK)
	{
		_connected = true;
		
		return true;
	}
	else
		return false;
}

template <typename value_t, typename key_t>
const noware::nr noware::array <value_t, key_t>::node::effect (void) const
{
	return sqlite3_changes (db);
}

template <typename value_t, typename key_t>
const noware::nr noware::array <value_t, key_t>::node::size (void) const
{
	if (!connected ())
		return 0;
	
	std::string query;
	noware::nr value;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	
	query = "select count(*) from entity";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.size (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return 0;
	}
	
	//column_count = sqlite3_column_count (statement);
	
	//row = 1;
	//tries = 1;
	// The next line is the fist try to evaluate the expression:
	result_code = sqlite3_step (statement);
	
	std::cout << "noware::array::node::size()::0" << std::endl;
	if (result_code != SQLITE_ROW/* && result_code != SQLITE_OK && result_code != SQLITE_DONE*/)
	{
		std::cout << "noware::array::node::size()::0.1" << std::endl;
		sqlite3_finalize (statement);
		
		std::cout << "noware::array::node::size()::0.2" << std::endl;
		return 0;
	}
	
	std::cout << "noware::array::node::size()::1" << std::endl;
	value = sqlite3_column_int (statement, 0);
	
	std::cout << "noware::array::node::size()::2" << std::endl;
	sqlite3_finalize (statement);
	//std::cout << "effect (after 'finalize ()') == [" << effect () << ']' << std::endl;
	
	std::cout << "noware::array::node::size()::3" << std::endl;
	return value;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::exist (const key_t & key) const
{
	value_t value;
	
	return get (key, value);
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::is_full (void) const
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::is_empty (void) const
{
	return size () <= 0;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::set (const key_t & key, const value_t & value)
{
	if (!connected ())
		return false;
	
	std::string query;
	//noware::nr value;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	//value_t * value_ptr;
	//std::string value_ptr_str;
	
	//query = "update entity set value = ?1 where id = ?2 and \"key.type\" = ?3 and key = ?4 and \"value.type\" = ?5";
	query = "insert or replace into entity (id, \"key.type\", key, \"value.type\", value) values (?1, ?2, ?3, ?4, ?5)";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.size (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//value_ptr_str = noware::ptr::str (value);
	//value_ptr = new value_t (*value);
	
	/*
	//sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
	sqlite3_bind_blob (statement, 1, static_cast <const void *> (&value), sizeof value, nullptr);
	//sqlite3_bind_text (statement, 1, value_ptr_str.c_str (), value_ptr_str.length (), SQLITE_TRANSIENT);
	sqlite3_bind_text (statement, 2, "", 0, SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 3, 0);
	sqlite3_bind_blob (statement, 4, static_cast <const void *> (&key), sizeof key, nullptr);
	//sqlite3_bind_text (statement, 4, key, key.length (), SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 5, 0);
	//column_count = sqlite3_column_count (statement);
	*/
	
	//sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
	// id
	sqlite3_bind_text (statement, 1, "", 0, SQLITE_TRANSIENT);
	// key.type
	sqlite3_bind_int (statement, 2, 0);
	// key
	sqlite3_bind_blob (statement, 3, static_cast <const void *> (&key), sizeof key, nullptr);
	// value.type
	sqlite3_bind_int (statement, 4, 0);
	// value
	sqlite3_bind_blob (statement, 5, static_cast <const void *> (&value), sizeof value, nullptr);
	//sqlite3_bind_text (statement, 1, value_ptr_str.c_str (), value_ptr_str.length (), SQLITE_TRANSIENT);
	//sqlite3_bind_text (statement, 4, key, key.length (), SQLITE_TRANSIENT);
	//column_count = sqlite3_column_count (statement);
	
	//row = 1;
	//tries = 1;
	// The next line is the fist try to evaluate the expression:
	result_code = sqlite3_step (statement);
	
	if (/*result_code != SQLITE_ROW && */result_code != SQLITE_OK && result_code != SQLITE_DONE)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//value = const_cast <value_t *> (static_cast <const value_t *> (noware::ptr::val (sqlite3_column_text (statement, 0))));
	
	sqlite3_finalize (statement);
	//std::cout << "effect (after 'finalize ()') == [" << effect () << ']' << std::endl;
	
	return true;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::get (const key_t & key, value_t & value) const
{
	if (!connected ())
		return false;
	
	std::string query;
	//noware::nr value;
	void * value_ptr;
	int value_size;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	
	//value_t * value_ptr;
	//std::string value_ptr_str;
	
	query = "select value from entity where id = ?1 and \"key.type\" = ?2 and key = ?3 and \"value.type\" = ?4";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.size (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	
	std::cout << "noware::array::node::get()::key==[" << key << ']' << std::endl;
	
	//value_ptr_str = noware::ptr::str (&value);
	//value_ptr = new value_t (value);
	
	//sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
	//sqlite3_bind_text (statement, 1, value_ptr_str.c_str (), value_ptr_str.length (), SQLITE_TRANSIENT);
	sqlite3_bind_text (statement, 1, "", 0, SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 2, 0);
	sqlite3_bind_blob (statement, 3, static_cast <const void *> (&key), sizeof key, nullptr);
	//sqlite3_bind_text (statement, 3, key, key.length (), SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 4, 0);
	//column_count = sqlite3_column_count (statement);
	
	//row = 1;
	//tries = 1;
	// The next line is the fist try to evaluate the expression:
	result_code = sqlite3_step (statement);
	
	std::cout << "noware::array::node::get()::0" << std::endl;
	if (result_code != SQLITE_ROW/* && result_code != SQLITE_OK && result_code != SQLITE_DONE*/)
	{
		std::cout << "noware::array::node::get()::0.0" << std::endl;
		sqlite3_finalize (statement);
		
		std::cout << "noware::array::node::get()::0.1" << std::endl;
		return false;
	}
	
	value_ptr = sqlite3_column_blob (statement, 0);
	
	std::cout << "noware::array::node::get()::2" << std::endl;
	if (value_ptr == nullptr)
	{
		std::cout << "noware::array::node::get()::2.0" << std::endl;
		sqlite3_finalize (statement);
		
		std::cout << "noware::array::node::get()::2.1" << std::endl;
		return false;
	}
	
	std::cout << "noware::array::node::get()::3" << std::endl;
	//value = const_cast <value_t *> (static_cast <const value_t *> (noware::ptr::val (sqlite3_column_text (statement, 0))));
	value = *(static_cast <const value_t *> (value_ptr));
	//value = noware::ptr::val (sqlite3_column_text (statement, 0));
	
	std::cout << "noware::array::node::get()::4" << std::endl;
	sqlite3_finalize (statement);
	//std::cout << "effect (after 'finalize ()') == [" << effect () << ']' << std::endl;
	
	std::cout << "noware::array::node::get()::5" << std::endl;
	return true;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::clear (void)
{
	if (!connected ())
		return false;
	
	std::string query;
	//noware::nr value;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	
	query = "delete from entity";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.length (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	result_code = sqlite3_step (statement);
	
	if (/*result_code != SQLITE_ROW && */result_code != SQLITE_OK && result_code != SQLITE_DONE)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	return result_code == SQLITE_OK || result_code == SQLITE_DONE;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::remove (const key_t & key)
{
	if (!connected ())
		return false;
	
	std::string query;
	//noware::nr value;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	
	query = "delete from entity where id = ?1 and \"key.type\" = ?2 and key = ?3 and \"value.type\" = ?4";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.length (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
	sqlite3_bind_text (statement, 1, "", 0, SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 2, 0);
	//sqlite3_bind_text (statement, 3, key, strlen (key), SQLITE_TRANSIENT);
	sqlite3_bind_blob (statement, 3, static_cast <const void *> (&key), sizeof key, nullptr);
	//sqlite3_bind_text (statement, 3, key, key.length (), nullptr);
	sqlite3_bind_int (statement, 4, 0);
	
	result_code = sqlite3_step (statement);
	
	if (/*result_code != SQLITE_ROW && */result_code != SQLITE_OK && result_code != SQLITE_DONE)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	return result_code == SQLITE_OK || result_code == SQLITE_DONE;
}

template <typename value_t, typename key_t>
const bool noware::array <value_t, key_t>::node::rename (const key_t & old_k, const key_t & new_k)
{
	if (!connected ())
		return false;
	
	std::string query;
	//noware::nr value;
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	//noware::nr column_count;
	//int column;
	//noware::nr row;
	//noware::nr tries;
	
	query = "update entity set key = ?1 where id = ?2 and \"key.type\" = ?3 and key = ?4";
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, query.c_str (), query.length (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
	//sqlite3_bind_text (statement, 1, key, strlen (new_k), SQLITE_TRANSIENT);
	
	sqlite3_bind_blob (statement, 1, static_cast <const void *> (&new_k), sizeof new_k, nullptr);
	//sqlite3_bind_text (statement, 1, new_k, new_k.length (), SQLITE_TRANSIENT);
	sqlite3_bind_text (statement, 2, "", 0, SQLITE_TRANSIENT);
	sqlite3_bind_int (statement, 3, 0);
	//sqlite3_bind_text (statement, 4, key, strlen (new_k), SQLITE_TRANSIENT);
	sqlite3_bind_blob (statement, 4, static_cast <const void *> (&old_k), sizeof old_k, nullptr);
	//sqlite3_bind_text (statement, 4, old_k, old_k.length (), SQLITE_TRANSIENT);
	
	result_code = sqlite3_step (statement);
	
	if (/*result_code != SQLITE_ROW && */result_code != SQLITE_OK && result_code != SQLITE_DONE)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	return result_code == SQLITE_OK || result_code == SQLITE_DONE;
}
