#include <iostream>
#include "entity_2.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

// Memory: Iterator:

//const std::string LIB::containers::memory::default_database_name;

LIB::containers::entity_2::iterator::iterator (void)
{
	//set = false;
}

/*
LIB::containers::entity_2::iterator::iterator (const memory & other)
{
	operator = (other);
}

LIB::containers::entity_2::iterator::~iterator (void)
{
}

const LIB::containers::entity_2::iterator & LIB::containers::entity_2::iterator::operator = (const iterator & other)
{
	return *this;
}
*/

const bool LIB::containers::entity_2::iterator::operator == (const LIB::containers::entity_2::iterator & other) const
{
	return iter == other.iter;
}

const bool LIB::containers::entity_2::iterator::operator != (const LIB::containers::entity_2::iterator & other) const
{
	return ! (operator == (other));
}

const LIB::containers::entity_2::iterator & LIB::containers::entity_2::iterator::operator ++ (void)
{
	++ iter;
	
	return * this;
}

const LIB::containers::entity_2::iterator & LIB::containers::entity_2::iterator::operator -- (void)
{
	-- iter;
	
	return * this;
}

const LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key>::package & LIB::containers::entity_2::iterator::operator * (void) const
{
	//return * (iter -> v);
	return * iter;
}

// Memory:
const bool LIB::containers::entity_2::default_tolerant = true;
/*
const LIB::containers::memory::key LIB::containers::entity_2::default_group = "";
const LIB::containers::memory::key LIB::containers::entity_2::default_name = "";
const LIB::containers::memory::value LIB::containers::entity_2::default_value = "";
*/
const LIB::containers::memory::key LIB::containers::entity_2::default_name = "";
const LIB::containers::memory::value LIB::containers::entity_2::backup;
LIB::containers::NAME_A <LIB::mathematics::numbers::natural, LIB::containers::memory *> LIB::containers::entity_2::instances;

const bool LIB::containers::entity_2::initialize (const LIB::containers::entity_2 * other, const LIB::containers::memory::key & _name, const LIB::containers::memory::key & _group, const std::string & database)
{
	if (other == NULL)
	{
		_memory = new LIB::containers::memory (database);
		tolerant = default_tolerant;
		
		//++ instances [_memory];
		instances [_memory] = 0;
		
		LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
		
		arguments.append (group);
		arguments.append (default_name);
		arguments.append (memory::default_value);
		
		if
		(
			! _memory -> database ().query
			(
				"\
					INSERT OR IGNORE INTO \"Entities\"\n\
						(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
					VALUES\n\
						(?, 0, ?, 0, ?)\
				"
				/*"\
					UPDATE\n\
						\"Entities\"\n\
					SET\n\
						\"Content: Type\" = 0\n\
						\"Content\" = ?,\n\
					WHERE\n\
						\"Group\" = ?\
						AND\n\
						\"Name\" = ?\n\
				"*/
				,
				arguments
			)
		)
			return false;
	}
	else
	{
		try
		{
			_memory = other -> _memory;
			tolerant = other -> tolerant;
		}
		catch (...)
		{
			return false;
		}
	}
	
	std::cout << instances [_memory] << std::endl;
	++ instances [_memory];
	std::cout << instances [_memory] << std::endl;
	
	group = _group;
	name = _name;
	
	return true;
}
/*
const bool LIB::containers::entity_2::initialize (const std::string & database)
{
	return initialize (NULL, default_name, memory::default_group, database);
}
*/
LIB::containers::entity_2::entity_2 (const LIB::containers::entity_2 * other, const LIB::containers::memory::key & _name, const LIB::containers::memory::key & _group, const std::string & database)
{
	initialize (other, _name, _group, database);
}
/*
LIB::containers::entity_2::entity_2 (const std::string & database)
{
	initialize (NULL,.default_name, memory::default_group, database);
}
*/
LIB::containers::entity_2::entity_2 (const LIB::containers::entity_2 & other)
{
	std::cout << instances [_memory] << std::endl;
	++ instances [other._memory];
	std::cout << instances [_memory] << std::endl;
	
	_memory = other._memory;
	tolerant = other.tolerant;
	group = other.group;
	name = other.name;
}

const bool LIB::containers::entity_2::finalize (void)
{
	std::cout << instances [_memory] << std::endl;
	-- instances [_memory];
	std::cout << instances [_memory] << std::endl;
	
	if (instances [_memory] < 1)
	{
		delete _memory;
		instances.unset (_memory);
	}
}

LIB::containers::entity_2::~entity_2 (void)
{
	finalize ();
}

const LIB::mathematics::numbers::integer LIB::containers::entity_2::key_integral_min (void) const
{
	/*
	key i = key_integral_max ();
	
	for (auto & element: *this)
	{
		if (element.k.is_numeric () && element.k < i)
		{
			i = element.k;
		}
	}
	
	return i;
	*/
	
	if (is_content_literal ())
	{
		return 0;
	}
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	
	_memory -> database ().query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MIN (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" =\n\
				(\n\
					SELECT\n\
						\"Content\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" = ?\n\
						AND\n\
						\"Name\" = ?\n\
				)\
		",
		arguments
	);
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::mathematics::numbers::integer LIB::containers::entity_2::key_integral_max (void) const
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
	
	if (is_content_literal ())
	{
		return 0;
	}
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	
	_memory -> database ().query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MAX (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" =\n\
				(\n\
					SELECT\n\
						\"Content\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" = ?\n\
						AND\n\
						\"Name\" = ?\n\
				)\
		",
		arguments
	);
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::containers::memory::key LIB::containers::entity_2::sequence_next_available (void) const
{
	if (is_content_literal ())
		return 0;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (group);
	arguments.append (name);
	
	_memory -> database ().query
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
							\"T4\".\"Group\" =\n\
							(\n\
								SELECT\n\
									\"Content\"\n\
								FROM\n\
									\"Entities\"\n\
								WHERE\n\
									\"Group\" = ?\n\
									AND\n\
									\"Name\" = ?\n\
							)\n\
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
							\"T4\".\"Group\" =\n\
							(\n\
								SELECT\n\
									\"Content\"\n\
								FROM\n\
									\"Entities\"\n\
								WHERE\n\
									\"Group\" = ?\n\
									AND\n\
									\"Name\" = ?\n\
							)\n\
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

const LIB::containers::memory::key LIB::containers::entity_2::sequence_next (void) const
{
	return key_integral_max () + 1;
}

const bool LIB::containers::entity_2::set (const LIB::containers::memory::value & val)
{
	clear/*_group*/ ();
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (val);
	
	return _memory -> database ().query
	(
		"\
			INSERT OR REPLACE INTO \"Entities\"\n\
				(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
			VALUES\n\
				(?, 0, ?, 0, ?)\
		"
		/*"\
			UPDATE\n\
				\"Entities\"\n\
			SET\n\
				\"Content: Type\" = 0,\n\
				\"Content\" = ?\n\
			WHERE\n\
				\"Group\" = ?\
				AND\n\
				\"Name\" = ?\n\
		"*/,
		arguments
	);
}

const LIB::containers::memory::value LIB::containers::entity_2::get (void) const
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	
	if
	(
		_memory -> database ().query
		(
			result,
			"\
				SELECT\n\
					\"Content\"\n\
				FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" = ?\n\
					AND\n\
					\"Name\" = ?\n\
					--AND\n\
					--\"Content: Type\" = 0\n\
				LIMIT 1\
			",
			arguments
		)
		&&
		result.size () > 0
	)
	{
		return result [1] [1];
	}
	else
	{
		return backup;
	}
}

LIB::containers::entity_2::operator const LIB::containers::memory::value/* &*/ (void) const
{
	return get ();
}
/*
std::ostream & operator << (std::ostream & stream, const LIB::containers::entity_2 & ntt)
{
	stream << ntt.get ();
	
	return stream;
}
*/
/*
std::ostream & LIB::containers::entity_2::operator << (std::ostream & stream) const
{
	stream << get ();
	
	return stream;
}
*/
LIB::containers::entity_2 LIB::containers::entity_2::get (const LIB::containers::memory::key & _name)
{
	if (! tolerant && is_content_literal ())
		return *this;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	if (! _memory -> database ().query ("BEGIN"))
		return *this;
	
	//if (is_content_literal ())
	//{
		arguments [1] = _memory -> sequence_next_available ();
		
		arguments [2] = group;
		arguments [3] = name;
		//arguments [2] = _name;
		//arguments [3] = memory::default_value;
		
		// Make it a reference.
		if (! _memory -> database ().query
		(
			/*
			"\
				INSERT OR REPLACE INTO \"Entities\"\n\
					(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
				VALUES\n\
					(?, 0, ?, 1, ?)\
			",
			*/
			
			"\
				UPDATE\n\
					\"Entities\"\n\
				SET\n\
					\"Content: Type\" = 1,\n\
					\"Content\" = ?\n\
				WHERE\n\
					\"Group\" = ?\n\
					AND\n\
					\"Name\" = ?\n\
					AND\n\
					\"Content: Type\" = 0\
			",
			
			arguments
		))
			return *this;
	//}
	
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments [1] = group;
	arguments [2] = name;
	arguments.unset (3);
	//arguments.unset (4);
	
	// Select the group containing the requested name.
	if (! _memory -> database ().query
	(
		result,
		"\
			SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?\
		",
		arguments
	))
		return *this;
	
	//arguments [2] = _name;
	//arguments [3] = memory::default_value;
	arguments [1] = result [1] [1];
	arguments [2] = _name;
	arguments [3] = memory::default_value;
	
	// Create the referred group.
	if (! _memory -> database ().query
	(
		"\
			INSERT OR IGNORE INTO \"Entities\"\n\
				(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
			VALUES\n\
				(?, 0, ?, 0, ?)\
		",
		arguments
	))
		return *this;
	
	// Finally, return the representation of the new entity.
	return entity_2 (this, _name, result [1] [1], _memory -> database_name ());
	
}

const LIB::containers::entity_2 & LIB::containers::entity_2::operator = (const LIB::containers::entity_2 & other)
{
	finalize ();
	
	initialize (& other, other.name, other.group, other._memory -> database_name ());
	
	return * this;
}

const LIB::containers::memory::value & LIB::containers::entity_2::operator = (const LIB::containers::memory::value & val)
{
	set (val);
	
	return val;
}

LIB::containers::entity_2 LIB::containers::entity_2::operator [] (const LIB::containers::memory::key & _name)
{
	//clear_literal ();
	
	return get (_name);
}

const bool LIB::containers::entity_2::unset (const LIB::containers::memory::key & _name)
{
	if (is_content_literal ())
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (_name);
	
	return
		_memory -> database ().query
		(
			"\
				DELETE FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" = ?\
			",
			arguments
		)
	;
}

const bool LIB::containers::entity_2::rename (const LIB::containers::memory::key & name_current, const LIB::containers::memory::key & name_new)
{
	if (is_content_literal () || ! exists (name_current) || exists (name_new))
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (name_new);
	arguments.append (group);
	arguments.append (name);
	arguments.append (name_current);
	arguments.append (name_new);
	
	return
		_memory -> database ().query
		(
			"\
				UPDATE\n\
					\"Entities\"\n\
				SET\n\
					\"Name\" = ?\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" = ?\n\
					AND\n\
					\"Name\" != ?\
			",
			arguments
		)
	;
}

/*
const bool LIB::containers::entity_2::clear_literal (void)
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (default_name);
	
	return
		_memory -> database ().query
		(
			"\
				DELETE FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" = ?\n\
					AND\n\
					\"Name\" = ?\
			",
			arguments
		)
	;
}
*/
/*
const bool LIB::containers::entity_2::clear_group (void)
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	//arguments.append (name);
	
	return
		_memory -> database ().query
		(
			"\
				DELETE FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" = ?\n\
					--AND\n\
					--\"Name\" != ?\
			",
			arguments
		)
	;
}
*/

const LIB::mathematics::numbers::natural LIB::containers::entity_2::size (void) const
{
	if (is_content_literal ())
		return 1;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	
	_memory -> database ().query
	(
		result,
		"\
			SELECT\n\
				COUNT (*)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				\"Group\" =\n\
				(\n\
					SELECT\n\
						\"Content\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" = ?\n\
						AND\n\
						\"Name\" = ?\n\
				)\
		",
		arguments
	);
	
	return result [1] [1];
}

const bool LIB::containers::entity_2::clear (void)
{
	if (! _memory -> database ().query ("BEGIN"))
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	if (! is_content_literal ())
	{
		arguments.append (group);
		arguments.append (name);
		
		return
			_memory -> database ().query
			(
				"\
					DELETE\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" =\n\
						(\n\
							SELECT\n\
								\"Content\"\n\
							FROM\n\
								\"Entities\"\n\
							WHERE\n\
								\"Group\" = ?\n\
								AND\n\
								\"Name\" = ?\n\
						)\
				",
				arguments
			)
		;
	}
	
	
	arguments.clear ();
	
	arguments.append (LIB::containers::memory::default_value);
	arguments.append (group);
	arguments.append (name);
	
	if
	(
		! _memory -> database ().query
		(
			"\
			UPDATE\n\
				\"Entities\"\n\
			SET\n\
				\"Content: Type\" = 0,\n\
				\"Content\" = ?\n\
			WHERE\n\
				\"Group\" = ?\n\
				AND\n\
				\"Name\" = ?\n\
				--AND\n\
				--\"Content: Type\" != 0\
			",
			arguments
		)
	)
	{
		_memory -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	return _memory -> database ().query ("COMMIT");
}

const bool LIB::containers::entity_2::empty (void) const
{
	return ! (size () > 0);
}

const bool LIB::containers::entity_2::full (void) const
{
	return false;
}

const bool LIB::containers::entity_2::exists (const LIB::containers::memory::key & _name) const
{
	if (is_content_literal ())
		return false;
	
	//key grp;
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
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
	arguments [3] = _name;
	
	_memory -> database ().query (result, "\
		SELECT COUNT (*)\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?) AND \"Name\" = ?\
		", arguments);
	
	return result [1] [1] > 0;
}

const bool LIB::containers::entity_2::add (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key name;
	
	return add (val, name);
}

const bool LIB::containers::entity_2::add (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return _add (val, _name, sequence_next_available ());
}

const bool LIB::containers::entity_2::_add (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name, const LIB::containers::memory::key & sequence_next_value)
{
	if (! _memory -> database ().query ("BEGIN"))
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	//std::cout << sequence_next_value << std::endl;
	_name = sequence_next_value;
	
	arguments [1] = sequence_next_value;
	arguments [2] = group;
	arguments [3] = name;
	
	// Make it a reference.
	if
	(
		! _memory -> database ().query
		(
			"\
				UPDATE\n\
					\"Entities\"\n\
				SET\n\
					\"Content: Type\" = 1,\n\
					\"Content\" = ?\n\
				WHERE\n\
					\"Group\" = ?\n\
					AND\n\
					\"Name\" = ?\n\
					AND\n\
					\"Content: Type\" = 0\
			",
			arguments
		)
	)
		return false;
	
	arguments [1] = group;
	arguments [2] = name;
	arguments [3] = sequence_next_value;
	arguments [4] = val;
	
	// Add the new entry.
	if (! _memory -> database ().query
	(
		"\
			INSERT OR IGNORE\n\
			INTO\n\
				\"Entities\"\n\
				(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
			VALUES\n\
				((SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?), 0, ?, 0, ?)\
		",
		arguments
	))
	{
		_memory -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	return _memory -> database ().query ("COMMIT");
}

const bool LIB::containers::entity_2::append (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return append (val, _name);
}

const bool LIB::containers::entity_2::append (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return _add (val, _name, sequence_next ());
}

const bool LIB::containers::entity_2::enqueue (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return enqueue (val, _name);
}

const bool LIB::containers::entity_2::enqueue (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return append (val, _name);
}

const bool LIB::containers::entity_2::dequeue (void)
{
	if
	(
		! _memory -> database ().query
		(
			"BEGIN"
		)
	)
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (group);
	arguments.append (name);
	
	// Remove the first entry.
	if
	(
		! _memory -> database ().query
		(
			"\
				DELETE\n\
				FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" =\n\
					(\n\
						SELECT COALESCE (MIN (\"Name\"), 0)\n\
						FROM \"Entities\"\
						WHERE TYPEOF (\"Name\") = 'integer'\n\
						AND \"Group\" =\n\
						(\n\
							SELECT\n\
								\"Content\"\n\
							FROM\n\
								\"Entities\"\n\
							WHERE\n\
								\"Group\" = ?\n\
								AND\n\
								\"Name\" = ?\n\
						)\n\
					)\
			",
			arguments
		)
	)
		return false;
	
	arguments.unset (3);
	arguments.unset (4);
	
	// Shift the next entries by one, towards the beginning.
	if
	(
		! _memory -> database ().query
		(
			"\
				UPDATE\n\
					\"Entities\"\n\
				SET\n\
					\"Name\" = \"Name\" - 1\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					TYPEOF (\"Name\") = 'integer'\n\
					AND\n\
					\"Name\" > 0\
			",
			arguments
		)
	)
	{
		_memory -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	return
		_memory -> database ().query
		(
			"COMMIT"
		)
	;
}

const bool LIB::containers::entity_2::push (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return push (val, _name);
}

const bool LIB::containers::entity_2::push (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return append (val, _name);
}

const bool LIB::containers::entity_2::pop (void)
{
	if
	(
		! _memory -> database ().query
		(
			"BEGIN"
		)
	)
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (group);
	arguments.append (name);
	
	// Remove the last entry.
	if
	(
		! _memory -> database ().query
		(
			"\
				DELETE\n\
				FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" =\n\
					(\n\
						SELECT\n\
							COALESCE (MAX (\"Name\"), 0)\n\
						FROM\n\
							\"Entities\"\
						WHERE\n\
							TYPEOF (\"Name\") = 'integer'\n\
							AND \"Group\" =\n\
							(\n\
								SELECT\n\
									\"Content\"\n\
								FROM\n\
									\"Entities\"\n\
								WHERE\n\
									\"Group\" = ?\n\
									AND\n\
									\"Name\" = ?\n\
							)\n\
					)\
			",
			arguments
		)
	)
		return false;
	
	return
		_memory -> database ().query
		(
			"COMMIT"
		)
	;
}

const bool LIB::containers::entity_2::refresh_list (void)
{
	for (const LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key>::package & element : _list)
	{
		delete element.v;
	}
	_list.clear ();
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	if (is_content_literal ())
	{
		arguments.append (group);
		
		if
		(
			! _memory -> database ().query
			(
				result,
				"\
					SELECT\n\
						\"Group\",\n\
						\"Name\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" = ?\
				",
				arguments
			)
		)
			return false;
	}
	else
	{
		arguments.append (group);
		arguments.append (name);
		
		if
		(
			! _memory -> database ().query
			(
				result,
				"\
					SELECT\n\
						\"Group\",\n\
						\"Name\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" =\n\
						(\n\
							SELECT\n\
								\"Content\"\n\
							FROM\n\
								\"Entities\"\n\
							WHERE\n\
								\"Group\" = ?\n\
								AND\n\
								\"Name\" = ?\n\
						)\
				",
				arguments
			)
		)
			return false;
	}
	
	for (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::package & row : result)
	{
		//for (const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>::package & column : row.v)
		//{
			//_list.append (entity_2 (this, row.v [2], row.v [1], _memory -> database_name ()));
			_list [row.v [2]] = new entity_2 (this, row.v [2], row.v [1], _memory -> database_name ());
		//}
	}
	
	return true;
}

const LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key> & LIB::containers::entity_2::list (void) const
{
	return _list;
}

const LIB::containers::entity_2::iterator LIB::containers::entity_2::begin (void)
{
	iterator iter;
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	iter.iter = _list.begin ();
	
	return iter;
}

const LIB::containers::entity_2::iterator LIB::containers::entity_2::end (void)
{
	iterator iter;
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	iter.iter = _list.end ();
	
	return iter;
}

const LIB::containers::entity_2 LIB::containers::entity_2::beginning (void) const
{
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	return *this;
}

const LIB::containers::entity_2 LIB::containers::entity_2::ending (void) const
{
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	return *this;
}

const LIB::containers::entity_2::relation LIB::containers::entity_2::relate (const LIB::containers::entity_2 & other) const
{
	return relation::other;
}

const bool LIB::containers::entity_2::is_content_literal (void) const
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (name);
	
	_memory -> database ().query
	(
		result,
		"\
			SELECT\n\
				\"Content: Type\"\n\
			FROM\n\
				\t\"Entities\"\n\
			WHERE\n\
				\t\"Group\" = ?\n\
				\tAND\n\
				\t\"Name\" = ?\
		",
		arguments
	);
	
	return result [1] [1] == 0;
}

const std::string LIB::containers::entity_2::serialize (void) const
{
	return LIB::serialize <LIB::containers::entity_2> (* this);
}

const bool LIB::containers::entity_2::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::containers::entity_2> (serial, * this);
}

template <typename archive>
void LIB::containers::entity_2::save (archive & arch, const unsigned int & version) const
{
}

template <typename archive>
void LIB::containers::entity_2::load (archive & arch, const unsigned int & version)
{
}
