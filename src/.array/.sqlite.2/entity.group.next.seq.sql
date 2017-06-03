/*
begin transaction;

drop view if exists
	"entity.group.next.seq"
;
*/

create view if not exists
	"entity.group.next.seq"
as
	select
		coalesce
		(
			max ("id") + 1,
			-- default,
			1 -- backup
		)
		as "id"
	from
		"entity.group.usage.seq"

/*
;

commit transaction;
*/
