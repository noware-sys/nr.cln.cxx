#include "sqlite.h++"
#include "../../mathematics.h++"

LIB::database::sqlite::sqlite (const std::string & name)
{
	sqlite3_open (name.c_str (), & db);
}

LIB::database::sqlite::~sqlite (void)
{
	sqlite3_close (db);
}

const bool LIB::database::sqlite::query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> & result, const std::string & qry, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> & arguments, const LIB::mathematics::numbers::natural & tries_max)
{
	//LIB::NAME_V val;
	//LIB::mathematics::numbers::natural count;
	//
	//va_list argv;
	//va_start (argv, count);
	//
	//val = va_arg (argv, LIB::NAME_V);
	//
	//va_end (argv);
	
	sqlite3_stmt * statement;
	const char * sql_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	LIB::mathematics::numbers::natural result_code;
	LIB::mathematics::numbers::natural column_count, column;
	LIB::mathematics::numbers::natural row;
	LIB::mathematics::numbers::natural tries;
	
	if (sqlite3_prepare_v2 (db, qry.c_str (), qry.size (), & statement, & sql_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	if (arguments != NULL && ! arguments.empty ())
	{
		for (auto & argument : arguments)
		{
			//if (value.v.is_string ())
			//{
				//val = value.v;
				//sqlite3_bind_value (statement, value.k, & val);
				sqlite3_bind_value (statement, argument.k, & argument.v);
			//}
		}
	}
	
	if (result != NULL)
	{
		column_count = sqlite3_column_count (statement);
		row = 1;
		tries = 1;
		// The next line is the fist try to evaluate the expression:
		result_code = sqlite3_step (statement);
		while (result_code == SQLITE_ROW || (result_code == SQLITE_BUSY && tries_max <= 0) || (result_code == SQLITE_BUSY && tries < tries_max))
		{
			for (column = 0; column < column_count; ++ column)
			{
				result [row] [column + 1] = sqlite3_column_value (statement, column);
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
		}
	}
	
	sqlite3_finalize (statement);
	
	return true;
}
