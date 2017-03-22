//#include <Poco/any.h>
#include <iostream>
//#include <string>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
/*
#include <omp.h>
#include <unordered_map>
#include <typeinfo>
#include <list>

// Boost:
#include <boost/any.hpp>
#include <boost/thread.hpp>
// Boost serialization:
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_member.hpp>	// For separating reading and writing.
#include <boost/serialization/list.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

//#include <string>
//#include <stack>
*/
#include <noware/mathematics.h++>
#include <noware/containers/array.h++>
//#include <noware/entity_2.h++>
//#include <noware/variable.h++>
//#include <noware/memory.h++>
#include <noware/network/ip.h++>

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

void display (const noware::containers::array <std::string, LIB::mathematics::numbers::natural> &);

signed int main (unsigned int argc, char * argv [])
{
	//using boost::any_cast;
	using namespace std;
	using namespace noware;
	
	for (unsigned int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	
	cout << "Argument count: " << argc << endl;
	cout << endl;
	
	
	//return EXIT_SUCCESS;
	
	display (noware::network::ip::networks ());
	//cout << noware::network::ip::addresses () << endl;
}

void display (const noware::containers::array <std::string, LIB::mathematics::numbers::natural> & elements)
{
	//std::cout << "Entity contains:" << std::endl;
	//ntt.refresh_list ();
	
	for (const noware::containers::array <std::string, LIB::mathematics::numbers::natural>::container & element : elements)
	{
		std::cout << '[' << element.k << ']' << ' ' << '[' << element.v << ']' << std::endl;
	}
}
