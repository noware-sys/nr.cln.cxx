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

//#include "HPC.h"

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0610
#endif _WIN32_WINNT

#ifndef _Any
#define _Any

namespace Any
{
	//std::fstream f;
	//typedef long double Number;
	struct Container
	{
		std::string	Generic;
		long double	Numeric;
		bool		Boolean;
	};

	bool is_numeric (const std::string);	// Determines if a string is a number in base 10.
	bool is_boolean (const std::string);
	//bool stobool (const std::string);
	//long double ston (const std::string);	// Converts a string to a long long double number, positive or negative.
	//std::string tolower (const std::string);

	namespace Default
	{
		static const std::string			GENERIC	= "";
		static const unsigned short int		NUMERIC	= 0;
		static const bool					BOOLEAN	= false;
	}

	static const enum Type {GENERIC, BOOLEAN, NUMERIC};

	Type Determine (const Any::Any);
	Type Determine (const std::string);
	Type Determine (const long double);

	class Any
	{
		private:
			Container value;
			// Default values:
			Type type;	// The type of value currently being stored.
			//std::string value;

			void Assign (/*Container &, */const std::string);
			void Assign (/*Container &, */const long double);

			std::string	to_string (void) const;
		public:
			Any (void);

			bool	Is_Generic	(void);
			bool	Is_Numeric	(void);
			bool	Is_Boolean	(void);

			std::string	To_String	(void);
			long double	To_Number	(void);
			bool		To_Boolean	(void);

			// Operations for the same type:
	friend	Any				operator	+	(const Any, const Any);
	friend	long double		operator	+	(const Any, const bool);
	friend	long double		operator	+	(const Any, const signed short int);
	friend	long double		operator	+	(const Any, const unsigned short int);
	friend	long double		operator	+	(const Any, const signed int);
	friend	long double		operator	+	(const Any, const unsigned int);
	friend	long double		operator	+	(const Any, const signed long int);
	friend	long double		operator	+	(const Any, const unsigned long int);
	friend	long double		operator	+	(const Any, const signed long long int);
	friend	long double		operator	+	(const Any, const unsigned long long int);
	friend	long double		operator	+	(const Any, const float);
	friend	long double		operator	+	(const Any, const double);
	friend	long double		operator	+	(const Any, const long double);
	friend	std::string		operator	+	(const Any, const signed char);
	friend	std::string		operator	+	(const Any, const unsigned char);
	friend	std::string		operator	+	(const Any, const std::string);

	friend	long double		operator	+	(const signed short int, const Any);
	friend	long double		operator	+	(const bool, const Any);
	friend	long double		operator	+	(const unsigned short int, const Any);
	friend	long double		operator	+	(const signed int, const Any);
	friend	long double		operator	+	(const unsigned int, const Any);
	friend	long double		operator	+	(const signed long int, const Any);
	friend	long double		operator	+	(const unsigned long int, const Any);
	friend	long double		operator	+	(const signed long long int, const Any);
	friend	long double		operator	+	(const unsigned long long int, const Any);
	friend	long double		operator	+	(const float, const Any);
	friend	long double		operator	+	(const double, const Any);
	friend	long double		operator	+	(const long double, const Any);
	friend	std::string		operator	+	(const signed char, const Any);
	friend	std::string		operator	+	(const unsigned char, const Any);
	friend	std::string		operator	+	(const std::string, const Any);

	friend	long double		operator	-	(const Any, const Any);
	friend	signed int		operator	-	(const Any, const bool);
	friend	long double		operator	-	(const Any, const signed short int);
	friend	long double		operator	-	(const Any, const unsigned short int);
	friend	long double		operator	-	(const Any, const signed int);
	friend	long double		operator	-	(const Any, const unsigned int);
	friend	long double		operator	-	(const Any, const signed long int);
	friend	long double		operator	-	(const Any, const unsigned long int);
	friend	long double		operator	-	(const Any, const signed long long int);
	friend	long double		operator	-	(const Any, const unsigned long long int);
	friend	long double		operator	-	(const Any, const float);
	friend	long double		operator	-	(const Any, const double);
	friend	long double		operator	-	(const Any, const long double);

	friend	long double		operator	-	(const signed short int, const Any);
	friend	signed int		operator	-	(const bool, const Any);
	friend	long double		operator	-	(const unsigned short int, const Any);
	friend	long double		operator	-	(const signed int, const Any);
	friend	long double		operator	-	(const unsigned int, const Any);
	friend	long double		operator	-	(const signed long int, const Any);
	friend	long double		operator	-	(const unsigned long int, const Any);
	friend	long double		operator	-	(const signed long long int, const Any);
	friend	long double		operator	-	(const unsigned long long int, const Any);
	friend	long double		operator	-	(const float, const Any);
	friend	long double		operator	-	(const double, const Any);
	friend	long double		operator	-	(const long double, const Any);

	friend	Any				operator	*	(const Any, const Any);
	friend	long double		operator	*	(const Any, const signed short int);
	friend	long double		operator	*	(const Any, const unsigned short int);
	friend	long double		operator	*	(const Any, const signed int);
	friend	long double		operator	*	(const Any, const unsigned int);
	friend	long double		operator	*	(const Any, const signed long int);
	friend	long double		operator	*	(const Any, const unsigned long int);
	friend	long double		operator	*	(const Any, const signed long long int);
	friend	long double		operator	*	(const Any, const unsigned long long int);
	friend	long double		operator	*	(const Any, const float);
	friend	long double		operator	*	(const Any, const double);
	friend	long double		operator	*	(const Any, const long double);

	friend	long double		operator	*	(const signed short int, const Any);
	friend	long double		operator	*	(const unsigned short int, const Any);
	friend	long double		operator	*	(const signed int, const Any);
	friend	long double		operator	*	(const unsigned int, const Any);
	friend	long double		operator	*	(const signed long int, const Any);
	friend	long double		operator	*	(const unsigned long int, const Any);
	friend	long double		operator	*	(const signed long long int, const Any);
	friend	long double		operator	*	(const unsigned long long int, const Any);
	friend	long double		operator	*	(const float, const Any);
	friend	long double		operator	*	(const double, const Any);
	friend	long double		operator	*	(const long double, const Any);

	friend	long double		operator	/	(const Any, const Any);
	friend	long double		operator	/	(const Any, const signed short int);
	friend	long double		operator	/	(const Any, const unsigned short int);
	friend	long double		operator	/	(const Any, const signed int);
	friend	long double		operator	/	(const Any, const unsigned int);
	friend	long double		operator	/	(const Any, const signed long int);
	friend	long double		operator	/	(const Any, const unsigned long int);
	friend	long double		operator	/	(const Any, const signed long long int);
	friend	long double		operator	/	(const Any, const unsigned long long int);
	friend	long double		operator	/	(const Any, const float);
	friend	long double		operator	/	(const Any, const double);
	friend	long double		operator	/	(const Any, const long double);

	friend	long double		operator	/	(const signed short int, const Any);
	friend	long double		operator	/	(const unsigned short int, const Any);
	friend	long double		operator	/	(const signed int, const Any);
	friend	long double		operator	/	(const unsigned int, const Any);
	friend	long double		operator	/	(const signed long int, const Any);
	friend	long double		operator	/	(const unsigned long int, const Any);
	friend	long double		operator	/	(const signed long long int, const Any);
	friend	long double		operator	/	(const unsigned long long int, const Any);
	friend	long double		operator	/	(const float, const Any);
	friend	long double		operator	/	(const double, const Any);
	friend	long double		operator	/	(const long double, const Any);
	
	friend	unsigned int	operator	%	(const Any, const Any);
	friend	unsigned int	operator	%	(const Any, const signed short int);
	friend	unsigned int	operator	%	(const Any, const unsigned short int);
	friend	unsigned int	operator	%	(const Any, const signed int);
	friend	unsigned int	operator	%	(const Any, const unsigned int);
	friend	unsigned int	operator	%	(const Any, const signed long int);
	friend	unsigned int	operator	%	(const Any, const unsigned long int);
	friend	unsigned int	operator	%	(const Any, const signed long long int);
	friend	unsigned int	operator	%	(const Any, const unsigned long long int);
	friend	unsigned int	operator	%	(const Any, const float);
	friend	unsigned int	operator	%	(const Any, const double);
	friend	unsigned int	operator	%	(const Any, const long double);

	friend	long double		operator	%	(const signed short int, const Any);
	friend	long double		operator	%	(const unsigned short int, const Any);
	friend	long double		operator	%	(const signed int, const Any);
	friend	long double		operator	%	(const unsigned int, const Any);
	friend	long double		operator	%	(const signed long int, const Any);
	friend	long double		operator	%	(const unsigned long int, const Any);
	friend	long double		operator	%	(const signed long long int, const Any);
	friend	long double		operator	%	(const unsigned long long int, const Any);
	friend	long double		operator	%	(const float, const Any);
	friend	long double		operator	%	(const double, const Any);
	friend	long double		operator	%	(const long double, const Any);
			
	// ^ represents exponentiation.
	friend	long double		operator	^	(const Any, const Any);
	friend	long double		operator	^	(const Any, const signed short int);
	friend	long double		operator	^	(const Any, const unsigned short int);
	friend	long double		operator	^	(const Any, const signed int);
	friend	long double		operator	^	(const Any, const unsigned int);
	friend	long double		operator	^	(const Any, const signed long int);
	friend	long double		operator	^	(const Any, const unsigned long int);
	friend	long double		operator	^	(const Any, const signed long long int);
	friend	long double		operator	^	(const Any, const unsigned long long int);
	friend	long double		operator	^	(const Any, const float);
	friend	long double		operator	^	(const Any, const double);
	friend	long double		operator	^	(const Any, const long double);

	friend	long double		operator	^	(const signed short int, const Any);
	friend	long double		operator	^	(const unsigned short int, const Any);
	friend	long double		operator	^	(const signed int, const Any);
	friend	long double		operator	^	(const unsigned int, const Any);
	friend	long double		operator	^	(const signed long int, const Any);
	friend	long double		operator	^	(const unsigned long int, const Any);
	friend	long double		operator	^	(const signed long long int, const Any);
	friend	long double		operator	^	(const unsigned long long int, const Any);
	friend	long double		operator	^	(const float, const Any);
	friend	long double		operator	^	(const double, const Any);
	friend	long double		operator	^	(const long double, const Any);
			
			bool			operator	!	(void);
			
			void			operator	=	(const Any);
			void			operator	=	(const bool);
			void			operator	=	(const signed short int);
			void			operator	=	(const unsigned short int);
			void			operator	=	(const signed int);
			void			operator	=	(const unsigned int);
			void			operator	=	(const signed long int);
			void			operator	=	(const unsigned long int);
			void			operator	=	(const signed long long int);
			void			operator	=	(const unsigned long long int);
			void			operator	=	(const float);
			void			operator	=	(const double);
			void			operator	=	(const long double);
			void			operator	=	(const signed char);
			void			operator	=	(const unsigned char);
			void			operator	=	(const std::string);
	//friend	void			operator	=	(const signed short int, const Any);
	//friend	void			operator	=	(const unsigned short int, const Any);
	//friend	void			operator	=	(const signed int, const Any);
	//friend	void			operator	=	(const unsigned int, const Any);
	//friend	void			operator	=	(const signed long int, const Any);
	//friend	void			operator	=	(const unsigned long int, const Any);
	//friend	void			operator	=	(const signed long long int, const Any);
	//friend	void			operator	=	(const unsigned long long int, const Any);
	//friend	void			operator	=	(const float, const Any);
	//friend	void			operator	=	(const double, const Any);
	//friend	void			operator	=	(const long double, const Any);
	friend	Any				operator	<	(const Any, const Any);
	friend	long double		operator	<	(const Any, const signed short int);
	friend	long double		operator	<	(const Any, const unsigned short int);
	friend	long double		operator	<	(const Any, const signed int);
	friend	long double		operator	<	(const Any, const unsigned int);
	friend	long double		operator	<	(const Any, const signed long int);
	friend	long double		operator	<	(const Any, const unsigned long int);
	friend	long double		operator	<	(const Any, const signed long long int);
	friend	long double		operator	<	(const Any, const unsigned long long int);
	friend	long double		operator	<	(const Any, const float);
	friend	long double		operator	<	(const Any, const double);
	friend	long double		operator	<	(const Any, const long double);
	friend	std::string		operator	<	(const Any, const signed char);
	friend	std::string		operator	<	(const Any, const unsigned char);
	friend	std::string		operator	<	(const Any, const std::string);

	friend	long double		operator	<	(const signed short int, const Any);
	friend	long double		operator	<	(const unsigned short int, const Any);
	friend	long double		operator	<	(const signed int, const Any);
	friend	long double		operator	<	(const unsigned int, const Any);
	friend	long double		operator	<	(const signed long int, const Any);
	friend	long double		operator	<	(const unsigned long int, const Any);
	friend	long double		operator	<	(const signed long long int, const Any);
	friend	long double		operator	<	(const unsigned long long int, const Any);
	friend	long double		operator	<	(const float, const Any);
	friend	long double		operator	<	(const double, const Any);
	friend	long double		operator	<	(const long double, const Any);
	friend	std::string		operator	<	(const signed char, const Any);
	friend	std::string		operator	<	(const unsigned char, const Any);
	friend	std::string		operator	<	(const std::string, const Any);
			
			bool			operator	>	(const Any);
			bool			operator	>	(const signed short int);
			bool			operator	>	(const unsigned short int);
			bool			operator	>	(const signed int);
			bool			operator	>	(const unsigned int);
			bool			operator	>	(const signed long int);
			bool			operator	>	(const unsigned long int);
			bool			operator	>	(const signed long long int);
			bool			operator	>	(const unsigned long long int);
			bool			operator	>	(const float);
			bool			operator	>	(const double);
			bool			operator	>	(const long double);
			bool			operator	>	(const signed char);
			bool			operator	>	(const unsigned char);
			Any				operator	+=	(const Any);
			long double		operator	+=	(const signed short int);
			long double		operator	+=	(const unsigned short int);
			long double		operator	+=	(const signed int);
			long double		operator	+=	(const unsigned int);
			long double		operator	+=	(const signed long int);
			long double		operator	+=	(const unsigned long int);
			long double		operator	+=	(const signed long long int);
			long double		operator	+=	(const unsigned long long int);
			long double		operator	+=	(const float);
			long double		operator	+=	(const double);
			long double		operator	+=	(const long double);
			std::string		operator	+=	(const std::string);
			long double		operator	-=	(const Any);
			long double		operator	-=	(const signed short int);
			long double		operator	-=	(const unsigned short int);
			long double		operator	-=	(const signed int);
			long double		operator	-=	(const unsigned int);
			long double		operator	-=	(const signed long int);
			long double		operator	-=	(const unsigned long int);
			long double		operator	-=	(const signed long long int);
			long double		operator	-=	(const unsigned long long int);
			long double		operator	-=	(const float);
			long double		operator	-=	(const double);
			long double		operator	-=	(const long double);
			long double		operator	*=	(const Any);
			long double		operator	*=	(const signed short int);
			long double		operator	*=	(const unsigned short int);
			long double		operator	*=	(const signed int);
			long double		operator	*=	(const unsigned int);
			long double		operator	*=	(const signed long int);
			long double		operator	*=	(const unsigned long int);
			long double		operator	*=	(const signed long long int);
			long double		operator	*=	(const unsigned long long int);
			long double		operator	*=	(const float);
			long double		operator	*=	(const double);
			long double		operator	*=	(const long double);
			long double		operator	/=	(const Any);
			long double		operator	/=	(const signed short int);
			long double		operator	/=	(const unsigned short int);
			long double		operator	/=	(const signed int);
			long double		operator	/=	(const unsigned int);
			long double		operator	/=	(const signed long int);
			long double		operator	/=	(const unsigned long int);
			long double		operator	/=	(const signed long long int);
			long double		operator	/=	(const unsigned long long int);
			long double		operator	/=	(const float);
			long double		operator	/=	(const double);
			long double		operator	/=	(const long double);
			unsigned int	operator	%=	(const Any);
			unsigned int	operator	%=	(const signed short int);
			unsigned int	operator	%=	(const unsigned short int);
			unsigned int	operator	%=	(const signed int);
			unsigned int	operator	%=	(const unsigned int);
			unsigned int	operator	%=	(const signed long int);
			unsigned int	operator	%=	(const unsigned long int);
			unsigned int	operator	%=	(const signed long long int);
			unsigned int	operator	%=	(const unsigned long long int);
			unsigned int	operator	%=	(const float);
			unsigned int	operator	%=	(const double);
			unsigned int	operator	%=	(const long double);
			long double		operator	^=	(const Any);
			long double		operator	^=	(const signed short int);
			long double		operator	^=	(const unsigned short int);
			long double		operator	^=	(const signed int);
			long double		operator	^=	(const unsigned int);
			long double		operator	^=	(const signed long int);
			long double		operator	^=	(const unsigned long int);
			long double		operator	^=	(const signed long long int);
			long double		operator	^=	(const unsigned long long int);
			long double		operator	^=	(const float);
			long double		operator	^=	(const double);
			long double		operator	^=	(const long double);

	friend	std::ostream &	operator	<<	(std::ostream &, Any);
	//friend	std::istream &	operator	>>	(std::istream &, const Any &);
			
			//friend std::ofstream & operator<<	(std::ofstream &, const Any &);
			//friend std::ifstream & operator>>	(std::ifstream &, const Any &);
			bool			operator	==	(const Any);
			bool			operator	==	(const bool);
			bool			operator	==	(const signed short int);
			bool			operator	==	(const unsigned short int);
			bool			operator	==	(const signed int);
			bool			operator	==	(const unsigned int);
			bool			operator	==	(const signed long int);
			bool			operator	==	(const unsigned long int);
			bool			operator	==	(const signed long long int);
			bool			operator	==	(const unsigned long long int);
			bool			operator	==	(const float);
			bool			operator	==	(const double);
			bool			operator	==	(const long double);
			bool			operator	==	(const signed char);
			bool			operator	==	(const unsigned char);
			bool			operator	==	(const std::string);
			bool			operator	!=	(const Any);
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
			bool			operator	!=	(const signed char);
			bool			operator	!=	(const unsigned char);
			bool			operator	!=	(const std::string);
			bool			operator	<=	(const Any);
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
			bool			operator	<=	(const signed char);
			bool			operator	<=	(const unsigned char);
			bool			operator	<=	(const long double);
			bool			operator	>=	(const Any);
			bool			operator	>=	(const bool);
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
			bool			operator	>=	(const signed char);
			bool			operator	>=	(const unsigned char);

	friend	bool			operator	&&	(const Any, const Any);
	friend	bool			operator	&&	(const Any, const bool);
	friend	bool			operator	&&	(const bool, const Any);

			bool			operator	||	(const Any);
			bool			operator	||	(const bool);

			long double		operator	++	(const signed int);
			long double		operator	--	(const signed int);
			//std::string		operator	,	(const Any);
			//std::string		operator	,	(const signed short int);
			//std::string		operator	,	(const unsigned short int);
			//std::string		operator	,	(const signed int);
			//std::string		operator	,	(const unsigned int);
			//std::string		operator	,	(const signed long int);
			//std::string		operator	,	(const unsigned long int);
			//std::string		operator	,	(const signed long long int);
			//std::string		operator	,	(const unsigned long long int);
			//std::string		operator	,	(const std::string);


			//friend std::string	&	operator=	(std::string &, Any);

			// bool std::string::operator== (Any); // Will this work?
			/*
				To do:

				Any <comparison> string
				Any <comparison> string

				(string <comparison> Any)?
			*/
	};
}
#endif _Any