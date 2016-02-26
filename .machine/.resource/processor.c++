//#include <vector>
#include <sstream>
//#include <fstream>
#include <sstream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
//#include <boost/thread/exceptions.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "processor.h++"

// Computational platform.

LIB::machine::resources::processor::instruction::instruction (void)
{
	// inputs [0] = inputs [1] = (std::string) "";
	action = operation::none;
	//active = true;
	//processing = false;
	
	// next_instruction = "";
	
	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";
	output = "";

	//user = "Guest";	// The default user.
	// user = 0;	// No user.	// The default user, the administrator.
}

LIB::machine::resources::processor::instruction::instruction (const instruction & other)
{
	//*this = other;
	
	input [0] = other.input [0];
	input [1] = other.input [1];
	
	output = other.output;
	
	action = other.action;
	//next_instruction = other.next_instruction;
	
	//user = other.user;
	
	//return *this;
}

LIB::machine::resources::processor::instruction::instruction (const std::string & instr)
{
	*this = instr;
}

template <typename archive>
void LIB::machine::resources::processor::instruction::serialize (archive & arch, const unsigned int & version)
{
	//try
	//{
		// archive & processing;

		//destination & instructions [0];
		//destination & instructions [1];
		//archive & next_instruction;

		//archive & inputs;
		arch & input [0];
		arch & input [1];

		arch & output;

		arch & action;

		//archive & user;
	//}
	//catch (...)
	//{
	//	//next_instruction = "";
	//	action = operation::none;
	//	output = "";
	//	//user = 0;
	//}
}

LIB::machine::resources::processor::instruction::operator const std::string (void) const
{
	return LIB::serialize <LIB::machine::resources::processor::instruction> (*this);
}

//LIB::machine::resources::processor::instruction
LIB::machine::resources::processor::instruction LIB::machine::resources::processor::instruction::operator = (const std::string & serial)
{
	LIB::deserialize <LIB::machine::resources::processor::instruction> (serial, *this);
	/*
	if (LIB::deserialize <LIB::machine::resources::processor::instruction> (serial, *this))
	{
		//return *this;
		return serial;
	}
	else
	{
		return "";
	}
	*/
	return *this;
}

LIB::machine::resources::processor::instruction LIB::machine::resources::processor::instruction::operator = (const LIB::machine::resources::processor::instruction & other)
{
	input [0] = other.input [0];
	input [1] = other.input [1];
	
	output = other.output;
	
	action = other.action;
	
	//next_instruction = other.next_instruction;
	
	//user = other.user;
	
	return *this;
}

/*
LIB::machine::resources::processor::instructions::instructions (void)
{
	//active = true;
	//processing = false;

	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";

	//user = "Guest";	// The default user.
}

LIB::machine::resources::processor::instructions::instructions (const instructions & other)
{
	//operator= (other);
	instructions_ = other.instructions_;
}

template <typename Archive>
void LIB::machine::resources::processor::instructions::serialize (Archive & archive, const unsigned int & version)
{
	//archive & _instructions;

	//archive & user;
}

LIB::machine::resources::processor::instructions::operator std::string (void)
{
	return LIB::serialize <LIB::machine::resources::processor::instructions> (*this);
}

LIB::machine::resources::processor::instructions LIB::machine::resources::processor::instructions::operator = (const std::string & serial)
{
	LIB::deserialize <LIB::machine::resources::processor::instructions> (serial, *this);

	return *this;
}

LIB::machine::resources::processor::instructions LIB::machine::resources::processor::instructions::operator = (const LIB::machine::resources::processor::instructions & other)
{
	instructions_ = other.instructions_;
	
	return *this;
}
*/

//LIB::machine::resources::processor::queue::queue (void)
//{
//
//}
//
//LIB::machine::resources::processor::queue::~queue (void)
//{
//
//}
//
//template <typename Archive>
//LIB::machine::resources::processor::queue::serialize (Archive & archive, const unsigned int version)
//{
//	archive & _queue;
//}
//
//LIB::machine::resources::processor::queue::operator std::string (void) const
//{
//	return LIB::serialize <LIB::machine::resources::processor::queue> (*this);
//}
//
//LIB::machine::resources::processor::queue LIB::machine::resources::processor::queue::operator = (const std::string & serial)
//{
//	LIB::deserialize <LIB::machine::resources::processor::queue> (serial, *this);
//
//	return *this;
//}

//LIB::machine::resources::processor::core::core (void /*const bool & _run*/)
//{
	// thread = NULL;
	
	// thread = new boost::thread (boost::bind (LIB::machine::resources::processor::perform, processor));
	
	// processor = NULL;
	
	//ended = false;
	
	//run (_run);
//}

//LIB::machine::resources::processor::core::~core (void)
//{
	//if (thread != NULL/* && !ended*/)
	
	/*
	if (thread != NULL)
	{
		//try
		//{
			
			
			// thread -> join ();

			delete thread;

			// thread = NULL;

			//ended = true;
		//}
		//catch (...)
		//{

		//}
	}
	*/
	//if (processor != NULL)
	//{
	//	processor = NULL;	// Prevent recursion, as the next line triggers this function.
	//	processor -> cores.unset (boost::this_thread::get_id ());
	//}
	
	//run (_run);
//}
/*
const bool & LIB::machine::resources::processor::core::active (void) const
{
	return _active;
}

const bool LIB::machine::resources::processor::core::run (const bool & state)
{
	if (processor != NULL && state && !_active)
	{
		thread = new boost::thread (boost::bind (LIB::machine::resources::processor::perform, processor));
		
		_active = state;
		
		return _active;
	}
	else if (!state && _active)
	{
		delete thread;
		
		_active = state;
		
		return _active;
	}
	
	return true;
}
*/
/*
const LIB::machine::resources::processor::core & LIB::machine::resources::processor::core::operator = (const LIB::machine::resources::processor::core & other)
{
	//processor = other.processor;
	thread = other.thread;
	
	return *this;
}
*/
//void LIB::machine::resources::processor::/*process::*/run (const bool & value)
/*
{
	{
		boost::unique_lock <boost::mutex> lock (running_mutex);
		running = value;
	}
	
	running_condition_variable.notify_all ();
}
*/
/*
void LIB::machine::resources::processor::pause (void) const
{
	boost::unique_lock <boost::mutex> lock (running_mutex);
	
	while (! running)
	{
		running_condition_variable.wait (lock);
	}
}
*/

// Processor.

LIB::machine::resources::processor::processor (const bool & state)
{
	t = type::processor;
	
	// Initialize random seed:
	//srand ((unsigned) time (NULL));

	//timeout = 4;
	// running_main = true;
	running = state;
	
	run (state);
	
	//last_instruction = "";

	// Create the threads.

	//boost::thread * thread = new boost::thread (boost::bind (LIB::machine::resources::processor::initialize, this));

	//threads [thread -> get_id ()].thread = thread;
	//threads [boost::this_thread::get_id ()].queue
	//threads.enqueue ();
	
	//LIB::machine::resources::processor::process temp_platform;
	//threads.begin ();	// Reset the iterator to the beginning (for *this.enqueue ()).

	//#pragma omp parallel for private (temp_platform)
	//{
	//	LIB::mathematics::numbers::natural n = omp_get_thread_num ();
		LIB::mathematics::numbers::natural n;
		n =
				////omp_get_num_procs ()
				//boost::thread::hardware_concurrency ()
				1
			;
		
		for (LIB::mathematics::numbers::natural i = 1; i <= n; ++ i/*, ++ threads*/)
		{
			// temp_platform.thread = new boost::thread (boost::bind (& LIB::machine::resources::processor::perform, this));
			cores [i];
			//temp_platform.thread = new boost::thread (*this);

	//		threads [temp_platform.thread -> get_id ()] = temp_platform;
		}
	//}

	//if (! memory.search ("queue"))	// If "queue" does not exist.
	//	memory.set ("queue", _queue);

	//temp_platform.thread = NULL;
	
	//processor_randomizer.max (cores.size ());
	
	//std::cout << "Created threads." << std::endl;
}

LIB::machine::resources::processor::~processor (void)
{
	// running_main = false;

	/*
		Complete any remaining instructions in the queue,
		so that the threads can be joined
		and so that they do not remain blocked, if they are paused.
	*/
	//run (true);
	// run (false);

	// Wait for other threads to finish?
	//io.reset ();

	//timer -> expires_from_now (boost::posix_time::seconds (timeout));
	//timer -> async_wait (boost::bind (& LIB::machine::resources::processor::dummy, this));
	
	//io.run ();

	//if (timer != NULL)
	//{
	//	delete timer;
	//	timer = NULL;
	//}
}

const bool LIB::machine::resources::processor::active (void) const
{
	//return !cores.empty ();
	return running;
}

void LIB::machine::resources::processor::pause (void) const
{
	//boost::unique_lock <boost::mutex> lock (running_mutex);
	std::unique_lock<std::mutex> lock (running_mutex);
	
	running_condition_variable.wait (lock, [] { return running; });
}

const bool LIB::machine::resources::processor::run (const bool & value)
{
	{
		//boost::unique_lock <boost::mutex> lock (running_mutex);
		std::unique_lock <std::mutex> lock (running_mutex);
		running = value;
	}
	
	running_condition_variable.notify_all ();
	
	//return true;
	
	//if (value && !active ())
	//{
		// Start.
		/*
		LIB::machine::resources::processor::core temp_core;
		LIB::mathematics::numbers::natural n;
		n =
				////omp_get_num_procs ()
				//boost::thread::hardware_concurrency ()
				1
			;
		//threads.begin ();	// Reset the iterator to the beginning (for *this.enqueue ()).
		
		for (LIB::mathematics::numbers::natural i = 0; i < n; ++ i)
		{
			//temp_core.thread = new boost::thread (boost::bind (& LIB::machine::resources::processor::perform, this));
			// temp_core.processor = this;
			//temp_platform.thread = new boost::thread (*this);
			
			// temp_core.run ();
			
			//if (temp_core.active ())
			//{
				//temp_platform.thread -> detach ();
				//cores [temp_core.thread -> get_id ()] = temp_core;
				cores.add (temp_core);
			//}
		}
		
		// This is important, so that its destructor does not delete the thread, if that thread is valid.
		temp_core.thread = NULL;
		
		unsigned long long int count;
		std::stringstream ss;
		ss << cores.size ();
		ss >> count;
		processor_randomizer.max (count);
		*/
		
		
	//}
	//else if (!value && active ())
	//{
		// Stop.
		
		//cores.clear ();
		
		//std::unique_lock <std::mutex> lock (activity);
	//}
	
	return true;
}

//void LIB::machine::resources::processor::run (const bool value)
//{
//	LIB::mathematics::numbers::natural n = threads.size ();
//
//	for (LIB::mathematics::numbers::natural i = 0; i < n; ++ i, ++ threads)
//	{
//		threads.current ().run (value);
//	}
//}

//bool LIB::machine::resources::processor::enqueue (LIB::machine::resources::processor::instructions _instructions)
//{
//	////return enqueue (_instruction, LIB::random (threads.size (), 1));
//
//	//std::string k, v;
//	////std::stringstream ss;
//	////std::vector <std::string> strings;
//
//	////strings = boost::split (strings, _instruction.next_instruction, boost::is_any_of (":"));
//
//	////std::ofstream ofs("archive.txt");
//	////boost::archive::text_oarchive oa (ofs);
//
//	////k = strings.operator[] (0);
//	//k = _instruction.id;
//	////ss << _instruction;
//	////ss >> v;
//	//v = _instruction;
//	////_instruction.parse (v);
//
//	//memory.set (k, v);
//
//	//return true;
//	//return enqueue (_instruction, random_processor ());	// Original.
//	///
//
//	LIB::mathematics::numbers::natural n, i, index;
//
//	index = random_processor ();
//
//	/*
//		Assign the instruction to a random processor;
//		this means to add it to the random processor's instruction queue.
//	*/
//
//	//threads.begin ();
//	//boost::thread::id * id = & threads.current ().thread -> get_id ();	//boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//boost::thread::id id = boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//++ threads;
//
//	//LIB::machine::resources::processor::process * process = & threads.current ();//& threads [* id];	// Prevent searching through the array again; this may increase performance.
//	//LIB::machine::resources::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
//	LIB::machine::resources::processor::process * thread = & threads.get_value (index);	// Prevent searching through the array again; this may increase performance.
//
//	//return process -> queue.enqueue (_instruction);
//	//return threads.current ().queue.enqueue (_instruction);
//	
//	//return threads.get_value (index).queue.enqueue (_instruction);
//	for (_instructions._instructions.begin (), n = _instructions._instructions.size (), i = 0; i < n; ++ _instructions._instructions, ++ i)
//	{
//		//threads.get_value (index).queue.push (_instructions._instructions.current ());
//		thread -> queue.push (_instructions._instructions.current ());
//	}
//
//	return true;
//
//	//if (process -> queue.enqueue (_instruction))
//	//{
//	//	//process -> run (true);
//
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//	//return true;
//}

//bool LIB::machine::resources::processor::enqueue (const LIB::machine::resources::processor::instruction & _instruction, LIB::mathematics::numbers::natural index)
//{
//	/*
//		Assign the instruction to a random processor;
//		this means to add it to the random processor's instruction queue.
//	*/
//
//	//threads.begin ();
//	//boost::thread::id * id = & threads.current ().thread -> get_id ();	//boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//boost::thread::id id = boost::this_thread::get_id ();	// Select the current processor from the available ones.
//	//++ threads;
//
//	//LIB::machine::resources::processor::process * process = & threads.current ();//& threads [* id];	// Prevent searching through the array again; this may increase performance.
//	//LIB::machine::resources::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
//
//	//return process -> queue.enqueue (_instruction);
//	//return threads.current ().queue.enqueue (_instruction);
//	
//	//return threads.get_value (index).queue.enqueue (_instruction);
//
//	//// Indexing starts at 
//	//if (index == 0)
//	//	index = 1;
//
//	while (index > threads.size ())
//		index = index - threads.size ();
//
//	threads.get_value (index).queue.push (_instruction);
//	
//	return true;
//
//	//if (process -> queue.enqueue (_instruction))
//	//{
//	//	//process -> run (true);
//
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//	//return true;
//}

//bool LIB::machine::resources::processor::enqueue (const std::string & file_name)
//{
//	//if (!parse (instructions))
//	//	return false;
//
//	std::ifstream infile;
//	std::string token;
//	//char cc; // Current character.
//
//	infile.open (file_name);
//
//	if (!infile.is_open ())
//		return false;
//
//	//LIB::machine::resources::processor::parser _parser;
//	//std::queue <std::string> parentheses;
//	LIB::NAME_A <std::string, LIB::mathematics::numbers::natural> parentheses;
//	std::queue <LIB::machine::resources::processor::instruction> instructions;
//	//LIB::NAME_A <LIB::machine::resources::processor::instruction, LIB::mathematics::numbers::natural> instructions;
//	LIB::machine::resources::processor::instruction instruction;
//	std::string next_instruction = (LIB::NAME_V) get_next_instruction ();	// Next available instruction ID.
//	LIB::mathematics::numbers::natural next_subinstruction = 0;
//	LIB::mathematics::numbers::natural processor = random_processor ();
//	//static enum tokens {};
//	//static std::map <std::string, tokens> tokens_map;
//	//static char sz [255];
//	//char token_c;
//	bool serialize = false;
//	//bool c = true;	// Continue the main loop.
//	bool commenting = false;	// For multi-line comments.
//
//	while (infile >> token)
//	{
//		if (token == "*/" && commenting)
//		{
//			commenting = false;
//		}
//		else if (commenting)
//		{
//			continue;	// Skip string/token if commenting.
//		}
//		else if (token == "/*")
//		{
//			// Skip until the token "*/" is encountered. If it is not encountered, assume that the comment spans until the end of the file.
//			//token_c = infile.peek ();
//			commenting = true;
//		}
//		//else if (token == "*/")
//		//{
//		//	commenting = false;
//		//}
//		else if (token == "//")
//		{
//			// Skip the whole current line.
//			std::getline (infile, token, '\n');
//		}
//		else if (token == "#include")
//		{
//
//		}
//		else if (token == "#serialize")
//		{
//			serialize = true;
//		}
//		else if (token == "{")
//		{
//			//parentheses.push (token);
//		}
//		else if (token == "}")
//		{
//			if (serialize)
//				serialize = false;
//
//			//parentheses.pop ();
//		}
//		else if (token == "global")
//		{
//
//		}
//		//else if (token == "shared")
//		//{
//
//		//}
//		else if (token == "cout")
//		{
//			do
//			{
//				if (!(infile >> token))
//					break;
//
//				if (token == "endl")
//				{
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::machine::resources::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					//instruction.id = next_instruction + ":" + (next_subinstruction == 0 ? 0 : next_subinstruction);
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				else if (token [0] == '$')
//				{
//					//instruction.inputs [0] = token.substr (1);
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::machine::resources::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				else if (token != "<<" && token != ";")
//				{
//					instruction.inputs [0] = token;
//					instruction._operation = LIB::machine::resources::processor::operation::echo;
//
//					//if (!serialize)
//					//	processor = random_processor ();
//
//					instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//					instruction.processor = processor;
//
//					//instructions.enqueue (instruction);
//					instructions.push (instruction);
//				}
//				//else if (token == ";" && !serialize)
//				//{
//				//	processor = random_processor ();
//				//}
//			}
//			while (token != ";");
//		}
//		else if (token [0] == '$')
//		{
//			//std::string destination = token.substr (1);
//			std::string destination = token;
//
//			do
//			{
//				if (!(infile >> token))
//					break;
//
//				if (token == "=")
//				{
//					// Set the output.
//					instruction.output = destination;
//
//					// Get the first operand:
//					if (!(infile >> token))
//						break;
//
//					//instruction.inputs [0] = token [0] == '$' ? token.substr (1) : token;
//					instruction.inputs [0] = token;
//
//					// Get the operation:
//					if (!(infile >> token) || token.length () != 1)
//						break;
//
//					switch (token [0])
//					{
//						case '+':
//							instruction._operation = LIB::machine::resources::processor::operation::add;
//							
//							break;
//
//						case '-':
//							instruction._operation = LIB::machine::resources::processor::operation::substract;
//							
//							break;
//
//						case '*':
//							instruction._operation = LIB::machine::resources::processor::operation::multiply;
//							
//							break;
//						case '/':
//							instruction._operation = LIB::machine::resources::processor::operation::divide;
//							
//							break;
//
//						case '%':
//							instruction._operation = LIB::machine::resources::processor::operation::modulo;
//							
//							break;
//
//						case ';':
//							instruction._operation = LIB::machine::resources::processor::operation::assign;
//							
//							//break;
//
//						//default:
//						//	break;
//					}
//
//					// Get the next token:
//					//if (!(infile >> token))
//					//	break;
//
//					if (token == ";")
//					{
//						instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//						instruction.processor = processor;
//
//						//instructions.enqueue (instruction);
//						instructions.push (instruction);
//
//						break;
//					}
//					else
//					{
//						// Get the second operand, if applicable:
//						if (!(infile >> token))
//							break;
//
//						//instruction.inputs [1] = token [0] == '$' ? token.substr (1) : token;
//						instruction.inputs [1] = token;
//
//
//						//if (!serialize)
//						//	processor = random_processor ();
//
//						instruction.next_instruction = next_instruction + ":" + (LIB::NAME_V) next_subinstruction;
//						instruction.processor = processor;
//
//						//instructions.enqueue (instruction);
//						instructions.push (instruction);
//
//						if (!(infile >> token))	// Expect the ';' character.
//							break;
//					}
//				}
//				//else if (token == ";" && !serialize)
//				//{
//				//	processor = random_processor ();
//				//}
//				else
//					break;
//			}
//			while (token != ";");
//		}
//		
//		if (serialize)
//		{
//			++ next_subinstruction;
//		}
//		else
//		{
//			processor = random_processor ();
//
//			next_instruction = (LIB::NAME_V) get_next_instruction ();
//			increment_next_instruction ();
//			//memory.set ("next instruction", (LIB::NAME_V) (++ ((LIB::NAME_V) memory.get ("next instruction"))));	// Update the ID.
//
//			if (next_subinstruction != 0)
//				next_subinstruction = 0;	// Reset the next subinstruction.
//		}
//	}
//
///*
//	while (c && infile >> cc)
//	{
//		if (comment && cc == '*')
//		{
//			if (!(infile >> cc))
//				break;
//
//			if (cc == '/')
//				comment = false;
//		}
//
//		if (comment)
//			continue;
//
//		switch (cc)
//		{
//			case '/':
//				if (!(infile >> cc))
//				{
//					c = false;
//
//					break;
//				}
//
//				switch (cc)
//				{
//					case '/':
//						// Skip the whole current line.
//						std::getline (infile, token);
//
//						break;
//
//					case '*':
//						comment = true;
//				}
//
//				break;
//
//			case '*':
//		}
//
//		if (!serialize)
//			processor = random_processor ();
//	}
//	
//*/
////	_parser.parse (file_name, instructions);
//	infile.close ();
//	threads.begin ();
//
//	while (! instructions.empty ())
//	{
//		//instructions.begin ();	// Update the "current".
//
//		//enqueue (instructions.current (), instructions.current ().processor);
//		//enqueue (instructions.front (), instructions.front ().processor);
//		enqueue (instructions.front ());
//		//instructions.dequeue ();
//		instructions.pop ();
//	}
//	
//	return true;
//}

//LIB::mathematics::numbers::natural LIB::machine::resources::processor::get_next_instruction (void)
//{
//	return 1;
//}
//
//void LIB::machine::resources::processor::increment_next_instruction (void)
//{
//	
//}

// Each processor/thread would be executing this for the duration of the this object, when there are instructions to be run.
void LIB::machine::resources::processor::perform (void)
//void LIB::machine::resources::processor::operator () (void)
{
	/*
		This is the concept:

		While there are instructions to be performed, perform them;
		otherwise, wait (preferably, without consuming any resources) for any instruction to come.
	*/
	
	//threads.begin ();
	//++ threads;
	//boost::thread::id id = threads.current_key ();
	
	//std::string instruction;
	//instruction instr;

	
	// boost::thread::id id = boost::this_thread::get_id ();	// Select a random processor from the avaiable ones.
	//std::cout << id << " Running once..." << std::endl;

	//LIB::mathematics::numbers::natural id = 1;
	// LIB::machine::resources::processor::process * process = & threads [id];	// Prevent searching through the array again; this may increase performance.
	//std::cout << id;

	//LIB::machine::resources::processor::instructions instructions_temp;
	// LIB::machine::resources::processor::instructions current_instructions;
	// LIB::mathematics::numbers::natural index, size;

	//while (running_main)
	//next_instruction = _memory.get ("Next", "Instructions");
	
	while (true)
	{
		//pause ();
		
		//instruction = dequeue ();

		//while (! instruction.empty ())
		while (!queue_empty ())
		{
			// Wait if we are paused;
			// pause ();

			//LIB::deserialize <LIB::machine::resources::processor::instructions> (memory.get ("queue"), instructions_temp);
			//current_instruction = pop ();

			//current_instructions._instructions.begin ();
			//for (index = 0, size = current_instructions._instructions.size (); index < size; ++ index, ++ current_instructions._instructions)
			//{
			//	if (!running_main)
			//		break;

			//	//process -> pause ();
			//	pause ();

			//	_do (current_instructions._instructions.current ());
			//}
			//if (mem.search ("0_0"))

			// next_instruction = _memory.get ("Next", "Instructions");

			//if (! next_instruction.empty ())
			//{
				//instruction _instruction;
			
				//_instruction = dequeue ();
				//instr = instruction;
				//instr = beginning ();
				execute (beginning ());
				//if (instr.action != operation::none)
				//{
				//	execute (instr);
				//}

	//			// If execution succeeded.
	//			if (_instruction.action != operation::none && execute (_instruction))
	//			{
	//				// To be done: if this instruction has already been processed by another processor, and if it has possibly already been advanced...
	//				// If this instruction has not already been dequeued by another processor, and if it has not already been advanced.
	//				if (next_instruction == _memory.get ("Next", "Instruction"))
	//				{
	//					// Set the Next Instruction to point to the next instruction.
	//					_memory.set ("NI", _instruction.next_instruction);
	//
	//					// Remove the instruction from the queue.
	//					_memory.unset (next_instruction /* The instruction that has just been processed. */);
	//
	//					// If this is the last instruction, reset the queue to be empty.
	//					if (_instruction.next_instruction.empty ())
	//					{
	//						_memory.set ("LI", "");
	//						//mem.set ("NI", "");
	//					}
	//				}
	//			}
			//}

			//while (! instructions_temp._instructions.empty ())
			//{
			//	if (!running_main)
			//		break;

			//	//process -> pause ();
			//	pause ();

			//	//std::cout << id << " Running..." << std::endl;

			//	//_do (process -> queue.current ());
			//	_do (instructions_temp._instructions.front ());

			//	//process -> queue.dequeue ();
			//	 instructions_temp._instructions.pop ();
			//}

			//next_instruction = _memory.get ("Next", "Instructions");
			//instruction = dequeue ();
			dequeue ();
		}
		
		//boost::this_thread::sleep (boost::posix_time::minutes (1));
		pause ();
	}
}

const bool LIB::machine::resources::processor::execute (LIB::machine::resources::processor::instruction & instr)
{
	switch (instr.action)
	{
		case LIB::machine::resources::processor::operation::addition:
		case LIB::machine::resources::processor::operation::substraction:
		case LIB::machine::resources::processor::operation::multiplication:
		case LIB::machine::resources::processor::operation::division:
		case LIB::machine::resources::processor::operation::modulo:
		case LIB::machine::resources::processor::operation::exponentiation:
			// For variable variables.
			while (((std::string) instr.input [0]) [0] == '$')
			{
				_instruction.input [0] = _memory.get (instr.input [0]);
			}
			
			while (((std::string) instr.input [1]) [0] == '$')
			{
				_instruction.input [1] = _memory.get (instr.input [1]);
			}
			
			switch (instr.action)
			{
				case LIB::machine::resources::processor::operation::addition:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] + instr.input [1]);
					
					//break;

				case LIB::machine::resources::processor::operation::substraction:
					return _memory.set (instr.output, instr.input [0] - instr.input [1]);
					
					//break;

				case LIB::machine::resources::processor::operation::multiplication:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] * (LIB::NAME_V) instr.input [1]);
					
					//break;

				case LIB::machine::resources::processor::operation::division:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] / instr.input [1]);
					
					//break;

				case LIB::machine::resources::processor::operation::modulo:
					return _memory.set (instr.output, (LIB::NAME_V) instr.input [0] % instr.input [1]);
					
					//break;
				case LIB::machine::resources::processor::operation::exponentiation:
					return _memory.set (instr.output, (LIB::NAME_V) (instr.input [0] ^ instr.input [1]));
					
					//break;
			}
			
			//break;
			
		case LIB::machine::resources::processor::operation::output:
			if ((std::string) instr.input [0] == "endl")
			{
				std::cout << std::endl;
			}
			else if ((std::string) instr.input [0] == "tab")
			{
				std::cout << '\t';
			}
			else if (((std::string) instr.input [0]) [0] == '$')
			{
				//while (((std::string) _instruction.inputs [0]) [0] == '$')
				//{
				//	_instruction.inputs [0] = memory.get (_instruction.inputs [0]);
				//}

				//std::string op = mem.get (_instruction.inputs [0]);
				//std::cout << op;
				std::cout << _memory.get (instr.input [0]);
			}
			else
			{
				//std::string str = _instruction.inputs [0];
				//std::cout << str;
				std::cout << instr.input [0];
			}
			
			//std::cout.flush ();
			
			return true;
			//break;

		case LIB::machine::resources::processor::operation::modulus:
			return _memory.set (instr.output, (LIB::NAME_V) LIB::tools::modulus (instr.input [0]));
			
			//break;
			
		case LIB::machine::resources::processor::operation::complement:
			return _memory.set (instr.output, (LIB::NAME_V) LIB::tools::complement (instr.input [0]));
			
			//break;
			
		case LIB::machine::resources::processor::operation::assignment:
			while (((std::string) instr.input [0]) [0] == '$')
			{
				instr.input [0] = _memory.get (instr.input [0]);
			}
			
			return _memory.set (instr.output, instr.input [0]);
			
			//break;
		//default:
		//	return LIB::mathematics::numbers::default;
	}
	
	return true;
}

/*
bool LIB::machine::resources::processor::enqueue (const LIB::machine::resources::processor::instruction _instruction, LIB::machine::resources::memory & _memory)
{

}
*/
/*
void LIB::machine::resources::processor::pause (void) const
{
	condition_variable.wait (lock, [] { return ready; });
}
*/
const LIB::mathematics::numbers::natural LIB::machine::resources::processor::random_processor ()
{
	//LIB::mathematics::numbers::natural size = threads.size ();

	//return size >= 2 ? LIB::random (size, 1) : 1;
	return processor_randomizer.generate ();
}

const LIB::machine::resources::processor::instruction LIB::machine::resources::processor::beginning (void) const
{
	instructions _instructions;
	instruction _instruction;
	std::string instr;
	LIB::machine::resources::memory::key k;
	
	k.group = "Instructions";
	k.name = "Beginning";
	
	instr = _memory.get (k);
	
	if (!instr.empty ())
	{
		k.name = instr;
		
		_instructions = _memory.get (k);
		
		if (!_instructions._instructions.empty ())
		{
			_instruction = _instructions._instructions.front ();
		}
	}
	
	//else
	//{
	//	_memory.unset (k);
	//}
	
	return _instruction;
}

//LIB::machine::resources::processor::instruction LIB::machine::resources::processor::dequeue (void)
//const std::string LIB::machine::resources::processor::dequeue (void)
const bool LIB::machine::resources::processor::dequeue (void)
{
	instructions _instructions;
	std::string _instrs;
	LIB::machine::resources::memory::key k;
	
	k.group = "Instructions";
	k.name = "Beginning";
	
	_instrs = _memory.get (k);
	
	if (_instrs.empty ())
	{
		return false;
	}
	
	k.name = _instrs;
	//_instrs = _memory.get (k);
	//_instructions = _instrs;
	_instructions = _memory.get (k);
	
	_instructions._instructions.pop ();
	
	if (!_instructions._instructions.empty ())
	{
		return _memory.set (k, _instructions);
	}
	else
	{
		return _memory.unset (k);
	}
}

/*
bool LIB::machine::resources::processor::enqueue (LIB::machine::resources::processor::instructions instructions_)
{
	//unsigned long long int c = instructions_.instructions_.size ();
	//for (unsigned long long int i = 0; i < c; ++ i)
	while (! instructions_.instructions_.empty ())
	{
		if (! enqueue (instructions_.instructions_.front ()))
		{
			return false;
		}
		
		instructions_.instructions_.pop ();
	}
	
	return true;
*/
/*	
	LIB::NAME_V instruction_key, instruction_subkey;
	instruction_key = instruction_subkey = 0;
	//std::string val;
	
	if (mem.search ("instruction_queue_vacant"))
	{
		while (mem.get ("instruction_queue_vacant") != "true")
		{
			// Wait.
		}
	}
	
	if (!mem.set ("instruction_queue_vacant", "false"))
		return false;
	
	// Find the key:
	while (mem.search (((std::string) instruction_key) + "_0"))
	{
		++ instruction_key;
	}
	
	//// Find the sub-key:
	//while (memory.search ((std::string) instruction_key + "_" + (std::string) instruction_subkey))
	//{
	//	++ instruction_subkey;
	//}
	
	//// Enque the first instruction:
	//if (! mem.set (instruction_key, _instructions._instructions.front ()))
	//	return false;
	
	//_instructions._instructions.pop ();
	
	// Enqueue the rest of the instructions:
	while (instructions_.instructions_.size () > 0)
	{
		assert (mem.set (((std::string) instruction_key) + "_" + ((std::string) instruction_subkey), instructions_.instructions_.front ()));

		instructions_.instructions_.pop ();
		++ instruction_subkey;
	}
	
	assert (mem.set ("instruction_queue_vacant", "true"));
	
	return true;
*/ 
//}

//const bool LIB::machine::resources::processor::enqueue (LIB::machine::resources::processor::instruction _instruction)
//{
//	instruction _instr;
//	std::string instr, last_instr, next_instr;
//	LIB::machine::resources::memory::key k;
//	
//	k.name = "Last";
//	k.group = "Instructions";
//	
//	retry:
//	
//	last_instr = _memory.get (k);
//	//next_instr = next_available_instruction_location ();	// The next available instruction should be obtained as late as possible, just before it would be used.
//	
//	// If the queue has not been empty, set the last queued instruction's "next_instruction" to refer to this one.
//	//if (! last_instr.empty ())
//	//{
//		//// "last_instruction" is a reference.
//		//last_instr = mem.get (last_instruction);
//		
//		if (! last_instr.empty ())
//		{
//			// Hope that the instruction is not dequeued while we are here, by another processor.
//			
//			//mem.set (last_instr, "ABC");
//			//instr = _memory.get (k);
//			//try
//			//{
//				k.name = last_instr;
//				instr = _memory.get (k);
//				//_instr = boost::any_cast <std::queue <LIB::machine::resources::processor::instruction>> (_memory.get (k));
//			//}
//			//catch (...)
//			//{
//			//	return false;
//			//}
//			
//			// If this is a valid instruction.
//			if (! instr.empty ())
//			{
//				_instr = instr;
//				
//				next_instr = next_available_instruction_location ();
//				
//				_instr.next = next_instr;
//				// To be fixed: if this instruction has already been dequeued, in the meantime, by another process, still set the following?
//				if (last_instr == _memory.get ("Last", "Instructions"))	// In case another process changed/set this.
//				{
//					_memory.set (last_instr, _instr, "Instructions");
//					//mem.set ("NI", "0");
//				}
//				else
//				{
//					goto retry;
//				}
//			}
//		}
//		else
//		// The queue has been empty. Set the "Next Instruction" and "Last Instruction" to this one.
//		{
//			next_instr = next_available_instruction_location ();
//			
//			if (! _memory.set ("Next", next_instr, "Instructions"))
//			{
//				return false;
//			}
//		}
//	//}
//	
//	// Set the Last Instruction which was enqueued to this one.
//	//last_instruction = next_instr;
//	if (! _memory.set ("Last", next_instr))
//	{
//		return false;
//	}
//	
//	return _memory.set (next_instr, _instruction, "Instructions");
//	
//	
///*
//	LIB::NAME_V instruction_key, instruction_subkey;
//	instruction_key = instruction_subkey = 0;
//	
//	if (mem.search ("instruction_queue_vacant"))
//	{
//		while (mem.get ("instruction_queue_vacant") != "true")
//		{
//			// Wait.
//		}
//	}
//	
//	if (mem.set ("instruction_queue_vacant", "false"))
//		return false;
//	
//	while (mem.search (((std::string) instruction_key) + "_0"))
//	{
//		++ instruction_key;
//	}
//	
//	mem.set (((std::string) instruction_key) + "_0", instruction_);
//	
//	return mem.set ("instruction_queue_vacant", "true");
//*/
//}

const bool LIB::machine::resources::processor::enqueue (const LIB::machine::resources::processor::instructions & _instructions)
{
	return _memory.set (next_available_instruction_location (), _instructions);
}

const bool LIB::machine::resources::processor::enqueue (const LIB::machine::resources::processor::instruction & _instruction)
{
	instructions _instructions;
	
	_instructions._instructions.push (_instruction);
	
	return enqueue (_instructions);
}

//const LIB::machine::resources::memory::key LIB::machine::resources::processor::next_available_instruction_location (void)
//{
//	LIB::NAME_V next_instr;
//	
//	next_instr = 1;
//	
//	//if (! _memory.get ("Last", "Instructions").empty ())
//	//{
//	//	next_instr = 1;
//	//}
//	//else
//	//if (! _memory.get ("Last", "Instructions").empty ())
//	//{
//		//next_instr = 1;
//		
//		while (_memory.exist (next_instr))
//		{
//			++ next_instr;
//		}
//	//}
//	
//	return next_instr;
//}

const LIB::machine::resources::memory::key LIB::machine::resources::processor::next_available_instruction_location (void)
{
	LIB::machine::resources::memory::key k;
	LIB::NAME_V next_instr;
	
	next_instr = 1;
	
	k.name = next_instr;
	k.group = "Instructions";
	//if (! _memory.get ("Last", "Instructions").empty ())
	//{
	//	next_instr = 1;
	//}
	//else
	//if (! _memory.get ("Last", "Instructions").empty ())
	//{
		//next_instr = 1;
		
		while (_memory.exist (k))
		{
			++ next_instr;
			
			k.name = next_instr;
		}
	//}
	
	return k;
}
