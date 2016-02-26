//#ifndef MESSAGING_CPP
//#define MESSAGING_CPP

#include <iostream>

#include <boost/thread.hpp>
//#include <boost/thread/detail/thread.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
//#include <ctime>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <time.h>
#include <boost/functional/hash.hpp>

//#include "tcp.h++"
//#include "udp.h++"
#include "ip.h++"
#include "mpi.h++"

const bool LIB::network::mpi::DEFAULT_CYCLE;

LIB::network::mpi::mpi (void)
{
	// Possible values: 229.1.1.1, 229.255.0.1, 239.255.0.1, 239.255.1.1
	
	//message_size = MESSAGE_SIZE;	ULLONG_MAX	// In bytes (characters).
	// 128, 256
	message_size = 128;

	//ports =
	//{
	//	{13, "daytime"},
	//	{21, "ftp"},
	//	{22, "ssh"},
	//	{23, "telnet"},
	//	{25, "smtp"},
	//	{110, "pop3"}
	//};

	//ports [13]	= "daytime";
	//ports [21]	= "ftp";
	//ports [22]	= "ssh";
	//ports [23]	= "telnet";
	//ports [25]	= "smtp";
	//ports [110]	= "pop3";

	//tcp.address = LIB::Network::IP::v4::TCP::ADDRESS;
	//tcp.port = LIB::Network::IP::v4::TCP::PORT;
	//tcp.address = "127.0.0.1";
	
	tcp_receive.address = "0.0.0.0";
	tcp_transmit.address = "0.0.0.0";
	
	tcp_port (1);
	
	//udp.address = LIB::Network::IP::v4::UDP::ADDRESS;
	//udp.port = LIB::Network::IP::v4::UDP::PORT;
	//udp.address = "0.0.0.0";
	//udp.port = 2;
	
	udp_listen.address = "0.0.0.0";
	udp_broadcast.address = "0.0.0.0";
	
	udp_port (2);
	
	//std::cout << (std::string) udp.address << std::endl;
	
	multicast_group_listen = "";
	multicast_group_broadcast = "";
	
	//socket_udp_receive = NULL;
		//socket_udp_receive = new boost::asio::ip::udp::socket (io);
	//socket_tcp_receive = NULL;
	//receive_acceptor = NULL;
	
	//multicast_port = 30001;
	//multicast_address = "239.255.0.1";
	//broadcast_flag = "BC";
	
	//services =
	//{
	//	{13, "daytime"},
	//	{21, "ftp"},
	//	{22, "ssh"},
	//	{23, "telnet"},
	//	{25, "smtp"},
	//	{110, "pop3"}
	//};
	
	//service services.at (13);	// Valid values: see "enum Services" above
	//port = 13;		// Valid values: see "enum Services" above
	//refresh ();
	//io.run ();
}

LIB::network::mpi::~mpi (void)
{
	//io.stop ();
	//// For TCP listening:
	//stop ();
	//// For UDP listening:
	stop ();
}

/*void LIB::network::mpi::stop (void)
{
	//io.stop ();
}
*/

/*
// Getter.
unsigned short int LIB::network::mpi::udp_port (void)
{
}
*/

// Setter.
unsigned short int LIB::network::mpi::udp_port (const unsigned short int & port)
{
	return udp_listen.port = udp_broadcast.port = port;
}

/*
// Getter.
unsigned short int LIB::network::mpi::tcp_port (void)
{
	if (tcp_receive.port == tcp_transmit.port)
	{
		return tcp_receive.port;
	}
	else
	{
		return 0;
	}
}
*/

// Setter.
unsigned short int LIB::network::mpi::tcp_port (const unsigned short int & port)
{
	return tcp_transmit.port = tcp_receive.port = port;
}

void LIB::network::mpi::stop (void)
{
	//cancel_udp ();
	//cancel_tcp ();
	
	//handlers.reset ();
	//mathematics::numbers::natural n;
	//n = handlers.size ();
	
	for (auto & element : handlers)
	{
		/*
		handlers.current_value ().reset ();
		m = handlers.current_value ().size ();

		for (j = 0; j < m; ++ j)
		{
			handlers.current_value ().current_value ().stop ();
			handlers.current_value ().next ();
		}
		*/
		//try
		//{
			//delete * (element.val);
			delete element.v;
		//}
		//catch (...)
		//{
		//}
		
	}
	
	handlers.clear ();
//	handlers.reset ();
//	mathematics::numbers::natural n = handlers.size (), m, i, j;
//	
//	for (i = 0; i < n; ++ i)
//	{
//		/*
//		handlers.current_value ().reset ();
//		m = handlers.current_value ().size ();
//
//		for (j = 0; j < m; ++ j)
//		{
//			handlers.current_value ().current_value ().stop ();
//			handlers.current_value ().next ();
//		}
//		*/
//		//try
//		//{
//			delete handlers [i];
//		//}
//		//catch (...)
//		//{
//		//}
//		
//		handlers.next ();
//	}
}

std::string LIB::network::mpi::multicast_group (const std::string & address)
{
	return multicast_group_broadcast = multicast_group_listen = address;
}

void LIB::network::mpi::stop_udp (void)
{
	//listeners.reset ();
	//mathematics::numbers::natural n;
	//n = listeners.size ();
	
//	listeners.reset ();
//	mathematics::numbers::natural n = listeners.size ();
//	
//	for (mathematics::numbers::natural i = 0; i < n; ++ i)
//	{
//		//boost::hash_combine (hash, handler);
//		//boost::hash_combine (hash, broadcast_address);
//		//boost::hash_combine (hash, port);
//		
//		boost::thread * thread;
//		boost::asio::ip::udp::socket * socket;
//		
//		listeners.current_value () [0] = 0;
//		socket = listeners.current_value () [1];
//		thread = listeners.current_value () [2];
//		
//		if (socket != NULL)
//		{
//			try
//			{
//				socket-> close ();
//				
//				delete socket;
//			}
//			catch (...)
//			{
//			}
//		
//		}
//		
//		if (thread != NULL)
//		{
//			//thread-> close ();
//			
//			try
//			{
//				delete thread;
//			}
//			catch (...)
//			{
//			}
//		}
//		
//		listeners.next ();
//	}
/*
	if (socket_udp_receive != NULL)
	{
		//socket_udp_receive -> cancel ();
		socket_udp_receive -> close ();
	}
*/
}

void LIB::network::mpi::stop_tcp (void)
{
	//io.stop ();
	
//	mathematics::numbers::natural n = receivers.size ();
//	receivers.reset ();
//	
//	for (mathematics::numbers::natural i = 0; i< n; ++ i)
//	{
//		boost::shared_ptr <boost::asio::io_service> io_service;
//		io_service = receivers.current_value ();
//		
//		if (io_service != NULL)
//		{
//			try
//			{
//				io_service-> stop ();
//				//delete io_service;
//			}
//			catch (...)
//			{
//			}
//		}
//		
//		receivers.next ();
//	}
}

/*
Send
	boost::asio::io_service io;
	boost::asio::ip::tcp::socket socket(io);

	boost::asio::ip::tcp::resolver resolver(io);
	boost::asio::ip::tcp::resolver::query query(host, service);

	boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	boost::asio::connect(socket, endpoint_iterator);
	size_t len = boost::asio::write(socket, boost::asio::buffer(message));
	return !(len < message.length());

	Broadcast:
	boost::asio::io_service io;

	boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(address), port);
	boost::asio::ip::udp::socket socket(io, endpoint.protocol());

	size_t len = socket.send_to(boost::asio::buffer(message), endpoint);

	return !(len < message.length());

Receive:
	boost::asio::ip::tcp::acceptor acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

	boost::asio::ip::tcp::socket socket(io);
	acceptor.accept(socket);


	boost::array<char, MAX_MESSAGE_SIZE> buf; // 2 ^ 20

	size_t len = socket.receive (boost::asio::buffer(buf, MAX_MESSAGE_SIZE)); //, ignored_error);

	std::string message = buf.data();

	return message.substr(0, len);

Receive broadcast
	boost::asio::io_service io;
	boost::asio::ip::udp::socket socket (io);
	boost::asio::ip::udp::endpoint sender_endpoint;

	boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string("0.0.0.0"), port);


	socket.open (listen_endpoint.protocol());
	socket.set_option (boost::asio::ip::udp::socket::reuse_address(true));
	socket.bind (listen_endpoint);

	Join the multicast group.
	socket.set_option (boost::asio::ip::multicast::join_group(boost::asio::ip::address::from_string(address)));

	char data[MAX_MESSAGE_SIZE];
	size_t len = socket.receive_from (boost::asio::buffer(data, MAX_MESSAGE_SIZE), sender_endpoint);

	std::string message = data;
	return message.substr(0, len);
*/
//bool LIB::Network::mpi::Send (std::string message)

bool LIB::network::mpi::transmit (const std::string & message)
{
	return transmit (message, tcp_transmit.address, tcp_transmit.port);
}

bool LIB::network::mpi::transmit (const std::string & message, const std::string & address)
{
	return transmit (message, address, tcp_transmit.port);
}

bool LIB::network::mpi::transmit (const std::string & message, const unsigned short int & port)
{
	return transmit (message, tcp_transmit.address, port);
}

bool LIB::network::mpi::transmit (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return transmit (message, address, port);
}

bool LIB::network::mpi::transmit (const std::string & message, const std::string & address, const unsigned short int & port)
{
	try
	{
		mathematics::numbers::natural len;

		//boost::asio::io_service io;
		boost::asio::ip::tcp::socket socket (io);
		//boost::asio::ip::address addr = boost::asio::ip::address::from_string ("127.0.0.1");
		// boost::asio::ip::tcp::resolver resolver (io);

		// boost::asio::ip::tcp::resolver::query query (tcp.Address (), "");
		
		// boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve (query);
		///
		//boost::asio::ip::address::address addr;
		// boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (tcp.Address ()), tcp.Port ());
		//std::cout << "Error...1" << std::endl;
		//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
		boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
		//std::cout << "Error...2" << std::endl;
		boost::system::error_code ec;
		//socket.connect(connectionEndpoint, ec);
		///
		
		// boost::asio::connect (socket, endpoint);
		//boost::asio::connect (socket, endpoint);
		socket.connect (endpoint, ec);
		std::cout << ec << std::endl;
		
		len = boost::asio::write (socket, boost::asio::buffer (message));
		
		return !(len < message.length ());
	}
	catch (std::exception & e)
	{
		std::cout << e.what () << std::endl;
		//error = e.what();
		//error = e;

		return false;
	}
	catch (...) //(std::exception & e)
	{
		//std::cout << e.what () << std::endl;
		//error = e.what();
		//error = e;

		return false;
	}
}

bool LIB::network::mpi::broadcast (const std::string & message)
{
	return broadcast (message, udp_broadcast.address, udp_broadcast.port);
}

bool LIB::network::mpi::broadcast (const std::string & message, const std::string & address)
{
	return broadcast (message, address, udp_broadcast.port);
}

bool LIB::network::mpi::broadcast (const std::string & message, const unsigned short int & port)
{
	return broadcast (message, udp_broadcast.address, port);
}

bool LIB::network::mpi::broadcast (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return broadcast (message, address, port);
}

bool LIB::network::mpi::broadcast (const std::string & message, const std::string & address, const unsigned short int & port)
{
	try
	{
		//boost::asio::io_service io_service;

		// Server binds to any address and any port.
		//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
		boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), 0));
		socket.set_option (boost::asio::socket_base::broadcast (true));
		
		// Broadcast will go to port 8888.
		boost::asio::ip::udp::endpoint broadcast_endpoint (boost::asio::ip::address_v4::broadcast (), port);
		
		// Broadcast data.
		mathematics::numbers::natural length = socket.send_to (boost::asio::buffer (message), broadcast_endpoint);
		
		return length >= message.length ();
		
//		mathematics::numbers::natural length;
//		
//		//boost::asio::io_service io;
//		
//		//boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
//		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
//		//boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::udp::v4 (), port);
//		boost::asio::ip::udp::socket socket (io, endpoint.protocol ());
//		//socket_udp_send = new boost::asio::ip::udp::socket (io, endpoint.protocol ());
//		//socket.set_option (boost::asio::socket_base::broadcast (true));
//		
//		if (! multicast_group_broadcast.empty ()/* && address != "0.0.0.0"*/)
//		{
//			socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_broadcast)));
//		}
//		
//		//socket.open (boost::asio::ip::udp::v4 ());
//		
//		length = socket.send_to (boost::asio::buffer (message), endpoint);
//		//len = boost::asio::write (socket, boost::asio::buffer (message), endpoint);
//		
//		//delete socket_udp_send;
//		//socket_udp_send = NULL;
//
//		return !(length < message.length ());
	}
	catch (...) //(std::exception & e)
	{
		//error = e.what();
		//error = e;

		return false;
	}
}

//std::string LIB::network::mpi::receive (const unsigned short int & port, const unsigned short int & version, void (* handler) (std::string), void (* handler_internal) (std::string))
/*std::string LIB::network::mpi::receive (const unsigned short int & port, const unsigned short int & version, void (* handler) (std::string), void (* handler_internal) (std::string))
{
	(* handler) (receive (link, handler, & LIB::network::mpi::receive_async_handler));
	unsigned long int hash = 0;
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	boost::hash_combine <const connection &> (hash, link);
	boost::hash_combine <const bool &> (hash, cycle);
	
	
	handlers.unset (hash);
}
*/
std::string LIB::network::mpi::receive (void)
{
	return receive (tcp_receive.address, tcp_receive.port);
}

std::string LIB::network::mpi::receive (const std::string & address)
{
	return receive (address, tcp_receive.port);
}

std::string LIB::network::mpi::receive (const unsigned short int & port)
{
	return receive (tcp_receive.address, port);
}

std::string LIB::network::mpi::receive (const unsigned short int & port, const std::string & address)
{
	return receive (address, port);
}

std::string LIB::network::mpi::receive (const std::string & address, const unsigned short int & port)
//std::string LIB::Network::mpi::Receive ()
{
	try
	{
		std::cout << "Messaging.cpp:\'receive()\' : Waiting to Receive..." << std::endl;
		//boost::asio::ip:tcp::iostream ios ();
		//unsigned short int port = tcp.Port ();
		//boost::asio::io_service io;
		std::string message;
		//boost::asio::ip::tcp::acceptor * acceptor;
		boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
		boost::asio::ip::tcp::acceptor acceptor (io, endpoint);
		boost::asio::ip::tcp::socket socket (io);
		
		//char * data;
		
		double diff;
		unsigned long long int available_chars;
		time_t time_end_allowed, time_end_actual;
		
		std::cout << "\tPreparing to Receive..." << std::endl;
		acceptor.accept (socket);
		
		/*if (handler != NULL && cycle)
		{
			handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, port, version, handler, cycle, hash));
			//handlers [hash] = t;
			//(* handler) (message);
		}
		else
		{
			handlers.unset (hash);
		}*/
		
		//boost::array<char, MESSAGE_SIZE> buf;
		// char * buffer = new char [message_size];
		//boost::posix_time::time_duration attempt = boost::posix_time::microseconds (1000);
		//time_start = time (NULL);
		//std::cout << time_start << std::endl;
		time_end_allowed = time (NULL);
		
		do
		{
			available_chars = socket.available ();	// This time may not work, returning 0.
			//available = socket_tcp_receive -> available ();
			//std::cout << time (NULL) << std::endl;
			time_end_actual = time (NULL);
			diff = std::difftime (time_end_actual, time_end_allowed);
		}
		while (available_chars <= 0 && diff <= 0.01);
		
		//data = new char [message_size];
		//data = new char [available_chars];
		char data [available_chars];
		
		
		//std::cout << "AVAILABLE(" << available<< ")";
		//std::vector <char> data (available);

		//size_t len = socket.receive (boost::asio::buffer (buf, message_size)); //, ignored_error);
		// mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (buffer, message_size)); //, ignored_error);
		//mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (data, available)); //, ignored_error);
		///*mathematics::numbers::natural len =*/ socket_tcp_receive -> receive (boost::asio::buffer (& message [0], message.size ())); //, ignored_error);
		// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
		// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
		// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (data));
		// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (message));
		//boost::asio::read (* socket_tcp_receive, boost::asio::buffer (& message [0], message.size ()));
		/*size_t len = */boost::asio::read (socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
		//boost::asio::read (* socket_tcp_receive, & message [0]);
		//socket_tcp_receive -> read_some (message);
		//socket_tcp_receive -> read_some (& message [0]);
		//socket_tcp_receive -> read_some (boost::asio::buffer (& message [0], 3));
		//size_t len = socket_tcp_receive -> receive (boost::asio::buffer (data, message_size)/*, ignored_error*/);
		//socket_tcp_receive -> read_some (boost::asio::buffer (data, available_chars)/*, ignored_error*/);
		
		
		acceptor.close ();
		//std::cout << "Messaging.cpp: Deleting \'receive_acceptor\'..." << std::endl;
		//delete acceptor;
		//std::cout << "Messaging.cpp: Deleted \'receive_acceptor\'..." << std::endl;
		//acceptor = NULL;
		
		//delete endpoint;
		
		//delete socket;
		//socket = NULL;
		
		//message = buf.data ();
		message = data;
		//delete [] data;
		//
		//for (unsigned long long int i = 0; i < available; ++ i)
		//{
		//	message += data [i];
		//}
		//
		//data[0];
		// message = buffer;
		//std::cout << std::endl << buf << std::endl;
		// delete [] buffer;

		//if (acceptor != NULL)
		//for (Mathematics::Number::Natural index = 0; index < message_size; index)
		
		
		std::cout << "Messaging.cpp: Received Message [" << message.substr (0, available_chars) << "]" << std::endl;
		
		// return message.substr (0, len);
		//return message.substr (0, 3);
		//std::cout << "Available characters: " << available_chars << std::endl;
		//std::cout << "Read characters: " << len << std::endl;
		//message = message.substr (0, available_chars);
		
		
		//return message;
		return message.substr (0, available_chars);
		//return message.substr (0, len);
		//return data.data ();
		//return data;

		//std::string buffer;
		//size_t size = socket.receive (boost::asio::buffer (buffer)); //, ignored_error);
		//return buffer;
	}
	catch (std::exception & e) //(...) //(std::exception & e)
	{
		//acceptor -> close ();
		std::cout << "Messaging.cpp (std::exception): \'Receive\' : Error: " << e.what () << std::endl;
		//error = e;
		
		//return e.what();
		return "";
	}
	catch (...) //(...) //(std::exception & e)
	{
		//acceptor -> close ();
		std::cout << "Messaging.cpp (...): \'Receive\': Error." << std::endl;
		//error = e;

		//return e.what();
		return "";
	}
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler)
{
	return receive_async (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle)
{
	return receive_async (handler, tcp_receive.address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address)
{
	return receive_async (handler, address, tcp_receive.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port)
{
	return receive_async (handler, tcp_receive.address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
{
	return receive_async (handler, address, tcp_receive.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
{
	return receive_async (handler, address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
{
	return receive_async (handler, tcp_receive.address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
{
	return receive_async (handler, tcp_receive.address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
{
	return receive_async (handler, address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
{
	return receive_async (handler, tcp_receive.address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
{
	unsigned long int hash = 0;
	//hash = 0;
	//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
	boost::hash_combine <ip::protocol> (hash, ip::protocol::tcp);
	boost::hash_combine <const std::string &> (hash, address);
	//boost::hash_combine <const unsigned short int> (hash, version);
	//boost::hash_combine <const connection &> (hash, link);
	boost::hash_combine <const unsigned short int &> (hash, port);
	//boost::hash_combine <const bool &> (hash, cycle);
	
	//if (handlers.exists (hash))
	//	return false;
	
	if (handlers.exists (hash))
		return false;
	
	handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
	
	//return handlers.exists (hash);
	return true;
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
{
	return receive_async (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
{
	return receive_async (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
{
	return receive_async (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
{
	return receive_async (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
{
	return receive_async (handler, address, port, cycle);
}

void LIB::network::mpi::receive_async_handler (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle, const unsigned long int & hash)
{
	//do
	//{
	//	(* handler) (receive (link, handler, & LIB::network::mpi::receive_async_handler));
	//}
	//(* handler) (receive (port, version, & LIB::network::mpi::receive_async_handler));
	//(* handler) (receive (port, version, handler, cycle));
	//handler (receive (port, version, handler, cycle));
	
	//while (cycle);
	if (handler != NULL)
	{
		try
		{
			std::cout << "Messaging.cpp:\'receive_async_handler()\': Waiting to Receive..." << std::endl;
			std::cout << "Messaging.cpp:\'receive_async_handler()\': address " << address << std::endl;
			std::cout << "Messaging.cpp:\'receive_async_handler()\': port " << port << std::endl;
			//boost::asio::ip:tcp::iostream ios ();
			//unsigned short int port = tcp.Port ();
			//boost::asio::io_service io;
			std::string message;
			//boost::asio::ip::tcp::acceptor * acceptor;
			// boost::asio::ip::tcp::endpoint * endpoint;
			// boost::asio::ip::tcp::acceptor * acceptor;
			// boost::asio::ip::tcp::socket * socket;
			
			boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::endpoint (boost::asio::ip::address::from_string (address), port));
			boost::asio::ip::tcp::acceptor acceptor (io, endpoint);
			
			acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
			
			boost::asio::ip::tcp::socket socket (io);
			
			//char * data;
			
			/*
			switch (version)
			{
				case 6:
					endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port);
					//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port));
					break;
				case 4:
					endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);

					if (version != 4)
						version = 4;	// Make sure it is 4.
					//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
			}
			*/
			
			//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::v4 ());
			//boost::asio::ip::tcp::acceptor acceptor = boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
			// /*receive_*/acceptor = new boost::asio::ip::tcp::acceptor (io, * endpoint);
			//acceptor -> open (endpoint -> protocol ());
			// /*receive_*/acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));

			//boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp:: (, port));
			//boost::asio::ip::tcp::acceptor acceptor (io);
			//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp (boost::asio::ip::tcp::family ()), port);

			//acceptor.open (endpoint.protocol ());
			//acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address(true));
			//boost::asio::ip::tcp::socket socket (io);
			// cancel_tcp ();

			//socket/*_tcp_receive*/ = new boost::asio::ip::tcp::socket (io);

			double diff;
			unsigned long long int available_chars;
			time_t time_end_allowed, time_end_actual;
			//boost::thread * t;

			/*
			unsigned long int hash = 0;
			boost::hash_combine <void (*) (std::string)> (hash, handler);
			//boost::hash_combine <const connection &> (hash, link);
			boost::hash_combine <const unsigned short int &> (hash, version);
			boost::hash_combine <const unsigned short int &> (hash, port);
			//boost::hash_combine <const bool &> (hash, cycle);
			*/

			std::cout << "\tPreparing to Receive..." << std::endl;
			///*receive_*/acceptor.accept (socket/*_tcp_receive*/);
			acceptor.accept (socket/*_tcp_receive*/);
			
//			if (/*handler != NULL && */cycle)
//			{
//				handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
//				//handlers [hash] = t;
//				//(* handler) (message);
//			}
//
			//boost::array<char, MESSAGE_SIZE> buf;
			// char * buffer = new char [message_size];
			//boost::posix_time::time_duration attempt = boost::posix_time::microseconds (1000);
			//time_start = time (NULL);
			//std::cout << time_start << std::endl;
			time_end_allowed = time (NULL);

			do
			{
				//available_chars = socket/*_tcp_receive*/ -> available ();	// This time may not work, returning 0.
				available_chars = socket.available ();	// This time may not work, returning 0.
				//available = socket_tcp_receive -> available ();
				//std::cout << time (NULL) << std::endl;
				time_end_actual = time (NULL);
				diff = std::difftime (time_end_actual, time_end_allowed);
			}
			while (available_chars <= 0 && diff <= 0.01);
			
			//data = new char [message_size];
			//data = new char [available_chars];
			char data [available_chars];
			
			
			//std::cout << "AVAILABLE(" << available<< ")";
			//std::vector <char> data (available);
			
			//size_t len = socket.receive (boost::asio::buffer (buf, message_size)); //, ignored_error);
			// mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (buffer, message_size)); //, ignored_error);
			//mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (data, available)); //, ignored_error);
			///*mathematics::numbers::natural len =*/ socket_tcp_receive -> receive (boost::asio::buffer (& message [0], message.size ())); //, ignored_error);
			// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
			// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
			// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (data));
			// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (message));
			//boost::asio::read (* socket_tcp_receive, boost::asio::buffer (& message [0], message.size ()));
			// /*size_t len = */boost::asio::read (* socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
			boost::asio::read (socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
			//boost::asio::read (* socket_tcp_receive, & message [0]);
			//socket_tcp_receive -> read_some (message);
			//socket_tcp_receive -> read_some (& message [0]);
			//socket_tcp_receive -> read_some (boost::asio::buffer (& message [0], 3));
			//size_t len = socket_tcp_receive -> receive (boost::asio::buffer (data, message_size)/*, ignored_error*/);
			//socket_tcp_receive -> read_some (boost::asio::buffer (data, available_chars)/*, ignored_error*/);


			acceptor.close ();
			//std::cout << "Messaging.cpp: Deleting \'receive_acceptor\'..." << std::endl;
			//delete acceptor;
			//std::cout << "Messaging.cpp: Deleted \'receive_acceptor\'..." << std::endl;
			//acceptor = NULL;

			//delete endpoint;

			//delete socket;
			//socket = NULL;

			//message = buf.data ();
			message = data;
			//delete [] data;
			//
			//for (unsigned long long int i = 0; i < available; ++ i)
			//{
			//	message += data [i];
			//}
			//
			//data[0];
			// message = buffer;
			//std::cout << std::endl << buf << std::endl;
			// delete [] buffer;
			
			//if (acceptor != NULL)
			//for (Mathematics::Number::Natural index = 0; index < message_size; index)
			
			
			std::cout << "Messaging.cpp: receive_async_handler(): Received Message [" << message/*.substr (0, available_chars)*/ << "]" << std::endl;
			
			// return message.substr (0, len);
			//return message.substr (0, 3);
			//std::cout << "Available characters: " << available_chars << std::endl;
			//std::cout << "Read characters: " << len << std::endl;
			//message = message.substr (0, available_chars);
			
			std::cout << "Messaging.cpp: receive_async_handler(): Received: Calling handler: handler (message.substr (0, available_chars))" << std::endl;
				handler (message/*.substr (0, available_chars)*/);
			
			if (/*handler != NULL && */cycle)
			{
				handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
				//handlers [hash] = t;
				//(* handler) (message);
			}
			
			if (! cycle)
			{
				handlers.unset (hash);
			}

			//return message;
			//return message.substr (0, available_chars);
			//return message.substr (0, len);
			//return data.data ();
			//return data;

			//std::string buffer;
			//size_t size = socket.receive (boost::asio::buffer (buffer)); //, ignored_error);
			//return buffer;
		}
		catch (std::exception & e) //(...) //(std::exception & e)
		{
			//acceptor -> close ();
			std::cout << "Messaging.cpp:933: receive_async_handler(): (std::exception): Error: " << e.what () << std::endl;
			//error = e;

			//return e.what();
			//return "";
		}
		catch (...) //(...) //(std::exception & e)
		{
			//acceptor -> close ();
			std::cout << "Messaging.cpp (...): receive_async_handler(): Error." << std::endl;
			//error = e;

			//return e.what();
			//return "";
		}
	}
}

/*
bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool cycle, const std::string & address, const unsigned short int version)
{
	return receive_async_stop (handler, tcp.port, version, cycle);
}
*/

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler)
{
	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address)
{
	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port)
{
	return receive_async_stop (handler, tcp_receive.address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle)
{
	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
{
	return receive_async_stop (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
{
	return receive_async_stop (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
{
	return receive_async_stop (handler, address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
{
	return receive_async_stop (handler, tcp_receive.address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
{
	return receive_async_stop (handler, address, tcp_receive.port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
{
	return receive_async_stop (handler, tcp_receive.address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
//bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
{
	//if (handler != NULL)
	//{
		//protocol p = protocol::tcp;
		unsigned long int hash = 0;
		//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
		boost::hash_combine <ip::protocol> (hash, ip::protocol::tcp);
		boost::hash_combine <const std::string &> (hash, address);
		//boost::hash_combine <const connection &> (hash, link);
		//boost::hash_combine <const unsigned short int> (hash, version);
		boost::hash_combine <const unsigned short int &> (hash, port);
		//boost::hash_combine <const bool> (hash, cycle);


		//boost::shared_ptr <boost::asio::io_service> io_service;
		//io_service = receivers [hash];

		//try
		//{
			//io_service-> stop ();
		//	handlers [hash].[handlers [hash].size () - 1].stop ();
			//delete io_service;
		//}
		//catch (...)
		//{
		//}

		if (! handlers.exists (hash))
			return true;
		
		try
		{
			//handlers [hash] -> interrupt ();
			delete handlers [hash];
		}
		catch (...)
		{
			return false;
		}
		
		handlers.unset (hash);
	//}
	
	return true;
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
{
	return receive_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
{
	return receive_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
{
	return receive_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
{
	return receive_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
{
	return receive_async_stop (handler, address, port, cycle);
}

// UDP:

//std::string LIB::Network::mpi::Listen ()
std::string LIB::network::mpi::listen (void)
{
	return listen (udp_listen.address, udp_listen.port);
}

std::string LIB::network::mpi::listen (const std::string & address)
{
	return listen (address, udp_listen.port);
}

std::string LIB::network::mpi::listen (const unsigned short int & port)
{
	return listen (udp_listen.address, port);
}

std::string LIB::network::mpi::listen (const unsigned short int & port, const std::string & address)
{
	return listen (address, port);
}

std::string LIB::network::mpi::listen (const std::string & address, const unsigned short int & port)
{
	try
	{
		//std::cout << "Messaging.cpp: Listening (Edited)..." << std::endl;
		std::string message;
		
		
		//boost::asio::io_service io_service;
		//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
		boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), port));
		boost::asio::ip::udp::endpoint sender_endpoint;
		
		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
		
//		socket.open (endpoint.protocol ());
//		//socket.open (boost::asio::ip::udp::v4 ());
//		
//		std::cout << "Messaging.cpp: listen (): allowing reusage of addresses..." << std::endl;
//		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
//		//socket.set_option (boost::asio::socket_base::broadcast (true));
//		
//		//socket.bind (endpoint);
//		//socket.connect (endpoint);
//		
//		// Join the multicast group.
//		//std::cout << "Messaging.cpp: listen (): joining the multicast group " << address << " ..." << std::endl;
//		//socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
//		if (! multicast_group_listen.empty ())
//		{
//			// Join the multicast group.
//			socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
//		}
//		
//		socket.bind (endpoint);
		
		char data [message_size];
		
		//socket.receive_from (boost::asio::buffer (buffer), sender_endpoint);
		mathematics::numbers::natural length = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		
		message = data;
		
		//message = message.substr (0, length);
		
		//std::cout << "Messaging.cpp: Listened (Edited): [" << message << "]" << std::endl;
		
		//return message;
		return message.substr (0, length);
		
//		//boost::asio::io_service io;
//		//boost::asio::io_service io_2;
//		// boost::asio::ip::udp::socket socket;
//		//boost::asio::ip::udp::socket socket (io);
//		// cancel_udp ();
//
//		// socket_udp_receive = new boost::asio::ip::udp::socket (io);
//		//boost::asio::ip::udp::endpoint sender_endpoint;
//		
//		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
//		//boost::asio::ip::udp::endpoint endpoint;
//		
//		boost::asio::ip::udp::socket socket (io/*, endpoint/*.protocol ()*/);
//		
//		socket.open (endpoint.protocol ());
//		//socket.open (boost::asio::ip::udp::v4 ());
//		
//		std::cout << "Messaging.cpp: listen (): allowing reusage of addresses..." << std::endl;
//		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
//		//socket.set_option (boost::asio::socket_base::broadcast (true));
//		
//		//socket.bind (endpoint);
//		//socket.connect (endpoint);
//		
//		// Join the multicast group.
//		//std::cout << "Messaging.cpp: listen (): joining the multicast group " << address << " ..." << std::endl;
//		//socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
//		if (! multicast_group_listen.empty ())
//		{
//			// Join the multicast group.
//			socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
//		}
//		
//		socket.bind (endpoint);
//		
//		//
//		//socket_udp_receive -> connect (,);
//		//unsigned long long int available = 5;
//			///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
//		
//		//char * data = new char [available];
//		//char data [MESSAGE_SIZE];
//		//char * data = new char [message_size];
//		char data [message_size];
//		
//		//io_2.run ();
//		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//		//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//		mathematics::numbers::natural length = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
//		
//		/*
//		if (handler != NULL && cycle)
//		{
//			handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, address, port, handler, cycle, hash));
//			//handlers [hash] = t;
//			//(* handler) (message);
//		}
//		else
//		{
//			handlers.unset (hash);
//		}
//		*/
//		
//		//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
//		// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
//		//socket_udp_receive ->
//		message = data;
//		//delete [] data;
//
//		//delete socket;
//		//socket = NULL;
//
//		std::cout << "Messaging.cpp: Listened: [" << message.substr (0, length) << "]" << std::endl;
//		
//		return message.substr (0, length);
		//return message.substr (0, available);
	}
	catch (std::exception & e)
	{
		//error = e;
		//std::cout << "Error: Listening." << std::endl;
		std::cout << "Messaging.cpp (std::exception & e): \'Listen\': Error:" << e.what () << std::endl;
		//return e.what();
		return "";
	}
	catch (...) //(std::exception & e)
	{
		//error = e;
		//std::cout << "Error: Listening." << std::endl;
		std::cout << "Messaging.cpp (...): \'Listen\': Error." << std::endl;
		//return e.what();
		return "";
	}
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler)
{
	return listen_async (handler, udp_listen.address, udp_listen.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address)
{
	return listen_async (handler, address, udp_listen.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port)
{
	return listen_async (handler, udp_listen.address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle)
{
	return listen_async (handler, udp_listen.address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
{
	return listen_async (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
{
	return listen_async (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
{
	return listen_async (handler, address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
{
	return listen_async (handler, udp_listen.address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
{
	return listen_async (handler, address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
{
	return listen_async (handler, udp_listen.address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
//bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & broadcast_address, const unsigned short int & port, const bool cycle)
{
	unsigned long int hash = 0;
	//hash = 0;
	//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
	//boost::hash_combine <const connection &> (hash, link);
	boost::hash_combine <ip::protocol> (hash, ip::protocol::udp);
	boost::hash_combine <const std::string &> (hash, address);
	boost::hash_combine <const unsigned short int &> (hash, port);
	//boost::hash_combine <const bool> (hash, cycle);
	
	if (handlers.exists (hash))
		return false;
	
	handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
	
	//return handlers.exists (hash);
	return true;
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
{
	return listen_async (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
{
	return listen_async (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
{
	return listen_async (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
{
	return listen_async (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
{
	return listen_async (handler, address, port, cycle);
}

void LIB::network::mpi::listen_async_handler (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle, const unsigned long int & hash)
{
	//do
	//{
	//	(* handler) (receive (link, handler, & LIB::network::mpi::receive_async_handler));
	//}
	//(* handler) (receive (port, version, & LIB::network::mpi::receive_async_handler));
	//(* handler) (receive (port, version, handler, cycle));
	//handler (listen (broadcast_address, port, handler, cycle, hash));
	//while (cycle);
	
	if (handler != NULL)
	{
		try
		{
			std::string message;
			
			//boost::asio::io_service io_service;
			//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
			boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), port));
			
			boost::asio::ip::udp::endpoint sender_endpoint;
			
			socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
			
			char data [message_size];
			
			mathematics::numbers::natural length = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
			
//			if (/*handler != NULL && */cycle)
//			{
//				handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
//			}
			
			message = data;
			//message = message.substr (0, length);
			
			handler (message.substr (0, length));
			
			if (/*handler != NULL && */cycle)
			{
				handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
			}
			
			if (! cycle)
			{
				handlers.unset (hash);
			}
			
			///
			
//			std::cout << "Messaging.cpp: Listening..." << std::endl;
//			std::string message;
//
//			//boost::asio::io_service io;
//			// boost::asio::ip::udp::socket socket;
//			//boost::asio::ip::udp::socket socket (io);
//			// cancel_udp ();
//
//			// socket_udp_receive = new boost::asio::ip::udp::socket (io);
//			boost::asio::ip::udp::socket socket (io);
//			//boost::asio::ip::udp::endpoint sender_endpoint;ad
//
//			boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
//
//			socket.open (endpoint.protocol ());
//			socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
//
//			if (! multicast_group_listen.empty ())
//			{
//				// Join the multicast group.
//				socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
//			}
//			
//			socket.bind (endpoint);
//			
//			//
//			//socket_udp_receive -> connect (,);
//			//unsigned long long int available = 5;
//				///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
//
//			//char * data = new char [available];
//			//char data [MESSAGE_SIZE];
//			//char * data = new char [message_size];
//			char data [message_size];
//
//			//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//			//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//			mathematics::numbers::natural len = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
//
//			if (/*handler != NULL && */cycle)
//			{
//				handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
//				//handlers [hash] = t;
//				//(* handler) (message);
//			}
//			//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
//			// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
//			//socket_udp_receive ->
//			message = data;
//			//delete [] data;
//
//			//delete socket;
//			//socket = NULL;
//
//			std::cout << "Messaging.cpp: Listened: [" << message.substr (0, len) << "]" << std::endl;
//
//			//handler (listen (broadcast_address, port, handler, cycle, hash));
//			
//			std::cout << "Messaging.cpp: Listened: Calling handler: handler (message.substr (0, len))" << std::endl;
//				handler (message.substr (0, len));
//
//			if (! cycle)
//			{
//				handlers.unset (hash);
//			}
//
//			//return message.substr (0, len);
//			//return message.substr (0, available);
		}
		catch (std::exception & e)
		{
			//error = e;
			//std::cout << "Error: Listening." << std::endl;
			std::cout << "Messaging.cpp (std::exception & e): \'Listen_async_handler\': Error: " << e.what () << std::endl;
			//return e.what();
			//return "";
		}
		catch (...) //(std::exception & e)
		{
			//error = e;
			//std::cout << "Error: Listening." << std::endl;
			std::cout << "Messaging.cpp (...): \'Listen_async_handler\': Error." << std::endl;
			//return e.what();
			//return "";
		}
	}
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler)
{
	return listen_async_stop (handler, udp_listen.address, udp_listen.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address)
{
	return listen_async_stop (handler, address, udp_listen.port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port)
{
	return listen_async_stop (handler, udp_listen.address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle)
{
	return listen_async_stop (handler, udp_listen.address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
{
	return listen_async_stop (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
{
	return listen_async_stop (handler, address, port, DEFAULT_CYCLE);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
{
	return listen_async_stop (handler, address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
{
	return listen_async_stop (handler, udp_listen.address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
{
	return listen_async_stop (handler, address, udp_listen.port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
{
	return listen_async_stop (handler, udp_listen.address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
//bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool cycle)
{
	//if (handler != NULL)
	//{
		//unsigned long int version = 4;
		unsigned long int hash = 0;
		
		//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
		//boost::hash_combine <unsigned short int> (hash, version);
		boost::hash_combine <ip::protocol> (hash, ip::protocol::udp);
		boost::hash_combine <const std::string &> (hash, address);
		boost::hash_combine <const unsigned short int &> (hash, port);
		//boost::hash_combine <const bool> (hash, cycle);
		
		if (! handlers.exists (hash))
			return true;
		
		try
		{
			delete handlers [hash];
		}
		catch (...)
		{
			return false;
		}
		
		handlers.unset (hash);
	//}
	
	return true;
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
{
	return listen_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
{
	return listen_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
{
	return listen_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
{
	return listen_async_stop (handler, address, port, cycle);
}

bool LIB::network::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
{
	return listen_async_stop (handler, address, port, cycle);
}


/*
std::exception LIB::Network::mpi::Error (void)
{
	return error;
}
*/
/*
LIB::network::messaging::address::address (void)
{
	refresh ();
}

bool LIB::network::messaging::address::refresh (void)
{
	_value = LIB::network::ip::address ();

	return true;
}

std::string LIB::network::messaging::address::value (void)
{
	return _value;
}
*/
//#endif MESSAGING_CPP
