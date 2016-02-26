#ifndef GROUP
#define GROUP

//#include <boost/any.hpp>
//#include <string>
//#include <iostream>
//#include <fstream>

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
//#include "../mathematics.h++"

/*#ifndef NAME_V
#define NAME_V variable
#endif NAME_V
*/
namespace LIB
{
	//class NAME_V;

	//typedef NAME_V var;
	
	template <typename value/* = NAME_V*/>
	class group// : public tools::iterator
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
			class container
			{
				public:
					container (void);
					container (const container &);
					
					value current;
					//const value & get (void) const;
				protected:
					value * previous;
					value * next;
			};
			
			class iterator : public tools::iterator
			{
				public:
					iterator (void);
					
					value operator * (void) const;
					bool operator != (const iterator &/* other*/);
					const iterator & operator ++ (void);
					
					value value_;
				protected:
					container * current;
					friend class container;
			};
			
			group (void);
			group (const group <value> &/* other*/);
			 //text (const char &);
			//text (const char *);
			
			//mathematics::numbers::natural	cardinality		(void) const;
			//mathematics::numbers::natural	length			(void) const;
			//mathematics::numbers::natural	size			(void) const;
			
			//operator text (void) const;
			//operator char * (void) const;
			
			//text operator = (const char &);
			//text operator = (const char *);
			
			//char operator [] (const char &) const;
			//char operator [] (const char []) const;
			
			void clear (void);
			bool add (const value &);
			//void append (const value &);
			//void prepend (const value &);
			value remove ();
			//value get ();
			
			bool operator == (const group <value> &);
			group <value> operator = (const group <value> &);
			group <value> operator + (const group <value> &);
			group <value> operator += (const group <value> &);
			
			// For range-based for loops:
			iterator begin (void) const;
			iterator end (void) const;
			
			value value_;	// To be returned by default.
		protected:
			container * values;
			//container * current;
			//LIB::NAME_A <char, LIB::mathematics::numbers::integer> value;
			
			bool locked;
			
			friend class iterator;
			friend class container;
	};
}

#include "group.t++"

#endif