class container
{
	public:
		container (void);
		~container (void);
		
		const bool initialize ();
	protected:
		noware::net::node node;
		
		noware::var group;
		key key;
		value value;
		
		const bool finalize (void);
};
