//#include <Poco/any.h>
#include <string>
#include <iostream>
//#include <sstream>
#include <fstream>
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

//#include <noware/array>
//#include <noware/var>
//#include <noware/machine>
//#include <noware/container/entity.h++>

//////#include <noware/containers/entity.h++>
////#include <noware/containers/variable-undefine.h++>
//#include <noware/math.h++>
//#include <noware/serialization.h++>

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
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "argument count [" << argc << ']' << std::endl;
	
	if (argc < 2)
	{
		std::cout << "'" << argv [0] << "'" << " <file.elf>" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	std::ifstream file;
	char * block;
	//char c;
	//unsigned int b;
	bool x64;
	std::streampos size;
	
	file.open (argv [1], std::ios::in | std::ios::binary | std::ios::ate);
	
	if (!file.is_open ())
		return EXIT_FAILURE;
	
	// TODO check size of file
	size = file.tellg ();
	fileblock = new char [size];
	file.seekg (0, std::ios::beg);
	file.read (block, size);
	
	/*
	printf ("[%s]\n", str);
	std::cout << "[" << str << "]" << std::endl;
	std::cout << "[" << (str [0] == 0x7f) << "]" << std::endl;
 	std::cout << "[" << (str [1] == 0x45) << "]" << std::endl;
	std::cout << "[" << (str [2] == 0x4c) << "]" << std::endl;
	std::cout << "[" << (str [3] == 0x46) << "]" << std::endl;
	*/
	if (block [0] != 0x7f || block [1] != 0x45 /* E */ || block [2] != 0x4c /* L */ || block [3] != 0x46 /* F */)
		return EXIT_FAILURE;
	
	x64 = block [4] == 0x2;
	
	
	
	//file.close ();
	//delete [] str;
}
