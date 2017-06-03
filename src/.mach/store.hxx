#pragma once

// data store
// storage space
// remembers memories

class storage : /*virtual*/ public device//, public misc::iterator <noware::var>//, public array
{
	public:
		#include ".storage/.hxx"
		
		storage (void);
		~storage (void);
		
		// Getters.
		//const bool empty (void) const;
		//const bool full (void) const;
		
		// magnitude size
		//const noware::nr::natural magnitude (void) const;
		const noware::nr size (void) const;
		const noware::nr size (const noware::var &/* group*/) const;
		//const unsigned int magnitude (void) const;
		
		// existence presence
		// exist present
		const bool exist (const noware::var &/* group*/, const noware::var &/* key*/) const;
		const bool exist (const noware::var &/* key*/) const;
		const bool exist_group (const noware::var &/* group*/) const;
		
		// obtain attain get
		const noware::var/* value*/ get (const noware::var &/* group*/, const noware::var &/* key*/) const;
		const noware::var/* value*/ get (const noware::var &/* key*/) const;
		
		
		// Modifiers.
		
		// reinitialize reset clear flush clean
		const bool clear (void);
		
		// delete remove unset
		const bool remove (const noware::var &/* group*/, const noware::var &/* key*/);
		const bool remove (const noware::var &/* key*/);
		
		// assign associate map set
		const bool/* success*/ set (const noware::var &/* group*/, const noware::var &/* key*/, const noware::var &/* content/value*/);
		const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* content/value*/);
		
		// Transmit a message to one node.
		//const noware::var unicast (const noware::tree <> &/* message*/, const std::string &/* peer*/);
		
		// Transmit a message to multiple nodes.
		// Main usage: To request other nodes to do an action.
		//const noware::var multicast (noware::tree <> /* message*/, const std::string &/* group*/ = group_default);
		
		//using device::evaluate;
		//static const noware::var group_zmq_default;
		static const noware::var group_default;
	protected:
		// content value data container
		//noware::list <> data;
		//noware::list <noware::list <>> data;
		noware::array <noware::array <>> data;
	//public:
		// Manager of received messages.
		//void receive (const zyre_event_t */* zyre_event*/);
	public:
	//protected:
		const bool/* success*/ respond (const noware::tree <> &/* message*/, const zyre_event_t */* (zyre) event*/);
		const bool/* success*/ search (noware::var &/* result*/, const noware::tree <> &/* message*/);// const
		const bool/* success*/ search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
		const noware::var/* result*/ aggregate (const noware::var &/* result*/, noware::nr::natural &/* responses_count*/, const noware::var &/* response*/, const noware::tree <> &/* expression*/);
		
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
