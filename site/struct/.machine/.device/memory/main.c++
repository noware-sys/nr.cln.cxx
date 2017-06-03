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

#include <noware/machine.h++>
#include <noware/name-undefine.h++>
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

void display_array (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> &);
//void display_array (const noware::array <unsigned short int, unsigned short int> &);
/*
void display_array (const noware::array <unsigned short int, unsigned short int> & arr)
{
	std::cout << "Array contains:" << std::endl;
	
	for (const noware::array <unsigned short int, unsigned short int>::package & element : arr)
	{
		std::cout << "Array [" << element.k << "] = [" << element.v << ']' << std::endl;
	}
}
*/
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
	
	noware::machine::device::memory mem ("/srv/public/adminer/test-1.db");
	noware::container::variable o, k, v;
	
	
	cout << "Size == " << mem.size () << endl;
	
//	cout << "exists (\"Last\", \"Name\") == " << mem.exists ("Last", "Name") << endl;
//	cout << "exists (\"Name\", \"Last\") == " << mem.exists ("Name", "Last") << endl;
//	cout << "exists (\"Last\", \"\") == " << mem.exists ("Last", "") << endl;
//	cout << "exists (\"Last\") == " << mem.exists ("Last") << endl;
//	
//	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::memory::value> values;
//	
//	values ["Name: Reference"] = 1;
//	values ["Content: Reference"] = 1;
//	values ["Content"] = "AAA";
//	
//	cout << "set (\"Test 7\", \"Test 7\") == " << mem.set ("Test 7", "Test 7") << endl;
//	cout << "set (\"Test 8\", values, \"Test 8\") == " << mem.set ("Test 8", values, "Test 8") << endl;
//	cout << "set (\"Test 6\", 6) == " << mem.set ("Test 6", 6) << endl;
//	
//	LIB::containers::memory::key grp;
//	
	cout << "Sequence: Next == " << mem.sequence_next () << endl;
	cout << "Sequence: Next Available == " << mem.sequence_next_available () << endl;
//	cout << "enqueue (grp, \"Test 9\", \"Test 9: Value\") == " << mem.enqueue (grp, "Test 9", "Test 9: Value") << endl;
//	cout << "grp (9) == " << grp << endl;
//	cout << endl;
//	cout << mem.sequence_next () << endl;
//	cout << "enqueue (grp, \"Test 10\", \"Test 10: Value\") == " << mem.enqueue (grp, "Test 10", "Test 10: Value") << endl;
//	cout << "grp (10) == " << grp << endl;
//	cout << endl;
//	cout << mem.sequence_next () << endl;
//	cout << "enqueue (grp, \"Test 11\", \"Test 10: Value\") == " << mem.enqueue (grp, "Test 11", "Test 11: Value") << endl;
//	cout << "grp (11) == " << grp << endl;
	
	//display_array (mem.list ());
	mem.refresh_list ();
	for (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::package & row : mem)
	{
		for (const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>::package & column : row.v)
		{
			//// This loop should normally last for only one (1) iteration.
			std::cout << '[' << row.k << "] [" << column.k << "] [" << column.v << ']' << std::endl;
		}
//		//{
//		//	LIB::containers::memory mem (db, row.v [2], group, row.v [1]);
//		//	
//		//	entities [row.v [1]] = mem;
//		//}
	}
	
	//noware::container::variable option;
	
	while (true)
	{
		//cout << "Option (Exit: 0 / Get: 2 / Set: 3 / Listen: 5 / Receive: 6 / Broadcast: 7 / Transmit: 8): ";
		cout << "Option (Exit: 0 / List: 1 / Get: 2 / Set: 3 / Members: 4): ";
		cin >> o;

		if (o == 0)
		{
			//exit (0);
//			memory.~Memory ();
			break;
		}
		else if (o == 1)
		{
			cout << "Variables: " << endl;
			
			//mem.list ();
		}
		else if (o == 2)
		{
			cout << "Key: ";
			cin >> k;

			cout << "Value of " << k << " == ";
			
			cout << mem.get (k) << endl;
		}
		else if (o == 3)
		{
			cout << "Key: ";
			cin >> k;

			cout << "Value: ";
			cin >> v;

			cout << "\tSet: " << (memory.set (k, v) ? "OK" : "Failed");
		}
		else if (o == 4)
		{
			//cout << "Members Count: " << _memory.size () << endl;
			////memory.mpi.Send ("", "127.0.0.1");
		}
		/*else if (option == 5)
		{
			cout << "Broadcasted Message: ";
			cout << mpi.listen () << endl;
		}
		else if (option == 6)
		{
			cout << "Received Message: ";
			cout << mpi.receive () << endl;
		}
		else if (option == 7)
		{
			cout << "Message to Broadcast: ";
			cin >> msg;
			
			cout << "Message ";
			
			if (!mpi.broadcast (msg))
				cout << "not ";
			
			cout << "broadcasted.";
			cout << endl;
		}
		else if (option == 8)
		{
			cout << "Host: ";
			cin >> host;
			
			cout << "Message to Transmit: ";
			cin >> msg;
			
			cout << "Message ";
			
			
			ep ["address"] = host;
			
			if (!mpi.transmit (msg, ep))
			//if (!mpi.transmit (msg, ep))
			{
				cout << "not ";
			}
			
			cout << "sent.";
			cout << endl;
		}*/
	}
}

void display_array (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> & arr)
{
	std::cout << "array =>";
	std::cout << std::endl;
	std::cout << '[';
	
	for (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::package & row : arr)
	{
		std::cout << std::endl;
		std::cout << '\t' << '[' << row.k << "] =>";
		std::cout << std::endl;
		std::cout << '\t' << '[';
		std::cout << std::endl;
		
		for (const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>::package & column : row.v)
		{
			std::cout << "\t\t" << '[' << column.k << ']' << " => " << '[' << column.v << ']' << std::endl;
		}
		
		std::cout << '\t' << ']';
		std::cout << std::endl;
	}
	
	std::cout << ']';
	std::cout << std::endl;
}
