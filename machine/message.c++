#include <iostream>
#include <fstream>
#include <string>

#include "cluster.h++"

LIB::cluster::cluster::cluster (void)
{
	error ["message"] = "";
	error ["code"] = "0";
	//std::cout << "message: " << error ["message"] << std::endl;
	//std::cout << "code: " << error ["code"] << std::endl;
	
	
	//error.tolerant = false;
	//error.set ((std::string) "message", "");
	//error.set ((std::string) "code", "0");
}

LIB::cluster::cluster::~cluster (void)
{

}

//bool LIB::cluster::cluster::enqueue (const std::string file_name)
//{
//	////if (!parse (instructions))
//	////	return false;
//
//	//std::ifstream infile;
//	//std::string token;
//
//	//infile.open (file_name);
//
//	//if (!infile.is_open ())
//	//	return false;
//
//	//while (infile >> token)
//	//{
//	//	;
//	//}
//	return processor.enqueue (file_name);
//}

//void LIB::cluster::cluster::run (const bool & _run)
//{
//	processor.run (_run);
//}

bool LIB::cluster::cluster::enqueue (const std::string & file_name)
{
	std::queue <LIB::cluster::processor::instructions> instructions;
	//std::string error_message;
	
	if (interpreter_.enqueue (file_name, instructions, error [/*(std::string) */"message"]) == 0)
	{
		while (! instructions.empty ())
		{
			processor_.enqueue (instructions.front ()); 

			instructions.pop ();
		}
		
		return true;
	}
	else
	{
		return false;
	}
//	//if (!parse (instructions))
//	//	return false;
//
//	std::ifstream infile;
//	std::string token;
//	//char cc; // Current character.
//
//	infile.open (file_name);
//
//	if (! infile.is_open ())
//		return false;
//
//	//LIB::cluster::processor::parser _parser;
//	//std::queue <std::string> parentheses;
//	LIB::NAME_A <std::string, LIB::mathematics::numbers::natural> parentheses;
//	std::queue <LIB::cluster::processor::instruction> instructions;
//	//LIB::NAME_A <LIB::cluster::processor::instruction, LIB::mathematics::numbers::natural> instructions;
//	LIB::cluster::processor::instruction instruction;
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
//					instruction._operation = LIB::cluster::processor::operation::echo;
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
//					instruction._operation = LIB::cluster::processor::operation::echo;
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
//					instruction._operation = LIB::cluster::processor::operation::echo;
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
//							instruction._operation = LIB::cluster::processor::operation::add;
//							
//							break;
//
//						case '-':
//							instruction._operation = LIB::cluster::processor::operation::substract;
//							
//							break;
//
//						case '*':
//							instruction._operation = LIB::cluster::processor::operation::multiply;
//							
//							break;
//						case '/':
//							instruction._operation = LIB::cluster::processor::operation::divide;
//							
//							break;
//
//						case '%':
//							instruction._operation = LIB::cluster::processor::operation::modulo;
//							
//							break;
//
//						case ';':
//							instruction._operation = LIB::cluster::processor::operation::assign;
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
	//return false;
}

//bool LIB::cluster::cluster::enqueue (const LIB::cluster::processor::instructions & file_name)
//{
//	
//}
//
//bool LIB::cluster::cluster::enqueue (const LIB::cluster::processor::instruction & file_name)
//{
//
//}

/*const LIB::NAME_A <std::string, std::string> & LIB::cluster::cluster::get_error (void) const
{
	return error;
}*/

std::string LIB::cluster::cluster::get_error_code (void)
{
	return (std::string) (error [(std::string) "code"]);
}

std::string LIB::cluster::cluster::get_error_message (void)
{
	return (std::string) (error [(std::string) "message"]);
}
