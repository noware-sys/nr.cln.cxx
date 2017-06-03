//#include <Poco/any.h>

//typedef nullptr nullp;

// #include <iostream>
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

//#include <noware/math/number.h++>
//#include <noware/serial.h++>
//#include <noware/tool.h++>
//#include <noware/container/content/null.h++>

//#include <noware/container/array.h++>
//#include <noware/entity_2.h++>
#include <noware/container/any.h++>
#include <noware/net/node.h++>
#include <noware/net/cluster.h++>
//#include <noware/machine.h++>
//#include <noware/network/ip.h++>

//#include <noware/container/text.h++>
//#include <noware/container/any.hpp>
//#include <NoWare/Container/Variable.h>
//#include <noware/container/array.hpp>
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

void display (const noware::container::array <noware::net::node, noware::math::numbers::natural> &);

signed int main (unsigned int argc, char * argv [])
{
	//using boost::any_cast;
	using namespace std;
	//using namespace noware;
	
	
	//for (unsigned int i = 0; i < argc; ++ i)
	//	cout << argv [i] << ' ';
	//cout << endl;
	
	//cout << "Argument count: " << argc << endl;
	//cout << endl;
	
	
	//return EXIT_SUCCESS;
	noware::container::any option;
	noware::net::cluster cluster;
	
	do
	{
		cout << "0. Exit" << endl;
		cout << "!0. Refresh" << endl;
		cout << "Option [!0]: ";
		
		getline (cin, option);
		
		std::cout << " option == " << option << std::endl;
		std::cout << " (option == 0) == " << (option == 0) << std::endl;
		
		if (option != 0)
		{
			//members.list ();
			cout << "==========" << endl;
			cout << "Members:" << endl;
			
			display (cluster.nodes ());
			
			cout << "==========" << endl;
			cout << endl;
		}
	}
	while (option != 0);
	
	//display (noware::net::ip::addresses ());
	//cout << noware::net::ip::addresses () << endl;
	
}

void display (const noware::container::array <noware::net::node, noware::math::numbers::natural> & nodes)
{
	//std::cout << "Entity contains:" << std::endl;
	//ntt.refresh_list ();
	
	for (const noware::container::array <noware::net::node, noware::math::numbers::natural>::container & node : nodes)
	{
		std::cout << "\t" << '[' << node.k << ']' << std::endl;
		
		for (const noware::container::array <noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>, std::string>::container & address : node.v.addresses)
		{
			for (const noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>::container & version : address.v)
			{
				for (const noware::container::array <std::string, std::string>::container & attribute : version.v)
				{
					std::cout << "\t\t" << '[' << address.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << "\t" << '[' << attribute.v << ']' << std::endl;
				}
			}
		}
	}
}

