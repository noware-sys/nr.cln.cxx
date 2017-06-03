#pragma once

//#include ".array/.cxx"
//#include <type_traits>

#include "../serial.cxx"
#include "../nr.cxx"
#include "../var.cxx"

// #include <typeinfo>
//#include <iostream>
// Array.CPP:
// Standard library:
//#include <utility>	// For "std::swap ()".

/*
// Static constants.
template <typename value_t, typename key_t>
value noware::array <value_t, key_t>::value;

template <typename value_t, typename key_t>
key noware::array <value_t, key_t>::key;
*/

//
// For array functionality
//
/*
template <typename value_t, typename key_t>
template <typename archive>
void noware::contnr::array <value_t, key_t>::serialize (archive &, const unsigned int & version)
{
}
*/

//const std::string noware::array::group_default = "array";
/*
template <typename value_t, typename key_t>
noware::array <value_t, key_t>::array (void)
{
}

template <typename value_t, typename key_t>
noware::array <value_t, key_t>::~array (void)
{
}
*/
template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::set (const key_t &/* key*/, const value_t &/* value*/)
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::get (const key_t &/* key*/, value_t &/* value*/) const
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::clear (void)
{
	return false;
}

template <typename value_t, typename key_t>
const noware::nr noware::contnr::array <value_t, key_t>::size (void) const
{
	return 0;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::exist (const key_t & key) const
{
	value_t value;
	return get (key, value);
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::remove (const key_t &/* key*/)
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::rename (const key_t &/* old_k*/, const key_t &/* new_k*/)
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::is_full (void) const
{
	return false;
}

template <typename value_t, typename key_t>
const bool noware::contnr::array <value_t, key_t>::is_empty (void) const
{
	return size () <= 0;
}

template <typename value_t, typename key_t>
value_t & noware::contnr::array <value_t, key_t>::operator [] (const std::nullptr_t &/* null*/)
{
	value_t value;
	//set (value);
	return value;
}

template <typename value_t, typename key_t>
value_t & noware::contnr::array <value_t, key_t>::operator [] (const key_t & key)
{
	value_t value;
	get (key, value);
	return value;
}
