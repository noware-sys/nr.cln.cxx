#pragma once

// Boost serialization:
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_member.hpp>	// For separating loading and saving.
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/bitset.hpp>
//#include <boost/serialization/hash_map.hpp>
//#include <boost/serialization/hash_set.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/slist.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>

#include "../serial.hxx"

namespace noware
{
	//namespace misc
	//{
		class serial
		{
			public:
				virtual const std::string serialize (void) const;
				virtual const bool deserialize (const std::string &);
			protected:
				friend class boost::serialization::access;
				
				template <typename archive>
				void serialize (archive &, const unsigned int &/* version*/);
		};
	//}
}
