#pragma once

noware::mach::screen::bitmap::coord::coord (void)
{
	horizontal = 0;
	vertical = 0;
}

noware::mach::screen::bitmap::coord::coord (const coord & other)
{
	horizontal = other.horizontal;
	vertical = other.vertical;
}

noware::mach::screen::bitmap::coord::coord (const noware::nr & h, const noware::nr & v)
{
	horizontal = h;
	vertical = v;
}

const coord & noware::mach::screen::bitmap::coord::operator = (const coord & other)
{
	horizontal = other.horizontal;
	vertical = other.vertical;
	
	return *this;
}

const bool noware::mach::screen::bitmap::coord::operator == (const coord & other) const
{
	return horizontal == other.horizontal && vertical == other.vertical;
}
