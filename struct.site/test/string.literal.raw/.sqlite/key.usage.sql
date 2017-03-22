begin transaction;

drop view if exists
	"entity.key.usage.seq"
;

create view if not exists
	"entity.key.usage.seq"
as
	select
		"group",
		"key"
	from
		"entity"
	where
		"key.type" = 0
		and
		typeof ("key") = 'integer'
;

commit transaction;
