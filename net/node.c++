#include "node.h++"
#include ".node/index.c++"

//const unsigned short int/*noware::math::numbers::natural*/ noware::net::node::default_keepalive = 20;
const unsigned short int/*noware::math::numbers::natural*/ noware::net::node::default_keepalive = 15;

noware::net::node::node (void)
{
	//available = false;
	keepalive = default_keepalive;
	//keepalive = cln::cl_I_to_uint (default_keepalive);	// Temporary!
	thread_timeout = NULL;
}

noware::net::node::node (const noware::net::node & other)
{
	operator = (other);
}

noware::net::node::~node (void)
{
	if (thread_timeout != NULL)
	{
		delete thread_timeout;
		thread_timeout = NULL;
	}
}

template <typename archive>
void noware::net::node::serialize (archive & arch, const unsigned int & version)
{
}

/*
const noware::math::numbers::natural & noware::net::node::id (void) const
{
	return _id;
}

const noware::math::numbers::natural noware::net::node::generate_id (void) const
{
	return 1;
}
*/

const noware::net::node & noware::net::node::operator = (const noware::net::node & other)
{
	keepalive = other.keepalive;
	
	//return *this;
	return other;
}

const bool noware::net::node::operator == (const noware::net::node & other) const
{
//	return this == &other || (keepalive == other.keepalive && paths == other.paths);
	return this == &other || (keepalive == other.keepalive);
}

void noware::net::node::function_timeout (noware::container::array <noware::net::node, noware::math::numbers::natural> & _nodes, const noware::math::numbers::natural & key, const noware::math::numbers::natural & timeout) const
//void noware::net::node::function_timeout (noware::container::array <noware::net::node, noware::container::any> & _nodes, const noware::container::any & key, const noware::math::numbers::natural & timeout) const
{
	boost::this_thread::sleep (boost::posix_time::seconds (cln::cl_I_to_uint (timeout)));
	
	_nodes.unset (key);
}
