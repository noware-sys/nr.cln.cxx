#include "transmission.h++"

LIB::communication::transmission::transmission (void)
{
	data = "";
	terminator = NULL;
}

LIB::communication::transmission::~transmission (void)
{
	if (terminator != NULL)
	{
		delete terminator;
		//terminator = NULL;
	}
	
	lock.unlock ();
}

void LIB::communication::transmission::terminate (LIB::NAME_A <transmission, LIB::mathematics::numbers::natural> & transmissions, const LIB::mathematics::numbers::natural & key, const LIB::mathematics::numbers::natural & timeout/* total*/) const
{
	boost::asio::io_service io;
	boost::asio::deadline_timer timer (io);
	
	//io.reset ();
	
	timer.expires_from_now (boost::posix_time::milliseconds (timeout));
	//timer.async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
	
	io.run ();
	
	timer.wait ();
	
	if (transmissions.exists (key))
	{
		transmissions [key].lock.unlock ();
	}
}
