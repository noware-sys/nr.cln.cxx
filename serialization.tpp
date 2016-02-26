#include <sstream>
#include <boost/serialization/serialization.hpp>

template <typename type>
bool LIB::parse (std::string serial, type & object)
{
	std::string s;
	std::stringstream ss;
	//s = "";
	//s = *this;

	//s.clear ();
	//ss.clear ();	// Make sure that there is nothing in the stream.

	// Convert the string into a string stream:
	ss << serial;

	try
	{
		// Get the obect's serializable members from the input stream:
		boost::archive::text_iarchive a (ss);
		a >> object;

		return true;
	}
	catch (...)
	{
		return false;
	}
}

//template <typename type>
//bool LIB::parse (std::string serial, type & object)
//{
//	return LIB::parse (const_cast <const std::string> (serial), object);
//}

template <typename type>
std::string LIB::serialize (type object)
{
	std::string s;
	std::stringstream ss;
	//s = "";
	//s = *this;

	//ss.clear ();	// Make sure that there is nothing in the stream.

	try
	{
		// Put the obect's serializable members into an output stream:
		boost::archive::text_oarchive a (ss);
		a << object;

		// Get the string representation:
		std::getline (ss, s, '\n');

		return s;
	}
	catch (...)
	{
		return "";
	}
}

//template <typename type>
//std::string LIB::serialize (type object)
//{
//	return LIB::serialize (const_cast <const type> (object));
//}
