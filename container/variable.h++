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

#include "../name.h++"
#include "../value.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
#include "../tool.h++"

#if !defined NAME_V
	#define NAME_V variable
#endif

namespace LIB
{
	//class NAME_V;
	
	//typedef NAME_V var;
	namespace containers
	{
	class NAME_V
	{
		public:
			enum /*class */type
			{
				GENERIC,
				NUMERIC
				//number,
				//text
			};

			class container
			{
				protected:
					friend class boost::serialization::access;
					
					//template<class Archive>
					//void save (Archive & archive, const unsigned int version) const;
					
					//template<class Archive>
					//void load (Archive & archive, const unsigned int version);
					
					template <typename Archive>
					void serialize (Archive & archive, const unsigned int & version);
					
				public:
					std::string	Generic;
					//long double numeric;
					LIB::mathematics::numbers::real numeric;
					//LIB::mathematics::number numeric;
					
					const std::string serialize (void) const;
					const bool deserialize (const std::string &);
			};

			const std::string serialize (void) const;
			const bool deserialize (const std::string &);
		protected:
			friend class boost::serialization::access;
			// friend std::ostream & operator << (std::ostream &, const instruction &);

			//template <typename Archive>
			//void serialize (Archive &, const unsigned int);
			template <typename Archive> 
			void serialize (Archive & archive, const unsigned int & version);
		//private:
			container value;
			// Default values:
			type _type;	// The type of the value being stored.
			//::std::string value;

			//void Assign (/*Container &, */const ::std::string);
			//void Assign (/*Container &, */const long double);

			// const std::string &	to_string (void) const;

			//_type Determine (const NAME_V::NAME_V);
			const type determine (const std::string &) const;
			//_type Determine (const long double);

		public:
			const type & get_type (void) const;
			
			NAME_V (void);
			NAME_V (const NAME_V &);	// Needed?
			//NAME_V (const bool);
			NAME_V (const signed short int &);
			NAME_V (const unsigned short int &);
			NAME_V (const signed int &);
			NAME_V (const unsigned int &);
			NAME_V (const signed long int &);
			NAME_V (const unsigned long int &);
			NAME_V (const signed long long int &);
			NAME_V (const unsigned long long int &);
			NAME_V (const float &);
			NAME_V (const double &);
			NAME_V (const long double &);
			NAME_V (const char &);
			//NAME_V (const signed char &);
			NAME_V (const unsigned char &);
			NAME_V (const char []);
			NAME_V (const LIB::mathematics::numbers::integer &);
			NAME_V (const LIB::mathematics::numbers::real &);
			//NAME_V (const LIB::mathematics::number &);
			NAME_V (const std::string &);

			//NAME_V (const char []);

			//~NAME_V (void);
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
			const std::string to_string (void) const;

			// returns the numeric value if the content is a number, or the default numerical value otherwise.
			//long double		to_number	(void);
			//bool		to_boolean	(void);
			//LIB::mathematics::numbers::natural	length		(void) const;
			const LIB::mathematics::numbers::natural	size		(void) const;
			const std::string substr (const unsigned long long int &/* Beginning character. */, const unsigned long long int &/* Length to retrieve. */);
			
			const bool empty		(void) const;
			const bool is_string (void) const;
			const bool is_text (void) const;
			const bool is_generic (void) const;
			const bool is_numeric (void) const;
			const bool is_number (void) const;
			
			// Operations for the same type:
			// NAME_V + Something
					//NAME_V		operator	+	(const NAME_V &) const;
					//NAME_V		operator	+	(const NAME_V &);
					//NAME_V		operator	+	(NAME_V &) const;
					//NAME_V		operator	+	(NAME_V &);
					NAME_V		operator	+	(const NAME_V);
					NAME_V		operator	+	(const NAME_V) const;
					//long double		operator	+	(const bool);
					NAME_V		operator	+	(const signed short int &);
					NAME_V		operator	+	(const unsigned short int &);
					//NAME_V		operator	+	(signed int);
					NAME_V		operator	+	(const signed int &);
					NAME_V		operator	+	(const signed int &) const;
					NAME_V		operator	+	(const unsigned int &);
					NAME_V		operator	+	(const signed long int &);
					NAME_V		operator	+	(const unsigned long int &);
					NAME_V		operator	+	(const signed long long int &);
					NAME_V		operator	+	(const unsigned long long int &);
					NAME_V		operator	+	(const float &);
					NAME_V		operator	+	(const double &);
					NAME_V		operator	+	(const long double &);
					NAME_V		operator	+	(const char &);
					//NAME_V		operator	+	(const signed char);
					//NAME_V		operator	+	(const unsigned char);
					NAME_V		operator	+	(const char []);
					NAME_V		operator	+	(const LIB::mathematics::numbers::integer &);
					NAME_V		operator	+	(const LIB::mathematics::numbers::real &);
					//NAME_V		operator	+	(const LIB::mathematics::number &);
					NAME_V		operator	+	(const ::std::string &);
			// Something + NAME_V
			//friend	long double		operator	+	(const NAME_V, const unsigned int);
			//friend	long double		operator	+	(const NAME_V, const signed long int);
			//friend	long double		operator	+	(const NAME_V, const unsigned long int);
			//friend	long double		operator	+	(const NAME_V, const signed long long int);
			//friend	long double		operator	+	(const NAME_V, const unsigned long long int);
			//friend	long double		operator	+	(const NAME_V, const float);
			//friend	long double		operator	+	(const NAME_V, const double);
			//friend	long double		operator	+	(const NAME_V, const long double);
			//friend	::std::string		operator	+	(const NAME_V, const signed char);
			//friend	::std::string		operator	+	(const NAME_V, const unsigned char);
			//friend	::std::string		operator	+	(const NAME_V, const ::std::string);

			//friend	long double		operator	+	(const bool, const NAME_V);
			friend	NAME_V		operator	+	(const signed short int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned short int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed int &, const NAME_V &);
			//friend	NAME_V		operator	+	(const signed int &, const NAME_V);
			friend	NAME_V		operator	+	(const unsigned int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed long long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned long long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const float &, const NAME_V &);
			friend	NAME_V		operator	+	(const double &, const NAME_V &);
			friend	NAME_V		operator	+	(const long double &, const NAME_V &);
			friend	NAME_V		operator	+	(const LIB::mathematics::numbers::integer &, const NAME_V &);
			friend	NAME_V		operator	+	(const LIB::mathematics::numbers::real &, const NAME_V &);
			friend	NAME_V		operator	+	(const char &, const NAME_V &);
			//friend	NAME_V		operator	+	(const signed char, NAME_V);
			//friend	NAME_V		operator	+	(const unsigned char, NAME_V);
			friend	NAME_V		operator	+	(const char [], const NAME_V &);
			friend	NAME_V		operator	+	(const std::string &, const NAME_V &);

			// - Left side:
					// For negating:
					NAME_V		operator	-	(void);

					NAME_V		operator	-	(const NAME_V &);
					NAME_V		operator	-	(const signed short int &);
					NAME_V		operator	-	(const unsigned short int &);
					NAME_V		operator	-	(const signed int &);
					NAME_V		operator	-	(const unsigned int &);
					NAME_V		operator	-	(const signed long int &);
					NAME_V		operator	-	(const unsigned long int &);
					NAME_V		operator	-	(const signed long long int &);
					NAME_V		operator	-	(const unsigned long long int &);
					NAME_V		operator	-	(const float &);
					NAME_V		operator	-	(const double &);
					NAME_V		operator	-	(const long double &);
					NAME_V		operator	-	(const char &);
					//NAME_V		operator	-	(const char);
					//NAME_V		operator	-	(const signed char);
					//NAME_V		operator	-	(const unsigned char);
					NAME_V		operator	-	(const char []);
					NAME_V		operator	-	(const ::std::string &);

			//friend	NAME_V				operator	-	(NAME_V);
			friend	NAME_V		operator	-	(const signed short int &, const NAME_V &);
			friend	NAME_V		operator	-	(const unsigned short int &, const NAME_V &);
			friend	NAME_V		operator	-	(const signed int &, const NAME_V &);
			friend	NAME_V		operator	-	(const unsigned int &, const NAME_V &);
			friend	NAME_V		operator	-	(const signed long int &, const NAME_V &);
			friend	NAME_V		operator	-	(const unsigned long int &, const NAME_V &);
			friend	NAME_V		operator	-	(const signed long long int &, const NAME_V &);
			friend	NAME_V		operator	-	(const unsigned long long int &, const NAME_V &);
			friend	NAME_V		operator	-	(const float &, const NAME_V &);
			friend	NAME_V		operator	-	(const double &, const NAME_V &);
			friend	NAME_V		operator	-	(const long double &, const NAME_V &);

					//NAME_V		operator	*	(NAME_V);
					NAME_V		operator	*	(const NAME_V &);
					NAME_V		operator	*	(const signed short int &);
					NAME_V		operator	*	(const unsigned short int &);
					NAME_V		operator	*	(const signed int &);
					NAME_V		operator	*	(const unsigned int &);
					NAME_V		operator	*	(const signed long int &);
					NAME_V		operator	*	(const unsigned long int &);
					NAME_V		operator	*	(const signed long long int &);
					NAME_V		operator	*	(const unsigned long long int &);
					NAME_V		operator	*	(const float &);
					NAME_V		operator	*	(const double &);
					NAME_V		operator	*	(const long double &);
					NAME_V		operator	*	(const char &);
					NAME_V		operator	*	(const char []);
					NAME_V		operator	*	(const ::std::string &);

			friend	NAME_V		operator	*	(const signed short int &, const NAME_V &);
			friend	NAME_V		operator	*	(const unsigned short int &, const NAME_V &);
			friend	NAME_V		operator	*	(const signed int &, const NAME_V &);
			friend	NAME_V		operator	*	(const unsigned int &, const NAME_V &);
			friend	NAME_V		operator	*	(const signed long int &, const NAME_V &);
			friend	NAME_V		operator	*	(const unsigned long int &, const NAME_V &);
			friend	NAME_V		operator	*	(const signed long long int &, const NAME_V &);
			friend	NAME_V		operator	*	(const unsigned long long int &, const NAME_V &);
			friend	NAME_V		operator	*	(const float &, const NAME_V &);
			friend	NAME_V		operator	*	(const double &, const NAME_V &);
			friend	NAME_V		operator	*	(const long double &, NAME_V &);

					NAME_V		operator	/	(const NAME_V &);
					NAME_V		operator	/	(const signed short int &);
					NAME_V		operator	/	(const unsigned short int &);
					NAME_V		operator	/	(const signed int &);
					NAME_V		operator	/	(const unsigned int &);
					NAME_V		operator	/	(const signed long int &);
					NAME_V		operator	/	(const unsigned long int &);
					NAME_V		operator	/	(const signed long long int &);
					NAME_V		operator	/	(const unsigned long long int &);
					NAME_V		operator	/	(const float &);
					NAME_V		operator	/	(const double &);
					NAME_V		operator	/	(const long double &);
					NAME_V		operator	/	(const char &);
					NAME_V		operator	/	(const char []);
					NAME_V		operator	/	(const LIB::mathematics::numbers::integer &);
					NAME_V		operator	/	(const LIB::mathematics::numbers::real &);
					//NAME_V		operator	/	(const LIB::mathematics::number &);
					NAME_V		operator	/	(const ::std::string &);
					
			friend	long double		operator	/	(const signed short int &, const NAME_V &);
			friend	long double		operator	/	(const unsigned short int &, const NAME_V &);
			friend	long double		operator	/	(const signed int &, const NAME_V &);
			friend	long double		operator	/	(const unsigned int &, const NAME_V &);
			friend	long double		operator	/	(const signed long int &, const NAME_V &);
			friend	long double		operator	/	(const unsigned long int &, const NAME_V &);
			friend	long double		operator	/	(const signed long long int &, const NAME_V &);
			friend	long double		operator	/	(const unsigned long long int &, const NAME_V &);
			friend	long double		operator	/	(const float &, const NAME_V &);
			friend	long double		operator	/	(const double &, const NAME_V &);
			friend	long double		operator	/	(const long double &, const NAME_V &);
			friend	const NAME_V	operator	/	(const LIB::mathematics::numbers::integer &, const NAME_V &);
			friend	const NAME_V	operator	/	(const LIB::mathematics::numbers::real &, const NAME_V &);
			//friend	const NAME_V	operator	/	(const LIB::mathematics::number &, const NAME_V &);
			
			// Modulo:
					NAME_V		operator	%	(const NAME_V &);
					NAME_V		operator	%	(const signed short int &);
					NAME_V		operator	%	(const unsigned short int &);
					NAME_V		operator	%	(const signed int &);
					NAME_V		operator	%	(const unsigned int &);
					NAME_V		operator	%	(const signed long int &);
					NAME_V		operator	%	(const unsigned long int &);
					NAME_V		operator	%	(const signed long long int &);
					NAME_V		operator	%	(const unsigned long long int &);
					NAME_V		operator	%	(const float &);
					NAME_V		operator	%	(const double &);
					NAME_V		operator	%	(const long double &);
					NAME_V		operator	%	(const char &);
					NAME_V		operator	%	(const char []);
					NAME_V		operator	%	(const ::std::string &);

			friend	signed long long int		operator	%	(const signed short int &, const NAME_V &);
			friend	signed long long int		operator	%	(const unsigned short int &, const NAME_V &);
			friend	signed long long int		operator	%	(const signed int &, const NAME_V &);
			friend	signed long long int		operator	%	(const unsigned int &, const NAME_V &);
			friend	signed long long int		operator	%	(const signed long int &, const NAME_V &);
			friend	signed long long int		operator	%	(const unsigned long int &, const NAME_V &);
			friend	signed long long int		operator	%	(const signed long long int &, const NAME_V &);
			friend	signed long long int		operator	%	(const unsigned long long int &, const NAME_V &);
			friend	signed long long int		operator	%	(const float &, const NAME_V &);
			friend	signed long long int		operator	%	(const double &, const NAME_V &);
			friend	signed long long int		operator	%	(const long double &, const NAME_V &);
			//friend	signed long long int		operator	%	(const char, NAME_V);
			//friend	signed long long int		operator	%	(const ::std::string, NAME_V);
			//friend	signed long long int		operator	%	(const ::std::string, signed short int);
			//friend	signed long long int		operator	%	(const ::std::string, unsigned short int);
			//friend	signed long long int		operator	%	(const ::std::string, signed int);
			//friend	signed long long int		operator	%	(const ::std::string, unsigned int);
			//friend	signed long long int		operator	%	(const ::std::string, signed long int);
			//friend	signed long long int		operator	%	(const ::std::string, unsigned long int);
			//friend	signed long long int		operator	%	(const ::std::string, signed long long int);
			//friend	signed long long int		operator	%	(const ::std::string, unsigned long long int);

			// Exponentiation:
					LIB::mathematics::numbers::real		operator	^	(const NAME_V &);
					LIB::mathematics::numbers::real		operator	^	(const signed short int &);
					LIB::mathematics::numbers::real		operator	^	(const unsigned short int &);
					LIB::mathematics::numbers::real		operator	^	(const signed int &);
					LIB::mathematics::numbers::real		operator	^	(const unsigned int &);
					LIB::mathematics::numbers::real		operator	^	(const signed long int &);
					LIB::mathematics::numbers::real		operator	^	(const unsigned long int &);
					LIB::mathematics::numbers::real		operator	^	(const signed long long int &);
					LIB::mathematics::numbers::real		operator	^	(const unsigned long long int &);
					LIB::mathematics::numbers::real		operator	^	(const float &);
					LIB::mathematics::numbers::real		operator	^	(const double &);
					LIB::mathematics::numbers::real		operator	^	(const long double &);
					LIB::mathematics::numbers::real		operator	^	(const LIB::mathematics::numbers::integer &);
					LIB::mathematics::numbers::real		operator	^	(const LIB::mathematics::numbers::real &);
					LIB::mathematics::numbers::real		operator	^	(const char &);
					LIB::mathematics::numbers::real		operator	^	(const char []);
					LIB::mathematics::numbers::real		operator	^	(const std::string &);
					
			friend	LIB::mathematics::numbers::real		operator	^	(const signed short int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const unsigned short int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const signed int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const unsigned int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const signed long int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const unsigned long int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const signed long long int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const unsigned long long int &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const float &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const double &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const long double &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const LIB::mathematics::numbers::integer &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const LIB::mathematics::numbers::real &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const char &, const NAME_V &);
			friend	LIB::mathematics::numbers::real		operator	^	(const std::string &, const NAME_V &);
			
					// Conversion functions:
					operator	NAME_V							(void) const;
					operator	bool							(void) const;
					operator	signed short int				(void) const;
					operator	unsigned short int				(void) const;
					operator	signed int						(void) const;
					operator	unsigned int					(void) const;
					operator	signed long int					(void) const;
					operator	unsigned long int				(void) const;
					operator	signed long long int			(void) const;
					operator	unsigned long long int			(void) const;
					operator	float							(void) const;
					operator	double							(void) const;
					operator	long double						(void) const;
					//operator	LIB::mathematics::numbers::natural	(void) const;
					operator	LIB::mathematics::numbers::integer	(void) const;
					operator	LIB::mathematics::numbers::real		(void) const;
					//operator	LIB::mathematics::number				(void) const;
					operator	char							(void) const;
					operator	std::string						(void) const;
					//operator	long double		(void) const;
					//operator	sqlite3_value					(void) const;
					
					//bool		NAME_V			(void);
					NAME_V		operator	~	(void) const;	// Complement.
					//NAME_V		operator	|	(void) const;	// Modulus.
					bool		operator	!	(void) const;

					NAME_V &			operator	=	(const NAME_V &);
					//NAME_V &			operator	=	(const bool);
					NAME_V &			operator	=	(const signed short int &);
					NAME_V &			operator	=	(const unsigned short int &);
					NAME_V &			operator	=	(const signed int &);
					NAME_V &			operator	=	(const unsigned int &);
					NAME_V &			operator	=	(const signed long int &);
					NAME_V &			operator	=	(const unsigned long int &);
					NAME_V &			operator	=	(const signed long long int &);
					NAME_V &			operator	=	(const unsigned long long int &);
					NAME_V &			operator	=	(const float &);
					NAME_V &			operator	=	(const double &);
					NAME_V &			operator	=	(const long double &);
					NAME_V &			operator	=	(const char &);
					//NAME_V &			operator	=	(const signed char);
					NAME_V &			operator	=	(const unsigned char &);
					NAME_V &			operator	=	(const char []);
					//NAME_V &			operator	=	(const LIB::mathematics::numbers::natural &);
					NAME_V &			operator	=	(const LIB::mathematics::numbers::integer &);
					NAME_V &			operator	=	(const LIB::mathematics::numbers::real &);
					//NAME_V &			operator	=	(const LIB::mathematics::number &);
					NAME_V &			operator	=	(const ::std::string &);
			//friend	void			operator	=	(const signed short int, NAME_V);
			//friend	void			operator	=	(const unsigned short int, NAME_V);
			//friend	void			operator	=	(const signed int, NAME_V);
			//friend	void			operator	=	(const unsigned int, NAME_V);
			//friend	void			operator	=	(const signed long int, NAME_V);
			//friend	void			operator	=	(const unsigned long int, NAME_V);
			//friend	void			operator	=	(const signed long long int, NAME_V);
			//friend	void			operator	=	(const unsigned long long int, NAME_V);
			//friend	void			operator	=	(const float, NAME_V);
			//friend	void			operator	=	(const double, NAME_V);
			//friend	void			operator	=	(const long double, NAME_V);
			//friend	void			operator	=	(const char, NAME_V);
			//friend	void			operator	=	(const signed char, NAME_V);
			//friend	void			operator	=	(const unsigned char, NAME_V);
			//friend	void			operator	=	(const ::std::string, NAME_V);

					//const bool			operator	<	(const NAME_V &);
					const bool			operator	<	(const NAME_V);
					const bool			operator	<	(const NAME_V) const;
					//const bool			operator	<	(NAME_V &) const;
					const bool			operator	<	(const signed short int &);
					bool			operator	<	(const unsigned short int &);
					bool			operator	<	(const signed int &);
					bool			operator	<	(const unsigned int &);
					bool			operator	<	(const signed long int &);
					bool			operator	<	(const unsigned long int &);
					bool			operator	<	(const signed long long int &);
					bool			operator	<	(const unsigned long long int &);
					bool			operator	<	(const float &);
					bool			operator	<	(const double &);
					bool			operator	<	(const long double &);
					bool			operator	<	(const LIB::mathematics::numbers::integer &);
					bool			operator	<	(const LIB::mathematics::numbers::real &);
					//bool			operator	<	(const LIB::mathematics::number &);
					bool			operator	<	(const char &);
					//bool			operator	<	(const signed char);
					//bool			operator	<	(const unsigned char);
					bool			operator	<	(const char []);
					bool			operator	<	(const ::std::string &);
				
			friend	bool			operator	<	(const signed short int &, NAME_V &);
			friend	bool			operator	<	(const unsigned short int &, NAME_V &);
			friend	bool			operator	<	(const signed int &, NAME_V &);
			friend	bool			operator	<	(const unsigned int &, NAME_V &);
			friend	bool			operator	<	(const signed long int &, NAME_V &);
			friend	bool			operator	<	(const unsigned long int &, NAME_V &);
			friend	bool			operator	<	(const signed long long int &, NAME_V &);
			friend	bool			operator	<	(const unsigned long long int &, NAME_V &);
			friend	bool			operator	<	(const float &, NAME_V &);
			friend	bool			operator	<	(const double &, NAME_V &);
			friend	bool			operator	<	(const long double &, NAME_V &);
			friend	bool			operator	<	(const char &, NAME_V &);
			//friend	bool			operator	<	(const signed char, NAME_V);
			//friend	bool			operator	<	(const unsigned char, NAME_V);
			friend	bool			operator	<	(const ::std::string &, NAME_V &);

					//const bool			operator	>	(const NAME_V &) const;
					//const bool			operator	>	(NAME_V &) const;
					//const bool			operator	>	(const NAME_V &);
					const bool			operator	>	(const NAME_V);
					const bool			operator	>	(const NAME_V) const;
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

			friend	bool			operator	>	(const signed short int &, NAME_V &);
			friend	bool			operator	>	(const unsigned short int &, NAME_V &);
			friend	bool			operator	>	(const signed int &, NAME_V &);
			friend	bool			operator	>	(const unsigned int &, NAME_V &);
			friend	bool			operator	>	(const signed long int &, NAME_V &);
			friend	bool			operator	>	(const unsigned long int &, NAME_V &);
			friend	bool			operator	>	(const signed long long int &, NAME_V &);
			friend	bool			operator	>	(const unsigned long long int &, NAME_V &);
			friend	bool			operator	>	(const float &, NAME_V &);
			friend	bool			operator	>	(const double &, NAME_V &);
			friend	bool			operator	>	(const long double &, NAME_V &);
			friend	bool			operator	>	(const char &, NAME_V &);
			//friend	bool			operator	>	(const signed char, NAME_V);
			//friend	bool			operator	>	(const unsigned char, NAME_V);
			friend	bool			operator	>	(const ::std::string &, NAME_V &);

					NAME_V	&		operator	+=	(const NAME_V &);
					NAME_V	&		operator	+=	(const signed short int &);
					NAME_V	&		operator	+=	(const unsigned short int &);
					NAME_V	&		operator	+=	(const signed int &);
					NAME_V	&		operator	+=	(const unsigned int &);
					NAME_V	&		operator	+=	(const signed long int &);
					NAME_V	&		operator	+=	(const unsigned long int &);
					NAME_V	&		operator	+=	(const signed long long int &);
					NAME_V	&		operator	+=	(const unsigned long long int &);
					NAME_V	&		operator	+=	(const float &);
					NAME_V	&		operator	+=	(const double &);
					NAME_V	&		operator	+=	(const long double &);
					NAME_V	&		operator	+=	(const char &);
					//NAME_V				operator	+=	(const signed char);
					//NAME_V				operator	+=	(const unsigned char);
					NAME_V	&		operator	+=	(const char []);
					NAME_V	&		operator	+=	(const std::string &);

			friend	const signed short int &				operator	+=	(signed short int &, NAME_V &);
			friend	const unsigned short int &				operator	+=	(unsigned short int &, NAME_V &);
			friend	const signed int &						operator	+=	(signed int &, NAME_V &);
			friend	const unsigned int &					operator	+=	(unsigned int &, NAME_V &);
			friend	const signed long int &					operator	+=	(signed long int &, NAME_V &);
			friend	const unsigned long int &				operator	+=	(unsigned long int &, NAME_V &);
			friend	const signed long long int &			operator	+=	(signed long long int &, NAME_V &);
			friend	const unsigned long long int &			operator	+=	(unsigned long long int &, NAME_V &);
			friend	const float &							operator	+=	(float &, NAME_V &);
			friend	const double &							operator	+=	(double &, NAME_V &);
			friend	const long double &						operator	+=	(long double &, const NAME_V &);
			friend	const mathematics::numbers::integer &	operator	+=	(mathematics::numbers::integer &, NAME_V &);
			friend	const mathematics::numbers::real &		operator	+=	(mathematics::numbers::real &, const NAME_V &);
			//friend	std::string								operator	+=	(const char, const NAME_V);
			friend	const std::string &						operator	+=	(std::string &, const NAME_V &);
			
					NAME_V	&		operator	-=	(const NAME_V &);
					NAME_V	&		operator	-=	(const signed short int);
					NAME_V	&		operator	-=	(const unsigned short int);
					NAME_V	&		operator	-=	(const signed int);
					NAME_V	&		operator	-=	(const unsigned int);
					NAME_V	&		operator	-=	(const signed long int);
					NAME_V	&		operator	-=	(const unsigned long int);
					NAME_V	&		operator	-=	(const signed long long int);
					NAME_V	&		operator	-=	(const unsigned long long int);
					NAME_V	&		operator	-=	(const float);
					NAME_V	&		operator	-=	(const double);
					NAME_V	&		operator	-=	(const long double);
					NAME_V	&		operator	-=	(const char);
					NAME_V	&		operator	-=	(const char []);
					NAME_V	&		operator	-=	(const ::std::string);

			friend	long double			operator	-=	(const signed short int, const NAME_V);
			friend	long double			operator	-=	(const unsigned short int, const NAME_V);
			friend	long double			operator	-=	(const signed int, const NAME_V);
			friend	long double			operator	-=	(const unsigned int, NAME_V);
			friend	long double			operator	-=	(const signed long int, const NAME_V);
			friend	long double			operator	-=	(const unsigned long int, const NAME_V);
			friend	long double			operator	-=	(const signed long long int, const NAME_V);
			friend	long double			operator	-=	(const unsigned long long int, const NAME_V);
			friend	long double			operator	-=	(const float, const NAME_V);
			friend	long double			operator	-=	(const double, const NAME_V);
			friend	long double			operator	-=	(const long double, NAME_V);

					NAME_V	&		operator	*=	(const NAME_V);
					NAME_V	&		operator	*=	(const signed short int);
					NAME_V	&		operator	*=	(const unsigned short int);
					NAME_V	&		operator	*=	(const signed int);
					NAME_V	&		operator	*=	(const unsigned int);
					NAME_V	&		operator	*=	(const signed long int);
					NAME_V	&		operator	*=	(const unsigned long int);
					NAME_V	&		operator	*=	(const signed long long int);
					NAME_V	&		operator	*=	(const unsigned long long int);
					NAME_V	&		operator	*=	(const float);
					NAME_V	&		operator	*=	(const double);
					NAME_V	&		operator	*=	(const long double);
		
			friend	long double			operator	*=	(const signed short int, const NAME_V);
			friend	long double			operator	*=	(const unsigned short int, const NAME_V);
			friend	long double			operator	*=	(const signed int, const NAME_V);
			friend	long double			operator	*=	(const unsigned int, NAME_V);
			friend	long double			operator	*=	(const signed long int, const NAME_V);
			friend	long double			operator	*=	(const unsigned long int, const NAME_V);
			friend	long double			operator	*=	(const signed long long int, const NAME_V);
			friend	long double			operator	*=	(const unsigned long long int, const NAME_V);
			friend	long double			operator	*=	(const float, const NAME_V);
			friend	long double			operator	*=	(const double, const NAME_V);
			friend	long double			operator	*=	(long double, NAME_V);

					NAME_V	&		operator	/=	(const NAME_V &);
					NAME_V	&		operator	/=	(const signed short int);
					NAME_V	&		operator	/=	(const unsigned short int);
					NAME_V	&		operator	/=	(const signed int);
					NAME_V	&		operator	/=	(const unsigned int);
					NAME_V	&		operator	/=	(const signed long int);
					NAME_V	&		operator	/=	(const unsigned long int);
					NAME_V	&		operator	/=	(const signed long long int);
					NAME_V	&		operator	/=	(const unsigned long long int);
					NAME_V	&		operator	/=	(const float);
					NAME_V	&		operator	/=	(const double);
					NAME_V	&		operator	/=	(const long double);
					NAME_V	&		operator	/=	(const char &);
					NAME_V	&		operator	/=	(const char []);
					NAME_V	&		operator	/=	(const std::string &);

			friend	long double			operator	/=	(const signed short int, const NAME_V);
			friend	long double			operator	/=	(const unsigned short int, const NAME_V);
			friend	long double			operator	/=	(const signed int, const NAME_V);
			friend	long double			operator	/=	(const unsigned int, NAME_V);
			friend	long double			operator	/=	(const signed long int, const NAME_V);
			friend	long double			operator	/=	(const unsigned long int, const NAME_V);
			friend	long double			operator	/=	(const signed long long int, const NAME_V);
			friend	long double			operator	/=	(const unsigned long long int, const NAME_V);
			friend	long double			operator	/=	(const float, const NAME_V);
			friend	long double			operator	/=	(const double, const NAME_V);
			friend	long double			operator	/=	(const long double, NAME_V);

			// Modulo:
					NAME_V		operator	%=	(const NAME_V);
					NAME_V		operator	%=	(const signed short int);
					NAME_V		operator	%=	(const unsigned short int);
					NAME_V		operator	%=	(const signed int);
					NAME_V		operator	%=	(const unsigned int);
					NAME_V		operator	%=	(const signed long int);
					NAME_V		operator	%=	(const unsigned long int);
					NAME_V		operator	%=	(const signed long long int);
					NAME_V		operator	%=	(const unsigned long long int);
					NAME_V		operator	%=	(const float);
					NAME_V		operator	%=	(const double);
					NAME_V		operator	%=	(const long double);
					NAME_V		operator	%=	(char);
					NAME_V		operator	%=	(const ::std::string);

			friend	signed long long int		operator	%=	(signed short int &, const NAME_V);
			friend	signed long long int		operator	%=	(unsigned short int &, const NAME_V);
			friend	signed long long int		operator	%=	(signed int &, const NAME_V);
			friend	signed long long int		operator	%=	(unsigned int &, const NAME_V);
			friend	signed long long int		operator	%=	(signed long int &, const NAME_V);
			friend	signed long long int		operator	%=	(unsigned long int &, const NAME_V);
			friend	signed long long int		operator	%=	(signed long long int &, const NAME_V);
			friend	signed long long int		operator	%=	(unsigned long long int &, const NAME_V);
			friend	signed long long int		operator	%=	(float &, const NAME_V);
			friend	signed long long int		operator	%=	(double &, const NAME_V);
			friend	signed long long int		operator	%=	(long double &, const NAME_V);
			//friend	signed long long int		operator	%=	(const char, NAME_V);
			//friend	signed long long int		operator	%=	(const ::std::string, NAME_V);

			// Exponentiation:
					NAME_V		operator	^=	(const NAME_V);
					NAME_V		operator	^=	(const signed short int);
					NAME_V		operator	^=	(const unsigned short int);
					NAME_V		operator	^=	(const signed int);
					NAME_V		operator	^=	(const unsigned int);
					NAME_V		operator	^=	(const signed long int);
					NAME_V		operator	^=	(const unsigned long int);
					NAME_V		operator	^=	(const signed long long int);
					NAME_V		operator	^=	(const unsigned long long int);
					NAME_V		operator	^=	(const float);
					NAME_V		operator	^=	(const double);
					NAME_V		operator	^=	(const long double);
					NAME_V		operator	^=	(const char);
					//NAME_V		operator	^=	(const char []);
					NAME_V		operator	^=	(const ::std::string);

			friend	signed long long int		operator	^=	(signed short int &, const NAME_V);
			friend	signed long long int		operator	^=	(unsigned short int &, const NAME_V);
			friend	signed long long int		operator	^=	(signed int &, const NAME_V);
			friend	signed long long int		operator	^=	(unsigned int &, const NAME_V);
			friend	signed long long int		operator	^=	(signed long int &, const NAME_V);
			friend	signed long long int		operator	^=	(unsigned long int &, const NAME_V);
			friend	signed long long int		operator	^=	(signed long long int &, const NAME_V);
			friend	signed long long int		operator	^=	(unsigned long long int &, const NAME_V);
			friend	signed long long int		operator	^=	(float &, const NAME_V);
			friend	signed long long int		operator	^=	(double &, const NAME_V);
			friend	signed long long int		operator	^=	(long double &, const NAME_V);

			friend	std::ostream &	operator	<<	(std::ostream &, const NAME_V &)/* const*/;
			friend	std::istream &	operator	>>	(std::istream &, NAME_V &);
	
			//friend	::std::ofstream &	operator	<<	(::std::ofstream &, NAME_V);
			//friend	::std::ifstream &	operator	>>	(::std::ifstream &, NAME_V);

					bool			operator	==	(const NAME_V &);
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
					bool			operator	==	(const NAME_V &) const;
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
				
			friend	bool			operator	==	(const bool &, const NAME_V &);
			friend	bool			operator	==	(const signed short int &, const NAME_V &);
			friend	bool			operator	==	(const unsigned short int &, const NAME_V &);
			friend	bool			operator	==	(const signed int &, const NAME_V &);
			friend	bool			operator	==	(const unsigned int &, const NAME_V &);
			friend	bool			operator	==	(const signed long int &, const NAME_V &);
			friend	bool			operator	==	(const unsigned long int &, const NAME_V &);
			friend	bool			operator	==	(const signed long long int &, const NAME_V &);
			friend	bool			operator	==	(const unsigned long long int &, const NAME_V &);
			friend	bool			operator	==	(const float &, const NAME_V &);
			friend	bool			operator	==	(const double &, const NAME_V &);
			friend	bool			operator	==	(const long double &, const NAME_V &);
			friend	bool			operator	==	(const char &, const NAME_V &);
			//friend	bool			operator	==	(const signed char, NAME_V);
			//friend	bool			operator	==	(const unsigned char, NAME_V);
			friend	bool			operator	==	(const ::std::string &, const NAME_V &);

					bool			operator	!=	(const NAME_V);
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

			friend	bool			operator	!=	(const bool, NAME_V);
			friend	bool			operator	!=	(const signed short int, NAME_V);
			friend	bool			operator	!=	(const unsigned short int, NAME_V);
			friend	bool			operator	!=	(const signed int, NAME_V);
			friend	bool			operator	!=	(const unsigned int, NAME_V);
			friend	bool			operator	!=	(const signed long int, NAME_V);
			friend	bool			operator	!=	(const unsigned long int, NAME_V);
			friend	bool			operator	!=	(const signed long long int, NAME_V);
			friend	bool			operator	!=	(const unsigned long long int, NAME_V);
			friend	bool			operator	!=	(const float, NAME_V);
			friend	bool			operator	!=	(const double, NAME_V);
			friend	bool			operator	!=	(const long double, NAME_V);
			friend	bool			operator	!=	(const char, NAME_V);
			//friend	bool			operator	!=	(const signed char, NAME_V);
			//friend	bool			operator	!=	(const unsigned char, NAME_V);
			friend	bool			operator	!=	(const ::std::string, NAME_V);

					const bool			operator	<=	(const NAME_V);
					const bool			operator	<=	(const NAME_V) const;
					//const bool			operator	<=	(const NAME_V);
					//const bool			operator	<=	(const NAME_V);
					//const bool			operator	<=	(const NAME_V) const;
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

			friend	bool			operator	<=	(const signed short int, NAME_V);
			friend	bool			operator	<=	(const unsigned short int, NAME_V);
			friend	bool			operator	<=	(const signed int, NAME_V);
			friend	bool			operator	<=	(const unsigned int, NAME_V);
			friend	bool			operator	<=	(const signed long int, NAME_V);
			friend	bool			operator	<=	(const unsigned long int, NAME_V);
			friend	bool			operator	<=	(const signed long long int, NAME_V);
			friend	bool			operator	<=	(const unsigned long long int, NAME_V);
			friend	bool			operator	<=	(const float, NAME_V);
			friend	bool			operator	<=	(const double, NAME_V);
			friend	bool			operator	<=	(const long double, NAME_V);
			friend	bool			operator	<=	(const char, NAME_V);
			//friend	bool			operator	<=	(const signed char, NAME_V);
			//friend	bool			operator	<=	(const unsigned char, NAME_V);
			friend	bool			operator	<=	(const ::std::string, NAME_V);

					bool			operator	>=	(const NAME_V);
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

			friend	bool			operator	>=	(const signed short int, NAME_V);
			friend	bool			operator	>=	(const unsigned short int, NAME_V);
			friend	bool			operator	>=	(const signed int, NAME_V);
			friend	bool			operator	>=	(const unsigned int, NAME_V);
			friend	bool			operator	>=	(const signed long int, NAME_V);
			friend	bool			operator	>=	(const unsigned long int, NAME_V);
			friend	bool			operator	>=	(const signed long long int, NAME_V);
			friend	bool			operator	>=	(const unsigned long long int, NAME_V);
			friend	bool			operator	>=	(const float, NAME_V);
			friend	bool			operator	>=	(const double, NAME_V);
			friend	bool			operator	>=	(const long double, NAME_V);
			friend	bool			operator	>=	(const char, NAME_V);
			//friend	bool			operator	>=	(const signed char, NAME_V);
			//friend	bool			operator	>=	(const unsigned char, NAME_V);
			friend	bool			operator	>=	(const ::std::string, NAME_V);

					bool			operator	&&	(const NAME_V);
					bool			operator	&&	(const bool);
			friend	bool			operator	&&	(const bool, NAME_V);
					bool			operator	||	(const NAME_V);
					bool			operator	||	(const bool);
			friend	bool			operator	||	(const bool, NAME_V);

			// Prefix:
			//friend		NAME_V &		operator	++	(NAME_V &);
			//friend		NAME_V &		operator	--	(NAME_V &);
						/*const*/ NAME_V	&	operator	++	(void);
						/*const*/ NAME_V	&	operator	--	(void);
			// Suffix / Postfix:
						//NAME_V &		operator	++	(void);
						//NAME_V &		operator	--	(void);
						/*const*/ NAME_V		operator	++	(signed int);
						/*const*/ NAME_V		operator	--	(signed int);
	};
	}
	
	//typedef NAME_V var;
	//typedef containers::NAME_V NAME_V, var;
}

std::istream &	getline (std::istream &, LIB::containers::NAME_V &, const char = '\n');

std::string		tolower (const LIB::containers::NAME_V &);
std::string		toupper (const LIB::containers::NAME_V &);

//#endif
