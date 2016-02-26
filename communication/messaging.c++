#include "messaging.h++"

const static unsigned short int LIB::communication::messaging::default_udp_port;
const static unsigned short int LIB::communication::messaging::default_tcp_port;

// Message :

LIB::communication::message::message (void)
{
}

LIB::communication::message::message (const LIB::communication::message & other)
{
	*this = other;
}

template <typename archive>
void LIB::communication::message::serialize (archive & archive, const unsigned int & version)
{
	//archive & action;
	archive & content;
}

//template <typename value, typename key>
const std::string LIB::communication::message::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const bool LIB::communication::message::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::communication::message> (serial, * this);
}

//template <typename value, typename key>
const LIB::communication::message & LIB::communication::message::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::communication::message::operator const std::string (void) const
{
	return serialize ();
}

const LIB::communication::message & LIB::communication::message::operator = (const message & other)
{
	content = other.content;
	
	return * this;
}

const LIB::communication::message & LIB::communication::message::operator == (const message & other) const
{
	return content == other.content;
}


// Transmission:

LIB::communication::transmission::transmission (void)
{
	data = "";
	terminator = NULL;
}

LIB::communication::transmission::~transmission (void)
{
	if (terminator != NULL)
	{
		delete terminator;
		//terminator = NULL;
	}
	
	lock.unlock ();
}

void LIB::communication::transmission::terminate (LIB::NAME_A <transmission, LIB::mathematics::numbers::natural> & transmissions, const LIB::mathematics::numbers::natural & key, const LIB::mathematics::numbers::natural & timeout/* total*/) const
{
	boost::asio::io_service io;
	boost::asio::deadline_timer timer (io);
	
	//io.reset ();
	
	timer.expires_from_now (boost::posix_time::milliseconds (timeout));
	//timer.async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
	
	io.run ();
	
	timer.wait ();
	
	if (transmissions.exists (key))
	{
		transmissions [key].lock.unlock ();
	}
}

// Messaging: Path:
LIB::communication::messaging::path::path (void)
{
	_direction = direction::forward;
}

LIB::communication::messaging::path::path (const LIB::communication::messaging::path & other)
{
	*this = other;
}

//LIB::communication::messaging::path::~path (void)
//{}

template <typename archive>
void LIB::communication::messaging::path::serialize (archive & arch, const unsigned int & version)
{
	arch & _direction;
	arch & _path;
}

const std::string LIB::communication::messaging::path::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const std::string LIB::communication::messaging::path::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const bool LIB::communication::messaging::path::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::communication::messaging::path> (serial, * this);
}

//template <typename value, typename key>
const LIB::communication::messaging::path & LIB::communication::messaging::path::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::communication::messaging::path::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::communication::messaging::path::operator == (const LIB::communication::messaging::path & other) const
{
	return _direction == other._direction && _path == other._path;
}

const LIB::communication::messaging::path & LIB::communication::messaging::path::operator = (const LIB::communication::messaging::path & other) const
{
	_path = other._path;
	_direction = other._direction;
	
	return * this;
}

// Messaging:

LIB::communication::messaging::messaging (void)
{
	mpi._connections [1].addrs.listen ["port"] = default_udp_port;
	mpi._connections [1].addrs.broadcast ["port"] = default_udp_port;
	
	mpi._connections [1].addrs.reception ["port"] = default_tcp_port;
	mpi._connections [1].addrs.transmission ["port"] = default_tcp_port;
	
	mpi.receive_async (boost::bind (boost::mem_fn (& LIB::communication::messaging::__receive), this, _1, _2));
	mpi.listen_async (boost::bind (boost::mem_fn (& LIB::communication::messaging::__receive), this, _1, _2));
}

LIB::communication::messaging::~messaging (void)
{
	//mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::members::__receive), this, _1, _2));
	//mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::members::__receive), this, _1, _2));
}

template <typename archive>
void LIB::communication::messaging::serialize (archive & arch, const unsigned int & version)
{
	arch & mpi;
}

const std::string LIB::communication::messaging::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const std::string LIB::communication::messaging::serialize (void) const
{
	return LIB::serialize <LIB::communication::message> (* this);
}

//template <typename value, typename key>
const bool LIB::communication::messaging::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::communication::messaging> (serial, * this);
}

//template <typename value, typename key>
const LIB::communication::messaging & LIB::communication::messaging::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return *this;
}

//template <typename value, typename key>
LIB::communication::messaging::operator const std::string (void) const
{
	return serialize ();
}

const bool LIB::communication::messaging::operator == (const LIB::communication::messaging & other) const
{
	return mpi == other.mpi;
}

const LIB::communication::messaging & LIB::communication::messaging::operator = (const LIB::communication::messaging & other) const
{
	mpi = other.mpi;
	
	return * this;
}

const bool LIB::communication::messaging::transmit (const LIB::communication::message & msg, const LIB::communication::messaging::path & _path) const
{
	if (_path._path.empty ())
		return false;
	
	return mpi.transmit (msg, _path._path.beginning ());
}
/*
const bool LIB::communication::messaging::broadcast (const message & msg) const
{
	return false;
}
*/
/*
const bool LIB::communication::messaging::transmit (const message & msg, const LIB::NAME_A <LIB::mathematics::numbers::natural, LIB::mathematics::numbers::natural> & machines) const
{
	return false;
}
*/
const std::string LIB::communication::messaging::communicate (const LIB::communication::message & msg, const path & _path, const LIB::mathematics::numbers::natural & timeout/* per hop*/)
{
	LIB::mathematics::numbers::natural key;
	transmission lmn;	// eLeMeNt : Something needs to be enqueued.
	
	if (! transmissions/* [_path]*/.enqueue (lmn, key))
	{
		transmissions/* [_path]*/.unset (key);
		
		//if (transmissions [_path].empty ())
		//	transmissions.unset (_path);
		
		return "";
	}
	
	// Prepare the message (set the header).
	msg = prepare (msg);
	msg.content ["meta"] ["transmission"] ["id"] = key;
	
	transmissions/* [_path]*/ [key].lock.lock ();
	
	if (! transmit (msg, _path))
	//if (communicate (message, _path) == "0")
	{
		transmissions/* [_path]*/.unset (key);
		
		//if (transmissions [_path].empty ())
		//	transmissions.unset (_path);
		
		return "";
	}
	
	// Calculate the total timeout.
	timeout *= _path._path.size () + 1 /* A little extra. */;
	
	transmissions [key].terminator = new boost::thread (boost::bind (& LIB::communication::transmission::terminate, & (transmissions [key]), transmissions, key, timeout));
	
	// Block to wait for a call to unlock ()
	// when ready or when the wait is not valid anymore.
	transmissions/* [_path]*/ [key].lock.lock ();
	
	//LIB::NTT <> data;
	std::string data;
	
	data = transmissions/* [_path]*/ [key].data;
	
	transmissions/* [_path]*/.unset (key);
	
	//if (transmissions [_path].empty ())
	//	transmissions.unset (_path);
	
	//transmissions [key].unlock ();
	
	return data;
}

const LIB::communication::message & LIB::communication::messaging::prepare (LIB::communication::message & msg) const
{
	// Create these keys, if needed, simply by stating them.
	msg.content ["meta"];// ["path"] ["forward"];
	//msg.content ["content/literal/data"];
	
	return msg;
}

const bool LIB::communication::messaging::validate (const LIB::communication::message & msg) const
{
	return msg.content.exists ("meta");// && msg.content ["meta"].exists ("path") && msg.content ["meta"] ["path"].exists ("forward");
}

void LIB::communication::messaging::__receive (LIB::NTT <> remote_endpoint, const std::string & msg)
{
	LIB::communication::message _message;
	
	if (_message.deserialize (msg))
	{
		if (validate (_message))
		{
			// Use the default port, not this one: it is the port used to send the message; it is not the listening nor the receiving port.
			remote_endpoint.unset ("port");
			
			LIB::communication::messaging::path _path, _path_reverse;
			
			if (msg.content ["meta"].exists ("path") && msg.content ["meta"] ["path"].exists ("forward") && _path.deserialize (_message.content ["meta"] ["path"] ["forward"]))
			{
				if (_message.content ["meta"] ["path"].exists ("reverse"))
					_path_reverse.deserialize (_message.content ["meta"] ["path"] ["reverse"]);
				
				//_message.content ["meta"] ["path"] ["descending"];
				//++ _path.location;
				//_message.content ["meta"] ["path"] = _path.serialize ();
				_path._path.dequeue ();
				_path_reverse._path.push (remote_endpoint);
				
				if (_path._path.empty ())
				//if (_path.location >= _path._path.size ())
				{
					// The message is for this local machine.
					
					// Manage the message.
					//manage (remote_endpoint, msg);
					manage (remote_endpoint, _message);
					
					if (_path._direction == path::direction::forward)
					{
						// Return the response.
						LIB::communication::messaging::path _path_reverse_temp;
						
						_path_reverse_temp._direction = path::direction::backward;
						
						for (; ! _path_reverse._path.empty (); _path_reverse._path.pop ())
						//for (LIB::methematics::numbers::natural step = _path_reverse._path.size (); step >= 1; --step)
						{
							_path_reverse_temp._path.enqeue (_path_reverse._path.ending ());
						}
						
						_message.content ["meta"] ["path"] ["forward"] = _path_reverse_temp.serialize ();
						
						transmit (_message, _path_reverse_temp);
					}
				}
				else
				{
					// The message is hopping via this local machine.
					_message.content ["meta"] ["path"] ["forward"] = _path.serialize ();
					_message.content ["meta"] ["path"] ["reverse"] = _path_reverse.serialize ();
					
					transmit (_message, _path);
				}
			}
		}
	}
	
	//receive (remote_endpoint, msg);
}

//void LIB::communication::messaging::receive (LIB::NTT <> remote_endpoint, const std::string & msg)
//{
//	// Intentionally left unimplemented.
//}

//void LIB::communication::messaging::manage (LIB::NTT <> remote_endpoint, const std::string & msg)
void LIB::communication::messaging::manage (LIB::NTT <> remote_endpoint, const LIB::communication::message & _message)
{
	// Intentionally left blank.
}
