#include "memory.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

// Memory: Iterator:

LIB::memory::iterator::iterator (void)
{
	set = false;
}

/*LIB::memory::iterator::iterator (const memory & other)
{
	operator = (other);
}

LIB::memory::iterator::~iterator (void)
{
}

const LIB::memory::iterator & LIB::memory::iterator::operator = (const iterator & other)
{
	return *this;
}*/

const bool LIB::memory::iterator::operator == (const iterator & other) const
{
	return iter == other.iter;
}

const bool LIB::memory::iterator::operator != (const iterator & other) const
{
	return !operator == (other);
}

const LIB::memory::iterator & LIB::memory::iterator::operator ++ (void)
{
	++ iter;
	
	return * this;
}

const LIB::memory::iterator & LIB::memory::iterator::operator -- (void)
{
	-- iter;
	
	return * this;
}

const LIB::memory LIB::memory::iterator::operator * (void)
{
	return * (iter -> v);
}

// Memory:

const static std::string LIB::memory::default_group;
const static std::string LIB::memory::default_name;
const static std::string LIB::memory::default_value;

LIB::memory::memory (const LIB::database::sqlite *& _db, const LIB::memory::key & grp, const LIB::memory::key & previous_grp, const LIB::memory::key & nm)
{
	if (_db == NULL)
	{
		db = new LIB::database::sqlite ();
		
		// Prepare the environment:
		db -> query (NULL, "PRAGMA foreign_keys true;");
		// Create the table:
		db -> query (NULL, "\
			\n\
			CREATE TABLE IF NOT EXISTS \"Entities\"\n\
			(\n\
				\"Group\" none NOT NULL DEFAULT '',\n\
				\"Name\" none NOT NULL,\n\
				\"Reference\" none NULL DEFAULT NULL,\n\
				\"Content\" none NULL DEFAULT NULL\n\
			);\n\
			\n\
			CREATE UNIQUE INDEX \"Uniqueness\" ON \"Entities\" (\"Group\", \"Name\");\n\
			");
	}
	else
	{
		db = _db;
	}
	
	group = grp;
	previous_group = previous_grp;
	previous_name = nm;
}

LIB::memory::memory (const memory & other)
{
//	db = other.db;
//	group = other.group;
//	previous_group = other.previous_group;
//	previous_name = other.previous_name;
	
	operator = (other);
}

LIB::memory::~memory (void)
{
	if (db != NULL && group == default_group)
	{
		delete db;
		db = NULL;
	}
}

template <typename archive>
void LIB::memory::save (archive & arch, const unsigned int & version) const
{}

template <typename archive>
void LIB::memory::load (archive & arch, const unsigned int & version)
{}

/*const bool LIB::memory::query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> & result, const std::string & qry, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> & arguments)
{
	return db -> query (result, qry, arguments);
}*/

LIB::database::sqlite & LIB::memory::database (void)
{
	// It should always be safe to dereference,
	// because the constructors ensure that an object is present.
	return * db;
}

const bool LIB::memory::operator == (const LIB::memory & other) const
{
	//typeid ();
}

const bool LIB::memory::operator != (const LIB::memory & other) const
{
	return ! operator == (other);
}

const bool LIB::memory::operator == (const LIB::memory::value & other) const
{}

const bool LIB::memory::operator != (const LIB::memory::value & other) const
{
	return ! operator == (other);
}

const LIB::memory & LIB::memory::operator = (const LIB::memory::memory & other)
{
	if (clear ())
	{
		
	}
	
	return * this;
}

const LIB::memory & LIB::memory::operator = (const LIB::memory::value & val)
{
}

const LIB::mathematics::numbers::natural LIB::memory::size (const bool & recursive, const bool & inclusive) const
{
	if (is_literal ())
	{
		return 1;
	}
	else
	{
		LIB::mathematics::numbers::natural total = inclusive ? 1 : 0;
		//LIB::mathematics::numbers::natural _inclusive = inclusive ? 1 : 0;
		
		for (auto & element : *this)
		{
			{
				memory mem (db, element.v, group, element.k);
				
				total += mem.size (recursive, inclusive);
			}
		}
		
		return total;
	}
}

const bool LIB::memory::clear (void) const
{
	if (is_literal ())
	{
		return true;
	}
	else
	{
		//LIB::mathematics::numbers::natural total = inclusive ? 1 : 0;
		//LIB::mathematics::numbers::natural _inclusive = inclusive ? 1 : 0;
		
		for (auto & element : *this)
		{
			{
				//db -> query (NULL, "SELECT \"*\" FROM \"Entities\" WHERE \"Group\" = ?", arguments);
				memory mem (db, element.v, group, element.k);
				
				if (! mem.clear ())
				{
					return false;
				}
			}
		}
		
		if (db -> query (NULL, "BEGIN", NULL))
		{
			db -> query (NULL, "ROLLBACK", NULL);
			return false;
		}
		
		LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
		
		arguments [1] = 0;
		arguments [2] = default_value;
		arguments [3] = previous_group;
		arguments [4] = previous_name;
		
		if (db -> query (NULL, "UPDATE \"Entities\" SET \"Reference\" = ?, \"Content\" = ? WHERE \"Group\" = ? AND \"Name\" = ?", arguments))
		{
			db -> query (NULL, "ROLLBACK", NULL);
			return false;
		}
		
		arguments.clear ();
		arguments [1] = group;
		
		if (db -> query (NULL, "DELETE FROM \"Entities\" WHERE \"Group\" = ?", arguments))
		{
			db -> query (NULL, "ROLLBACK", NULL);
			return false;
		}
		
		if (db -> query (NULL, "COMMIT", arguments))
		{
			db -> query (NULL, "ROLLBACK", NULL);
			return false;
		}
		
		return true;
	}
}

const bool LIB::memory::empty (void) const
{
	return size () <= 0;
}

const bool LIB::memory::full (void) const
{
	return false;
}

const bool LIB::memory::exist (const LIB::memory::key & name) const
{
	//key grp;
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	/*
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "SELECT \"Name\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?);", arguments))
	{
		if (result.empty ())
		{
			return "";
		}
		else
		{
			return result [1] [1];
		}
	}
	else
	{
		return "";
	}
	*/
	
	//grp = sequence_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "\
			SELECT COUNT(*)\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\
			", arguments));
	
	return result [1] [1] > 0;
}

const bool LIB::memory::exists (const LIB::memory::key & name) const
{
	return exist (name);
}

const LIB::memory LIB::memory::operator + (const LIB::memory::value & val) const
{}

const LIB::memory LIB::memory::operator + (const LIB::memory & other) const
{}

const LIB::memory & LIB::memory::operator += (const LIB::memory::value & val)
{}

const LIB::memory & LIB::memory::operator += (const LIB::memory & other)
{}

const bool LIB::memory::add (const LIB::memory::value & val)
{}

const bool LIB::memory::add (const LIB::memory::value & val, LIB::memory::key & used_key)
{}

const bool LIB::memory::add (const LIB::memory & other)
{}

const bool LIB::memory::append (const LIB::memory::value & val)
{}

const bool LIB::memory::append (const LIB::memory::value & val, LIB::memory::key & key_used)
{}

const bool LIB::memory::append (const LIB::memory & other)
{}

const LIB::memory::key LIB::memory::least_numeric_key (void) const
{
	key i = greatest_numeric_key ();
	
	for (auto & element: *this)
	{
		if (element.k < i)
		{
			i = element.k;
		}
	}
	
	return i;
}

const LIB::memory::key LIB::memory::greatest_numeric_key (void) const
{
	key i = 1;
	
	for (auto & element : *this)
	{
		if (element.k > i)
		{
			i = element.k;
		}
	}
	
	return i;
}

const bool LIB::memory::enqueue (const LIB::memory::value & val)
{
	key used_group;
	
	return enqueue (val, used_group);
}

const bool LIB::memory::enqueue (const LIB::memory::value & val, LIB::memory::key & used_group)
{
	// To be completed.
	/*
	used_group = sequence_next ();
	
	if (! set_group (used_group, val))
		return false;
	
	memory mem ();
	
	if (! mem.set (val))
		return false;
	
	return true;
	*/
}

const bool LIB::memory::dequeue (void)
{}

const LIB::memory LIB::memory::beginning (void) const
{
	return operator [] (least_numeric_key ());
}

const LIB::memory LIB::memory::ending (void) const
{
	return operator [] (greatest_numeric_key ());
}

const bool LIB::memory::push (const LIB::memory::value & val)
{}

const bool LIB::memory::push (const LIB::memory::value & val, LIB::memory::key & used_key)
{}

const bool LIB::memory::pop (void)
{}

//const bool LIB::memory::numeric_key (void) const
//{}

const LIB::memory::key LIB::memory::sequence_next_available (void) const
{
	for (key i = 1; i <= size (); ++ i)
	{
		if (! exist (i))
		{
			return i;
		}
	}
}

const LIB::memory::key LIB::memory::sequence_next (void) const
{
	return greatest_numeric_key () + 1;
}

const LIB::NAME_A <LIB::memory, LIB::memory::key> LIB::memory::list (void) const
{
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	LIB::NAME_A <LIB::memory, LIB::memory::key> entities;
	
	arguments [1] = group;
	db -> query (result, "SELECT \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arguments);
	
	for (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V>::container & row : result)
	{
		//for (LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>::container & column : row.v)
		//{
		//	// This loop should last for only one (1) iteration.
		//}
		{
			LIB::memory mem (db, row.v [2], group, row.v [1]);
			
			entities [row.v [1]] = mem;
		}
	}
	
	return entities;
}

const LIB::memory::iterator LIB::memory::begin (void) const
{
	LIB::memory::iterator iter;
	
	if (!iter.set)
		iter.list = list ();
	
	iter.iter = iter.list.begin ();
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}

const LIB::memory::iterator LIB::memory::end (void) const
{
	LIB::memory::iterator iter;
	
	if (!iter.set)
		iter.list = list ();
	
	iter.iter = iter.list.end ();
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}

const std::string LIB::memory::serialize (void) const
{
	return LIB::serialize <LIB::memory> (* this);
}

const bool LIB::memory::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::memory> (serial, * this);
}

/*operator const std::string (void) const
{
	return serialize ();
}

const LIB::memory & operator = (const std::string & serial)
{
	deserialize (serial);
	return *this;
}*/

LIB::memory::operator const value (void) const
{
	return get ();
}

LIB::memory LIB::memory::operator [] (const key & name)
{
	if (! exists (name))
	{
		set_group (name);
	}
	
	return get (name);
}

/*const LIB::memory & LIB::memory::operator [] (const key & name) const
{
	return *this;
}*/

const LIB::memory::value LIB::memory::get (void) const
{
	// Set "Reference" to "false" and "Content/Value" to ""
	// if the name which is being
	
	//content_clear_group ();
	
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	
	arguments [1] = previous_group;
	arguments [2] = previous_name;
	
	if (db -> query (result, "\
			SELECT \"Content\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\
			", arguments))
	{
		if (! result.empty ())
		{
			return result [1] [1];
		}
		//if (result.empty ())
		//{
		//	return "";
		//}
		//else
		//{
		//	return result [1] [1];
		//}
	}
	//else
	//{
	//	return "";
	//}
	
	return "";
	
	//return mem;
}

const LIB::memory LIB::memory::get (const LIB::memory::key & nm) const
{
	//content_clear_literal (nm/* the new, inexistent, (sub-)name*/);
	
	key grp;
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	/*
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "SELECT \"Name\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?);", arguments))
	{
		if (result.empty ())
		{
			return "";
		}
		else
		{
			return result [1] [1];
		}
	}
	else
	{
		return "";
	}
	*/
	
	//grp = sequence_next_available ();
	
	//if (grp <= 0)
	//	return *this;
	
	arguments [1] = group;
	arguments [2] = nm;
	//arguments [3] = nm;
	
	//db -> query (NULL, "BEGIN;\n\
			--DELETE FROM \"Entities\"\n\
			--WHERE \"Group\" = ? AND \"Name\" = ?;\n\
			INSERT OR REPLACE INTO \"Entities\"\n\
			(\"Group\", \"Name\", \"Reference\", \"Content\")\n\
			VALUES (?, ?, ?, ?), (?, ?, ?, ?);\n\
			COMMIT;", arguments);
	//db -> query (NULL, "BEGIN;\n\
			UPDATE \"Entities\"\n\
			SET \"Reference\" = ?, \"Content\" = NULL\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
			COMMIT;", arguments);
	
	grp = "";
	
	if (db -> query (result, "\
			SELECT \"Content\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ? AND \"Reference\" != 0;\
			", arguments))
	{
		if (! result.empty ())
		{
			grp = result [1] [1];
		}
		//else
		//{
		//	grp = result [1] [1];
		//}
	}
	//else
	//{
	//	grp = "";
	//}
	
	memory mem (db, grp, group, nm);
	//return memory (db, group, name);
	return mem;
	//return result;
}

const bool LIB::memory::set/*_literal*/ (const LIB::memory::value & val)
{
	if (! clear ())
	{
		return false;
	}
	
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	
	//arguments [1] = 0;
	arguments [1] = val;
	arguments [2] = previous_group;
	arguments [3] = previous_name;
	
	return db -> query (NULL, "\
			BEGIN;\n\
			UPDATE \"Entities\"\n\
			SET \"Reference\" = 0, \"Content\" = ?\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
			COMMIT;\
			", arguments);
}

const bool LIB::memory::set_group (const LIB::memory::key & name)
{
	key used_group;
	return set_group (name, used_group);
}

const bool LIB::memory::set_group (const LIB::memory::key & name, const LIB::memory::key & used_group)
{
	if (! clear ())
	{
		return false;
	}
	
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	
	//key grp = sequence_next_available ();
	used_group =  sequence_next_available ();
	
	arguments [1] = used_group;
	arguments [2] = name;
	arguments [3] = 1;
	//arguments [3] = previous_group;
	
	if (! db -> query (NULL, "BEGIN", NULL))
	{
		db -> query (NULL, "ROLLBACK", NULL);
		return false;
	}
	
	if (!
		db -> query (NULL, "\
			INSERT OR IGNORE INTO \"Entities\"\n\
			(\"Group\", \"Name\", \"Reference\", \"Content\")\n\
			VALUES (?, ?, ?, NULL)\
			", arguments)
	)
	{
		db -> query (NULL, "ROLLBACK", NULL);
		return false;
	}
	
	arguments [1] = 1;
	arguments [2] = used_group;
	arguments [3] = previous_group;
	arguments [4] = previous_name;
	
	if (!
		db -> query (NULL, "\
			UPDATE \"Entities\"\n\
			SET \"Reference\" = ?, \"Content\" = ?\n\
			WHERE \"Group\" = ? AND \"Name\" = ?\
			", arguments)
	)
	{
		db -> query (NULL, "ROLLBACK", NULL);
		return false;
	}
	
	return db -> query (NULL, "COMMIT", NULL);
}

const bool LIB::memory::set_group (void)
{
	if (! clear ())
	{
		return false;
	}
	
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	
	arguments [1] = 1;
	arguments [2] = previous_group;
	arguments [3] = previous_name;
	
	return db -> query (NULL, "\
			BEGIN;\n\
			UPDATE \"Entities\"\n\
			SET \"Reference\" = ?, \"Content\" = NULL\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
			COMMIT;\
			", arguments);
}

const bool LIB::memory::is_literal (void) const
{
	//key grp;
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arguments;
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	/*
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "SELECT \"Name\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?);", arguments))
	{
		if (result.empty ())
		{
			return "";
		}
		else
		{
			return result [1] [1];
		}
	}
	else
	{
		return "";
	}
	*/
	
	//grp = sequence_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = previous_group;
	arguments [2] = previous_name;
	
	if (db -> query (result, "\
			SELECT \"Reference\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?;\
			", arguments));
	
	return result [1] [1] == 0;
}

const bool LIB::memory::is_group (void) const
{
	return ! is_literal ();
}
/*
const bool content_clear_literal (const key & name)
{
	return false;
}

const bool content_clear_group (const key & name)
{
	return false;
}
*/
