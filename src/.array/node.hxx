class node
{
	public:
		node (void);
		~node (void);
	//protected:
		//net::node node;
	
	public:
		//
		// SQLite functionality
		//
		const bool connect (const std::string &);
		const bool disconnect (void);
		// get the connected state
		const bool connected (void) const;
		
		const nr size (void) const;
		const bool exist (const key_t &) const;
		const bool is_full (void) const;
		const bool is_empty (void) const;
		const bool set (const key_t &, const value_t &);
		const bool get (const key_t &, value_t &) const;
		//const key & get_key (const key &) const;
		const bool clear (void);
		const bool remove (const key_t &);
		const bool rename (const key_t &/* old_k*/, const key_t &/* new_k*/);
		//const bool query (noware::array <noware::array <>> &/* result*/, const std::string &/* query*/, const noware::array <std::string, int> &/* arguments*/, const noware::nr &/* tries*/ = tries_default);
		//const bool query (noware::array <noware::array <>> &/* result*/, const std::string &/* query*/, const noware::nr &/* tries*/ = tries_default);
		//const bool query (const std::string &/* query*/, const noware::array <std::string, int> &/* arguments*/, const noware::nr &/* tries*/ = tries_default);
		//const bool query (const std::string &/* query*/, const noware::nr &/* tries*/ = tries_default);
		
		const nr effect (void) const;	// Affected rows
		
		////static const unsigned short int tries_default = 3;
		//static const noware::nr tries_dft;
		
	protected:
		friend array;
		
		//const bool search (const key_t *, value_t *);
		
		sqlite3 * db;
		//noware::methematics::nr::integer success;
		
		// set the connected state
		//const bool connected (const bool &/* new_value*/);
		bool _connected;
		//std::unordered_map <key, value> container;
		
		
		boost::thread * reception;	// For running "void receive (void)".
		
		// Receiver of incoming messages.
		void receive (void);
		// Manager of incoming messages.
		//void manage (const std::string &/* message*/, const std::string &/* node_id*/ = "");
		void manage (zmq::socket_t & sock);
	//protected:
		
		//
		// ZeroMQ functionality
		//
		
		zmq::context_t * ctx;
		zmq::socket_t * sock_rx_any;
		zmq::socket_t * sock_rx_all;
		zmq::socket_t * sock_tx;
		
		//static const std::string srv_id;
};
