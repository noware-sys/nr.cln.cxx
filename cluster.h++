#pragma once
//#ifndef __MACHINE
//#define __MACHINE

#include <string>
#include <sstream>
#include <mutex>

//#include <boost/any.hpp>

//#include "Lexical_Analyzer"
#include "value.h++"
//#include "peers.h++"
#include "containers/array.h++"
#include "mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "cluster.h++" file.
#include "cluster/machine.h++"
#include "cluster/members.h++"
#include "machine/resource.h++"
#include "machine/resources/memory.h++"
#include "machine/resources/processor.h++"
//#include "../machine/resources.h++"
//#include "members.h++"
#include "containers/entity.h++"
//#include "../network/ip/mpi.h++"
#include "network/mpi.h++"
#include "communication/messaging.h++"
#include "language/interpreter.h++"

namespace LIB
{
	namespace cluster
	{
		class cluster
		{
			public:
				cluster (void);
				~ cluster (void);
				
				// For resolving ID conflicts.
				class conflict
				{
					public:
						conflict (void);
						~conflict (void);
						
						LIB::NAME_A <bool, std::string> response;
						LIB::NAME_A <boost::asio::io_service, std::string> io;
						LIB::NAME_A <boost::asio::deadline_timer *, std::string> timer;
						
						//LIB::NAME_A <LIB::NAME_A <bool, std::string>, LIB::mathematics::numbers::natural> response;
						//LIB::NAME_A <LIB::NAME_A <boost::asio::io_service, std::string>, LIB::mathematics::numbers::natural> io;
						//LIB::NAME_A <LIB::NAME_A <boost::asio::deadline_timer *, std::string>, LIB::mathematics::numbers::natural> timer;
				};
				
				class communication
				{
					public:
						~communication (void);
						
						std::mutex lock;
						LIB::NTT <> data;
				};
				
				void dummy (void) const;
				
				//using namespace LIB;
				/*
				class container
				{
					public:
						enum type
						{
							variable,
							string,
							number
						};
						
						//container (void);
						//container (const container &);
						
						type t;
						
						boost::any content;
				};
				*/
				//LIB::machine::devices::processor cpu;
				
				//members membs;
				
				//class process
				//{
				
				//};
				
				//void run (const bool & = false);
				
				//// Connections with peers.
				// Transfer to a network device (implementation)?
				//LIB::NAME_A <LIB::NAME_A <std::string, /*LIB::mathematics::numbers::*/natural>, /*LIB::mathematics::numbers::*/natural> connections;
				
				//LIB::machine::resources rscs;
				//LIB::NAME_A <LIB::machine::resources::resource> rscs;
				//LIB::NAME_A <LIB::machine::device *> devices;
				
				//LIB::cluster::memory memory;
				//LIB::machine::devices::processor _processor;
				//processor.
				
				// Enqueue instructions.
				const bool enqueue (const std::string &/* file_name*/);
				//bool enqueue (const LIB::cluster::devices::processor::instructions & /* A queue of instruction. */);
				//bool enqueue (const LIB::cluster::devices::processor::instruction & /* A single instruction. */);
				
				//bool parse (const std::string);
				
				// Provide read-only access:
				//const LIB::NAME_A <std::string, std::string> & get_error (void) const;
				// std::string get_error_code (void);
				// std::string get_error_message (void);
				
				//const bool set (const std::string &/* name*/, const boost::any &/* value*/, const std::string &/* group*/ = "");
				//const bool get (const std::string &/* name*/, const boost::any &/* value*/, const std::string &/* group*/ = "") const;
				//const bool exist (const std::string &/* name*/, const std::string &/* group*/ = "") const;
				//const bool rename (const std::string &/* name*/, const std::string &/* new name*/, const std::string &/* group*/ = "", const std::string &/* new group*/ = "");
				//const bool unset (const std::string &/* name*/, const std::string &/* group*/ = "");
				
				//const LIB::NAME_A <machine, mathematics::numbers::natural> & nodes (void);
				const LIB::cluster::members & machines (void) const;
				// const machine & machine (const mathematics::numbers::natural & = 0);
				//const LIB::entity <machine, mathematics::numbers::natural> & machines (void);
			//	const LIB::NAME_A <LIB::machine::resource *, std::string> & resources (void) const;
				//const LIB::NAME_A <LIB::machine::resource *> & resources (const LIB::NAME_V &);
				
				// Manage outbound point-to-point message.
				const bool transmit (const LIB::communication::message &, const machine &/* Machine. */) const;
				//const bool transmit (const std::string &, const mathematics::numbers::natural /* ID. */&) const;
				//const bool transmit (const std::string &, const LIB::NTT <> /* Endpoint. */&) const;
				// Manage outbound point-to-multipoint message.
				//const bool broadcast (const std::string &) const;
				const bool broadcast/*transmit*/ (const LIB::communication::message &) const;	// Broadcast.
				//const bool broadcast (const std::string &, const LIB::NAME_A <machine, mathematics::numbers::natural> &) const;
				const bool transmit (const LIB::communication::message &, const LIB::NAME_A <machine, mathematics::numbers::natural> &/* List of machines. */) const;
				//const bool broadcast (const std::string &, const LIB::NTT <mathematics::numbers::natural /* ID. */, mathematics::numbers::natural/* key*/> &) const;
				// const bool broadcast (const communication::message &, const LIB::NAME_A <std::string, mathematics::numbers::natural> /* Addresses. */&) const;
				//const bool broadcast (const communication::message &, const LIB::NAME_A <LIB::network::ip::address, mathematics::numbers::natural> /* Addresses. */&) const;
				
				const communication::message communicate (const communication::message &) const;	// Broadcast.
				const communication::message communicate (const communication::message &, const machine &/* Machine. */) const;
				
				//// Manage inbound point-to-point message.
				//void receive (const std::string &/* Message. */);
				//// Manage inbound point-to-multipoint message.
				//void listen (const std::string &/* Message. */);
				// Manage point-to-point and point-to-multipoint message.
				const bool run (const bool & = true);
				const bool & active/*run*//*ning*/ (void) const;
				
				// Time used for resolving conflicts.
				// In milliseconds.
				const unsigned short int delay_max = 5000;
			//public:
			protected:
				void input (const LIB::NTT <> &/* remote_endpoint */, const std::string &/* Message. */);
				
				bool _active;
				
				LIB::NAME_A <conflict, LIB::mathematics::numbers::natural> conflicts;
				LIB::NAME_A <communication, LIB::mathematics::numbers::natural> communications;
				
				//LIB::NAME_A <machine, mathematics::numbers::natural> nodes;
				LIB::cluster::members _machines;
				
				//// Resources.
				//LIB::NAME_A <LIB::machine::resource *, std::string> rsrc;
				
				// LIB::entity <boost::any, std::string> entities;
				//LIB::entity <container, std::string> entities;
				
				LIB::network::mpi mpi;
				
				LIB::language::interpreter _interpreter;
				//LIB::NAME_A <std::string, std::string> error;
				std::string error;
				//unsigned short int delay;
				const LIB::communication::message & prepare (/*const*/ LIB::communication::message &/* message*/) const;
				//void prepare (LIB::communication::message &/* message*/) const;
		};
	}
}

//#endif
