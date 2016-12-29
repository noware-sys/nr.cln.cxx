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

#include <noware/computer>
//#include <noware/containers/entity.h++>
//#include <noware/containers/variable-undefine.h++>

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
	//using namespace noware;
	
	for (unsigned int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument count: " << argc << std::endl;
	
	noware::computer pc;
	
	
	/*
	//container::any var1;
	//noware::mathematics::numbers::real n;
	//long double d;
	//unsigned int i;
	//char * c = "HELLO\0";
	
	var1 = "ABC";
	
	std::cout << var1 << std::endl;
	
	//std::cout << c << std::endl;
	//std::cout << *c << std::endl;
	//var1 = c;
	//std::cout << var1 << std::endl;
	//c = ;
	std::cout << var1 << std::endl;
	
	var1 = 20;
	
	std::cout << var1 + 10 << std::endl;
	std::cout << 10 + var1 << std::endl;
	*/
	/*
	v1 = 5;
	v2 = 7;
	
	std::cout << (v1 == v2) << std::endl;	// 0
	std::cout << (v1 != v2) << std::endl;	// 1
	std::cout << (v1 < v2) << std::endl;	// 1
	std::cout << (v1 <= v2) << std::endl;	// 1
	std::cout << (v1 > v2) << std::endl;	// 0
	std::cout << (v1 >= v2) << std::endl;	// 0
	
	std::cout << (v1 - v2) << std::endl;	// -2
	
	//v1 + v2;
	std::cout << "v1 == " << v1 << std::endl;	// 
	std::cout << "v2 == " << v2 << std::endl;	// 
	v1 = v1 + v2;
	std::cout << v1 << std::endl;	// 12
	
	v1 = 10;
	
	n = 5;
	n += v1;
	std::cout << n << std::endl;	// 15
	
	d = 2.5;
	d += v1;
	std::cout << d << std::endl;	// 12.5
	
	i = 7;
	i += v1;
	std::cout << i << std::endl;	// 17
	*/
}

