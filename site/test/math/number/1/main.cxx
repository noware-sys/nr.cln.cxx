#include <string>
#include <iostream>
#include <noware/math/number>

int main (unsigned long long int argc, char * argv [])
{
	//using namespace std;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	noware::math::number x;
	
	x = 111;
	std::cout << "x == [" << x << ']' << std::endl;
	
	x = x * 2;
	std::cout << "x == [" << x << ']' << std::endl;
	
	return EXIT_SUCCESS;
}

