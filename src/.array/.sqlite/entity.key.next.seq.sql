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
		"entity.group.usage.seq"."id" as "group",
		coalesce
		(
			max ("key") + 1,
			-- default,
			1 -- backup
		)
		as "key"
	from
		"entity.group.usage.seq"
		
		left outer join
		
		"entity.key.usage.seq"
		
		on
			"entity.group.usage.seq"."id" = "entity.key.usage.seq"."group"
	group by
		"group"

/*
;

commit transaction;
*/
