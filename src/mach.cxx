#pragma once

//#include <thread>

// #include <assert.h>

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>
//#include <boost/bind.hpp>

#include <boost/thread.hpp>

// #include <omp.h>

#include "mach.hxx"

//#include "array.txx"
// #include "var.cxx"
// #include <zmq/msg.cxx>
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
	
	
	//cpu.activate ();
	
	
	unsigned int n;
	
	store * s;
	queue * q;
	cpu * p;
	
	
	//n = boost::thread::hardware_concurrency ();
	n = 1;
	
	#pragma omp parallel
	{
		#pragma omp for
		for (unsigned int ndx = 1; ndx <= n; ++ndx)
		{
			#pragma omp critical
			{
				s = &_store [ndx];
				
				assert (s -> init ());
				assert (s -> enable ());
				assert (s -> start ());
				assert (s -> running ());
			}
			
			#pragma omp critical
			{
				q = &_queue [ndx];
				
				assert (q -> init ());
				assert (q -> enable ());
				assert (q -> start ());
				assert (q -> running ());
			}
			
			#pragma omp critical
			{
				p = &_cpu [ndx];
				
				assert (p -> init ());
				assert (p -> enable ());
				assert (p -> start ());
				assert (p -> running ());
				assert (p -> node.join (noware::mach::cpu::grp_dft));
			}
		}
	}
}

noware::mach::~mach (void)
{
	//delete
}
