#pragma once

#include <string>
//#include <bits/basic_string.h>
//#include <bits/basic_string.tcc>

namespace noware
{
	typedef std::basic_string <char unsigned> str_nsigned;
	
	std::ostream & operator << (std::ostream &, str_nsigned const &)/* const*/;
}
