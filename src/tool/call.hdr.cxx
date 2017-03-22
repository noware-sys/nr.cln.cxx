#pragma once

namespace noware
{
	class call
	{
		public:
			call (void);
			~call (void);
			
			const bool pend (fn(...), calback);
			//expire (call*, expiration);
			const bool expire (expiration);
			const bool expired (void) const;
		protected:
			boost::thread * callee;
			//boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> expirer;
			boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> expirer;	// External (for the object) event handler.
	}
}
