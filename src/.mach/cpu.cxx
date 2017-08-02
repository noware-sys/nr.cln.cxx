#pragma once

//#include "processor.hdr.cxx"

const std::string noware::mach::cpu::grp_dft = "noware::mach::cpu";

noware::mach::cpu::instr::instr (void)
{
	oprn = opr::none;
	
	oprnd [0] = oprnd [1] = "";
	//oprnd_src_ref = false;
	ref [0] = ref [1] = false;
	
	thread_id = "";
}

noware::mach::cpu::instr::instr (const std::string & other)
{
	//oprn = opr::none;
	//deserialize (other);
	*this = other;
}

noware::mach::cpu::instr::~instr (void)
{
}

template <typename archive>
void noware::mach::cpu::instr::serialize (archive & arch, const unsigned int &/* version*/)
{
	arch & oprn;
	
	arch & oprnd [0];
	arch & oprnd [1];
	//arch & oprnd [2];
	
	arch & _ref [0];
	arch & _ref [1];
	
	arch & _offset [0];
	arch & _offset [1];
	
	arch & offset [0];
	arch & offset [1];
	
	arch & thread_id;
	
	//arch & oprnd_src_ref;
}

const bool noware::mach::cpu::instr::deserialize (const std::string & serial)
{
	return noware::deserialize <noware::mach::cpu::instr> (*this, serial);
}

const std::string noware::mach::cpu::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::mach::cpu::instr> (serial, *this))
		return serial;
	else
		return "";
}

const std::string noware::mach::cpu::instr::val (void) const
{
	return oprnd [0];
}

const noware::mach::cpu::instr & noware::mach::cpu::instr::operator = (const instr & other)
{
	oprn = other.oprn;
	
	oprnd [0] = other.oprnd [0];
	oprnd [1] = other.oprnd [1];
	
	ref [0] = other.ref [0];
	ref [1] = other.ref [1];
	
	thread_id = other.thread_id;
	
	return *this;
}

const std::string & noware::mach::cpu::instr::operator = (const std::string & other)
{
	deserialize (other);
	return other;
}

noware::mach::cpu::instr::operator const std::string (void) const
{
	return serialize ();
}

noware::mach::cpu::cpu (void)
{
	exen = nullptr;
	//assert (node.join (grp_dft));
	//node.join ("noware::mach::thread::1");
}

noware::mach::cpu::~cpu (void)
{
	stop ();
}

const bool noware::mach::cpu::stop (void)
{
	if (!status ())
		return true;
	
	delete exen;
	exen = nullptr;
	
	return true;
}

const bool noware::mach::cpu::status (void) const
{
	return exen != nullptr;
}

const bool noware::mach::cpu::start (void)
{
	if (status ())
		return true;
	
	exen = new boost::thread (boost::bind (boost::mem_fn (&noware::mach::cpu::exe), this));
	
	return true;
}

void noware::mach::cpu::exe (void)
{
	std::cout << "noware::mach::cpu::exe()::in scope" << std::endl;
	
	instr inst;
	instr inst_next;
	
	noware::nr index_max;
	noware::nr index;
	
	noware::var src;
	noware::var dest;
	
	noware::var src_offset;
	noware::var dest_offset;
	
	std::string thread_id;
	/*
	//zmq::msg msg_thread;
	std::map <std::string, std::string> map_thread;
	std::string map_thread_serial;
	zmq::msg msg;
	
	map_thread ["subject"] = "notification";
	map_thread ["success"] = "1";
	
	noware::serialize <std::map <std::string, std::string>> (map_thread_serial, map_thread);
	
	msg = map_thread_serial;
	
	msg.prepend (zmq::msg::frame ("dummy_request_token"));
	*/
	
	while (true)
	{
		std::cout << "noware::mach::cpu::exe()::while(true)::in scope" << std::endl;
		
		while (!empty ())
		{
			std::cout << "noware::mach::cpu::exe()::while(!empty())::in scope" << std::endl;
			
			// fetch next (and dequeue)
			std::cout << "noware::mach::cpu::next_dequeue()" << std::endl;
			inst = next_dequeue ();
			
			// there is not a decode step
			thread_id = std::string ("thread ") + inst.thread_id;
			
			// execute
			//inst.val ();
			/*
			if (inst.oprnd_src_ref)
			{
				inst.oprnd [0] = get (inst.oprnd [0]);
			}
			*/
			//set (inst.oprnd [2]/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
			////set (grp, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
			//if ()
			//set (inst.oprnd [2]/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
			std::cout << "noware::mach::cpu::exe::set(\"thread " << inst.thread_id << "\"," << inst.oprnd [1] << "," << inst.oprnd [0] << ")" << std::endl;
			
			switch (inst.oprn)
			{
				case cpu::opr::set:
					std::cout << "noware::mach::cpu::exe::instr.opr==set" << std::endl;
					
					if (inst._ref [0]/* source*/)
					{
						std::cout << "noware::mach::cpu::exe::instr.ref[src]==true" << std::endl;
						
						if (inst._offset [0])
							if
							(
								//inst.oprnd [0].kind () == noware::var::type::nr
								//&&
								inst.offset [0].kind () == noware::var::type::nr
							)
								src = get (thread_id, inst.oprnd [0] + inst.offset [0]);
							else
							{
								//src_offset = get (thread_id, inst.offset [0]);
								//src = get (thread_id, src_offset);
								src = get (thread_id, inst.oprnd [0] + get (thread_id, inst.offset [0]));
							}
						else
							src = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.oprnd [0]);
					}
					else
					{
						std::cout << "noware::mach::cpu::exe::instr.ref[src]==false" << std::endl;
						
						src = inst.oprnd [0];
					}
					
					if (inst._ref [1]/* destination*/)
					{
						std::cout << "noware::mach::cpu::exe::instr.ref[dest]==true" << std::endl;
						
						//dest = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.oprnd [1]);
						
						if (inst._offset [1])
							if
							(
								//inst.oprnd [0].kind () == noware::var::type::nr
								//&&
								inst.offset [1].kind () == noware::var::type::nr
							)
								dest = get (thread_id, inst.oprnd [1] + inst.offset [1]);
							else
							{
								//src_offset = get (thread_id, inst.offset [0]);
								//src = get (thread_id, src_offset);
								dest = get (thread_id, inst.oprnd [1] + get (thread_id, inst.offset [1]));
							}
						else
							dest = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.oprnd [1]);
					}
					else
					{
						std::cout << "noware::mach::cpu::exe::instr.ref[dest]==false" << std::endl;
						
						dest = inst.oprnd [1];
					}
					
					std::cout << "noware::mach::cpu::exe::thread_id==[" << thread_id << "]" << std::endl;
					std::cout << "noware::mach::cpu::exe::instr.dest==[" << dest << "]" << std::endl;
					std::cout << "noware::mach::cpu::exe::instr.src==[" << src << "]" << std::endl;
					std::cout << "noware::mach::cpu::exe::ref[dest],ref[src]==[" << inst._ref [1] << "],[" << inst._ref [0] << "]" << std::endl;
					std::cout << "noware::mach::cpu::exe::offset[dest],offset[src]==[" << inst.offset [1] << "],[" << inst.offset [0] << "]" << std::endl;
					
					//assert (set (std::string ("thread ") + inst.thread_id/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/));
					assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, dest/* key*/, src/* value*/));
					//assert (set (/*std::string ("thread ") + inst.*/"A 1"/* group*/, dest/* key*/, src/* value*/));
					
					break;
				case cpu::opr::go:
					std::cout << "noware::mach::cpu::exe::instr.opr==go" << std::endl;
					break;
				case cpu::opr::none:
					std::cout << "noware::mach::cpu::exe::instr.opr==none" << std::endl;
					break;
				default:
					std::cout << "noware::mach::cpu::exe::instr.opr==default" << std::endl;
			}
			
			//assert (set (inst.thread_id/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/));
			
			// remove the instruction from the queue
			// it is now processed
			// it is no longer needed
			//dequeue ();
			
			//// synchronize with our cpu group
			//node.multicast (msg_cpu_serial, grp);
			
			//// synchronize all the members of the thread group
			// tell the caller that we have successfully executed the instruction
			//node.unicast (, inst.thread_id);
			//node.multicast (msg_thread_serial, inst.oprnd [2]);
		//	map_thread ["subject"] = "notification";
		//	map_thread ["success"] = "1";
			//map_thread ["instr.ndx"] = inst.ndx;
			
		//	noware::serialize <std::map <std::string, std::string>> (map_thread_serial, map_thread);
		
		//	std::cout << "noware::mach::cpu::node.multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
		//	std::cout << "noware::mach::cpu::node.unicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
			//std::cout << "noware::mach::cpu::multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
			
		//	msg = map_thread_serial;
		//	msg.prepend (zmq::msg::frame ("dummy_request_token"));
			//msg.prepend (zmq::msg::frame (noware::random::string (noware::mach::dev::token_size_dft)));
			
		//	node.multicast (msg, inst.thread_id);
			index_max = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index.max"/* key*/);
			index = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/);
			++index;
			std::cout << "noware::mach::cpu::exen()::index_max==[" << index_max << "]" << std::endl;
			std::cout << "noware::mach::cpu::exen()::index==[" << index << "]" << std::endl;
			if (index.operator const unsigned int () > index_max.operator const unsigned int ())
			{
				std::cout << "noware::mach::cpu::exen()::resetting index=1" << std::endl;
				assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
				index = 1;
			}
			assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/, index/* value*/));
			
			inst_next = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, std::string ("instr ") + index.operator const std::string ()/* key*/);
			
			if (get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/) == "1")
				assert (enqueue (inst_next));
			else
				assert (clear (/*std::string ("thread ") + inst.*/thread_id/* group*/));
			//node.unicast (msg, inst.thread_id);
			//multival (msg, inst.thread_id);
			//map_thread.clear ();
			
			
		}
		
		std::cout << "noware::mach::cpu::sleeping..." << std::endl;
		boost::this_thread::sleep_for (boost::chrono::seconds (3));
	}
}

// Store
const bool noware::mach::cpu::exist (const std::string & key) const
{
	return exist (std::string (""), key);
}

const bool noware::mach::cpu::exist (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft)) == "1";
}

const bool noware::mach::cpu::clear (void)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::cpu::clear (const std::string & group)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::cpu::remove (const std::string & group, const std::string & key)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "removal";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft)) == "1";
}

const bool noware::mach::cpu::remove (const std::string & key)
{
	return remove (std::string (""), key);
}

const std::string/* value*/ noware::mach::cpu::get (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const std::string/* value*/ noware::mach::cpu::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const bool/* success*/ noware::mach::cpu::set (const std::string & group, const std::string & key, const std::string & value)
{
	std::cout << "noware::mach::cpu::set()::in scope" << std::endl;
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cout << "noware::mach::cpu::set()::serialize()::false" << std::endl;
		
		return false;
	}
	
	std::cout << "noware::mach::cpu::set()::return" << std::endl;
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft)) == "1";
}

const bool/* success*/ noware::mach::cpu::set (const std::string & key, const std::string & value)
{
	return set (std::string (""), key);
}

// Queue
const noware::nr noware::mach::cpu::size (void) const
{
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "magnitude";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::queue::grp_dft));
}

const bool noware::mach::cpu::empty (void) const
{
	return size () <= 0;
}

const bool noware::mach::cpu::full (void) const
{
	return false;
}

const noware::mach::cpu::instr noware::mach::cpu::next_dequeue (void)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	instr inst;
	
	expression ["subject"] = "next_dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")));
}

const noware::mach::cpu::instr noware::mach::cpu::next (void) const
{
	instr inst;
	
	if (full ())
		return inst;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")));
}

const bool noware::mach::cpu::dequeue (void)
{
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")) == "1";
}

const bool noware::mach::cpu::enqueue (const instr & inst)
{
	//return false;
	
	if (full ())
		return false;
	
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = inst.serialize ();
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1";
}

const bool noware::mach::cpu::enqueue (const std::string & operand1, const opr & op, const std::string & operand2, const std::string & thread_id)
{
	instr inst;
	
	inst.oprn = op;
	inst.oprnd [0] = operand1;
	inst.oprnd [1] = operand2;
	//inst.oprnd [2] = operand3;
	inst.thread_id = thread_id;
	
	return enqueue (inst);
}

/*
const bool noware::mach::cpu::respond (const zyre_event_t * event, const std::string & event_type, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::cout << "noware::mach::cpu::respond()::called" << std::endl;
	
	//noware::tree <std::string, std::string> response;
	std::map <std::string, std::string> response;
	//noware::tree <std::string, std::string> message;
	std::map <std::string, std::string> message;
	noware::var result_tmp;
	bool result;
	
//	zframe_t * frm;
	//noware::nr ndx;
	
	//data.clear ();
	//frm = zmsg_first (msg_rx);
//	frm = zmsg_first (zmsg);
	//ndx = 1;
	//while (frm != nullptr)
	//{
		// This makes a copy of the frame.
		//data [ndx] = *frm;
		
		//zframe_destroy (&f);
		
	//	frm = zmsg_next (&other);
	//	++ndx;
	//}
	
	//return other;
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_request)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
		return false;
	
	result = false;
	
	std::cout << "noware::mach::cpu::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::mach::cpu::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cout << "noware::mach::cpu::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::mach::cpu::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg, "");
			std::cout << "noware::mach::cpu::respond()::unicast_local(message)==" << (result ? "success" : "failure") << std::endl;
		//}
	}
	
	return result;
}
*/

const bool noware::mach::cpu::load_file (const std::string & file_name)
{
	std::ifstream file;
	std::string dest, src;
	bool dest_is_ref, src_is_ref;
	bool dest_is_offset, src_is_offset;
	cpu::instr _instr;
	unsigned int _ndx;
	std::string operation;
	std::string dest_offset_location, src_offset_location;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	_ndx = 0;
	_instr.thread_id = noware::random::string (16);
	//_instr.thread_id = "1";
	//_instr.oprn = cpu::opr::set;
	while (file >> operation >> dest >> dest_ref >> dest_is_offset >> dest_offset_location >> src >> src_ref >> src_is_offset >> src_offset_location)
	{
		++_ndx;
		
		_instr.oprnd [0] = src;
		_instr.oprnd [1] = dest;
		//_instr.ndx = _ndx;
		
		std::cout << "noware::mach::cpu::load::ref[dest],ref[src]==[" << dest_ref << "],[" << src_ref << "]" << std::endl;
		
		_instr._ref [0] = src_is_ref;
		_instr._ref [1] = dest_is_ref;
		
		_instr._offset [0] = src_is_offset;
		_instr._offset [1] = dest_is_offset;
		
		_instr.offset [0] = src_offset_location;
		_instr.offset [1] = dest_offset_location;
		
		if (operation == "SET" || operation == "set" || operation == "MOVE" || operation == "move" || operation == "MOV" || operation == "mov")
			_instr.oprn = cpu::opr::set;
		else if (operation == "GO" || operation == "go" || operation == "JUMP" || operation == "jump" || operation == "JMP" || operation == "jmp")
			_instr.oprn = cpu::opr::go;
		else
			_instr.oprn = cpu::opr::none;
		
		//_instr.thread_id = std::string ("thread ") + grp;
		//_instr.thread_id = id ();
		
	//	instr [_ndx] = _instr;
		assert (set (std::string ("thread ") + _instr.thread_id, std::string ("instr ") + noware::nr (_ndx).operator const std::string (), _instr.serialize ()));
	}
	
	file.close ();
	
	//assert (set (std::string ("thread ") + _instr.thread_id, "running", "0"));
	assert (set (std::string ("thread ") + _instr.thread_id, "running", "1"));
	assert (set (std::string ("thread ") + _instr.thread_id, "index", "1"));
	//set (std::string ("thread ") + _instr.thread_id, "running", "0");
	assert (set (std::string ("thread ") + _instr.thread_id, "index.max", noware::nr (_ndx).operator const std::string ()));
	
	//_loaded = true;
	
	return true;
}

const bool/* success*/ noware::mach::cpu::search (zmq::msg & msg_result, const zmq::msg & msg_resp)
{
	std::cout << "noware::mach::cpu::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cout << "noware::mach::cpu::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cout << "noware::mach::cpu::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	// Store
	if (resp ["subject"] == "existence")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "obtainment")
	{
		if (resp ["value.exist"] == "0")
		{
			return false;
		}
		
		msg_result = resp ["value"];
		
		return true;
	}
	else if (resp ["subject"] == "assignment")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "removal")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	else if (resp ["subject"] == "clearance")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	// Queue
	else if (resp ["subject"] == "magnitude")
	{
		std::cout << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cout << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "next_dequeue")
	{
		std::cout << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cout << "noware::mach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cout << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cout << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cout << "noware::mach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "next")
	{
		std::cout << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cout << "noware::mach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cout << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cout << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cout << "noware::mach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cout << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("noware::mach::queue::nonempty"));
		}
		
		assert (node.join ("noware::mach::queue::nonfull"));
		
		
		msg_result = "1";
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "enqueue")
	{
		std::cout << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.push (resp ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("noware::mach::queue::nonfull"));
		}
		
		assert (node.join ("noware::mach::queue::nonempty"));
		
		
		msg_result = "1";
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	
	return false;
}
