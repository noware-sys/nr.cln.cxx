#ifndef THREADS
#define THREADS

//#include <string>
#include <stddef.h>	// For NULL
#include <cstdarg>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
//#include <boost/date_time/posix_time/posix_time.hpp>

//#include "noware/default.hpp"
//#include "noware/containers/array.hpp"

//#include "mathematics.hpp"

namespace LIB
{
	//typedef void (* function) (int, ...);
	//typedef void (* fn) (int, ...);
	//typedef void (* function) (void);

	//LIB::mathematics::

	class threads
	{
		protected:
			//NAME_A <boost::thread *, boost::thread::id> container;

		public:
			threads (void);
			//~threads (void);
			//LIB::
			//bool add (function, ...);
			bool add (void (*) (void));
	};
}

#endif THREADS
