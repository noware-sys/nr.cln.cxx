// operator -=

const noware::var noware::var::operator -= (const var & other)
{
	nr -= other.nr;
	return nr;
}

const noware::var noware::var::operator -= (const noware::nr & other)
{
	nr -= other;
	return nr;
}
