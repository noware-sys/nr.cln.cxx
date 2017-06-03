u8R"___(
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
		"group",
		"key"
	)

/*
;

commit transaction;
*/
)___"
