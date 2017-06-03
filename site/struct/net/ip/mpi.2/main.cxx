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

//#include <noware/all.h++>
//#include <noware/all-undefine.h++>

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

signed int main (const unsigned long long int argc, const char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using namespace noware;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	
	cout << "Argument count: " << argc << endl;
	
	
	{
		noware::any arg, option;
		//machine::devices::memory _memory;
		noware::net/*::ip*/::mpi mpi;
		std::string key, val;
		std::string msg, host;
		//int option;
		//noware::math::number::natural nr;
		
		
		//(mpi.connections [(unsigned int) 1]) -> tcp_port (5555);
		//(mpi.connections [(unsigned int) 1]) -> udp_port (4444);
		//mmpi.udp.address = "229.255.1.1";
		
		// _memory.mpi_.tcp_port (77);	//12
		// _memory.mpi_.udp_port (66);	//13
		//_memory.mpi_.tcp_receive.address = "229.255.0.1";
		//_memory.mpi_.udp.address = "229.255.0.1";
		// mmpi.multicast_group_listen = "229.255.0.1";
		// mmpi.multicast_group_broadcast = "229.255.0.1";
	
		//cout << typeid ("String.").name () << endl;
	
		if (argc > 1)
		{
			arg = argv [1];
			
			if
			(
				arg == "addr" || arg == "address" || arg == "addresses" ||
				arg == "net" || arg == "network" || arg == "networks" ||
				arg == "dev" || arg == "device" || arg == "devices"
			)
			{
				//cout << "Getting network devices:" << endl;
			
				// noware::math::number::natural nr;
				noware::array <noware::net::ip::address, noware::math::number::natural> addrs;
				
				//addrs.tolerant = false;
				//n = addrs.size ();
				//addrs.clear ();
				
				addrs = noware::net::ip::addresses ();
				
				// nr = addrs.size ();
				//std::string s;
				
				//for (noware::mathematics::numbers::natural i = 0; i < n; ++ i)
				for (auto & i : addrs)
				{
					// std::cout << i << ". " << addrs [i].to_string () << std::endl;
					std::cout << i.k << ". " << i.v.to_string () << std::endl;
					
	//				std::cout << i << ". ";
	//				std::cout.flush ();
	//				s = addrs [i].to_string ();
	//				std::cout << s;
	//				std::cout.flush ();
	//				std::cout << std::endl;
				}
				
				//cout << "Exiting successfully." << endl;
				return EXIT_SUCCESS;
			}
			/*
			else
			{
				// _memory.network_device = arg;
				// _memory.refresh_local_address ();
				
				//_memory.mpi_.tcp_receive.address = _memory.get_local_address ();
				// _memory.mpi_.udp_listen.address = _memory.get_local_address ();
				// _memory.mpi_.multicast_group ("229.1.1.1");
				
				//mmpi.tcp_receive.address = _memory.get_local_address ();
				// mmpi.udp_listen.address = _memory.get_local_address ();
				// mmpi.multicast_group ("229.255.0.1");
			}
			*/
		}
		
		// _memory.start ();
		noware::entity <> endpt;	// Endpoint.
		
		while (true)
		{
			cout << "Option (Exit: 0 / Transmit: 1 / Receive: 2 / Broadcast: 3 / Listen: 4): ";
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
			/*else if (option == 2)
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
			*/
			else if (option == 1)
			{
				cout << "Host: ";
				cin >> addr;
				
				cout << "Message to Transmit: ";
				cin >> msg;
				
				cout << "Message ";
				
				
				endpt ["address"] = addr;
				
				if (!mpi.transmit (msg, endpt))
				//if (!mpi.transmit (msg, endpt))
				{
					cout << "not ";
				}
				
				cout << "sent.";
				cout << endl;
			}
			else if (option == 2)
			{
				cout << "Received Message: ";
				cout << mpi.receive () << endl;
			}
			else if (option == 3)
			{
				cout << "Message to Broadcast: ";
				cin >> msg;
				
				cout << "Message ";
				
				if (!mpi.broadcast (msg))
					cout << "not ";
				
				cout << "broadcasted.";
				cout << endl;
			}
			else if (option == 4)
			{
				cout << "Broadcasted Message: ";
				cout << mpi.listen () << endl;
			}
		}
	}
	
	//LIB::network::messaging::interface mpi;
	
	//noware::tools::pause ("Press [Enter] to continue");
	noware::tool::pause ();
	
	return EXIT_SUCCESS;
}

