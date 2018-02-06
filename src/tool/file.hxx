#pragma once

#include <string>

namespace noware
{
	namespace tool
	{
		namespace file
		{
			namespace content
			{
				bool const get (std::string const &/* path*/, std::string &/* content*/);
				bool const set (std::string const &/* path*/, std::string const &/* content*/);
			}	
		}
	}
}
