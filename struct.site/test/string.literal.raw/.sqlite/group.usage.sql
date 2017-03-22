begin transaction;

drop view if exists
	"entity.group.usage.seq"
;

create view if not exists
	"entity.group.usage.seq"
as
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
		typeof ("value") = 'integer';

commit transaction;
