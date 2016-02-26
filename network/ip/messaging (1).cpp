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

//#include "tcp.hpp"
//#include "udp.hpp"
#include "ip.hpp"
#include "messaging.hpp"

LIB::network::mpi::mpi (void)
{
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
	tcp.address = "127.0.0.1";
	tcp.port = 1;
	
	//udp.address = LIB::Network::IP::v4::UDP::ADDRESS;
	//udp.port = LIB::Network::IP::v4::UDP::PORT;
	udp.address = "229.1.1.1";	// Possible values: 229.1.1.1, 229.255.0.1, 239.255.0.1, 239.255.1.1
	
	//std::cout << (std::string) udp.address << std::endl;
	
	udp.port = 2;
	
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
}

LIB::network::mpi::~mpi (void)
{
	//io.stop ();
	//// For TCP listening:
	//stop ();
	//// For UDP listening:
	cancel ();
}

void LIB::network::mpi::stop (void)
{
	//io.stop ();
}

void LIB::network::mpi::cancel (void)
{
	//cancel_udp ();
	//cancel_tcp ();
	
	//handlers.reset ();
	//mathematics::numbers::natural n;
	//n = handlers.size ();
	
	handlers.reset ();
	mathematics::numbers::natural n = handlers.size (), m, i, j;
	
	for (i = 0; i < n; ++ i)
	{
		handlers.current_value ().reset ();
		m = handlers.current_value ().size ();

		for (j = 0; j < m; ++ j)
		{
			handlers.current_value ().current_value ().stop ();
			handlers.current_value ().next ();
		}
		
		handlers.next ();
	}
}

void LIB::network::mpi::cancel_udp (void)
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

void LIB::network::mpi::cancel_tcp (void)
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

bool LIB::network::mpi::transmit (const std::string message)
{
	return transmit (message, tcp.address, tcp.port);
}

bool LIB::network::mpi::transmit (const std::string message, const std::string address)
{
	return transmit (message, address, tcp.port);
}

bool LIB::network::mpi::transmit (const std::string message, const unsigned short int port)
{
	return transmit (message, tcp.address, port);
}

bool LIB::network::mpi::transmit (const std::string message, const std::string address, const unsigned short int port)
{
	try
	{
		mathematics::numbers::natural len;

		boost::asio::io_service io;
		boost::asio::ip::tcp::socket socket (io);
		//boost::asio::ip::address addr = boost::asio::ip::address::from_string ("127.0.0.1");
		// boost::asio::ip::tcp::resolver resolver (io);

		// boost::asio::ip::tcp::resolver::query query (tcp.Address (), "");
		
		// boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve (query);
		///
		//boost::asio::ip::address::address addr;
		// boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (tcp.Address ()), tcp.Port ());
		//std::cout << "Error...1" << std::endl;
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

bool LIB::network::mpi::broadcast (const std::string message)
{
	return broadcast (message, udp.address, udp.port);
}

bool LIB::network::mpi::broadcast (const std::string message, const std::string address)
{
	return broadcast (message, address, udp.port);
}

bool LIB::network::mpi::broadcast (const std::string message, const unsigned short int port)
{
	return broadcast (message, udp.address, port);
}

bool LIB::network::mpi::broadcast (const std::string message, const std::string address, const unsigned short int port)
{
	try
	{
		mathematics::numbers::natural len;
		
		boost::asio::io_service io;
		
		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
		boost::asio::ip::udp::socket socket (io, endpoint.protocol ());
		//socket_udp_send = new boost::asio::ip::udp::socket (io, endpoint.protocol ());
		
		len = socket.send_to (boost::asio::buffer (message), endpoint);
		//len = boost::asio::write (socket, boost::asio::buffer (message), endpoint);
		
		//delete socket_udp_send;
		//socket_udp_send = NULL;

		return !(len < message.length ());
	}
	catch (...) //(std::exception & e)
	{
		//error = e.what();
		//error = e;

		return false;
	}
}

std::string LIB::network::mpi::receive (void)
{
	return receive (tcp.port);
}

std::string LIB::network::mpi::receive (const unsigned short int & port, const unsigned short int & version)
//std::string LIB::Network::mpi::Receive ()
{
	try
	{
		std::cout << "Messaging.cpp:\'receive()\' : Waiting to Receive..." << std::endl;
		//boost::asio::ip:tcp::iostream ios ();
		//unsigned short int port = tcp.Port ();
		boost::asio::io_service io;
		std::string message;
		//boost::asio::ip::tcp::acceptor * acceptor;
		boost::asio::ip::tcp::endpoint * endpoint;
		boost::asio::ip::tcp::acceptor * acceptor;
		boost::asio::ip::tcp::socket * socket;
		
		char * data;
		
		switch (version)
		{
			case 6:
				endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port);
				//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port));
			default:
				endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);
				//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		}
		
		//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::v4 ());
		//boost::asio::ip::tcp::acceptor acceptor = boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		/*receive_*/acceptor = new boost::asio::ip::tcp::acceptor (io, * endpoint);
		//acceptor -> open (endpoint -> protocol ());
		/*receive_*/acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
		
		//boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp:: (, port));
		//boost::asio::ip::tcp::acceptor acceptor (io);
		//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp (boost::asio::ip::tcp::family ()), port);

		//acceptor.open (endpoint.protocol ());
		//acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address(true));
		//boost::asio::ip::tcp::socket socket (io);
		// cancel_tcp ();
		
		socket/*_tcp_receive*/ = new boost::asio::ip::tcp::socket (io);
		
		std::cout << "\tPreparing to Receive..." << std::endl;
		/*receive_*/acceptor -> accept (* socket/*_tcp_receive*/);
		
		//boost::array<char, MESSAGE_SIZE> buf;
		// char * buffer = new char [message_size];
		unsigned long long int available_chars;
		//boost::posix_time::time_duration attempt = boost::posix_time::microseconds (1000);
		time_t time_end_allowed = time (NULL), time_end_actual;
		//time_start = time (NULL);
		//std::cout << time_start << std::endl;
		double diff;
		
		do
		{
			available_chars = socket/*_tcp_receive*/ -> available ();	// This time may not work, returning 0.
			//available = socket_tcp_receive -> available ();
			//std::cout << time (NULL) << std::endl;
			time_end_actual = time (NULL);
			diff = std::difftime (time_end_actual, time_end_allowed);
		}
		while (available_chars <= 0 && diff <= 0.01);
		
		//data = new char [message_size];
		data = new char [available_chars];
		
		
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
		/*size_t len = */boost::asio::read (* socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
		//boost::asio::read (* socket_tcp_receive, & message [0]);
		//socket_tcp_receive -> read_some (message);
		//socket_tcp_receive -> read_some (& message [0]);
		//socket_tcp_receive -> read_some (boost::asio::buffer (& message [0], 3));
		//size_t len = socket_tcp_receive -> receive (boost::asio::buffer (data, message_size)/*, ignored_error*/);
		//socket_tcp_receive -> read_some (boost::asio::buffer (data, available_chars)/*, ignored_error*/);
		
		
		acceptor -> close ();
		std::cout << "Messaging.cpp: Deleting \'receive_acceptor\'..." << std::endl;
		delete acceptor;
		std::cout << "Messaging.cpp: Deleted \'receive_acceptor\'..." << std::endl;
		acceptor = NULL;
		
		delete endpoint;
		
		delete socket;
		socket = NULL;
		
		//message = buf.data ();
		message = data;
		delete [] data;
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

bool LIB::network::mpi::receive_async_stop (void (* handler) (std::string), const bool & cycle, const unsigned short int & version)
{
	return receive_async_stop (handler, tcp.port, version, cycle);
}

bool LIB::network::mpi::receive_async_stop (void (* handler) (std::string), const unsigned short int & port, const unsigned short int & version, const bool & cycle)
{
	//protocol p = protocol::tcp;
	unsigned long int hash = 0;
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	boost::hash_combine <const unsigned short int &> (hash, version);
	boost::hash_combine <const unsigned short int &> (hash, port);
	boost::hash_combine <protocol> (hash, protocol::tcp);
	boost::hash_combine <const bool &> (hash, cycle);
	
	
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
	handlers [hash].reset ();
	handlers [hash].previous ();
	handlers [hash].current_value ().stop ();
	handlers [hash].unset (handlers [hash].current_key ());
	
	if (handlers [hash].size () <= 0)
	{
		handlers.unset (hash);
	}
	
	handlers.unset (hash);
	
	return true;
}

void LIB::network::mpi::receive_async (void (* handler) (std::string), const bool & cycle)
{
	receive_async (handler, tcp.port, DEFAULT_IP_ADDRESS_VERSION, cycle);
}

void LIB::network::mpi::receive_async (void (* handler) (std::string), const unsigned short int & port, unsigned short int version, const bool & cycle)
{
	//using boost::asio::ip::tcp;
	boost::asio::io_service io_service;
	//boost::asio::io_service * io_service;
	//boost::shared_ptr <boost::asio::io_service> io_service (new boost::asio::io_service ());
	//boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);
	//boost::shared_ptr <boost::asio::ip::tcp::endpoint> endpoint;
	//boost::shared_ptr <boost::asio::ip::tcp::endpoint> endpoint (new boost::asio::ip::tcp::endpoint ());
	boost::asio::ip::tcp::endpoint * endpoint;
	//protocol p = protocol::tcp;
	
	switch (version)
	{
		case 6:
			endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port);
			//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port));
		default:
			endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);
			version = 4;	// Make sure that the value is 4, needed for hashing, below.
			//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
	}
	
	//boost::shared_ptr <boost::asio::ip::tcp::acceptor> acceptor (new boost::asio::ip::tcp::acceptor (* io_service, * endpoint));
	boost::asio::ip::tcp::acceptor acceptor (io_service, * endpoint);
	
	//boost::shared_ptr <boost::asio::ip::tcp::socket> socket (new boost::asio::ip::tcp::socket (acceptor -> get_io_service ()));
	boost::asio::ip::tcp::socket socket (io_service);
	
	//acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
	acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
	
	// Add a job to start accepting connections.
	receive_accept (socket, acceptor/*, endpoint*/, handler, cycle/*, port, version*/);
	
	unsigned long int hash = 0;
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	boost::hash_combine <const unsigned short int &> (hash, version);
	boost::hash_combine <const unsigned short int &> (hash, port);
	boost::hash_combine <protocol> (hash, protocol::tcp);
	boost::hash_combine <const bool &> (hash, cycle);
	
	//receivers [hash] = io_service;
	handlers [hash].append (io_service);
	
	// Process event loop.
	// This is a blocking call.
	io_service.run ();
	
	delete endpoint;
	//std::cout << "Server thread exiting." << std::endl;
}

void LIB::network::mpi::receive_accept (/*, boost::shared_ptr <boost::asio::ip::tcp::endpoint> endpoint*//*boost::shared_ptr <boost::asio::ip::tcp::socket> */boost::asio::ip::tcp::socket socket,/* boost::shared_ptr <boost::asio::ip::tcp::acceptor> */boost::asio::ip::tcp::acceptor acceptor, void (* handler) (std::string), const bool & cycle/*, const unsigned short int & port, const unsigned short int & version*/)
{
	//using boost::asio::ip::tcp;
	// boost::shared_ptr <boost::asio::ip::tcp::socket> socket (new boost::asio::ip::tcp::socket (acceptor.get_io_service ()));
	
	// Add an accept call to the service.  This will prevent io_service::run()
	// from returning.
	//std::cout << "Waiting on connection" << std::endl;
	//acceptor -> async_accept
	acceptor.async_accept
	(
		/** */socket,
		boost::bind
		(
			& LIB::network::mpi::receive_accept_handler,
			this,
			boost::asio::placeholders::error,
			socket,
			boost::ref (acceptor),
			//acceptor,
			handler,
			cycle/*,
			port,
			version*/
		)
	)
	;
}

void LIB::network::mpi::receive_accept_handler (const boost::system::error_code & error, /*boost::shared_ptr <boost::asio::ip::tcp::socket>*/boost::asio::ip::tcp::socket socket, /*boost::shared_ptr <boost::asio::ip::tcp::acceptor>*/boost::asio::ip::tcp::acceptor acceptor, void (* handler) (std::string), const bool & cycle/*, const unsigned short int & port, const unsigned short int & version*/)
{
	if (cycle)
	{
		// Prepare another instance to accept incoming connections.
		receive_accept (socket, acceptor, handler, cycle/*, port, version*/);
	}
	
	// If there was an error, then do not add any more jobs to the service.
//	if (error)
//	{
//		//std::cout << "Error accepting connection: " << error.message() << std::endl;
//		return;
//	}
	
	// Otherwise, the socket is good to use.
	//std::cout << "Doing things with socket..." << std::endl;
	
	// Perform async operations on the socket.
	try
	{
		std::cout << "Messaging.cpp:\'receive()\' : Waiting to Receive..." << std::endl;
		//boost::asio::ip:tcp::iostream ios ();
		//unsigned short int port = tcp.Port ();
		//boost::asio::io_service io;
		std::string message;
		//boost::asio::ip::tcp::acceptor * acceptor;
		//boost::asio::ip::tcp::endpoint * endpoint;
		char * data;
		/*
		switch (version)
		{
			case 6:
				endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port);
				//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port));
			default:
				endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);
				//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		}
		*/
		//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::v4 ());
		//boost::asio::ip::tcp::acceptor acceptor = boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		//receive_acceptor = new boost::asio::ip::tcp::acceptor (io, * endpoint);
		//acceptor -> open (endpoint -> protocol ());
		// acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
		
		//boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp:: (, port));
		//boost::asio::ip::tcp::acceptor acceptor (io);
		//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp (boost::asio::ip::tcp::family ()), port);

		//acceptor.open (endpoint.protocol ());
		//acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address(true));
		//boost::asio::ip::tcp::socket socket (io);
		// cancel_tcp ();
		
		// socket_tcp_receive = new boost::asio::ip::tcp::socket (io);
		
		std::cout << "\tPreparing to Receive..." << std::endl;
		acceptor.accept (socket);
		
		//boost::array<char, MESSAGE_SIZE> buf;
		// char * buffer = new char [message_size];
		unsigned long long int available_chars;
		//boost::posix_time::time_duration attempt = boost::posix_time::microseconds (1000);
		time_t time_end_allowed = time (NULL), time_end_actual;
		//time_start = time (NULL);
		//std::cout << time_start << std::endl;
		double diff;
		
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
		data = new char [available_chars];
		
		
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
		/*size_t len = */boost::asio::read (socket, boost::asio::buffer (data, available_chars));
		//boost::asio::read (* socket_tcp_receive, & message [0]);
		//socket_tcp_receive -> read_some (message);
		//socket_tcp_receive -> read_some (& message [0]);
		//socket_tcp_receive -> read_some (boost::asio::buffer (& message [0], 3));
		//size_t len = socket_tcp_receive -> receive (boost::asio::buffer (data, message_size)/*, ignored_error*/);
		//socket_tcp_receive -> read_some (boost::asio::buffer (data, available_chars)/*, ignored_error*/);
		
		
		//receive_acceptor -> close ();
		//std::cout << "Messaging.cpp: Deleting \'receive_acceptor\'..." << std::endl;
		//delete receive_acceptor;
		//std::cout << "Messaging.cpp: Deleted \'receive_acceptor\'..." << std::endl;
		//receive_acceptor = NULL;
		
		//delete socket_tcp_receive;
		//socket_tcp_receive = NULL;
		
		//message = buf.data ();
		message = data;
		delete [] data;
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
		
		
		std::cout << "Messaging.cpp: Received Message full=[" << message << "] substr=[" << message.substr (0, available_chars) << "]" << std::endl;
		
		// return message.substr (0, len);
		//return message.substr (0, 3);
		//std::cout << "Available characters: " << available_chars << std::endl;
		//std::cout << "Read characters: " << len << std::endl;
		//return message.substr (0, available_chars);
		(* handler) (message.substr (0, available_chars));
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
		//return "";
	}
	catch (...) //(...) //(std::exception & e)
	{
		//acceptor -> close ();
		std::cout << "Messaging.cpp (...): \'Receive\': Error." << std::endl;
		//error = e;

		//return e.what();
		//return "";
	}
	
	// Done using the socket, so start accepting another connection.  This
	// will add a job to the service, preventing io_service::run() from
	// returning.
	//std::cout << "Done using socket, ready for another connection." << std::endl;
}

// UDP:

void LIB::network::mpi::listen_async (void (* handler) (std::string), const bool & cycle)
{
	listen_async ((* handler), udp.address, udp.port, cycle);
}

void LIB::network::mpi::listen_async (void (* handler) (std::string), const std::string & broadcast_address, const unsigned short int & port, const bool & cycle)
{
	//protocol p = protocol::udp;
	//unsigned short int version = 4;
	unsigned long long int handler_index;
	boost::asio::io_service io_service;
	//boost::shared_ptr <boost::asio::ip::udp::socket> socket (new boost::asio::ip::udp::socket (io_udp));
	//boost::asio::ip::udp::socket * socket = new boost::asio::ip::udp::socket (io_udp);
	boost::asio::ip::udp::socket socket (io_service);
	//boost::shared_ptr <boost::asio::ip::udp::endpoint> endpoint (new boost::asio::ip::udp::endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port));
	
	//boost::asio::ip::udp::endpoint * endpoint = new boost::asio::ip::udp::endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
	boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
	//boost::asio::udp::acceptor acceptor (io, * endpoint);
	
	/*
	socket -> open (endpoint -> protocol ());
	socket -> set_option (boost::asio::ip::udp::socket::reuse_address (true));
	socket -> bind (* endpoint);
	*/
	socket.open (endpoint.protocol ());
	socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
	socket.bind (endpoint);
	
	// Join the multicast group.
	socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (broadcast_address)));
	
	//boost::shared_ptr <boost::asio::ip::tcp::acceptor> acceptor (new boost::asio::ip::tcp::acceptor (io_udp, /*c_library_function(& * endpoint)*/ * (endpoint -> get ())));
	//boost::asio::ip::tcp::acceptor acceptor (io_service, /*c_library_function(& * endpoint)*/ * (endpoint));
	boost::asio::ip::tcp::acceptor acceptor (io_service, endpoint);
	
	//boost::shared_ptr <boost::asio::ip::tcp::socket> socket (new boost::asio::ip::tcp::socket (acceptor -> get_io_service ()));
	
	//acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
	acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
	
	// Add a job to start accepting connections.
	//listen_accept (socket, endpoint, handler, cycle);
	//listener = new boost::thread (boost::bind (& LIB::cluster::memory::listen_accept, this));
	//boost::hash <mathematics::numbers::natural> hash;
	
	unsigned long int hash = 0;
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	//boost::hash_combine <unsigned short int> (hash, version);
	boost::hash_combine <const std::string &> (hash, broadcast_address);
	boost::hash_combine <const unsigned short int &> (hash, port);
	boost::hash_combine <protocol> (hash, protocol::udp);
	boost::hash_combine <const bool &> (hash, cycle);
	
	// Hash now contains the hashed value.
	//for (mathematics::numbers::natural i = 0, n = broadcast_address.size (), address = 0; i < n; ++ i)
	//	address +=
	//hash = handler + (cycle ? 1 : 0) + address + port;
	//boost::thread * thread;
	
	/*
	listeners [hash] [0] = cycle ? 1 : 0;
	listeners [hash] [1] = socket;
	//thread = new boost::thread (boost::bind (listen_accept, socket, endpoint, handler, cycle));
	listeners [hash] [2] = new boost::thread (boost::bind (& LIB::network::mpi::listen_accept, this, socket, endpoint, handler, broadcast_address, port));
	*/
	
	handlers [hash].append (io_service, handler_index);
	
	std::cout << "Pre-'listen_accept_handler ()'" << std::endl;
	//listen_accept_handler (socket, endpoint, handler, version, broadcast_address, port, cycle);
	// Perform async operations on the socket.
	try
	{
		std::cout << "Messaging.cpp: Listening..." << std::endl;
		std::string message;
		
		//boost::asio::io_service io;
		//boost::asio::ip::udp::socket socket (io);
		//cancel_udp ();
		
		//socket_udp_receive = new boost::asio::ip::udp::socket (io);
		//boost::asio::ip::udp::endpoint sender_endpoint;ad
		
		//boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
		
		//socket_udp_receive -> open (listen_endpoint.protocol ());
		//socket_udp_receive -> set_option (boost::asio::ip::udp::socket::reuse_address (true));
		//socket_udp_receive -> bind (listen_endpoint);
		
		// Join the multicast group.
		//socket_udp_receive -> set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
		
		//
		//socket_udp_receive -> connect (,);
		//unsigned long long int available = 5;
			///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
		
		//char * data = new char [available];
		//char data [MESSAGE_SIZE];
		char * data = new char [message_size];
		
		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		mathematics::numbers::natural len = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
		//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
		// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
		//socket_udp_receive ->
		//delete endpoint;
		//protocol p = protocol::udp;
		
		/*
		unsigned long int hash = 0;
		boost::hash_combine <void (*) (std::string)> (hash, handler);
		boost::hash_combine <const unsigned short int &> (hash, version);
		boost::hash_combine <const std::string &> (hash, broadcast_address);
		boost::hash_combine <const unsigned short int &> (hash, port);
		boost::hash_combine <protocol> (hash, protocol::udp);
		boost::hash_combine <const bool &> (hash, cycle);
		*/
		
//		if (listeners [hash] [0] != 0)
//		{
//			// Prepare another instance to accept incoming connections.
//			//listen_accept (socket, /*acceptor, */endpoint, handler, cycle/*, port, version*/);
//			endpoint = new boost::asio::ip::udp::endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
//			
//			listeners [hash] [2] = new boost::thread (boost::bind (& LIB::network::mpi::listen_accept, this, socket, endpoint, handler, broadcast_address, port));;
//		}
		
		handlers [hash].unset (handler_index);
		
		if (!cycle && handlers [hash].size () <= 0)
		{
			handlers.unset (hash);
		}
		
		if (cycle)
		{
			// Prepare another instance to accept incoming connections.
			//listen_async_handler (socket, /*acceptor, */endpoint, handler, version, broadcast_address, port, cycle/*, port, version*/);
			listen_async (handler, broadcast_address, port, cycle);
		}
		
		message = data;
		delete [] data;
		
		//delete socket_udp_receive;
		//socket_udp_receive = NULL;
		
		std::cout << "Messaging.cpp: Listened: [" << message.substr (0, len) << "]" << std::endl;
		
		(* handler) (message.substr (0, len));
		//return message.substr (0, len);
		//return message.substr (0, available);
	}
	catch (...) //(std::exception & e)
	{
		//error = e;
		//std::cout << "Error: Listening." << std::endl;
		std::cout << "Messaging.cpp (...): \'Listen\': Error." << std::endl;
		//return e.what();
		return "";
	}
	std::cout << "Post-'listen_accept_handler ()'" << std::endl;
	std::cout << std::endl;
	// Process event loop.
	// This is a blocking call.
	//io_udp.run ();
	std::cout << "Pre-'io_service.run ()'" << std::endl;
	//io_service.run ();
	std::cout << "Post-'io_service.run ()'" << std::endl;
	
	//delete endpoint;
	//std::cout << "Server thread exiting." << std::endl;
	std::cout << "Listening thread " << hash << " exiting." << std::endl;
}

//void LIB::network::mpi::listen_accept (boost::shared_ptr <*/boost::asio::ip::udp::socket> socket/*, boost::shared_ptr <boost::asio::ip::udp::acceptor> acceptor*/, boost::asio::ip::udp::endpoint * endpoint, void (* handler) (std::string)/*, const bool & cycle*/, const std::string & broadcast_address, const unsigned short int & port/*, const unsigned short int & version*/)
//{
//	//using boost::asio::ip::tcp;
//	//boost::shared_ptr <boost::asio::ip::tcp::socket> socket (new boost::asio::ip::tcp::socket (io));
//	
//	// Add an accept call to the service.  This will prevent io_service::run()
//	// from returning.
//	//std::cout << "Waiting on connection" << std::endl;
///*
//	acceptor -> async_accept
//	(
//		* socket,
//		boost::bind
//		(
//			listen_accept_handler,
//			socket,
//			//acceptor,
//			endpoint,
//			//boost::ref (acceptor),
//			boost::asio::placeholders::error
//			handler,
//			cycle
//		)
//	);
//*/
//	listen_accept_handler (socket, endpoint, /*boost::asio::placeholders::error, */handler/*, cycle*/, broadcast_address, port);
//}

//void LIB::network::mpi::listen_accept_handler (/*boost::shared_ptr <*/boost::asio::ip::udp::socket/*>*/ socket/*, boost::shared_ptr <boost::asio::ip::tcp::acceptor> acceptor*/, boost::asio::ip::udp::endpoint endpoint/*, const boost::system::error_code & error*/, void (* handler) (std::string), const unsigned short int & version, const std::string & broadcast_address, const unsigned short int & port, const bool & cycle)
//{
////	if (cycle)
////	{
////		// Prepare another instance to accept incoming connections.
////		listen_accept_handler (socket, /*acceptor, */endpoint, handler, version, broadcast_address, port, cycle/*, port, version*/);
////	}
//	
//	// If there was an error, then do not add any more jobs to the service.
////	if (error)
////	{
////		//std::cout << "Error accepting connection: " << error.message() << std::endl;
////		return;
////	}
//	
//	// Otherwise, the socket is good to use.
//	//std::cout << "Doing things with socket..." << std::endl;
//	
//	// Perform async operations on the socket.
//	try
//	{
//		std::cout << "Messaging.cpp: Listening..." << std::endl;
//		std::string message;
//		
//		//boost::asio::io_service io;
//		//boost::asio::ip::udp::socket socket (io);
//		//cancel_udp ();
//		
//		//socket_udp_receive = new boost::asio::ip::udp::socket (io);
//		//boost::asio::ip::udp::endpoint sender_endpoint;ad
//		
//		//boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
//		
//		//socket_udp_receive -> open (listen_endpoint.protocol ());
//		//socket_udp_receive -> set_option (boost::asio::ip::udp::socket::reuse_address (true));
//		//socket_udp_receive -> bind (listen_endpoint);
//		
//		// Join the multicast group.
//		//socket_udp_receive -> set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
//		
//		//
//		//socket_udp_receive -> connect (,);
//		//unsigned long long int available = 5;
//			///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
//		
//		//char * data = new char [available];
//		//char data [MESSAGE_SIZE];
//		char * data = new char [message_size];
//		
//		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//		//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//		mathematics::numbers::natural len = socket.receive_from (boost::asio::buffer (data, message_size), * endpoint);
//		//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
//		// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
//		//socket_udp_receive ->
//		delete endpoint;
//		//protocol p = protocol::udp;
//		
//		/*
//		unsigned long int hash = 0;
//		boost::hash_combine <void (*) (std::string)> (hash, handler);
//		boost::hash_combine <const unsigned short int &> (hash, version);
//		boost::hash_combine <const std::string &> (hash, broadcast_address);
//		boost::hash_combine <const unsigned short int &> (hash, port);
//		boost::hash_combine <protocol> (hash, protocol::udp);
//		boost::hash_combine <const bool &> (hash, cycle);
//		*/
//		
////		if (listeners [hash] [0] != 0)
////		{
////			// Prepare another instance to accept incoming connections.
////			//listen_accept (socket, /*acceptor, */endpoint, handler, cycle/*, port, version*/);
////			endpoint = new boost::asio::ip::udp::endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
////			
////			listeners [hash] [2] = new boost::thread (boost::bind (& LIB::network::mpi::listen_accept, this, socket, endpoint, handler, broadcast_address, port));;
////		}
//		
//		if (cycle)
//		{
//			// Prepare another instance to accept incoming connections.
//			listen_accept_handler (socket, /*acceptor, */endpoint, handler, version, broadcast_address, port, cycle/*, port, version*/);
//		}
//		
//		message = data;
//		delete [] data;
//		
//		//delete socket_udp_receive;
//		//socket_udp_receive = NULL;
//		
//		std::cout << "Messaging.cpp: Listened: [" << message.substr (0, len) << "]" << std::endl;
//		
//		(* handler) (message.substr (0, len));
//		//return message.substr (0, len);
//		//return message.substr (0, available);
//	}
//	catch (...) //(std::exception & e)
//	{
//		//error = e;
//		//std::cout << "Error: Listening." << std::endl;
//		std::cout << "Messaging.cpp (...): \'Listen\': Error." << std::endl;
//		//return e.what();
//		return "";
//	}
//	
//	// Done using the socket, so start accepting another connection.  This
//	// will add a job to the service, preventing io_service::run() from
//	// returning.
//	//std::cout << "Done using socket, ready for another connection." << std::endl;
//}

bool LIB::network::mpi::listen_async_stop (void (* handler) (std::string), const bool & cycle)
{
	listen_async_stop (handler, udp.address, udp.port, cycle);
}

bool LIB::network::mpi::listen_async_stop (void (* handler) (std::string), const std::string & broadcast_address, const unsigned short int & port, const bool & cycle)
{
	//unsigned long int version = 4;
	unsigned long int hash = 0;
	
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	//boost::hash_combine <unsigned short int> (hash, version);
	boost::hash_combine <const std::string &> (hash, broadcast_address);
	boost::hash_combine <const unsigned short int &> (hash, port);
	boost::hash_combine <protocol> (hash, protocol::udp);
	boost::hash_combine <const bool &> (hash, cycle);
	
	handlers [hash].reset ();
	handlers [hash].previous ();
	handlers [hash].current_value ().stop ();
	handlers [hash].unset (handlers [hash].current_key ());
	
	//handlers [hash] [handlers [hash].size () - 1].stop ();
	//handlers [hash].unset (handlers [hash].size () - 1);
	
	if (handlers [hash].size () <= 0)
	{
		handlers.unset (hash);
	}
	
//	if (listeners.exists (hash))
//	{
//		boost::thread * thread;
//		boost::asio::ip::udp::socket * socket;
//		
//		listeners.current_value () [0] = 0;
//		socket = listeners.current_value () [1];
//		thread = listeners.current_value () [2];
//		
//		if (socket != NULL)
//		{
//			socket-> close ();
//			
//			try
//			{
//				delete socket;
//			}
//			catch (...)
//			{
//			}
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
//		//listeners [hash] [0] = 0;
//		//listeners [hash] [1].;
//		
//		listeners.unset (hash);
//		
//		return true;
//	}
//	else
//		return true;
}

//std::string LIB::Network::mpi::Listen ()
std::string LIB::network::mpi::listen (void)
{
	return listen (udp.address, udp.port);
}

std::string LIB::network::mpi::listen (const std::string address)
{
	return listen (address, udp.port);
}

std::string LIB::network::mpi::listen (const unsigned short int port)
{
	return listen (udp.address, port);
}

std::string LIB::network::mpi::listen (const std::string address, const unsigned short int port)
{
	try
	{
		std::cout << "Messaging.cpp: Listening..." << std::endl;
		std::string message;

		boost::asio::io_service io;
		// boost::asio::ip::udp::socket socket;
		//boost::asio::ip::udp::socket socket (io);
		// cancel_udp ();

		// socket_udp_receive = new boost::asio::ip::udp::socket (io);
		boost::asio::ip::udp::socket socket (io);
		//boost::asio::ip::udp::endpoint sender_endpoint;ad
		
		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
		
		socket.open (endpoint.protocol ());
		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
		socket.bind (endpoint);
		
		// Join the multicast group.
		socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
		
		//
		//socket_udp_receive -> connect (,);
		//unsigned long long int available = 5;
			///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
		
		//char * data = new char [available];
		//char data [MESSAGE_SIZE];
		char * data = new char [message_size];
		
		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		mathematics::numbers::natural len = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
		//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
		// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
		//socket_udp_receive ->
		message = data;
		delete [] data;

		//delete socket;
		//socket = NULL;

		std::cout << "Messaging.cpp: Listened: [" << message.substr (0, len) << "]" << std::endl;
		
		return message.substr (0, len);
		//return message.substr (0, available);
	}
	catch (std::exception & e)
	{
		//error = e;
		//std::cout << "Error: Listening." << std::endl;
		std::cout << "Messaging.cpp (...): \'Listen\': Error:" << e.what () << std::endl;
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
