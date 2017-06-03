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

#include <noware/array>
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

int main (int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	std::cout << std::boolalpha;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "argc==[" << argc << ']' << std::endl;
	
	
	std::string selection;
	std::string key;
	std::string value;
	
	// Random/Direct-Access Memory/Store
	noware::array <std::string, std::string> store;
	
	do
	{
		std::cout << std::endl;
		std::cout << "Array:" << std::endl;
		std::cout << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "  " << "0. Exit" << std::endl;
		std::cout << "  " << "1. Exist" << std::endl;
		std::cout << "  " << "2. Get" << std::endl;
		std::cout << "  " << "3. Set" << std::endl;
		std::cout << "  " << "4. Remove" << std::endl;
		std::cout << "  " << "5. Size" << std::endl;
		std::cout << "  " << "6. Clear" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Selection: ";
		getline (std::cin, selection);
		//std::cout << std::endl;
		
		if (selection == "0")
		{
			//return EXIT_SUCCESS;
			break;
		}
		else if (selection == "1")
		{
			std::cout << "  " << "Key: ";
			//getline (std::cin, key);
			std::cin >> key;
			
			std::cout << "  " << "Exist : [" << key << "] == " << store.exist (key) << std::endl;
		}
		else if (selection == "2")
		{
			std::cout << "  " << "Key: ";
			//getline (std::cin, key);
			std::cin >> key;
			
			std::cout << "  " << "Getting : [" << key << ']' << std::endl;
			if (store.get (key, value))
			{
				std::cout << "    " << '[' << key << ']' << " == " << '[' << value << ']' << std::endl;
			}
			else
			{
				std::cout << "    " << "Key not present" << std::endl;
			}
		}
		else if (selection == "3")
		{
			std::cout << "  " << "Key: ";
			//getline (std::cin, key);
			std::cin >> key;
			
			std::cout << "  " << "Value: ";
			//getline (std::cin, value);
			std::cin >> value;
			
			std::cout << "  " << "Setting : [" << key << "] = [" << value << "] ... " << store.set (key, value) << std::endl;
		}
		else if (selection == "4")
		{
			std::cout << "  " << "Key: ";
			//getline (std::cin, key);
			std::cin >> key;
			
			std::cout << "  " << "Removing : " << '[' << key << "] ... " << store.remove (key) << std::endl;
		}
		else if (selection == "5")
		{
			std::cout << "  " << "Size == [" << store.size () << ']' << std::endl;
		}
		else if (selection == "6")
		{
			std::cout << "  " << "Clearing ... " << store.clear () << std::endl;
		}
		else// if (selection != 0)
		{
			std::cout << "  " << "Unrecognized option" << std::endl;
		}
	}
	//while (selection != 0);
	while (true);
	
	//return EXIT_SUCCESS;
}
