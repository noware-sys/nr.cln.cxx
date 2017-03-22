/*
// Complement.
const noware::number noware::number::operator ~ (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::complement (content.number);
	else
		return *this;
}
*/
/*
// Modulus.
const noware::number noware::number::operator | (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::modulus (content.number);
	else
		return *this;
}
*/
/*
const bool noware::number::operator ! (void) const
{
	if (content.t == math::type::numeric)
		//return content.number == 0 ? true : false;
		return false;
	else
		return content.text.length () == 0;
}

const bool noware::number::operator && (const number & other) const
{
	return bool (*this) && bool (other);
}

const bool noware::number::operator && (const bool & other) const
{
	return bool (*this) && other;
}

const bool noware::number::operator || (const number & other) const
{
	return bool (*this) || bool (other);
}

const bool noware::number::operator || (const bool & other) const
{
	return bool (*this) || other;
}
*/
const noware::number & noware::number::operator ++ (void)
{
	++ content;
	
	return *this;
}

const noware::number & noware::number::operator -- (void)
{
	-- content;
	
	return *this;
}

const noware::number noware::number::operator ++ (const int other)
{
	number previous (*this);
	
	++ *this;
	
	return previous;
}

const noware::number noware::number::operator -- (const int other)
{
	number previous (*this);
	
	-- *this;
	
	return previous;
}

// Friends:
namespace noware
{
	//namespace math
	//{
		/*
		const bool operator && (const bool & other, const noware::number & self)
		{
			return other && bool (self);
		}
		
		const bool operator || (const bool & other, const noware::number & self)
		{
			return other || bool (self);
		}
		*/
		// operator <<
		std::ostream & operator << (std::ostream & stream, const number & self)
		{
			stream << self.content;
			
			return stream;
		}
		
		// operator >>
		std::istream & operator >> (std::istream & stream, number & self)
		{
			//std::string txt;
			
			//stream >> txt;
			//self = txt;
			try
			{
				stream >> self.content;
			}
			catch (...)
			{
			}
			
			return stream;
		}
	//}
}

