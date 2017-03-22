#pragma once

namespace noware
{
	namespace tool
	{
		class invocation
		{
			public:
				invocation (void);
				~invocation (void);
				
				const bool pend (fn(...), callback);
				//expire (invocation*, expiration);
				const bool expire (expiration);
				const bool expired (void) const;
			protected:
				boost::thread * callee;
				//boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> expirer;
				boost::function <void/* manage*/ (const zyre_event_t */* zyre_event*/)> expirer;	// External (for the object) event handler.
		};
	}
}
