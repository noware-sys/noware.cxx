#pragma once

#include "itr.hxx"

namespace noware
{
	namespace misc
	{
		template <typename val_t>
		//class iera(ta)ble
		class itrble
		{
			public:
				// Necessary:
				// Should be implemented:
				virtual itr <val_t> const begin (void) const;
				// Should be implemented:
				virtual itr <val_t> const end (void) const;
		};
	}
}

#include "itr.cxx"
