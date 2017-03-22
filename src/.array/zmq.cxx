#pragma once

#include "zmq.hxx"
#include ".zmq/.cxx"

//#include "var.cxx"
//#include "nr.hxx"
//#include "../../db/sqlite.hxx"
#include "../../net/node.cxx"

/*
// Default static constants:
template <typename __value, typename __key>
value noware::array <__value, __key>::zmq <value, key>::_value;

template <typename value, typename key>
key noware::array <__value, __key>::zmq <value, key>::_key;
*/
//template <typename value, typename key>
//const std::string noware::array <__value, __key>::zmq <value, key>::group_default = "";

template <typename _value, typename _key>
template <typename value, typename key>
noware::array <_value, _key>::zmq <value, key>::zmq (void)
{
	initialize ();
}

template <typename _value, typename _key>
template <typename value, typename key>
noware::array <_value, _key>::zmq <value, key>::~zmq (void)
{
	finalize ();
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::finalize (void)
{
	return true;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::initialized (void) const
{
	return true;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::initialize (void)
{
	return true;
}

template <typename _value, typename _key>
template <typename value, typename key>
const noware::nr noware::array <_value, _key>::zmq <value, key>::size (void) const
{
	return 0;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::exist (const noware::var & group, const key & k) const
{
	return false;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::exist (const key & k) const
{
	return exist (noware::array <_value, _key>::sqlite::group_default, k);
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::full (void) const
{
	return false;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::empty (void) const
{
	return size () <= 0;
}

template <typename _value, typename _key>
template <typename value, typename key>
const value & noware::array <_value, _key>::zmq <value, key>::get (const noware::var & group, const key & k)
{
	value tmp;
	return tmp;
}

template <typename _value, typename _key>
template <typename value, typename key>
const value & noware::array <_value, _key>::zmq <value, key>::get (const key & k)
{
	return get (noware::array <_value, _key>::sqlite::group_default, k);
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::set (const noware::var & group, const key & k, const value & val)
{
	std::string _owner;
	
	if (exist (group, k, _owner))
	{
		noware::tree <> message;
		
		message ["subject"] = "settlement";
		message ["group"] = group;
		message ["key"] = k;
		message ["value"] = val;
		
		return node.unicast (message, _owner);
	}
	else
	{
		return add (group, k, val);
	}
	
	//return false;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::set (const key & k, const value & val)
{
	return noware::array <_value, _key>::zmq <value, key>::set (noware::array <_value, _key>::sqlite::group_default, k, val);
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::clear (void)
{
	return false;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::remove (const noware::var & group, const key & k)
{
	return false;
}

template <typename _value, typename _key>
template <typename value, typename key>
const bool noware::array <_value, _key>::zmq <value, key>::remove (const key & k)
{
	return remove (noware::array <_value, _key>::sqlite::group_default, k);
}
