#pragma once

#include "sqlite.hdr.cxx"

#include "../../db/sqlite.cxx"

const noware::var noware::container::list::sqlite::group_default = "";
const std::string noware::container::list::sqlite::query_sql_initial_table = //"";
//const std::string noware::machine::storage::sqlite::sql1 = //"";
	"\
	create table if not exists \"entity\"\
	(\
		\"group\" 			none null default null,\
		\
		\"key.type\" 		none null default null,\
		\"key\"					none null default null,\
		\
		\"value.type\"	none null default null,\
		\"value\"				none null default null\
	)\
	"
;
const std::string noware::container::list::sqlite::query_sql_initial_index = //"";
//const std::string noware::machine::storage::sqlite::sql1 = //"";
	"\
	create unique index if not exists \"entity.id\" on \"entity\" (\"group\", \"key\")\
	"
;

noware::container::list::sqlite::sqlite (void)
{
}

noware::container::list::sqlite::~sqlite (void)
{
	finalize ();
}

const bool noware::container::list::sqlite::finalize (void)
{
	if (!data.disconnect ())
		return false;
	
	return true;
}

const bool noware::container::list::sqlite::initialized (void) const
{
	//return data.connected ();
	if (!data.connected ())
		return false;
	
	return true;
}

const bool noware::container::list::sqlite::initialize (const std::string & database)
{
	std::cout << "noware::container::list::sqlite::initialize()::called" << std::endl;
	
	
	if (!data.connect (database))
		return false;
	
	std::cout << "noware::container::list::sqlite::initialize()::connected" << std::endl;
	
	
	if (!data.query ("begin transaction"))
		return false;
	
	std::cout << "noware::container::list::sqlite::initialize()::transaction::begun" << std::endl;
	
	
	if (!data.query (noware::container::list::sqlite::query_sql_initial_table))
		return false;
	
	std::cout << "noware::container::list::sqlite::initialize()::table::queried" << std::endl;
	
	
	if (!data.query (noware::container::list::sqlite::query_sql_initial_index))
		return false;
	
	std::cout << "noware::container::list::sqlite::initialize()::index::queried" << std::endl;
	
	
	if (!data.query ("commit transaction"))
		return false;
	
	std::cout << "noware::container::list::sqlite::initialize()::transaction::committed" << std::endl;
	
	return true;
}

const noware::number noware::container::list::sqlite::magnitude (void) const
{
	noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	
	if (!data.query (result, "select count (*) from \"entity\""))
		return 0;
	
	return result  [1] /* row */  [1] /* column */;
}

const bool noware::container::list::sqlite::exist (const noware::var & group, const noware::var & key) const
{
	noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	noware::list <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	if (!data.query (result, "select count (*) from \"entity\" where \"group\" = ?1 and \"key\" = ?2", arguments))
	{
		std::cout << "noware::container::list::sqlite::exist()::date.query()==[" << 0 << ']' << std::endl;
		
		return false;
	}
	
	std::cout << "noware::container::list::sqlite::exist()::date.query()==[" << 1 << ']' << std::endl;
	
	//std::cout << "noware::container::list::sqlite::exist()::result[1]==[" << result [1] << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::exist()::result[1][1]==[" << result [1][1] << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::exist()::(result[1][1]>0)==[" << (result [1][1]>0) << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::exist()::(((bool) (result[1][1])))==[" << (((bool) (result [1][1]))) << ']' << std::endl;
	//std::cout << "noware::container::list::sqlite::exist()::(((noware::number::integer) (result[1][1]))>0)==[" << (((noware::number::integer) (result [1][1]))>0) << ']' << std::endl;
	
	return (((bool) (result  [1] /* row */  [1] /* column */)));
}

const bool noware::container::list::sqlite::exist (const noware::var & key) const
{
	return exist (noware::container::list::sqlite::group_default, key);
}

const bool noware::container::list::sqlite::full (void) const
{
	return false;
}

const bool noware::container::list::sqlite::empty (void) const
{
	return magnitude () <= 0;
}

const noware::var noware::container::list::sqlite::get (const noware::var & group, const noware::var & key)
{
	noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	noware::list <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	if (!data.query (result, "select value from \"entity\" where \"group\" = ?1 and key = ?2", arguments))
		return "";
	
	return result  [1] /* row */  [1] /* column */;
}

const noware::var noware::container::list::sqlite::get (const noware::var & key)
{
	return get (noware::container::list::sqlite::group_default, key);
}

const bool noware::container::list::sqlite::set (const noware::var & group, const noware::var & key, const noware::var & value)
{
	std::cout << "noware::container::list::sqlite::set()::called" << std::endl;
	
	//noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	noware::list <noware::var, int> arguments;
	
	std::cout << "noware::container::list::sqlite::set()::group==[" << group << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::set()::key==[" << key << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::set()::value==[" << value << ']' << std::endl;
	
	arguments [1] = group;
	arguments [2] = key;
	arguments [3] = value;
	
	std::cout << "noware::container::list::sqlite::set()::arguments[1]==[" << arguments [1] << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::set()::arguments[2]==[" << arguments [2] << ']' << std::endl;
	std::cout << "noware::container::list::sqlite::set()::arguments[3]==[" << arguments [3] << ']' << std::endl;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("insert or replace into \"entity\" (\"group\", \"key\", \"value\") values (?1, ?2, ?3)", arguments))
	{
		std::cout << "noware::container::list::sqlite::set()::failure" << std::endl;
		
		return false;
	}
	
	std::cout << "noware::container::list::sqlite::set()::success" << std::endl;
	
	return true;
}

const bool noware::container::list::sqlite::set (const noware::var & key, const noware::var & value)
{
	return noware::container::list::sqlite::set (noware::container::list::sqlite::group_default, key, value);
}

const bool noware::container::list::sqlite::reset (void)
{
	//noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	//noware::list <noware::var, noware::var> arguments;
	
	//arguments [1] = value;
	//arguments [2] = group;
	//arguments [3] = key;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("delete from \"entity\""))
		return false;
	
	return true;
}

const bool noware::container::list::sqlite::remove (const noware::var & group, const noware::var & key)
{
	//noware::list <noware::list <noware::var, noware::var>, noware::var> result;
	noware::list <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("delete from \"entity\" where \"group\" = ?1 and \"key\" = ?2", arguments))
		return false;
	
	return true;
}

const bool noware::container::list::sqlite::remove (const noware::var & key)
{
	return remove (noware::container::list::sqlite::group_default, key);
}
