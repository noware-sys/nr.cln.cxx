#include <string>
#include <iostream>

int main (int argc, char * argv [])
{
	using namespace std;
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	const std::string content =
		#include "sequence.hdr.cxx"
	;
	
	std::cout << "============================= Content ==========================================" << std::endl;
	std::cout << content << std::endl;
	std::cout << "================================================================================" << std::endl;
	
	return EXIT_SUCCESS;
}
