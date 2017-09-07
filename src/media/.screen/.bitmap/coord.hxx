#pragma once

/*
	coord[inate]
	res[olutio]n
*/
class coord
{
	public:
		coord (void);
		coord (const coord &/* other*/);
		coord (const noware::nr &/* horizontal*/, const noware::nr &/* vertical*/);
		
		virtual const coord & operator = (const coord &/* other*/);
		virtual const bool operator == (const coord &/* other*/) const;
		
		noware::nr horizontal;
		noware::nr vertical;
};
