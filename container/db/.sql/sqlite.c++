/*
#include "sqlite.h++"
#include "../../math.h++"

#include <iostream>
#include <assert.h>
*/
//#include "../../../name.h++"

//static const unsigned short int LIB::container::db::sql::sqlite::default_tries;
const LIB::math::numbers::natural LIB::container::db::sql::sqlite::default_tries = 3;


LIB::container::db::sql::sqlite::sqlite (const std::string & name)
{
	//sqlite3_open (name.c_str (), & db);
	connect (name);
}

LIB::container::db::sql::sqlite::sqlite (void)
{
	_connected = false;
}

LIB::container::db::sql::sqlite::~ sqlite (void)
{
	//sqlite3_close (db);
	//while (connected ())
	//{
		disconnect ();
	//}
}

const bool LIB::container::db::sql::sqlite::connect (const std::string & name)
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

const bool LIB::container::db::sql::sqlite::disconnect (void)
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

const bool LIB::container::db::sql::sqlite::connected (void) const
{
	return _connected;
}
/*
const sqlite & LIB::container::db::operator = (const sqlite & other)
{
	return *this;
}
*/
const bool LIB::container::db::sql::sqlite::operator == (const LIB::container::db::sql::sqlite & other) const
{
	return this == &other;
}

const bool LIB::container::db::sql::sqlite::query (LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> & result, const std::string & qry, const LIB::container::array <LIB::container::any, LIB::container::any> & arguments, const LIB::math::numbers::natural & tries_max)
{
	if (! connected ())
		return false;
	
	//LIB::container::any val;
	//LIB::math::numbers::natural count;
	//
	//va_list argv;
	//va_start (argv, count);
	//
	//val = va_arg (argv, LIB::container::any);
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
	LIB::math::numbers::natural result_code;
	LIB::math::numbers::natural column_count;
	signed int column;
	LIB::math::numbers::natural row;
	LIB::math::numbers::natural tries;
	
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
				//if (argument.v.is_numeric ())
				if (argument.v.type () == noware::container::any::container::type::numeric)
				{
					sqlite3_bind_double (statement, argument.k, argument.v);
				}
				else
				{
					//sqlite3_bind_text (statement, argument.k, argument.v.to_string ().c_str (), argument.v.to_string ().size (), SQLITE_STATIC);
					sqlite3_bind_text (statement, argument.k, argument.v.text ().c_str (), argument.v.text ().length (), SQLITE_STATIC);
					
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

const bool LIB::container::db::sql::sqlite::query (LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> & result, const std::string & qry, const LIB::math::numbers::natural & tries_max)
{
	const LIB::container::array <LIB::container::any, LIB::container::any> arguments;
	
	return query (result, qry, arguments, tries_max);
}

const bool LIB::container::db::sql::sqlite::query (const std::string & qry, const LIB::container::array <LIB::container::any, LIB::container::any> & arguments, const LIB::math::numbers::natural & tries_max)
{
	LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	
	return query (result, qry, arguments, tries_max);
}

const bool LIB::container::db::sql::sqlite::query (const std::string & qry, const LIB::math::numbers::natural & tries_max)
{
	LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	const LIB::container::array <LIB::container::any, LIB::container::any> arguments;
	
	return query (result, qry, arguments, tries_max);
}

#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
	const bool LIB::container::db::sql::sqlite::effect/*_set*/ (const int & val)
	{
		sqlite3_changes_set (db, val);
		
		return true;
	}
#endif

const LIB::math::numbers::natural LIB::container::db::sql::sqlite::effect (void) const
{
	return sqlite3_changes (db);
}
