#include <string>
#include <ifstream>

#include <noware/var>

int main (int argc, char * argv [])
{
	//using namespace std;
	//using namespace noware;
	
	for (int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	
	
	return EXIT_SUCCESS;
}
