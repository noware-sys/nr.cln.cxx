class sqlite
{
	public:
		//sqlite (const std::string & = ":memory:");
		sqlite (void);
		sqlite (const std::string &);
		~sqlite (void);
	
		const bool connect (const std::string &);
		const bool disconnect (void);
		const bool connected (void) const;
	
		const bool query (LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> &/* result*/, const std::string &/* the query*/, const LIB::container::array <LIB::container::any, LIB::container::any> &/* arguemnts*/, const LIB::math::numbers::natural &/* tries*/ = default_tries);
		const bool query (LIB::container::array <LIB::container::array <LIB::container::any, LIB::container::any>, LIB::container::any> &/* result*/, const std::string &/* the query*/, const LIB::math::numbers::natural &/* tries*/ = default_tries);
		const bool query (const std::string &/* the query*/, const LIB::container::array <LIB::container::any, LIB::container::any> &/* arguemnts*/, const LIB::math::numbers::natural &/* tries*/ = default_tries);
		const bool query (const std::string &/* the query*/, const LIB::math::numbers::natural &/* tries*/ = default_tries);
	
		const LIB::math::numbers::natural effect (void) const;
	
		//static const unsigned short int default_tries = 3;
		static const LIB::math::numbers::natural default_tries;
		//math::numbers::natural tries;
	
		//const sqlite & operator = (const sqlite &);
		const bool operator == (const sqlite &) const;
	protected:
		#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
			const bool effect/*_set*/ (const int &/* = 0*/);
		#endif

		sqlite3 * db;
		//LIB::methematics::numbers::natural success;
	
		bool _connected;
};
