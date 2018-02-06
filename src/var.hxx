#pragma once

//#ifndef __VARIABLE
//#define __VARIABLE

//#include <boost/any.hpp>
#include <string>
#include <iostream>
//#include <fstream>
#include <climits>
#include <cfloat>
#include <cmath>

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
//#include <boost/operators.hpp>

//#include"../name.hxx"
// #include "text.hxx"
//#include "tool.hdr.cxx"
//#include "tool/.hxx"
//#include "content/value.hdr.cxx"
//#include "serial.hxx"
//#include "misc/serial.hxx"
#include <cln/nr.hxx>
#include "serial.hxx"
#include "tool/string.hxx"
#include ".var/.incl.hxx"

//#include ".var/incl.hxx"

//dynamic ~!= static
//constant ~!= variable

//#define BOOST_FORCE_SYMMETRIC_OPERATORS 1
/*
#ifndef NAME_V
	#define NAME_V var
#endif

#ifndef any
	#define any var
#endif
*/
namespace noware
{
	//class NAME_V;
	
	//typedef NAME_V var;
	// container cont ctn ctnr ctner
	//namespace container
	//{
		// type: fundamental primitive built-in intrinsic basic
		// (container of a value) all any/ne container/contnr val[ue] cat[egory] var[iable] [con]struct[ure] class obj[ect] it[e]m id[entifier]
		class var
			: virtual public noware::serial
			, virtual public boost::equality_comparable <var>
			, virtual public boost::equality_comparable <var, std::string>
			, virtual public boost::equality_comparable <var, cln::nr>
			, virtual public boost::equality_comparable <var, char *>
			, virtual public boost::equality_comparable <var, char>
		//	, virtual public boost::equality_comparable <var, unsigned char>
		//	, virtual public boost::equality_comparable <var, signed char>
			, virtual public boost::equality_comparable <var, cln::cl_N>
			, virtual public boost::equality_comparable <var, cln::cl_R>
			, virtual public boost::equality_comparable <var, cln::cl_RA>
			, virtual public boost::equality_comparable <var, cln::cl_I>
			, virtual public boost::equality_comparable <var, cln::cl_F>
			, virtual public boost::equality_comparable <var, cln::cl_SF>
			, virtual public boost::equality_comparable <var, cln::cl_FF>
			, virtual public boost::equality_comparable <var, cln::cl_DF>
			, virtual public boost::equality_comparable <var, cln::cl_LF>
			, virtual public boost::equality_comparable <var, long double>
			, virtual public boost::equality_comparable <var, double>
			, virtual public boost::equality_comparable <var, float>
			, virtual public boost::equality_comparable <var, unsigned long long int>
			, virtual public boost::equality_comparable <var, unsigned long int>
			, virtual public boost::equality_comparable <var, unsigned int>
			, virtual public boost::equality_comparable <var, unsigned short int>
			, virtual public boost::equality_comparable <var, signed long long int>
			, virtual public boost::equality_comparable <var, signed long int>
			, virtual public boost::equality_comparable <var, signed int>
			, virtual public boost::equality_comparable <var, signed short int>
			/*
			, virtual public boost::less_than_comparable <var>
			, virtual public boost::less_than_comparable <var, std::string>
			, virtual public boost::less_than_comparable <var, char *>
			, virtual public boost::less_than_comparable <var, char>
		//	, virtual public boost::less_than_comparable <var, unsigned char>
		//	, virtual public boost::less_than_comparable <var, signed char>
			, virtual public boost::less_than_comparable <var, cln::cl_N>
			, virtual public boost::less_than_comparable <var, cln::cl_R>
			, virtual public boost::less_than_comparable <var, cln::cl_RA>
			, virtual public boost::less_than_comparable <var, cln::cl_I>
			, virtual public boost::less_than_comparable <var, cln::cl_F>
			, virtual public boost::less_than_comparable <var, cln::cl_SF>
			, virtual public boost::less_than_comparable <var, cln::cl_FF>
			, virtual public boost::less_than_comparable <var, cln::cl_DF>
			, virtual public boost::less_than_comparable <var, cln::cl_LF>
			, virtual public boost::less_than_comparable <var, long double>
			, virtual public boost::less_than_comparable <var, double>
			, virtual public boost::less_than_comparable <var, float>
			, virtual public boost::less_than_comparable <var, unsigned long long int>
			, virtual public boost::less_than_comparable <var, unsigned long int>
			, virtual public boost::less_than_comparable <var, unsigned int>
			, virtual public boost::less_than_comparable <var, unsigned short int>
			, virtual public boost::less_than_comparable <var, signed long long int>
			, virtual public boost::less_than_comparable <var, signed long int>
			, virtual public boost::less_than_comparable <var, signed int>
			, virtual public boost::less_than_comparable <var, signed short int>
			*/
			, virtual public boost::addable <var>
			, virtual public boost::addable <var, std::string>
			, virtual public boost::addable <var, cln::nr>
			, virtual public boost::addable <var, char *>
			, virtual public boost::addable <var, char>
		//	, virtual public boost::addable <var, unsigned char>
		//	, virtual public boost::addable <var, signed char>
			, virtual public boost::addable <var, cln::cl_N>
			, virtual public boost::addable <var, cln::cl_R>
			, virtual public boost::addable <var, cln::cl_RA>
			, virtual public boost::addable <var, cln::cl_I>
			, virtual public boost::addable <var, cln::cl_F>
			, virtual public boost::addable <var, cln::cl_SF>
			, virtual public boost::addable <var, cln::cl_FF>
			, virtual public boost::addable <var, cln::cl_DF>
			, virtual public boost::addable <var, cln::cl_LF>
			, virtual public boost::addable <var, long double>
			, virtual public boost::addable <var, double>
			, virtual public boost::addable <var, float>
			, virtual public boost::addable <var, unsigned long long int>
			, virtual public boost::addable <var, unsigned long int>
			, virtual public boost::addable <var, unsigned int>
			, virtual public boost::addable <var, unsigned short int>
			, virtual public boost::addable <var, signed long long int>
			, virtual public boost::addable <var, signed long int>
			, virtual public boost::addable <var, signed int>
			, virtual public boost::addable <var, signed short int>
			, virtual public boost::subtractable <var>
			, virtual public boost::subtractable <var, std::string>
			, virtual public boost::subtractable <var, cln::nr>
			, virtual public boost::subtractable <var, char *>
			, virtual public boost::subtractable <var, char>
		//	, virtual public boost::subtractable <var, unsigned char>
		//	, virtual public boost::subtractable <var, signed char>
			, virtual public boost::subtractable <var, cln::cl_N>
			, virtual public boost::subtractable <var, cln::cl_R>
			, virtual public boost::subtractable <var, cln::cl_RA>
			, virtual public boost::subtractable <var, cln::cl_I>
			, virtual public boost::subtractable <var, cln::cl_F>
			, virtual public boost::subtractable <var, cln::cl_SF>
			, virtual public boost::subtractable <var, cln::cl_FF>
			, virtual public boost::subtractable <var, cln::cl_DF>
			, virtual public boost::subtractable <var, cln::cl_LF>
			, virtual public boost::subtractable <var, long double>
			, virtual public boost::subtractable <var, double>
			, virtual public boost::subtractable <var, float>
			, virtual public boost::subtractable <var, unsigned long long int>
			, virtual public boost::subtractable <var, unsigned long int>
			, virtual public boost::subtractable <var, unsigned int>
			, virtual public boost::subtractable <var, unsigned short int>
			, virtual public boost::subtractable <var, signed long long int>
			, virtual public boost::subtractable <var, signed long int>
			, virtual public boost::subtractable <var, signed int>
			, virtual public boost::subtractable <var, signed short int>
			, virtual public boost::subtractable2_left <var, std::string>
			, virtual public boost::subtractable2_left <var, cln::nr>
			, virtual public boost::subtractable2_left <var, char *>
			, virtual public boost::subtractable2_left <var, char>
		//	, virtual public boost::subtractable2_left <var, unsigned char>
		//	, virtual public boost::subtractable2_left <var, signed char>
			, virtual public boost::subtractable2_left <var, cln::cl_N>
			, virtual public boost::subtractable2_left <var, cln::cl_R>
			, virtual public boost::subtractable2_left <var, cln::cl_RA>
			, virtual public boost::subtractable2_left <var, cln::cl_I>
			, virtual public boost::subtractable2_left <var, cln::cl_F>
			, virtual public boost::subtractable2_left <var, cln::cl_SF>
			, virtual public boost::subtractable2_left <var, cln::cl_FF>
			, virtual public boost::subtractable2_left <var, cln::cl_DF>
			, virtual public boost::subtractable2_left <var, cln::cl_LF>
			, virtual public boost::subtractable2_left <var, long double>
			, virtual public boost::subtractable2_left <var, double>
			, virtual public boost::subtractable2_left <var, float>
			, virtual public boost::subtractable2_left <var, unsigned long long int>
			, virtual public boost::subtractable2_left <var, unsigned long int>
			, virtual public boost::subtractable2_left <var, unsigned int>
			, virtual public boost::subtractable2_left <var, unsigned short int>
			, virtual public boost::subtractable2_left <var, signed long long int>
			, virtual public boost::subtractable2_left <var, signed long int>
			, virtual public boost::subtractable2_left <var, signed int>
			, virtual public boost::subtractable2_left <var, signed short int>
			, virtual public boost::multipliable <var>
			, virtual public boost::multipliable <var, std::string>
			, virtual public boost::multipliable <var, cln::nr>
			, virtual public boost::multipliable <var, char *>
			, virtual public boost::multipliable <var, char>
		//	, virtual public boost::multipliable <var, unsigned char>
		//	, virtual public boost::multipliable <var, signed char>
			, virtual public boost::multipliable <var, cln::cl_N>
			, virtual public boost::multipliable <var, cln::cl_R>
			, virtual public boost::multipliable <var, cln::cl_RA>
			, virtual public boost::multipliable <var, cln::cl_I>
			, virtual public boost::multipliable <var, cln::cl_F>
			, virtual public boost::multipliable <var, cln::cl_SF>
			, virtual public boost::multipliable <var, cln::cl_FF>
			, virtual public boost::multipliable <var, cln::cl_DF>
			, virtual public boost::multipliable <var, cln::cl_LF>
			, virtual public boost::multipliable <var, long double>
			, virtual public boost::multipliable <var, double>
			, virtual public boost::multipliable <var, float>
			, virtual public boost::multipliable <var, unsigned long long int>
			, virtual public boost::multipliable <var, unsigned long int>
			, virtual public boost::multipliable <var, unsigned int>
			, virtual public boost::multipliable <var, unsigned short int>
			, virtual public boost::multipliable <var, signed long long int>
			, virtual public boost::multipliable <var, signed long int>
			, virtual public boost::multipliable <var, signed int>
			, virtual public boost::multipliable <var, signed short int>
			, virtual public boost::dividable <var>
			, virtual public boost::dividable <var, std::string>
			, virtual public boost::dividable <var, cln::nr>
			, virtual public boost::dividable <var, char *>
			, virtual public boost::dividable <var, char>
		//	, virtual public boost::dividable <var, unsigned char>
		//	, virtual public boost::dividable <var, signed char>
			, virtual public boost::dividable <var, cln::cl_N>
			, virtual public boost::dividable <var, cln::cl_R>
			, virtual public boost::dividable <var, cln::cl_RA>
			, virtual public boost::dividable <var, cln::cl_I>
			, virtual public boost::dividable <var, cln::cl_F>
			, virtual public boost::dividable <var, cln::cl_SF>
			, virtual public boost::dividable <var, cln::cl_FF>
			, virtual public boost::dividable <var, cln::cl_DF>
			, virtual public boost::dividable <var, cln::cl_LF>
			, virtual public boost::dividable <var, long double>
			, virtual public boost::dividable <var, double>
			, virtual public boost::dividable <var, float>
			, virtual public boost::dividable <var, unsigned long long int>
			, virtual public boost::dividable <var, unsigned long int>
			, virtual public boost::dividable <var, unsigned int>
			, virtual public boost::dividable <var, unsigned short int>
			, virtual public boost::dividable <var, signed long long int>
			, virtual public boost::dividable <var, signed long int>
			, virtual public boost::dividable <var, signed int>
			, virtual public boost::dividable <var, signed short int>
			, virtual public boost::dividable2_left <var, std::string>
			, virtual public boost::dividable2_left <var, cln::nr>
			, virtual public boost::dividable2_left <var, char *>
			, virtual public boost::dividable2_left <var, char>
		//	, virtual public boost::dividable2_left <var, unsigned char>
		//	, virtual public boost::dividable2_left <var, signed char>
			, virtual public boost::dividable2_left <var, cln::cl_N>
			, virtual public boost::dividable2_left <var, cln::cl_R>
			, virtual public boost::dividable2_left <var, cln::cl_RA>
			, virtual public boost::dividable2_left <var, cln::cl_I>
			, virtual public boost::dividable2_left <var, cln::cl_F>
			, virtual public boost::dividable2_left <var, cln::cl_SF>
			, virtual public boost::dividable2_left <var, cln::cl_FF>
			, virtual public boost::dividable2_left <var, cln::cl_DF>
			, virtual public boost::dividable2_left <var, cln::cl_LF>
			, virtual public boost::dividable2_left <var, long double>
			, virtual public boost::dividable2_left <var, double>
			, virtual public boost::dividable2_left <var, float>
			, virtual public boost::dividable2_left <var, unsigned long long int>
			, virtual public boost::dividable2_left <var, unsigned long int>
			, virtual public boost::dividable2_left <var, unsigned int>
			, virtual public boost::dividable2_left <var, unsigned short int>
			, virtual public boost::dividable2_left <var, signed long long int>
			, virtual public boost::dividable2_left <var, signed long int>
			, virtual public boost::dividable2_left <var, signed int>
			, virtual public boost::dividable2_left <var, signed short int>
			, virtual public boost::modable <var>
			, virtual public boost::modable <var, std::string>
			, virtual public boost::modable <var, cln::nr>
			, virtual public boost::modable <var, char *>
			, virtual public boost::modable <var, char>
		//	, virtual public boost::modable <var, unsigned char>
		//	, virtual public boost::modable <var, signed char>
			, virtual public boost::modable <var, cln::cl_N>
			, virtual public boost::modable <var, cln::cl_R>
			, virtual public boost::modable <var, cln::cl_RA>
			, virtual public boost::modable <var, cln::cl_I>
			, virtual public boost::modable <var, cln::cl_F>
			, virtual public boost::modable <var, cln::cl_SF>
			, virtual public boost::modable <var, cln::cl_FF>
			, virtual public boost::modable <var, cln::cl_DF>
			, virtual public boost::modable <var, cln::cl_LF>
			, virtual public boost::modable <var, long double>
			, virtual public boost::modable <var, double>
			, virtual public boost::modable <var, float>
			, virtual public boost::modable <var, unsigned long long int>
			, virtual public boost::modable <var, unsigned long int>
			, virtual public boost::modable <var, unsigned int>
			, virtual public boost::modable <var, unsigned short int>
			, virtual public boost::modable <var, signed long long int>
			, virtual public boost::modable <var, signed long int>
			, virtual public boost::modable <var, signed int>
			, virtual public boost::modable <var, signed short int>
			, virtual public boost::modable2_left <var, std::string>
			, virtual public boost::modable2_left <var, cln::nr>
			, virtual public boost::modable2_left <var, char *>
			, virtual public boost::modable2_left <var, char>
		//	, virtual public boost::modable2_left <var, unsigned char>
		//	, virtual public boost::modable2_left <var, signed char>
			, virtual public boost::modable2_left <var, cln::cl_N>
			, virtual public boost::modable2_left <var, cln::cl_R>
			, virtual public boost::modable2_left <var, cln::cl_RA>
			, virtual public boost::modable2_left <var, cln::cl_I>
			, virtual public boost::modable2_left <var, cln::cl_F>
			, virtual public boost::modable2_left <var, cln::cl_SF>
			, virtual public boost::modable2_left <var, cln::cl_FF>
			, virtual public boost::modable2_left <var, cln::cl_DF>
			, virtual public boost::modable2_left <var, cln::cl_LF>
			, virtual public boost::modable2_left <var, long double>
			, virtual public boost::modable2_left <var, double>
			, virtual public boost::modable2_left <var, float>
			, virtual public boost::modable2_left <var, unsigned long long int>
			, virtual public boost::modable2_left <var, unsigned long int>
			, virtual public boost::modable2_left <var, unsigned int>
			, virtual public boost::modable2_left <var, unsigned short int>
			, virtual public boost::modable2_left <var, signed long long int>
			, virtual public boost::modable2_left <var, signed long int>
			, virtual public boost::modable2_left <var, signed int>
			, virtual public boost::modable2_left <var, signed short int>
			, virtual public boost::xorable <var>
			, virtual public boost::xorable <var, std::string>
			, virtual public boost::xorable <var, cln::nr>
			, virtual public boost::xorable <var, char *>
			, virtual public boost::xorable <var, char>
		//	, virtual public boost::xorable <var, unsigned char>
		//	, virtual public boost::xorable <var, signed char>
			, virtual public boost::xorable <var, cln::cl_N>
			, virtual public boost::xorable <var, cln::cl_R>
			, virtual public boost::xorable <var, cln::cl_RA>
			, virtual public boost::xorable <var, cln::cl_I>
			, virtual public boost::xorable <var, cln::cl_F>
			, virtual public boost::xorable <var, cln::cl_SF>
			, virtual public boost::xorable <var, cln::cl_FF>
			, virtual public boost::xorable <var, cln::cl_DF>
			, virtual public boost::xorable <var, cln::cl_LF>
			, virtual public boost::xorable <var, long double>
			, virtual public boost::xorable <var, double>
			, virtual public boost::xorable <var, float>
			, virtual public boost::xorable <var, unsigned long long int>
			, virtual public boost::xorable <var, unsigned long int>
			, virtual public boost::xorable <var, unsigned int>
			, virtual public boost::xorable <var, unsigned short int>
			, virtual public boost::xorable <var, signed long long int>
			, virtual public boost::xorable <var, signed long int>
			, virtual public boost::xorable <var, signed int>
			, virtual public boost::xorable <var, signed short int>
			
			, virtual public boost::incrementable <var>
			, virtual public boost::decrementable <var>
		//	, virtual public boost::equivalent <nr>
			
			, virtual public boost::partially_ordered <var>
			, virtual public boost::partially_ordered <var, std::string>
			, virtual public boost::partially_ordered <var, cln::nr>
			, virtual public boost::partially_ordered <var, char *>
			, virtual public boost::partially_ordered <var, char>
		//	, virtual public boost::partially_ordered <var, unsigned char>
		//	, virtual public boost::partially_ordered <var, signed char>
			, virtual public boost::partially_ordered <var, cln::cl_N>
			, virtual public boost::partially_ordered <var, cln::cl_R>
			, virtual public boost::partially_ordered <var, cln::cl_RA>
			, virtual public boost::partially_ordered <var, cln::cl_I>
			, virtual public boost::partially_ordered <var, cln::cl_F>
			, virtual public boost::partially_ordered <var, cln::cl_SF>
			, virtual public boost::partially_ordered <var, cln::cl_FF>
			, virtual public boost::partially_ordered <var, cln::cl_DF>
			, virtual public boost::partially_ordered <var, cln::cl_LF>
			, virtual public boost::partially_ordered <var, long double>
			, virtual public boost::partially_ordered <var, double>
			, virtual public boost::partially_ordered <var, float>
			, virtual public boost::partially_ordered <var, unsigned long long int>
			, virtual public boost::partially_ordered <var, unsigned long int>
			, virtual public boost::partially_ordered <var, unsigned int>
			, virtual public boost::partially_ordered <var, unsigned short int>
			, virtual public boost::partially_ordered <var, signed long long int>
			, virtual public boost::partially_ordered <var, signed long int>
			, virtual public boost::partially_ordered <var, signed int>
			, virtual public boost::partially_ordered <var, signed short int>
		{
			public:
				enum class type
				{
					string,
					nr
				};
				
				#include ".var/.hxx"
				
				//#include ".var/container.hxx"
				//const std::string serialize (void) const;
				//const bool deserialize (const std::string &);
				
				//const t & type (void) const;
				//const bool is_text (void) const;
				//const bool is_nr (void) const;
				//bool const nr (void) const;
				
				cln::nr const size (void) const;
				
				/*
				#include ".var/constructor.hxx"
				#include ".var/destructor.hxx"
				
				#include ".var/set.hxx"
				
				#include ".var/conversion.hxx"
				
				#include ".var/comparison.hxx"
				
				#include ".var/addition.hxx"
				#include ".var/substraction.hxx"
				//
				#include ".var/multiplication.hxx"
				#include ".var/division.hxx"
				//
				#include ".var/exponentiation.hxx"
				#include ".var/modulo.hxx"
				
				#include ".var/special.hxx"
				*/
				
				/*
				#include ".var/constr.hxx"
				#include ".var/destr.hxx"
				
				#include ".var/set.hxx"
				
				#include ".var/conver.hxx"
				
				#include ".var/compar.hxx"
				
				#include ".var/add.hxx"
				#include ".var/substr.hxx"
				//
				#include ".var/multi.hxx"
				#include ".var/div.hxx"
				//
				#include ".var/exponent.hxx"
				#include ".var/modulo.hxx"
				
				#include ".var/special.hxx"
				*/
				
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
				//long double		to_nr	(void);
				//bool		to_boolean	(void);
				//noware::mathematics::numbers::natural	length		(void) const;
				// size length
				// const math::nr size (void) const;
				
				//std::ostream & operator << (std::ostream &) const;
				//std::istream & operator >> (std::istream &);
				
				//const var & operator += (const var &);
			protected:
			//private:
				friend class boost::serialization::access;
				
				template <typename archive>
				void serialize (archive &, unsigned int const &/* version*/);
				
				//container content;
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
				
				
				type _type;
				
				std::string _string;
				cln::nr _nr;
		};
	//}
	
	//typedef any var;
	//typedef any any, var;
}

std::istream & getline (std::istream &, noware::var &, char const = '\n');

//std::string		tolower (const noware::any &);
//std::string		toupper (const noware::any &);

//#endif
