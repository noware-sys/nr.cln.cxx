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
		"table.id"."id",
		"table.key"."key"
	from
		(
			select
				"id"
			from
				"entity.id.used.seq"
		)
		as "table.id"
		
		left outer join
		
		(
			select
				"id",
				"key"
			from
				"entity.key.used.seq"
		)
		as "table.key"
		
		on
			"table.id"."id" = "table.key"."id"

/*
;

commit transaction;
*/
