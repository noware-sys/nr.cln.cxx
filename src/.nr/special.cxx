bool const cln::nr::is (std::string const & str)
{
	//complex test;
	
	try
	{
		complex test;
		
		test = str.data ();
		
		return true;
	}
	catch (...)
	{
	}
	
	return false;
}

/*
const bool cln::nr::is (const type & t) const
{
	return true;
}

const bool cln::nr::is (const category & cat) const
{
	return false;
}
*/

/*
cln::nr::type const cln::nr::kind (void) const
{
	return type::complex;
}

cln::nr::category const cln::nr::cat (void) const
{
	return category::zero;
}
*/

/*
// Complement.
const cln::nr cln::nr::operator ~ (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::complement (content.number);
	else
		return *this;
}
*/
/*
// Modulus.
const cln::nr cln::nr::operator | (void) const
{
	if (content.t == math::type::numeric)
		return noware::tool::modulus (content.number);
	else
		return *this;
}
*/
/*
const bool cln::nr::operator ! (void) const
{
	if (content.t == math::type::numeric)
		//return content.number == 0 ? true : false;
		return false;
	else
		return content.text.length () == 0;
}

const bool cln::nr::operator && (const nr & other) const
{
	return bool (*this) && bool (other);
}

const bool cln::nr::operator && (const bool & other) const
{
	return bool (*this) && other;
}

const bool cln::nr::operator || (const nr & other) const
{
	return bool (*this) || bool (other);
}

const bool cln::nr::operator || (const bool & other) const
{
	return bool (*this) || other;
}
*/

std::string const cln::nr::format (void) const
{
	return operator std::string const ();
}

cln::nr const & cln::nr::operator ++ (void)
{
	++val;
	
	return *this;
}

cln::nr const & cln::nr::operator -- (void)
{
	--val;
	
	return *this;
}

/*
const cln::nr cln::nr::operator ++ (const int other)
{
	nr previous (*this);
	
	++ *this;
	
	return previous;
}

const cln::nr cln::nr::operator -- (const int other)
{
	nr previous (*this);
	
	-- *this;
	
	return previous;
}
*/

// Friends:
namespace cln
{
	//namespace math
	//{
		/*
		const bool operator && (const bool & other, const cln::nr & self)
		{
			return other && bool (self);
		}
		
		const bool operator || (const bool & other, const cln::nr & self)
		{
			return other || bool (self);
		}
		*/
		// operator <<
		std::ostream & operator << (std::ostream & stream, const nr & self)
		{
			stream << self.val;
			
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
				stream >> self.val;
			}
			catch (...)
			{
			}
			*/
			
			return stream;
		}
	//}
}
