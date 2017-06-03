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
//#include <noware/containers/array.h++>
//#include <noware/entity_2.h++>
#include <noware/containers/variable.h++>
//#include <noware/memory.h++>
//#include <noware/network/ip.h++>
#include <noware/network/mpi.h++>

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

//void display (const noware::containers::array <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> &);

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
	
	noware::containers::entity <> networks, remote_endpoint, dummy_address;
	noware::containers::variable message;
	noware::containers::variable option;
	noware::network::ip::mpi mpi;
	
	//message = "MESSAGE";
	
	if (argc < 2)
	{
		goto usage;
	}
	
	option = argv [1];
	
	if (option == "broadcast")
	{
		if (argc < 3)
		{
			goto usage;
		}
		else if (argc < 4)
		{
			message = argv [2];
			
			if (! mpi.broadcast (message.to_string (), false))
					cout << "Not ";
			cout << "Broadcasted" << endl;
		}
		else if (argc >= 4)
		{
			message = argv [2];
			
			for (unsigned short int i = 3; i < argc ; ++ i)
			{
				networks ["networks"] [i] ["address"] = argv [i];
			}
			
			if (! mpi.broadcast (message.to_string (), networks, false))
					cout << "Not ";
			cout << "Broadcasted" << endl;
		}
	}
	else if (option == "listen")
	{
		cout << "Listening..." << endl;
		cout << mpi.receive (remote_endpoint, dummy_address, false) << endl;
		cout << "Received from [" << remote_endpoint ["address"] << ':' << remote_endpoint ["port"] << ']' << endl;
		
	}
	
	//display (noware::network::ip::addresses ());
	//cout << noware::network::ip::addresses () << endl;
	
	//boost::asio::ip::address_v4::
	//boost::asio::ip::address::
	
	return EXIT_SUCCESS;
	
	usage:
	
	cout << "Usage: '" << argv [0] << '\'' << "(broadcast|listen) ['message'] [network [...]]" << endl;
	
	return EXIT_FAILURE;
}
/*
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
*/