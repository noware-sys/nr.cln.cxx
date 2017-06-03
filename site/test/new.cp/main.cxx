#include <sstream>
#include <string>
#include <iostream>
#include <list>

//#include <noware/tool/ptr.hxx>

int main (int argc, char * argv [])
{
	//using namespace std;
	//using boost;
	//using namespace noware;
	
	for (/*unsigned long long*/ int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	const std::string _3 = "333";
	//const std::string _5 = "55555";
	
	//void * __3;
	std::string * __3;
	std::string addr;
	
	// Convert the address to a string:
	//ss << static_cast <const std::string *> (& _3);
	
	addr = noware::tool::ptr::str (& _3);
	// Convert the string back to an address:
	//__3 = dynamic_cast <const std::string *> (ss.str ());
	//ss >> __3;
	__3 = const_cast <std::string *> (static_cast <const std::string *> (noware::tool::ptr::val (addr)));
	std::cout << "================================================================================" << std::endl;
	//std::cout << "sizeof _3 == " << sizeof _3 << std::endl;
	//std::cout << "sizeof _5 == " << sizeof _5 << std::endl;
	std::cout << std::endl;
	std::cout << "     & _3 == " << & _3 << std::endl;
	//std::cout << "     & _5 == " << & _5 << std::endl;
	std::cout << std::endl;
	//std::cout << " ss.str() == " << ss.str () << std::endl;
	//std::cout << " ss.str() == " << ss.str () << std::endl;
	std::cout << "     addr == " << addr << std::endl;
	std::cout << "      __3 == " << __3 << std::endl;
	std::cout << "    * __3 == " << * __3 << std::endl;
	//std::cout << "    static_cast <const std::string *> (__3) == " << static_cast <const std::string *> (__3) << std::endl;
	//std::cout << "  * static_cast <const std::string *> (__3) == " << * static_cast <const std::string *> (__3) << std::endl;
	std::cout << "================================================================================" << std::endl;
	
	//return EXIT_SUCCESS;
}
