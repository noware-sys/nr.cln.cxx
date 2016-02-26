#include "connection.h++"


LIB::network::connection::~connection (void)
{
}

// Transmit

const bool LIB::network::connection::transmit (const std::string & message)
{
	return transmit (message, addrs.transmit);
}

/*
const bool LIB::network::connection::transmit (const std::string & message, const std::string & address)
{
	return transmit (message, address, tcp_transmit.port);
}

const bool LIB::network::connection::transmit (const std::string & message, const unsigned short int & port)
{
	return transmit (message, tcp_transmit.address, port);
}

const bool LIB::network::connection::transmit (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return transmit (message, address, port);
}
*/


// Broadcast

/*
const bool LIB::network::connection::broadcast (const std::string & message)
{
	return broadcast (message, udp_broadcast.address, udp_broadcast.port);
}

const bool LIB::network::connection::broadcast (const std::string & message, const std::string & address)
{
	return broadcast (message, address, udp_broadcast.port);
}

const bool LIB::network::connection::broadcast (const std::string & message, const unsigned short int & port)
{
	return broadcast (message, udp_broadcast.address, port);
}

const bool LIB::network::connection::broadcast (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return broadcast (message, address, port);
}
*/


// Receive

/*
std::string LIB::network::connection::receive (void)
{
	return receive (addrs.receive);
}
*/
/*
std::string LIB::network::connection::receive (const std::string & address)
{
	return receive (address, tcp_receive.port);
}

std::string LIB::network::connection::receive (const unsigned short int & port)
{
	return receive (tcp_receive.address, port);
}

std::string LIB::network::connection::receive (const unsigned short int & port, const std::string & address)
{
	return receive (address, port);
}
*/


// Listen

/*
std::string LIB::network::connection::listen (void)
{
	return listen (udp_listen.address, udp_listen.port);
}

std::string LIB::network::connection::listen (const std::string & address)
{
	return listen (address, udp_listen.port);
}

std::string LIB::network::connection::listen (const unsigned short int & port)
{
	return listen (udp_listen.address, port);
}

std::string LIB::network::connection::listen (const unsigned short int & port, const std::string & address)
{
	return listen (address, port);
}
*/
