-- Show the used keys, implicitly.

/*
begin transaction;

drop view if exists
	"entity.key.used.seq"
;
*/

create view if not exists
	"entity.key.used.seq"
as
	select
		"id",
		"key"
	from
		"entity"
	where
		-- "key.type" = 0
		-- and
		typeof ("key") = 'integer'

/*
;

commit transaction;
*/
