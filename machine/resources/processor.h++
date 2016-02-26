#pragma once
//#ifndef __PROCESSOR
//#define __PROCESSOR

// Standard:
#include <string>
#include <queue>
//#include <stack>
#include <mutex>
#include <condition_variable>

// Boost:
//#include <boost/thread/mutex.hpp>
//#include <boost/thread/condition_variable.hpp>
#include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
#include <boost/date_time/posix_time/posix_time.hpp>

// This class:
#include "../../default.h++"
#include "../../mathematics.h++"
#include "../../containers/array.h++"
#include "../../containers/variable.h++"
#include "../../tools.h++"
#include "../resource.h++"
#include "memory.h++"
#include "../../serialization.h++"

namespace LIB
{
	namespace machine
	{
		namespace resources
		{
			//class processor;
			
			class processor : public LIB::machine::resource
			{
				public:
					//class parser
					//{
					//	protected:
					//		// State handlers:
					//		void comment ();

					//		std::queue <LIB::machine::devices::processor::instruction> instructions;
					//	public:
					//		void parse (const std::string, std::queue <LIB::machine::devices::processor::instruction> &);
					//};
					
					enum /*class */operation
					{
						none,
						// For controlling the flow of the execution:
						// and, intersection
						// or, union
						addition,
						substraction,
						multiplication,
						division,
						modulo,
						modulus,
						complement,
						exponentiation,
						assignment,
						//jump,
						output	// Or "echo".
					};
					
					class instruction
					{
						protected:
							friend class boost::serialization::access;
							// friend std::ostream & operator << (std::ostream &, const instruction &);
							
							template <typename archive>
							void serialize (archive &, const unsigned int &/* version*/);
						public:
							instruction (void);
							instruction (const instruction &/* other*/);
							instruction (const std::string &/* serial representation; text archive*/);
							/*
								ID: "1"
							*/
							
							operator const std::string (void) const;
							// operator instruction (void);
							
							// Overwrite this instruction by the one parsed from the string.
							const instruction operator = (const std::string &/* serial*/);
							const instruction operator = (const instruction &/* other*/);
							
							
							// bool active;	// If the instruction should be processed.
							// bool processing;	// If there is a processor processing the instruction.
							
							//std::string instructions [2];
							/*
								instructions [0] == Prerequisite instruction, if any.
								instructions [1] == Next instruction, if any.
							*/
							// std::string prerequisite_instruction;
							// std::string next;
							// std::string id;
							//std::string next_sequence;
							
							//mathematics::numbers::real inputs [2];
							LIB::NAME_V input [2];
							//std::string inputs [2];
							//LIB::NAME_V output;
							std::string output;
							
							operation action;
							
							// std::string user;
							// LIB::mathematics::numbers::natural user;	// The ID of the user who owns this instructions; who enqueued this instruction.
							//LIB::mathematics::numbers::natural processor;
					};
					
					class instructions
					{
						public:
						//protected:
							friend class boost::serialization::access;
							// friend std::ostream & operator << (std::ostream &, const instruction &);
							
							template <typename archive>
							void serialize (archive &, const unsigned int &/* version*/);
						public:
							instructions (void);
							instructions (const instructions &);
							/*
								ID: "1"
							*/
							
							operator const std::string (void) const;
							// operator instruction (void);
							
							
							// Overwrite this set of instructions by the one parsed from the string.
							const instructions operator = (const std::string &);
							const instructions operator = (const instructions &);
							
							// bool active;	// If the instruction should be processed.
							// bool processing;	// If there is a processor processing the instruction.
							
							//std::string instructions [2];
							/*
								instructions [0] : Prerequisite instruction, if any.
								instructions [1] : Next instruction, if any.
							*/
							// std::string prerequisite_instruction;
							//std::string next_instruction;
							//std::string id;
							
							////mathematics::numbers::real inputs [2];
							// LIB::NAME_A <LIB::machine::devices::processor::instruction, LIB::mathematics::numbers::natural> _instructions;
							std::queue <LIB::machine::resources::processor::instruction> _instructions;
							////std::string inputs [2];
							////LIB::NAME_V output;
							//std::string output;
							//operation _operation;
							
							// std::string user;
							////LIB::mathematics::numbers::natural processor;
					};
				
					//class queue
					//{
					//	protected:
					//		friend class boost::serialization::access;
					//		// friend std::ostream & operator << (std::ostream &, const instruction &);

					//		template <typename archive>
					//		void serialize (archive &, const unsigned int);
					//	public:
					//		queue (void);
					//		~queue (void);

					//		std::queue <LIB::machine::devices::processor::instructions> _queue;

					//		operator std::string (void) const;
					//		queue operator = (const std::string &);
					//};

					//class results
					//{
					//	protected:
					//		friend class boost::serialization::access;

					//		template <typename std::string>
					//		void serialize (std::string &/*, const unsigned int version*/);
					//};
					/*
					// Computational platform.
					class core
					{
						//protected:
							//bool ended;
						
						public:
							core (void /*const bool & = false* /);
							~core (void);
							
							// const core operator = (const core &);
							
							//const bool active (void) const;
							
							// Non-blocking:
							// To control the state.
							//void run (const bool = true);
							
							// Blocking:
							// To pause the target/worker thread until it is set to `run ([true])` again.
							void pause (void);
						protected:
							boost::thread * thread;
							//boost::thread thread (boost::bind (& LIB::machine::resources::processor::perform, this));
							
							// LIB::machine::resources::processor * processor;
							
							//bool _active;
							// Activity's state.
							//std::mutex activity;
							
							// LIB::Pointer <boost::thread> thread;
							//LIB::NAME_A <LIB::machine::devices::processor::instruction, LIB::mathematics::numbers::natural> queue;
							// std::queue <instruction> queue;
					};
					*/
				protected:
					std::mutex running_mutex;
					std::condition_variable running_condition_variable;
					
					bool running;
					// bool running, running_main;
					//std::string last_instruction;	// Name of the location of the last instruction which has been enqueued.
					//const std::string next_available_instruction_location (void) const;	// Get the next available name for an instruction.
					//const std::string next_available_instruction (void) const;	// Get the next available name for an instruction.
					
					// boost::mutex running_mutex;
					// boost::condition_variable running_condition_variable;
					
					//LIB::NAME_A <core, boost::thread::id> cores;
					//LIB::NAME_A <core, LIB::mathematics::numbers::natural> cores;
					LIB::NAME_A <boost::thread (boost::bind (& LIB::machine::resources::processor::perform, this)), LIB::mathematics::numbers::natural> cores;
					//LIB::NAME_A <LIB::machine::devices::processor::platform, mathematics::numbers::natural> threads;
					//LIB::mathematics::numbers::real _do (const LIB::machine::devices::processor::instruction) const;
					void perform (void);
					const bool execute (const instruction &);
					void pause (void) const;
					//LIB::NAME_A <LIB::mathematics::numbers::real, mathematics::numbers::natural> _results;
					
					// Get a random processor from the available ones.
					// Returns 1 to maximum.
					LIB::tools::randomizer processor_randomizer;	// processors
					const LIB::mathematics::numbers::natural random_processor (void);
					//void dummy (void);
					
					// LIB::mathematics::numbers::natural get_next_instruction (void);
					// void increment_next_instruction (void);
					//boost::asio::io_service io;
					//boost::asio::deadline_timer * timer;
				
					//LIB::mathematics::numbers::natural timeout;
					
					// LIB::machine::devices::processor::queue _queue;
					//LIB::machine::devices::processor::instructions _queue;
					
				public:
					processor (const bool & /* Run. */ = true);
					~processor (void);
					
					const LIB::mathematics::numbers::natural queue_size (void) const;
					const bool queue_empty (void) const;
					//const instruction beginning (void);
					//const bool dequeue (void);
					const instruction beginning (void) const;
					const bool dequeue (void);
					const bool enqueue (const instructions &);
					const bool enqueue (const instruction &);
					
					//void operator () (void);
					const bool run (const bool & = true);
					const bool active (void) const;
					//std::string execute (LIB::machine::devices::processor::instruction);
					
					// Queue instructions.
					//bool enqueue (LIB::machine::devices::processor::instructions);
					// bool enqueue (const LIB::machine::devices::processor::instruction &, LIB::mathematics::numbers::natural /* Processor index. */);
					//bool enqueue (const std::string & /* File name. */);
					// bool enqueue (const LIB::machine::devices::processor::instruction, LIB::language::devices::memory &);
					//void initialize (std::string);
					//LIB::mathematics::numbers::real Do (const LIB::machine::devices::processor::instruction) const;
					//LIB::NAME_V Do (const LIB::machine::devices::processor::instruction) const;
					LIB::machine::resources::memory _memory;
					//bool parse (const std::string);
					// Results:
					//bool result_exists (const LIB::mathematics::numbers::natural);
					//mathematics::numbers::real get_result (const LIB::mathematics::numbers::natural);
					//mathematics::numbers::real delete_result (const LIB::mathematics::numbers::natural);
			};
		}
	}
}

/*
LIB::Cluster::Platform::Platform (void)
{
	thread = NULL;
}

LIB::Cluster::Platform::Platform (void)
{
	delete thread;
}
*/

//#endif
