#pragma once

// data store
// storage space
// remembers memories

class store
	: /*virtual*/ public dev
	//, public misc::iterator <noware::var>
	, public contnr::array <std::string, std::string>
{
	public:
		//#include ".store/.hxx"
		
		store (void);
		~store (void);
		
		// Getters.
		const bool empty (void) const;
		const bool full (void) const;
		
		// magnitude size
		//const noware::nr::natural magnitude (void) const;
		const noware::nr size (void) const;
		const noware::nr size (const std::string &/* group*/) const;
		//const unsigned int magnitude (void) const;
		
		// existence presence
		// exist present
		//const bool exist (const noware::var &/* group*/, const noware::var &/* key*/) const;
		const bool exist (const std::string &/* key*/) const;
		const bool exist (const std::string &/* group*/, const std::string &/* key*/) const;
		//const bool exist_group (const noware::var &/* group*/) const;
		
		// obtain attain get
		const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
		const std::string/* value*/ get (const std::string &/* key*/) const;
		
		
		// Modifiers.
		
		// reinitialize reset clear flush clean
		const bool clear (void);
		const bool clear (const std::string &/* group*/);
		
		// delete remove unset
		const bool remove (const std::string &/* group*/, const std::string &/* key*/);
		const bool remove (const std::string &/* key*/);
		
		// assign associate map set
		const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
		const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
		
		// Transmit a message to one node.
		//const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
		
		// Transmit a message to multiple nodes.
		// Main usage: To request other nodes to do an action.
		//const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = group_default);
		
		//using device::evaluate;
		//static const noware::var group_zmq_default;
		static const std::string grp_dft;
	protected:
		// content value data container
		//noware::list <> data;
		//noware::list <noware::list <>> data;
		//noware::array <noware::array <>> data;
		std::map <std::string, std::map <std::string, std::string>> data;
	//public:
		// Manager of received messages.
		//void receive (const zyre_event_t */* zyre_event*/);
	//public:
	protected:
		virtual const bool/* success*/ respond (const zmq::msg &/* message*/, const zyre_event_t */* (zyre) event*/);
		virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
		
		/*
			// Iteration-related:
			//virtual const iterator <value> begin (void) const;
			//virtual const iterator <value> end (void) const;
			//
			virtual const iterator <value> operator ++ (void);
			virtual const iterator <value> operator -- (void);
			
			virtual const bool operator == (const iterator <value> &) const;
			virtual const value operator * (void) const;
		*/
		
	//protected:
		// Receives responses to queries.
		//const std::string receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
		
		// Transmits responses to queries.
		//const bool unicast_local (const noware::tree <> &/* message*/) const;
	//protected:
		//const bool search_exists (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_get (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_set (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_remove (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_magnitude (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_clear (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
		//const bool search_empty (const noware::tree <> &/* message*/, noware::var &/* result*/);// const;
};

//#include "storage.cxx"
