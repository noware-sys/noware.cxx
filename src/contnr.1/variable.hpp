#ifndef VARIABLE
#define VARIABLE

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

#include "../default.hpp"
#include "../utilities.hpp"

#ifndef NAME_V
#define NAME_V variable
#endif NAME_V

namespace LIB
{
	class NAME_V;

	typedef NAME_V var;

	class NAME_V
	{
		public:
			static const enum type
			{
				GENERIC,
				NUMERIC
			};

			struct container
			{
				::std::string	Generic;
				mathematics::numbers::real numeric;
			};

		protected:
		//private:
			container value;
			// Default values:
			type _type;	// The type of value currently being stored.
			//::std::string value;

			//void Assign (/*Container &, */const ::std::string);
			//void Assign (/*Container &, */const mathematics::numbers::real);

			//::std::string	to_string (void) const;

			//_type Determine (const NAME_V::NAME_V);
			type determine (const ::std::string &) const;
			//_type Determine (const mathematics::numbers::real);

		public:
			type determine (void) const;

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
			NAME_V (const mathematics::numbers::real &);
			NAME_V (const char &);
			//NAME_V (const signed char &);
			//NAME_V (const unsigned char &);
			NAME_V (const ::std::string &);

			NAME_V (const char []);

			//~NAME_V (void);
			//_type GetType (void);

			//bool		GetValueBoolean (void);
			//mathematics::numbers::real	GetValueNumeric (void);
			//::std::string	GetValueGeneric (void);

			//::std::istream	&	getline (::std::istream &, const ::std::string = "\n");
			//::std::istream	&	getline (::std::istream &, const unsigned int, const ::std::string = "\n");
			//::std::istream	&	getline (::std::istream &, const unsigned int);

			//bool	Is_Generic	(void);
			//bool	Is_Numeric	(void);
			//bool	Is_Boolean	(void);

			// Returns a string representation of the content, whatever type it may be.
			//::std::string						to_string		(void) const;

			// returns the numeric value if the content is a number, or the default numerical value otherwise.
			//mathematics::numbers::real		to_number	(void);
			//bool		to_boolean	(void);
			mathematics::numbers::natural	length		(void) const;

			//bool is_generic (void) const;
			//bool is_numeric (void) const;

			// Operations for the same type:
			// NAME_V + Something
					NAME_V		operator	+	(const NAME_V &);
					//mathematics::numbers::real		operator	+	(const bool);
					NAME_V		operator	+	(const signed short int &);
					NAME_V		operator	+	(const unsigned short int &);
					NAME_V		operator	+	(const signed int &);
					NAME_V		operator	+	(const unsigned int &);
					NAME_V		operator	+	(const signed long int &);
					NAME_V		operator	+	(const unsigned long int &);
					NAME_V		operator	+	(const signed long long int &);
					NAME_V		operator	+	(const unsigned long long int &);
					NAME_V		operator	+	(const float &);
					NAME_V		operator	+	(const double &);
					NAME_V		operator	+	(const mathematics::numbers::real &);
					NAME_V		operator	+	(const char &);
					//NAME_V		operator	+	(const signed char);
					//NAME_V		operator	+	(const unsigned char);
					NAME_V		operator	+	(const ::std::string &);
			// Something + NAME_V
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const unsigned int);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const signed long int);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const unsigned long int);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const signed long long int);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const unsigned long long int);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const float);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const double);
			//friend	mathematics::numbers::real		operator	+	(const NAME_V, const mathematics::numbers::real);
			//friend	::std::string		operator	+	(const NAME_V, const signed char);
			//friend	::std::string		operator	+	(const NAME_V, const unsigned char);
			//friend	::std::string		operator	+	(const NAME_V, const ::std::string);

			//friend	mathematics::numbers::real		operator	+	(const bool, const NAME_V);
			friend	NAME_V		operator	+	(const signed short int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned short int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const signed long long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const unsigned long long int &, const NAME_V &);
			friend	NAME_V		operator	+	(const float &, const NAME_V &);
			friend	NAME_V		operator	+	(const double &, const NAME_V &);
			friend	NAME_V		operator	+	(const mathematics::numbers::real &, const NAME_V &);
			friend	NAME_V		operator	+	(const char &, const NAME_V &);
			//friend	NAME_V		operator	+	(const signed char, NAME_V);
			//friend	NAME_V		operator	+	(const unsigned char, NAME_V);
			friend	NAME_V		operator	+	(const ::std::string &, const NAME_V &);

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
					NAME_V		operator	-	(const mathematics::numbers::real &);
					NAME_V		operator	-	(const char &);
					//NAME_V		operator	-	(const char);
					//NAME_V		operator	-	(const signed char);
					//NAME_V		operator	-	(const unsigned char);
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
			friend	NAME_V		operator	-	(const mathematics::numbers::real &, const NAME_V &);

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
					NAME_V		operator	*	(const mathematics::numbers::real &);
					NAME_V		operator	*	(const char &);
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
			friend	NAME_V		operator	*	(const mathematics::numbers::real &, NAME_V &);

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
					NAME_V		operator	/	(const mathematics::numbers::real &);
					NAME_V		operator	/	(const char &);
					NAME_V		operator	/	(const ::std::string &);

			friend	mathematics::numbers::real		operator	/	(const signed short int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const unsigned short int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const signed int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const unsigned int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const signed long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const unsigned long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const signed long long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const unsigned long long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const float &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const double &, const NAME_V &);
			friend	mathematics::numbers::real		operator	/	(const mathematics::numbers::real &, const NAME_V &);
		
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
					NAME_V		operator	%	(const mathematics::numbers::real &);
					NAME_V		operator	%	(const char &);
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
			friend	signed long long int		operator	%	(const mathematics::numbers::real &, const NAME_V &);
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
					mathematics::numbers::real		operator	^	(const NAME_V &);
					mathematics::numbers::real		operator	^	(const signed short int &);
					mathematics::numbers::real		operator	^	(const unsigned short int &);
					mathematics::numbers::real		operator	^	(const signed int &);
					mathematics::numbers::real		operator	^	(const unsigned int &);
					mathematics::numbers::real		operator	^	(const signed long int &);
					mathematics::numbers::real		operator	^	(const unsigned long int &);
					mathematics::numbers::real		operator	^	(const signed long long int &);
					mathematics::numbers::real		operator	^	(const unsigned long long int &);
					mathematics::numbers::real		operator	^	(const float &);
					mathematics::numbers::real		operator	^	(const double &);
					mathematics::numbers::real		operator	^	(const mathematics::numbers::real &);
					mathematics::numbers::real		operator	^	(const char &);
					mathematics::numbers::real		operator	^	(const ::std::string &);

			friend	mathematics::numbers::real		operator	^	(const signed short int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const unsigned short int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const signed int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const unsigned int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const signed long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const unsigned long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const signed long long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const unsigned long long int &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const float &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const double &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const char &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const ::std::string &, const NAME_V &);
			friend	mathematics::numbers::real		operator	^	(const mathematics::numbers::real &, const NAME_V &);

					// Conversion function:
					operator	NAME_V						(void) const;
					operator	bool						(void) const;
					operator	mathematics::numbers::real	(void) const;
					operator	::std::string				(void) const;

					//bool		NAME_V			(void);
					NAME_V		operator	~	(void) const;
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
					NAME_V &			operator	=	(const mathematics::numbers::real &);
					NAME_V &			operator	=	(const char &);
					//NAME_V &			operator	=	(const signed char);
					//NAME_V &			operator	=	(const unsigned char);
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
			//friend	void			operator	=	(const mathematics::numbers::real, NAME_V);
			//friend	void			operator	=	(const char, NAME_V);
			//friend	void			operator	=	(const signed char, NAME_V);
			//friend	void			operator	=	(const unsigned char, NAME_V);
			//friend	void			operator	=	(const ::std::string, NAME_V);

					bool			operator	<	(const NAME_V &);
					bool			operator	<	(const signed short int &);
					bool			operator	<	(const unsigned short int &);
					bool			operator	<	(const signed int &);
					bool			operator	<	(const unsigned int &);
					bool			operator	<	(const signed long int &);
					bool			operator	<	(const unsigned long int &);
					bool			operator	<	(const signed long long int &);
					bool			operator	<	(const unsigned long long int &);
					bool			operator	<	(const float &);
					bool			operator	<	(const double &);
					bool			operator	<	(const mathematics::numbers::real &);
					bool			operator	<	(const char &);
					//bool			operator	<	(const signed char);
					//bool			operator	<	(const unsigned char);
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
			friend	bool			operator	<	(const mathematics::numbers::real &, NAME_V &);
			friend	bool			operator	<	(const char &, NAME_V &);
			//friend	bool			operator	<	(const signed char, NAME_V);
			//friend	bool			operator	<	(const unsigned char, NAME_V);
			friend	bool			operator	<	(const ::std::string &, NAME_V &);

					bool			operator	>	(const NAME_V &);
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
					bool			operator	>	(const mathematics::numbers::real &);
					bool			operator	>	(const char &);
					//bool			operator	>	(const signed char);
					//bool			operator	>	(const unsigned char);
					bool			operator	>	(const ::std::string &);

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
			friend	bool			operator	>	(const mathematics::numbers::real &, NAME_V &);
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
					NAME_V	&		operator	+=	(const mathematics::numbers::real &);
					NAME_V	&		operator	+=	(const char &);
					//NAME_V				operator	+=	(const signed char);
					//NAME_V				operator	+=	(const unsigned char);
					NAME_V	&		operator	+=	(const ::std::string &);

			friend	mathematics::numbers::real			operator	+=	(const signed short int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const unsigned short int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const signed int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const unsigned int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const signed long int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const unsigned long int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const signed long long int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const unsigned long long int &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const float &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const double &, NAME_V &);
			friend	mathematics::numbers::real			operator	+=	(const mathematics::numbers::real, NAME_V);
			//friend	::std::string							operator	+=	(const char, const NAME_V);
			friend	::std::string &							operator	+=	(::std::string &, const NAME_V &);

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
					NAME_V	&		operator	-=	(const mathematics::numbers::real);
					NAME_V	&		operator	-=	(const char);
					NAME_V	&		operator	-=	(const ::std::string);

			friend	mathematics::numbers::real			operator	-=	(const signed short int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const unsigned short int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const signed int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const unsigned int, NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const signed long int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const unsigned long int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const signed long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const unsigned long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const float, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const double, const NAME_V);
			friend	mathematics::numbers::real			operator	-=	(const mathematics::numbers::real, NAME_V);

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
					NAME_V	&		operator	*=	(const mathematics::numbers::real);
		
			friend	mathematics::numbers::real			operator	*=	(const signed short int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const unsigned short int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const signed int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const unsigned int, NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const signed long int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const unsigned long int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const signed long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const unsigned long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const float, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(const double, const NAME_V);
			friend	mathematics::numbers::real			operator	*=	(mathematics::numbers::real, NAME_V);

					NAME_V	&		operator	/=	(const NAME_V);
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
					NAME_V	&		operator	/=	(const mathematics::numbers::real);
					::std::string		operator	/=	(const char);
					::std::string		operator	/=	(const ::std::string);

			friend	mathematics::numbers::real			operator	/=	(const signed short int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const unsigned short int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const signed int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const unsigned int, NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const signed long int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const unsigned long int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const signed long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const unsigned long long int, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const float, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const double, const NAME_V);
			friend	mathematics::numbers::real			operator	/=	(const mathematics::numbers::real, NAME_V);

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
					NAME_V		operator	%=	(const mathematics::numbers::real);
					NAME_V		operator	%=	(const char);
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
			friend	signed long long int		operator	%=	(mathematics::numbers::real &, const NAME_V);
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
					NAME_V		operator	^=	(const mathematics::numbers::real);
					NAME_V		operator	^=	(const char);
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
			friend	signed long long int		operator	^=	(mathematics::numbers::real &, const NAME_V);

			friend	::std::ostream &	operator	<<	(::std::ostream &, const NAME_V);
			friend	::std::istream &	operator	>>	(::std::istream &, NAME_V &);
	
			//friend	::std::ofstream &	operator	<<	(::std::ofstream &, NAME_V);
			//friend	::std::ifstream &	operator	>>	(::std::ifstream &, NAME_V);

					bool			operator	==	(const NAME_V);
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
					bool			operator	==	(const mathematics::numbers::real);
					bool			operator	==	(const char);
					//bool			operator	==	(const signed char);
					//bool			operator	==	(const unsigned char);
					bool			operator	==	(const ::std::string);
				
			friend	bool			operator	==	(const bool, NAME_V);
			friend	bool			operator	==	(const signed short int, NAME_V);
			friend	bool			operator	==	(const unsigned short int, NAME_V);
			friend	bool			operator	==	(const signed int, NAME_V);
			friend	bool			operator	==	(const unsigned int, NAME_V);
			friend	bool			operator	==	(const signed long int, NAME_V);
			friend	bool			operator	==	(const unsigned long int, NAME_V);
			friend	bool			operator	==	(const signed long long int, NAME_V);
			friend	bool			operator	==	(const unsigned long long int, NAME_V);
			friend	bool			operator	==	(const float, NAME_V);
			friend	bool			operator	==	(const double, NAME_V);
			friend	bool			operator	==	(const mathematics::numbers::real, NAME_V);
			friend	bool			operator	==	(const char, NAME_V);
			//friend	bool			operator	==	(const signed char, NAME_V);
			//friend	bool			operator	==	(const unsigned char, NAME_V);
			friend	bool			operator	==	(const ::std::string, NAME_V);

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
					bool			operator	!=	(const mathematics::numbers::real);
					bool			operator	!=	(const char);
					//bool			operator	!=	(const signed char);
					//bool			operator	!=	(const unsigned char);
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
			friend	bool			operator	!=	(const mathematics::numbers::real, NAME_V);
			friend	bool			operator	!=	(const char, NAME_V);
			//friend	bool			operator	!=	(const signed char, NAME_V);
			//friend	bool			operator	!=	(const unsigned char, NAME_V);
			friend	bool			operator	!=	(const ::std::string, NAME_V);

					bool			operator	<=	(const NAME_V);
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
					bool			operator	<=	(const mathematics::numbers::real);
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
			friend	bool			operator	<=	(const mathematics::numbers::real, NAME_V);
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
					bool			operator	>=	(const mathematics::numbers::real);
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
			friend	bool			operator	>=	(const mathematics::numbers::real, NAME_V);
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
			// Postfix / Suffix:
						//NAME_V &		operator	++	(void);
						//NAME_V &		operator	--	(void);
						/*const*/ NAME_V		operator	++	(signed int);
						/*const*/ NAME_V		operator	--	(signed int);
	};
}

::std::istream &	getline (::std::istream &, LIB::NAME_V &, const char = '\n');

::std::string		tolower (const LIB::NAME_V &);
::std::string		toupper (const LIB::NAME_V &);

#endif VARIABLE
