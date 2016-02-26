#include "_mpi.h++"

LIB::network::_mpi::_mpi (void)
{
	reliable = default_reliable;
}

LIB::network::_mpi::_mpi (const LIB::network::_mpi & other)
{
	*this = other;
}

LIB::network::_mpi::~_mpi (void)
{
}

template <typename archive>
void LIB::network::_mpi::serialize (archive & arch, const unsigned int & version)
{
	arch & reliable;
	arch & transmission;
	arch & reception;
	arch & multicast;
}

const std::string LIB::network::_mpi::serialize (void) const
{
	return LIB::serialize <LIB::network::_mpi> (* this);
}

////template <typename value, typename key>
//const std::string LIB::network::_mpi::serialize (void) const
//{
//	return LIB::serialize <LIB::network::_mpi> (* this);
//}

//template <typename value, typename key>
const bool LIB::network::_mpi::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::network::_mpi> (serial, * this);
}

//template <typename value, typename key>
const LIB::network::_mpi & LIB::network::_mpi::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::network::_mpi::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::network::_mpi::operator == (const LIB::network::_mpi & other) const
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

const LIB::network::_mpi & LIB::network::_mpi::operator = (const LIB::network::_mpi & other)
{
	reliable = other.reliable;
	transmission = other.transmission;
	multicast = other.multicast;
	reception = other.reception;
	
	return * this;
}


// Connection: Addresses:

template <typename archive>
void LIB::network::_mpi::address::serialize (archive & arch, const unsigned int & version)
{
	arch & reliable;
	arch & unreliable;
}

const std::string LIB::network::_mpi::address::serialize (void) const
{
	return LIB::serialize <LIB::network::_mpi::address> (* this);
}

////template <typename value, typename key>
//const std::string LIB::network::_mpi::address::serialize (void) const
//{
//	return LIB::serialize <LIB::network::_mpi::address> (* this);
//}

//template <typename value, typename key>
const bool LIB::network::_mpi::address::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::network::_mpi::address> (serial, * this);
}

//template <typename value, typename key>
const LIB::network::_mpi::address & LIB::network::_mpi::address::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::network::_mpi::address::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::network::_mpi::address::operator == (const LIB::network::_mpi::address & other) const
{
	return reliable == other.reliable && unreliable == other.unreliable;
}

const LIB::network::_mpi::address & LIB::network::_mpi::address::operator = (const LIB::network::_mpi::address & other)
{
	reliable = other.reliable;
	unreliable = other.unreliable;
	
	return * this;
}

// Transmit

const bool LIB::network::_mpi::transmit (const std::string & message)
{
	return transmit (message, reliable ? transmission.reliable : transmission.unreliable, reliable);
}

const bool LIB::network::_mpi::transmit (const std::string & message, const bool & _reliable)
{
	return transmit (message, _reliable ? transmission.reliable : transmission.unreliable, _reliable);
}

const bool LIB::network::_mpi::transmit (const std::string & message, const LIB::containers::NTT <> & address)
{
	return transmit (message, address, reliable);
}

const bool LIB::network::_mpi::transmit (const std::string & message, LIB::containers::NTT <> address, const bool & _reliable)
{
	return false;
}

/*
const bool LIB::network::_mpi::transmit (const std::string & message, const std::string & address)
{
	return transmit (message, address, tcp_transmit.port);
}

const bool LIB::network::_mpi::transmit (const std::string & message, const unsigned short int & port)
{
	return transmit (message, tcp_transmit.address, port);
}

const bool LIB::network::_mpi::transmit (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return transmit (message, address, port);
}
*/


// Broadcast

const bool LIB::network::_mpi::broadcast (const std::string & message)
{
	return broadcast (message, reliable ? multicast.reliable : multicast.unreliable, reliable);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, const bool & _reliable)
{
	return broadcast (message, _reliable ? multicast.reliable : multicast.unreliable, _reliable);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, const LIB::containers::NTT <> & addresses)
{
	return broadcast (message, addresses, reliable);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, LIB::containers::NTT <> addresses, const bool & _reliable)
{
	return false;
}

/*
const bool LIB::network::_mpi::broadcast (const std::string & message)
{
	return broadcast (message, udp_broadcast.address, udp_broadcast.port);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, const std::string & address)
{
	return broadcast (message, address, udp_broadcast.port);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, const unsigned short int & port)
{
	return broadcast (message, udp_broadcast.address, port);
}

const bool LIB::network::_mpi::broadcast (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return broadcast (message, address, port);
}
*/


// Receive

/*
std::string LIB::network::_mpi::receive (void)
{
	return receive (addrs.receive);
}
*/
const std::string LIB::network::_mpi::receive (void)
{
	LIB::containers::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, reliable ? reception.reliable : reception.unreliable, reliable);
}

const std::string LIB::network::_mpi::receive (const bool & _reliable)
{
	LIB::containers::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, _reliable ? reception.reliable : reception.unreliable, _reliable);
}

const std::string LIB::network::_mpi::receive (LIB::containers::NTT <> address, const bool & _reliable)
{
	LIB::containers::NTT <> remote_endpoint;
	
	return receive (remote_endpoint, address, _reliable);
}

const std::string LIB::network::_mpi::receive (LIB::containers::NTT <> & remote_endpoint, LIB::containers::NTT <> address, const bool & _reliable)
{
	return "";
}


// Listen

/*
std::string LIB::network::_mpi::listen (void)
{
	return listen (udp_listen.address, udp_listen.port);
}

std::string LIB::network::_mpi::listen (const std::string & address)
{
	return listen (address, udp_listen.port);
}

std::string LIB::network::_mpi::listen (const unsigned short int & port)
{
	return listen (udp_listen.address, port);
}

std::string LIB::network::_mpi::listen (const unsigned short int & port, const std::string & address)
{
	return listen (address, port);
}
*/

const LIB::communication::message prepare (LIB::communication::message message)
{
	return message;
}
