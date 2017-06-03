//#include <Poco/any.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>	// For for_each ()
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

#include <noware/containers/array.h++>
//#include <noware/containers/entity.h++>

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

//void display_array (const noware::array <unsigned short int, unsigned short int> &);

void display_array (const noware::array <unsigned short int, unsigned short int> & arr)
{
	std::cout << "Array contains:" << std::endl;
	
	for (const noware::array <unsigned short int, unsigned short int>::package & element : arr)
	{
		std::cout << "Array [" << element.k << "] = [" << element.v << ']' << std::endl;
	}
}

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
	
	
	//std::list <unsigned short int> lst;
	
	//lst.push_back (1);
	//lst.push_back (2);
	//lst.push_back (3);
	
	//for (std::list <unsigned short int>::const_iterator iterator = lst.begin(), end = lst.end(); iterator != end; ++ iterator)
	//{
	//	cout << * iterator << endl;
	//}
	
	//for (const unsigned int & element : lst)
	//{
	//	cout << element << endl;
	//}
	
	//return EXIT_SUCCESS;
	
	noware::array <unsigned short int, unsigned short int> arr1;
	
	
	arr1.append (10);
	arr1.append (20);
	arr1.append (30);
	
	display_array (arr1);
	
	return EXIT_SUCCESS;
	
	arr1.clear ();
	
	arr1 [1] = 1;
	arr1 [3] = 3;
	
	if (arr1.add (2))
	{
		display_array (arr1);
		
		arr1.dequeue ();
		arr1.dequeue ();
		
		cout << endl;
		
		display_array (arr1);
	}
	else
	{
		cout << "Failed to dequeue..." << endl;
	}
}

