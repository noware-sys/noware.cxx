#pragma once

namespace noware
{
	namespace misc
	{
		template <typename val_t>
		//class ierator
		class itr
		{
			public:
				//itr <val_t> (itr <val_t> const &/* other*/);
				
				/*
				// Necessary:
				// Should be implemented:
				virtual itr <val_t> const begin (void) const;
				// Should be implemented:
				virtual itr <val_t> const end (void) const;
				*/
				
				// Should be implemented:
				//virtual val_t & operator * (void);
				virtual val_t const operator * (void) const;
				virtual bool const operator != (itr <val_t> const &/* other*/) const;
				// Should be implemented:
				virtual itr <val_t> const operator ++ (void);
				
				
				// Additional:
				// Should be implemented:
				virtual bool const operator == (itr <val_t> const &/* other*/) const;
				// Should be implemented:
				virtual itr <val_t> const operator -- (void);
				
				//val_t contnt;
		};
	}
}

#include "itr.cxx"
