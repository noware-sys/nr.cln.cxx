#pragma once

#include "tool/number.cxx"
#include "tool/string.cxx"

#include "number.hxx"

#include ".number/rule.cxx"

#include ".number/constructor.cxx"
#include ".number/destructor.cxx"

#include ".number/set.cxx"
#include ".number/conversion.cxx"

#include ".number/comparison.cxx"

#include ".number/addition.cxx"
#include ".number/substraction.cxx"

#include ".number/multiplication.cxx"
#include ".number/division.cxx"

#include ".number/exponentiation.cxx"
#include ".number/modulo.cxx"

#include ".number/special.cxx"

template <typename archive> 
void noware::number::serialize (archive & arch, const unsigned int & version)
{
	arch & content;
}

/*
const bool noware::number::limited (void) const
{
	return !rules.empty ();
}

const noware::container::array <rule> & noware::number::limits (void) const
{
	return rules;
}

const bool noware::number::limit (const rule & r)
{
	return false;
}
*/
const std::string noware::number::string (void) const
{
	return std::string (*this);
}

const noware::number::type noware::number::category (void) const
{
	return type::complex;
}
/*
const bool noware::number::exact (void) const
{
	return true;	// true _exact
}
*/
const bool noware::number::categorized (const type & t) const
{
	return true;
}

