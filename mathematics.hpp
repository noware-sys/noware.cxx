#ifndef MATHEMATICS
#define MATHEMATICS

#include <string>
#include <stddef.h>	// For NULL

namespace LIB
{
	namespace mathematics
	{
		namespace numbers
		{
			typedef long double real;
			typedef signed long long int integer;
			typedef unsigned long long int natural;

			//static const unsigned short int DEFAULT = 0;
			static const bool default = 0;	// false or 0;
		}
	}

	namespace math = mathematics;
}

#endif MATHEMATICS
