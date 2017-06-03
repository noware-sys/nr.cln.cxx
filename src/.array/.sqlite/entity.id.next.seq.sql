/*
begin transaction;

drop view if exists
	"entity.group.next.seq"
;
*/

create view if not exists
	"entity.id.next.seq"
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
		"entity.id.used.seq"

/*
;

commit transaction;
*/
