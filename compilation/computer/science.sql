begin transaction;

-- drop table if exists entity;
create table if not exists entity
(
	 id 						none null default null,	-- group id
	 
	"key: type" 		none null default null,
	 key 						none null default null,	-- name key
	 
	"value: type"		none null default null,
	 value 					none null default null	-- content value
);

-- drop index if exists "entity: id";
create unique index if not exists "entity: id" on entity (id, key);

commit transaction;

