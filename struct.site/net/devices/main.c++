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

void display (const noware::containers::array <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> &);

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
	
	display (noware::network::ip::addresses ());
	//cout << noware::network::ip::addresses () << endl;
}

void display (const noware::containers::array <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> & elements)
{
	//std::cout << "Entity contains:" << std::endl;
	//ntt.refresh_list ();
	
	for (const noware::containers::array <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string>::container & device : elements)
	{
		//if (element.v.is_content_literal ())
		//{
		//	std::cout << '  [' << element.v << ']' << std::endl;
		//}
		//else
		//{
		for (const LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>::container & version : device.v)
		{
			for (const LIB::containers::NAME_A <std::string, std::string>::container & attribute : version.v)
			{
				std::cout << '[' << device.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << ' ' << '[' << attribute.v << ']' << std::endl;
			}
		}
		//}
	}
}
