#include "members.h++"

LIB::cluster::members::members (const LIB::mathematics::numbers::natural & ka)
{
	_active = false;
	keepalive = ka;
	
	_local = NULL;
	//local_machine = NULL;
}

LIB::cluster::members::~members (void)
{
}

const LIB::mathematics::numbers::natural LIB::cluster::members::count (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::cardinality (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::magnitude (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::size (void) const
{
	return nodes.size ();
}

const bool LIB::cluster::members::empty (void) const
{
	return nodes.empty ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator * (void)
{
	return _machines;
}

/*
const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator -> (void)
{
	return operator * ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator () (void)
{
	return operator * ();
}
*/

void LIB::cluster::members::distribute (void)
{
	LIB::communication::message message;
	//std::string message_serial;
	
	////message.content ["addresses"] = network::ip::addresses ();
	//message.content ["id"] = local;
	
	message.content ["action"] = "presence";
	message.content ["function"] = "declaration";
	message.content ["value"] = true;
	//message.content ["endpoint"] ["port"] ["tcp"] = static_cast <LIB::network::ip::mpi> (mpi -> connections ()).;
	//message.content ["endpoint"] ["udp"] = mpi -> addrs.listen;
	//message.content ["endpoint"] ["tcp"] = mpi -> addrs.receive;
	
	//message.content ["id"] = * _local;
	//message.content ["id:next"] = nodes.sequence_next ();
	//message.content ["machines"] = nodes;
	
	//LIB::NAME_V * __id = & (message.content ["id"]);
	
	// message_serial = message;
	
	//message.content.clear ();
	
	//io.reset ();
	
	while (true)
	{
		//if (/*_local != NULL && */(* __id) != (* _local))
		//{
			//(* __id) = (* _local);
			message.content ["id"] = * _local;
			message.content ["id:next"] = nodes.sequence_next ();
			message.content ["machines"] = nodes;
			message.content ["endpoint"] ["udp"] = mpi -> addrs.listen;
			message.content ["endpoint"] ["tcp"] = mpi -> addrs.receive;
			message.content ["time"] ["keepalive"] = keepalive;
			
			//message_serial = message;
		//}
		
		mpi -> broadcast (message);
		
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::milliseconds (keepalive));
	}
	
	//distribution = NULL;
}

const LIB::mathematics::numbers::natural & LIB::cluster::members::local_id (void) const
{
	if (local == NULL)
		return 0;
	else
		return * local;
}

const bool LIB::cluster::members::run (const bool & state)
{
	if (state && ! active)
	{
		// Start.
		
		if (mpi == NULL)
		{
			return false;
		}
		
		//if (! nodes [local].run (state))
		//{
		//	return false;
		//}
		
		/*
		// Get the list of (directly connected) peers.
		communication::message message;
		
		//message.content ["addresses"] = network::ip::addresses (0, false);
		message.content ["id"] = local;
		message.content ["action"] = "presence";
		message.content ["function"] = "interrogation";
		message.content ["recursive"] = false;//true;
		message.content ["machines"] = nodes;
		
		if (! mpi -> broadcast (message))
		{
			return false;
		}
		
		// Wait for all machines to respond.
		// Use the existing variables, as they are not in use now.
		io_service.reset ();
		scanning_timer.expires_from_now (boost::posix_time::microseconds (keepalive));
		io_service.run ();
		
		// Now, the list should have been, in normal conditions, populated.
		*/
		
		mathematics::numbers::natural __local;
		
		// Create the local machine.
		machine mach;
		
		mach.t = machine::type::literal;
		// Only the reference (address) is copied here.
		mach.mpi = mpi;
		mach.cluster = cluster;
		
		if (! nodes.enqueue (mach, __local))
		{
			nodes.clear ();
			
			return false;
		}
		
		// Prevent having multiple copies: refer to one copy.
		nodes [__local].id = _local = & nodes.get_key (__local);
		
		if (! nodes [__local].run ())
		{
			return false;
		}
		
		//local_machine = & nodes [__local];
		
		active = true;
		
		if (distribution == NULL)
		{
			distribution = new boost::thread (boost::bind (& LIB::cluster::members::distribute, this));
		}
		
		return true;
	}
	else if (! state && active)
	{
		// Stop.
		
		//if (! nodes [local].run (state))
		//{
		//	return false;
		//}
		nodes.clear ();
		
		//mpi = NULL;
		
		if (distribution != NULL)
		{
			try
			{
				delete distribution;
			}
			catch (...)
			{
			}
			
			distribution = NULL;
		}
		
		active = false;
		
		return true;
	}
	// There is nothing to be done.
	else
	{
		return true;
	}
	
	// Just in case.
	return false;
}

const bool & LIB::cluster::members::active (void) const
{
	return _active;
}
