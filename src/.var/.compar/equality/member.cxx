// operator ==

const bool noware::var::operator == (const var & other) const
{
	if (t != other.t)
		return false;
	
	if (t == type::nr)
		return nr == other.nr;
	
	return txt == other.txt;
}

const bool noware::var::operator == (const noware::nr & other) const
{
	if (t != type::nr)
		return false;
	
	return nr == other;
}
