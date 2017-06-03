#pragma once

template <typename value>
const iterator <value> noware::misc::iterator <value>::begin (void) const
{
	return *this;
}

template <typename value>
const iterator <value> noware::misc::iterator <value>::end (void) const
{
	return *this;
}

template <typename value>
const value noware::misc::iterator <value>::operator * (void) const
{
	value temp;
	return temp;
}

template <typename value>
const bool noware::misc::iterator <value>::operator != (const iterator <value> & other) const
{
	return !((*this) == other);
}

template <typename value>
const iterator <value> noware::misc::iterator <value>::operator ++ (void)
{
	return *this;
}

template <typename value>
const bool noware::misc::iterator <value>::operator == (const iterator <value> & other) const
{
	return false;
}

template <typename value>
const iterator <value> noware::misc::iterator <value>::operator -- (void)
{
	return *this;
}
