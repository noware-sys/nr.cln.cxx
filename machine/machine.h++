#ifndef CLUSTER
#define CLUSTER

#include <string>
#include <sstream>

//#include "Lexical_Analyzer"
//#include "peers.h++"
#include "../containers/array.h++"
#include "memory.h++"
#include "processor.h++"
#include "interpreter.h++"

namespace LIB
{
	namespace machine
	{
		class machine
		{
			protected:
				interpreter interpreter_;
				LIB::NAME_A <std::string, std::string> error;
				
			public:
				machine (void);
				~machine (void);
				
				processor processor_;
				
				//class process
				//{
				
				//};
				
				//void run (const bool & = false);
				
				//LIB::cluster::memory memory;
				// LIB::cluster::processor _processor;
				//processor.
				// Enqueue instructions.
				bool enqueue (const std::string &/* file_name*/);
				//bool enqueue (const LIB::cluster::processor::instructions & /* A queue of instruction. */);
				//bool enqueue (const LIB::cluster::processor::instruction & /* A single instruction. */);
				
				//bool parse (const std::string);
				
				// Provide read-only access:
				//const LIB::NAME_A <std::string, std::string> & get_error (void) const;
				std::string get_error_code (void);
				std::string get_error_message (void);
		};
	}
}

#endif
