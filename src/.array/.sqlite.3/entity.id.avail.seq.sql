/*
begin transaction;

drop view if exists
	"entity.group.avail.seq"
;
*/

create view if not exists
	"entity.id.avail.seq"
as
	select distinct
		"t1"."id" + 1 as "id"
	from
			(
				select
					1 as "id"
				
				union all
				
				select
					"id"
				from
					"entity.id.used.seq"
				
				order by
					1 asc
			)
			as "t1"
		left outer join
			(
				select
					1 as "id"
				
				union all
				
				select
					"id"
				from
					"entity.id.used.seq"
				
				order by
					1 asc
			)
			as "t2"
		on
			"t1"."id" = "t2"."id" - 1
	where
		"t2"."id" is null
	and
		"t1"."id" + 1 >= 1
	order by
		"t1"."id" asc
	limit 1

/*
;

commit transaction;
*/
