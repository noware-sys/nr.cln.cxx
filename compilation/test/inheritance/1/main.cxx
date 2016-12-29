#include <string>
#include <iostream>
#include "derivative.hxx"

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
		}
		std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
	}
	std::cout << "instance_count: [" << base::instance_count << ']' << std::endl;
	
	return EXIT_SUCCESS;
}
