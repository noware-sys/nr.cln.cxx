#pragma once

namespace noware
{
	namespace communication
	{
		class qbit
		{
			public:
				qbit (void);
				//~qbit (void);
				
				const bool entangle (const qbit &/* other*/);
				const bool detangle (void);
				
				const bool entangled (void) const;
				const bool entangled (const qbit &/* other*/) const;
				
				const bool & get (void) const;
				operator const bool & (void) const;
				
				const bool read (const bool &/* reading*/ = true);
			protected:
				//static
				bool _state;
				const bool state (void) const;
				const bool random_state (bool) const;
				bool being_read;
				qbit * other;
		};
	}
	
	typedef communication::qbit qbit;
}
