//#include <Poco/any.h>
#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
//#include <omp.h>
//#include <unordered_map>
//#include <typeinfo>
//#include <list>
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

//#include <string>
//#include <stack>

//#include <noware/containers/variable.h++>
//#include <noware/variable.h++>
////#include <noware/containers/entity.h++>
//#include <noware/containers/variable-undefine.h++>

//#include <noware/.device/prememory.h++>
//#include <noware/.device/memory.h++>
#include <noware/machine.h++>
#include <noware/name-undefine.h++>

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
	using namespace std;
	using namespace noware;
	
	for (unsigned int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	cout << "Argument count: " << argc << endl;
	
	machine::device::memory ram;
	container::variable option;
	
	while (true)
	{
		cout << "Option (Exit: 0 / Get: 2 / Set: 3 / Listen: 5 / Receive: 6 / Broadcast: 7 / Transmit: 8): ";
		cin >> option;

		if (option == 0)
		{
			//exit (0);
//			memory.~Memory ();
			break;
		}
		//else if (o == 1)
		//{
		//	cout << "Members: " << endl;
		//	
		//	//_memory.list ();
		//}
		else if (option == 2)
		{
			cout << "Key: ";
			cin >> k;

			cout << "Value of " << k << ": ";
			// cout << _memory.get (k) << endl;
		}
		else if (option == 3)
		{
			cout << "Key: ";
			cin >> k;

			cout << "Value: ";
			cin >> v;

			// _memory.set (k, v);
		}
		//else if (option == 4)
		//{
		//	//cout << "Members Count: " << _memory.size () << endl;
		//	//memory.mpi.Send ("", "127.0.0.1");
		//}
		else if (option == 5)
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
		}
	}
}
