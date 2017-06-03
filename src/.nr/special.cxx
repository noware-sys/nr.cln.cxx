const bool noware::nr::is (const std::string & str)
{
	complex test;
	
	try
	{
		test = str.c_str ();
		
		return true;
	}
	catch (...)
	{
		return false;
	}
}

/*
const bool noware::nr::is (const type & t) const
{
	return true;
}

const bool noware::nr::is (const category & cat) const
{
	return false;
}
*/

const noware::nr::type noware::nr::kind (void) const
{
	return type::complex;
}

const noware::nr::category noware::nr::cat (void) const
{
	return category::zero;
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

const noware::nr & noware::nr::operator ++ (void)
{
	++contnt;
	
	return *this;
}

const noware::nr & noware::nr::operator -- (void)
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
		std::ostream & operator << (std::ostream & stream, const nr & self)
		{
			stream << self.contnt;
			
			return stream;
		}
		
		// operator >>
		std::istream & operator >> (std::istream & stream, nr & self)
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
