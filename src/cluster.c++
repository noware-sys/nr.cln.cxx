///#include <iostream>
//#include <fstream>
//#include <string>

#include "cluster.h++"

LIB::cluster::cluster::communication::~communication (void)
{
	lock.unlock ();
}

LIB::cluster::cluster::cluster (void)
{
	
}

LIB::cluster::cluster::cluster (void)
{
	_active = false;
	members.cluster = this;
	//members.mpi = & mpi;
	
	//rsrc ["memory"] = new LIB::machine::resources::memory ();
	//rsrc ["processor"] = new LIB::machine::resources::processor ();
}

LIB::cluster::cluster::~cluster (void)
{
	/*
	for (auto & element : devices)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	
	for (auto & element : peers)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	*/
	
	//delete rsrc ["memory"];
	//delete rsrc ["processor"];
}

void LIB::cluster::cluster::input (LIB::entity <> remote_endpoint, const std::string & message_serial)
{
	LIB::communication::message message/*, message_outgoing*/;
	//LIB::entity <> outgoing_address;
	LIB::cluster::machine /*machine_source, */machine_destination;
	
	if (message.deserialize (message_serial))
	{
		//LIB::communication::message message;
		//std::string serial_message;
		
		// Validate.
		//if (message.content ["id"] != ""/* && message.content ["id"] != 0*/)
		if (message.content.exist ("id") && !message.content ["id"].empty ()/* && message.content ["id"] != 0*/)
		{
			if (message.content.exist ("endpoint") && message.content ["endpoint"].exist ("tcp"))
			{
				remote_endpoint ["port"] = message.content ["endpoint"] ["tcp"] ["port"];
			}
			
			//LIB::entity <> remote_endpoint = remote_endpoint_received;
			//remote_endpoint.unset ("port");
			std::cout << std::endl;
			std::cout << '(' << LIB << "::cluster::cluster::input ()) Remote Endpoint [\"port\"] == " << remote_endpoint ["port"] << std::endl;
			std::cout << std::endl;
			
			
			machine_destination = message.content ["meta"] ["machine_destination"];
			
			if (!machine_destination.path.empty ())
			{
				//machine_source = message.content ["meta"] ["machine_source"];
				
				//machine_source.path.push (remote_endpoint);
				//machine_destination.path.pop ();
				
				//message.content ["endpoint"] ["tcp"] ["port"]= remote_endpoint ["port"];
				//message.content ["meta"] ["machine_source"] = machine_source;
				//message.content ["meta"] ["machine_destination"] = machine_destination;
				
				transmit (message, machine_destination);
				
				return;
			}
			
			//message.content ["addresses"] = network::ip::addresses ();
			// Peer probing.
			if (message.content ["action"] == "presence")
			{
//				if (message.content ["function"] == "interrogation"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
//				{
//					/*
//					if (id == message.content ["id"])
//					{
//						message_outgoing.content ["addresses"] = network::ip::addresses ();
//						
//						send (message_outgoing, message_outgoing.content ["addresses"]);
//						//mpi -> send ();
//					}
//					else if (machines.exist (message.content ["id"]))
//					{
//						// Update the element.
//					}
//					*/
//					/*
//					if (! message.content.exist ("value") || message.content ["value"] == true)
//					{
//						// Keep.
//					
//					}
//					else 
//					*/
//					
//					LIB::communication::message message_response, message_demand;
//					//LIB::NAME_A <std::string, mathematics::numbers::natural> path;
//					LIB::NAME_A <machine, LIB::mathemathics::numbers::natural/* ID. */> nodes, nodes_demand;
//					
//					//path = network::ip::addresses (0, false);
//					
//					message_response.content ["id"] = machines.nodes.local;
//					//message_response.content ["addresses"] = network::ip::addresses (0, false);
//					message_response.content ["action"] = "presence";
//					message_response.content ["function"] = "declaration";
//					//message_outbound.content ["path"] = ;
//					//message_response.content ["value"] = true;
//					
//					if (message.content.exist ("recursive") && message.content ["recursive"])
//					{
//						message_demand = message_response;
//						//message_demand.unset ("value");
//						message_demand.content ["function"] = "interrogation";
//						//message_demand.content.unset ("value");
//						//message_demand.content ["recursive"] = true;
//						//message_demand.content ["machines"] = machines.nodes;
//						nodes = message.content ["machines"];
//						nodes_demand = machines.nodes;
//						
//						for (auto & mach : nodes)
//						{
//							nodes_demand.unset (mach.k);
//						}
//						
//						for (auto & mach : nodes_demand)
//						{
//							//mach.v.path.enqueue (message.content ["addresses"]);
//							mach.v.path.enqueue (remote_endpoint);
//						}
//						
//						//mpi.broadcast (message_outbound, message.content ["addresses"]);
//						//mpi.broadcast (message_outbound);
//						broadcast (message_demand, nodes_demand);
//					}
//					/*else
//					{
//						message_response.content ["function"] = "declaration";
//						message_response.content ["value"] = true;
//						//message_outbound.content ["id"];
//						
//						//mpi.broadcast (message_outbound, message.content ["addresses"]);
//					}
//					*/
//					
//					message_response.content ["value"] = true;
//					//message_response.content ["addresses"] = path;
//					
//					//mpi.broadcast (message_demand, message.content ["addresses"]);
//					//mpi.transmit (message_demand, message.content ["addresses"]);
//					//broadcast (message_response, message.content ["addresses"]);
//					//broadcast (message_response, remote_endpoint);
//					mpi.transmit (message_response, remote_endpoint);
//				}
//				else 
				if (message.content ["function"] == "declaration"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
				{
					//machines.nodes.exist (message.content ["id"])
					LIB::NAME_A <machine /* Member. */, LIB::mathemathics::numbers::natural/* ID. */> machs;
					LIB::mathematics::numbers::natural id;
					bool exist;
					
					machs = message.content ["machines"];
					exist = false;
					
					for (auto & mach : machines ().nodes)
					{
						if (machs.exist (mach.k))
						{
							id = mach.k;
							exist = true;
							
							break;
						}
					}
					
					if (exist)
					{
						conflicts [id].response [remote_endpoint ["address"]] = false;
						
						//conflicts.io [id] [remote_endpoint ["address"]];	// Create an io_service.
						conflicts [id].timer [remote_endpoint ["address"]] = new boost::asio::deadline_timer (conflicts [id].io [remote_endpoint ["address"]]);
						
						LIB::tools::randomizer randomizer;
						
						//delay = randomizer.generate (delay_max);
						
						conflicts [id].timer [remote_endpoint ["address"]] -> expires_from_now (boost::posix_time::milliseconds (randomizer.generate (delay_max)));
						conflicts [id].timer [remote_endpoint ["address"]] -> async_wait (boost::bind (& LIB::cluster::cluster::dummy, this));
						
						conflicts [id].io [remote_endpoint ["address"]] -> run ();
						
						if (!conflicts [id].response [remote_endpoint ["address"]])
						{
							LIB::communication::message message_response;
							
							message_response.content ["action"] = "resolution";
							message_response.content ["function"] = "response";
							message_response.content ["topic"] = "id";
							
							if (mpi.transmit (message_response, remote_endpoint))
							{
								mathematics::numbers::natural next_available_location;
								
								next_available_location = machines ().nodes.sequence_next ();
								
								if (id > next_available_location)
								{
									next_available_location = id;
								}
								
								// Try to rename.
								machines ().nodes.rename (* (machines ().nodes._local), next_available_location);
								
								/*
								message_demand.content ["id"] = machines ().nodes.local;
								//message_demand.content ["addresses"] = network::ip::addresses (0, false);
								message_demand.content ["action"] = "rename";
								message_demand.content ["function"] = "interrogation";
								message_demand.content ["proposed_id"] = machines ().nodes.next_id ();
								*/
								
								//mpi.transmit (message_demand, remote_endpoint);
							}
						}
						
						conflicts [id].response.unset (remote_endpoint ["address"]);
						conflicts [id].io.unset (remote_endpoint ["address"]);
						delete conflicts [id].timer [remote_endpoint ["address"]];
						conflicts [id].timer.unset (remote_endpoint ["address"]);
						
						if (conflicts [id].response.empty ()/* The rest (io, timer) should also be empty. */)
						{
							conflicts.unset (id);
							//// The rest should also be empty.
							//conflicts [id].io.unset (id);
							//conflicts [id].timer.unset (id);
						}
					}
					else
					{
						for (auto & mach : machs)
						{
							// Refer to the actual key, to prevent having another copy.
							machines ().nodes [mach.k].id = & machines ().nodes.get_key (mach.k);
							machines ().nodes [mach.k].cluster = machines ().cluster;
							machines ().nodes [mach.k].mpi = machines ().mpi;
							machines ().nodes [mach.k].path = mach.path;
							machines ().nodes [mach.k].path.push (remote_endpoint);
							//machines ().nodes [message.content ["id"]].timeout = message.content ["timeout"];
							
							machines ().nodes [mach.k].run ();
						}
						
						// Refer to the actual key, to prevent having another copy.
						//machines.nodes [message.content ["id"]].id = & machines.nodes.get_key (message.content ["id"]);
						//machines.nodes [message.content ["id"]].path = message.content ["path"];
						//machines.nodes [message.content ["id"]].timeout = message.content ["timeout"];
					}
					
					/*
					if (id == message.content ["id"])
					{
						message_outgoing.content ["addresses"] = network::ip::addresses ();
					 
						send (message_outgoing, message_outgoing.content ["addresses"]);
						//mpi -> send ();
					}
					else if (machines.exist (message.content ["id"]))
					{
						// Update the element.
					}
					*/
					/*
					if (! message.content.exist ("value") || message.content ["value"] == true)
					{
						// Keep.
					 
					}
					else 
					*/
					
					/*if (message.content ["id"] == 0)
					{
						// Add.
					}
					else */
					/*
					if (message.content.exist ("recursive") && message.content ["recursive"])
					{
						if (message.content.exists ("machines"))
						{
							// Add the list.
							
							for (machine & mach : (LIB::NAME_A <machine, mathematics::numbers::natural>) message.content ["machines"])
							//for (machine & mach : /*(LIB::NAME_A <machine, mathematics::numbers::natural>) * /message.content ["machines"])
							//for (auto & mach : message.content ["machines"])
							{
								//if (! machines.nodes.exist [* (mach.get_key ())])
								if (! machines.nodes.exist [mach.get_key ()])
								{
									//machines.nodes [* (mach.get_key ())] = mach ();
									machines.nodes [mach.get_key ()] = mach ();
								}
							}
						}
					}
					// Verify that it is the same machine.
					else if (machines.nodes.exist (message.content ["id"]) && machines.nodes [message.content ["id"]].addresses () == message.content ["addresses"])
					{
						if (message.content.exist ("value"))
						{
							if (message.content ["value"])
							{
								// Prevent removal.
								machines.nodes [message.content ["id"]].responded = true;
								machines.nodes [message.content ["id"]].io_service.stop ();
							}
							else
							{
								// Explicit removal.
								// Remove.
								
								rsrc.unset (message.content ["id"]);
								
								//if (machines -> exist (message.content ["id"]))
								//{
									//delete machines -> operator [] (message.content ["id"]);
								//}
								
								machines.nodes.unset (message.content ["id"]);
								
								// TODO: Pass on this message to indirectly connected peers, to notify them of this removal request too.
								//broadcast ();
							}
						}
					}
					else if (machines.nodes.exist (message.content ["id"]))
					{
						// There is a conflict: two machines have the same ID.
						
						// Try renaming the newly conflicting ID.
						
						message_outgoing.content ["id"] = machines.nodes.local;
						//message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
						message_outgoing.content ["action"] = "rename";
						message_outgoing.content ["function"] = "interrogation";
						// "message_outgoing.content ["id"]" is occupied.
						message_outgoing.content ["name"] ["old"] = message.content ["id"];
						message_outgoing.content ["name"] ["new"] = machines.nodes.next_id ();
						
						//// Reserve a location, in case another process will take it while the machine responds.
						//mathematics::numbers::natural n = machines.nodes.next_id ();
						//machines.nodes [n].t = machine::type::idle;
						//machines.nodes [n].id = & machines.nodes.get_key (n);
						//machines.nodes [n].mpi = machines.mpi;
						
						//mpi.transmit (message_outgoing, message.content ["addresses"]);
						mpi.transmit (message_outgoing, remote_endpoint);
					}
					else
					{
						// The machine does not yet exist in the local list.
						
						machines.nodes [message.content ["id"]].t = machine::type::reference;
						machines.nodes [message.content ["id"]].id = & machines.nodes.get_key (message.content ["id"]);
						//machines.nodes [message.content ["id"]].path.enqueue (message.content ["addresses"]);
						machines.nodes [message.content ["id"]].mpi = machines.mpi;
						
						//for (auto & peer : machines.nodes [message.content ["id"]].peers ())
						//{
						//	
						//}
					}
					*/
				}
			}
			else if (message.content ["action"] == "resolution")
			{
				if (message.content ["function"] == "response")
				{
					if (message.content ["topic"] == "id")
					{
						conflicts.response [id] [remote_endpoint ["address"]] = true;
					}
				}
			}
			else if (message.content ["action"] == "memory:presence")
			{
				if (message.content ["function"] == "demand")
				{
					LIB::cluster::machine machine;
					LIB::communication::message message_response;
					
					machine = message.content ["meta"] ["machine_source"];
					
					message_response.content ["action"] = "memory:presence";
					message_response.content ["function"] = "response";
					
					message_response.content ["value"] = static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]).exist (message.content ["entity"] ["name"], message.content ["entity"] ["group"]);
					
					transmit (message_response, machine);
				}
			}
			else if (message.content ["action"] == "memory:presence")
			{
				if (message.content ["function"] == "response")
				{
					LIB::resources::memory * memory = & static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]);
					
					if (message.content ["meta"].exist ("communication") && message.content ["meta"] ["communication"].exist ("id"))
					{
						if (communications.exist (message.content ["meta"] ["communication"] ["id"]))
						{
							communications [message.content ["meta"] ["communication"] ["id"]].data = message.content ["value"];
							communications [message.content ["meta"] ["communication"] ["id"]].lock.unlock ();
						}
					}
					else if (message.content.exist ("search") && message.content ["search"].exist ("id"))
					{
						memory -> searches [message.content ["search"] ["id"]].machines [message.content ["id"]].found = message.content ["value"];
						memory -> searches [message.content ["search"] ["id"]].machines [message.content ["id"]].responded = true;
						
						if (memory -> searches [message.content ["search"] ["id"]].responded ())
						{
							memory -> searches [message.content ["search"] ["id"]].lock.unlock ();
						}
					}
				}
			}
			else if (message.content ["action"] == "memory:variable")
			{
				if (message.content ["function"] == "demand")
				{
					if (message.content.exist ("machine_source"))
					{
						LIB::cluster::machine mach = message.content ["machine_source"];
						
						if (mach.active ())
						{
							LIB::machine::resources::memory * memory = & static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]);
							LIB::machine::resources::memory::keys k;
							
							if (message.content.exist ("value") && message.content.exist ["value"].exist ("name") && message.content ["value"].exist ("group"))
							{
								k.name = message.content ["value"] ["name"];
								k.group = message.content ["value"] ["group"];
								
								if (memory -> variables.exist (k))
								{
									LIB::communication::message message_response;
									
									message_response.content ["value"] = memory -> variables.get (k);;
									
									transmit (message_response, mach);
								}
							}
						}
					}
				}
			}
			//else if (message.content ["function"] == "interrogation")
			//{}
			/*
			else if (message.content ["action"] == "rename")
			{
				//if (message.content.exist ("function"))
				//{
					if (message.content ["function"] == "interrogation")
					{
						LIB::communication::message message_response;
						
						message_response.content ["id"] = machines.nodes.local;
						message_response.content ["action"] = "rename";
						message_response.content ["function"] = "declaration";
						
						if (message.content.exist ("proposed_id"))
						{
							if (! message.content ["proposed_id"].empty ())
							{
								//if (machines.nodes.exist (message.content ["proposed_id"]))
								//{
								//}
								//else
								//{
									message_response.content ["value"] = true;
									message_response.content ["new_id"] = message.content ["proposed_id"];
								//}
								
								mpi.transmit (message_response, remote_endpoint);
								//if (mpi.transmit (message_response, remote_endpoint))
								//{
									//machines.nodes.local = ;
								//}
							}
						}
			*/
						/*
						message_outgoing.content ["id"] = machines.nodes.local;
						//message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
						message_outgoing.content ["action"] = "rename";
						message_outgoing.content ["function"] = "declaration";
						message_outgoing.content ["name"] ["old"] = message.content ["id"];
						message_outgoing.content ["name"] ["new"] = machines.nodes.next_id ();
						
						if (machines.nodes.exist (message.content ["name"] ["new"]))
						{
							message_outgoing.content ["value"] = false;
						}
						else
						{
							message_outgoing.content ["value"] = machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]);
						}
						
						// Make sure to send to addresses instead of the ID, as there are conflicting IDs.
						mpi.transmit (message_outgoing, message.content ["addresses"]);
						*/
					}
					/*
					else if (message.content ["function"] == "declaration")
					{
						//machines.nodes [message.content ["name"] ["new"]].t = machines.nodes [message.content ["name"] ["old"]].t;
						
						if (message.content.exist ("value") && message.content ["value"])
						{
							machines.nodes [message.content ["name"] ["new"]].t = machine::type::reference;
							//machines.nodes [message.content ["name"] ["new"]].start ();
							//machines.nodes.unset (message.content ["name"] ["old"]);
						}
						else
						{
							// Rename the currently present one.
							
							if (machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]))
							{
							}
							//else
							//{
							//}
							
							message_outgoing.content ["id"] = machines.nodes.local;
							//message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
							message_outgoing.content ["addresses_conflicting"] = network::ip::addresses (0, false);
							message_outgoing.content ["action"] = "rename";
							message_outgoing.content ["function"] = "notification";
							message_outgoing.content ["name"] = message.content ["name"];
							
							// Send to IDs instead of addresses, to reach indirectly connected members.
							// transmit/broadcast (message_outgoing, "All, locally known, cluster members.");
							mpi.broadcast (message_outgoing);
						}
					}
					else if (message.content ["function"] == "notification")
					{
						
						
						//// Make space.
						//machines.nodes.unset (message.content ["name"] ["new"]);
						
						// Try to rename.
						if (machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]))
						{
							
							//machines.nodes [message.content ["name"] ["new"]].t = machine::type::reference;
						}
						//else
						//{
						//}
					}
					*/
				//}
			//}
		}
	}
}

//void LIB::cluster::cluster::receive (const std::string & message_serial)
//{
//	LIB::communication::message message, message_outgoing;
//	//LIB::entity <> outgoing_address;
//	
//	if (message.deserialize (message_serial))
//	{
//		//LIB::communication::message message;
//		//std::string serial_message;
//		
//		// Validate.
//		if (message.content ["id"] != ""/* && message.content ["id"] != 0*/)
//		{
//			//message.content ["addresses"] = network::ip::addresses ();
//			// Peer probing.
//			if (message.content ["action"] == "presence")
//			{
//				if (message.content ["function"] == "declaration"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
//				{
//					/*
//					if (id == message.content ["id"])
//					{
//						message_outgoing.content ["addresses"] = network::ip::addresses ();
//					 
//						send (message_outgoing, message_outgoing.content ["addresses"]);
//						//mpi -> send ();
//					}
//					else if (machines.exist (message.content ["id"]))
//					{
//						// Update the element.
//					}
//					*/
//					/*
//					if (! message.content.exist ("value") || message.content ["value"] == true)
//					{
//						// Keep.
//					 
//					}
//					else 
//					*/
//					
//					/*if (message.content ["id"] == 0)
//					{
//						// Add.
//					}
//					 else */if (message.content.exist ("recursive") && message.content ["recursive"])
//					{
//						if (message.content.exists ("machines"))
//						{
//							// Add the list.
//							
//							for (machine & mach : (LIB::NAME_A <machine, mathematics::numbers::natural>) message.content ["machines"])
//							//for (machine & mach : /*(LIB::NAME_A <machine, mathematics::numbers::natural>) */message.content ["machines"])
//							//for (auto & mach : message.content ["machines"])
//							{
//								//if (! machines.nodes.exist [* (mach.get_key ())])
//								if (! machines.nodes.exist [mach.get_key ()])
//								{
//									//machines.nodes [* (mach.get_key ())] = mach ();
//									machines.nodes [mach.get_key ()] = mach ();
//								}
//							}
//						}
//					}
//					else if (machines.nodes.exist (message.content ["id"]) && machines.nodes [message.content ["id"]].addresses () == message.content ["addresses"]/* Verify that it is the same machine. */)
//					{
//						if (message.content.exist ("value"))
//						{
//							if (message.content ["value"])
//							{
//								// Prevent removal.
//								machines.nodes [message.content ["id"]].responded = true;
//								machines.nodes [message.content ["id"]].io_service.stop ();
//							}
//							else
//							{
//								// Explicit removal.
//								// Remove.
//								
//								rsrc.unset (message.content ["id"]);
//								
//								//if (machines -> exist (message.content ["id"]))
//								//{
//									//delete machines -> operator [] (message.content ["id"]);
//								//}
//								
//								machines.nodes.unset (message.content ["id"]);
//								
//								// TODO: Pass on this message to indirectly connected peers, to notify them of this removal request too.
//								//broadcast ();
//							}
//						}
//					}
//					else if (machines.nodes.exist (message.content ["id"]))
//					{
//						// There is a conflict: two machines have the same ID.
//						
//						// Try renaming the newly conflicting ID.
//						
//						message_outgoing.content ["id"] = machines.nodes.local;
//						message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
//						message_outgoing.content ["action"] = "rename";
//						message_outgoing.content ["function"] = "interrogation";
//						message_outgoing.content ["name"]/* ["id"] is occupied. */ ["old"] = message.content ["id"];
//						message_outgoing.content ["name"] ["new"] = machines.nodes.next_id ();
//						
//						//// Reserve a location, in case another process will take it while the machine responds.
//						//mathematics::numbers::natural n = machines.nodes.next_id ();
//						//machines.nodes [n].t = machine::type::idle;
//						//machines.nodes [n].id = & machines.nodes.get_key (n);
//						//machines.nodes [n].mpi = machines.mpi;
//						
//						mpi.transmit (message_outgoing, message.content ["addresses"]);
//					}
//					else
//					{
//						// The machine does not yet exist in the local list.
//						
//						machines.nodes [message.content ["id"]].t = machine::type::reference;
//						machines.nodes [message.content ["id"]].id = & machines.nodes.get_key (message.content ["id"]);
//						//machines.nodes [message.content ["id"]].path.enqueue (message.content ["addresses"]);
//						machines.nodes [message.content ["id"]].mpi = machines.mpi;
//						
//						//for (auto & peer : machines.nodes [message.content ["id"]].peers ())
//						//{
//						//	
//						//}
//					}
//				}
//			}
//			//else if (message.content ["function"] == "interrogation")
//			//{}
//			else if (message.content ["action"] == "rename")
//			{
//				if (message.content.exist ("function"))
//				{
//					if (message.content ["function"] == "interrogation")
//					{
//						message_outgoing.content ["id"] = machines.nodes.local;
//						message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
//						message_outgoing.content ["action"] = "rename";
//						message_outgoing.content ["function"] = "declaration";
//						message_outgoing.content ["name"] ["old"] = message.content ["id"];
//						message_outgoing.content ["name"] ["new"] = machines.nodes.next_id ();
//						
//						if (machines.nodes.exist (message.content ["name"] ["new"]))
//						{
//							message_outgoing.content ["value"] = false;
//						}
//						else
//						{
//							message_outgoing.content ["value"] = machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]);
//						}
//						
//						// Make sure to send to addresses instead of the ID, as there are conflicting IDs.
//						mpi.transmit (message_outgoing, message.content ["addresses"]);
//					}
//					else if (message.content ["function"] == "declaration")
//					{
//						//machines.nodes [message.content ["name"] ["new"]].t = machines.nodes [message.content ["name"] ["old"]].t;
//						
//						if (message.content.exist ("value") && message.content ["value"])
//						{
//							machines.nodes [message.content ["name"] ["new"]].t = machine::type::reference;
//							//machines.nodes [message.content ["name"] ["new"]].start ();
//							//machines.nodes.unset (message.content ["name"] ["old"]);
//						}
//						else
//						{
//							// Rename the currently present one.
//							
//							if (machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]))
//							{
//							}
//							//else
//							//{
//							//}
//							
//							message_outgoing.content ["id"] = machines.nodes.local;
//							message_outgoing.content ["addresses"] = network::ip::addresses (0, false);
//							message_outgoing.content ["addresses_conflicting"] = network::ip::addresses (0, false);
//							message_outgoing.content ["action"] = "rename";
//							message_outgoing.content ["function"] = "notification";
//							message_outgoing.content ["name"] = message.content ["name"];
//							
//							// Send to IDs instead of addresses, to reach indirectly connected members.
//							// transmit/broadcast (message_outgoing, "All, locally known, cluster members.");
//							mpi.broadcast (message_outgoing);
//						}
//					}
//					else if (message.content ["function"] == "notification")
//					{
//						
//						
//						//// Make space.
//						//machines.nodes.unset (message.content ["name"] ["new"]);
//						
//						// Try to rename.
//						if (machines.nodes.rename (message.content ["name"] ["old"], message.content ["name"] ["new"]))
//						{
//							
//							//machines.nodes [message.content ["name"] ["new"]].t = machine::type::reference;
//						}
//						//else
//						//{
//						//}
//					}
//				}
//			}
//		}
//	}
//}
//
//void LIB::cluster::cluster::listen (const std::string & message_serial)
//{
//	LIB::communication::message message;
//	
//	if (message.deserialize (message_serial))
//	{
//		// Validate.
//		if (message.content ["id"] != ""/* && message.content ["id"] != 0*/)
//		{
//			// Peer probing.
//			if (message.content ["action"] == "presence")
//			{
//				if (message.content ["function"] == "interrogation"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
//				{
//					/*
//					if (id == message.content ["id"])
//					{
//						message_outgoing.content ["addresses"] = network::ip::addresses ();
//						
//						send (message_outgoing, message_outgoing.content ["addresses"]);
//						//mpi -> send ();
//					}
//					else if (machines.exist (message.content ["id"]))
//					{
//						// Update the element.
//					}
//					*/
//					/*
//					if (! message.content.exist ("value") || message.content ["value"] == true)
//					{
//						// Keep.
//					
//					}
//					else 
//					*/
//					
//					LIB::communication::message message_response, message_demand;
//					//LIB::NAME_A <std::string, mathematics::numbers::natural> path;
//					LIB::NAME_A <machine, LIB::mathemathics::numbers::natural/* ID. */> nodes, nodes_demand;
//					
//					//path = network::ip::addresses (0, false);
//					
//					message_response.content ["id"] = machines.nodes.local;
//					message_response.content ["addresses"] = network::ip::addresses (0, false);
//					message_response.content ["action"] = "presence";
//					message_response.content ["function"] = "declaration";
//					//message_outbound.content ["path"] = ;
//					message_response.content ["value"] = true;
//					
//					if (message.content.exist ("recursive") && message.content ["recursive"])
//					{
//						message_demand = message_response;
//						//message_demand.unset ("value");
//						message_demand.content ["function"] = "interrogation";
//						//message_demand.content ["recursive"] = true;
//						//message_demand.content ["machines"] = machines.nodes;
//						nodes = message.content ["machines"];
//						nodes_demand = machines.nodes;
//						
//						for (auto & mach : nodes)
//						{
//							nodes_demand.unset (mach.k);
//						}
//						
//						//mpi.broadcast (message_outbound, message.content ["addresses"]);
//						//mpi.broadcast (message_outbound);
//						broadcast (message_demand, nodes_demand);
//					}
//					/*else
//					{
//						message_response.content ["function"] = "declaration";
//						message_response.content ["value"] = true;
//						//message_outbound.content ["id"];
//						
//						//mpi.broadcast (message_outbound, message.content ["addresses"]);
//					}
//					*/
//					
//					//message_response.content ["addresses"] = path;
//					
//					//mpi.broadcast (message_demand, message.content ["addresses"]);
//					//mpi.transmit (message_demand, message.content ["addresses"]);
//					broadcast (message_demand, message.content ["addresses"]);
//				}
//			}
//		}
//	}
//}

const bool LIB::cluster::cluster::run (const bool & state)
{
	//LIB::communication::message message;
	
	LIB::cluster::machine * local_machine = (* _machines) [* (_machines.local)];
	
	if (state && !_active)
	{
		// Start.
		
		// Add the handlers.
		//mpi -> receive_async (boost::bind (boost::mem_fn (& LIB::cluster::cluster::receive), this, _1));
		mpi.receive_async (boost::bind (boost::mem_fn (& LIB::cluster::cluster::input), this, _1, _2));
		if (! machines ().run (state))
		{
			//mpi -> receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::receive), this, _1));
			mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::input), this, _1, _2));
			
			return false;
		}
		//mpi -> listen_async (boost::bind (boost::mem_fn (& LIB::cluster::cluster::listen), this, _1));
		mpi.listen_async (boost::bind (boost::mem_fn (& LIB::cluster::cluster::input), this, _1, _2));
		
		
		static_cast <LIB::machine::resources::memory *> (local_machine -> rsrc ["memory"]).run (true);
		static_cast <LIB::machine::resources::processor *> (local_machine -> rsrc ["processor"]).run (true);
		
		//LIB::communication::message message;
		//std::string serial_message;
		
		//message.content ["addresses"] = network::ip::addresses ();
		//message.content ["action"] = "presence";
		//message.content ["function"] = "interrogation";
		//message.content ["value"] = true;
		
		//mpi -> broadcast (message);
		/*
		id = next_id ();
		
		// Start polling after the ID is obtained.
		if (scanning == NULL)
		{
			scanning = new boost::thread (boost::bind (& LIB::cluster::machine::scan, this));
		}
		*/
		
		
		_active = state;
		
		return true;
	}
	else if (!state && active)
	{
		// Stop.
		
		if (! machines ().run (state))
		{
			return false;
		}
		
		// Remove the handlers.
		//mpi -> receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::receive), this, _1));
		//mpi -> listen_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::listen), this, _1));
		mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::input), this, _1, _2));
		mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::cluster::input), this, _1, _2));
		
		static_cast <LIB::machine::resources::memory *> (local_machine -> rsrc ["memory"]).run (false);
		static_cast <LIB::machine::resources::processor *> (local_machine -> rsrc ["processor"]).run (false);
		
		//if (timeout_timer_wait_thread != NULL)
		//{
		//	delete timeout_timer_wait_thread;
		//}
		
		//id = 0;
		
		//clear ();
		
		_active = state;
		
		return true;
	}
	else
	{
		// Nothing needs to be done.
		
		return true;
	}
	
	return false;
}

const bool & LIB::cluster::cluster::active (void) const
{
	return _active;
}

//const LIB::NAME_A <LIB::machine::resource> & LIB::cluster::cluster::resources (void) const
//{
//	//return rsrc;
//	
//	
//}

const LIB::NAME_A <LIB::machine::resource> & LIB::cluster::cluster::machines (void) const
{
	return _machines;
}

void LIB::cluster::cluster::dummy (void) const
{
	// Do not do anything.
}

const LIB::NTT <> LIB::cluster::cluster::communicate (LIB::NTT <> message, const machine &) const
{
	LIB::mathematics::numbers::natural id;
	communication lmn;	// Something needs to be enqueued.
	
	if (!communications.enqueue (lmn, id))
	{
		communications.unset (id);
		return "";
	}
	
	message ["meta"] ["communication"] ["id"] = id;
	
	communications [id].lock ();
	
	if (!transmit (message, machine))
	{
		communications.unset (id);
		return "";
	}
	
	communications [id].lock ();
	
	LIB::NTT <> data;
	
	data = communications [id].data;
	
	communications.unset (id);
	//communications [id].unlock ();
	
	return data;
}

const bool LIB::cluster::cluster::enqueue (const std::string & file_name)
{
	std::queue <LIB::machine::resources::processor::instructions> instructions;
	
	if (_interpreter.enqueue (file_name, instructions, error))
	{
		LIB::machine::resources::processor * processor = static_cast <LIB::machine::resources::processor *> (((* _machines) [* (_machines.local)]).rsrc ["processor"]);
		
		while (! instructions.empty ())
		{
			if (! processor -> enqueue (instructions.front ()))
				return false;
			
			instructions.pop ();
		}
		
		return true;
	}
	else
	{
		return false;
	}
}
