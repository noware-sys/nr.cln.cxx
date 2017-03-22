//#include "member.h++"

const bool noware::net::node::path::default_journal_limit_maximum = true;
const unsigned short int/*LIB::math::numbers::natural*/ noware::net::node::path::default_journal_maximum = 20;

noware::net::node::path::path (void)
{
	journal_limit_maximum = default_journal_limit_maximum;
	journal_maximum = default_journal_maximum;
	
	if (db.connect (":memory:"))
	//if (db.connect ("/srv/public/adminer/test-1.db"))
	{
		/*
			PRAGMA foreign_keys = true;
			
			CREATE TABLE IF NOT EXISTS `Latencies`
			(
				`Endpoint` none NOT NULL
				,
				`Value` none NULL
				,
				`Time` none NOT NULL
			)
			;
			
			CREATE VIEW IF NOT EXISTS "Paths" AS
				SELECT
					`Endpoint`,
					AVG (`Value`)
						AS 'Value'
				FROM
					`Latencies`
					
					GROUP BY
						`Endpoint`
			;
		*/
		db.query ("PRAGMA foreign_keys = true");
		
		db.query ("CREATE TABLE IF NOT EXISTS `Latencies`\
			(\
				`Endpoint` none NOT NULL\
				,\
				`Value` none NOT NULL\
				,\
				`Time` none NOT NULL	-- Inserted\
			)");
		
		db.query ("CREATE VIEW IF NOT EXISTS `Paths` AS\
			SELECT\
				`Endpoint`,\
				AVG (`Value`)\
					AS 'Value',\
				MAX (`Time`) AS 'Update'	-- Last Updated\
			FROM\
				`Latencies`\
			GROUP BY\
				`Endpoint`");
	}
}
/*
noware::net::node::path::path (const noware::net::node::path & other)
{
	//operator = (other);
}
*/
noware::net::node::path::~path (void)
{
}

template <typename archive>
void noware::net::node::path::serialize (archive & arch, const unsigned int & version)
{
	//arch & db;
}
/*
template <typename archive>
void noware::net::node::path::save (archive & arch, const unsigned int & version) const
{}

template <typename archive>
void noware::net::node::path::load (archive & arch, const unsigned int & version)
{}
*/
const noware::net::node::path & noware::net::node::path::operator = (const noware::net::node::path & other)
{
	//return *this;
	return other;
}

const bool noware::net::node::path::operator == (const noware::net::node::path & other) const
{
	return this == &other || db == other.db;
}

const LIB::math::numbers::natural noware::net::node::path::size (const std::string & endpoint) const
{
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	LIB::container::NAME_A <LIB::container::any, LIB::container::any> arguments;
	
	arguments.append (LIB::container::any (endpoint));
	
	if (!db.query (result, "SELECT COUNT (*) FROM `Latencies` WHERE `Endpoint` = ?", arguments))
		return 0;
	
	return result [1 /* 1st Row */] [1 /* 1st Column */];
}

const bool noware::net::node::path::reduce (const std::string & endpoint)
{
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	LIB::container::NAME_A <LIB::container::any, LIB::container::any> arguments;
	
	arguments.append (LIB::container::any (endpoint));
	arguments.append (LIB::container::any (endpoint));
	
	return db.query (/*result, */"DELETE FROM `Latencies` WHERE `Endpoint` = ? AND `Time` = (SELECT MIN (`Time`) FROM `Latencies` WHERE `Endpoint` = ?)", arguments);
}

const bool noware::net::node::path::add (const std::string & endpoint, const LIB::math::numbers::natural & latency)
{
	if (journal_limit_maximum && size (endpoint) >= journal_maximum)
		reduce (endpoint);
	
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	LIB::container::NAME_A <LIB::container::any, LIB::container::any> arguments;
	
	arguments.append (LIB::container::any (endpoint));
	arguments.append (LIB::container::any (latency));
	
	return db.query (/*result, */"INSERT INTO `Latencies` (`Endpoint`, `Value`, `Time`) VALUES (?, ?, strftime ('%Y/%m/%d %H:%M:%S', 'now'))", arguments);
}

const std::string noware::net::node::path::average (void) const
{
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	//LIB::container::NAME_A <LIB::container::any, LIB::container::any> arguments;
	
	//arguments.append (endpoint);
	
	if (!db.query (result, "SELECT `Endpoint` FROM `Paths` WHERE `Value` = (SELECT MIN (`Value`) FROM `Paths` WHERE `Value` IS NOT NULL) LIMIT 1"/*, arguments*/))
		return "";
	
	return result [1/*First row.*/] [1/*First column.*/];
}

const std::string noware::net::node::path::minimum (void) const
{
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> result;
	//LIB::container::NAME_A <LIB::container::any, LIB::container::any> arguments;
	
	//arguments.append (endpoint);
	
	if (!db.query (result, "SELECT `Endpoint` FROM `Latencies` WHERE `Value` = (SELECT MIN (`Value`) FROM `Latencies` WHERE `Value` IS NOT NULL) LIMIT 1"/*, arguments*/))
		return "";
	
	return result [1/*First row.*/] [1/*First column.*/];
}

//const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural> noware::net::node::path::all (void) const
const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> noware::net::node::path::all (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural> all_paths;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> all_next_destinations;
	
	db.query (all_next_destinations, "SELECT DISTINCT `Endpoint` FROM `Latencies` WHERE `Value` IS NOT NULL"/*, arguments*/);
	
	return all_next_destinations;
}

