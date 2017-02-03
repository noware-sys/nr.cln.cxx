//#include ".cluster/index.c++"
#include "cluster.h++"

//static const unsigned short int LIB::net::cluster::default_udp_port;
//static const unsigned short int LIB::net::cluster::default_tcp_port;
const unsigned short int/*LIB::math::numbers::natural*/ LIB::net::cluster::default_udp_port = 6;
const unsigned short int/*LIB::math::numbers::natural*/ LIB::net::cluster::default_tcp_port = 7;
const /*unsigned short int*/LIB::math::numbers::natural LIB::net::cluster::default_timeout = 10;
//#include "member.c++"
/*
template <typename archive>
void LIB::net::cluster::serialize (archive & arch, const unsigned int & version)
{
	//arch & local;
	//arch & keepalive;
	//arch & _nodes;
}
*/
LIB::net::cluster::cluster (void)
{
	//running = true;
	//timeout = 10;
//	handler = LIB::container::content::null;
	//handler = nullptr;
	
	local = id_generate ();
	
	timeout = default_timeout;
	
	/*
	//mpi._connections [1].addrs.listen ["port"] = default_udp_port;
	mpi._connections [1].multicast.reliable ["port"] = default_tcp_port;
	mpi._connections [1].multicast.unreliable ["port"] = default_udp_port;
	
	mpi._connections [1].reception.reliable ["port"] = default_tcp_port;
	mpi._connections [1].reception.unreliable ["port"] = default_udp_port;
	mpi._connections [1].transmission.reliable ["port"] = default_tcp_port;
	mpi._connections [1].transmission.unreliable ["port"] = default_udp_port;
	
	//_nodes [local].addresses = LIB::net::ip::addresses ();
	*/
	
	// Set ports.
	mpi.connections () ["ip"] -> multicast.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> multicast.unreliable ["port"] = default_udp_port;
	
	mpi.connections () ["ip"] -> reception.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> reception.unreliable ["port"] = default_udp_port;
	
	mpi.connections () ["ip"] -> transmission.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> transmission.unreliable ["port"] = default_udp_port;
	
	
	mpi.receive_async (boost::bind (boost::mem_fn (&LIB::net::cluster::receive), this, _1, _2));
	//mpi.receive_async (boost::bind (& LIB::net::cluster::receive, this, _1, _2));
	//mpi.receive_async (boost::mem_fn (& LIB::net::cluster::receive), this, _1, _2);
	
	mpi.listen_async (boost::bind (boost::mem_fn (&LIB::net::cluster::receive), this, _1, _2));
	//mpi.listen_async (boost::bind (& LIB::net::cluster::receive, this, _1, _2));
	//mpi.listen_async (boost::mem_fn (& LIB::net::cluster::receive), this, _1, _2);
	
	//distribution = new boost::thread (boost::bind (& LIB::net::cluster::distribute, this));
//	distribution = new boost::thread (& LIB::net::cluster::distribute, this);
	distribution = new boost::thread (boost::bind (boost::mem_fn (&LIB::net::cluster::distribute), this));
}

LIB::net::cluster::~cluster (void)
{
	// running = false;
	//distribution -> interrupt ();
	//if (distribution -> joinable ())
	// 	distribution -> join ();
	delete distribution;
	
	//mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::net::cluster::receive), this, _1, _2));
	mpi.receive_async_stop ();
	//mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::net::cluster::receive), this, _1, _2));
	mpi.listen_async_stop ();
	
	
	// Tell all other machines that this machine is leaving the group.
	//LIB::communication::message _message;
	noware::container::object <> msg;
	
//	_message = LIB::net::_mpi::prepare (_message);
	
	msg ["meta"] ["source"] ["subject"] = "presence";
	msg ["meta"] ["source"] ["function"] = "declaration";
	msg ["meta"] ["source"] ["value"] = false;
	
	broadcast (msg);
}

/*
const LIB::math::numbers::natural LIB::net::cluster::size (void) const
{
	return _nodes.size ();
}

const bool LIB::net::cluster::empty (void) const
{
	return ! (size () > 0);
}
*/

const LIB::math::numbers::natural LIB::net::cluster::id_generate (void) const
{
	return LIB::tool::random ();
}

const noware::math:::numbers::natural LIB::net::cluster::size (void) const
{
	return _nodes.size ();
}

const noware::math:::numbers::natural LIB::net::cluster::local_node_id (void) const
{
	return local;
}

const noware::net::node LIB::net::cluster::local_node (void) const
{
	return nodes [local];
}

const LIB::container::NAME_A <LIB::net::node/*LIB::net::cluster::member*/, LIB::math::numbers::natural> & LIB::net::cluster::nodes (void) const
//const LIB::container::NAME_A <LIB::net::node/*LIB::net::cluster::member*/, noware::container::any> & LIB::net::cluster::nodes (void) const
{
	return _nodes;
}

void LIB::net::cluster::distribute (void)
{
	// LIB::communication::message _message;
	noware::container::object <> msg;
	//std::string _message_serial;
	
	////msg ["address"] = net::ip::addresses ();
	//msg ["id"] = local;
	
//	_message = LIB::net::_mpi::prepare (_message);
	
	msg ["meta"] ["source"] /*["action"]*/["subject"] = "presence";
	msg ["meta"] ["source"] ["function"] = "declaration";
	msg ["meta"] ["source"] ["value"] = true;
	//msg ["endpoint"] ["port"] ["tcp"] = static_cast <LIB::net::ip::mpi> (mpi -> connections ()).;
	//msg ["endpoint"] ["udp"] = mpi -> addrs.listen;
	//msg ["endpoint"] ["tcp"] = mpi -> addrs.receive;
	
	//msg ["id"] = * _local;
	//msg ["id:next"] = nodes.sequence_next ();
	//msg ["machines"] = nodes;
	
	//LIB::any * __id = & (msg ["id"]);
	
	// _message_serial = _message;
	
	//msg.clear ();
	
	//io.reset ();
	
	while (true)
	{
		//if (/*_local != nullptr && */(* __id) != (* _local))
		//{
			//(* __id) = (* _local);
			//_nodes [local].addresses = LIB::net::ip::addresses ();
			
	//		msg ["content"] ["id"]/* ["local"]*/ ["source"/*source origin*/] = local;
	//		msg ["content"] ["id"] ["last"/*previous intermediate last source*/] = local;
			//msg ["content"] ["id"] ["target"] = local;
			//msg ["content"] ["id"] ["next"] = _nodes.sequence_next ();
		//	msg ["content"] ["machines"] = _nodes;
			//msg ["content"] ["endpoint"] ["udp"] = mpi.addrs.listen;
			//msg ["content"] ["endpoint"] ["tcp"] = mpi.addrs.receive;
			
			msg ["meta"] ["source"]/* ["time"]*/ ["id"] = local;
			//msg ["meta"] ["source"]/* ["time"]*/ ["keepalive"] = LIB::container::any (_nodes [local].keepalive);
			//std::cout << _nodes [local].keepalive << std::endl;
			//std::cout << msg ["meta"] ["source"] ["keepalive"] << std::endl;
			msg ["meta"] ["source"]/* ["time"]*/ ["keepalive"] = _nodes [local].keepalive;
			
			
			//LIB::container::NAME_A <> nets = _nodes [local].networks = LIB::net::ip::networks ();
			_nodes [local].networks = LIB::net::ip::networks ();
			for (const LIB::container::NAME_A <std::string, LIB::math::numbers::natural>::container & network : _nodes [local].networks)
				msg ["meta"] ["source"] ["network"] [network.k] = LIB::container::any (network.v);
			
			//std::cout << msg ["meta"] ["source"] ["keepalive"] << std::endl;
			
			//msg ["meta"] ["source"] ["network"] = _nodes [local].networks = LIB::net::ip::networks ();
			// msg ["meta"] ["source"] ["network"] = LIB::container::any (nets.serialize ());
		//	msg ["meta"] ["source"] ["network"] = *(dynamic_cast <LIB::container::object <> *> (const_cast <LIB::container::NAME_A <std::string, LIB::math::numbers::natural> *> (& (_nodes [local].networks = LIB::net::ip::networks ()))));
			//msg ["meta"] ["source"] ["address"] = _nodes [local].addresses = LIB::net::ip::addresses ();
			
			// Addresses.
			//msg ["meta"] ["source"] ["address"] = (LIB::container::any) (_nodes [local].addresses = LIB::net::ip::addresses ()).serialize ();
			_nodes [local].addresses = LIB::net::ip::addresses ();
			
		//	msg ["meta"] ["source"] ["address"] = *(dynamic_cast <LIB::container::object <> *> (& (_nodes [local].addresses = LIB::net::ip::addresses ())));
			
			for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, noware::math::numbers::natural>, std::string>::container & address : _nodes [local].addresses)
			{
				for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, noware::math::numbers::natural>::container & version : address.v)
				{
					for (const LIB::container::NAME_A <std::string, std::string>::container & attribute : version.v)
					{
						//std::cout << "\t\t" << '[' << address.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << "\t" << '[' << attribute.v << ']' << std::endl;
						msg ["meta"] ["source"] ["address"] [address.k] [version.k] [attribute.k] = LIB::container::any (attribute.v);
					}
				}
			}
			
			//std::cout << msg ["meta"] ["source"] ["keepalive"] << std::endl;
			//_message_serial = _message;
		//}
		
		//std::cout << "Sending 0::  Subject: [" << msg ["meta"] ["source"] ["subject"] << ']'<< std::endl;
		//std::cout << "Sending 0:: Function: [" << msg ["meta"] ["source"] ["function"] << ']'<< std::endl;
		//std::cout << "Sending 0::    Value: [" << msg ["meta"] ["source"] ["value"] << ']'<< std::endl;
		
		//mpi.broadcast (_message, false);
		broadcast (msg);
		
		//std::cout << msg ["meta"] ["source"] ["keepalive"] << std::endl;
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::seconds (_nodes [local].keepalive));
	}
	
	//distribution = nullptr;
}

//void LIB::net::cluster::receive (LIB::container::object <> remote_endpoint, const LIB::communication::message & _message)
void LIB::net::cluster::receive (LIB::container::object <> remote_endpoint, const std::string & serial)
{
	// LIB::communication::message _message;
	noware::container::set <> msg;
	
	/*
	LIB::container::NAME_A <LIB::cluster::member, LIB::math::numbers::natural> __nodes;
	
	if (msg ["content"].exists ("machines") && __nodes.deserialize (msg ["content"] ["machines"]))
	{
		for (auto & _member : __nodes)
		{
			_nodes [_member.k] = _member.v;
			
			if (_nodes [_member.k].thread_timeout != nullptr)
			{
				// Cancel the current thread, so that it will not remove the member.
				delete _nodes [_member.k].thread_timeout;
			}
			
			_nodes [_member.k].thread_timeout = new boost::thread (boost::bind (& LIB::cluster::member::function_timeout, & (_nodes [_member.k]), _nodes, _member.k, _nodes [_member.k].keepalive + timeout));
		}
		
		
		//boost::this_thread::sleep (boost::posix_time::seconds (timeout));
	}
	*/
	
	/*
	// Self message.
	if (remote_endpoint.is_group () && remote_endpoint.exists ("address") && _nodes [local].addresses.exists_value (remote_endpoint ["address"]))
	{
		// Do not process.
		return;
	}
	*/
	
	std::cout << "SERIAL[" << serial << ']' << std::endl;
	if (msg.deserialize (serial))
	{
		std::cout << "Deserialization Succeeded" << std::endl;
		
		if (msg.exists ("meta"))
		{
			std::cout << "meta" << std::endl;
			
			if (msg ["meta"].exists ("source"))
			{
				std::cout << "[meta].origin" << std::endl;
				
				if (/*msg ["meta"].exists ("source") && */msg ["meta"] ["source"].exists ("id"))
				{
					std::cout << "[meta] [origin].id" << std::endl;
					
					std::cout << "    Local ID: [" << local << ']'<< std::endl;
					std::cout << " Received ID: [" << msg ["meta"] ["source"] ["id"] << ']'<< std::endl;
					std::cout << " Previous ID: [" << msg ["meta"] ["previous"] ["id"] << ']'<< std::endl;
					
					std::cout << "  Subject: [" << msg ["meta"] ["source"] ["subject"] << ']'<< std::endl;
					std::cout << " Function: [" << msg ["meta"] ["source"] ["function"] << ']'<< std::endl;
					std::cout << "    Value: [" << msg ["meta"] ["source"] ["value"] << ']'<< std::endl;
					
					//msg ["meta"] ["source"] ["id"] = local + 1000;
					std::cout << " Received ID (again): [" << msg ["meta"] ["source"] ["id"] << ']'<< std::endl;
					if (msg ["meta"] ["source"] ["id"] != local/* && noware::container::any (msg ["meta"] ["source"] ["id"]).type () == noware::container::any::container::type::numeric*/)
					{
						//// Customization should be done here?
						std::cout << "[meta] [origin] [id] != local" << std::endl;
						
						if (msg ["meta"] ["source"].exists ("subject") && msg ["meta"] ["source"].exists ("function"))
						{
							std::cout << "[meta] [origin] [id].subject && .function" << std::endl;
							
							if (msg ["meta"] ["source"] ["subject"] == "presence" && msg ["meta"] ["source"] ["function"] == "declaration" && msg ["meta"] ["source"].exists ("value"))
							{
								std::cout << "[meta] [origin] [subject] == presence && [meta] [origin] [function] == declaration && [meta] [origin].value" << std::endl;
								
								//if (msg.exists ("content"))
								//{
									//if (/*msg ["meta"].exists ("source") && */msg ["meta"] ["source"].exists ("id"))
									//{
										if ((LIB::container::any) (msg ["meta"] ["source"] ["value"]))
										{
											if (_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].thread_timeout != nullptr)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].thread_timeout;
											}
											
											
											// Set the node's attributes.
											
											// Keepalive.
											_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].keepalive = msg ["meta"] ["source"] ["keepalive"].get_value ();
											
											// Addresses.
											//for (const LIB::container::object <>::container::grp & address : msg ["meta"] ["source"] ["address"])
											for (
													LIB::container::object <>::iterator it_address_current = msg ["meta"] ["source"] ["address"].begin (),
														it_address_end = msg ["meta"] ["source"] ["address"].end ();
													it_address_current != it_address_end;
													++ it_address_current
												)
											{
												//for (const LIB::container::object <>::container::grp & version : *(address.v))
												for (
														LIB::container::object <>::iterator it_version_current = (*it_address_current).begin (),
															it_version_end = (*it_address_current).end ();
														it_version_current != it_version_end;
														++ it_version_current
													)
												{
													//for (const LIB::container::object <>::container::grp & attribute : *(version.v))
													for (
															LIB::container::object <>::iterator it_attribute_current = (*it_version_current).begin (),
																it_attribute_end = (*it_version_current).end ();
															it_attribute_current != it_attribute_end;
															++ it_attribute_current
														)
													{
														_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].addresses [it_address_current.k ()] [it_version_current.k ()] [it_attribute_current.k ()] = (*it_attribute_current).get_value ().text ();
													}
												}
											}
											
											// Networks.
											//for (const LIB::container::object <> & network : msg ["meta"] ["source"] ["network"])
											for (
													LIB::container::object <>::iterator it_current = msg ["meta"] ["source"] ["network"].begin (),
														it_end = msg ["meta"] ["source"] ["network"].end ();
													it_current != it_end;
													++ it_current
												)
												_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].networks [it_current.k ()] = (*it_current).get_value ().text ();
											
											
											std::cout << "Setting node thread." << std::endl;
											
											//_nodes [(LIB::container::any) msg ["content"] ["source"] ["id"]].thread_timeout = new boost::thread (boost::bind (& LIB::net::node::function_timeout/*, & (_nodes [msg ["content"] ["id"] ["source"]])*/, _nodes, (LIB::container::any) msg ["content"] ["source"] ["id"], _nodes [(LIB::container::any) msg ["content"] ["source"] ["id"]].keepalive + timeout));
											_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].thread_timeout = new boost::thread (boost::bind (boost::mem_fn (& LIB::net::node::function_timeout), & (_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]]), _nodes, LIB::math::numbers::natural (LIB::container::any (msg ["meta"] ["source"] ["id"]).text ().c_str ()), _nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].keepalive + timeout));
											// _nodes [/*(LIB::container::any) */msg ["meta"] ["source"] ["id"]].thread_timeout = new boost::thread (boost::bind (boost::mem_fn (& LIB::net::node::function_timeout), & (_nodes [msg ["meta"] ["source"] ["id"]]), _nodes, msg ["meta"] ["source"] ["id"], _nodes [msg ["meta"] ["source"] ["id"]].keepalive + timeout));
										}
										else
										{
											/*
											if (_nodes [msg ["content"] ["id"] ["source"]].thread_timeout != nullptr)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [msg ["content"] ["id"] ["source"]].thread_timeout;
												_nodes [msg ["content"] ["id"] ["source"]].thread_timeout = nullptr;
											}
											*/
											
											
											std::cout << "Unsetting node thread." << std::endl;
											
											// Done within node::~node().
											/*if (_nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].thread_timeout != nullptr)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [(LIB::container::any) msg ["meta"] ["source"] ["id"]].thread_timeout;
											}*/
											_nodes.unset (LIB::container::any (msg ["meta"] ["source"] ["id"]));
											
											//// TODO: Pass the message to everyone else who is not connected (did not receive).
											//broadcast (_message, remote_endpoint);
										}
									//}
								//}
							}
							else
							{
								std::cout << "[meta] [origin] [subject] != presence || [meta] [origin] [function] != declaration || ![meta] [origin].value" << std::endl;
							}
						}
						else
						{
							std::cout << "![meta] [origin] [id].subject || !.function" << std::endl;
						}
						
						broadcast (msg, remote_endpoint);
						
						//if (handler != LIB::container::content::null)
						//if (handler != nullptr)
						if (!handler.empty ())
							//(*handler) (msg, remote_endpoint);
							//(*handler) (remote_endpoint, serial);
							
							//(*handler) (msg, remote_endpoint);
							handler (msg, remote_endpoint);
					}
					else
					{
						std::cout << "[meta] [origin] [id] == local" << std::endl;
					}
					
					//broadcast (_message, remote_endpoint);
				}
				else
				{
					std::cout << "![meta] [origin].id" << std::endl;
				}
			}
			else
			{
				std::cout << "![meta].origin" << std::endl;
			}
		}
		else
		{
			std::cout << "!meta" << std::endl;
		}
	}
	else
	{
		std::cout << "Deserialization Failed" << std::endl;
	}
	
	//if (handler != LIB::container::content::null)
	//	(*handler) (remote_endpoint, serial);
}

//const bool LIB::net::cluster::receive_async (const boost::function <void (const LIB::container::object <> &/* remote_endpoint*/, const std::string &/* message*/)> & _handler)
//const bool LIB::net::cluster::receive_async (const boost::function <void (const LIB::communication::message &/* message*/, const LIB::container::object <> &/* remote_endpoint*/)> & _handler)
const bool LIB::net::cluster::receive_async (const boost::function <void (const noware::container::object <> &/* message*/, const LIB::container::object <> &/* remote_endpoint*/)> & _handler)
{
	handler = &_handler;
	
	return true;
}

const bool LIB::net::cluster::receive_async_stop (void)
{
	//if (handler != LIB::container::content::null)
	//if (handler != nullptr)
		//handler = LIB::container::content::null;
		//handler = nullptr;
	
	handler.clear ();
	
	return true;
}

//const bool LIB::net::cluster::broadcast (const LIB::communication::message & _message) const
//const bool LIB::net::cluster::broadcast (LIB::communication::message _message) const
const bool LIB::net::cluster::broadcast (noware::container::object <> msg) const
{
	const LIB::container::object <> remote_endpoint;
	//LIB::container::object <> remote_endpoint;
	
	if (msg.exists ("meta"))
	{
		std::cout << "Exists::meta:" << true << std::endl;
		
		if (msg ["meta"].exists ("source"))
		{
			std::cout << "Exists::meta.origin:" << true << std::endl;
			
			if (msg ["meta"] ["source"].exists ("subject"))
			{
				std::cout << "Exists::meta.origin.subject:" << true << std::endl;
			}
		}
	}
	std::cout << "Sending 1::  Subject: [" << msg ["meta"] ["source"] ["subject"] << ']'<< std::endl;
	std::cout << "Sending 1:: Function: [" << msg ["meta"] ["source"] ["function"] << ']'<< std::endl;
	std::cout << "Sending 1::    Value: [" << msg ["meta"] ["source"] ["value"] << ']'<< std::endl;
	
	return broadcast (msg, remote_endpoint);
}

// const bool LIB::net::cluster::broadcast (LIB::communication::message _message, const LIB::container::object <> & remote_endpoint) const
//const bool LIB::net::cluster::broadcast (LIB::communication::message _message, LIB::container::object <> remote_endpoint) const
const bool LIB::net::cluster::broadcast (noware::container::object <> msg, const LIB::container::object <> & remote_endpoint) const
{
	//std::string received_network;
	
	LIB::math::numbers::natural id_previous;
	//LIB::container::NAME_A <std::string, LIB::math::numbers::natural> networks_previous;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>, std::string> addresses_origin;
	bool id_previous_existed = false;
	// bool networks_previous_existed = false;
	//bool addresses_origin_existed = false;
	
	
	if (/*! msg ["meta"].exists ("source") || */msg ["meta"] ["previous"].exists ("id") && LIB::container::any (msg ["meta"] ["previous"] ["id"]).type () == noware::container::any::container::type::numeric)
	{
		std::cout << " Previous ID (broadcast): [" << msg ["meta"] ["previous"] ["id"] << ']'<< std::endl;
		id_previous = LIB::math::numbers::natural (std::string (LIB::container::any (msg ["meta"] ["previous"] ["id"])).c_str ());
		//id_previous = LIB::math::numbers::natural (LIB::container::any (msg ["meta"] ["previous"] ["id"]));
		//id_previous = msg ["meta"] ["previous"] ["id"];
		id_previous_existed = true;
	}
	
	std::cout << " Sending::   Local ID: [" << local << ']'<< std::endl;
	//std::cout << " Sending::PRE::  Origin ID: [" << msg ["meta"] ["source"] ["id"] << ']'<< std::endl;
	//std::cout << " Sending::PRE::Previous ID: [" << msg ["meta"] ["previous"] ["id"] << ']'<< std::endl;
	
	//if (/*! msg ["meta"].exists ("source") || */msg ["meta"] ["previous"].exists ("network"))
	//{
	//	//networks_previous = msg ["meta"] ["previous"] ["network"];
	//	networks_previous_existed = true;
	//}
	
	//if (/*! msg ["meta"].exists ("source") || */msg ["meta"] ["source"].exists ("address"))
	//{
	//	addresses_origin = msg ["meta"] ["source"] ["address"];
	//	addresses_origin_existed = true;
	//}
	
	
	
	//msg ["meta"] ["redistribution"]/* ["re"]*/ = true;
	msg ["meta"] ["previous"] ["id"] = local;
	//msg ["meta"] ["previous"] ["network"] = LIB::container::any (_nodes [local].networks);
	for (const LIB::container::NAME_A <std::string, LIB::math::numbers::natural>::container & network : _nodes [local].networks)
		msg ["meta"] ["previous"] ["network"] [network.k] = LIB::container::any (network.v);
	
	if (/*! msg ["meta"].exists ("source") || */! msg ["meta"] ["source"].exists ("id"))
		msg ["meta"] ["source"] ["id"] = msg ["meta"] ["previous"] ["id"];
	
	if (/*! msg ["meta"].exists ("source") || */! msg ["meta"] ["source"].exists ("network"))
		msg ["meta"] ["source"] ["network"] = msg ["meta"] ["previous"] ["network"];
	
	if (/*! msg ["meta"].exists ("source") || */! msg ["meta"] ["source"].exists ("address"))
		//msg ["meta"] ["source"] ["address"] = (LIB::container::any) _nodes [local].addresses.serialize ();
		for (const noware::container::array <noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>, std::string>::container & address : _nodes [local].addresses)
		{
			for (const noware::container::array <noware::container::array <std::string, std::string>, noware::math::numbers::natural>::container & version : address.v)
			{
				for (const noware::container::array <std::string, std::string>::container & attribute : version.v)
				{
					//std::cout << "\t\t" << '[' << address.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << "\t" << '[' << attribute.v << ']' << std::endl;
					msg ["meta"] ["source"] ["address"] [address.k] [version.k] [attribute.k] = LIB::container::any (attribute.v);
				}
			}
		}
	
	
	std::cout << " Sending::POST::  Origin ID: [" << msg ["meta"] ["source"] ["id"] << ']'<< std::endl;
	std::cout << " Sending::POST::Previous ID: [" << msg ["meta"] ["previous"] ["id"] << ']'<< std::endl;
	
	std::cout << "Sending::  Subject: [" << msg ["meta"] ["source"] ["subject"] << ']'<< std::endl;
	std::cout << "Sending:: Function: [" << msg ["meta"] ["source"] ["function"] << ']'<< std::endl;
	std::cout << "Sending::    Value: [" << msg ["meta"] ["source"] ["value"] << ']'<< std::endl;
	
	// If any *_previous_existed == false, then that should (normally) mean that this machine is the origin.
	
	if (id_previous_existed)
	// There was a previous node which transmitted.
	{
		LIB::container::object <> addresses;
		//LIB::container::NAME_A <std::string, LIB::math::numbers::natural> networks;	// Try to use this one!
		LIB::container::NAME_A <> networks;														// Temporary work-around.
		
		networks
			=																		// Value
				// The networks which this machine is connected to.
				//msg ["meta"] ["previous"] ["network"]
				//networks_previous
				_nodes [local].networks
		;
		//}
		
		if (/*addresses_origin_existed && */remote_endpoint.is_group () && remote_endpoint.exists ("address"))
		{
			networks
				-=
					// Network which the message was received on.
					network_received (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>, std::string> (/*addresses_origin*/msg ["meta"] ["source"] ["address"].serialize ()), remote_endpoint ["address"].serialize ())
			;
		}
		
		// If this machine is a neighbour of the original transmitter.
		if (/*networks_previous_existed && *//*id_previous_existed && */msg ["meta"] ["source"] ["id"] == id_previous)
		{
			//// If we are here, then that means that this machine is a neighbour of the original transmitter.
			
			networks
				-=
					// The networks which the source (original transmitter) is connected to.
					//original_networks
					//LIB::container::NAME_A <> (msg ["meta"] ["source"] ["network"]) - networks_disconnected (id_previous)
					LIB::container::NAME_A <> (msg ["meta"] ["source"] ["network"]) - LIB::container::NAME_A <> (networks_disconnected (id_previous))
					//LIB::container::NAME_A <> (msg ["meta"] ["source"] ["network"]) - *(dynamic_cast <LIB::container::NAME_A <> *> (const_cast <LIB::container::NAME_A <std::string, LIB::math::numbers::natural> *> (& networks_disconnected (id_previous))))
			;
		}
		
		
		addresses ["addresses"] = LIB::container::any (networks.serialize ());
		//addresses ["network"] = networks;
		
		std::cout << "::Networks:" << std::endl;
		for (const LIB::container::NAME_A <>::container & network : networks)
			std::cout << "\t" << '[' << network.k << ']' << ' ' << '[' << network.v << ']' << std::endl;
		
		std::cout << "Broadcast :: Proxy" << std::endl;
		
		//return mpi.broadcast (_message, addresses, false);
		if (mpi.broadcast (msg.serialize (), addresses, false))
		{
			std::cout << "Broadcast :: Success" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Broadcast :: Failure" << std::endl;
			return false;
		}
	}
	else
	//if (networks.empty ())	// ?
	// This machine is the original transmitter.
	{
		std::cout << "Broadcast :: Origin" << std::endl;
		//LIB::container::object <> addr;
		//addr ["address"]
		
		std::cout << "SERIAL(DEPARTING)[" << msg.serialize () << ']';
		//return mpi.broadcast (_message, false);
		if (mpi.broadcast (msg.serialize (), false))
		{
			std::cout << "Broadcast :: Success" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Broadcast :: Failure" << std::endl;
			return false;
		}
	}
	/*else
	{
		LIB::container::object <> addresses;
		
		addresses ["addresses"] = networks;
		
		
		return mpi.broadcast (_message, addresses, false);
	}*/
}

const std::string LIB::net::cluster::network_received (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>, std::string> & addresses, const std::string & address)
{
	for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>, std::string>::container & devices : addresses)
	{
		for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>::container & version : devices.v)
		{
			if (version.v.exists ("address") && version.v ["address"] == address && version.v.exists ("network"))
			{
				return version.v ["network"];
			}
		}
	}
	
	return "";
}

const LIB::container::NAME_A <std::string, LIB::math::numbers::natural> LIB::net::cluster::networks_disconnected (const LIB::math::numbers::natural & member) const
{
	LIB::container::NAME_A <std::string, LIB::math::numbers::natural> networks;
	bool network_found;
	
	for (const LIB::container::NAME_A <std::string, LIB::math::numbers::natural>::container & network_local : _nodes [local].networks)
	{
		for (const LIB::container::NAME_A <std::string, LIB::math::numbers::natural>::container & network_remote : _nodes [member].networks)
		{
			if (network_local.v == network_remote.v)
			{
				network_found = false;
				
				//for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::math::numbers::natural>::container & path_remote : _nodes [member].paths.all ())
				for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any>::container & path_remote : _nodes [member].paths.all ())
				{
					//if (path_remote.v.exists ("network") && path_remote.v ["network"] == network_local.v)
					if (/*path_remote.v.exists (1) && */path_remote.v [1] == network_local.v)
					{
						network_found = true;
						
						break;
					}
				}
				
				if ( ! /* we are interested if the network is not connected */ network_found)
					networks += network_local.v;
			}
		}
	}
	
	return networks;
}

const bool LIB::net::cluster::transmit (const noware::container::set <> & message, const LIB::math::numbers::natural & id) const
{
	return false;
}

const bool LIB::net::cluster::transmit (const noware::container::set <> & message, const noware::container::array <LIB::math::numbers::natural> & ids) const
{
	for (const auto & id : ids)
	{
		if (!transmit (message, id.v))
			return false;
	}
	
	return true;
}

