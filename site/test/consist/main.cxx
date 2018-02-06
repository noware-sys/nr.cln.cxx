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

#include <cln/nr>
//#include <noware/array>
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

int main (int argc, char * argv [], char * envp [])
{
	//using namespace boost::any_cast;
	//using namespace std;
	//using namespace boost;
	//using namespace noware;
	
	std::cout << "  ";
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "  argc==[" << argc << ']' << std::endl;
	
	std::cout << std::boolalpha;
	
	//cln::nr n;
	
	//n = 123;
	
	//std::cout << "n==[" << n << ']' << std::endl;
	
	if (argc < 3)
	{
		std::cout << "  usage: '" << argv [0] << "' x y" << std::endl;
		return EXIT_FAILURE;
	}
	
	cln::nr x;
	cln::nr y;
	
	x = argv [1];
	y = argv [2];
	
	std::cout << std::endl;
	std::cout << "  " << 'x' << '=' << '[' << x << ']' << std::endl;
	std::cout << "  " << 'y' << '=' << '[' << y << ']' << std::endl;
	std::cout << std::endl;
	std::cout << "  " << "x == y" << ' ' << '[' << x << " == " << y << ']' << ' ' << '[' << (x == y) << ']' << std::endl;
	std::cout << "  " << "x != y" << ' ' << '[' << x << " != " << y << ']' << ' '  << '[' << (x != y) << ']' << std::endl;
	std::cout << std::endl;
	std::cout << "  " << "x <  y" << ' ' << '[' << x << " <  " << y << ']' << ' '  << '[' << (x <  y) << ']' << std::endl;
	std::cout << "  " << "x >  y" << ' ' << '[' << x << " >  " << y << ']' << ' '  << '[' << (x >  y) << ']' << std::endl;
	std::cout << std::endl;
	std::cout << "  " << "x <= y" << ' ' << '[' << x << " <= " << y << ']' << ' '  << '[' << (x <= y) << ']' << std::endl;
	std::cout << "  " << "x >= y" << ' ' << '[' << x << " >= " << y << ']' << ' '  << '[' << (x >= y) << ']' << std::endl;
	std::cout << std::endl;
	std::cout << "  " << "x +  y" << ' ' << '[' << x << " +  " << y << ']' << ' '  << '[' << (x +  y) << ']' << std::endl;
	std::cout << "  " << "x -  y" << ' ' << '[' << x << " -  " << y << ']' << ' '  << '[' << (x -  y) << ']' << std::endl;
	std::cout << "  " << "x *  y" << ' ' << '[' << x << " *  " << y << ']' << ' '  << '[' << (x *  y) << ']' << std::endl;
	if (y == 0)
		std::cout << "  " << "x /  y" << ' ' << '[' << x << " /  " << y << ']' << ' '  << '[' << "infinity" << ']' << std::endl;
	else
		std::cout << "  " << "x /  y" << ' ' << '[' << x << " /  " << y << ']' << ' '  << '[' << (x /  y) << ']' << std::endl;
	std::cout << "  " << "x %  y" << ' ' << '[' << x << " %  " << y << ']' << ' '  << '[' << (x %  y) << ']' << std::endl;
	std::cout << "  " << "x ^  y" << ' ' << '[' << x << " ^  " << y << ']' << ' '  << '[' << (x ^  y) << ']' << std::endl;
	
	//return EXIT_SUCCESS;
}
