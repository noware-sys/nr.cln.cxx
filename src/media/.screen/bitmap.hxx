#pragma once

class bitmap
{
	public:
		#include ".bitmap/.hxx"
		
		bitmap (void);
		//virtual ~bitmap (void);
		
		// get the current value
		virtual const coord &/* current value*/ size (void) const;
		// set a new value
		virtual const bool size (const coord &/* new value*/);
		//virtual const bool size (const noware::nr &/* width*/, const noware::nr &/* height*/);
		
		std::map <noware::nr/* horizontal coordinate*/, std::map <noware::nr/* vertical coordinate*/, pixel/* value*/>> area;
		//bool visible;
	//protected:
		coord resolution;
};
