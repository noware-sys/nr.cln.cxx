//#ifndef MESSAGING_CPP
//#define MESSAGING_CPP

#include <boost/array.hpp>
#include <boost/bind.hpp>

//#include "tcp.hpp"
//#include "udp.hpp"
#include "ip.hpp"
#include "messaging.hpp"

LIB::network::messaging::interface::interface (void)
{
	//message_size = MESSAGE_SIZE;		// In bytes (characters).
	message_size = 128;
	//message_size = 256;

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
	udp.address = "239.255.0.1";	// Possible values: 239.255.0.1, 239.255.1.1, 229.255.0.1, 229.1.1.1
	udp.port = 2;

	socket_udp_receive = NULL;
	socket_tcp_receive = NULL;

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

LIB::network::messaging::interface::~interface (void)
{
	cancel ();
}

void LIB::network::messaging::interface::cancel (void)
{
	cancel_udp ();
	cancel_tcp ();
}

void LIB::network::messaging::interface::cancel_udp (void)
{
	if (socket_udp_receive != NULL)
	{
		//socket_udp_receive -> cancel ();
		socket_udp_receive -> close ();
	}
}

void LIB::network::messaging::interface::cancel_tcp (void)
{
	if (socket_tcp_receive != NULL)
	{
		//socket_tcp_receive -> cancel ();
		socket_tcp_receive -> close ();
	}
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
//bool LIB::Network::Messaging::interface::Send (std::string message)

bool LIB::network::messaging::interface::send (const std::string message)
{
	return send (message, tcp.address, tcp.port);
}

bool LIB::network::messaging::interface::send (const std::string message, const std::string address)
{
	return send (message, address, tcp.port);
}

bool LIB::network::messaging::interface::send (const std::string message, const unsigned short int port)
{
	return send (message, tcp.address, port);
}

bool LIB::network::messaging::interface::send (const std::string message, const std::string address, const unsigned short int port)
{
	try
	{
		mathematics::numbers::natural len;

		// boost::asio::io_service io;
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
		//boost::system::error_code ec;
		//socket.connect(connectionEndpoint, ec);
		///
		
		// boost::asio::connect (socket, endpoint);
		//boost::asio::connect (socket, endpoint);
		socket.connect (endpoint/*, ec*/);
		//std::cout << ec << std::endl;

		len = boost::asio::write (socket, boost::asio::buffer (message));
		
		return !(len < message.length ());
	}
	catch (...) //(std::exception & e)
	{
		//std::cout << e.what () << std::endl;
	    //error = e.what();
		//error = e;

		return false;
	}
}

bool LIB::network::messaging::interface::broadcast (const std::string message)
{
	return broadcast (message, udp.address, udp.port);
}

bool LIB::network::messaging::interface::broadcast (const std::string message, const std::string address)
{
	return broadcast (message, address, udp.port);
}

bool LIB::network::messaging::interface::broadcast (const std::string message, const unsigned short int port)
{
	return broadcast (message, udp.address, port);
}

bool LIB::network::messaging::interface::broadcast (const std::string message, const std::string address, const unsigned short int port)
{
	try
	{
		mathematics::numbers::natural len;

		// boost::asio::io_service io;
		
		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
		boost::asio::ip::udp::socket socket (io, endpoint.protocol ());
		//socket_udp_send = new boost::asio::ip::udp::socket (io, endpoint.protocol ());
		
		len = socket.send_to (boost::asio::buffer (message), endpoint);
		
		//delete socket_udp_send;
		//socket_udp_send = NULL;

		return !(len < message.length());
	}
	catch (...) //(std::exception & e)
	{
		//error = e.what();
		//error = e;

		return false;
	}
}

std::string LIB::network::messaging::interface::receive (void)
{
	return receive (tcp.port);
}

std::string LIB::network::messaging::interface::receive (const unsigned short int port)
//std::string LIB::Network::Messaging::interface::Receive ()
{
	try
	{
		// unsigned short int port = tcp.Port ();
		// boost::asio::io_service io;
		std::string message;

		boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		
		//boost::asio::ip::tcp::socket socket (io);
		cancel_tcp ();

		socket_tcp_receive = new boost::asio::ip::tcp::socket (io);
		acceptor.accept (* socket_tcp_receive);

		//boost::array<char, MESSAGE_SIZE> buf;
		char * buffer = new char [message_size];

		//size_t len = socket.receive (boost::asio::buffer (buf, message_size)); //, ignored_error);
		mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (buffer, message_size)); //, ignored_error);
		//message = buf.data ();
		message = buffer;
		//std::cout << std::endl << buf << std::endl;
		delete [] buffer;

		delete socket_tcp_receive;
		socket_tcp_receive = NULL;

		//for (Mathematics::Number::Natural index = 0; index < message_size; index)


		return message.substr (0, len);
		//return message;

		//std::string buffer;
		//size_t size = socket.receive (boost::asio::buffer (buffer)); //, ignored_error);
		//return buffer;
	}
	catch (...) //(std::exception & e)
	{
		//error = e;

	    //return e.what();
		return "";
	}
}

//std::string LIB::Network::Messaging::interface::Listen ()
std::string LIB::network::messaging::interface::listen (void)
{
	return listen (udp.address, udp.port);
}

std::string LIB::network::messaging::interface::listen (const std::string address)
{
	return listen (address, udp.port);
}

std::string LIB::network::messaging::interface::listen (const unsigned short int port)
{
	return listen (udp.address, port);
}

std::string LIB::network::messaging::interface::listen (const std::string address, const unsigned short int port)
{
	try
	{
		std::string message;

		boost::asio::io_service io;
		//boost::asio::ip::udp::socket socket (io);
		cancel_udp ();

		socket_udp_receive = new boost::asio::ip::udp::socket (io);
		boost::asio::ip::udp::endpoint sender_endpoint;
 
		boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);
		
		socket_udp_receive -> open (listen_endpoint.protocol());
		socket_udp_receive -> set_option (boost::asio::ip::udp::socket::reuse_address (true));
		socket_udp_receive -> bind (listen_endpoint);

		// Join the multicast group.
		socket_udp_receive -> set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
		
		//char data [MESSAGE_SIZE];
		char * data = new char [message_size];

		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
		mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);

		message = data;
		delete [] data;

		delete socket_udp_receive;
		socket_udp_receive = NULL;

		return message.substr (0, len);
	}
	catch (...) //(std::exception & e)
	{
		//error = e;
		//std::cout << "Error: Listening." << std::endl;
	    //return e.what();
		return "";
	}
}
/*
std::exception LIB::Network::Messaging::interface::Error (void)
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
