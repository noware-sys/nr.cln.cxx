/*
begin transaction;

drop table if exists
	"entity"
;
*/

create table if not exists "entity"
(
	"id" 					none null default null,
	
	"key.type" 		none null default null,
	"key"					none null default null,
	
	"value.type"	none null default null,
	"value"				none null default null
)

/*
;

commit transaction;
*/
