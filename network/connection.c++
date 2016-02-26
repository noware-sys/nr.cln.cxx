#include "connection.h++"


LIB::network::connection::connection (const LIB::network::connection & other)
{
	* this = other;
}

LIB::network::connection::~connection (void)
{
}

template <typename archive>
void LIB::network::connectio::serialize (archive & arch, const unsigned int & version)
{
	arch & addrs;
}

const std::string LIB::network::connection::serialize (void) const
{
	return LIB::serialize <LIB::network::connection> (* this);
}

//template <typename value, typename key>
const std::string LIB::network::connection::serialize (void) const
{
	return LIB::serialize <LIB::network::connection> (* this);
}

//template <typename value, typename key>
const bool LIB::network::connection::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::network::connection> (serial, * this);
}

//template <typename value, typename key>
const LIB::network::connection & LIB::network::connection::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::network::connectio::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::network::connection::operator == (const LIB::network::connection & other) const
{
	return addrs = other.addrs;
}

const LIB::network::connection & LIB::network::connection::operator = (const LIB::network::connection & other) const
{
	addrs = other.addrs;
	
	return * this;
}


// Connection: Addresses:

template <typename archive>
void LIB::network::connection::addresses::serialize (archive & arch, const unsigned int & version)
{
	arch & transmit;
	arch & broadcast;
	arch & receive;
	arch & listen;
}

const std::string LIB::network::connection::addresses::serialize (void) const
{
	return LIB::serialize <LIB::network::connection::addresses> (* this);
}

//template <typename value, typename key>
const std::string LIB::network::connection::addresses::serialize (void) const
{
	return LIB::serialize <LIB::network::connection::addresses> (* this);
}

//template <typename value, typename key>
const bool LIB::network::connection::addresses::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::network::connection::addresses> (serial, * this);
}

//template <typename value, typename key>
const LIB::network::connection::addresses & LIB::network::connection::addresses::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::network::connection::addresses::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::network::connection::addresses::operator == (const LIB::network::connection::addresses & other) const
{
	return transmit == other.transmit && broadcast == other.broadcast && receive == other.receive && listen == other.listen;
}

const LIB::network::connection::addresses & LIB::network::connection::addresses::operator = (const LIB::network::connection::addresses & other) const
{
	transmit = other.transmit;
	broadcast = other.broadcast;
	receive = other.receive;
	listen = other.listen;
	
	return * this;
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
