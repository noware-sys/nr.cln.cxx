#include "_mpi.h++"

noware::net::_mpi::_mpi (void)
{
	reliable = default_reliable;
}

noware::net::_mpi::_mpi (const noware::net::_mpi & other)
{
	*this = other;
}

noware::net::_mpi::~_mpi (void)
{
}

template <typename archive>
void noware::net::_mpi::serialize (archive & arch, const unsigned int & version)
{
	arch & reliable;
	arch & transmission;
	arch & reception;
	arch & multicast;
}

const std::string noware::net::_mpi::serialize (void) const
{
	return LIB::serialize <noware::net::_mpi> (* this);
}

////template <typename value, typename key>
//const std::string noware::net::_mpi::serialize (void) const
//{
//	return LIB::serialize <noware::net::_mpi> (* this);
//}

//template <typename value, typename key>
const bool noware::net::_mpi::deserialize (const std::string & serial)
{
	return LIB::deserialize <noware::net::_mpi> (serial, * this);
}

//template <typename value, typename key>
const noware::net::_mpi & noware::net::_mpi::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
noware::net::_mpi::operator const std::string (void) const
{
	return serialize ();
}

const bool noware::net::_mpi::operator == (const noware::net::_mpi & other) const
{
	return
		reliable == other.reliable
		&&
		transmission == other.transmission
		&&
		multicast == other.multicast
		&&
		reception == other.reception
	;
}

const noware::net::_mpi & noware::net::_mpi::operator = (const noware::net::_mpi & other)
{
	reliable = other.reliable;
	transmission = other.transmission;
	multicast = other.multicast;
	reception = other.reception;
	
	return * this;
}


// Connection: Addresses:

template <typename archive>
void noware::net::_mpi::address::serialize (archive & arch, const unsigned int & version)
{
	arch & reliable;
	arch & unreliable;
}

const std::string noware::net::_mpi::address::serialize (void) const
{
	return LIB::serialize <noware::net::_mpi::address> (* this);
}

////template <typename value, typename key>
//const std::string noware::net::_mpi::address::serialize (void) const
//{
//	return LIB::serialize <noware::net::_mpi::address> (* this);
//}

//template <typename value, typename key>
const bool noware::net::_mpi::address::deserialize (const std::string & serial)
{
	return LIB::deserialize <noware::net::_mpi::address> (serial, * this);
}

//template <typename value, typename key>
const noware::net::_mpi::address & noware::net::_mpi::address::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
noware::net::_mpi::address::operator const std::string (void) const
{
	return serialize ();
}

const bool noware::net::_mpi::address::operator == (const noware::net::_mpi::address & other) const
{
	return reliable == other.reliable && unreliable == other.unreliable;
}

const noware::net::_mpi::address & noware::net::_mpi::address::operator = (const noware::net::_mpi::address & other)
{
	reliable = other.reliable;
	unreliable = other.unreliable;
	
	return * this;
}

// Transmit

const bool noware::net::_mpi::transmit (const std::string & message)
{
	return transmit (message, reliable ? transmission.reliable : transmission.unreliable, reliable);
}

const bool noware::net::_mpi::transmit (const std::string & message, const bool & _reliable)
{
	return transmit (message, _reliable ? transmission.reliable : transmission.unreliable, _reliable);
}

const bool noware::net::_mpi::transmit (const std::string & message, const LIB::container::NTT <> & address)
{
	return transmit (message, address, reliable);
}

const bool noware::net::_mpi::transmit (const std::string & message, LIB::container::NTT <> address, const bool & _reliable)
{
	return false;
}

/*
const bool noware::net::_mpi::transmit (const std::string & message, const std::string & address)
{
	return transmit (message, address, tcp_transmit.port);
}

const bool noware::net::_mpi::transmit (const std::string & message, const unsigned short int & port)
{
	return transmit (message, tcp_transmit.address, port);
}

const bool noware::net::_mpi::transmit (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return transmit (message, address, port);
}
*/


// Broadcast

const bool noware::net::_mpi::broadcast (const std::string & message)
{
	return broadcast (message, reliable ? multicast.reliable : multicast.unreliable, reliable);
}

const bool noware::net::_mpi::broadcast (const std::string & message, const bool & _reliable)
{
	return broadcast (message, _reliable ? multicast.reliable : multicast.unreliable, _reliable);
}

const bool noware::net::_mpi::broadcast (const std::string & message, const LIB::container::NTT <> & addresses)
{
	return broadcast (message, addresses, reliable);
}

const bool noware::net::_mpi::broadcast (const std::string & message, LIB::container::NTT <> addresses, const bool & _reliable)
{
	return false;
}

/*
const bool noware::net::_mpi::broadcast (const std::string & message)
{
	return broadcast (message, udp_broadcast.address, udp_broadcast.port);
}

const bool noware::net::_mpi::broadcast (const std::string & message, const std::string & address)
{
	return broadcast (message, address, udp_broadcast.port);
}

const bool noware::net::_mpi::broadcast (const std::string & message, const unsigned short int & port)
{
	return broadcast (message, udp_broadcast.address, port);
}

const bool noware::net::_mpi::broadcast (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return broadcast (message, address, port);
}
*/


// Receive

/*
std::string noware::net::_mpi::receive (void)
{
	return receive (addrs.receive);
}
*/
const std::string noware::net::_mpi::receive (void)
{
	LIB::container::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, reliable ? reception.reliable : reception.unreliable, reliable);
}

const std::string noware::net::_mpi::receive (const bool & _reliable)
{
	LIB::container::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, _reliable ? reception.reliable : reception.unreliable, _reliable);
}

const std::string noware::net::_mpi::receive (LIB::container::NTT <> address, const bool & _reliable)
{
	LIB::container::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, address, _reliable);
}

const std::string noware::net::_mpi::receive (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address, const bool & _reliable)
{
	return "";
}


// Listen

/*
std::string noware::net::_mpi::listen (void)
{
	return listen (udp_listen.address, udp_listen.port);
}

std::string noware::net::_mpi::listen (const std::string & address)
{
	return listen (address, udp_listen.port);
}

std::string noware::net::_mpi::listen (const unsigned short int & port)
{
	return listen (udp_listen.address, port);
}

std::string noware::net::_mpi::listen (const unsigned short int & port, const std::string & address)
{
	return listen (address, port);
}
*/

const noware::container::object <> noware::net::_mpi::prepare (noware::container::object <> message)
{
	return message;
}
