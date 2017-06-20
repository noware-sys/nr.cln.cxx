#pragma once

//#include "../var.hdr.cxx"

//namespace noware
//{
	// Place in another project (kernel/os)?
	//namespace machine
	//{
			class dev //: misc::instance
			{
				public:
					dev (void);
					virtual ~dev (void);
					
					//virtual const noware::var evaluate (const noware::var &/* expression*/);
					virtual const zmq::msg/* value*/ multival (const zmq::msg &/* expression*/, const std::string &/* (zyre) group*/ = grp_dft);
					
					//virtual const noware::var/* value*/ get (const noware::var &/* key*/) const;
					//virtual const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* value*/);
					
					// Transmit a message to one node.
					virtual const zmq::msg/* message: response*/ unicast (const zmq::msg &/* message: request*/, const std::string &/* peer (id)*/);
					
					// Transmit a message to multiple nodes (a group of nodes).
					// Main usage: request other nodes to perform an operation.
					virtual const zmq::msg/* message: response*/ multicast (const zmq::msg &/* message: request*/, noware::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group*/ = /*noware::machine::device::*/grp_dft, const std::string &/* filter*/ = "");
					
					static const std::string grp_dft;
				//protected:
					//static net::cluster nodes;
					net::node node;
					//zmq::zyre node;
				//protected:
				//private:
					// Manager of received messages.
					virtual void receive (const zyre_event_t */* zyre_event*/);
					
					// Receives responses from queries.
					//virtual const noware::var receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
					virtual const zmq::msg receive_local (noware::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group (to receive from (where the message was sent to))*/ = /*noware::machine::device::*/grp_dft, const std::string &/* ^filter*/ = "") const;
					
					// Transmits responses to the thread who queried.
					virtual const bool unicast_local (const zmq::msg &/* message*/) const;
					//virtual const bool unicast_local (const zmsg_t */* message*/) const;
					
					
					//
					// Only these functions
					// need to be implemented
					// by the inheriting class:
					//
					////virtual const noware::tree <>/* response*/ respond (const noware::tree <> &/* message*/);
					//virtual const bool/* success*/ respond (const /*zmq::msg &*/zmsg_t */* message*/, const zyre_event_t */* (zyre) event*/);
					virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/);
					virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
					virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
					virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
			};
	//}
//}
