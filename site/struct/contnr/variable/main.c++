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

#include <noware/containers/variable.h++>
#include <noware/variable.h++>
//#include <noware/containers/entity.h++>
#include <noware/containers/variable-undefine.h++>

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
	
	noware::variable v1, v2;
	noware::mathematics::numbers::real n;
	long double d;
	unsigned int i;

	v1 = 5;
	v2 = 7;
	
	cout << (v1 == v2) << endl;	// 0
	cout << (v1 != v2) << endl;	// 1
	cout << (v1 < v2) << endl;	// 1
	cout << (v1 <= v2) << endl;	// 1
	cout << (v1 > v2) << endl;	// 0
	cout << (v1 >= v2) << endl;	// 0
	
	cout << (v1 - v2) << endl;	// -2
	
	//v1 + v2;
	cout << "v1 == " << v1 << endl;	// 
	cout << "v2 == " << v2 << endl;	// 
	v1 = v1 + v2;
	cout << v1 << endl;	// 12
	
	v1 = 10;
	
	n = 5;
	n += v1;
	cout << n << endl;	// 15
	
	d = 2.5;
	d += v1;
	cout << d << endl;	// 12.5
	
	i = 7;
	i += v1;
	cout << i << endl;	// 17
}
