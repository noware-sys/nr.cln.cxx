#pragma once

#include "intel.hxx"

#include "var.cxx"
#include "db/sqlite.cxx"
//#include "zmq/zyre.cxx"
#include "net/node.cxx"

/*
const std::string noware::computer::query_sql_initial = //"";
//const std::string noware::computer::sql1 = //"";
			"\
			begin transaction;\
			\
			-- drop table if exists entity;\
			create table if not exists entity\
			(\
				 \"group\" 						none null default null,	-- group id\
				 \
				\"key.type\" 		none null default null,\
				 key 						none null default null,	-- name key\
				 \
				\"value.type\"		none null default null,\
				 value 					none null default null	-- content value\
			);\
			\
			-- (compound key) id[entification] uni[queness] element/entry/row /entity\
			-- drop index if exists \"entity.id\";\
			create unique index if not exists \"entity.id\" on entity (\"group\", name);\
			\
			commit transaction;\
			"
;
*/

noware::intel::intel (void)
{
	//sci.connect ("");
/*
	//std::cout << "memory.query: " << 
	if (knowledge.connect ("knowledge.db"))
	{
		knowledge.query (query_sql_initial);
		//memory.query (sql1);
		/*
		(
			"\
				begin transaction;\
			\
			-- drop table if exists entity;\
			create table if not exists entity\
			(\
				 id 						none null default null,	-- group id\
				 \
				\"key: type\" 		none null default null,\
				 key 						none null default null,	-- name key\
				 \
				\"value: type\"		none null default null,\
				 value 					none null default null	-- content value\
			);\
			\
			-- drop index if exists \"entity: id\";\
			create unique index if not exists \"entity: id\" on entity (id, key);\
			\
			commit transaction;\
			"
		);
		*/
	//}
	
	// << std::endl;
	//*/
}

noware::intel::~intel (void)
{
}

const noware::var noware::intel::val (const noware::var & xpr)
{
	return "";
}

/*
const bool good (/*action?* /)
{
	return true;
}
*/
