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
#include <boost/random/random_device.hpp>

//#include <string>
//#include <stack>

//#include <noware/containers/variable.h++>
//#include <noware/variable.h++>
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
	using namespace std;
	//using namespace noware;
	
	for (unsigned int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	cout << "Argument count: " << argc << endl;
	
	boost::random::random_device randomizer;
	
	cout << "Min: " << randomizer.min () << endl;
	cout << "Max: " << randomizer.max () << endl;
	
	for (unsigned short int count = 0; count < 3; ++ count)
	{
		cout << count + 1 << ". " << randomizer () << endl;
	}
}
