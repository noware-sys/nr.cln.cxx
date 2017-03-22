#pragma once

#include "tool/nr.cxx"
#include "tool/string.cxx"

#include "nr.hxx"

/*
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
*/
#include ".nr/.cxx"

template <typename archive> 
void noware::nr::serialize (archive & arch, const unsigned int & version)
{
	arch & content;
}

/*
const bool noware::nr::limited (void) const
{
	return !rules.empty ();
}

const noware::container::array <rule> & noware::nr::limits (void) const
{
	return rules;
}

const bool noware::nr::limit (const rule & r)
{
	return false;
}
*/
const std::string noware::nr::string (void) const
{
	return std::string (*this);
}

const noware::nr::type noware::nr::category (void) const
{
	return type::complex;
}
/*
const bool noware::nr::exact (void) const
{
	return true;	// true _exact
}
*/
/*
const bool noware::nr::categorized (const type & t) const
{
	return true;
}
*/
