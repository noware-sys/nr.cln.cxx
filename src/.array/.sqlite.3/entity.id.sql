/*
begin transaction;

drop index if exists
	"entity.id"
;
*/

create unique index if not exists
	"entity.id"
on
	"entity"
	(
		"id",
		"key"
	)

/*
;

commit transaction;
*/
