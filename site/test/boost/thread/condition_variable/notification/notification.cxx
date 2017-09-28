#pragma once

#include "notification.hxx"

const unsigned int notification::delay = 3;

notification::notification (void)
{
	_wait = new boost::thread (boost::bind (boost::mem_fn (&notification::wait), this));
	_notification = new boost::thread (boost::bind (boost::mem_fn (&notification::notify), this, delay));
}

notification::~notification (void)
{
	_wait -> interrupt ();
	_wait -> join ();
	delete _wait;
	
	_notification -> interrupt ();
	_notification -> join ();
	delete _notification;
}

const bool notification::wait (void)
{
	boost::unique_lock <boost::mutex> lock (_mutex);
	
	while (true)
	{
		//boost::this_thread::sleep_for (boost::chrono::seconds (delay_));
		std::cerr << "notification::wait()::_condition.wait()ing" << std::endl;
		_condition.wait (lock);
		std::cerr << "notification::wait()::_condition.wait()ed" << std::endl;
	}
}

const bool notification::notify (const unsigned int & delay_)
{
	while (true)
	{
		std::cerr << "notification::notify()::sleep()ing for " << delay_ << " seconds" << std::endl;
		boost::this_thread::sleep_for (boost::chrono::seconds (delay_));
		std::cerr << "notification::notify()::sleep()pt for " << delay_ << " seconds" << std::endl;
		
		std::cerr << "notification::notify()::notify_all()ing" << std::endl;
		_condition.notify_all ();
		std::cerr << "notification::notify()::notify_all()ed" << std::endl;
	}
}
