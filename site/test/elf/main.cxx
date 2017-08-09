//#include <Poco/any.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
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

const unsigned int str_int (const std::string & block, const bool & swap = false)
{
	unsigned int val;
	unsigned int size;
	std::stringstream ss;
	
	//val = 0;
	size = block.size ();
	ss << std::hex;
	
	if (swap)
	{
		for (signed int ndx = size; ndx >= 0; --ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	else
	{
		for (unsigned int ndx = 0; ndx < size; ++ndx)
		{
			//std::cout << "ndx:" << ndx << std::endl;
			ss << int (block [ndx]);
		}
	}
	
	ss >> val;
	
	return val;
}

int main (int argc, char * argv [])
{
	//using boost::any_cast;
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	std::cout << std::boolalpha;
	std::cout << std::hex;
	std::cout << std::showbase;
	
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
	unsigned char * fileblock;
	//char c;
	//unsigned int b;
	std::streampos size;
	bool x64;
	unsigned int phoff;
	unsigned char * phoff_c;
	std::string phoff_s;
	
	file.open (argv [1], std::ios::in | std::ios::binary | std::ios::ate);
	
	if (!file.is_open ())
		return EXIT_FAILURE;
	
	size = file.tellg ();
	fileblock = new unsigned char [size];
	file.seekg (0, std::ios::beg);
	file.read (fileblock, size);
	
	/*
	printf ("[%s]\n", str);
	std::cout << "[" << str << "]" << std::endl;
	std::cout << "[" << (str [0] == 0x7f) << "]" << std::endl;
 	std::cout << "[" << (str [1] == 0x45) << "]" << std::endl;
	std::cout << "[" << (str [2] == 0x4c) << "]" << std::endl;
	std::cout << "[" << (str [3] == 0x46) << "]" << std::endl;
	*/
	
	// the magic number
	if (fileblock [0] != 0x7f || fileblock [1] != 0x45 /* E */ || fileblock [2] != 0x4c /* L */ || fileblock [3] != 0x46 /* F */)
		return EXIT_FAILURE;
	
	x64 = fileblock [4] == 0x2;
	std::cout << "x64[" << x64 << "]" << std::endl;
	
	
	
	file.seekg (0x20, std::ios::beg);
	phoff_c = new unsigned char [8];
	file.read (phoff_c, 8);
	
	/*
	std::stringstream ss;
	ss << std::hex;
	for (signed short int ndx = 1; ndx >= 0; --ndx)
	{
		//std::cout << "ndx:" << ndx << std::endl;
		ss << int (phoff_c [ndx]);
	}
	ss >> phoff;
	*/
	
	phoff = str_int ((char *) phoff_c, true);
	
	std::cout << "phoff_c[0][" << int (phoff_c [0]) << "]" << std::endl;
	std::cout << "phoff_c[1][" << int (phoff_c [1]) << "]" << std::endl;
	/*std::cout << "phoff_c[2][" << phoff_c [2] << "]" << std::endl;
	std::cout << "phoff_c[3][" << phoff_c [3] << "]" << std::endl;
	std::cout << "phoff_c[4][" << phoff_c [4] << "]" << std::endl;
	std::cout << "phoff_c[5][" << phoff_c [5] << "]" << std::endl;
	std::cout << "phoff_c[6][" << phoff_c [6] << "]" << std::endl;
	std::cout << "phoff_c[7][" << phoff_c [7] << "]" << std::endl;
	*/
	//phoff = 0;
	//phoff += phoff_c [0];
	//phoff += phoff_c [1];
	
	//phoff_s = (char *) phoff_c;
//	std::cout << "phoff_c[" << phoff_c << "]" << std::endl;
	//std::cout << "phoff_s[" << phoff_s << "]" << std::endl;
	//std::cout << "phoff_c==0x40[" << (phoff_c == 0x40) << "]" << std::endl;
	std::cout << "phoff[" << phoff << "]" << std::endl;
	//std::cout << "ss.str()[" << ss.str () << "]" << std::endl;
	
	delete [] phoff_c;
	
	
	file.seekg (phoff, std::ios::beg);
	phoff_c = new unsigned char [4];
	file.read (phoff_c, 4);
	
	std::cout << "ph[" << str_int ((char *) phoff_c, true) << "]" << std::endl;
	
	
	file.close ();
	delete [] fileblock;
}
