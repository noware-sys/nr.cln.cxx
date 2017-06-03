u8R"___(
/*
begin transaction;

drop view if exists
	"entity.group.used.seq"
;
*/

create view if not exists
	"entity.group.used.seq"
as
	select distinct
		*
	from
	(
		select
			"group" as "id"
		from
			"entity"
		where
			typeof ("group") = 'integer'
		
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
)___"
