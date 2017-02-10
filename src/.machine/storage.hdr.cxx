//#pragma once

// storage space
// remembers memories

class storage : /*virtual*/ public device// : public array
{
	public:
		storage (void);
		~storage (void);
		
		//const bool exists (const noware::var &/* group*/, const noware::var &/* name*/) const;
		const bool exists (const noware::var &/* name*/) const;
		//const noware::var get (const noware::var &/* group*/, const noware::var &/* name*/) const;
		const noware::var get (const noware::var &/* name*/) const;
		//const bool set (const noware::var &/* group*/, const noware::var &/* name*/, const noware::var &/* content*/);
		const bool set (const noware::var &/* name*/, const noware::var &/* content*/);
		//const noware::number::natural magnitude (void) const;
		const noware::number magnitude (void) const;
		//const unsigned int magnitude (void) const;
		const bool clear (void);
		//const bool remove (const noware::var &/* group*/, const noware::var &/* name*/);
		const bool remove (const noware::var &/* name*/);
		const bool empty (void) const;
		
		// Transmit a message to one node.
		const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
		
		// Transmit a message to multiple nodes.
		// Main usage: To request other nodes to do an action.
		const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = "storage");
		
		//using device::evaluate;
	protected:
		noware::list <> data;
		static const noware::var group_default;
	//public:
		// Manager of received messages.
		void receive (const zyre_event_t */* zyre_event*/);
	protected:
		// Receives responses to queries.
		const std::string receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
		
		// Transmits responses to queries.
		const bool unicast_local (const noware::tree <> &/* message*/) const;
	protected:
		const bool search_exists (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_get (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_set (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_remove (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_magnitude (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_clear (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		const bool search_empty (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
};