#pragma once
//#ifndef __VARIABLE
//#define __VARIABLE

//#include <boost/any.hpp>
#include <string>
#include <iostream>
//#include <fstream>

//#include <sqlite3.h>
//#include "../../sqlite/3.h"
//#include "databases/sqlite.h"
//#include "../../sqlite/3.c"

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
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/string.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>

//#include "../name.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
#include "../tool.h++"
#include "content/value.h++"
#include "text.h++"

//dynamic ~!= static
//constant ~!= variable

namespace noware
{
	//class NAME_V;
	
	//typedef NAME_V var;
	// container cont ctn ctnr ctner
	namespace container
	{
		// type: fundamental primitive built-in intrinsic basic
		// (container of a value) all any container value category var[iable] struct[ure] class obj[ect] it[e]m 
		class any
		{
			public:
				class container
				{
					public:
						enum /*class */type
						{
							generic,
							numeric
							
							//text
							//string
							//number,
						};
						
						friend class boost::serialization::access;
						
						// The type of the variable currently being stored.
						// Only one type is active at any time.
						type t;
						
						text txt;
						//noware::math::numbers::real number;
						math::number no;
						//boost::any content;
						
						template <typename archive>
						void serialize (archive &/* archive*/, const unsigned int &/* version*/);
						
						const text serialize (void) const;
						const bool deserialize (const text &/* serial*/);
				};
				
				friend class boost::serialization::access;
				
				const text serialize (void) const;
				const bool deserialize (const text &);
				
				const container::type & type (void) const;
				
				any (void);
				any (const any &);	// Needed?
				any (const bool &);
				//any (const math::number &);
				any (const text &);
				//any (const std::string &);
				
				//any (const char []);
				
				//~any (void);
				
				// Conversion functions:
				//operator any (void) const;
				operator const bool (void) const;
				operator const math::number (void) const;
				operator const text (void) const;
				
				//_type GetType (void);

				//bool		GetValueBoolean (void);
				//long double	GetValueNumeric (void);
				//::std::string	GetValueGeneric (void);

				//::std::istream	&	getline (::std::istream &, const ::std::string = "\n");
				//::std::istream	&	getline (::std::istream &, const unsigned int, const ::std::string = "\n");
				//::std::istream	&	getline (::std::istream &, const unsigned int);

				//bool	Is_Generic	(void);
				//bool	Is_Numeric	(void);
				//bool	Is_Boolean	(void);

				// Returns a string representation of the content, whatever type it may be.
				// const std::string to_string (void) const;
				
				// returns the numeric value if the content is a number, or the default numerical value, otherwise.
				//long double		to_number	(void);
				//bool		to_boolean	(void);
				//noware::mathematics::numbers::natural	length		(void) const;
				// size length
				// const math::number size (void) const;
				const math::number length (void) const;
				
				//const any operator + (void) const;
				const any operator + (const any &) const;
				//const any operator + (const math::number &) const;
				const any operator + (const text &) const;
				friend const any operator + (const math::number &, const any &);
				friend const any operator + (const text &, const any &);
				
				// -
				const any operator - (void) const;	// For negating:
				const any operator - (const any &) const;
				//const any operator - (const math::number &) const;
				const any operator - (const text &) const;
				friend const any operator - (const math::number &, const any &);
				friend const any operator - (const text &, const any &);
				
				const any operator * (const any &) const;
				//const any operator * (const math::number &) const;
				const any operator * (const text &) const;
				friend any operator * (const math::number &, const any &);
				friend any operator * (const text &, const any &);

				const any operator / (const any &) const;
				//const any operator / (const math::number &) const;
				const any operator / (const text &) const;
				friend const any	operator / (const math::number &, const any &);
				friend const any	operator / (const text &, const any &);
			
				// Modulo:
				const any operator % (const any &) const;
				//const any operator % (const math::number) const;
				const any operator % (const text &) const;
				friend signed long long int operator % (const math::number &, const any &);
				friend signed long long int operator % (const text &, const any &);
				
				// Exponentiation:
				const any operator ^ (const any &) const;
				//const any operator ^ (const math::number &) const;
				const any operator ^ (const text &) const;
				friend const any operator ^ (const math::number &, const any &);
				friend const any operator ^ (const text &, const any &);
			
				//bool		any			(void);
				// Complement.
				const any operator ~ (void) const;
				// Modulus.
				//const any operator | (void) const;
				// Negation.
				const bool operator ! (void) const;
				
				// Assignment.
				const any & operator = (const any &);
				//const math::number & operator = (const math::number &);
				const text & operator = (const text &);
				
				const bool operator < (const any &) const;
				const bool operator < (const math::number &) const;
				//const bool operator < (const text &) const;
				friend bool operator < (const math::number &, const any &);

						//const bool			operator	>	(const any &) const;
						//const bool			operator	>	(any &) const;
						//const bool			operator	>	(const any &);
						const bool			operator	>	(const any);
						const bool			operator	>	(const any) const;
						bool			operator	>	(const signed short int &);
						bool			operator	>	(const unsigned short int &);
						bool			operator	>	(const signed int &);
						bool			operator	>	(const unsigned int &);
						bool			operator	>	(const signed long int &);
						bool			operator	>	(const unsigned long int &);
						bool			operator	>	(const signed long long int &);
						bool			operator	>	(const unsigned long long int &);
						bool			operator	>	(const float &);
						bool			operator	>	(const double &);
						bool			operator	>	(const long double &);
						bool			operator	>	(const char &);
						//bool			operator	>	(const signed char);
						//bool			operator	>	(const unsigned char);
						bool			operator	>	(const char []);
						bool			operator	>	(const std::string &);

				friend	bool			operator	>	(const signed short int &, any &);
				friend	bool			operator	>	(const unsigned short int &, any &);
				friend	bool			operator	>	(const signed int &, any &);
				friend	bool			operator	>	(const unsigned int &, any &);
				friend	bool			operator	>	(const signed long int &, any &);
				friend	bool			operator	>	(const unsigned long int &, any &);
				friend	bool			operator	>	(const signed long long int &, any &);
				friend	bool			operator	>	(const unsigned long long int &, any &);
				friend	bool			operator	>	(const float &, any &);
				friend	bool			operator	>	(const double &, any &);
				friend	bool			operator	>	(const long double &, any &);
				friend	bool			operator	>	(const char &, any &);
				//friend	bool			operator	>	(const signed char, any);
				//friend	bool			operator	>	(const unsigned char, any);
				friend	bool			operator	>	(const ::std::string &, any &);

						any	&		operator	+=	(const any &);
						any	&		operator	+=	(const signed short int &);
						any	&		operator	+=	(const unsigned short int &);
						any	&		operator	+=	(const signed int &);
						any	&		operator	+=	(const unsigned int &);
						any	&		operator	+=	(const signed long int &);
						any	&		operator	+=	(const unsigned long int &);
						any	&		operator	+=	(const signed long long int &);
						any	&		operator	+=	(const unsigned long long int &);
						any	&		operator	+=	(const float &);
						any	&		operator	+=	(const double &);
						any	&		operator	+=	(const long double &);
						any	&		operator	+=	(const char &);
						//any				operator	+=	(const signed char);
						//any				operator	+=	(const unsigned char);
						any	&		operator	+=	(const char []);
						any	&		operator	+=	(const std::string &);

				friend	const signed short int &				operator	+=	(signed short int &, any &);
				friend	const unsigned short int &				operator	+=	(unsigned short int &, any &);
				friend	const signed int &						operator	+=	(signed int &, any &);
				friend	const unsigned int &					operator	+=	(unsigned int &, any &);
				friend	const signed long int &					operator	+=	(signed long int &, any &);
				friend	const unsigned long int &				operator	+=	(unsigned long int &, any &);
				friend	const signed long long int &			operator	+=	(signed long long int &, any &);
				friend	const unsigned long long int &			operator	+=	(unsigned long long int &, any &);
				friend	const float &							operator	+=	(float &, any &);
				friend	const double &							operator	+=	(double &, any &);
				friend	const long double &						operator	+=	(long double &, const any &);
				friend	const mathematics::numbers::integer &	operator	+=	(mathematics::numbers::integer &, any &);
				friend	const mathematics::numbers::real &		operator	+=	(mathematics::numbers::real &, const any &);
				//friend	std::string								operator	+=	(const char, const any);
				friend	const std::string &						operator	+=	(std::string &, const any &);
			
						any	&		operator	-=	(const any &);
						any	&		operator	-=	(const signed short int);
						any	&		operator	-=	(const unsigned short int);
						any	&		operator	-=	(const signed int);
						any	&		operator	-=	(const unsigned int);
						any	&		operator	-=	(const signed long int);
						any	&		operator	-=	(const unsigned long int);
						any	&		operator	-=	(const signed long long int);
						any	&		operator	-=	(const unsigned long long int);
						any	&		operator	-=	(const float);
						any	&		operator	-=	(const double);
						any	&		operator	-=	(const long double);
						any	&		operator	-=	(const char);
						any	&		operator	-=	(const char []);
						any	&		operator	-=	(const ::std::string);

				friend	long double			operator	-=	(const signed short int, const any);
				friend	long double			operator	-=	(const unsigned short int, const any);
				friend	long double			operator	-=	(const signed int, const any);
				friend	long double			operator	-=	(const unsigned int, any);
				friend	long double			operator	-=	(const signed long int, const any);
				friend	long double			operator	-=	(const unsigned long int, const any);
				friend	long double			operator	-=	(const signed long long int, const any);
				friend	long double			operator	-=	(const unsigned long long int, const any);
				friend	long double			operator	-=	(const float, const any);
				friend	long double			operator	-=	(const double, const any);
				friend	long double			operator	-=	(const long double, any);

						any	&		operator	*=	(const any);
						any	&		operator	*=	(const signed short int);
						any	&		operator	*=	(const unsigned short int);
						any	&		operator	*=	(const signed int);
						any	&		operator	*=	(const unsigned int);
						any	&		operator	*=	(const signed long int);
						any	&		operator	*=	(const unsigned long int);
						any	&		operator	*=	(const signed long long int);
						any	&		operator	*=	(const unsigned long long int);
						any	&		operator	*=	(const float);
						any	&		operator	*=	(const double);
						any	&		operator	*=	(const long double);
		
				friend	long double			operator	*=	(const signed short int, const any);
				friend	long double			operator	*=	(const unsigned short int, const any);
				friend	long double			operator	*=	(const signed int, const any);
				friend	long double			operator	*=	(const unsigned int, any);
				friend	long double			operator	*=	(const signed long int, const any);
				friend	long double			operator	*=	(const unsigned long int, const any);
				friend	long double			operator	*=	(const signed long long int, const any);
				friend	long double			operator	*=	(const unsigned long long int, const any);
				friend	long double			operator	*=	(const float, const any);
				friend	long double			operator	*=	(const double, const any);
				friend	long double			operator	*=	(long double, any);

						any	&		operator	/=	(const any &);
						any	&		operator	/=	(const signed short int);
						any	&		operator	/=	(const unsigned short int);
						any	&		operator	/=	(const signed int);
						any	&		operator	/=	(const unsigned int);
						any	&		operator	/=	(const signed long int);
						any	&		operator	/=	(const unsigned long int);
						any	&		operator	/=	(const signed long long int);
						any	&		operator	/=	(const unsigned long long int);
						any	&		operator	/=	(const float);
						any	&		operator	/=	(const double);
						any	&		operator	/=	(const long double);
						any	&		operator	/=	(const char &);
						any	&		operator	/=	(const char []);
						any	&		operator	/=	(const std::string &);

				friend	long double			operator	/=	(const signed short int, const any);
				friend	long double			operator	/=	(const unsigned short int, const any);
				friend	long double			operator	/=	(const signed int, const any);
				friend	long double			operator	/=	(const unsigned int, any);
				friend	long double			operator	/=	(const signed long int, const any);
				friend	long double			operator	/=	(const unsigned long int, const any);
				friend	long double			operator	/=	(const signed long long int, const any);
				friend	long double			operator	/=	(const unsigned long long int, const any);
				friend	long double			operator	/=	(const float, const any);
				friend	long double			operator	/=	(const double, const any);
				friend	long double			operator	/=	(const long double, any);

				// Modulo:
						any		operator	%=	(const any);
						any		operator	%=	(const signed short int);
						any		operator	%=	(const unsigned short int);
						any		operator	%=	(const signed int);
						any		operator	%=	(const unsigned int);
						any		operator	%=	(const signed long int);
						any		operator	%=	(const unsigned long int);
						any		operator	%=	(const signed long long int);
						any		operator	%=	(const unsigned long long int);
						any		operator	%=	(const float);
						any		operator	%=	(const double);
						any		operator	%=	(const long double);
						any		operator	%=	(char);
						any		operator	%=	(const ::std::string);

				friend	signed long long int		operator	%=	(signed short int &, const any);
				friend	signed long long int		operator	%=	(unsigned short int &, const any);
				friend	signed long long int		operator	%=	(signed int &, const any);
				friend	signed long long int		operator	%=	(unsigned int &, const any);
				friend	signed long long int		operator	%=	(signed long int &, const any);
				friend	signed long long int		operator	%=	(unsigned long int &, const any);
				friend	signed long long int		operator	%=	(signed long long int &, const any);
				friend	signed long long int		operator	%=	(unsigned long long int &, const any);
				friend	signed long long int		operator	%=	(float &, const any);
				friend	signed long long int		operator	%=	(double &, const any);
				friend	signed long long int		operator	%=	(long double &, const any);
				//friend	signed long long int		operator	%=	(const char, any);
				//friend	signed long long int		operator	%=	(const ::std::string, any);

				// Exponentiation:
						any		operator	^=	(const any);
						any		operator	^=	(const signed short int);
						any		operator	^=	(const unsigned short int);
						any		operator	^=	(const signed int);
						any		operator	^=	(const unsigned int);
						any		operator	^=	(const signed long int);
						any		operator	^=	(const unsigned long int);
						any		operator	^=	(const signed long long int);
						any		operator	^=	(const unsigned long long int);
						any		operator	^=	(const float);
						any		operator	^=	(const double);
						any		operator	^=	(const long double);
						any		operator	^=	(const char);
						//any		operator	^=	(const char []);
						any		operator	^=	(const ::std::string);

				friend	signed long long int		operator	^=	(signed short int &, const any);
				friend	signed long long int		operator	^=	(unsigned short int &, const any);
				friend	signed long long int		operator	^=	(signed int &, const any);
				friend	signed long long int		operator	^=	(unsigned int &, const any);
				friend	signed long long int		operator	^=	(signed long int &, const any);
				friend	signed long long int		operator	^=	(unsigned long int &, const any);
				friend	signed long long int		operator	^=	(signed long long int &, const any);
				friend	signed long long int		operator	^=	(unsigned long long int &, const any);
				friend	signed long long int		operator	^=	(float &, const any);
				friend	signed long long int		operator	^=	(double &, const any);
				friend	signed long long int		operator	^=	(long double &, const any);

				friend	std::ostream &	operator	<<	(std::ostream &, const any &)/* const*/;
				friend	std::istream &	operator	>>	(std::istream &, any &);
	
				//friend	::std::ofstream &	operator	<<	(::std::ofstream &, any);
				//friend	::std::ifstream &	operator	>>	(::std::ifstream &, any);

						bool			operator	==	(const any &);
						bool			operator	==	(const bool &);
						bool			operator	==	(const signed short int &);
						bool			operator	==	(const unsigned short int &);
						bool			operator	==	(const signed int &);
						bool			operator	==	(const unsigned int &);
						bool			operator	==	(const signed long int &);
						bool			operator	==	(const unsigned long int &);
						bool			operator	==	(const signed long long int &);
						bool			operator	==	(const unsigned long long int &);
						bool			operator	==	(const float &);
						bool			operator	==	(const double &);
						bool			operator	==	(const long double &);
						bool			operator	==	(const char &);
						//bool			operator	==	(const signed char);
						//bool			operator	==	(const unsigned char);
						bool			operator	==	(const char []);
						bool			operator	==	(const ::std::string &);
					
						// Equality, constant:
						bool			operator	==	(const any &) const;
						bool			operator	==	(const bool &) const;
						bool			operator	==	(const signed short int &) const;
						bool			operator	==	(const unsigned short int &) const;
						bool			operator	==	(const signed int &) const;
						bool			operator	==	(const unsigned int &) const;
						bool			operator	==	(const signed long int &) const;
						bool			operator	==	(const unsigned long int &) const;
						bool			operator	==	(const signed long long int &) const;
						bool			operator	==	(const unsigned long long int &) const;
						bool			operator	==	(const float &) const;
						bool			operator	==	(const double &) const;
						bool			operator	==	(const long double &) const;
						bool			operator	==	(const char &) const;
						//bool			operator	==	(const signed char);
						//bool			operator	==	(const unsigned char);
						bool			operator	==	(const char []) const;
						bool			operator	==	(const ::std::string &) const;
				
				friend	bool			operator	==	(const bool &, const any &);
				friend	bool			operator	==	(const signed short int &, const any &);
				friend	bool			operator	==	(const unsigned short int &, const any &);
				friend	bool			operator	==	(const signed int &, const any &);
				friend	bool			operator	==	(const unsigned int &, const any &);
				friend	bool			operator	==	(const signed long int &, const any &);
				friend	bool			operator	==	(const unsigned long int &, const any &);
				friend	bool			operator	==	(const signed long long int &, const any &);
				friend	bool			operator	==	(const unsigned long long int &, const any &);
				friend	bool			operator	==	(const float &, const any &);
				friend	bool			operator	==	(const double &, const any &);
				friend	bool			operator	==	(const long double &, const any &);
				friend	bool			operator	==	(const char &, const any &);
				//friend	bool			operator	==	(const signed char, any);
				//friend	bool			operator	==	(const unsigned char, any);
				friend	bool			operator	==	(const ::std::string &, const any &);

						bool			operator	!=	(const any);
						bool			operator	!=	(const bool);
						bool			operator	!=	(const signed short int);
						bool			operator	!=	(const unsigned short int);
						bool			operator	!=	(const signed int);
						bool			operator	!=	(const unsigned int);
						bool			operator	!=	(const signed long int);
						bool			operator	!=	(const unsigned long int);
						bool			operator	!=	(const signed long long int);
						bool			operator	!=	(const unsigned long long int);
						bool			operator	!=	(const float);
						bool			operator	!=	(const double);
						bool			operator	!=	(const long double);
						bool			operator	!=	(const char);
						//bool			operator	!=	(const signed char);
						//bool			operator	!=	(const unsigned char);
						bool			operator	!=	(const char []);
						bool			operator	!=	(const ::std::string);

				friend	bool			operator	!=	(const bool, any);
				friend	bool			operator	!=	(const signed short int, any);
				friend	bool			operator	!=	(const unsigned short int, any);
				friend	bool			operator	!=	(const signed int, any);
				friend	bool			operator	!=	(const unsigned int, any);
				friend	bool			operator	!=	(const signed long int, any);
				friend	bool			operator	!=	(const unsigned long int, any);
				friend	bool			operator	!=	(const signed long long int, any);
				friend	bool			operator	!=	(const unsigned long long int, any);
				friend	bool			operator	!=	(const float, any);
				friend	bool			operator	!=	(const double, any);
				friend	bool			operator	!=	(const long double, any);
				friend	bool			operator	!=	(const char, any);
				//friend	bool			operator	!=	(const signed char, any);
				//friend	bool			operator	!=	(const unsigned char, any);
				friend	bool			operator	!=	(const ::std::string, any);

						const bool			operator	<=	(const any);
						const bool			operator	<=	(const any) const;
						//const bool			operator	<=	(const any);
						//const bool			operator	<=	(const any);
						//const bool			operator	<=	(const any) const;
						bool			operator	<=	(const signed short int);
						bool			operator	<=	(const unsigned short int);
						bool			operator	<=	(const signed int);
						bool			operator	<=	(const unsigned int);
						bool			operator	<=	(const signed long int);
						bool			operator	<=	(const unsigned long int);
						bool			operator	<=	(const signed long long int);
						bool			operator	<=	(const unsigned long long int);
						bool			operator	<=	(const float);
						bool			operator	<=	(const double);
						bool			operator	<=	(const char);
						//bool			operator	<=	(const signed char);
						//bool			operator	<=	(const unsigned char);
						bool			operator	<=	(const long double);
						bool			operator	<=	(const ::std::string);

				friend	bool			operator	<=	(const signed short int, any);
				friend	bool			operator	<=	(const unsigned short int, any);
				friend	bool			operator	<=	(const signed int, any);
				friend	bool			operator	<=	(const unsigned int, any);
				friend	bool			operator	<=	(const signed long int, any);
				friend	bool			operator	<=	(const unsigned long int, any);
				friend	bool			operator	<=	(const signed long long int, any);
				friend	bool			operator	<=	(const unsigned long long int, any);
				friend	bool			operator	<=	(const float, any);
				friend	bool			operator	<=	(const double, any);
				friend	bool			operator	<=	(const long double, any);
				friend	bool			operator	<=	(const char, any);
				//friend	bool			operator	<=	(const signed char, any);
				//friend	bool			operator	<=	(const unsigned char, any);
				friend	bool			operator	<=	(const ::std::string, any);

						bool			operator	>=	(const any);
						bool			operator	>=	(const signed short int);
						bool			operator	>=	(const unsigned short int);
						bool			operator	>=	(const signed int);
						bool			operator	>=	(const unsigned int);
						bool			operator	>=	(const signed long int);
						bool			operator	>=	(const unsigned long int);
						bool			operator	>=	(const signed long long int);
						bool			operator	>=	(const unsigned long long int);
						bool			operator	>=	(const float);
						bool			operator	>=	(const double);
						bool			operator	>=	(const long double);
						bool			operator	>=	(const char);
						//bool			operator	>=	(const signed char);
						//bool			operator	>=	(const unsigned char);
						bool			operator	>=	(const ::std::string);

				friend	bool			operator	>=	(const signed short int, any);
				friend	bool			operator	>=	(const unsigned short int, any);
				friend	bool			operator	>=	(const signed int, any);
				friend	bool			operator	>=	(const unsigned int, any);
				friend	bool			operator	>=	(const signed long int, any);
				friend	bool			operator	>=	(const unsigned long int, any);
				friend	bool			operator	>=	(const signed long long int, any);
				friend	bool			operator	>=	(const unsigned long long int, any);
				friend	bool			operator	>=	(const float, any);
				friend	bool			operator	>=	(const double, any);
				friend	bool			operator	>=	(const long double, any);
				friend	bool			operator	>=	(const char, any);
				//friend	bool			operator	>=	(const signed char, any);
				//friend	bool			operator	>=	(const unsigned char, any);
				friend	bool			operator	>=	(const ::std::string, any);

						bool			operator	&&	(const any);
						bool			operator	&&	(const bool);
				friend	bool			operator	&&	(const bool, any);
						bool			operator	||	(const any);
						bool			operator	||	(const bool);
				friend	bool			operator	||	(const bool, any);

				// Prefix:
				//friend		any &		operator	++	(any &);
				//friend		any &		operator	--	(any &);
							/*const*/ any	&	operator	++	(void);
							/*const*/ any	&	operator	--	(void);
				// Suffix / Postfix:
							//any &		operator	++	(void);
							//any &		operator	--	(void);
							/*const*/ any		operator	++	(signed int);
							/*const*/ any		operator	--	(signed int);
			protected:
				template <typename archive>
				void serialize (archive &, const unsigned int &);
				
			//private:
				container content;
				//boost::any content;
				
				// Default values:
				// type _type;	// The type of the value being stored.
				//::std::string value;
			
				//void Assign (/*Container &, */const ::std::string);
				//void Assign (/*Container &, */const long double);
			
				// const std::string &	to_string (void) const;
				
				//_type Determine (const any::any);
				// determine specify
			//	const type determine (const std::string &) const;
				//_type Determine (const long double);
			
		};
	}
	
	//typedef any var;
	//typedef container::any any, var;
}

std::istream &	getline (std::istream &, noware::container::any &, const char = '\n');

std::string		tolower (const noware::container::any &);
std::string		toupper (const noware::container::any &);

//#endif
