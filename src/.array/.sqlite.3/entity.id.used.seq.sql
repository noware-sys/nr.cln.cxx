/*
begin transaction;

drop view if exists
	"entity.group.used.seq"
;
*/

create view if not exists
	"entity.id.used.seq"
as
	select
		*
	from
	(
		select
			"id"
		from
			"entity"
		where
			typeof ("id") = 'integer'
		
		union all
		
		select
			"value"
		from
			"entity"
		where
			"value.type" = 1
		and
			typeof ("value") = 'integer'
	)

/*
;

commit transaction;
*/
