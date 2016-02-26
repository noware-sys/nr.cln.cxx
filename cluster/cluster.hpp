#ifndef CLUSTER
#define CLUSTER

#include <string>
#include <sstream>

//#include "Lexical_Analyzer"
//#include "peers.hpp"
#include "memory.hpp"
#include "processor.hpp"
#include "interpreter.hpp"

namespace LIB
{
	namespace cluster
	{
		class cluster
		{
			protected:
				LIB::cluster::interpreter interpreter;

			public:
				LIB::cluster::processor processor;

				//class process
				//{

				//};

				cluster (void);
				~cluster (void);

				void run (const bool & = true);

				//LIB::cluster::memory memory;
				// LIB::cluster::processor _processor;
				//processor.
				// Enqueue instructions.
				bool enqueue (const std::string & /* File name. */);
				//bool enqueue (const LIB::cluster::processor::instructions & /* A queue of instruction. */);
				//bool enqueue (const LIB::cluster::processor::instruction & /* A single instruction. */);

				//bool parse (const std::string);
		};
	}
}

#endif CLUSTER
