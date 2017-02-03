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

#include <noware/var>
#include <noware/net/node>
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
#include "reception"

int main (int argc, char * argv [])
{
	//using boost::any_cast;
	using namespace std;
	using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	
	noware::var selection, peer, group, message;
	noware::net::node node;
	
	do
	{
		std::cout << std::endl;
		std::cout << "Memory Storage:" << std::endl;
		std::cout << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "  " << "   ------------------" << std::endl;
		std::cout << "  " << "0. Exit" << std::endl;
		std::cout << "  " << "   ------------------" << std::endl;
		std::cout << "  " << "1. Finalize" << std::endl;
		std::cout << "  " << "2. Verify if the Node is Initialized" << std::endl;
		std::cout << "  " << "3. Initialize" << std::endl;
		std::cout << "  " << "   ------------------" << std::endl;
		std::cout << "  " << "4. Stop" << std::endl;
		std::cout << "  " << "5. Status" << std::endl;
		std::cout << "  " << "6. Start" << std::endl;
		std::cout << "  " << "   ------------------" << std::endl;
		std::cout << "  " << "7. Leave" << std::endl;
		std::cout << "  " << "8. Join" << std::endl;
		std::cout << "  " << "   ------------------" << std::endl;
		std::cout << "  " << "9. Unset Handler" << std::endl;
		std::cout << "  " << "10. Verify if a Handler is Set" << std::endl;
		std::cout << "  " << "11. Set Handler" << std::endl;
		std::cout << "  " << "    ------------------" << std::endl;
		std::cout << "  " << "12. Multicast" << std::endl;
		std::cout << "  " << "13. Unicast" << std::endl;
		std::cout << "  " << "    ------------------" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Selection: ";
		getline (std::cin, selection);
		//std::cout << std::endl;
		
		if (selection == 0)
		{
			//return EXIT_SUCCESS;
			break;
		}
		else 
		if (selection == 1)
		{
			std::cout << "  " << "Finalizing ... " << (node.finalize () ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 2)
		{
			std::cout << "  " << "Initialized ... " << (node.initialized () ? "True" : "False") << std::endl;
		}
		else if (selection == 3)
		{
			std::cout << "  " << "Initializing ... " << (node.initialize () ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 4)
		{
			std::cout << "  " << "Stopping ... " << (node.stop () ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 5)
		{
			std::cout << "  " << "Status ... " << (node.status () ? "Active" : "Inactive") << std::endl;
		}
		else if (selection == 6)
		{
			std::cout << "  " << "Starting ... " << (node.start () ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 7)
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Leaving : [" << group << "] ... " << (node.leave (group) ? "Success" : "Failure") << ']' << std::endl;
		}
		else if (selection == 8)
		{
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Joining : [" << group << "] ... " << (node.join (group) ? "Success" : "Failure") << ']' << std::endl;
		}
		else if (selection == 9)
		{
			std::cout << "  " << "Unsetting the Handler ... " << (node.reception_unset () ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 10)
		{
			std::cout << "  " << "A Handler ... " << (node.reception_is_set () ? "Is Set" : "Is Not Set") << std::endl;
		}
		else if (selection == 11)
		{
			std::cout << "  " << "Setting a Handler ... " << (node.reception_set (&receive) ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 12)
		{
			std::cout << "  " << "Message: ";
			getline (std::cin, message);
			
			std::cout << "  " << "Group: ";
			getline (std::cin, group);
			
			std::cout << "  " << "Multicasting : [" << message << "] ... " << (node.multicast (message, group) ? "Success" : "Failure") << std::endl;
		}
		else if (selection == 13)
		{
			std::cout << "  " << "Message: ";
			getline (std::cin, message);
			
			std::cout << "  " << "Peer: ";
			getline (std::cin, peer);
			
			std::cout << "  " << "Unicasting : [" << message << "] ... " << (node.unicast (message, peer) ? "Success" : "Failure") << std::endl;
		}
		else //if (selection != 0)
		{
			std::cout << "  " << "Unrecognized Selection" << std::endl;
		}
	}
	//while (selection != 0);
	while (true);
	
	return EXIT_SUCCESS;
}

