#pragma once

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class notification
{
	public:
		notification (void);
		virtual ~notification (void);
		
		const bool wait (void);
		const bool notify (const unsigned int &/* delay*/);
	protected:
		boost::condition_variable _condition;
		boost::mutex _mutex;
		boost::thread * _wait;
		boost::thread * _notification;
	public:
		static const unsigned int delay;
};
