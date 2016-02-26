#include "node.h++"
#include ".node/index.c++"

//const unsigned short int/*LIB::mathematics::numbers::natural*/ LIB::network::node::default_keepalive = 20;
const unsigned short int/*LIB::mathematics::numbers::natural*/ LIB::network::node::default_keepalive = 15;

LIB::network::node::node (void)
{
	//available = false;
	keepalive = default_keepalive;
	//keepalive = cln::cl_I_to_uint (default_keepalive);	// Temporary!
	thread_timeout = NULL;
}

LIB::network::node::node (const LIB::network::node & other)
{
	operator = (other);
}

LIB::network::node::~node (void)
{
	if (thread_timeout != NULL)
	{
		delete thread_timeout;
		thread_timeout = NULL;
	}
}

template <typename archive>
void LIB::network::node::serialize (archive & arch, const unsigned int & version)
{
}

/*
const LIB::mathematics::numbers::natural & LIB::network::node::id (void) const
{
	return _id;
}

const LIB::mathematics::numbers::natural LIB::network::node::generate_id (void) const
{
	return 1;
}
*/

const LIB::network::node & LIB::network::node::operator = (const LIB::network::node & other)
{
	keepalive = other.keepalive;
	
	//return *this;
	return other;
}

const bool LIB::network::node::operator == (const LIB::network::node & other) const
{
//	return this == &other || (keepalive == other.keepalive && paths == other.paths);
	return this == &other || (keepalive == other.keepalive);
}

void LIB::network::node::function_timeout (LIB::container::NAME_A <LIB::network::node, LIB::mathematics::numbers::natural> & _nodes, const LIB::mathematics::numbers::natural & key, const LIB::mathematics::numbers::natural & timeout) const
{
	boost::this_thread::sleep (boost::posix_time::seconds (cln::cl_I_to_uint (timeout)));
	
	_nodes.unset (key);
}
