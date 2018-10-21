#pragma once

#include "str_nsigned.hxx"

namespace noware
{
	std::ostream & operator << (std::ostream & stream, const str_nsigned & self)
	{
		for (char unsigned const & c : self)
		{
			std::cout << c;
		}
		
		return stream;
	}
}
