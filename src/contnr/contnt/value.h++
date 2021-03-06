#pragma once
//#ifndef __DEFAULT
//#define __DEFAULT

//#include <string>
// #include <cstddef>	// For NULL.

// #include <unistd.h>	// For read (,,) in tools::pause ().

//#include <cln/cln.h>

//#include "mathematics.h++"
//#include "name.h++"

/*
	Please define _WIN32_WINNT or _WIN32_WINDOWS appropriately. For example:
	- add -D_WIN32_WINNT=0x0501 to the compiler command line; or
	- add _WIN32_WINNT=0x0501 to your project's Preprocessor Definitions.
	Assuming _WIN32_WINNT=0x0501 (i.e. Windows XP target).
*/
//#ifndef _WIN32_WINNT
//	#define _WIN32_WINNT 0x0610
//#endif

//#define BOOST_EXCEPTION_DISABLE 1
//#ifndef BOOST_DATE_TIME_HAS_NANOSECONDS
//	#define BOOST_DATE_TIME_HAS_NANOSECONDS 1
//#endif

//#ifndef LIB
//	#define LIB noware
//#endif

//typedef long double real;
//typedef signed long long int integer;
//typedef unsigned long long int natural;
//typedef cln::cl_N number;

namespace noware
{
	//namespace mathematics;

	//namespace math = mathematics;
	namespace container
	{
		namespace content
		{
			/*
				General ~= All/Everything
				Generic ~= Any
			*/
			//static const std::string general = "";
			static const char text [] = "";	// generic, text
			//static const std::string generic = "";	// to be removed
			static const char character = ' ';	// '\0', ' '
			//static const LIB::mathematics::numbers::natural number = 0;
			static const unsigned short int number = 0;
			static const bool boolean = false;
		}
	}
	// namespace def = _default;	// dft ?
	//namespace dft = default_;
}

//#endif

