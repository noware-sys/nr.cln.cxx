//#include <Poco/any.h>
#include <string>
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

// #include <cln/cln.h>

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

//#include <noware/array>
//#include <noware/var>
//#include <noware/machine>
//#include <noware/container/entity.h++>

//////#include <noware/containers/entity.h++>
////#include <noware/containers/variable-undefine.h++>
//#include <noware/math.h++>
//#include <noware/serialization.h++>

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

#include "test.hxx"

int main (int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "argument count [" << argc << ']' << std::endl;
	
	
	std::string selection;
	//noware::array <std::string, int> dam;	// Direct Access Memory.
	
	do
	{
		std::cout << std::endl;
		std::cout << "Call:" << std::endl;
		std::cout << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "  " << " 0. Exit" << std::endl;
		std::cout << "  " << "!0. Test" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Selection: ";
		getline (std::cin, selection);
		//std::cout << std::endl;
		
		if (selection == "0")
		{
			//return EXIT_SUCCESS;
			break;
		}
		else //if (selection != 0)
		{
			test ();
		}
	}
	//while (selection != 0);
	while (true);
	
	//return EXIT_SUCCESS;
}
