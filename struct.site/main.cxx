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

#include <noware/all.h++>
#include <noware/all-undefine.h++>
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
	using namespace std;
	using namespace noware;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	
	cout << "Argument count: " << argc << endl;
	
	
	//string s;
	/*
	noware::array <string, string>::package pack;
	pack.k = "KEY";
	pack.v = new string ("VAL");
	
	cout << "Serializing... ";
	
	s = LIB::serialize (pack);
	cout << '"' << s << '"' << endl;
	
	pack.k = "";
	* (pack.v) = "";
	
	cout << "Deserializing... " << endl;
	LIB::deserialize (s, pack);
	//LIB::deserialize ("22 serialization::archive 10 0 0 3 KES 3 VAS", pack);
	
	cout << "Deserialized:" << endl;
	cout << "Key: " << '"' << pack.k << '"' << endl;
	cout << "Value: " << '"' << * (pack.v) << '"' << endl;
	
	return EXIT_SUCCESS;
	*/
	
	/*
	std::list <int> ints;
	ints.push_back (1);
	ints.push_back (2);
	ints.push_back (3);
	
	
	cout << endl;
	cout << "\"ints\" contains:" << endl;
	for (auto i : ints)
	{
		cout << "ints \"" << i << '"' << endl;
	}
	
	cout << endl;
	cout << "Serializing...";
	s = LIB::serialize <std::list<int>> (ints);
	cout << " Done." << endl;
	cout << "Serialized: " << '"' << s << '"' << endl;
	
	cout << endl;
	cout << "Emptying...";
	ints.clear ();
	cout << " Done." << endl;
	
	cout << endl;
	cout << "Deserializing...";
	
	cout.flush ();
	
	if (LIB::deserialize <std::list<int>> (s, ints))
	{
		cout << "Deserialized \"ints\" contains:" << endl;
		for (auto i : ints)
		{
			cout << "ints \"" << i << '"' << endl;
		}
	}
	else
	{
		cout << "Could not deserialize." << endl;
	}
	
	
	return EXIT_SUCCESS;
	*/
	
	/*
	int i = 121;
	
	//std::string s;
	std::stringstream ss;
	//s = "";
	//s = *this;
	
	//ss.clear ();	// Make sure that there is nothing in the stream.
	
	
	// Put the obect's serializable members into an output stream:
	boost::archive::text_oarchive a (ss);
	a << i;
	
	// Get the string representation:
	std::getline (ss, s);
	
	cout << s << endl;
	
	return EXIT_SUCCESS;
	*/
	/*
	noware::text t;
	
	
	s = "ABC";
	//t = "ABC";
	t = s.c_str ();
	
	
	std::cout << t << std::endl;
	s = "XYZ";
	std::cout << t << std::endl;
	
	return EXIT_SUCCESS;
	
	cout << endl;
	cout << "Array:" << endl;
	
	noware::array <int, int> arr1;
	
	
	cout << "Array: Assigning:" << endl;
	
	arr1 [1] = 111;
	//arr1.get (1) = 112;
	arr1 [2] = 222;
	arr1 [3] = 333;
	
	cout << "arr1 contains:" << endl;
	for (auto i : arr1)
	{
		cout << "arr1 [" << i.ky << "] = [" << i.val << ']' << endl;
	}
	cout << endl << endl;
	cout << "arr1 [" << 1 << "] = [" << arr1 [1] << ']' << endl;
	cout << "arr1 [" << 2 << "] = [" << arr1 [2] << ']' << endl;
	cout << "arr1 [" << 3 << "] = [" << arr1 [3] << ']' << endl;
	
	arr1 [1] = -555;
	arr1 [2] = -444;
	arr1 [3] = -999;
	
	cout << "arr1 now contains:" << endl;
	
	cout << "arr1 [" << 1 << "] = [" << arr1 [1] << ']' << endl;
	cout << "arr1 [" << 2 << "] = [" << arr1 [2] << ']' << endl;
	cout << "arr1 [" << 3 << "] = [" << arr1 [3] << ']' << endl;


	cout << endl;
	cout << endl;
	cout << "One package:" << endl;
	
	noware::array <int, int>::package pack, pack2;
	//std::string s;
	
	pack.ky = 100;
	//pack.val = new int (1000);
	pack.val = 1000;
	//pack.v = * (pack.val);
	
	cout << endl;
	cout << "\"pack\" contains:" << endl;
	cout << "pack [" << pack.ky << "] = [" << pack.val << ']' << endl;
	//cout << "pack [" << pack.ky << "] = [" << pack.v << ']' << endl;
	
	cout << endl;
	cout << "Serializing...";
	s = pack.serialize ();
	cout << " Done." << endl;
	cout << "Serial: s: " << '"' << s << '"' << endl;
	
	//cout << endl;
	//cout << "Emptying...";
	//a1.clear ();
	//cout << " Done." << endl;
	
	cout << endl;
	cout << "Deserializing...";
	
	cout.flush ();
	
	if (pack2.deserialize (s))
	//if (LIB::deserialize (s, pack2))
	{
		cout << "Deserialized \"s\" contains:" << endl;
		cout << "pack2 [" << pack2.ky << "] = [" << pack2.val << ']' << endl;
		//cout << "pack2 [" << pack2.ky << "] = [" << pack2.v << ']' << endl;
	}
	else
	{
		cout << "Could not deserialize." << endl;
	}
	
	
	cout << endl;
	cout << "Multiple packages:" << endl;
	///
	std::list <LIB::NAME_A <int, int>::package> packages;
	
	{
	LIB::NAME_A <int, int>::package p;
	
	p.ky = 11;
	p.val = 110;
	//p.val = new int (110);
	//p.v = * (p.val);
	packages.push_back (p);
	p.ky = 22;
	p.val = 220;
	//p.val = new int (220);
	//p.v = * (p.val);
	packages.push_back (p);
	p.ky = 33;
	p.val = 330;
	//p.val = new int (330);
	//p.v = * (p.val);
	packages.push_back (p);
	}
	
	cout << endl;
	cout << "\"packages\" contains:" << endl;
	for (auto i : packages)
	{
		cout << "packages [" << i.ky << "] = [" << i.val << ']' << endl;
		//cout << "packages [" << i.ky << "] = [" << i.v << ']' << endl;
	}
	
	cout << endl;
	cout << "Serializing...";
	s = LIB::serialize (packages);
	cout << " Done." << endl;
	cout << "Serial: s: " << '"' << s << '"' << endl;
	
	cout << endl;
	cout << "Emptying...";
	packages.clear ();
	cout << " Done." << endl;
	
	cout << endl;
	cout << "Deserializing...";
	
	cout.flush ();
	
	if (LIB::deserialize (s, packages))
	{
		cout << "Deserialized \"s\" contains:" << endl;
		for (auto i : packages)
		{
			cout << "packages [" << i.ky << "] = [" << i.val << ']' << endl;
			//cout << "packages [" << i.ky << "] = [" << i.v << ']' << endl;
		}
	}
	else
	{
		cout << "Could not deserialize." << endl;
	}
	///
	
	return EXIT_SUCCESS;
	*/
	/*
	noware::array <unsigned short int, unsigned short int> a1;
	//std::string s;
	
	a1 [1] = 10;
	a1 [2] = 20;
	a1 [3] = 30;
	
	//a1 [1] = "One";
	//a1 [2] = "Two";
	//a1 [3] = "Three";
	
	cout << endl;
	cout << "\"a1\" contains " << a1.size () << " elements:" << endl;
	for (auto i : a1)
	{
		cout << "a1 [" << i.ky << "] = " << '[' << * (i.val) << ']' << endl;
	}
	
	cout << endl;
	cout << "Serializing...";
	s = a1.serialize ();
	cout << " Done." << endl;
	cout << "Serialized: " << '"' << s << '"' << endl;
	
	cout << endl;
	cout << "Emptying...";
	a1.clear ();
	cout << " Done." << endl;
	
	cout << endl;
	cout << "Deserializing...";
	
	cout.flush ();
	
	if (a1.deserialize (s))
	//if (LIB::deserialize (s, a1))
	{
		cout << "Deserialized \"a1\" contains " << a1.size () << " elements:" << endl;
		for (auto i : a1)
		{
			cout << "a1 [" << i.ky << "] = " << '[' << * (i.val) << ']' << endl;
		}
	}
	else
	{
		cout << "Could not deserialize." << endl;
	}
	
	return EXIT_SUCCESS;
	*/
	//stringstream ss;
	
	//ss.st
	
	//noware::any a;
	//int i = 10;
	
	//a = i;
	
	////cout << boost::any_cast <int> (a);
	////cout << a.get <int> ();
	//
	//cout << endl;
	
	//noware::array <std::string, bool> a1;
	//noware::array <int, char> a2;
	
	//a2 = a1;
	
	//cout << boost::this_thread::get_id () << endl;
	
	//noware::any a;
	
	//a = 10;
	
	//cout << a.get_int () << endl;
	//exit (0);
	
//	noware::array <> arr1, arr2;
//	//noware::variable v;
//	std::string var;
//	//v = "THREE";
//	
//	arr1 [1] = (std::string) "One";
//	arr1 [2] = (std::string) "Two";
//	
//	//cout << arr1.size () << endl;
//	
//	//cout << arr1 [1] << endl;
//	//cout << arr1 [2] << endl;
//	//var = arr1 [3];
//	
//	//cout << arr1.size () << endl;
//	
//	arr1.begin ();
//	for (int i = 0; i < arr1.size (); ++ i, ++ arr1)
//	{
//		cout << arr1.current_key () << ": " << arr1.current () << endl;
//	}
///*
//	var = noware::serialize <noware::array <>> (arr1);
//	
//	noware::parse <noware::array <>> (var, arr2);
//*/
//	
//	arr2 = arr1;
//	
//	//std::for_each (arr2.begin (), arr2.end (), arr2);
//	arr2.begin ();
//	for (int i = 0; i < arr2.size (); ++ i, ++ arr2)
//	{
//		cout << arr2.current_key () << ": " << arr2.current () << endl;
//	}
//
	//std::queue <std::string> q1;
	//std::queue <std::string> q2;

	//q1.push ("Item 1");
	//q1.push ("Item 2");
	//q1.push ("Item 3");

	//q2 = q1;

	//for (int i = 0; i < 3; ++ i)
	//{
	//	std::cout << q2.front () << std::endl;
	//	q2.pop ();
	//}

	//std::stringstream ss;
	//std::string s;

	//ss << "Line 1" << std::endl;
	//ss << "Line 2" << std::endl;
	//ss << "Line 3" << std::endl;

	//for (int i = 0; i < 3; ++ i)
	//{
	//	std::getline (ss, s);
	//	//ss >> s;
	//	
	//	std::cout << s << std::endl;
	//}
/*
	noware::cluster::interpreter intr;
	//noware::cluster::devices::processor cpu (false);
	std::string error;

	//cpu.enqueue ("test.txt");
	std::queue <noware::cluster::devices::processor::instructions> instrs;
	
	//system ("pause");
	noware::tools::pause ();
	
	if (intr.enqueue ("test.txt", instrs, error) == 0)
	{

		//cpu.run (true);

		while (! instrs.empty ())
		{
			cout << "#serialize" << endl;
			cout << '{' << endl;

			while (! instrs.front ()._instructions.empty ())
			{
				cout << '\t' << "Output : " << instrs.front ()._instructions.front ().output << endl;
				cout << '\t' << "Operation : ";

				switch (instrs.front ()._instructions.front ()._operation)
				{
					case LIB::cluster::devices::processor::operation::addition:
						cout << '+';
						break;
					case LIB::cluster::devices::processor::operation::substraction:
						cout << '-';
						break;
					case LIB::cluster::devices::processor::operation::multiplication:
						cout << '*';
						break;
					case LIB::cluster::devices::processor::operation::division:
						cout << '/';
						break;
					case LIB::cluster::devices::processor::operation::modulo:
						cout << '%';
						break;
					default:
						cout << instrs.front ()._instructions.front ()._operation;
				}

				cout << endl;
			
				cout << '\t' << "Input 1: " << instrs.front ()._instructions.front ().inputs [0] << endl;
				cout << '\t' << "Input 2: " << instrs.front ()._instructions.front ().inputs [1] << endl;

				cout << endl;
				instrs.front ()._instructions.pop ();
			}

			cout << '}' << endl;

			instrs.pop ();
		}
	}
	else
	{
		cout << error << endl;
	}

	//system ("pause");
	noware::tools::pause ();
*/
/*
	noware::array <> arr;
	//std::unordered_map <int, std::string> arr;

	arr [0] = "zero";
	arr [1] = "one";
	arr [2] = "two";

	std::cout << arr.size () << std::endl;
	std::cout << arr [0] << std::endl;
	std::cout << arr [1] << std::endl;
	std::cout << arr [2] << std::endl;
*/
/*	
	int i = 123;
	void * a;

	a = &i;
	cout << static_cast <int *> (a) << endl;
*/
/*	
	noware::any a;
	a = 123;
	cout << a << endl;
*/	
/*
	int i = 5;

	//type_info type;
	
	//type = typeid (i);
	const std::type_info & t1 = typeid (i);
	cout << t1.name ();

	//cout << typeid (i).name () << endl;
	//cout << typeid (i).raw_name () << endl;

	//cout << run () << endl;
	
	
	//
	noware::any a1;
	a1 = &i;
	//

	boost::any a2;

*/

	//if (argc > 1 && /*((std::string) (*/argv [1]/*))*/ == "dev")
	//std::cout << "Created cluster." << std::endl;
	//std::cout << "argc:" << argc << std::endl;
	
	/*
	{
		noware::entity <> ntt1;
		
		ntt1 = "ABC";
		
		cout << ntt1 << endl;
		
		ntt1 = 123;
		
		cout << ntt1 << endl;
		
		cout << ntt1.exist (1) << endl;
		cout << ntt1.exist (2) << endl;
		cout << ntt1.exist (3) << endl;
		
		ntt1 [1] = "One";
		ntt1 [2] = "Two";
		ntt1 [3] = "Three";
		
		cout << ntt1.exist (1) << endl;
		cout << ntt1.exist (2) << endl;
		cout << ntt1.exist (3) << endl;
		
		cout << ntt1 [1] << ' ' << ntt1 [2] << ' ' << ntt1 [3] << endl;
		
		cout << "ntt1 size: " << ntt1.size () << endl;
		
		//cout.flush ();
		
		for (auto & element : ntt1)
		{
			cout << "Element: " << element /*()* / << endl;
		}
		
		cout << ntt1.unset (1) << endl;
		cout << ntt1.unset (2) << endl;
		cout << ntt1.unset (3) << endl;
		
		cout << ntt1.exist (1) << endl;
		cout << ntt1.exist (2) << endl;
		cout << ntt1.exist (3) << endl;
		
		cout << typeid (ntt1).name () << endl;
		*/
		/*
		int i = 12321;
		void * v;
		v = & i;
		
		cout << * (static_cast <int *> (v)) << endl;
		//cout << static_cast <int> (v) << endl;
		
		noware::array <> a3;
		
		a3 [3] = 333;
		a3 [5] = 555;
		a3 [6] = 666;
		
		a3.add (11);
		a3.add (22);
		a3.add (44);
		a3.add (77);
		a3.add (88);
		a3.add (99);
		
		for (auto & element : a3)
		{
			std::cout << "a3 [" << element.k << "] = " << element.v << std::endl;
		}
		*/
	// }
	/*
	variable v3;
	
	v3 = "ABC";
	cout << v3 << endl;
	
	v3 = 110;
	cout << v3 << endl;
	
	++ v3;
	cout << v3 << endl;
	
	v3 *= 7;
	cout << v3 << endl;
	*/
	// return EXIT_SUCCESS;
	
	
	/*
	//{
	if (argc > 1 && argv [1] == (std::string) "dev")
	{
		mathematics::numbers::natural n;
		noware::array <noware::network::ip::address, noware::mathematics::numbers::natural> addrs;
		
		//addrs.tolerant = false;
		//n = addrs.size ();
		//addrs.clear ();
		
		addrs = noware::network::ip::addresses ();
		
		n = addrs.size ();
		
		for (noware::mathematics::numbers::natural i = 0; i < n; ++ i)
		{
			std::cout << i << ". " << addrs [i].to_string () << std::endl;
		}
	}
	else
	{
		noware::cluster::machine cl;
		
		if (cl.enqueue (argc > 1 ? argv [1] : "Instructions.txt"))
		{
			std::cout << "Running cluster\'s processor." << std::endl;
			
			//cl.processor_.memory_.network_device = (argc > 2 ? ((noware::mathematics::numbers::natural) ((noware::variable) (argv [2]))) : 0);
			cl.cpu.mem.network_device = argc > 2 ? (int) (noware::variable) (argv [2]) : 0;
			cl.cpu.mem.refresh_local_address ();
			
			cl.cpu.run (true);
		}
		else
		{
			cout << "Error " << cl.get_error_code () << ": " << cl.get_error_message () << endl;
		}

		//while (true)
		//{

		//}

		noware::tools::pause ();

		//cl.p

		//noware::pause ();
	}
	//}
	return EXIT_SUCCESS;
	*/
	
/*
	Type * refObj = new TypeImpl <std::string> (new std::string ("Hello."));
	std::cout << typeid (refObj -> getObj ()).name () << std::endl;
	//std::cout << (refObj -> getObj ()).c_str () << std::endl;
	std::cout << (*(refObj -> getObj ())).c_str () << std::endl;
*/
//	//NoWare::Cluster::Memory memory;
//	
////	noware::any a1;
//
//	//a1.container = 123;
//
//	//cout << a1.get <int> () << endl;
//
//	//noware::any a;
//	//int i1 = MAXIMUM (5, 7);
//
//	//cout << i1 << endl;
//
//	cout << endl;
//
//	boost::any a;
//
//	//cout << a.empty () << endl;
//
//	//boost::any_cast <std::string> (a).operator= ("ABC");
//	//a = std::string ("ABC");
//	a = int (123);
//
//	cout << a.type ().name () << endl;
//	//const std::type_info T (a.type ());
//
//	cout << boost::any_cast <int> (a) << endl;
//	//`cout << boost::any_cast <BOOST_DEDUCED_TYPENAME remove_reference <(a.type ())>::type> (a) << endl;
//	
//	//
//	char mc [6] = "HELLO";
//
//	cout << mc << endl;
//	cout << mc [0] << endl;
//	cout << *mc << endl;
//	cout << &mc << endl;
//
//	cout << endl;
//
//	//
//	noware::array <std::string, int> ma;
//
//	ma.enqueue ("one");
//	ma.enqueue ("two");
//	ma.enqueue ("three");
//
//redo:
//
//	ma.begin ();
//
//
//	for (unsigned long long int i = 0; i < ma.size (); ++ i, ++ ma)
//	{
//		cout << "Key: " << ma.current_key () << " Value: " << ma.current () << endl;
//	}
////
//	ma.dequeue ();
//	//vector <int> vec;
//	//vec.push_back (10);
//	//vec.push_back (20);
//
//	//for (int value in vec)
//	//	cout << value << endl;
//
//	goto redo;
//
//	int i = 2;
//	void * t;
//
//	t = &i;
//
//	//*t = 4;
//	cout << *(static_cast <int *> (t)) << endl;
//
//	noware::array <std::string, unsigned short int> a1;
//
//	variable v1;
//
//	cout << typeid (v1).hash_code () << endl;
//	cout << typeid (v1).name () << endl;
//	cout << typeid (v1).raw_name () << endl;
//
//	cout << endl;
//
//	//cout << typeid (a1).hash_code () << endl;
//	//cout << typeid (a1).name () << endl;
//	//cout << typeid (a1).raw_name () << endl;
//
//	////cout << Digits (0101.75) << endl;
//
//	cout << endl;
//
//	noware::any a2;
//
//	//a2.
//	//a = "ABC";
//
//	//cout << a.empty () << endl;
//
//	//v1 = "String";
//
//	////arr1 [1] = "This.";
//	//arr1 [1] = 'T';
//	//cout << "Array1: " << arr1 [1] << endl;
//	////arr2 = arr2;
//	//arr1.Rename (1, 2);
//	//cout << "Array1: " << arr1 [2] << endl;
//	//cout << "Array2: " << arr2 [11] << endl;
//
//	////NoWare::Dynamic<NoWare::Variable> d;
//
//	mathematics::numbers::real l = 1440.15;
//
//	cout << LIB::digits (l) << endl;
//
//	cout << LIB::digits ((mathematics::numbers::real) 1440.15) << endl;
//
//	cout << LIB::digits ((mathematics::numbers::real) 0.0) << endl;
//	cout << LIB::digits ((mathematics::numbers::real) -0.0) << endl;
//
//	cout << LIB::digits ((mathematics::numbers::real) 00.00) << endl;
//	cout << LIB::digits ((mathematics::numbers::real) -000.00) << endl;
//	cout << LIB::digits ((mathematics::numbers::natural) 0) << endl;
//
//	cout << LIB::digits ((mathematics::numbers::real) 1440.0) << endl;
//	cout << LIB::digits ((mathematics::numbers::real) 01440.0) << endl;
//
//	cout << digits ((mathematics::numbers::natural) 0) << endl;
//	cout << digits ((mathematics::numbers::natural) 1) << endl;
//	cout << digits ((mathematics::numbers::natural) 5) << endl;
//	cout << digits ((mathematics::numbers::natural) 9) << endl;
//	cout << digits ((mathematics::numbers::natural) 10) << endl;
//	cout << digits ((mathematics::numbers::integer) -0) << endl;
//	cout << digits ((mathematics::numbers::integer) -1) << endl;
//	cout << digits ((mathematics::numbers::integer) -10) << endl;
//	cout << digits ((mathematics::numbers::natural) 144) << endl;
//	cout << digits ((mathematics::numbers::natural) 1440) << endl;
//
//	cout << endl;
//
//	variable v;
//
//	v = 0;
//	cout << ~ v << endl;
//
//	v = 1;
//	cout << ~ v << endl;
//
//	v = 3;
//	cout << ~ v << endl;
//
//	v = 9;
//	cout << ~ v << endl;
//
//	v = 10;
//	cout << ~ v << endl;
//
//	v = 144;
//	cout << ~ v << endl;
//
//	v = 218;
//	cout << ~ v << endl;
//
//	v = -3;
//	cout << ~ v << endl;
//
//	noware::array <std::string, int> arr;
//	std::string s;
//	cout << arr.size () << endl;
//	s = arr [1];
//	//cout << arr.operator [] (1) << endl;
//	//arr.operator [] (1);
//	cout << arr.size () << endl;
	//cout << arr [1] << endl;
	//cout << arr.Size () << endl;
	//arr [1] = "One.";
	//cout << arr.Size () << endl;
	//cout << arr [1] << endl;
	//cout << arr.Size () << endl;

	//arr.strict = false;
	////delete &arr;
	//cout << arr [2] << endl;
	//cout << arr.Size () << endl;
	//cout << arr [2] << endl;
	//cout << arr.Size () << endl;

	//arr.Clear ();

	//arr [0] = "Zero.";

	//cout << arr [0] << endl;

/*
	Array <bool, string> arr;

	arr ["1"] = true;
	cout << arr ["1"] << endl;

	arr ["1"] = false;
	cout << arr ["1"] << endl;

	cout << arr ["2"] << endl;
	cout << arr ["2"] << endl;
	cout << arr.Size () << endl;
*/	
/*
	{
		noware::array <int, int> a10;
		a10 [1] = 111;
		a10 [2] = 222;
		a10 [1] = 100;
		
		cout << "a10 [1]: " << a10 [1] << endl;
		cout << "a10 [2]: " << a10 [2] << endl;
		
		cout << endl;
	}
*/
	
/*
	{
		noware::entity ntt1;
		
		ntt1 = (variable) "ABC";
		
		cout << ntt1 () << endl;
		
		ntt1 = (variable) 123;
		
		cout << ntt1 () << endl;
		
		ntt1 [1] = (variable) "ABCD";
		ntt1 ["ONE"] = (variable) 111;
		
		cout << ntt1 [1] () << ' ' << ntt1 ["ONE"] () << endl;
	}
	
	return EXIT_SUCCESS;
*/

	{
		cluster cl;
		
		if (cl.enqueue ("test.txt"))
		{
			cout << "Enqueued" << endl;
			
			cout << "Activating . . . ";
			
			if (cl.run (true))
			{
				cout << "Activated";
			}
			else
			{
				cout << "Failed";
			}
			
			cout << endl;
		}
		else
		{
			cout << "Failed" << endl;
		}
	}


	return EXIT_SUCCESS;
	
	/*
	{
	noware::variable arg, option;
	//machine::devices::memory _memory;
	network::ip::mpi mpi;
	std::string k, v;
	std::string msg, host;
	//int option;
	
	
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
		
		if (arg == "dev")
		{
			//cout << "Getting network devices:" << endl;
			
			mathematics::numbers::natural n;
			noware::array <noware::network::ip::address, noware::mathematics::numbers::natural> addrs;
			
			//addrs.tolerant = false;
			//n = addrs.size ();
			//addrs.clear ();
			
			addrs = noware::network::ip::addresses ();
			
			n = addrs.size ();
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
	}
	
	// _memory.start ();
	noware::entity <> ep;	// Endpoint.
	
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
	*/
	//LIB::network::messaging::interface mpi;
	
	//noware::tools::pause ("Press [Enter] to continue");
	noware::tools::pause ();
	
	
	/*
	noware::array <std::string, unsigned short int> ar1;
	var v1;
	
	v1 = "String.";
	
	cout << "v1: " << v1 << endl;
	
	
	cout << "ar1 [0] = \"Zero\": " << endl;
	//ar1 [0];
	ar1 [0] = "Zero";
	cout << "ar1 [1] = \"One\": " << endl;
	//ar1 [1];
	ar1 [1] = "One";
	
	cout << "ar1.size (): " << ar1.size () << endl;
	
	cout << "ar1 [0]: ";
	cout.flush();
	cout << ar1 [0] << endl;
	
	cout << "ar1 [1]: ";
	cout.flush();
	cout << ar1 [1] << endl;
	
	//cout << "ar1 [0]: " << (ar1.operator[] (0)) << endl;
	//cout << "ar1 [1]: " << (ar1 [1]) << endl;
	*/
/*
	Array<string, int> A;


	A [0] = "Hello";
	A [1] = "World";

	cout << A [0] << endl;
	cout << A [1] << endl;

	cout << "Size: " << A.Size () << endl;

	A.Clear ();

	cout << "Size: " << A.Size () << endl;
	//A [11] = 111;

	//cout << A [11] << endl;

	if (0)
		cout << "Yes";
	else
		cout << "No";

	cout << endl;

	cout << "True: " << true << endl;
	cout << "False: " << false << endl;

	Variable v1, v2;

	//"FOUR4" % 2;

	v1 = 3;
	v2 = 5;
	unsigned short int vi = 10;

	vi %= v2;

	cout << "v1: \"" << v1 << "\"" << endl;
	cout << "v2: \"" << v2 << "\"" << endl;
	cout << "vi: \"" << vi << "\"" << endl;

	cout << "v2 % 5 == \"" << 
		v2 + 5
		<< "\"" << endl;
	cout << "v1 == \"" << v1 << "\"" << endl;
	cout << "9 + v2 + 3 == \"" << 9 + v2 + 3 << "\"" << endl;
	cout << "\"I have \" + v1 == \"" << "I have " + v1 << "\"" << endl;

	cout << "v2 == \"" << v2 << "\"" << endl;
	v2 = v2 / 4;
	//cout << "v2 += v1 == \"" << v2;
	cout << "v2 == \"" << v2 << "\"" << endl;
*/


	//Variable v = 110;
	//v.~Variable ();

	//cout << "String: " << v.ToString () << endl;

	//d.value = 10;
	//cout << "Dynamic: " << endl;
	////d.Delete ();
	//d.~Dynamic ();
	//cout << "Dynamic: " << endl;

	//std::string answer;
	////bool b = true;
	////cout << b;
	//boost::any var;

	//int x, y, z;

	////cout << a = b = 11 << endl;
	//x = y = 12;

	//cout << "x: " << x << endl;
	//cout << "y: " << y << endl;

	//NoWare::Any
	//	varA,
	//	varB,
	//	varC;
	////My m;

	//varC = 110;

	//varA = 10;

	//cout << "varA: " << varA << endl;

	//varA = varA + ++ varC;

	//cout << "varA: " << varA << endl;
	////cout << "++varC: " << ++ varC << endl;

	////fstream f;

	////f.open ("test.txt", ios::out | ios::in);

	////if (f.is_open ())
	////{
	////	f << (varA = varB = 110);
	////	f.seekg (0);
	////	f >> varC;

	////	cout << "varC: " << varC << endl;
	////	f.close ();
	////}
	////var = varB;
	////var = m;
	////cout << var;

	////varA = 11;
	//cout << "varA: ." << varA << '.' << endl;
	//if (varA == 10)
	//	cout << ".YES.";
	//else if (varA && varB)
	//	cout << ".YES.1.1.";
	//else
	//	cout << ".NO.";

	////boost::any varB;
	////	+	OR
	////	*	AND
	////cout << "true: " << true * true << endl;
	////cout << "false: " << false * false << endl;
	////cout << "true/f: " << true * false << endl;

	////string s = "C";
	////cout << s.length () << endl;
	//long double b = 0;
	//if (false == b)
	//{
	//	cout << "Yes TF";
	//}
	//else
	//{
	//	cout << "No TF";
	//}

	//cout << endl;

	//unsigned char c = NULL;

	//cout << '.' << c << '.' << endl;

	//c --;

	//cout << '.' << c << '.' << endl;

	//c = NULL + 1;

	//cout << '.' << c << '.' << endl;

	//do
	//{
	//	cout << "Please enter your value: ";
	//	//getline (cin, answer);
	//	getline (cin, varA);
	//	//cin >> answer;
	//	//ifstream f;

	//	cout << "Please enter your 2nd value: ";
	//	getline (cin, varB);

	//	//varA = answer;
	//	//answer = varA.To_String ();
	//	//answer = varA;
	//	cout << "Your value is: " << varA << endl;
	//	cout << "Your second value is: " << varB << endl;

	//	cout << "A * B: " << varA * varB << endl;
	//	cout << "B * A: " << varB * varA << endl;

	//	cout << "A / B: " << varA / varB << endl;
	//	cout << "B / A: " << varB / varA << endl;

	//	cout << "A % B: " << varA % varB << endl;
	//	cout << "B % A: " << varB % varA << endl;

	//	//varB = varA;

	//	//cout << "varB: " << varB << endl;

	//	if (varA <= varB)
	//	{
	//		cout << "varA <= varB";
	//	}
	//	else if (varA >= varB)
	//	{
	//		cout << "varA >= varB";
	//	}
	//	else if (varA > varB)
	//	{
	//		cout << "varA > varB";
	//	}
	//	else
	//	{
	//		cout << "varA != varB";
	//	}

	//	cout << endl;

	//	long double n =
	//		(varA - varB)
	//		.Number ();
	//	cout << "numeric (varA - varB): " << n;
	//	cout << endl;

	//	cout << "-A: " <<
	//		-varA;
	//	cout << endl;

	//	cout << "-B: " << 
	//		-varB;
	//	cout << endl;

	//	//printf ("Your value is: %s\n", varA);
	//	//if (varA == (long double) 123)
	//	//	cout << "Yes";
	//	//else
	//	//	cout << "No";
	//	//cout << varA;
	//	//cout << endl;
	//	//cout << "Answer: " << answer;
	//	cout << endl;
	//	//varB = true;
	//	//varB = "Q";
	//}
	////while (varB != true);
	//while (!!varA);

	//system ("pause");
}

