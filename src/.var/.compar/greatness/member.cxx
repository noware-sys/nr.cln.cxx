// operator >
/*
const bool noware::nr::operator > (const nr & other) const
{
	return false;
}
*/
/*
const bool noware::nr::operator > (const text & other) const
{
	return *this > nr (other);
}
*/

const bool noware::var::operator > (const var & other) const
{
	//return *this > var (other);
	//return *(const_cast <const nr *> (this)) > *(const_cast <const nr *> (&(nr (other))));
	return false;
}

const bool noware::var::operator > (const noware::nr & other) const
{
	return operator > (var (other));
	//return *(const_cast <const nr *> (this)) > *(const_cast <const nr *> (&(nr (other))));
}
