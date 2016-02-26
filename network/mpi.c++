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

static const bool LIB::network::mpi::default_cycle;

LIB::network::mpi::mpi (void)
{
	//_connections [1] = new LIB::network::ip::mpi ();
	//_connections.add (new LIB::network::ip::mpi ());
	_connections ["ip"] = new LIB::network::ip::mpi ();
}

LIB::network::mpi::~mpi (void)
{
	stop ();
	
	for (auto & element : _connections)
	{
		//try
		//{
			//if (element.v != NULL)
			//{
				//delete * (element.val);
				delete element.v;
			//}
		//}
		//catch (...)
		//{
		//}
		
	}
	
	_connections.clear ();
}

//void /*const LIB::communication::message & */prepare (/*const */LIB::communication::message &/* message*/)
//{
//}

//const bool LIB::network::mpi::transmit (const std::string & message)
//{
//	return transmit (message, transmission.reliable);
//}

const bool LIB::network::mpi::transmit (const std::string & message, LIB::container::NTT <> address, const bool & _reliable)
{
	// Using logical OR.
	
	bool success = false;
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if (element.v -> transmit (message, address, _reliable) && ! success)
		{
			success = true;
		}
	}
	
	return success;
}
/*
const bool LIB::network::mpi::broadcast (const std::string & message)
{
	// Using logical OR.
	
	bool success = false;
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if (element.v -> broadcast (message) && !success)
		{
			success = true;
		}
	}
	
	return success;
}
*/
const bool LIB::network::mpi::broadcast (const std::string & message, LIB::container::NTT <> addresses, const bool & _reliable)
{
	// Using logical OR.
	
	bool success = false;
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if (element.v -> broadcast (message, addresses, _reliable) && !success)
		{
			success = true;
		}
	}
	
	return success;
}
/*
const std::string LIB::network::mpi::receive (void)
{
	// Using logical OR.
	
	//bool success = false;
	std::string current = "", previous = "";
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if ((current = element.v -> receive ()) != previous)
		{
			return current;
		}
	}
	
	return current;
}
*/
const std::string LIB::network::mpi::receive (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address, const bool & _reliable)
{
	// Using logical OR.
	
	std::string current = ""/*, previous = ""*/;
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if ((current = element.v -> receive (remote_endpoint, address, _reliable)) != /*previous*/"")
		{
			return current;
		}
	}
	
	return current;
}
/*
const std::string LIB::network::mpi::listen (void)
{
	// Using logical OR.
	// To be refined!: First one (current) Versus All at once (to be done).
	
	std::string current = "", previous = "";
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if ((current = element.v -> listen ()) != previous)
		{
			return current;
		}
	}
	
	return current;
}

const std::string LIB::network::mpi::listen (LIB::container::NTT <> & remote_endpoint, LIB::container::NTT <> address)
{
	// Using logical OR.
	// To be refined!: First one (current) Versus All at once (to be done).
	
	std::string current = "", previous = "";
	
	for (auto & element : _connections)
	{
		//new boost::thread (boost::bind (& (element.v -> transmit), this, message, address));
		if ((current = element.v -> listen (remote_endpoint, address)) != previous)
		{
			return current;
		}
	}
	
	return current;
}
*/
void LIB::network::mpi::stop (void)
{
	for (auto & element : handlers)
	{
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
}

// Receive asynchronously.
const bool LIB::network::mpi::receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler)
{
	return receive_async (handler, reception.reliable, default_cycle);
}

const bool LIB::network::mpi::receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, LIB::container::NTT <> & address)
{
	return receive_async (handler, address, default_cycle);
}

const bool LIB::network::mpi::receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const bool & cycle)
{
	return receive_async (handler, reception.reliable, cycle);
}

const bool LIB::network::mpi::receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, LIB::container::NTT <> & address, const bool & cycle)
{
	unsigned long int hash = 0;
	
	boost::hash_combine <communication> (hash, communication::single);
	boost::hash_combine <const std::string &> (hash, address ().to_string ());
	
	if (handlers.exist (hash))
		return true;
	
	handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, handler, address, cycle, hash));
	
	//return handlers.exists (hash);
	return true;
}

const bool LIB::network::mpi::receive_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const bool & cycle, LIB::container::NTT <> & address)
{
	return receive_async (handler, address, cycle);
}

// Stop receiving asynchronously.
const bool LIB::network::mpi::receive_async_stop (void)
{
	return receive_async_stop (reception.reliable);
}

const bool LIB::network::mpi::receive_async_stop (const LIB::container::NTT <> & address)
{
	//if (handler != NULL)
	//{
		unsigned long int hash = 0;
		
		boost::hash_combine <communication> (hash, communication::single);
		boost::hash_combine <const std::string &> (hash, address ().to_string ());
		
		
		if (! handlers.exist (hash))
		{
			return true;
		}
		
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

// Listen asynchronously.
const bool LIB::network::mpi::listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler)
{
	return listen_async (handler, reception.unreliable, default_cycle);
}

const bool LIB::network::mpi::listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const LIB::container::NTT <> & address)
{
	return listen_async (handler, address, default_cycle);
}

const bool LIB::network::mpi::listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const bool & cycle)
{
	return listen_async (handler, reception.unreliable, cycle);
}

const bool LIB::network::mpi::listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const LIB::container::NTT <> & address, const bool & cycle)
{
	unsigned long int hash = 0;
	
	boost::hash_combine <communication> (hash, communication::multiple);
	boost::hash_combine <const std::string &> (hash, address ().to_string ());
	
	if (handlers.exist (hash))
		return true;
	
	handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, cycle, hash));
	
	//return handlers.exists (hash);
	return true;
}

const bool LIB::network::mpi::listen_async (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, const bool & cycle, const LIB::container::NTT <> & address)
{
	return listen_async (handler, address, cycle);
}

// Stop listening asynchronously.
const bool LIB::network::mpi::listen_async_stop (void)
{
	return listen_async_stop (reception.unreliable);
}

const bool LIB::network::mpi::listen_async_stop (const LIB::container::NTT <> & address)
{
	//if (handler != NULL)
	//{
		unsigned long int hash = 0;
		
		boost::hash_combine <communication> (hash, communication::multiple);
		boost::hash_combine <const std::string &> (hash, address ().to_string ());
		
		
		if (! handlers.exist (hash))
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

void LIB::network::mpi::receive_async_handler (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, LIB::container::NTT <> & address, const bool & cycle, const unsigned long int & hash)
{
	if (handler != NULL)
	{
		LIB::container::NTT <> endpoint;
		
		handler (endpoint, receive (endpoint, address, true));
		
		if (cycle)
		{
			handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::receive_async_handler, this, handler, address, cycle, hash));
		}
		else
		//if (! cycle)
		{
			handlers.unset (hash);
		}
	}
}

void LIB::network::mpi::listen_async_handler (const boost::function <void (const LIB::container::NTT <> &, const std::string &)> & handler, LIB::container::NTT <> & address, const bool & cycle, const unsigned long int & hash)
{
	if (handler != NULL)
	{
		LIB::container::NTT <> endpoint;
		
		//handler (endpoint, listen (endpoint, address));
		handler (endpoint, receive (endpoint, address, false));
		
		if (cycle)
		{
			handlers [hash] = new boost::thread (boost::bind (& LIB::network::mpi::listen_async_handler, this, handler, address, cycle, hash));
		}
		else
		//if (! cycle)
		{
			handlers.unset (hash);
		}
	}
}

//const LIB::container::NAME_A <LIB::network::connection *, unsigned short int> & LIB::network::mpi::connections (void) const
const LIB::container::NAME_A <LIB::network::_mpi */*, unsigned short int*/> & LIB::network::mpi::connections (void) const
{
	return _connections;
}
