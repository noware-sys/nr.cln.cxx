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

//#include <noware/container/array.h++>
//#include <noware/container/entity.h++>
#include <noware/communication/message.h++>
//#include <noware/variable.h++>
////#include <noware/containers/entity.h++>
//#include <noware/containers/variable-undefine.h++>
//#include <noware/math.h++>
#include <noware/serialization.h++>

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

int main (unsigned long long int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using namespace noware;
	
	//noware::container::array <noware::math::numbers::real, noware::math::numbers::real> numbers;
	//noware::container::array <> test;
	//noware::math::numbers::real number, number2;
	//noware::container::entity <> ntt1, ntt2;
	noware::communication::message msg1, msg2;
	std::string serial;
	//std::string s = "43252003274489856000";
	bool success;
	
	//number = 789.321;
	//number2 = s.c_str ();
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	/*
	for (noware::math::numbers::natural i = 0; i < 3; ++ i)
	{
		numbers [i] = i * 10 + i;
		//test [i] = i * 10 + i;
	}
	
	for (const noware::container::array <noware::math::numbers::real, noware::math::numbers::real>::container & number : numbers)
		std::cout << "\t[" << number.k <<  "] = " << number.v << std::endl;
	
	
	//test = static_cast <noware::container::array <>> (numbers);
	//test = noware::container::array <> (numbers);
	//test = numbers;
	//LIB::container::NAME_A <> test = numbers;
	
	for (const noware::container::array <>::container & number : test)
		std::cout << "\t[" << number.k <<  "] = " << number.v << std::endl;
	*/
	
	//ntt1 ["one"] = 111;
	msg1.content ["one"] = 111;
	
	//serial = noware::serialize <noware::math::numbers::real> (number);
	//serial = noware::serialize <noware::container::message <>> (ntt1);
	serial = noware::serialize <noware::communication::message> (msg1);
	//serial = noware::serialize <std::string> ("12345");
	
	std::cout << serial << std::endl;
	//success = noware::deserialize <noware::math::numbers::real> (serial, number2);
	//success = noware::deserialize <noware::container::entity <>> (serial, ntt2);
	success = noware::deserialize <noware::communication::message> (serial, msg2);
	//success = noware::deserialize <std::string> (serial, s);
	std::cout << "Success: " << success;
	if (success)
		//std::cout << ". " << number2 << std::endl;
		//std::cout << ". " << ntt2.content ["one"];
		std::cout << ". " << msg2.content ["one"];
		//std::cout << ". " << s << std::endl;
	
	std::cout << std::endl;
	//std::cout << numbers.serialize () << std::endl;
	//std::cout << test.serialize () << std::endl;
	
	return EXIT_SUCCESS;
}
