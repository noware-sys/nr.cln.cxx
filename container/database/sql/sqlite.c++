/*
#include "sqlite.h++"
#include "../../mathematics.h++"

#include <iostream>
#include <assert.h>
*/
//static const unsigned short int LIB::container::database::sql::sqlite::default_tries;
const LIB::mathematics::numbers::natural LIB::container::database::sql::sqlite::default_tries = 3;


LIB::container::database::sql::sqlite::sqlite (const std::string & name)
{
	//sqlite3_open (name.c_str (), & db);
	connect (name);
}

LIB::container::database::sql::sqlite::sqlite (void)
{
	_connected = false;
}

LIB::container::database::sql::sqlite::~ sqlite (void)
{
	//sqlite3_close (db);
	//while (connected ())
	//{
		disconnect ();
	//}
}

const bool LIB::container::database::sql::sqlite::connect (const std::string & name)
{
	if (_connected && ! disconnect ())
	{
		return false;
	}
	else if (sqlite3_open (name.c_str (), & db) == SQLITE_OK)
	{
		_connected = true;
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool LIB::container::database::sql::sqlite::disconnect (void)
{
	if (! _connected)
	{
		return true;
	}
	else if (sqlite3_close (db) == SQLITE_OK)
	{
		_connected = false;
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool LIB::container::database::sql::sqlite::connected (void) const
{
	return _connected;
}
/*
const sqlite & LIB::container::database::operator = (const sqlite & other)
{
	return *this;
}
*/
const bool LIB::container::database::operator == (const sqlite & other) const
{
	return this == & other;
}

const bool LIB::container::database::sql::sqlite::query (LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> & result, const std::string & qry, const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> & arguments, const LIB::mathematics::numbers::natural & tries_max)
{
	if (! connected ())
		return false;
	
	//LIB::containers::NAME_V val;
	//LIB::mathematics::numbers::natural count;
	//
	//va_list argv;
	//va_start (argv, count);
	//
	//val = va_arg (argv, LIB::containers::NAME_V);
	//
	//va_end (argv);
	
	
	// Try to reset the counter representing the number of changed rows.
	/*
	if (sqlite3_mutex_held (db -> mutex) != 0)
	{
		std::cout << "Trying to reset the counter." << std::endl;
		db -> nChange = 0;
		std::cout << "effect (after resetting the counter) == [" << effect () << ']' << std::endl;
	}
	*/
	#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
		//std::cout << "effect (before resetting the counter) == [" << effect () << ']' << std::endl;
		//std::cout << "Trying to reset the counter." << std::endl;
		//sqlite3VdbeSetChanges (db, 0);
		effect/*_set*/ (0);
		//std::cout << "effect (after resetting the counter) == [" << effect () << ']' << std::endl;
	#endif
	
	
	sqlite3_stmt * statement;
	const char * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	LIB::mathematics::numbers::natural result_code;
	LIB::mathematics::numbers::natural column_count;
	signed int column;
	LIB::mathematics::numbers::natural row;
	LIB::mathematics::numbers::natural tries;
	
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, qry.c_str (), qry.size (), & statement, & query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//std::cout << "effect (after 'prepare ()') == [" << effect () << ']' << std::endl;
	
	
	if (/*arguments != NULL && */! arguments.empty ())
	{
		for (auto & argument : arguments)
		{
			//if (value.v.is_string ())
			//{
				//val = value.v;
				//sqlite3_bind_value (statement, value.k, & val);
				if (argument.v.is_numeric ())
				{
					sqlite3_bind_double (statement, argument.k, argument.v);
				}
				else
				{
					sqlite3_bind_text (statement, argument.k, argument.v.to_string ().c_str (), argument.v.to_string ().size (), SQLITE_STATIC);
					//sqlite3_bind_value (statement, argument.k, & argument.v);
				}
				/*
				std::cout << "\t\targument.k == " << argument.k << std::endl;
				std::cout << "\t\targument.v == " << argument.v << std::endl;
				std::cout << "\t\targument.v.to_string () == " << argument.v.to_string () << std::endl;
				std::cout << "\t\targument.v.to_string ().c_str () == " << argument.v.to_string ().c_str () << std::endl;
				std::cout << "\t\targument.v.to_string ().size () == " << argument.v.to_string ().size () << std::endl;
				*/
				//sqlite3_bind_text (statement, argument.k, argument.v.to_string ().c_str (), argument.v.to_string ().size (), SQLITE_STATIC);
				//sqlite3_bind_value (statement, argument.k, & argument.v);
			//}
		}
	}
	
	//if (result != NULL)
	//{
		column_count = sqlite3_column_count (statement);
		row = 1;
		tries = 1;
		// The next line is the fist try to evaluate the expression:
		// std::cout << "qry == (" << qry << ')' << std::endl;
		// std::cout << "column_count == " << column_count << std::endl;
		//std::cout << "effect (after 'column_count ()') == [" << effect () << ']' << std::endl;
		result_code = sqlite3_step (statement);
		//std::cout << "result_code == " << result_code << std::endl;
		//std::cout << "effect (after 'step ()') == [" << effect () << ']' << std::endl;
		while (result_code == SQLITE_ROW || (result_code == SQLITE_BUSY && tries_max <= 0) || (result_code == SQLITE_BUSY && tries < tries_max))
		{
			for (column = 0; column < column_count; ++ column)
			{
				//result [row] [column + 1] = sqlite3_column_value (statement, /*(signed int) */column);
				result [row] [column + 1] = std::string ((char *) sqlite3_column_text (statement, /*(signed int) */column));
				//std::cout << "result [" << row << "] [" << column + 1 << "] == " << result [row] [column + 1] << std::endl;
			}
			
			if (result_code == SQLITE_ROW)
			{
				++ row;
				tries = 1;
			}
			else if (result_code == SQLITE_BUSY && tries_max > 0)
			{
				++ tries;
			}
			
			result_code = sqlite3_step (statement);
			//std::cout << "effect (after 'step ()', subsequent) == [" << effect () << ']' << std::endl;
		}
	//}
	
	sqlite3_finalize (statement);
	//std::cout << "effect (after 'finalize ()') == [" << effect () << ']' << std::endl;
	
	return result_code == SQLITE_OK || result_code == SQLITE_DONE;
}

const bool LIB::container::database::sql::sqlite::query (LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> & result, const std::string & qry, const LIB::mathematics::numbers::natural & tries_max)
{
	const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	return query (result, qry, arguments, tries_max);
}

const bool LIB::container::database::sql::sqlite::query (const std::string & qry, const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> & arguments, const LIB::mathematics::numbers::natural & tries_max)
{
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	return query (result, qry, arguments, tries_max);
}

const bool LIB::container::database::sql::sqlite::query (const std::string & qry, const LIB::mathematics::numbers::natural & tries_max)
{
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	return query (result, qry, arguments, tries_max);
}

#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
	const bool LIB::container::database::sql::sqlite::effect/*_set*/ (const int & val)
	{
		sqlite3_changes_set (db, val);
		
		return true;
	}
#endif

const LIB::mathematics::numbers::natural LIB::container::database::sql::sqlite::effect (void) const
{
	return sqlite3_changes (db);
}
