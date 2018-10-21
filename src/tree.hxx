#pragma once
//#ifndef __ENTITY
//#define __ENTITY

#include <string>
#include <map>

//#include <boost/any.hpp>

//#include "content/value.h++"
#include "serial.hxx"
//#include "misc/itr.hxx"
#include "var.hxx"
//#include "array.hxx"
//#include "entity_container.h++"

//#include "../machine/resources/memory.h++"

//#include "../math.h++"
////#include "../machine/resource.h++"
/*
#ifndef LIB
	#define LIB noware
#endif

// gr[oup] [multi]set r[ecursive[_]]array m[ulti[_]]array matrix lattice obj[ect] tree
// rep[ository] dir[ectory] folder
#ifndef NTT
	//#define NTT entity
	//#define NTT object
	//#define NTT matrix
	#define NTT tree
	//#define NTT set
	//#define NTT group
#endif
//#include "entity-pre.h++"
*/
namespace noware
{
	//namespace container
	//{
	/*
	namespace machine
	{
		namespace resources
		{
			//typedef std::string key, value;
			
			//class processor;
			//class memory;
			
			//template <typename Value = std::string, Key = std::string>
			//class memory : public resource
			class memory
			{
				public:
					class keys;
					
					typedef keys key;
			};
		}
	}
	*/
	//namespace machine
	//{
		//class NTT;
		
//		class container
//		{
//			public:
//				container (void);
//				~ container (void);
//				
//				//std::string text;
//				//bool reference;
//				LIB::container::any literal;
//				
//				LIB::array <LIB::container::NTT, LIB::container::any> group;
//		};
		
		template <typename val_t = var, typename key_t = var>
		class tree
			: virtual public serial
			//, virtual public misc::itrble <val_t>
		{
			private:
				//type t;
				bool _lit;
				
				//contnr data;
				val_t lit;
				std::map <key_t, tree <val_t, key_t>> grp;
			public:
				//enum /*class */type
				//{
				//	lit,
				//	grp
				//};
				
				friend class boost::serialization::access;
				//friend class container;
				
				tree <val_t, key_t> (void);
				tree <val_t, key_t> (val_t const &);
				tree <val_t, key_t> (tree <val_t, key_t> const &);
				//tree (LIB::NAME_A <value, key> const &);
				//NTT (const machine::resources::memory::key &);
				
				virtual tree <val_t, key_t> const & operator = (val_t const &);
				virtual tree <val_t, key_t> const & operator = (tree <val_t, key_t> const &);
				//const NTT <value, key> & operator = (const LIB::NAME_A <value, key> &);
				//const NTT <value, key> & operator = (const machine::resources::memory::key &);
				
				virtual bool const operator == (val_t const &) const;
				virtual bool const operator != (val_t const &) const;
				virtual bool const operator == (tree <val_t, key_t> const &) const;
				virtual bool const operator != (tree <val_t, key_t> const &) const;
				//bool const operator == (LIB::NAME_A <value, key> const &) const;
				//bool const operator != (LIB::NAME_A <value, key> const &) const;
				
				//const bool operator == (const machine::resources::memory::key &);
				//const bool operator != (const machine::resources::memory::key &);
				//const value & operator ++ (void);
				
				//const LIB::container::any & operator = (const LIB::container::any);
				//operator = (const std::string &);
				// const LIB::NAME_A <NTT *, container::key> & operator = (const LIB::NAME_A <NTT *, container::key> &);
				virtual tree <val_t, key_t> & operator [] (key_t const &);
				//tree <val_t, key_t> const & operator [] (const key &) const;
				
				virtual bool const unset (key_t const &);
				virtual bool const exist (key_t const &, bool const &/* recursive*/ = false) const;
				virtual bool const clear (void);
				virtual bool const empty (void) const;
				virtual bool const full (void) const;
				virtual nr const size (bool const &/* recursive*/ = false, bool const &/* grouped/inclusive (consider a group as an item, in addition to its children) (only considered if recursive == true)*/ = false) const;
				virtual bool const rename (key_t const &/* old*/, key_t const &/* new*/);
				
				//const key * & get_key (void);
				
				//operator const LIB::NAME_A <value, key> (void) const;
				//virtual operator val_t const & (void) const;
				virtual operator val_t & (void);
				//operator const value & (void) const;
				virtual val_t & operator * (void);
				//virtual val_t const & operator * (void) const;	// required by misc::itr
				//const value & operator -> (void);
				//const value & operator -> (void) const;
				//const value & operator () (void);
				//const value & operator () (void) const;
				//const value & value (void);
				//const value & value (void) const;
				//const value & get_value (void);
				//const value & get_value (void) const;
				
				virtual std::string const serialize (void) const;
				virtual bool const deserialize (std::string const &);
				
				//const bool grp (void) const;
				virtual bool const & literal (void) const;
				
				
				template <typename archive>
				virtual void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				//const iterator_const & begin (void) const;
				//const iterator_const & end (void) const;
				
				virtual std::map <key_t, val_t>::iterator & begin (void) const;
				virtual std::map <key_t, val_t>::iterator & end (void) const;
				//const /*const_*/itr begin (void) const;
				//const /*const_*/itr end (void) const;
				
		};
		
		//typedef set <> set;
	//}
	//}
	
	// http://stackoverflow.com/questions/6907194/how-to-typedef-a-template-class
	
	template <typename value_t = noware::var, typename key_t = noware::var>
	using tree = tree <value_t, key_t>;
	
	//template <typename value, typename key>
	//using NTT = container::NTT <value, key>;
}

//#include "../machine/resources/memory.h++"

//#include "object.t++"
//#include "set.txx"
#include "tree.cxx"

//#endif

