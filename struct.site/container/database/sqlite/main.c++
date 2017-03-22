//#include <Poco/any.h>
#include <iostream>
#include <noware/containers/databases/sqlite.h++>

//void display_array (const noware::array <unsigned short int, unsigned short int> &);

void display_array (const LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> & arr)
{
	std::cout << "array =>";
	std::cout << std::endl;
	std::cout << '[';
	
	for (const LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V>::package & row : arr)
	{
		std::cout << std::endl;
		std::cout << '\t' << '[' << row.k << "] =>";
		std::cout << std::endl;
		std::cout << '\t' << '[';
		std::cout << std::endl;
		
		for (const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>::package & column : row.v)
		{
			std::cout << "\t\t" << '[' << column.k << ']' << " => " << '[' << column.v << ']' << std::endl;
		}
		
		std::cout << '\t' << ']';
		std::cout << std::endl;
	}
	
	std::cout << ']';
	std::cout << std::endl;
}

signed int main (unsigned int argc, char * argv [])
{
	//using boost::any_cast;
	using namespace std;
	using namespace noware;
	
	for (unsigned int i = 0; i < argc; ++ i)
		cout << argv [i] << ' ';
	cout << endl;
	
	cout << "Argument count: " << argc << endl;
	cout << endl;
	
	databases::sqlite db ("/srv/public/adminer/test-1.db");
	
	LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> result;
	
	LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> arg_select, arg_insert, arg_delete, arg_update;
	
	arg_select [1] = "Test 1.3: Name";
	
	arg_insert [1] = "Test 1.3: Name";
	arg_insert [2] = 0;
	arg_insert [3] = "First";
	arg_insert [4] = 0;
	arg_insert [5] = "FirstName";
	
	arg_insert [6] = "Test 1.3: Name";
	arg_insert [7] = 0;
	arg_insert [8] = "Last";
	arg_insert [9] = 0;
	arg_insert [10] = "LastName";
	
	arg_delete [1] = "Test 1.3: Name";
	
	//arg_update [1] = "Test 1";
	
	//cout << db.query (result, "SELECT \"Group\", \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arg_select) << endl;
	
	//display_array (result);
	
	//cout << db.query ("BEGIN") << endl;
	
	cout << "Success (DELETE): " << db.query ("DELETE FROM \"Entities\" WHERE \"Group\" = ?", arg_delete) << endl;
	cout << "Effect: " << db.effect () << endl;
	
	cout << "Success (INSERT): " << db.query ("INSERT OR IGNORE INTO \"Entities\" (\"Group\", \"Name: Reference\", \"Name\", \"Content: Reference\", \"Content\") VALUES (?, ?, ?, ?, ?), (?, ?, ?, ?, ?)", arg_insert) << endl;
	cout << "Effect: " << db.effect () << endl;
//	
	//cout << db.query ("DELETE FROM \"Entities\" WHERE \"Group\", = ?", arg_delete) << endl;
	
	//cout << db.query ("COMMIT") << endl;
	
	
	//cout << "Success (SELECT): " << db.query (result, "SELECT \"Group\", \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arg_select) << endl;
	//cout << "Effect: " << db.effect () << endl;
//	
//	display_array (result);
//	
//	result.clear ();
//	
//	arg_select [1] = 10;
//	
//	cout << db.query (result, "SELECT \"Group\", \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arg_select) << endl;
//	cout << result.size () << endl;
//	cout << db.effect () << endl;
//	
//	display_array (result);
}

