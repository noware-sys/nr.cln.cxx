#pragma once

//#include "processor.hdr.cxx"

const std::string noware::mach::cpu::grp_dft = "cpu";

noware::mach::cpu::instr::instr (void)
{
	oprn = opr::none;
}

noware::mach::cpu::instr::instr (const std::string & other)
{
	//oprn = opr::none;
	deserialize (other);
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

const noware::var noware::mach::cpu::instr::val (void) const
{
	return oprnd [0];
}

noware::mach::cpu::cpu (void)
{
	//assert (node.join (grp_dft));
}

noware::mach::cpu::~cpu (void)
{
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
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
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
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "queue.nonempty")));
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
	
	return std::string (anyval (zmq::msg (expression_serial), "queue.nonempty")) == "1";
}

const bool noware::mach::cpu::enqueue (const instr & inst)
{
	//return false;
	
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = inst.serialize ();
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "queue.nonfull")) == "1";
}

const bool noware::mach::cpu::enqueue (const noware::var & operand1, const opr & op, const noware::var & operand2)
{
	instr inst;
	
	inst.oprn = op;
	inst.oprnd [0] = operand1;
	inst.oprnd [1] = operand2;
	
	return enqueue (inst);
}

const bool/* success*/ noware::mach::cpu::respond (const zyre_event_t * event)
{
	std::cout << "noware::mach::cpu::respond()::called" << std::endl;
	
	zmq::msg msg;
	zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	std::string event_type;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	event_type = zyre_event_type (event);
	if (event_type != "WHISPER" && event_type != "SHOUT")
	{
		std::cout << "noware::mach::cpu::respond()::event not of interest" << std::endl;
		
		return false;
	}
	std::cout << "noware::mach::cpu::respond()::event==" << event_type << std::endl;
	
	zmsg = zyre_event_msg (event);
	if (zmsg == nullptr)
	{
		std::cout << "noware::mach::cpu::respond()::event_msg==nullptr" << std::endl;
		
		return false;
	}
	
	std::cout << "noware::mach::cpu::respond()::event of interest" << std::endl;
	msg = zmsg;
	
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
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg)))
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
			assert (node.leave ("queue.nonempty"));
		}
		
		assert (node.join ("queue.nonfull"));
		
		
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
			assert (node.leave ("queue.nonfull"));
		}
		
		assert (node.join ("queue.nonempty"));
		
		
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
