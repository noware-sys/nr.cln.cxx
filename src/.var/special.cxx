// Complement.
const noware::any noware::any::operator ~ (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.nr);
		return *this;
	else
		return *this;
}

/*
// Modulus.
const noware::any noware::any::operator | (void) const
{
	if (content.t == container::type::numeric)
		return noware::tool::modulus (content.nr);
	else
		return *this;
}
*/

const bool noware::any::operator ! (void) const
{
	if (content.t == container::type::numeric)
		//return content.nr == 0 ? true : false;
		return false;
	else
		return content.text.length () == 0;
}

const bool noware::any::operator && (const any & other) const
{
	return bool (*this) && bool (other);
}

const bool noware::any::operator && (const bool & other) const
{
	return bool (*this) && other;
}

const bool noware::any::operator || (const any & other) const
{
	return bool (*this) || bool (other);
}

const bool noware::any::operator || (const bool & other) const
{
	return bool (*this) || other;
}

const noware::any & noware::any::operator ++ (void)
{
	if (content.t == container::type::numeric)
		++content.number;
	
	return *this;
}

const noware::any & noware::any::operator -- (void)
{
	if (content.t == container::type::numeric)
		--content.number;
	
	return *this;
}

const noware::any noware::any::operator ++ (signed int other)
{
	any previous (*this);
	
	++*this;
	
	return previous;
}

const noware::any noware::any::operator -- (signed int other)
{
	any previous (*this);
	
	--*this;
	
	return previous;
}

// Friends:
namespace noware
{
	//namespace container
	//{
		const bool operator && (const bool & other, const noware::any & self)
		{
			return other && bool (self);
		}
		
		const bool operator || (const bool & other, const noware::any & self)
		{
			return other || bool (self);
		}
		
		// operator <<
		std::ostream & operator << (std::ostream & stream, const noware::any & self)
		{
			switch (self.content.t)
			{
				case noware::any::container::type::numeric:
					stream << self.content.number;
					break;
				case noware::any::container::type::generic:
				default:
					stream << self.content.text;
			}
			
			return stream;
		}
		
		// operator >>
		std::istream & operator >> (std::istream & stream, noware::any & self)
		{
			//text txt;
			std::string txt;
			
			stream >> txt;
			self = txt;
			
			return stream;
		}
	//}
}

