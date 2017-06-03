/*
begin transaction;

drop view if exists
	"entity.key.avail.seq"
;
*/

create view if not exists
	"entity.key.avail.seq"
as
	select distinct
		"group",
		(
			select distinct
				"t1"."id" + 1 as "id"
			from
			(
				select
					0 as "id"
				
				union all
				
				select distinct
					coalesce ("t4"."key", 0) as "id"
				from
					"entity.key.usage.expl.seq" as "t4"
				where
					"t4"."group" = "outer"."group"
				order by
					"id" asc
			)
			as "t1"
			
			left outer join
			
			(
				select
					0 as "id"
			
				union all
			
				select distinct
					coalesce ("t4"."key", 0) as "id"
				from
					"entity.key.usage.expl.seq" as "t4"
				where
					"t4"."group" = "outer"."group"
				order by
					"id" asc
			)
			as "t2"
			
			on
				"t1"."id" = "t2"."id" - 1
			
			where
				"t2"."id" is null
				and
				"t1"."id" + 1 >= 0
			
			order by
				"t1"."id" asc
			
			limit 1
		)
		as "key"
	from
		"entity.key.usage.expl.seq" as "outer"

/*
;

commit transaction;
*/
