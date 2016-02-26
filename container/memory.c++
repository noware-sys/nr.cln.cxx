//#include <iostream>
#include "memory.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

const std::string LIB::container::memory::default_database_name = ":memory:";
const LIB::container::memory::key LIB::container::memory::default_group = 0;
//const LIB::container::memory::value LIB::container::memory::default_name;
const LIB::container::memory::value LIB::container::memory::default_value = "";

// Memory: Iterator:

LIB::container::memory::iterator::iterator (void)
{
	//set = false;
}

LIB::container::memory::iterator::iterator (const LIB::container::memory::iterator & other)
{
	operator = (other);
}
/*
LIB::container::memory::iterator::~iterator (void)
{
}
*/
const LIB::container::memory::iterator & LIB::container::memory::iterator::operator = (const LIB::container::memory::iterator & other)
{
	iter = other.iter;
	
	return *this;
}

const bool LIB::container::memory::iterator::operator == (const iterator & other) const
{
	return iter == other.iter;
	//return false;
}

const bool LIB::container::memory::iterator::operator != (const iterator & other) const
{
	return ! (operator == (other));
}

const LIB::container::memory::iterator & LIB::container::memory::iterator::operator ++ (void)
{
	++ iter;
	
	return * this;
}

const LIB::container::memory::iterator & LIB::container::memory::iterator::operator -- (void)
{
	-- iter;
	
	return * this;
}

const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::container & LIB::container::memory::iterator::operator * (void) const
{
	//return * (iter -> v);
	//return iter -> v;
	return *iter;
}

// Memory:

//static const std::string LIB::container::memory::default_database_name;
//static const std::string LIB::container::memory::default_group;
////static const std::string LIB::container::memory::default_name;
//static const std::string LIB::container::memory::default_value;
//
//const bool LIB::container::memory::initialize (const LIB::database::sqlite *& _db, const LIB::container::memory::key & grp, const LIB::container::memory::key & previous_grp, const LIB::container::memory::key & nm, const std::string & __database_name)
//{
//}

const bool LIB::container::memory::initialize (const std::string & __database_name)
{
	//std::cout << std::endl << default_database_name << std::endl;
	_database_name = __database_name;
	
	db = new LIB::container::database::sql::sqlite (_database_name);
	
	if (! db -> query ("BEGIN"))
		return false;
	
	// Prepare the environment:
	if (! db -> query ("PRAGMA foreign_keys = true"))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}

	// Create the table:
	if (! db -> query ("\
		CREATE TABLE IF NOT EXISTS \"Entities\"\n\
		(\n\
		\t	\"Group\" none NOT NULL DEFAULT '',\n\
		\t	\"Name: Type\" none NULL DEFAULT NULL,\n\
		\t	\"Name\" none NOT NULL,\n\
		\t	\"Content: Type\" none NULL DEFAULT NULL,\n\
		\t	\"Content\" none NULL DEFAULT NULL\n\
		\n\
		--, PRIMARY KEY (\"Group\", \"Name\")\n\
		)\
		"))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}
	
	if (! db -> query ("\
		CREATE UNIQUE INDEX IF NOT EXISTS \"Entities: Entry: Unique\" ON \"Entities\" (\"Group\", \"Name\")\
		"))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}
	
	return db -> query ("COMMIT");
}

LIB::container::memory::memory (const std::string & __database_name)
{
//	db = other.db;
//	group = other.group;
//	previous_group = other.previous_group;
//	previous_name = other.previous_name;
	
	initialize (__database_name);
	//_database_name = __database_name;
}
/*
LIB::container::memory::memory (const memory & other, const std::string & __database_name)
{
//	db = other.db;
//	group = other.group;
//	previous_group = other.previous_group;
//	previous_name = other.previous_name;
	
	initialize (__database_name);
	
	operator = (other);
}
*/
LIB::container::memory::~memory (void)
{
	//if (db != NULL && group == default_group)
	//{
		finalize ();
	//	db = NULL;
	//}
}

const bool LIB::container::memory::finalize (void)
{
	try
	{
	//if (db != NULL && group == default_group)
	//{
		delete db;
	//	db = NULL;
	//}
		
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename archive>
void LIB::container::memory::save (archive & arch, const unsigned int & version) const
{
}

template <typename archive>
void LIB::container::memory::load (archive & arch, const unsigned int & version)
{
}

/*const bool LIB::container::memory::query (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> & result, const std::string & qry, const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> & arguments)
{
	return db -> query (result, qry, arguments);
}*/

const std::string & LIB::container::memory::database_name (void) const
{
	return _database_name;
}

LIB::container::database::sql::sqlite & LIB::container::memory::database (void)
{
	// It should always be safe to dereference,
	// because the constructors should normally ensure that an object is present.
	return * db;
}

//const LIB::container::memory::relation LIB::container::memory::relate (const LIB::container::memory::memory & other) const
//{
//	relation rel/* = relation::self*/;
//	
//	return rel;
//}
/*
const bool LIB::container::memory::operator == (const LIB::container::memory & other) const
{
	//typeid ();
	if (db == other.db)	// Is this everything which is needed?
		return true;
	
	return false;
}

const bool LIB::container::memory::operator != (const LIB::container::memory & other) const
{
	return ! (operator == (other));
}
*/
/*
const bool LIB::container::memory::operator == (const LIB::container::memory::value & other) const
{
	return false;
}

const bool LIB::container::memory::operator != (const LIB::container::memory::value & other) const
{
	return ! operator == (other);
}
*/
/*
const LIB::container::memory & LIB::container::memory::operator = (const LIB::container::memory & other)
{
	return * this;
}
*/
//const LIB::container::memory & LIB::container::memory::operator = (const LIB::container::memory::value & val)
//{
//	if (clear ())
//	{
//		LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//		
//		arguments [1] = group;
//		arguments [2] = 0;
//		arguments [3] = previous_name;
//		arguments [4] = 0;
//		arguments [5] = val;
//		
//		db -> query ("INSERT OR REPLACE INTO \"Entities\" (\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\") VALUES (?, ?, ?, ?, ?)", arguments);
//	}
//	
//	return * this;
//}

const LIB::mathematics::numbers::natural LIB::container::memory::size (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT COUNT (*)\n\
		FROM \"Entities\"\
		");
	
	return result [1] [1];
}

const LIB::mathematics::numbers::natural LIB::container::memory::size_group (const LIB::container::memory::key & group) const
{
	return false;
}

const bool LIB::container::memory::clear (void)
{
	return
	db -> query ("\
		DELETE FROM\n\
		\"Entities\"\
		");
}

const bool LIB::container::memory::clear_group (const LIB::container::memory::key & group)
{
	return false;
}

const bool LIB::container::memory::empty (void) const
{
	return ! (size () > 0);
}

const bool LIB::container::memory::empty_group (const LIB::container::memory::key & group) const
{
	return false;
}

const bool LIB::container::memory::full (void) const
{
	return false;
}

const bool LIB::container::memory::exists (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	//key grp;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
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
	
	//grp = sequence_group_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	db -> query (result, "\
		SELECT COUNT (*)\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = ? AND \"Name\" = ?\
		", arguments);
	
	return result [1] [1] > 0;
}

//const bool LIB::container::memory::exists (const LIB::container::memory::key & name) const
//{
//	return exist (name);
//}
/*
const LIB::container::memory LIB::container::memory::operator + (const LIB::container::memory::value & val) const
{}
*/
/*
const LIB::container::memory LIB::container::memory::operator + (const LIB::container::memory & other) const
{
	memory aggregate (* this); // use the default_database_name
	
	// Add "other" to "this".
	
	return aggregate;
}
*/
/*
const LIB::container::memory & LIB::container::memory::operator += (const LIB::container::memory::value & val)
{}
*/
/*
const LIB::container::memory & LIB::container::memory::operator += (const LIB::container::memory & other)
{
	return * this;
}
*/
const bool LIB::container::memory::add (const LIB::container::memory::key & k, const LIB::container::memory::value & val)
{
	key used_group;
	
	return add (used_group, k, val);
}

const bool LIB::container::memory::add (LIB::container::memory::key & used_group, const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	used_group = sequence_group_next_available ();
	
	return _set (used_group, k, v);
}
/*
const bool LIB::container::memory::add (const LIB::container::memory & other)
{
	return false;
}
*/
const bool LIB::container::memory::append (const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	key used_group;
	
	return append (used_group, k, v);
}

const bool LIB::container::memory::append (LIB::container::memory::key & used_group, const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	used_group = sequence_group_next ();
	
	return _set (used_group, k, v);
}

const bool LIB::container::memory::_set (const LIB::container::memory::key & used_group, const LIB::container::memory::key & k, const LIB::container::memory::value & val)
{
	if (! db -> query ("BEGIN"))
		return false;
	
	// To be completed.
	/*
	used_group = sequence_group_next ();
	
	if (! set_group (used_group, val))
		return false;
	
	memory mem ();
	
	if (! mem.set (val))
		return false;
	
	return true;
	*/
	
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	//used_group = sequence_group_next ();
	
	arguments [1] = used_group;
	
	//std::cout << "\tsequence_next () == " << sequence_group_next () << std::endl;
	//std::cout << "\tused_group == " << used_group << std::endl;
	//std::cout << "\targuments [1] == " << arguments [1] << std::endl;
	//std::cout << "\targuments [1].to_string () == " << arguments [1].to_string () << std::endl;
	//std::cout << "\targuments [1].to_string ().c_str () == " << arguments [1].to_string ().c_str () << std::endl;
	//std::cout << "\targuments [1].to_string ().size () == " << arguments [1].to_string ().size () << std::endl;
	arguments [2] = 0;
	arguments [3] = k;
	arguments [4] = 0;
	arguments [5] = val;
	
	if (! db -> query ("\
		INSERT OR IGNORE INTO \"Entities\"\n\
		(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
		VALUES\n\
		(?, ?, ?, ?, ?)\
		", arguments))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}
	//else
	//{
	//	return true;
	//}
	
	return db -> query ("COMMIT");
}
/*
const bool LIB::container::memory::append (const LIB::container::memory & other)
{}
*/
const bool LIB::container::memory::push (const LIB::container::memory::key & k, const LIB::container::memory::value & val)
{
	key used_group;
	
	return push (used_group, k, val);
}

const bool LIB::container::memory::push (LIB::container::memory::key & used_group, const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	return append (used_group, k, v);
}

const bool LIB::container::memory::pop (void)
{
	if (! db -> query ("BEGIN"))
		return false;
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	if (! db -> query ("\
		DELETE FROM \"Entities\"\n\
		WHERE GROUP = (SELECT COALESCE (MAX (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		"))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}
	
	return db -> query ("COMMIT");
}

const LIB::mathematics::numbers::integer LIB::container::memory::key_group_integral_min (void) const
{
	/*
	key i = key_group_integral_max ();
	
	for (auto & element: *this)
	{
		if (element.k.is_numeric () && element.k < i)
		{
			i = element.k;
		}
	}
	
	return i;
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT COALESCE (MIN (\"Group\"), 0)\n\
		FROM \"Entities\"\
		WHERE TYPEOF (\"Group\") = 'integer'\
		");
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// ? There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::mathematics::numbers::integer LIB::container::memory::key_group_integral_max (void) const
{
	/*
	key i = 1;
	
	for (auto & element : *this)
	{
		if (element.k.is_numeric () && element.k > i)
		{
			i = element.k;
		}
	}
	
	return i;
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT COALESCE (MAX (\"Group\"), 0)\n\
		FROM \"Entities\"\
		WHERE TYPEOF (\"Group\") = 'integer'\
		");
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// ? There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::mathematics::numbers::integer LIB::container::memory::key_name_integral_min (const LIB::container::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	
	db -> query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MIN (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" = ?\
		",
		arguments
	);
	
	// There should always be a result, because of the coalesce function.
	return result [1] [1];
}

const LIB::mathematics::numbers::integer LIB::container::memory::key_name_integral_max (const LIB::container::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	
	db -> query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MAX (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" = ?\
		",
		arguments
	);
	
	// There should always be a result, because of the coalesce function.
	return result [1] [1];
}

const bool LIB::container::memory::enqueue (const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	key used_group;
	
	return enqueue (used_group, k, v);
}

const bool LIB::container::memory::enqueue (LIB::container::memory::key & used_group, const LIB::container::memory::key & k, const LIB::container::memory::value & v)
{
	return append (used_group, k, v);
}

const bool LIB::container::memory::dequeue (void)
{
	if (! db -> query ("BEGIN"))
		return false;
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	if (! db -> query ("\
		DELETE FROM \"Entities\"\n\
		WHERE GROUP = (SELECT COALESCE (MIN (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		"))
	{
		db -> query ("ROLLBACK");
		
		return false;
	}
	
	if (db -> effect () > 0 && key_group_integral_min () > 1)
	{
		if (! db -> query ("\
			UPDATE \"Entities\"\n\
			SET \"Group\" = \"Group\" - 1\n\
			WHERE TYPEOF (\"Group\") = 'integer'\
			"))
		{
			db -> query ("ROLLBACK");
			
			return false;
		}
	}
	
	return db -> query ("COMMIT");
}

const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::container::memory::beginning (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = (SELECT COALESCE (MIN (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		");
	
	return result [1];
}

const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::container::memory::ending (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = (SELECT COALESCE (MAX (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		");
	
	return result [1];
}

/*
const bool LIB::container::memory::push (const LIB::container::memory::value & val)
{}

const bool LIB::container::memory::push (const LIB::container::memory::value & val, LIB::container::memory::key & used_key)
{}

const bool LIB::container::memory::pop (void)
{}
*/
//const bool LIB::container::memory::integral_key (void) const
//{}

const LIB::mathematics::numbers::natural LIB::container::memory::sequence_group_next_available (void) const
{
	/*
	for (key i = 1; i <= size (); ++ i)
	{
		if (! exists (i))
		{
			return i;
		}
	}
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	db -> query (result, "\
		SELECT DISTINCT\n\
			-- \"T1\".\"ID\" AS \"Original\", \"T1\".\"ID\" + 1 AS \"Next\", TYPEOF (\"T1\".\"ID\") AS \"Type\"\n\
			\"T1\".\"ID\" + 1 AS \"ID\"\n\
		FROM\n\
				(\n\
					SELECT DISTINCT\n\
						0 AS \"ID\"\n\
					\n\
					UNION\n\
					\n\
					SELECT DISTINCT\n\
						\"T4\".\"Group\" AS \"ID\"\n\
					FROM\n\
						\"Entities\" AS \"T4\"\n\
					WHERE\n\
						\"T4\".\"Group\" IS NOT NULL\n\
						AND\n\
						TYPEOF (\"T4\".\"Group\") = 'integer'\n\
					\n\
					ORDER BY\n\
						\"ID\" ASC\n\
				) AS \"T1\"\n\
			LEFT OUTER JOIN\n\
				(\n\
					SELECT DISTINCT\n\
						0 AS \"ID\"\n\
					\n\
					UNION\n\
					\n\
					SELECT DISTINCT\n\
						\"T4\".\"Group\" AS \"ID\"\n\
					FROM\n\
						\"Entities\" AS \"T4\"\n\
					WHERE\n\
						\"T4\".\"Group\" IS NOT NULL\n\
						AND\n\
						TYPEOF (\"T4\".\"Group\") = 'integer'\n\
					\n\
					ORDER BY\n\
						\"ID\" ASC\n\
				) AS \"T2\"\n\
					ON \"T1\".\"ID\" = \"T2\".\"ID\" - 1\n\
		WHERE\n\
			\"T2\".\"ID\" IS NULL\n\
			AND\n\
			\"T1\".\"ID\" + 1 >= 1\n\
		ORDER BY \"T1\".\"ID\" ASC\n\
		\n\
		LIMIT 1\
	");
	
	return result [1] [1];
	//return 1;
}

const LIB::mathematics::numbers::natural LIB::container::memory::sequence_group_next (void) const
{
	return key_group_integral_max () + 1;
}

const LIB::mathematics::numbers::natural LIB::container::memory::sequence_name_next_available (const LIB::container::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	arguments.append (group);
	
	//_memory -> database ().query
	db -> query
	(
		result,
		"\
			SELECT DISTINCT\n\
				-- \"T1\".\"ID\" AS \"Original\", \"T1\".\"ID\" + 1 AS \"Next\", TYPEOF (\"T1\".\"ID\") AS \"Type\"\n\
				\"T1\".\"ID\" + 1 AS \"ID\"\n\
			FROM\n\
					(\n\
						SELECT DISTINCT\n\
							0 AS \"ID\"\n\
						\n\
						UNION\n\
						\n\
						SELECT DISTINCT\n\
							\"T4\".\"Name\" AS \"ID\"\n\
						FROM\n\
							\"Entities\" AS \"T4\"\n\
						WHERE\n\
							\"T4\".\"Name\" IS NOT NULL\n\
							AND\n\
							TYPEOF (\"T4\".\"Name\") = 'integer'\n\
							AND\n\
							\"T4\".\"Group\" = ?\n\
						\n\
						ORDER BY\n\
							\"ID\" ASC\n\
					) AS \"T1\"\n\
				LEFT OUTER JOIN\n\
					(\n\
						SELECT DISTINCT\n\
							0 AS \"ID\"\n\
						\n\
						UNION\n\
						\n\
						SELECT DISTINCT\n\
							\"T4\".\"Name\" AS \"ID\"\n\
						FROM\n\
							\"Entities\" AS \"T4\"\n\
						WHERE\n\
							\"T4\".\"Name\" IS NOT NULL\n\
							AND\n\
							TYPEOF (\"T4\".\"Name\") = 'integer'\n\
							AND\n\
							\"T4\".\"Group\" = ?\n\
						\n\
						ORDER BY\n\
							\"ID\" ASC\n\
					) AS \"T2\"\n\
						ON \"T1\".\"ID\" = \"T2\".\"ID\" - 1\n\
			WHERE\n\
				\"T2\".\"ID\" IS NULL\n\
				AND\n\
				\"T1\".\"ID\" + 1 >= 1\n\
			ORDER BY \"T1\".\"ID\" ASC\n\
			\n\
			LIMIT 1\
		",
		arguments
	);
	
	return result [1] [1];
}

const LIB::mathematics::numbers::natural LIB::container::memory::sequence_name_next (const LIB::container::memory::key & group) const
{
	return key_name_integral_max (group) + 1;
}

const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> LIB::container::memory::list (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	//LIB::container::NAME_A <LIB::container::memory, LIB::container::memory::key> entities;
	
	//arguments [1] = group;
	//db -> query (result, "SELECT \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arguments);
	db -> query (result, "SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\" FROM \"Entities\"");
	
//	for (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::container & row : result)
//	{
//		//for (LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>::container & column : row.v)
//		//{
//		//	// This loop should last for only one (1) iteration.
//		//}
//		{
//			LIB::container::memory mem (db, row.v [2], group, row.v [1]);
//			
//			entities [row.v [1]] = mem;
//		}
//	}
//	
//	return entities;
	return result;
}

const bool LIB::container::memory::refresh_list (void)
{
	_list = list ();
	
	return true;
}

const LIB::container::memory::iterator LIB::container::memory::begin (void) const
{
	//return _list.begin ();
	
	LIB::container::memory::iterator iter;
	/*
	if (! iter.set)
	{
		//iter.list = list ();
		//iter.list = _list;
		iter.set = true;
	}
	*/
	//iter.iter = iter.list.begin ();
	iter.iter = _list.begin ();
	
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}

const LIB::container::memory::iterator LIB::container::memory::end (void) const
{
	//return _list.end ();
	
	LIB::container::memory::iterator iter;
	/*
	if (! iter.set)
	{
		//iter.list = list ();
		//iter.list = _list;
		iter.set = true;
	}
	*/
	//iter.iter = iter.list.end ();
	iter.iter = _list.end ();
	
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}

const std::string LIB::container::memory::serialize (void) const
{
	return LIB::serialize <LIB::container::memory> (* this);
}

const bool LIB::container::memory::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::container::memory> (serial, * this);
}

/*operator const std::string (void) const
{
	return serialize ();
}

const LIB::container::memory & operator = (const std::string & serial)
{
	deserialize (serial);
	return *this;
}*/

//LIB::container::memory::operator const value (void) const
//{
//	return get ();
//}

//LIB::container::memory LIB::container::memory::operator [] (const key & name)
//{
//	if (! exists (name))
//	{
//		set_group (name);
//	}
//	
//	return get (name);
//}

/*const LIB::container::memory & LIB::container::memory::operator [] (const key & name) const
{
	return *this;
}*/

//const LIB::container::memory::value LIB::container::memory::get (void) const
//{
//	// Set "Reference" to "false" and "Content/Content" to ""
//	// if the name which is being
//	
//	//content_clear_group ();
//	
//	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	arguments [1] = previous_group;
//	arguments [2] = previous_name;
//	
//	if (db -> query (result, "\
//			SELECT \"Content\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\
//			", arguments))
//	{
//		if (! result.empty ())
//		{
//			return result [1] [1];
//		}
//		//if (result.empty ())
//		//{
//		//	return "";
//		//}
//		//else
//		//{
//		//	return result [1] [1];
//		//}
//	}
//	//else
//	//{
//	//	return "";
//	//}
//	
//	return "";
//	
//	//return mem;
//}
//
//const LIB::container::memory LIB::container::memory::get (const LIB::container::memory::key & nm) const
//{
//	//content_clear_literal (nm/* the new, inexistent, (sub-)name*/);
//	
//	key grp;
//	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	/*
//	
//	arguments [1] = group;
//	arguments [2] = name;
//	
//	if (db -> query (result, "SELECT \"Name\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?);", arguments))
//	{
//		if (result.empty ())
//		{
//			return "";
//		}
//		else
//		{
//			return result [1] [1];
//		}
//	}
//	else
//	{
//		return "";
//	}
//	*/
//	
//	//grp = sequence_group_next_available ();
//	
//	//if (grp <= 0)
//	//	return *this;
//	
//	arguments [1] = group;
//	arguments [2] = nm;
//	//arguments [3] = nm;
//	
//	//db -> query (NULL, "BEGIN;\n\
//			--DELETE FROM \"Entities\"\n\
//			--WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			INSERT OR REPLACE INTO \"Entities\"\n\
//			(\"Group\", \"Name\", \"Reference\", \"Content\")\n\
//			VALUES (?, ?, ?, ?), (?, ?, ?, ?);\n\
//			COMMIT;", arguments);
//	//db -> query (NULL, "BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Reference\" = ?, \"Content\" = NULL\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;", arguments);
//	
//	grp = "";
//	
//	if (db -> query (result, "\
//			SELECT \"Content\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = ? AND \"Name\" = ? AND \"Content: Type\" != 0;\
//			", arguments))
//	{
//		if (! result.empty ())
//		{
//			grp = result [1] [1];
//		}
//		//else
//		//{
//		//	grp = result [1] [1];
//		//}
//	}
//	//else
//	//{
//	//	grp = "";
//	//}
//	
//	memory mem (db, grp, group, nm);
//	//return memory (db, group, name);
//	return mem;
//	//return result;
//}

//const bool LIB::container::memory::set/*_literal*/ (const LIB::container::memory::value & val)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	//arguments [1] = 0;
//	arguments [1] = val;
//	arguments [2] = previous_group;
//	arguments [3] = previous_name;
//	
//	return db -> query (NULL, "\
//			BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = 0, \"Content\" = ?\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;\
//			", arguments);
//}

const bool LIB::container::memory::set (const LIB::container::memory::key & name, const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::memory::value> & values, const LIB::container::memory::key & group)
{
	//if (! values.exists ("Group") || ! values.exists ("Name"))
	//{
	//	return false;
	//}
	
	//LIB::container::NAME_A <LIB::container::NAME_V, value> columns;
	
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	
	LIB::container::NAME_A <> cols;
	
	std::string column_names = "\"Group\", \"Name\"", column_placeholders = "?, ?";
	
	arguments.append (group);
	arguments.append (name);
	
	//cols.append ("Group");
	cols.append ("Name: Type");
	//cols.append ("Name");
	cols.append ("Content: Type");
	cols.append ("Content");
	
	//LIB::container::NAME_V val;
	
	for (const LIB::container::NAME_A <>::container & column_name : cols)
	{
		column_names += ", \"" + column_name.v.to_string () + '\"';
		column_placeholders += ", ?";
		
		if (values.exists (column_name.v))
		{
			arguments.append (values [column_name.v]);
		}
		//else
		//{
			//if (column_name.v == "Name: Type" || column_name.v == "Content: Type")
			//{
			//	arguments.append (0);
			//}
			else// if (column_name == "Content")
			{
				arguments.append (default_value);
			}
		//}
	}
	
	//// Remove the trailing ", ".
	//column_names.substr (0, column_names.size () - 2);
	//column_placeholders.substr (0, column_placeholders.size () - 2);
	
	
	//arguments.append (group);
	//arguments.append (name);
	
	std::cout <<
			"\
			INSERT OR REPLACE INTO \"Entities\"\n\
			" + column_names + "\n\
			VALUES\n\
			(" + column_placeholders + ")\
			"
			<< std::endl;
	
	std::cout << "Arguments:" << std::endl;
	for (const auto & arg : arguments)
	{
		std::cout << '[' << arg.k << ']' << " => " << '[' << arg.v << ']' << std::endl;
	}
	std::cout << "Arguments." << std::endl;
	
	return db -> query ("\
			INSERT OR REPLACE INTO \"Entities\"\n\
			(" + column_names + ")\n\
			VALUES\n\
			(" + column_placeholders + ")\
			", arguments);
//			\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n
//			WHERE \"Group\" = ? AND \"Name\" = ?;
}

const bool LIB::container::memory::set (const LIB::container::memory::key & name, const LIB::container::memory::key & group)
{
	const LIB::container::NAME_A <LIB::container::NAME_V, value> values;
	
	return set (name, values, group);
}
/*
const bool LIB::container::memory::set (const LIB::container::memory & other)
{
	operator = (other);
	
	return true;
}
*/
//const bool LIB::container::memory::set_group (const LIB::container::memory::key & name)
//{
//	key used_group;
//	return set_group (name, used_group);
//}
//
//const bool LIB::container::memory::set_group (const LIB::container::memory::key & name, const LIB::container::memory::key & used_group)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	//key grp = sequence_group_next_available ();
//	used_group =  sequence_group_next_available ();
//	
//	arguments [1] = used_group;
//	arguments [2] = name;
//	arguments [3] = 1;
//	//arguments [3] = previous_group;
//	
//	if (! db -> query (NULL, "BEGIN", NULL))
//	{
//		db -> query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	if (!
//		db -> query (NULL, "\
//			INSERT OR IGNORE INTO \"Entities\"\n\
//			(\"Group\", \"Name\", \"Content: Type\", \"Content\")\n\
//			VALUES (?, ?, ?, NULL)\
//			", arguments)
//	)
//	{
//		db -> query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	arguments [1] = 1;
//	arguments [2] = used_group;
//	arguments [3] = previous_group;
//	arguments [4] = previous_name;
//	
//	if (!
//		db -> query (NULL, "\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = ?, \"Content\" = ?\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?\
//			", arguments)
//	)
//	{
//		db -> query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	return db -> query (NULL, "COMMIT", NULL);
//}
//
//const bool LIB::container::memory::set_group (void)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	arguments [1] = 1;
//	arguments [2] = previous_group;
//	arguments [3] = previous_name;
//	
//	return db -> query (NULL, "\
//			BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = ?, \"Content\" = NULL\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;\
//			", arguments);
//}

const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::container::memory::get (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	// This is the default, backup variable:
	const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> columns;
	
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	
	arguments [1] = group;
	arguments [2] = name;
	
	//	SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
	//
	db -> query (result, "\
		SELECT \"Name: Type\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = ? AND \"Name\" = ?\
		", arguments);
	
	if (result.empty ())
	{
		// Return the default, backup variable.
		return columns;
	}
	else
	{
		// There should always be one row present because of the (unique) index, if there is anything present.
		// Return the first (and only) row.
		// 
		// Use the fact that "LIB::container::memory::value == LIB::container::NAME_V", for now.
		return result [1];
	}
}

const bool LIB::container::memory::is_name_literal (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	//key grp;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
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
	
	//grp = sequence_group_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "\
			SELECT \"Name: Type\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?\
			", arguments));
	
	return result [1] [1] == 0;
}
/*
const bool LIB::container::memory::is_name_group (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	return ! is_name_literal (name, group);
}
*/
const bool LIB::container::memory::is_content_literal (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	//key grp;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
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
	
	//grp = sequence_group_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (db -> query (result, "\
			SELECT \"Content: Type\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?\
			", arguments));
	
	return result [1] [1] == 0;
}
/*
const bool LIB::container::memory::is_value_group (const LIB::container::memory::key & name, const LIB::container::memory::key & group) const
{
	return ! is_content_literal (name, group);
}
*/
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
