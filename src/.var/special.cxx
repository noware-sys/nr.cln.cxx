/*
const bool noware::var::is (const type & t) const
{
	return this -> t == t;
}
*/

const noware::var::type noware::var::kind (void) const
{
	return t;
}

/*
// Complement.
const noware::nr noware::nr::operator ~ (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::complement (content.number);
	else
		return *this;
}
*/
/*
// Modulus.
const noware::nr noware::nr::operator | (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::modulus (content.number);
	else
		return *this;
}
*/
/*
const bool noware::nr::operator ! (void) const
{
	if (content.t == math::type::numeric)
		//return content.number == 0 ? true : false;
		return false;
	else
		return content.text.length () == 0;
}

const bool noware::nr::operator && (const nr & other) const
{
	return bool (*this) && bool (other);
}

const bool noware::nr::operator && (const bool & other) const
{
	return bool (*this) && other;
}

const bool noware::nr::operator || (const nr & other) const
{
	return bool (*this) || bool (other);
}

const bool noware::nr::operator || (const bool & other) const
{
	return bool (*this) || other;
}
*/

const noware::var & noware::var::operator ++ (void)
{
	++contnt;
	
	return *this;
}

const noware::var & noware::var::operator -- (void)
{
	--contnt;
	
	return *this;
}

/*
const noware::nr noware::nr::operator ++ (const int other)
{
	nr previous (*this);
	
	++ *this;
	
	return previous;
}

const noware::nr noware::nr::operator -- (const int other)
{
	nr previous (*this);
	
	-- *this;
	
	return previous;
}
*/

// Friends:
namespace noware
{
	//namespace math
	//{
		/*
		const bool operator && (const bool & other, const noware::nr & self)
		{
			return other && bool (self);
		}
		
		const bool operator || (const bool & other, const noware::nr & self)
		{
			return other || bool (self);
		}
		*/
		// operator <<
		std::ostream & operator << (std::ostream & stream, const var & self)
		{
			if (self.t == var::type::nr)
				stream << self.nr;
			else
				stream << self.txt;
			
			return stream;
		}
		
		// operator >>
		std::istream & operator >> (std::istream & stream, var & self)
		{
			std::string str;
			
			stream >> str;
			self = str;
			/*
			try
			{
				stream >> self.contnt;
			}
			catch (...)
			{
			}
			*/
			
			return stream;
		}
	//}
}
