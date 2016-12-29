//#include <Poco/any.h>
#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
//#include <omp.h>
//#include <unordered_map>
//#include <typeinfo>
//#include <list>
//#include <string>
//#include <stack>

#include <cln/cln.h>

//
//// Boost:
//#include <boost/any.hpp>
//#include <boost/thread.hpp>
//// Boost serialization:
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/split_member.hpp>	// For separating reading and writing.
//#include <boost/serialization/list.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
////#include <boost/archive/binary_oarchive.hpp>
////#include <boost/archive/binary_iarchive.hpp>

#include <noware/containers/variable.h++>
//#include <noware/variable.h++>
////#include <noware/containers/entity.h++>
//#include <noware/containers/variable-undefine.h++>
#include <noware/tools.h++>

//#include <noware/containers/text.h++>
//#include <noware/containers/any.hpp>
//#include <NoWare/Container/Variable.h>
//#include <noware/containers/array.hpp>
//#include <NoWare/Containers/Dynamic.h>
//#include <NoWare/Containers/Dynamic.cpp>
//#include "MPI.h"
//#include <noware/cluster.h++>
//#include "Memory.h"
//#include "HPC.cpp"
//#include "Numerical Strings.h"
//#include <vector>
//struct My
//{
//	int x, y;
//};

int main (unsigned long long int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using namespace noware;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	std::cout << "Minimum Number: " << noware::tools::random_number_generator.min () << std::endl;
	std::cout << "Maximum Number: " << noware::tools::random_number_generator.max () << std::endl;
	
	//cln::
	//cln::default_float_format.float_format_t = cln::float_format_t.float_format_dfloat;
	//cln::default_print_flags.default_float_format = cln::float_format_t::float_format_sfloat;
	//cln::default_print_flags.default_float_format = cln::float_format (9);
	
	
	noware::numbers::natural test = ULLONG_MAX;
	//cln::cln_R r1, r2;
	
	std::cout << "ULLONG_MAX     = " << ULLONG_MAX << std::endl;
	std::cout << "ULLONG_MAX + 1 = " << ULLONG_MAX + 1 << std::endl;
	test = test * 2;
	std::cout << "ULLONG_MAX * 2 = " << test << std::endl;
	
	std::cout << "Real-Float Test : [" << cln::cl_float (cln::cl_R ("537590831/4294967296"), cln::float_format (32)) << ']' << " (0.12516761920414865016937255859375)"<< std::endl;
	
	noware::containers::variable count;
	
	//count = argc >= 2 ? argv [1] : 5;
	if (argc >= 2)
		count = argv [1];
	else
		count = 5;
	
	if (! count.is_numeric () || count < 0)
		return EXIT_FAILURE;
	
	if (argc >= 4)
	{
		noware::containers::variable minimum, maximum;

		minimum = argv [3];
		maximum = argv [2];

		if (! maximum.is_numeric () || ! minimum.is_numeric ())
			return EXIT_FAILURE;
		
		while (count > 0)
		{
			std::cout << cln::cl_float (noware::tools::random (maximum, minimum), cln::float_format (3)) << std::endl;

			-- count;
		}
	}
	else if (argc >= 3)
	{
		noware::containers::variable minimum, maximum;
		
		//minimum = argv [3];
		maximum = argv [2];
		
		if (! maximum.is_numeric ())
			return EXIT_FAILURE;
		
		while (count > 0)
		{
			std::cout << cln::cl_float (noware::tools::random (maximum), cln::float_format (3)) << std::endl;
			
			-- count;
		}
	}
	else
	{
		while (count > 0)
		{
			std::cout << noware::tools::random () << std::endl;
			
			-- count;
		}
	}
	//std::cout << std::endl;
}
