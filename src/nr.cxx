#pragma once

//#include "tool/nr.cxx"
#include <noware/tool/string.cxx>
#include <noware/misc/serial.cxx>
//#include <noware/serial.cxx>

#include "nr.hxx"

//#include <sstream>

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
#include ".nr/.incl.cxx"
#include ".nr/.cxx"
/*
bool noware::nr::operator == (const nr & other)
{
	return contnt == other.contnt;
}

noware::nr noware::nr::operator += (const nr & other)
{
	return contnt += other.contnt;
}

noware::nr noware::nr::operator -= (const nr & other)
{
	return contnt -= other.contnt;
}

noware::nr noware::nr::operator *= (const nr & other)
{
	return contnt *= other.contnt;
}

noware::nr noware::nr::operator /= (const nr & other)
{
	return contnt /= other.contnt;
}

noware::nr noware::nr::operator %= (const nr & other)
{
	return contnt %= other.contnt;
}

noware::nr noware::nr::operator ^= (const nr & other)
{
	return contnt ^= other.contnt;
}
*/
template <typename arch>
void cln::nr::serialize (arch & a, unsigned int const &/* version*/)
{
	a & val;
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
/*
noware::nr::operator const std::string (void) const
{
	std::stringstream ss;
	ss << contnt;
	return ss.str ();
	//return std::string (*this);
}
*/
/*
const noware::nr::type noware::nr::kind (void) const
{
	return type::complex;
}

const noware::nr::category noware::nr::cat (void) const
{
	return category::odd;
}
*/

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

std::istream & getline (std::istream & stream, cln::nr & value, char const delimiter)
{
	std::string temp;
	std::getline (stream, temp, delimiter);
	value /*+*/= temp;
	return stream;
}
