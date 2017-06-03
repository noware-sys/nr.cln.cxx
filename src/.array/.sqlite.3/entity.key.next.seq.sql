/*
begin transaction;

drop view if exists
	"entity.key.next.seq"
;
*/

create view if not exists
	"entity.key.next.seq"
as
	select
		"entity.id.used.seq"."id" as "id",
		coalesce
		(
			max ("key") + 1,
			-- default,
			1 -- backup
		)
		as "key"
	from
		"entity.id.used.seq"
		
		left outer join
		
		"entity.key.used.seq"
		
		on
			"entity.id.used.seq"."id" = "entity.key.used.seq"."id"
	group by
		"id"

/*
;

commit transaction;
*/
