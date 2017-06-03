#include "test.hxx"
#include <boost/thread.hpp>

void test (void)
{
	std::cout << "  " << boost::this_thread::get_id ()  << std::endl;
}
