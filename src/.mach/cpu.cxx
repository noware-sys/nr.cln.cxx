//#pragma once

//#include "processor.hdr.cxx"

noware::machine::processor::instruction::instruction (void)
{
	operation = operation::none;
}

noware::machine::processor::instruction::~instruction (void)
{
}

noware::machine::processor::instruction::evaluate (void)
{
	return "";
}

noware::machine::processor::processor (void)
{
}

noware::machine::processor::~processor (void)
{
}

const instruction noware::machine::processor::next (void) const
{
	instruction inst;
	
	return inst;
}

const bool noware::machine::processor::dequeue (void)
{
	return false;
}

const bool noware::machine::processor::enqueue (const instruction & inst)
{
	return false;
}

const bool noware::machine::processor::enqueue (const noware::var & operand1, const operation & op, const noware::var & operand2)
{
	instruction inst;
	
	inst.operand1 = operand1;
	inst.operation = op;
	inst.operand1 = operand2;
	
	return enqueue (inst);
}
