//#include "library.h++"
#include "object.h++"

namespace noware
{
	namespace container
	{
		// http://stackoverflow.com/questions/6907194/how-to-typedef-a-template-class
		
		template <typename value = any, typename key = any>
		using obj = object <value, key>;
		/*
		template <typename value = containers::NAME_V, typename key = containers::NAME_V>
		class NAME_A
		{
			typedef containers::NAME_A <typename value, typename key> type;
		};
		*/
	}
}

