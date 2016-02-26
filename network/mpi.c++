//#ifndef MESSAGING_CPP
//#define MESSAGING_CPP

#include <boost/array.hpp>
#include <boost/bind.hpp>

//#include "tcp.hpp"
//#include "udp.hpp"
#include "./ip.hpp"
#include "./mpi.hpp"

LIB::network::mpi::mpi (void)
{
	//message_size = MESSAGE_SIZE;		// In bytes (characters).
	message_size_listening = message_size_receiving = 20;	//ULLONG_MAX;	// The number of characters.
	//message_size = ULLONG_MAX;
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
	//tcp.address = "127.0.0.1";
	//tcp.port = 1;

	//udp.address = LIB::Network::IP::v4::UDP::ADDRESS;
	//udp.port = LIB::Network::IP::v4::UDP::PORT;
	//udp.address = "239.255.0.1";	// Possible values: 239.255.0.1, 239.255.1.1, 229.255.0.1, 229.1.1.1
	//udp.port = 2;

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

bool LIB::network::mpi::send (const std::string message)
{
	return send (message, connection.tcp.address, connection.tcp.port);
}

bool LIB::network::mpi::send (const std::string message, const std::string address)
{
	return send (message, address, connection.tcp.port);
}

bool LIB::network::mpi::send (const std::string message, const unsigned short int port)
{
	return send (message, connection.tcp.address, port);
}

bool LIB::network::mpi::send (const std::string message, const std::string address, const unsigned short int port)
{
	//return send_internal (message, address, port);
}

bool LIB::network::mpi::broadcast (const std::string message)
{
	return broadcast (message, connection.udp.address, connection.udp.port);
}

bool LIB::network::mpi::broadcast (const std::string message, const std::string address)
{
	return broadcast (message, address, connection.udp.port);
}

bool LIB::network::mpi::broadcast (const std::string message, const unsigned short int port)
{
	return broadcast (message, connection.udp.address, port);
}

bool LIB::network::mpi::broadcast (const std::string message, const std::string address, const unsigned short int port)
{
	//return broadcast_internal (message, address, port);
	return true;
}

std::string LIB::network::mpi::receive (void)
{
	return receive (connection.tcp.port);
}

std::string LIB::network::mpi::receive (const unsigned short int port)
{
	//return receive_internal (port);
	return "";
}

std::string LIB::network::mpi::listen (void)
{
	return listen (connection.udp.address, connection.udp.port);
}

std::string LIB::network::mpi::listen (const std::string address)
{
	return listen (address, connection.udp.port);
}

std::string LIB::network::mpi::listen (const unsigned short int port)
{
	return listen (connection.udp.address, port);
}

std::string LIB::network::mpi::listen (const std::string address, const unsigned short int port)
{
	//return listen_internal (address, port);
}

/*
bool LIB::network::mpi::send_internal (const std::string message, const std::string address, const unsigned short int port)
{

}

std::string LIB::network::mpi::receive_internal (const unsigned short int port)
{
}

bool LIB::network::mpi::broadcast_internal (const std::string message, const std::string address, const unsigned short int port)
{
}

std::string LIB::network::mpi::listen_internal (const std::string address, const unsigned short int port)
{
}
*/