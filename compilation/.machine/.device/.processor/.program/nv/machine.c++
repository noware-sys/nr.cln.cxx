#include <cstdlib>
#include <iostream>
#include <fstream>
#include <bitset>

signed int main (unsigned int argc, char * argv [])
{
	if (argc <= 1)
		return EXIT_FAILURE;
	
	std::streampos size = 5;
	
	char * memblock;
	
	//std::cout << 1 << std::endl;
	
	//std::ifstream file ("main.do", ios::in|ios::binary|ios::ate);
	std::ifstream file (argv [1], std::ios::in | std::ios::binary);
	
	//std::cout << 2 << std::endl;
	
	if (file.is_open ())
	{
		//std::cout << 3.1 << std::endl;
		
		//size = file.tellg ();
		memblock = new char [size];
		//file.seekg (0, ios::beg);
		//file.read (memblock, size);
		//std::cout << 3.2 << std::endl;
		file.read (memblock, size);
		//std::cout << 3.3 << std::endl;
		file.close();
		
		std::cout << "the entire file content is in memory" << std::endl;
		
		//std::cout << (memblock [0] == 0x7F) << std::endl;
		//std::cout << (memblock [4] == 0x2) << std::endl;
		
		for (int i = 0; i < size; ++ i)
		{
			//std::cout << 3.4 << '.' << i << std::endl;
			std::cout << memblock [i] << " :: " << std::bitset <8> (static_cast <unsigned short int> (memblock [i])) << " :: " << static_cast <unsigned short int> (memblock [i]) << std::endl;
		}
		
		//std::cout << std::endl;
		
		delete [] memblock;
		
		return EXIT_SUCCESS;
	}
	else
	{
		//std::cout << 4.1 << std::endl;
		
		std::cout << "Unable to open file" << std::endl;
		
		return EXIT_FAILURE;
	}
}

