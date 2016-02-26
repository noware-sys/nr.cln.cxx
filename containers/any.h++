#ifndef ANY
#define ANY

#include <cstdarg>
#include <sstream>

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

#include <boost/any.hpp>
//#include <boost/array.hpp>
//#include <boost/asio.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "../default.h++"
#include "../tools.h++"

#ifndef NAME_NE
#define NAME_NE any
#endif

//#define MAXIMUM (a, b) (a > b ? a : b)

namespace LIB
{
	//template <typename type> 
	//class container
	//{
	//	//container (void);
	//	//~container (void);

	//	//void * data;
	//	type data;
	//};
	//http://stackoverflow.com/questions/2562176/storing-a-type-in-c
	class Type
	{
		public:
			virtual void* getObj () const=0;
	};
	
	template <typename T> class TypeImpl : public Type
	{
		public:
			TypeImpl (T * obj)
			{
				myobj=obj;
			}
			
			T * getObj () const
			{
				return dynamic_cast <T *> (myobj);
			}

		private:
			T* myobj;
	};
	
	
	struct Load_Interface;
	
	struct Loader
	{
	  virtual void visit(Load_Interface&) = 0;
	};
	
	struct Load_Interface
	{
	  virtual void accept_loader(Loader& l)
		{
			l.visit (*this);
		}
	};
	
//	class NAME_NE //: public boost::any
//	{
//		// std::type_info type_holder;
//		protected:
//		//public:
//			/*
//				int i = 5;
//
//				const std::type_info & t1 = typeid (i);
//				cout << t1.name ();
//			*/
//
//			std::type_info * type;
//
//			//std::string _type;
//			//boost::any content;
//			void * content;
//			//std::stringstream content;
//		public:
//			NAME_NE ();
//			~NAME_NE ();
//
//			//container <int> * data;
//            //const std::type_info & type () const;
//
//			//std::type_info type;
////			boost::any content;
////			//void * container;
////
////			//template <typename ValueType> ValueType data;
//////			template <typename ValueType = typeid (content)> ValueType get (void);
////
//
//			//NAME_NE & operator = (const boost::any &);
//			NAME_NE & operator = (/*const */void * );
//			
//			//template <typename type>
//			//operator type (void);
//			//operator NAME_NE & (void);
//			// operator void * (void);
//			//bool get (NAME_NE &, ...);
//			//template <typename T>
//			//operator T (void);
//			// LIB::NAME_NE::operator void *& (void) const;
//			//LIB::NAME_NE::operator std::stringstream (void) const;
//			// std::string get (void);
//			// int get_int (void);
//			//operator int (void);
//			//template <typename type>
//			//type get (void);
//			//template <typename type>
//			//type LIB::NAME_NE::get (void)
//			//{
//			//	type variable;
//
//			//	try
//			//	{
//			//		// Get the instruction's members from the input stream:
//			//		boost::archive::text_iarchive a (content);
//			//		//a >> ss;
//			//		//std::getline (content, s, '\n');
//			//		//a >> s;
//			//		a >> variable;
//
//			//	}
//			//	catch (...)
//			//	{
//
//			//	}
//
//			//	return variable;
//
//			//}
//			
//			//T get (void);
//			
//			//operator boost::any (void);
//			//operator void * (void);
//			//operator bool (void);
//			//operator signed short int (void);
//			//operator unsigned short int (void);
//			//operator signed int (void);
//			//operator unsigned int (void);
//			//operator signed long int (void);
//			//operator unsigned long int (void);
//			//operator signed long long int (void);
//			//operator unsigned long long int (void);
//			//operator float (void);
//			//operator double (void);
//			//operator long double (void);
//			//operator char (void);
//			//operator signed char (void);
//			//operator unsigned char (void);
//			//operator std::string (void);
//
//
//			//NAME_NE & operator = (void *);
//			//operator void * (void);
//			
//            //virtual const std::type_info & type (void) const = 0;
//
//			//void f (void *, int);
//			//operator -> ();
//			//template <typename type> 
//			//operator type ();
//
//			//void * & operator = (const void *);
//
			//#define _set (t) \
			(\
				container = t\
			)

			//#define _get () \
			(\
				container;\
			)

//			//NAME_NE & operator = (void *);
//			//void *& operator = (void *);
////			NAME_NE & set (boost::any);
//
//			//void * operator -> (void);
//	};
}

//#include "any.cpp"

//#include <cmath>
////#include <stdio.h>
////#include <ctype.h>
////#include <sstream>
////#include <iostream>
//#include "../default.hpp"
//#include "any.hpp"
////#include "../Utilities.h"
////using namespace ::std;
//
//
//LIB::NAME_NE::NAME_NE ()
//{
//	//_type = NULL;
//	//_type;
//	//type = NULL;
//	//type (,);
//	//*this ->
//
//}
//
//LIB::NAME_NE::~NAME_NE ()
//{
//	//& container;
//	//delete _type;
//	//delete content;
//}
//
//LIB::NAME_NE & LIB::NAME_NE::operator = (boost::any value)
////NAME_NE & NAME_NE::operator = (void * value)
//{
//	//type = 
///*		if (container.empty ())
//		return container = value;
//	else
//		return
//*/	
//	//*this -> content = ;
//	//return container = & value;
//	//return *this;
//	//* _type = typeid (value);
//	//_type = typeid (value).name ();
//	content = value;
//
//	return *this;
//}
//
//template <typename T>
////NAME_NE::operator boost::any (void)
////NAME_NE::operator T (void)
//T LIB::NAME_NE::get (void)
//{
//	//return boost::any_cast <content.type ()> (content);
//	//return boost::any_cast <const_cast <const content> (content)> (content);
//	//return reinterpret_cast <_type> (content);
//	//return const_cast <_type -> > (content);
//	//return const_cast <T> (content);
//	
//	//return boost::any_cast <T> (content);
//
//	return boost::any_cast <content.type ()> (content);
//}
//
//void * NAME_NE::operator -> (void)
//{

//}
//void NAME_NE::f (void * v, int i)
//{

//}

//NAME_NE & NAME_NE::set (boost::any val)
//{
//	content = val;

//	return *this;
//}

//NAME_NE & NAME_NE::set (void * ne, ...)
//{
//	va_list arguments;

//	va_start (arguments, ne);

//	va_arg (arguments, void *);

//	va_end (arguments);
//}

//  template <typename ValueType>
//  ValueType get (void) //(any * operand)
//  {
	//return boost::any_cast <ValueType> (content);
//      //return & static_cast <any::holder <ValueType> *> (operand -> content) -> held;
//  }
//virtual const std::type_info & NAME_NE::type (void) const
//{
//	return typeid (_type);
//}

#endif
