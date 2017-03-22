//#include <cstddef>
#include "qbit.h++"

noware::communication::qbit::qbit (void)
{
	_state = random_state ();
	being_read = false;
	//detangle ();
	other = NULL;
}

//noware::communication::qbit::~qbit (void)
//{}

const bool noware::communication::qbit::entangle (const qbit & other_)
{
	if (entangled (other_))
	{
		return true;
	}
	else if (entangled () && ! detangle ())
	{
		//if (! detangle ())
		//{
			return false;
		//}
	}
	
	other = & other_;
	
	return other_.entangle (* this);
	
	//return true;
}

const bool noware::communication::qbit::detangle (void)
{
	other = NULL;
	
	return true;
}

const bool noware::communication::qbit::entangled (void) const
{
	return other != NULL;
}

const bool noware::communication::qbit::entangled (const qbit & other_) const
{
	return other == & other_;
}

const bool & noware::communication::qbit::get (void) const
{
	return state ();
}

noware::communication::qbit::operator const bool & (void) const
{
	return get ();
}

const bool noware::communication::qbit::read (const bool & reading)
{
	being_read = reading;
	
	return being_read == reading;
//	switch (reading)
//	{
//		case true:
//			if (entangled ())
//			{
//				
//			}
//			else
//			{
//				
//			}
//			
//			break;
//		default:
//	}
}

const bool noware::communication::qbit::state (void) const
{
	if (entangled ())
	{
		if (other -> being_read)
		{
			return ! other -> state ();
		}
		else if (being_read)
		{
			return _state;
		}
		else
		{
			return random_state ();
		}
	}
	else
	{
		return random_state ();
	}
}

const bool noware::communication::qbit::random_state (void) const
{
	return labs (time (NULL)) % 2;
}
