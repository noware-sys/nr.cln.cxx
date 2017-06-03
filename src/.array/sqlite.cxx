#pragma once

#include "sqlite.hxx"

#include "../db/sqlite.cxx"

template <typename value, typename key>
const noware::var noware::array <value, key>::sqlite::group_default = "";

template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity =
	#include ".sqlite/entity.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_id =
	#include ".sqlite/entity.id.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_group_used_seq =
	#include ".sqlite/entity.group.used.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_key_used_seq =
	#include ".sqlite/entity.key.used.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_key_used_expl_seq =
	#include ".sqlite/entity.key.used.expl.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_group_avail_seq =
	#include ".sqlite/entity.group.avail.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_key_avail_seq =
	#include ".sqlite/entity.key.avail.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_group_next_seq =
	#include ".sqlite/entity.group.next.seq.hxx"
;
template <typename value, typename key>
static const std::string noware::array <value, key>::sqlite::query_sql_initial_entity_key_next_seq =
	#include ".sqlite/entity.key.next.seq.hxx"
;

template <typename value, typename key>
noware::array <value, key>::sqlite::sqlite (void)
{
}

template <typename value, typename key>
noware::array <value, key>::sqlite::~sqlite (void)
{
	finalize ();
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::finalize (void)
{
	if (!data.disconnect ())
		return false;
	
	return true;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::initialized (void) const
{
	//return data.connected ();
	if (!data.connected ())
		return false;
	
	return true;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::initialize (const std::string & database)
{
	std::cout << "noware::array::sqlite::initialize()::called" << std::endl;
	
	if (!data.connect (database))
		return false;
	std::cout << "noware::array::sqlite::initialize()::connected" << std::endl;
	
	if (!data.query ("begin transaction"))
		return false;
	std::cout << "noware::array::sqlite::initialize()::transaction::begun" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_uid))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.uid::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_group_used_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.group.used.seq::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_key_used_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.key.used.seq::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_key_used_expl_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.key.used.expl.seq::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_group_avail_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.group.avail.seq::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_key_avail_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.key.avail.seq::queried" << std::endl;
	
	if (!data.query (noware::array <value, key>::sqlite::query_sql_initial_entity_group_next_seq))
		return false;
	std::cout << "noware::array::sqlite::initialize()::entity.group.next.seq::queried" << std::endl;
	
	if (!data.query ("commit transaction"))
		return false;
	
	std::cout << "noware::array::sqlite::initialize()::transaction::committed" << std::endl;
	
	return true;
}

template <typename value, typename key>
const noware::nr noware::array <value, key>::sqlite::size (void) const
{
	noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	
	if (!data.query (result, "select count (*) from \"entity\""))
		return 0;
	
	return result  [1] /* row */  [1] /* column */;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::exist (const noware::var & group, const noware::var & key) const
{
	noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	noware::array <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	if (!data.query (result, "select count (*) from \"entity\" where \"group\" = ?1 and \"key\" = ?2", arguments))
	{
		std::cout << "noware::array::sqlite::exist()::date.query()==[" << 0 << ']' << std::endl;
		
		return false;
	}
	
	std::cout << "noware::array::sqlite::exist()::date.query()==[" << 1 << ']' << std::endl;
	
	//std::cout << "noware::array::sqlite::exist()::result[1]==[" << result [1] << ']' << std::endl;
	std::cout << "noware::array::sqlite::exist()::result[1][1]==[" << result [1][1] << ']' << std::endl;
	std::cout << "noware::array::sqlite::exist()::(result[1][1]>0)==[" << (result [1][1]>0) << ']' << std::endl;
	std::cout << "noware::array::sqlite::exist()::(((bool) (result[1][1])))==[" << (((bool) (result [1][1]))) << ']' << std::endl;
	//std::cout << "noware::array::sqlite::exist()::(((noware::nr::integer) (result[1][1]))>0)==[" << (((noware::nr::integer) (result [1][1]))>0) << ']' << std::endl;
	
	return (((bool) (result  [1] /* row */  [1] /* column */)));
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::exist (const noware::var & key) const
{
	return exist (noware::array <value, key>::sqlite::group_default, key);
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::full (void) const
{
	return false;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::empty (void) const
{
	return size () <= 0;
}

template <typename value, typename key>
const noware::var noware::array <value, key>::sqlite::get (const noware::var & group, const noware::var & key)
{
	noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	noware::array <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	if (!data.query (result, "select value from \"entity\" where \"group\" = ?1 and key = ?2", arguments))
		return "";
	
	return result  [1] /* row */  [1] /* column */;
}

template <typename value, typename key>
const noware::var noware::array <value, key>::sqlite::get (const noware::var & key)
{
	return get (noware::array <value, key>::sqlite::group_default, key);
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::set (const noware::var & group, const noware::var & key, const noware::var & value)
{
	std::cout << "noware::array::sqlite::set()::called" << std::endl;
	
	//noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	noware::array <noware::var, int> arguments;
	
	std::cout << "noware::array::sqlite::set()::group==[" << group << ']' << std::endl;
	std::cout << "noware::array::sqlite::set()::key==[" << key << ']' << std::endl;
	std::cout << "noware::array::sqlite::set()::value==[" << value << ']' << std::endl;
	
	arguments [1] = group;
	arguments [2] = key;
	arguments [3] = value;
	
	std::cout << "noware::array::sqlite::set()::arguments[1]==[" << arguments [1] << ']' << std::endl;
	std::cout << "noware::array::sqlite::set()::arguments[2]==[" << arguments [2] << ']' << std::endl;
	std::cout << "noware::array::sqlite::set()::arguments[3]==[" << arguments [3] << ']' << std::endl;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("insert or replace into \"entity\" (\"group\", \"key\", \"value\") values (?1, ?2, ?3)", arguments))
	{
		std::cout << "noware::array::sqlite::set()::failure" << std::endl;
		
		return false;
	}
	
	std::cout << "noware::array::sqlite::set()::success" << std::endl;
	
	return true;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::set (const noware::var & key, const noware::var & value)
{
	return noware::array <value, key>::sqlite::set (noware::array <value, key>::sqlite::group_default, key, value);
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::clear (void)
{
	//noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	//noware::array <noware::var, noware::var> arguments;
	
	//arguments [1] = value;
	//arguments [2] = group;
	//arguments [3] = key;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("delete from \"entity\""))
		return false;
	
	return true;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::remove (const noware::var & group, const noware::var & key)
{
	//noware::array <noware::array <noware::var, noware::var>, noware::var> result;
	noware::array <noware::var, int> arguments;
	
	arguments [1] = group;
	arguments [2] = key;
	
	// "insert or replace" inserts if inexistent or updates if existent
	if (!data.query ("delete from \"entity\" where \"group\" = ?1 and \"key\" = ?2", arguments))
		return false;
	
	return true;
}

template <typename value, typename key>
const bool noware::array <value, key>::sqlite::remove (const noware::var & key)
{
	return remove (noware::array <value, key>::sqlite::group_default, key);
}
