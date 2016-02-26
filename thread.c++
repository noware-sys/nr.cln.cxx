#include "threads.hpp"

LIB::threads::threads (void)
{
	//container.tolerant = false;
}

//LIB::threads::~threads (void)
//{}

bool LIB::threads::add (void (* function) (void))
{

	//boost::thread * temp = new boost::thread (function);
	boost::thread temp = boost::thread (function);

	//container [temp -> get_id ()] = temp;

	//delete temp;

	//container.unset (temp -> get_id ());
	return true;
}

/*
bool LIB::threads::add (function function_name, ...)
{
	va_list args;
	va_start (args, function_name);
	
	//while (true)
	//{
	//	try
	//	{
	//		//va_arg (args, );
	//	}
	//	catch (...)
	//	{
	//		break;
	//	}
	//}
	
	va_end (args);

	return false;
}
*/
