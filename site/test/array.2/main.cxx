#include <sstream>
//#include <string>
#include <iostream>
//#include <list>

#include <noware/array.hxx>

int main (int argc, char * argv [])
{
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	noware::array <int, int> a;
	int val;
	
	std::cout << boolalpha;
	std::cout << "================================================================================" << std::endl;
	
	std::cout << "size ... " << a.size () << std::endl;
	
	std::cout << "set ..." << std::endl;
	success = a.set (0, 101);
	std::cout << success << std::endl;
	
	if (success)
	{
		std::cout << "size ... " << a.size () << std::endl;
		
		std::cout << "get ..." << std::endl;
		success = a.get (0, val);
		std::cout << success << std::endl;
		
		if (success)
			std::cout << val << std::endl;
	}
	
	std::cout << "================================================================================" << std::endl;
	
	//return EXIT_SUCCESS;
}
