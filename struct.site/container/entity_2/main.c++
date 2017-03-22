//#include <Poco/any.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>	// For for_each ()
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
#include <noware/array.h++>
#include <noware/entity_2.h++>
#include <noware/variable.h++>
#include <noware/memory.h++>

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

void display (const noware::entity_2 &);

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
	noware::array <> arr1;
	//noware::containers::array <> arr2;
	//noware::array <variable, variable> arr3;
	noware::entity_2 ntt (NULL, entity_2::default_name, memory::default_group, "/srv/public/adminer/test-1.db");
	noware::variable option;
	noware::memory::value value_1, value_2;
	
	do
	{
		if (option == "")
		{
			cout << "[.] Refresh" << endl;
			cout << "[..] Previous" << endl;
			cout << "[0] Exit" << endl;
			cout << "[+] Add" << endl;
			cout << "[+=] Append" << endl;
			cout << "[<] Push" << endl;
			cout << "[>] Pop" << endl;
			cout << "[<+] Enqueue" << endl;
			cout << "[<-] Dequeue" << endl;
			cout << "[?] Exists" << endl;
			cout << "[*] Size" << endl;
			cout << "[_] Min" << endl;
			cout << "[^] Max" << endl;
			cout << "[=] Set" << endl;
			cout << "[-] Unset" << endl;
			cout << "[,] Rename" << endl;
			cout << "[/] Clear" << endl;
			cout << endl;
			display (ntt);
			cout << endl;
			
			cout << "Enter an option: ";
			getline (cin, option);
		}
		else if (option == '.')
		{
			option = "";
		}
		else if (option == "..")
		{
			option = "";
		}
		else if (option == '+')
		{
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tValue: ";
				getline (cin, value_1);
			//}
			//while (option);
			if (ntt.add (value_1))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == "+=")
		{
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tValue: ";
				getline (cin, value_1);
			//}
			//while (option);
			if (ntt.append (value_1))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == '<')
		{
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tValue: ";
				getline (cin, value_1);
			//}
			//while (option);
			if (ntt.push (value_1))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == '>')
		{
			//do
			//{
				//cout << "\t[C] Cancel" << endl;
				//cout << "\tValue: " << endl;
				//getline (cin, value_1);
			//}
			//while (option);
			if (ntt.pop ())
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == "<+")
		{
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tValue: ";
				getline (cin, value_1);
			//}
			//while (option);
			if (ntt.enqueue (value_1))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == "<-")
		{
			/*
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tValue: ";
				getline (cin, value_1);
			//}
			//while (option);
			*/
			if (ntt.dequeue ())
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == ',')
		{
			value_1 = value_2 = "";
			
			cout << "\tKey: Current: ";
			getline (cin, value_1);
			cout << "\tKey:     New: ";
			getline (cin, value_2);
			
			if (ntt.rename (value_1, value_2))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (option == '*')
		{
			cout << "\t" << ntt.size () << endl;
			option = "";
		}
		else if (option == '_')
		{
			cout << "\t" << ntt.key_integral_min () << endl;
			option = "";
		}
		else if (option == '^')
		{
			cout << "\t" << ntt.key_integral_max () << endl;
			option = "";
		}
		else if (option == '?')
		{
			//do
			//{
				value_1 = "";
				//cout << "\t[C] Cancel" << endl;
				cout << "\tKey: ";
				getline (cin, value_1);
			//}
			//while (option);
			if (ntt.exists (value_1))
			{
				cout << "\tPresent." << endl;
			}
			else
			{
				cout << "\tAbsent." << endl;
			}
			option = "";
		}
		else if (option == '-')
		{
			value_1 = "";
			
			cout << "\tKey: ";
			getline (cin, value_1);
			
			if (ntt.unset (value_1))
			{
				cout << "\tSucceeded." << endl;
			}
			else
			{
				cout << "\tFailed." << endl;
			}
			option = "";
		}
		else if (/*option != ""*//* && option != 0*//* && */ntt.exists (option))
		{
			//ntt = ntt [];
			display (ntt [option]);
			option = "";
		}
		//else
		//{
		//	option = "";
		//}
		
		cout << endl;
	}
	while (option != 0);
}

void display (const noware::entity_2 & ntt)
{
	//std::cout << "Entity contains:" << std::endl;
	ntt.refresh_list ();
	
	for (const noware::containers::array <noware::containers::entity_2 *, noware::containers::memory::key>::package & element : ntt)
	{
		//if (element.v.is_content_literal ())
		//{
		//	std::cout << '  [' << element.v << ']' << std::endl;
		//}
		//else
		//{
			std::cout << '[' << element.k << ']' << " > " << '[' << element.v -> get () << ']' << std::endl;
		//}
	}
}
