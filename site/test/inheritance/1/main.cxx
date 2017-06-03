#include <string>
#include <iostream>
//#include "derivative.hxx"
#include "base.cxx"
#include "derivative.cxx"

int main (unsigned long long int argc, char * argv [])
{
	//using namespace std;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
	{
		derivative d2;
		std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
		{
			derivative d1;
			std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
			std::cout << "set(\"test\"):" << std::boolalpha << d1.set ("test") << std::endl;
			std::cout << "get(): [" << d1.get () << ']' << std::endl;
		}
		std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
	}
	std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
	
	return EXIT_SUCCESS;
}
