#pragma once

#include "string.hxx"
#include <cln/nr.cxx>

const std::string noware::random::string (const cln::nr & size, const std::string & set)
{
	std::string result;
	unsigned int size_i = (unsigned int) size;
	
	result = "";
	
	for (unsigned int i = 0; i < size_i; ++i)
	{
		result += set [rand () % (set.size () - 1)];
	}
	
	return result;
}
