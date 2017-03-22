#ifndef __TEXT
#define __TEXT

//#include <boost/any.hpp>
#include <string>
#include <iostream>
#include <fstream>

//#include <algorithm>
//#include <cstdlib>
//#include <cmath>
//#include <deque>
//#include <iostream>
//#include <list>
//#include <set>
//#include <map>
//#include <boost/bind.hpp>
//#include <boost/shared_ptr.hpp>
//#include <boost/enable_shared_from_this.hpp>

//#include <boost/array.hpp>
//#include <boost/asio.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "../default.h++"
#include "../tools.h++"
#include "../mathematics.h++"

/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
namespace LIB
{
	//class NAME_V;

	//typedef NAME_V var;
	
	// binary
	// text string script
	class text
	{
		/*
		public:
		protected:
			friend class boost::serialization::access;
			// friend std::ostream & operator << (std::ostream &, const instruction &);

			//template <typename Archive>
			//void serialize (Archive &, const unsigned int);
			template <typename Archive>
			void serialize (Archive & destination, const unsigned int version)
			{
				destination & value;
				destination & _type;
			}
		*/
		public:
			//text (void);
			//text (const text &);
			 //text (const char &);
			//text (const char *);
			
			//mathematics::numbers::natural	cardinality		(void) const;
			//mathematics::numbers::natural	length			(void) const;
			//mathematics::numbers::natural	size			(void) const;
			
			//operator text (void) const;
			operator char * (void) const;
			
			//text operator = (const char &);
			text operator = (const char *);
			
			//char operator [] (const char &) const;
			//char operator [] (const char []) const;
		protected:
			//char * value;
			//LIB::NAME_A <char, LIB::mathematics::numbers::integer> value;
			LIB::group <char> value;
	};
}

#endif
