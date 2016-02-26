#ifndef PEERS
#define PEERS

#include <string>
#include <map>
//#include <list>
//#include <omp.h>

//#include <boost/any.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/system/error_code.hpp>
//#include <boost/system/system_error.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "../default.hpp"
#include "../containers/variable.hpp"
#include "../containers/array.hpp"
#include "../mathematics.hpp"
#include "../network/messaging.hpp"
#include "../network/ip.hpp"

namespace LIB
{
	namespace cluster
	{
		//class InitialBroadcast
		//{
		//public:
		//	void operator () (void);
		//};

		//class InitialListen
		//{
		//public:
		//	void operator () (void);
		//};

		class peers
		{
			protected:
				//std::string localhost;
				//std::map<std::string, bool> members;
				//bool running;
				//std::map<std::string, bool> members;
				LIB::NAME_A <bool /*Value (Online/Offline)*/, std::string /*Key (IP address)*/> peers;
				//map <std::string, bool> peers;
				//LIB::NAME_A <std::string /*Value (IP address)*/, Mathematics::Number::Natural /*Key: Index*/> members;
				//LIB::NAME_A <Mathematics::Number::Natural, > members;
				// bool confirm;
				// string answer;

				//bool copy;
				std::string delimiter;			// Delimits parts of the message
				std::string actionDelimiter;	// Delimits parts of the message

				boost::asio::io_service ioKeepalive;
				boost::asio::io_service ioDiscovery;

				boost::asio::deadline_timer * timerKeepalive;
				boost::asio::deadline_timer * timerDiscovery;

				//boost::asio::deadline_timer t (io);

				boost::thread * keepaliveThreadBroadcast;
				boost::thread * keepaliveListener;

				boost::thread * discoveryThreadBroadcast;
				boost::thread * discoveryListener;
				
				boost::thread * discoveryReceiver;
				boost::thread * keepaliveReceiver;
				
				enum Content {ADDRESS, ACTION, DATA};
				enum Action {KEEPALIVE, ACKNOWLEDGE, DISCOVERY, DISCOVERED};

				void Acknowledge (std::string);
				void Broadcast (/*const boost::system::error_code & e*/);
				void Clear (void);
				void Clean (void);
				//void InitialBroadcast (const boost::system::error_code & e);
				//void InitialListen (const boost::system::error_code & e);
				
				std::string parse (std::string/*Message*/, content/*What is being asked*/, mathematics::numbers::natural = 0/*Data index*/);	// Parse the message.

				void Discover (void);
				void DiscoverDo (void);

				void DiscoveryReceive (void);
				void DiscoveryListen (void);
				//
				void KeepaliveAsk (void);
				void KeepaliveAskDo (void);

				void KeepaliveReceive (void);
				void KeepaliveListen (void);
				//
				void ActDirectKeepalive (std::string /*Received message.*/);
				void ActBroadcastKeepalive (std::string /*Received message.*/);

				void ActDirectDiscovery (std::string /*Received message.*/);
				void ActBroadcastDiscovery (std::string /*Received message.*/);
			public:
				peers (void);
				~peers (void);

				LIB::mathematics::numbers::natural	keepalive,	// Seconds between online checks among nodes.
													timeout,	// Seconds to wait before a node is declared offline.
													delay;		// Discovery delay.

				//void Refresh (void);
				LIB::mathematics::numbers::natural size () const;
				bool empty () const;
				//LIB::NAME_A <bool, std::string> * List (void);

				LIB::network::messaging::Interface mpi_keepalive, mpi_discovery;

				//LIB::NAME_A <bool, std::string> & List (void);
		};
	}
}

#endif PEERS
