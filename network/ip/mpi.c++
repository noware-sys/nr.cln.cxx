//#ifndef MESSAGING_CPP
//#define MESSAGING_CPP

#include <iostream>

#include <boost/thread.hpp>
//#include <boost/thread/detail/thread.hpp>
//#include <boost/array.hpp>
#include <boost/bind.hpp>
//#include <ctime>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <time.h>
#include <boost/functional/hash.hpp>

//#include "tcp.h++"
//#include "udp.h++"
#include "../ip.h++"
#include "mpi.h++"

//const bool LIB::network::ip::mpi::DEFAULT_CYCLE;	// Original.
//const static bool LIB::network::ip::mpi::DEFAULT_CYCLE;
const unsigned short int LIB::network::ip::mpi::default_udp_port = 1;
const unsigned short int LIB::network::ip::mpi::default_tcp_port = 1;
//const static unsigned short int LIB::network::ip::mpi::default_udp_port;
//const static unsigned short int LIB::network::ip::mpi::default_tcp_port;
//const static bool LIB::network::ip::mpi::default_reliable;
const bool LIB::network::ip::mpi::default_reliable = true;
const bool LIB::network::ip::mpi::default_receive_self = false;
//const static unsigned short int LIB::network::ip::mpi::default_message_size;
const unsigned short int LIB::network::ip::mpi::default_message_size = 4096;

template <typename archive>
void LIB::network::ip::mpi::serialize (archive & _archive, const unsigned int & version)
{
	//LIB::network::connection::serialize <archive> (arch, version);
	
	_archive & message_size;
}

const bool LIB::network::ip::mpi::operator == (const LIB::network::ip::mpi & other) const
{
	return message_size == other.message_size && static_cast <LIB::network::_mpi> (* this) == static_cast <LIB::network::_mpi> (other);
}

const LIB::network::ip::mpi & LIB::network::ip::mpi::operator = (const LIB::network::ip::mpi & other)
{
	// static_cast <LIB::network::_mpi> (* this) = static_cast <LIB::network::connection> (other);
	
	message_size = other.message_size;
	//reliable = other.reliable;
	
	return * this;
}

LIB::network::ip::mpi::mpi (void)
{
	//LIB::network::endpoint ep;
	
	// Possible values: 229.1.1.1, 229.255.0.1, 239.255.0.1, 239.255.1.1
	
	//message_size = MESSAGE_SIZE;	ULLONG_MAX	// In bytes (characters).
	// 128, 256
	message_size = default_message_size;
	//reliable = default_reliable;
	receive_self = default_receive_self;
	
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
	
	//ep.address = "0.0.0.0";
	
	// set_receive ("0.0.0.0");
	// set_transmit ("0.0.0.0");
	
	// tcp_port (DEFAULT_TCP_PORT);
	// addrs.listen ["address"] = "0.0.0.0";
	// addrs.listen ["port"] = default_udp_port;
	
	// For broadcast transmissions.
	multicast.reliable ["address"] = "0.0.0.0";
	multicast.reliable ["port"] = default_tcp_port;
	multicast.unreliable ["address"] = "0.0.0.0";
	multicast.unreliable ["port"] = default_udp_port;
	
	//udp.address = LIB::Network::IP::v4::UDP::ADDRESS;
	//udp.port = LIB::Network::IP::v4::UDP::PORT;
	//udp.address = "0.0.0.0";
	//udp.port = 2;
	
	
	// set_listen ("0.0.0.0");
	// set_broadcast ("0.0.0.0");
	
	// udp_port (DEFAULT_UDP_PORT);
	reception.reliable ["address"] = "0.0.0.0";
	reception.reliable ["port"] = default_tcp_port;
	reception.unreliable ["address"] = "0.0.0.0";
	reception.unreliable ["port"] = default_udp_port;
	
	transmission.reliable ["address"] = "0.0.0.0";
	transmission.reliable ["port"] = default_tcp_port;
	transmission.unreliable ["address"] = "0.0.0.0";
	transmission.unreliable ["port"] = default_udp_port;
	
	//std::cout << (std::string) udp.address << std::endl;
	
	// multicast_group_listen = "";
	// multicast_group_broadcast = "";
	
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

LIB::network::ip::mpi::~mpi (void)
{
	//io.stop ();
	//// For TCP listening:
	//stop ();
	//// For UDP listening:
	// stop ();
}

/*void LIB::network::ip::mpi::stop (void)
{
	//io.stop ();
}
*/
/*
// Get endpoint.
const LIB::container::NTT <> LIB::network::ip::mpi::get_transmit (void) const
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.transmission);
//	}
//	catch (...)
//	{
//	}
//	
//	return ep;
	
	return addrs.transmission;
}

const LIB::container::NTT <> LIB::network::ip::mpi::get_receive (void) const
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.reception);
//	}
//	catch (...)
//	{
//	}
//	
//	return ep;
	
	return addrs.reception;
}

const LIB::container::NTT <> LIB::network::ip::mpi::get_broadcast (void) const
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.broadcast);
//	}
//	catch (...)
//	{
//	}
//	
//	return ep;
	
	return addrs.broadcast;
}

const LIB::container::NTT <> LIB::network::ip::mpi::get_listen (void) const
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.broadcast);
//	}
//	catch (...)
//	{
//	}
//	
//	return ep;
	
	return addrs.listen;
}

/*
const LIB::NAME_A <LIB::container::NTT <>, LIB::mathematics::numbers::natural> LIB::network::ip::mpi::get_broadcast_multiple (void)
{
	LIB::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural> eps;
	
	try
	{
		eps = boost::any_cast <LIB::NAME_A <LIB::container::NTT <>, LIB::mathematics::numbers::natural>> (addrs.broadcast);
	}
	catch (...)
	{
	}
	
	return eps;
}
* /

// Set whole endpoint.
const bool LIB::network::ip::mpi::set_transmit (LIB::container::NTT <> & ep)
{
	if (ep.exist ("address"))
	{
		addrs.transmission ["address"] = ep ["address"] ();
	}
	
	if (ep.exist ("port"))
	{
		addrs.transmission ["port"] = ep ["port"] ();
	}
	
	return true;
}

const bool LIB::network::ip::mpi::set_receive (LIB::container::NTT <> & ep)
{
	if (ep.exist ("address"))
	{
		addrs.reception ["address"] = ep ["address"] ();
	}
	
	if (ep.exist ("port"))
	{
		addrs.reception ["port"] = ep ["port"] ();
	}
	
	return true;
}

const bool LIB::network::ip::mpi::set_broadcast (LIB::container::NTT <> & ep)
{
	if (ep.exist ("address"))
	{
		addrs.broadcast ["address"] = ep ["address"] ();
	}
	
	if (ep.exist ("port"))
	{
		addrs.broadcast ["port"] = ep ["port"] ();
	}
	
	return true;
}

const bool LIB::network::ip::mpi::set_listen (LIB::container::NTT <> & ep)
{
	if (ep.exist ("address"))
	{
		addrs.listen ["address"] = ep ["address"] ();
	}
	
	if (ep.exist ("port"))
	{
		addrs.listen ["port"] = ep ["port"] ();
	}
	
	return true;
}

// Set Address.
const bool LIB::network::ip::mpi::set_transmit (const std::string & address)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.transmission);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.address = address;
//	
//	addrs.transmission = ep;
//	
	addrs.transmission ["address"] = address;
	
	return true;
}

const bool LIB::network::ip::mpi::set_receive (const std::string & address)
{
	//LIB::network::endpoint ep;
	
	//try
	//{
	//	ep = boost::any_cast <LIB::network::endpoint> (addrs.reception);
	//}
	//catch (...)
	//{
	//}
	
	//ep.address = address;
	
	//addrs.reception = ep;
	addrs.reception ["address"] = address;
	
	return true;
}

const bool LIB::network::ip::mpi::set_broadcast (const std::string & address)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.broadcast);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.address = address;
//	
//	addrs.broadcast = ep;
	
	addrs.broadcast ["address"] = address;
	
	return true;
}

const bool LIB::network::ip::mpi::set_listen (const std::string & address)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.listen);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.address = address;
//	
//	addrs.listen = ep;
	
	addrs.listen ["address"] = address;
	
	return true;
}

// Set Port.
const bool LIB::network::ip::mpi::set_transmit (const unsigned short int & port)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.transmission);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.port = port;
//	
//	addrs.transmission = ep;
	
	addrs.transmission ["port"] = port;
	
	return true;
}

const bool LIB::network::ip::mpi::set_receive (const unsigned short int & port)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.reception);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.port = port;
//	
//	addrs.reception = ep;
	
	addrs.reception ["port"] = port;
	
	return true;
}

const bool LIB::network::ip::mpi::set_broadcast (const unsigned short int & port)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.broadcast);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.port = port;
//	
//	addrs.broadcast = ep;
	
	addrs.broadcast ["port"] = port;
	
	return true;
}

const bool LIB::network::ip::mpi::set_listen (const unsigned short int & port)
{
//	LIB::network::endpoint ep;
//	
//	try
//	{
//		ep = boost::any_cast <LIB::network::endpoint> (addrs.listen);
//	}
//	catch (...)
//	{
//	}
//	
//	ep.port = port;
//	
//	addrs.listen = ep;
	
	addrs.listen ["port"] = port;
	
	return false;
}
*/
/*
// Getter.
unsigned short int LIB::network::ip::mpi::udp_port (void)
{
}
*/
/*
// Setter.
const bool LIB::network::ip::mpi::udp_port (const unsigned short int & port)
{
	return set_listen (port) && set_broadcast (port);
	
	/*
	LIB::network::endpoint ep_in, ep_out;
	
	try
	{
		ep_in = boost::any_cast <LIB::network::endpoint> (addrs.listen);
		ep_in.port = port;
		addr.listen = ep_in;
	}
	catch (...)
	{
	}
	
	try
	{
		ep_out = boost::any_cast <LIB::network::endpoint> (addrs.broadcast);
		ep_out.port = port;
		addr.broadcast = ep_out;
	}
	catch (...)
	{
	}
	* /
	
	//return true;
}
*/
/*
// Getter.
unsigned short int LIB::network::ip::mpi::tcp_port (void)
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
/*
// Setter.
const bool LIB::network::ip::mpi::tcp_port (const unsigned short int & port)
{
	return set_receive (port) && set_transmit (port);
	
	//return true;
}
*/
//void LIB::network::ip::mpi::stop (void)
//{
//	//cancel_udp ();
//	//cancel_tcp ();
//	
//	//handlers.reset ();
//	//mathematics::numbers::natural n;
//	//n = handlers.size ();
//	
//	for (auto & element : handlers)
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
//			//delete * (element.val);
//			delete element.v;
//		//}
//		//catch (...)
//		//{
//		//}
//		
//	}
//	
//	handlers.clear ();
////	handlers.reset ();
////	mathematics::numbers::natural n = handlers.size (), m, i, j;
////	
////	for (i = 0; i < n; ++ i)
////	{
////		/*
////		handlers.current_value ().reset ();
////		m = handlers.current_value ().size ();
////
////		for (j = 0; j < m; ++ j)
////		{
////			handlers.current_value ().current_value ().stop ();
////			handlers.current_value ().next ();
////		}
////		*/
////		//try
////		//{
////			delete handlers [i];
////		//}
////		//catch (...)
////		//{
////		//}
////		
////		handlers.next ();
////	}
//}
//
///*
//const std::string & LIB::network::ip::mpi::multicast_group (const std::string & address)
//{
//	return multicast_group_broadcast = multicast_group_listen = address;
//}
//*/
//
//void LIB::network::ip::mpi::stop_udp (void)
//{
//	//listeners.reset ();
//	//mathematics::numbers::natural n;
//	//n = listeners.size ();
//	
////	listeners.reset ();
////	mathematics::numbers::natural n = listeners.size ();
////	
////	for (mathematics::numbers::natural i = 0; i < n; ++ i)
////	{
////		//boost::hash_combine (hash, handler);
////		//boost::hash_combine (hash, broadcast_address);
////		//boost::hash_combine (hash, port);
////		
////		boost::thread * thread;
////		boost::asio::ip::udp::socket * socket;
////		
////		listeners.current_value () [0] = 0;
////		socket = listeners.current_value () [1];
////		thread = listeners.current_value () [2];
////		
////		if (socket != NULL)
////		{
////			try
////			{
////				socket-> close ();
////				
////				delete socket;
////			}
////			catch (...)
////			{
////			}
////		
////		}
////		
////		if (thread != NULL)
////		{
////			//thread-> close ();
////			
////			try
////			{
////				delete thread;
////			}
////			catch (...)
////			{
////			}
////		}
////		
////		listeners.next ();
////	}
///*
//	if (socket_udp_receive != NULL)
//	{
//		//socket_udp_receive -> cancel ();
//		socket_udp_receive -> close ();
//	}
//*/
//}
//
//void LIB::network::ip::mpi::stop_tcp (void)
//{
//	//io.stop ();
//	
////	mathematics::numbers::natural n = receivers.size ();
////	receivers.reset ();
////	
////	for (mathematics::numbers::natural i = 0; i< n; ++ i)
////	{
////		boost::shared_ptr <boost::asio::io_service> io_service;
////		io_service = receivers.current_value ();
////		
////		if (io_service != NULL)
////		{
////			try
////			{
////				io_service-> stop ();
////				//delete io_service;
////			}
////			catch (...)
////			{
////			}
////		}
////		
////		receivers.next ();
////	}
//}

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

//const bool LIB::network::ip::mpi::transmit (const std::string & message, const bool & _reliable)
//{
//	return transmit (message, _reliable ? transmission.reliable : transmission.unreliable, _reliable);
//	/*
//	LIB::network::endpoint addr;
//	
//	try
//	{
//		addr = boost::any_cast <LIB::network::endpoint> (addrs.transmission);
//	}
//	catch (...)
//	{
//		return false;
//	}
//	
//	return transmit (message, addr.address, addr.port);
//	*/
//}

//const bool LIB::network::ip::mpi::transmit (const std::string & message)
//{
//	return transmit (message, reliable ? transmission.reliable : transmission.unreliable);
//	/*
//	LIB::network::endpoint addr;
//	
//	try
//	{
//		addr = boost::any_cast <LIB::network::endpoint> (addrs.transmission);
//	}
//	catch (...)
//	{
//		return false;
//	}
//	
//	return transmit (message, addr.address, addr.port);
//	*/
//}

//const bool LIB::network::ip::mpi::transmit (const std::string & message, const std::string & address)
//{
//	return transmit (message, address, tcp_transmit.port);
//}
/*
const bool LIB::network::ip::mpi::transmit (const std::string & message, const LIB::container::NTT <> & address)
{
	LIB::network::endpoint addr;
	
	try
	{
		addr = boost::any_cast <LIB::network::endpoint> (address);
	}
	catch (...)
	{
		return false;
	}
	
	return transmit (message, addr.address, addr.port);
}
*/
/*
const bool LIB::network::ip::mpi::transmit (const std::string & message, const unsigned short int & port)
{
	return transmit (message, tcp_transmit.address, port);
}

const bool LIB::network::ip::mpi::transmit (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return transmit (message, address, port);
}
*/

//const bool LIB::network::ip::mpi::transmit (const std::string & message, LIB::container::NTT <> address)
//{
//	return transmit (message, address, reliable);
//}

// const bool LIB::network::ip::mpi::transmit (const std::string & message, const std::string & address, const unsigned short int & port)
const bool LIB::network::ip::mpi::transmit (const std::string & message, LIB::container::NTT <> address, const bool & _reliable)
{
	//LIB::network::endpoint addr;
	
	if (_reliable)
	{
		if (!address.exists ("port") && transmission.reliable.exists ("port"))
		{
			address ["port"] = transmission.reliable ["port"] ();
		}
		
		if (!address.exists ("address") || !address.exists ("port"))
		{
			return false;
		}
		
		/*
		try
		{
			addr = boost::any_cast <LIB::network::endpoint> (address);
		}
		catch (...)
		{
			return false;
		}
		*/

		//return transmit (message, addr.address, addr.port);


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

			boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (address ["address"] ()), (unsigned short int) (address ["port"] ()));
			// boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);

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
	else
	{
		/*if (!address.exists ("port") && addrs.transmission.reliable.exists ("port"))
		{
			address ["port"] = addrs.transmission.reliable ["port"] ();
		}
		
		if (!address.exists ("address") || !address.exists ("port"))
		{
			return false;
		}*/
		
		return false;
	}
}

//const bool LIB::network::ip::mpi::broadcast (const std::string & message)
//{
//	return broadcast (message, reliable ? broadcast.reliable : broadcast.unreliable);
//}
//
//const bool LIB::network::ip::mpi::broadcast (const std::string & message, const bool & _reliable)
//{
//	return broadcast (message, _reliable ? broadcast.reliable : broadcast.unreliable, _reliable);
//}

/*
const bool LIB::network::ip::mpi::broadcast (const std::string & message, const std::string & address)
{
	return broadcast (message, address, udp_broadcast.port);
}

const bool LIB::network::ip::mpi::broadcast (const std::string & message, const LIB::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural> & addresses)
{
	return false;
}

const bool LIB::network::ip::mpi::broadcast (const std::string & message, const unsigned short int & port)
{
	return broadcast (message, udp_broadcast.address, port);
}

const bool LIB::network::ip::mpi::broadcast (const std::string & message, const unsigned short int & port, const std::string & address)
{
	return broadcast (message, address, port);
}
*/

//const bool LIB::network::ip::mpi::broadcast (const std::string & message, LIB::container::NTT <> addresses)
//{
//	return broadcast (message, addresses, reliable);
//}

// const bool LIB::network::ip::mpi::broadcast (const std::string & message, const std::string & address, const unsigned short int & port)
//const bool LIB::network::ip::mpi::broadcast (const std::string & message, const LIB::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural> & addresses)
const bool LIB::network::ip::mpi::broadcast (const std::string & message, LIB::container::NTT <> addresses, const bool & _reliable)
{
	// bool multiple = false;
	// LIB::network::endpoint addr;
	// LIB::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural> _addrs;
	//LIB::NAME_A <LIB::network::endpoint, mathematics::numbers::natural> addrs2;
	
	/*
	try
	{
		_addrs = boost::any_cast <LIB::NAME_A <LIB::container::NTT <>, mathematics::numbers::natural>> (addresses);
		
		//for (auto & element : addresses)
		//{
		//	addr = boost::any_cast <LIB::network::endpoint> (element);
		//	//addrs2.add (addr);
		//}
		
		multiple = true;
	}
	catch (...)
	{
		try
		{
			addr = boost::any_cast <LIB::network::endpoint> (addresses);
		}
		catch (...)
		{
			return false;
		}
	}
	*/
	
	
	//if (!multiple)
	if (_reliable)
	{
		return false;
	}
	else
	{
		////if (addresses.exist ("port"))
		//if (addresses.exists ("address") || addresses.exists ("port"))
		//{
		//}
		if (addresses.exists ("addresses"))
		{
			bool success = true;
			
			for (const LIB::container::NTT <> & address : addresses ["addresses"])
			{
				if (!/* transmit*/ broadcast (message, address, _reliable)/* && success*/)
				{
					success = false;
				}
			}
			
			return success;
		}
		else
		{
			if (addresses.is_literal ())
			{
				if (addresses.get_value ().is_numeric ())
					addresses ["port"] = LIB::container::NAME_V (addresses);
				else if (!addresses.get_value ().empty ())
					addresses ["address"] = LIB::container::NAME_V (addresses);
			}
			
			/*
			if (!addresses.exists ("address") && reception.unreliable.exists ("address"))
			{
				addresses ["address"] = reception.unreliable ["address"] ();
			}
			*/
			if (!addresses.exists ("port") && reception.unreliable.exists ("port"))
			{
				addresses ["port"] = reception.unreliable ["port"] ();
			}
			
			if (/*!addresses.exists ("address") || */!addresses.exists ("port"))
			{
				return false;
			}
			
			try
			{
				//boost::asio::io_service io_service;
				
				// Server binds to any address and any port.
				//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
				//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v6::any (), 0));
				boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), 0));
				//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::from_string (addresses ["address"] ().to_string ()), 0));
				socket.set_option (boost::asio::socket_base::broadcast (true));
				//socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
				
				// Broadcast will go to port 8888.
				//boost::asio::ip::udp::endpoint broadcast_endpoint_6 (boost::asio::ip::address_v6::broadcast (), (unsigned short int) (addresses ["port"] ()));
				
				boost::asio::ip::udp::endpoint * broadcast_endpoint;
				
				if (addresses.exists ("address")/* && reception.unreliable.exists ("address")*/)
				{
					//boost::asio::ip::udp::endpoint broadcast_endpoint (boost::asio::ip::address_v4::from_string (addresses ["address"] ().to_string ()), (unsigned short int) (addresses ["port"] ()));
					broadcast_endpoint = new boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::from_string (addresses ["address"] ().to_string ()), (unsigned short int) (addresses ["port"] ()));
				}
				else
				{
					//boost::asio::ip::udp::endpoint broadcast_endpoint (boost::asio::ip::address_v4::broadcast (), (unsigned short int) (addresses ["port"] ()));
					broadcast_endpoint = new boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::broadcast (), (unsigned short int) (addresses ["port"] ()));
				}
				
				//std::cout << std::endl << "Address:[" << addresses ["address"] ().to_string () << ']' << std::endl;
				//boost::asio::ip::udp::endpoint network_endpoint (boost::asio::ip::address::from_string (addresses ["address"] ().to_string ()), 0);
				//socket.bind (network_endpoint);
				
				// Broadcast data.
				//mathematics::numbers::natural length_6 = socket.send_to (boost::asio::buffer (message), broadcast_endpoint);
				mathematics::numbers::natural length = socket.send_to (boost::asio::buffer (message), * broadcast_endpoint);
				
				delete broadcast_endpoint;
				
				return ! (length < message.length ());
				
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
	}
}

//std::string LIB::network::ip::mpi::receive (const unsigned short int & port, const unsigned short int & version, void (* handler) (std::string), void (* handler_internal) (std::string))
/*std::string LIB::network::ip::mpi::receive (const unsigned short int & port, const unsigned short int & version, void (* handler) (std::string), void (* handler_internal) (std::string))
{
	(* handler) (receive (link, handler, & LIB::network::ip::mpi::receive_async_handler));
	unsigned long int hash = 0;
	boost::hash_combine <void (*) (std::string)> (hash, handler);
	boost::hash_combine <const connection &> (hash, link);
	boost::hash_combine <const bool &> (hash, cycle);
	
	
	handlers.unset (hash);
}
*/

//const std::string LIB::network::ip::mpi::receive (void)
//{
//	LIB::container::NTT <> remote_endpoint;
//	return receive (remote_endpoint, reliable ? reception.reliable : reception.unreliable, reliable);
//}
//
//const std::string LIB::network::ip::mpi::receive (const bool & _reliable)
//{
//	LIB::container::NTT <> remote_endpoint;
//	return receive (remote_endpoint, _reliable ? reception.reliable : reception.unreliable, _reliable);
//}

/*
std::string LIB::network::ip::mpi::receive (const LIB::container::NTT <> & address)
{
	std::string addr;
	
	try
	{
		addr = boost::any_cast <std::string> (address);
	}
	catch (...)
	{
		return false;
	}
	
	return receive (addr, tcp_receive.port);
}

std::string LIB::network::ip::mpi::receive (const unsigned short int & port)
{
	return receive (tcp_receive.address, port);
}

std::string LIB::network::ip::mpi::receive (const unsigned short int & port, const std::string & address)
{
	return receive (address, port);
}
*/

//const std::string LIB::network::ip::mpi::receive (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address)
//{
//	return receive (remote_endpoint, address, reliable);
//}

const std::string LIB::network::ip::mpi::receive (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address, const bool & _reliable)
// std::string LIB::network::ip::mpi::receive (const std::string & address, const unsigned short int & port)
//std::string LIB::Network::mpi::Receive ()
{
	if (_reliable)
	{
		/*
		LIB::network::endpoint addr;

		try
		{
			addr = boost::any_cast <LIB::network::endpoint> (address);
		}
		catch (...)
		{
			return "";
		}
		*/

		try
		{
			if (!address.exists ("address") && reception.reliable.exists ("address"))
			{
				address ["address"] = reception.reliable ["address"] ();
			}
			
			if (!address.exists ("port") && reception.reliable.exists ("port"))
			{
				address ["port"] = reception.reliable ["port"] ();
			}
			
			if (!address.exists ("address") || !address.exists ("port"))
			{
				return "";
			}
			
			
			// std::cout << "Messaging.cpp:\'receive()\' : Waiting to Receive..." << std::endl;
			//boost::asio::ip:tcp::iostream ios ();
			//unsigned short int port = tcp.Port ();
			//boost::asio::io_service io;
			std::string message;
			//boost::asio::ip::tcp::acceptor * acceptor;
			boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::address::from_string (address ["address"] ()), address ["port"] ());
			boost::asio::ip::tcp::acceptor acceptor (io, endpoint);
			boost::asio::ip::tcp::socket socket (io);

			//char * data;

			double diff;
			unsigned long long int available_chars;
			time_t time_end_allowed, time_end_actual;

			// std::cout << "\tPreparing to Receive..." << std::endl;
			acceptor.accept (socket);

			/*if (handler != NULL && cycle)
			{
				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::receive_async_handler, this, port, version, handler, cycle, hash));
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
			
			if (! (available_chars > 0))
				available_chars = message_size;
			
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

			//if (remote_endpoint != NULL)
			//{
				boost::asio::ip::tcp::endpoint remote_ep = socket.remote_endpoint ();

				remote_endpoint ["address"] = (LIB::container::NAME_V) remote_ep.address ().to_string ();
				remote_endpoint ["port"] = remote_ep.port ();
			//}

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


			// std::cout << "Messaging.cpp: Received Message [" << message.substr (0, available_chars) << "]" << std::endl;

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
			// std::cout << "Messaging.cpp (std::exception): \'Receive\' : Error: " << e.what () << std::endl;
			//error = e;

			//return e.what();
			return "";
		}
		catch (...) //(...) //(std::exception & e)
		{
			//acceptor -> close ();
			// std::cout << "Messaging.cpp (...): \'Receive\': Error." << std::endl;
			//error = e;

			//return e.what();
			return "";
		}
	}
	else
	{
		try
		{
			/*
			if (!address.exists ("address") && addrs.reception.unreliable.exists ("address"))
			{
				address ["address"] = addrs.reception.reliable ["address"] ();
			}
			*/
			if (!address.exists ("port") && reception.unreliable.exists ("port"))
			{
				address ["port"] = reception.unreliable ["port"] ();
			}
			
			if (/*!address.exists ("address") || */!address.exists ("port"))
			{
				return "";
			}
			
			
			//std::cout << "Messaging.cpp: Listening (Edited)..." << std::endl;
			std::string message;

			// TODO: Bind to the specified address if it is provided.
			//boost::asio::io_service io_service;
			//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
			//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), port));
			boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), address ["port"] ()));
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
			unsigned long long int
			//LIB::mathematics::numbers::natural
				length = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
			
			//boost::asio::ip::udp::endpoint remote_ep = socket.remote_endpoint ();
			//boost::asio::ip::address remote_add = remote_ep.address ();
			//std::string remote_address = remote_add.to_string ();
			
			message = data;
			
			// delete [] data;
			
			//if (remote_endpoint != NULL)
			//{
				//boost::asio::ip::udp::endpoint remote_ep = socket.remote_endpoint ();
				
				remote_endpoint ["address"] = (LIB::container::NAME_V) sender_endpoint.address ().to_string ();
				remote_endpoint ["port"] = sender_endpoint.port ();
			//}
			
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
	//			handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, address, port, handler, cycle, hash));
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
			//std::cout << "noware/messaging/network/ip/mpi.c++:1526: error (std::exception & e):" << e.what () << std::endl;
			//return e.what();
			return "";
		}
		catch (...) //(std::exception & e)
		{
			//error = e;
			//std::cout << "Error: Listening." << std::endl;
			// std::cout << "Messaging.cpp (...): \'Listen\': Error." << std::endl;
			//return e.what();
			return "";
		}
	}
}

//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler)
//{
//	return receive_async (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle)
//{
//	return receive_async (handler, tcp_receive.address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address)
//{
//	return receive_async (handler, address, tcp_receive.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port)
//{
//	return receive_async (handler, tcp_receive.address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
//{
//	return receive_async (handler, address, tcp_receive.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
//{
//	return receive_async (handler, address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
//{
//	return receive_async (handler, tcp_receive.address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
//{
//	return receive_async (handler, tcp_receive.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
//{
//	return receive_async (handler, address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
//{
//	return receive_async (handler, tcp_receive.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
//{
//	unsigned long int hash = 0;
//	//hash = 0;
//	//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
//	boost::hash_combine <ip::protocol> (hash, ip::protocol::tcp);
//	boost::hash_combine <const std::string &> (hash, address);
//	//boost::hash_combine <const unsigned short int> (hash, version);
//	//boost::hash_combine <const connection &> (hash, link);
//	boost::hash_combine <const unsigned short int &> (hash, port);
//	//boost::hash_combine <const bool &> (hash, cycle);
//	
//	//if (handlers.exist (hash))
//	//	return false;
//	
//	if (handlers.exist (hash))
//		return true;
//	
//	handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
//	
//	//return handlers.exist (hash);
//	return true;
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
//{
//	return receive_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
//{
//	return receive_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
//{
//	return receive_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
//{
//	return receive_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
//{
//	return receive_async (handler, address, port, cycle);
//}
//
//void LIB::network::ip::mpi::receive_async_handler (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle, const unsigned long int & hash)
//{
//	//do
//	//{
//	//	(* handler) (receive (link, handler, & LIB::network::ip::mpi::receive_async_handler));
//	//}
//	//(* handler) (receive (port, version, & LIB::network::ip::mpi::receive_async_handler));
//	//(* handler) (receive (port, version, handler, cycle));
//	//handler (receive (port, version, handler, cycle));
//	
//	//while (cycle);
//	if (handler != NULL)
//	{
//		try
//		{
//			std::cout << "Messaging.cpp:\'receive_async_handler()\': Waiting to Receive..." << std::endl;
//			std::cout << "Messaging.cpp:\'receive_async_handler()\': address " << address << std::endl;
//			std::cout << "Messaging.cpp:\'receive_async_handler()\': port " << port << std::endl;
//			//boost::asio::ip:tcp::iostream ios ();
//			//unsigned short int port = tcp.Port ();
//			//boost::asio::io_service io;
//			std::string message;
//			//boost::asio::ip::tcp::acceptor * acceptor;
//			// boost::asio::ip::tcp::endpoint * endpoint;
//			// boost::asio::ip::tcp::acceptor * acceptor;
//			// boost::asio::ip::tcp::socket * socket;
//			
//			boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::endpoint (boost::asio::ip::address::from_string (address), port));
//			boost::asio::ip::tcp::acceptor acceptor (io, endpoint);
//			
//			acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
//			
//			boost::asio::ip::tcp::socket socket (io);
//			
//			//char * data;
//			
//			/*
//			switch (version)
//			{
//				case 6:
//					endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port);
//					//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v6 (), port));
//					break;
//				case 4:
//					endpoint = new boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port);
//
//					if (version != 4)
//						version = 4;	// Make sure it is 4.
//					//acceptor = new boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
//			}
//			*/
//			
//			//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp::v4 ());
//			//boost::asio::ip::tcp::acceptor acceptor = boost::asio::ip::tcp::acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp::v4 (), port));
//			// /*receive_*/acceptor = new boost::asio::ip::tcp::acceptor (io, * endpoint);
//			//acceptor -> open (endpoint -> protocol ());
//			// /*receive_*/acceptor -> set_option (boost::asio::ip::tcp::acceptor::reuse_address (true));
//
//			//boost::asio::ip::tcp::acceptor acceptor (io, boost::asio::ip::tcp::endpoint (boost::asio::ip::tcp:: (, port));
//			//boost::asio::ip::tcp::acceptor acceptor (io);
//			//boost::asio::ip::tcp::endpoint endpoint (boost::asio::ip::tcp (boost::asio::ip::tcp::family ()), port);
//
//			//acceptor.open (endpoint.protocol ());
//			//acceptor.set_option (boost::asio::ip::tcp::acceptor::reuse_address(true));
//			//boost::asio::ip::tcp::socket socket (io);
//			// cancel_tcp ();
//
//			//socket/*_tcp_receive*/ = new boost::asio::ip::tcp::socket (io);
//
//			double diff;
//			unsigned long long int available_chars;
//			time_t time_end_allowed, time_end_actual;
//			//boost::thread * t;
//
//			/*
//			unsigned long int hash = 0;
//			boost::hash_combine <void (*) (std::string)> (hash, handler);
//			//boost::hash_combine <const connection &> (hash, link);
//			boost::hash_combine <const unsigned short int &> (hash, version);
//			boost::hash_combine <const unsigned short int &> (hash, port);
//			//boost::hash_combine <const bool &> (hash, cycle);
//			*/
//
//			std::cout << "\tPreparing to Receive..." << std::endl;
//			///*receive_*/acceptor.accept (socket/*_tcp_receive*/);
//			acceptor.accept (socket/*_tcp_receive*/);
//			
////			if (/*handler != NULL && */cycle)
////			{
////				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
////				//handlers [hash] = t;
////				//(* handler) (message);
////			}
////
//			//boost::array<char, MESSAGE_SIZE> buf;
//			// char * buffer = new char [message_size];
//			//boost::posix_time::time_duration attempt = boost::posix_time::microseconds (1000);
//			//time_start = time (NULL);
//			//std::cout << time_start << std::endl;
//			time_end_allowed = time (NULL);
//
//			do
//			{
//				//available_chars = socket/*_tcp_receive*/ -> available ();	// This time may not work, returning 0.
//				available_chars = socket.available ();	// This time may not work, returning 0.
//				//available = socket_tcp_receive -> available ();
//				//std::cout << time (NULL) << std::endl;
//				time_end_actual = time (NULL);
//				diff = std::difftime (time_end_actual, time_end_allowed);
//			}
//			while (available_chars <= 0 && diff <= 0.01);
//			
//			//data = new char [message_size];
//			//data = new char [available_chars];
//			char data [available_chars];
//			
//			
//			//std::cout << "AVAILABLE(" << available<< ")";
//			//std::vector <char> data (available);
//			
//			//size_t len = socket.receive (boost::asio::buffer (buf, message_size)); //, ignored_error);
//			// mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (buffer, message_size)); //, ignored_error);
//			//mathematics::numbers::natural len = socket_tcp_receive -> receive (boost::asio::buffer (data, available)); //, ignored_error);
//			///*mathematics::numbers::natural len =*/ socket_tcp_receive -> receive (boost::asio::buffer (& message [0], message.size ())); //, ignored_error);
//			// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
//			// socket_tcp_receive -> receive (boost::asio::buffer (& message [0], /*message.size ()*/3)); //, ignored_error);
//			// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (data));
//			// boost::asio::read (* socket_tcp_receive, boost::asio::buffer (message));
//			//boost::asio::read (* socket_tcp_receive, boost::asio::buffer (& message [0], message.size ()));
//			// /*size_t len = */boost::asio::read (* socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
//			boost::asio::read (socket/*_tcp_receive*/, boost::asio::buffer (data, available_chars));
//			//boost::asio::read (* socket_tcp_receive, & message [0]);
//			//socket_tcp_receive -> read_some (message);
//			//socket_tcp_receive -> read_some (& message [0]);
//			//socket_tcp_receive -> read_some (boost::asio::buffer (& message [0], 3));
//			//size_t len = socket_tcp_receive -> receive (boost::asio::buffer (data, message_size)/*, ignored_error*/);
//			//socket_tcp_receive -> read_some (boost::asio::buffer (data, available_chars)/*, ignored_error*/);
//
//
//			acceptor.close ();
//			//std::cout << "Messaging.cpp: Deleting \'receive_acceptor\'..." << std::endl;
//			//delete acceptor;
//			//std::cout << "Messaging.cpp: Deleted \'receive_acceptor\'..." << std::endl;
//			//acceptor = NULL;
//
//			//delete endpoint;
//
//			//delete socket;
//			//socket = NULL;
//
//			//message = buf.data ();
//			message = data;
//			//delete [] data;
//			//
//			//for (unsigned long long int i = 0; i < available; ++ i)
//			//{
//			//	message += data [i];
//			//}
//			//
//			//data[0];
//			// message = buffer;
//			//std::cout << std::endl << buf << std::endl;
//			// delete [] buffer;
//			
//			//if (acceptor != NULL)
//			//for (Mathematics::Number::Natural index = 0; index < message_size; index)
//			
//			
//			std::cout << "Messaging.cpp: receive_async_handler(): Received Message [" << message/*.substr (0, available_chars)*/ << "]" << std::endl;
//			
//			// return message.substr (0, len);
//			//return message.substr (0, 3);
//			//std::cout << "Available characters: " << available_chars << std::endl;
//			//std::cout << "Read characters: " << len << std::endl;
//			//message = message.substr (0, available_chars);
//			
//			std::cout << "Messaging.cpp: receive_async_handler(): Received: Calling handler: handler (message.substr (0, available_chars))" << std::endl;
//				handler (message/*.substr (0, available_chars)*/);
//			
//			if (/*handler != NULL && */cycle)
//			{
//				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::receive_async_handler, this, handler, address, port, cycle, hash));
//				//handlers [hash] = t;
//				//(* handler) (message);
//			}
//			
//			if (! cycle)
//			{
//				handlers.unset (hash);
//			}
//
//			//return message;
//			//return message.substr (0, available_chars);
//			//return message.substr (0, len);
//			//return data.data ();
//			//return data;
//
//			//std::string buffer;
//			//size_t size = socket.receive (boost::asio::buffer (buffer)); //, ignored_error);
//			//return buffer;
//		}
//		catch (std::exception & e) //(...) //(std::exception & e)
//		{
//			//acceptor -> close ();
//			std::cout << "Messaging.cpp:933: receive_async_handler(): (std::exception): Error: " << e.what () << std::endl;
//			//error = e;
//
//			//return e.what();
//			//return "";
//		}
//		catch (...) //(...) //(std::exception & e)
//		{
//			//acceptor -> close ();
//			std::cout << "Messaging.cpp (...): receive_async_handler(): Error." << std::endl;
//			//error = e;
//
//			//return e.what();
//			//return "";
//		}
//	}
//}
//
///*
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool cycle, const std::string & address, const unsigned short int version)
//{
//	return receive_async_stop (handler, tcp.port, version, cycle);
//}
//*/
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler)
//{
//	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address)
//{
//	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port)
//{
//	return receive_async_stop (handler, tcp_receive.address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle)
//{
//	return receive_async_stop (handler, tcp_receive.address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
//{
//	return receive_async_stop (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
//{
//	return receive_async_stop (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
//{
//	return receive_async_stop (handler, address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
//{
//	return receive_async_stop (handler, tcp_receive.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
//{
//	return receive_async_stop (handler, address, tcp_receive.port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
//{
//	return receive_async_stop (handler, tcp_receive.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
////bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
//{
//	//if (handler != NULL)
//	//{
//		//protocol p = protocol::tcp;
//		unsigned long int hash = 0;
//		//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
//		boost::hash_combine <ip::protocol> (hash, ip::protocol::tcp);
//		boost::hash_combine <const std::string &> (hash, address);
//		//boost::hash_combine <const connection &> (hash, link);
//		//boost::hash_combine <const unsigned short int> (hash, version);
//		boost::hash_combine <const unsigned short int &> (hash, port);
//		//boost::hash_combine <const bool> (hash, cycle);
//
//
//		//boost::shared_ptr <boost::asio::io_service> io_service;
//		//io_service = receivers [hash];
//
//		//try
//		//{
//			//io_service-> stop ();
//		//	handlers [hash].[handlers [hash].size () - 1].stop ();
//			//delete io_service;
//		//}
//		//catch (...)
//		//{
//		//}
//
//		if (! handlers.exist (hash))
//			return true;
//		
//		try
//		{
//			//handlers [hash] -> interrupt ();
//			delete handlers [hash];
//		}
//		catch (...)
//		{
//			return false;
//		}
//		
//		handlers.unset (hash);
//	//}
//	
//	return true;
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
//{
//	return receive_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
//{
//	return receive_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
//{
//	return receive_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
//{
//	return receive_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::receive_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
//{
//	return receive_async_stop (handler, address, port, cycle);
//}

// UDP:

/*
const std::string LIB::network::ip::mpi::listen (const LIB::container::NTT <> & address)
{
	std::string addr;
	
	try
	{
		addr = boost::any_cast <std::string> (address);
	}
	catch (...)
	{
		return false;
	}
	
	return listen (addr, udp_listen.port);
}

std::string LIB::network::ip::mpi::listen (const unsigned short int & port)
{
	return listen (udp_listen.address, port);
}

std::string LIB::network::ip::mpi::listen (const unsigned short int & port, const std::string & address)
{
	return listen (address, port);
}
*/

// *** Previously used:
////std::string LIB::Network::mpi::Listen ()
//const std::string LIB::network::ip::mpi::listen (void)
//{
//	return listen (NULL, addrs.listen);
//}
//
////const std::string LIB::network::ip::mpi::listen (const std::string & address, const unsigned short int & port)
//const std::string LIB::network::ip::mpi::listen (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address)
//{
//	/*
//	LIB::network::endpoint addr;
//	
//	try
//	{
//		addr = boost::any_cast <LIB::network::endpoint> (address);
//	}
//	catch (...)
//	{
//		return "";
//	}
//	*/
//	
//	if (!address.exist ("port") && addrs.listen.exist ("port"))
//	{
//		address ["port"] = addrs.listen ["port"] ();
//	}
//	
//	if (!address.exist ("address") || !address.exist ("port"))
//	{
//		return "";
//	}
//	
//	try
//	{
//		//std::cout << "Messaging.cpp: Listening (Edited)..." << std::endl;
//		std::string message;
//		
//		
//		//boost::asio::io_service io_service;
//		//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
//		//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), port));
//		boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), address ["port"] ()));
//		boost::asio::ip::udp::endpoint sender_endpoint;
//		
//		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
//		
////		socket.open (endpoint.protocol ());
////		//socket.open (boost::asio::ip::udp::v4 ());
////		
////		std::cout << "Messaging.cpp: listen (): allowing reusage of addresses..." << std::endl;
////		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
////		//socket.set_option (boost::asio::socket_base::broadcast (true));
////		
////		//socket.bind (endpoint);
////		//socket.connect (endpoint);
////		
////		// Join the multicast group.
////		//std::cout << "Messaging.cpp: listen (): joining the multicast group " << address << " ..." << std::endl;
////		//socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
////		if (! multicast_group_listen.empty ())
////		{
////			// Join the multicast group.
////			socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
////		}
////		
////		socket.bind (endpoint);
//		
//		char data [message_size];
//		
//		//socket.receive_from (boost::asio::buffer (buffer), sender_endpoint);
//		unsigned long long int length;
//		length = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//		
//		//boost::asio::ip::udp::endpoint remote_ep = socket.remote_endpoint ();
//		//boost::asio::ip::address remote_add = remote_ep.address ();
//		//std::string remote_address = remote_add.to_string ();
//		
//		if (remote_endpoint != NULL)
//		{
//			boost::asio::ip::udp::endpoint remote_ep = socket.remote_endpoint ();
//			
//			remote_endpoint ["address"] = remote_ep.address ().to_string ();
//			remote_endpoint ["port"] = remote_ep.port ();
//		}
//		
//		message = data;
//		
//		//message = message.substr (0, length);
//		
//		//std::cout << "Messaging.cpp: Listened (Edited): [" << message << "]" << std::endl;
//		
//		//return message;
//		return message.substr (0, length);
//		
////		//boost::asio::io_service io;
////		//boost::asio::io_service io_2;
////		// boost::asio::ip::udp::socket socket;
////		//boost::asio::ip::udp::socket socket (io);
////		// cancel_udp ();
////
////		// socket_udp_receive = new boost::asio::ip::udp::socket (io);
////		//boost::asio::ip::udp::endpoint sender_endpoint;
////		
////		boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
////		//boost::asio::ip::udp::endpoint endpoint;
////		
////		boost::asio::ip::udp::socket socket (io/*, endpoint/*.protocol ()*/);
////		
////		socket.open (endpoint.protocol ());
////		//socket.open (boost::asio::ip::udp::v4 ());
////		
////		std::cout << "Messaging.cpp: listen (): allowing reusage of addresses..." << std::endl;
////		socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
////		//socket.set_option (boost::asio::socket_base::broadcast (true));
////		
////		//socket.bind (endpoint);
////		//socket.connect (endpoint);
////		
////		// Join the multicast group.
////		//std::cout << "Messaging.cpp: listen (): joining the multicast group " << address << " ..." << std::endl;
////		//socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (address)));
////		if (! multicast_group_listen.empty ())
////		{
////			// Join the multicast group.
////			socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
////		}
////		
////		socket.bind (endpoint);
////		
////		//
////		//socket_udp_receive -> connect (,);
////		//unsigned long long int available = 5;
////			///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
////		
////		//char * data = new char [available];
////		//char data [MESSAGE_SIZE];
////		//char * data = new char [message_size];
////		char data [message_size];
////		
////		//io_2.run ();
////		//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
////		//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
////		mathematics::numbers::natural length = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
////		
////		/*
////		if (handler != NULL && cycle)
////		{
////			handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, address, port, handler, cycle, hash));
////			//handlers [hash] = t;
////			//(* handler) (message);
////		}
////		else
////		{
////			handlers.unset (hash);
////		}
////		*/
////		
////		//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
////		// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
////		//socket_udp_receive ->
////		message = data;
////		//delete [] data;
////
////		//delete socket;
////		//socket = NULL;
////
////		std::cout << "Messaging.cpp: Listened: [" << message.substr (0, length) << "]" << std::endl;
////		
////		return message.substr (0, length);
//		//return message.substr (0, available);
//	}
//	catch (std::exception & e)
//	{
//		//error = e;
//		//std::cout << "Error: Listening." << std::endl;
//		// std::cout << "Messaging.cpp (std::exception & e): \'Listen\': Error:" << e.what () << std::endl;
//		//return e.what();
//		return "";
//	}
//	catch (...) //(std::exception & e)
//	{
//		//error = e;
//		//std::cout << "Error: Listening." << std::endl;
//		// std::cout << "Messaging.cpp (...): \'Listen\': Error." << std::endl;
//		//return e.what();
//		return "";
//	}
//}
// *** Previously used.

//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler)
//{
//	return listen_async (handler, udp_listen.address, udp_listen.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address)
//{
//	return listen_async (handler, address, udp_listen.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port)
//{
//	return listen_async (handler, udp_listen.address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle)
//{
//	return listen_async (handler, udp_listen.address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
//{
//	return listen_async (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
//{
//	return listen_async (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
//{
//	return listen_async (handler, address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
//{
//	return listen_async (handler, udp_listen.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
//{
//	return listen_async (handler, address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
//{
//	return listen_async (handler, udp_listen.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
////bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & broadcast_address, const unsigned short int & port, const bool cycle)
//{
//	unsigned long int hash = 0;
//	//hash = 0;
//	//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
//	//boost::hash_combine <const connection &> (hash, link);
//	boost::hash_combine <ip::protocol> (hash, ip::protocol::udp);
//	boost::hash_combine <const std::string &> (hash, address);
//	boost::hash_combine <const unsigned short int &> (hash, port);
//	//boost::hash_combine <const bool> (hash, cycle);
//	
//	if (handlers.exist (hash))
//		return true;
//	
//	handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
//	
//	//return handlers.exist (hash);
//	return true;
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
//{
//	return listen_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
//{
//	return listen_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
//{
//	return listen_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
//{
//	return listen_async (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
//{
//	return listen_async (handler, address, port, cycle);
//}
//
//void LIB::network::ip::mpi::listen_async_handler (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle, const unsigned long int & hash)
//{
//	//do
//	//{
//	//	(* handler) (receive (link, handler, & LIB::network::ip::mpi::receive_async_handler));
//	//}
//	//(* handler) (receive (port, version, & LIB::network::ip::mpi::receive_async_handler));
//	//(* handler) (receive (port, version, handler, cycle));
//	//handler (listen (broadcast_address, port, handler, cycle, hash));
//	//while (cycle);
//	
//	if (handler != NULL)
//	{
//		try
//		{
//			std::string message;
//			
//			//boost::asio::io_service io_service;
//			//boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::udp::v4 (), port));
//			boost::asio::ip::udp::socket socket (io, boost::asio::ip::udp::endpoint (boost::asio::ip::address_v4::any (), port));
//			
//			boost::asio::ip::udp::endpoint sender_endpoint;
//			
//			socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
//			
//			char data [message_size];
//			
//			mathematics::numbers::natural length = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
//			
////			if (/*handler != NULL && */cycle)
////			{
////				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
////			}
//			
//			message = data;
//			//message = message.substr (0, length);
//			
//			handler (message.substr (0, length));
//			
//			if (/*handler != NULL && */cycle)
//			{
//				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
//			}
//			
//			if (! cycle)
//			{
//				handlers.unset (hash);
//			}
//			
//			///
//			
////			std::cout << "Messaging.cpp: Listening..." << std::endl;
////			std::string message;
////
////			//boost::asio::io_service io;
////			// boost::asio::ip::udp::socket socket;
////			//boost::asio::ip::udp::socket socket (io);
////			// cancel_udp ();
////
////			// socket_udp_receive = new boost::asio::ip::udp::socket (io);
////			boost::asio::ip::udp::socket socket (io);
////			//boost::asio::ip::udp::endpoint sender_endpoint;ad
////
////			boost::asio::ip::udp::endpoint endpoint (boost::asio::ip::address::from_string (address), port);
////
////			socket.open (endpoint.protocol ());
////			socket.set_option (boost::asio::ip::udp::socket::reuse_address (true));
////
////			if (! multicast_group_listen.empty ())
////			{
////				// Join the multicast group.
////				socket.set_option (boost::asio::ip::multicast::join_group (boost::asio::ip::address::from_string (multicast_group_listen)));
////			}
////			
////			socket.bind (endpoint);
////			
////			//
////			//socket_udp_receive -> connect (,);
////			//unsigned long long int available = 5;
////				///*available */= socket_udp_receive -> available ();	// This time may not work, returning 0.
////
////			//char * data = new char [available];
////			//char data [MESSAGE_SIZE];
////			//char * data = new char [message_size];
////			char data [message_size];
////
////			//size_t len = socket.receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
////			//mathematics::numbers::natural len = socket_udp_receive -> receive_from (boost::asio::buffer (data, message_size), sender_endpoint);
////			mathematics::numbers::natural len = socket.receive_from (boost::asio::buffer (data, message_size), endpoint);
////
////			if (/*handler != NULL && */cycle)
////			{
////				handlers [hash] = new boost::thread (boost::bind (& LIB::network::ip::mpi::listen_async_handler, this, handler, address, port, cycle, hash));
////				//handlers [hash] = t;
////				//(* handler) (message);
////			}
////			//socket_udp_receive -> receive_from (boost::asio::buffer (data, available), sender_endpoint);
////			// socket_udp_receive -> receive_from (boost::asio::buffer (data, available), listen_endpoint);
////			//socket_udp_receive ->
////			message = data;
////			//delete [] data;
////
////			//delete socket;
////			//socket = NULL;
////
////			std::cout << "Messaging.cpp: Listened: [" << message.substr (0, len) << "]" << std::endl;
////
////			//handler (listen (broadcast_address, port, handler, cycle, hash));
////			
////			std::cout << "Messaging.cpp: Listened: Calling handler: handler (message.substr (0, len))" << std::endl;
////				handler (message.substr (0, len));
////
////			if (! cycle)
////			{
////				handlers.unset (hash);
////			}
////
////			//return message.substr (0, len);
////			//return message.substr (0, available);
//		}
//		catch (std::exception & e)
//		{
//			//error = e;
//			//std::cout << "Error: Listening." << std::endl;
//			std::cout << "Messaging.cpp (std::exception & e): \'Listen_async_handler\': Error: " << e.what () << std::endl;
//			//return e.what();
//			//return "";
//		}
//		catch (...) //(std::exception & e)
//		{
//			//error = e;
//			//std::cout << "Error: Listening." << std::endl;
//			std::cout << "Messaging.cpp (...): \'Listen_async_handler\': Error." << std::endl;
//			//return e.what();
//			//return "";
//		}
//	}
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler)
//{
//	return listen_async_stop (handler, udp_listen.address, udp_listen.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address)
//{
//	return listen_async_stop (handler, address, udp_listen.port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port)
//{
//	return listen_async_stop (handler, udp_listen.address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle)
//{
//	return listen_async_stop (handler, udp_listen.address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port)
//{
//	return listen_async_stop (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address)
//{
//	return listen_async_stop (handler, address, port, DEFAULT_CYCLE);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle)
//{
//	return listen_async_stop (handler, address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle)
//{
//	return listen_async_stop (handler, udp_listen.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address)
//{
//	return listen_async_stop (handler, address, udp_listen.port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port)
//{
//	return listen_async_stop (handler, udp_listen.address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool & cycle)
////bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const unsigned short int & port, const bool cycle)
//{
//	//if (handler != NULL)
//	//{
//		//unsigned long int version = 4;
//		unsigned long int hash = 0;
//		
//		//boost::hash_combine <const boost::function <void (std::string)> &> (hash, handler);
//		//boost::hash_combine <unsigned short int> (hash, version);
//		boost::hash_combine <ip::protocol> (hash, ip::protocol::udp);
//		boost::hash_combine <const std::string &> (hash, address);
//		boost::hash_combine <const unsigned short int &> (hash, port);
//		//boost::hash_combine <const bool> (hash, cycle);
//		
//		if (! handlers.exist (hash))
//			return true;
//		
//		try
//		{
//			delete handlers [hash];
//		}
//		catch (...)
//		{
//			return false;
//		}
//		
//		handlers.unset (hash);
//	//}
//	
//	return true;
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const std::string & address, const bool & cycle, const unsigned short int & port)
//{
//	return listen_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const std::string & address, const bool & cycle)
//{
//	return listen_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const unsigned short int & port, const bool & cycle, const std::string & address)
//{
//	return listen_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const std::string & address, const unsigned short int & port)
//{
//	return listen_async_stop (handler, address, port, cycle);
//}
//
//bool LIB::network::ip::mpi::listen_async_stop (const boost::function <void (std::string)> & handler, const bool & cycle, const unsigned short int & port, const std::string & address)
//{
//	return listen_async_stop (handler, address, port, cycle);
//}


/*
std::exception LIB::Network::mpi::Error (void)
{
	return error;
}
*/
/*
LIB::network::ip::messaging::address::address (void)
{
	refresh ();
}

bool LIB::network::ip::messaging::address::refresh (void)
{
	_value = LIB::network::ip::ip::address ();

	return true;
}

std::string LIB::network::ip::messaging::address::value (void)
{
	return _value;
}
*/
//#endif MESSAGING_CPP
