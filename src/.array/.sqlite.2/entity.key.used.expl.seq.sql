-- Show the used keys, explicitly.

/*
begin transaction;

drop view if exists
	"entity.key.used.expl.seq"
;
*/

create view if not exists
	"entity.key.used.expl.seq"
as
	select
		"table_group"."group",
		"table_key"."key"
	from
		(
			select
				"id" as "group"
			from
				"entity.group.used.seq"
		)
		as "table_group"
		
		left outer join
		
		(
			select
				"group",
				"key"
			from
				"entity.key.used.seq"
		)
		as "table_key"
		
		on
			"table_group"."group" = "table_key"."group"

/*
;

commit transaction;
*/
