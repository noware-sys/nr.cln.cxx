#pragma once

#include "reception.hdr.cxx"

void receive (const zyre_event_t * event)
{
  std::cout << "noware::machine::storage::receive(): invoked" << std::endl;
  
	std::string event_type = zyre_event_type (event);
	//noware::tree <> message_zyre;
	noware::tree <> message;
	
  std::cout << "noware::machine::storage::receive():event_type==[" << event_type <<']' << std::endl;
  
	/*
	if (zyre_event_type (event) == "ENTER")
	{
		////  If new peer, say hello to it and wait for it to answer us
		//zsys_info ("[%s] peer entered", zyre_event_peer_name (event));
		//zyre_whispers (zyre, zyre_event_peer_uuid (event), "Hello");
	}
	else if (zyre_event_type (event) == "EXIT")
	{
		//zsys_info ("[%s] peer exited", zyre_event_peer_name (event));
	}
	*/
	//else
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
		//zsys_info ("[%s] received ping (WHISPER)", zyre_event_peer_name (event));
		//zyre_shouts (zyre, "GLOBAL", "Hello");
		
		zmsg_t * message_zmq;
		//std::string message_part;
		//std::string message;
		//std::string group;	// Group name which the message was sent to.
		//noware::list <> peer;
		
    //  Initialize random number generator
    //srandom ((unsigned) time (NULL));
    //while (true)
    //{
    	// First, get the message from the zyre peer.
			message_zmq = zyre_recv (node.get_zyre ());
			
	    std::cout << "noware::machine::storage::receive(): Receiving Message..." << std::endl;
			if (message_zmq != nullptr)
			{
				// Read message.
		    std::cout << "noware::machine::storage::receive(): Received Message" << std::endl;
		    //std::cout << "noware::machine::storage::receive():239: Received Message " << '[' << static_cast <char *> (message_zmq.data ()) << ']' << std::endl;
				//message.deserialize ((char *) forwarded_message.data ());
				//do
				//{
				/*
					message_zyre ["event"] = zmsg_popstr (message_zmq);	// Type of the event (in this case, "WHISPER" or "SHOUT").
					message_zyre ["peer"] ["id"] = zmsg_popstr (zyre_message);	// Peer ID.
					message_zyre ["peer"] ["name"] = zmsg_popstr (zyre_message);	// Peer name.
				
					if (message_zyre ["event"] == "SHOUT")
						message_zyre ["group"] =  = zmsg_popstr (zyre_message);	// Group name.
				
					message_zyre ["content"] =  = zmsg_popstr (zyre_message);	// Message body.
				//}
				//while (zmq_msg_more (message_zmq) != 0);
				
		    //int zipcode, temperature, relhumidity;
				//
		    ////  Get values that will fool the boss
		    //zipcode     = within (100000);
		    //temperature = within (215) - 80;
		    //relhumidity = within (50) + 10;
				
				
				
				// Prepare for transmission.
				zmq::context_t context (1);
				zmq::socket_t transmitter (context, ZMQ_PUB);
				transmitter.bind ("tcp://127.0.0.1:5555");
				//transmitter.bind("ipc://weather.ipc");                // Not usable on Windows.
				
				zmq::message_t forwarded_message (message ["content"].length ());
		    //  Send message to all subscribers
		    snprintf
				(
					(char *) forwarded_message.data (), message ["content"].length (),
					"%s",
					message ["content"]
				)
		    ;
		    std::cout << "Forwarding Message " << '[' << static_cast <char *> (forwarded_message.data ()) << ']' << std::endl;
		    publisher.send (forwarded_message);
    //}
    //return 0;
    */
			}
	}
	/*
	else if (zyre_event_type (event) == "SHOUT")
	{
		/*
		zsys_info
		(
			"[%s](%s) received ping (SHOUT)"
			,
			zyre_event_peer_name (event)
			,
			zyre_event_group (event)
		)
		;
		*/
	//}
}
