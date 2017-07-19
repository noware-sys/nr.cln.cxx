#pragma once

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>

#include <boost/bind.hpp>

#include "mach.hxx"

//#include "array.txx"
#include "var.cxx"
//#include "nr.cxx"
//#include "container/list/sqlite.cxx"
#include ".mach/.incl.cxx"
#include ".mach/.cxx"

noware::mach::mach (void)
{
	/*
	thread * t;
	
	t = new thread ();
	
	trd [t -> group ()] = t;
	*/
	
	//cpu.start ();
}

noware::mach::~mach (void)
{
	//delete
}

//const LIB::container::NAME_V LIB::mach::evaluate (const LIB::container::NAME_V & expression)
//{
//	return "";
//}

const bool noware::mach::enqueue (const std::string & file_name)
{
//	if (!trd.load (file_name))
//		return false;
	
	//if (!trd.start ())
	//	return false;
	
	return true;
}
