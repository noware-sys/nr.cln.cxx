//#include "device.hdr.cxx"
#include "../var.cxx"
#include "../net/node.cxx"

noware::machine::device::device (void)
{
	node.initialize ();
	node.start ();
	
	//nodes.add (node);
}

noware::machine::device::~device (void)
{
	node.stop ();
	node.finalize ();
	
	//nodes.remove (node);
}

const noware::any noware::machine::device::evaluate (const noware::any & expression)
{
	return "";
	//if (!nodes.evaluate (expression))
	//	return false;
	//nodes.evaluate (expression);
	//
	//return nodes.respond ();
}

