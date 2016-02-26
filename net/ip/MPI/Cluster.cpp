#include <boost/asio.hpp>
//#include <list>
//#include <boost/any.hpp>
#include <boost/array.hpp>
#include <string>
#include <boost/bind.hpp>
#include "Cluster.h"

#include <windows.h>
//#include <Winsock2.h>
#include <stdio.h>

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdlib.h>

//using namespace std;

Cluster::Network::Connection::Connection (std::string _host, unsigned int _port)
{
	Host (_host);
	Port (_port);
}

std::string Cluster::Network::Connection::Host (void)
{
	//std::cout << std::endl << host << std::endl;
	return host;
}

bool Cluster::Network::Connection::Host (std::string _host)
{
	host = _host;
	return true;
}

unsigned int Cluster::Network::Connection::Port (void)
{
	//std::cout << std::endl << port << std::endl;
	return port;
}

bool Cluster::Network::Connection::Port (unsigned int _port)
{
	port = _port;
	return true;
}


Cluster::Network::Messaging::Interface::Interface (void)
{
	message_size = MESSAGE_SIZE;		// In bytes (characters).
	
	//ports =
	//{
	//	{13, "daytime"},
	//	{21, "ftp"},
	//	{22, "ssh"},
	//	{23, "telnet"},
	//	{25, "smtp"},
	//	{110, "pop3"}
	//};

	ports [13] = "daytime";
	ports [21] = "ftp";
	ports [22] = "ssh";
	ports [23] = "telnet";
	ports [25] = "smtp";
	ports [110] = "pop3";

	tcp.Host (Protocols::TCP::HOST);
	tcp.Port (Protocols::TCP::PORT);

	udp.Host (Protocols::UDP::HOST);
	udp.Port (Protocols::UDP::PORT);

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

}
/*
// Send
	boost::asio::io_service io;
	boost::asio::ip::tcp::socket socket(io);

	boost::asio::ip::tcp::resolver resolver(io);
	boost::asio::ip::tcp::resolver::query query(host, service);

	boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	boost::asio::connect(socket, endpoint_iterator);
	size_t len = boost::asio::write(socket, boost::asio::buffer(message));
	return !(len < message.length());

//	Broadcast:
	boost::asio::io_service io;

	boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(address), port);
	boost::asio::ip::udp::socket socket(io, endpoint.protocol());
  
	size_t len = socket.send_to(boost::asio::buffer(message), endpoint);

	return !(len < message.length());

// Receive:
	boost::asio::ip::tcp::acceptor acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

	boost::asio::ip::tcp::socket socket(io);
	acceptor.accept(socket);


	boost::array<char, MAX_MESSAGE_SIZE> buf; // 2 ^ 20

	size_t len = socket.receive (boost::asio::buffer(buf, MAX_MESSAGE_SIZE)); //, ignored_error);

	std::string message = buf.data();

	return message.substr(0, len);

// Receive broadcast
	boost::asio::io_service io;
	boost::asio::ip::udp::socket socket (io);
	boost::asio::ip::udp::endpoint sender_endpoint;
 
	boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string("0.0.0.0"), port);


	socket.open (listen_endpoint.protocol());
	socket.set_option (boost::asio::ip::udp::socket::reuse_address(true));
	socket.bind (listen_endpoint);

	// Join the multicast group.
	socket.set_option (boost::asio::ip::multicast::join_group(boost::asio::ip::address::from_string(address)));

	char data[MAX_MESSAGE_SIZE];
	size_t len = socket.receive_from (boost::asio::buffer(data, MAX_MESSAGE_SIZE), sender_endpoint);

	std::string message = data;
	return message.substr(0, len);
*/
bool Cluster::Network::Messaging::Interface::Send (std::string message)
//bool Cluster::Network::Messaging::Interface::Send (std::string message, std::string host, std::string service)//unsigned int node)
{
	try
	{
		std::string host = tcp.Host ();
		std::string service = ports.at (tcp.Port ());

		// boost::asio::io_service io;
		boost::asio::ip::tcp::socket socket (io);
		
		boost::asio::ip::tcp::resolver resolver (io);

		//boost::asio::ip::basic_resolver_query ();

		boost::asio::ip::tcp::resolver::query query (host, service);
		
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve (query);
		
		boost::asio::connect (socket, endpoint_iterator);
		
		size_t len = boost::asio::write (socket, boost::asio::buffer (message));
		
		return !(len < message.length ());
	}
	catch (std::exception & e)
	{
	    //error = e.what();
		error = e;

		return false;
	}
}

//bool Cluster::Network::Messaging::Interface::Broadcast (std::string message, std::string address, unsigned int port)
bool Cluster::Network::Messaging::Interface::Broadcast (std::string message)
{
	try
	{
		std::string address = udp.Host ();
		unsigned int port = udp.Port ();

		// boost::asio::io_service io;
		
		boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string (address), port);
		boost::asio::ip::udp::socket socket (io, endpoint.protocol());
  
		size_t len = socket.send_to (boost::asio::buffer (message), endpoint);
		
		return !(len < message.length());
	}
	catch (std::exception & e)
	{
		//error = e.what();
		error = e;

		return false;
	}
}

//std::string Cluster::Network::Messaging::Interface::Receive (unsigned int port)
std::string Cluster::Network::Messaging::Interface::Receive ()
{
	try
	{
		unsigned int port = tcp.Port ();
		// boost::asio::io_service io;
	
		boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
		
		boost::asio::ip::tcp::socket socket (io);
		acceptor.accept (socket);

		boost::array<char, MESSAGE_SIZE> buf;
		
		size_t len = socket.receive (boost::asio::buffer (buf, MESSAGE_SIZE)); //, ignored_error);
		
		std::string message = buf.data ();
		
		return message.substr (0, len);

		//std::string buffer;
		//size_t size = socket.receive (boost::asio::buffer (buffer)); //, ignored_error);
		//return buffer;
	}
	catch (std::exception & e)
	{
		error = e;

	    //return e.what();
		return "";
	}
}

std::string Cluster::Network::Messaging::Interface::Listen ()
//std::string Cluster::Network::Messaging::Interface::Listen (std::string address, unsigned int port)
{
	try
	{
		std::string address = udp.Host ();
		unsigned int port = udp.Port ();
		
		boost::asio::io_service io;
		boost::asio::ip::udp::socket socket (io);
		boost::asio::ip::udp::endpoint sender_endpoint;
 
		boost::asio::ip::udp::endpoint listen_endpoint (boost::asio::ip::address::from_string ("0.0.0.0"), port);


		socket.open (listen_endpoint.protocol());
		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
		socket.bind (listen_endpoint);

		// Join the multicast group.
		socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
		
		char data [MESSAGE_SIZE];

		size_t len = socket.receive_from (boost::asio::buffer (data, MESSAGE_SIZE), sender_endpoint);

		std::string message = data;
		return message.substr (0, len);
	}
	catch (std::exception & e)
	{
		error = e;

	    //return e.what();
		return "";
	}
}

std::string Cluster::Network::Protocols::IP::Value (void)
{
	// Init WinSock
	WSADATA wsa_Data;
	int wsa_ReturnCode = WSAStartup (0x101, &wsa_Data);
	
	// Get the local hostname 
	char szHostName [255];
	gethostname (szHostName, 255);
	struct hostent *host_entry;
	host_entry = gethostbyname (szHostName);
	char * szLocalIP;
	szLocalIP = inet_ntoa (* (struct in_addr *) * host_entry -> h_addr_list);
	WSACleanup ();

	return (std::string) szLocalIP;
}