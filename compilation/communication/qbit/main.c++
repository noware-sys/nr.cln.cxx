#include "qbit.h++"
#include <noware/containers/variable.h++>

void report (const noware::var & total, const noware::var & positive, const noware::var & negative)
{
	std::cout << "Total:\t" << total;
	std::cout << "Positive:\t" << positive;
	std::cout << "Negative:\t" << negative;
}

int main (int argc, char * argv [])
{
	using namespace std;
	using namespace noware;
	
	qbit qb;
	
	var total = argc > 1 ? argv [1] : 3;
	
	if (! total.is_numeric ())
	{
		return EXIT_FAILURE;
	}
	
	var positive, negative;
	
	
	for (var i; i < total; ++ i)
	{
		if (qb.get ())
			++ positive;
		else
			++ negative;
	}
	
	report (total, positive, negative);
}
