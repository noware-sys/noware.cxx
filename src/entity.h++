#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#define OTL_ODBC
//#define ODBCVER 0x0250
//#define OTL_ODBC_UNIX // uncomment this line if UnixODBC is used
//#include <otlv4.h> // include the OTL 4.0 header file

// #include <cstdarg>
#include <string>
//#include <map>
// #include <mutex>
#include <iostream>

//#include <stdio.h>
//#include <sqlite3.h>

// Intel Treading Building Blocks:
//#include <tbb/tbb.h>

// Boost:
//#include <boost/any.hpp>
// #include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/thread.hpp>	//
//#include <boost/thread/detail/thread.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>

/*
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/Socket.h>
#include <Poco/Data/DataException.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Util/TimerTaskAdapter.h>
*/

#include "../default.h++"
#include "../mathematics.h++"
#include "../containers/array.h++"
#include "../containers/variable.h++"
// #include "../containers/entity.h++"
#include "../containers/memory.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
// #include "../cluster/machine.h++"
// #include "../machine/resource.h++"
// #include "../containers/databases/sqlite.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace containers
	{
		class entity_2
		{
			public:
				/*
				class container
				{
					public:
						container (void);
						container (const container &);
						~container (void);

						bool reference;
						LIB::NAME_V value;
				};
				*/
				
				class iterator
				{
					public:
						iterator (void);
						//iterator (const iterator &);
						//~iterator (void);
						
						//const interator & operator = (const iterator &);
						const bool operator == (const iterator &) const;
						const bool operator != (const iterator &) const;
						const iterator & operator ++ (void);
						const iterator & operator -- (void);
						const LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key>::package & operator * (void) const;
						
						//LIB::containers::NAME_A <LIB::containers::entity_2, LIB::containers::memory::key> list;
						//bool set;
						
						typename LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key>::iterator iter;
				};
				
				// Relations used when dealing with this/the self object.
				enum relation
				{
					self,	// Note that this value also considers the entity.
					sibbling,
					descendant,
					ancestor,
					// Special cases:
					root,
					other
				};

				// This returns the relationship of the other object: what does the other represent to this?
				// If another object than self is passed to this function, "relation::other" is returned.
				const relation relate (const entity_2 &/* other*/) const;
				
				//static const std::string default_database_name = ":memory:";
				static const bool default_tolerant;
				/*
				static const key default_group;
				//static const key default_previous_group = 0;
				static const key default_name;
				static const value default_value;
				*/
				static const memory::key default_name;
				
				friend class boost::serialization::access;
				
				//template <typename archive>
				//void serialize (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				template <typename archive>
				void save (archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
				
				template <typename archive>
				void load (archive &/* Archive (stream). */, const unsigned int &/* Version. */);
				
				BOOST_SERIALIZATION_SPLIT_MEMBER ();
				
				//typedef LIB::containers::NAME_V key, value;
				//typedef container value;
				
				entity_2 (const entity_2 * = NULL, const memory::key & = default_name, const memory::key &/* previous_group*/ = memory::default_group, const std::string &/* database*/ = memory::default_database_name);
				//entity_2 (const std::string &/* = default_database_name*/);
				// Copy constructor.
				entity_2 (const entity_2 &/* other*/);
				entity_2 (const memory::value &/* _value*/);
				~entity_2 (void);
				
				//const bool query (LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, LIB::NAME_V>, LIB::NAME_V> &/* result*/, const std::string &/* the query*/, const LIB::NAME_A <LIB::NAME_V, LIB::NAME_V> &/* arguments*/ = NULL);
				
				//const bool operator == (const entity_2 &) const;
				//const bool operator != (const entity_2 &) const;
				//const bool operator == (const value &) const;
				//const bool operator != (const value &) const;
				const entity_2 & operator = (const entity_2 &);
				const memory::value & operator = (const memory::value &);
				
				const bool refresh_list (void);
				const LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key> & list (void) const;
				
				//const bool set (const key &/* name*/, const value &);
				// Set a literal value.
				const bool set/*_literal*/ (const memory::value &/* value*//* = default_value*/);
			//	const bool set/*_literal*/ (const LIB::entity_2 &/* other*/);
				//// Set a undefined grouped value.
				//const bool set_group (void);
				//// Set a defined, named grouped value.
				//const bool set_group (const key &/* name*//* = default_value*/);
				//const bool set_group (const key &/* name*//* = default_value*/, const key &);
				
				// Get the literal value.
				const memory::value get (void) const;
				// Get the value from the named group.
				entity_2 get (const memory::key &/* name*/);
				//const memory & get (const key &/* name*/) const;
				
				// Getter.
				operator const memory::value/* &*/ (void) const;
				//operator const LIB::NAME_A <value, key>/* &*/ (void) const;
				
				// Getter and setter.
				entity_2 operator [] (const memory::key &/* name*/);
				// Getter.
				//const memory & operator [] (const key &/* name*/) const;
				
				//const bool content_clear_literal (const key &/* name*/);
				//const bool content_clear_group (const key &/* name*/ = default_name);
				
				const LIB::mathematics::numbers::natural size (void) const;
				const bool clear (void);
				const bool empty (void) const;
				const bool full (void) const;
				//const bool exist (const key &/* name*/) const;
				const bool exists (const memory::key &/* name*/) const;
				// Set the name.
				const bool rename (const memory::key &/* name*/, const memory::key &/* new_name*/);
				const bool unset (const memory::key &/* name*/);
				
				//const bool is_group (void) const;
				const bool is_content_literal (void) const;
				
				// These use "add ()":
				//const entity_2 operator + (const value &) const;
				//const entity_2 operator + (const entity_2 &) const;
				//const entity_2 & operator += (const value &);
				//const entity_2 & operator += (const entity_2 &);
				
				const bool add (const memory::value &);
				// This gives back the key that was used.
				const bool add (const memory::value &, memory::key &);
				// This adds the provided values.
			//	const bool add (const LIB::containers::NAME_A <value, key> &);
				// This overwrites any existing keys with the provided values.
			//	const bool set (const LIB::containers::NAME_A <value, key> &);
				// To add:
				// Add (entity).
				// Set (entity).
				
				
				// These are used as "add", as "enqueue" and as "push".
				const bool append (const memory::value &);
				// Gives back the key that was used.
				const bool append (const memory::value &, memory::key &);
				// Uses new keys for any existing ones rather than the provided values.
				//const bool append (const LIB::containers::NAME_A <value, key> &);
				
				const LIB::mathematics::numbers::integer key_integral_min (void) const;
				const LIB::mathematics::numbers::integer key_integral_max (void) const;
				
				// Queue functionality:
				const bool enqueue (const memory::value &);
				const bool enqueue (const memory::value &, memory::key &);
				const bool dequeue (void);
				//const key front_key (void) const;
				const entity_2 beginning (void) const;
				//const key rear_key (void) const;
				const entity_2 ending (void) const;
				
				// Stack functionality:
				const bool push (const memory::value &);
				const bool push (const memory::value &, memory::key &);
				const bool pop (void);
				//const key top_key (void) const;
				//const value top (void) const;
				//const key bottom_key (void) const;
				//const value bottom (void) const;
				
				//// Is the type of the key numeric?
				//const bool numeric_key (void) const;
				
				// Returns the next greatest value in the sequence.
				const memory::key sequence_next (void) const;
				// Returns the next available value in the sequence.
				const memory::key sequence_next_available (void) const;
				// Returns the next greatest group in the sequence.
				//const memory::key group_next (void) const;
				// Returns the next available group in the sequence.
				//const memory::key group_next_available (void) const;
				// Returns the next greatest name in the sequence.
				//const memory::key name_next (const memory::key &/* group*/ = memory::default_group) const;
				// Returns the next available name in the sequence.
				//const memory::key name_next_available (const memory::key &/* group*/ = memory::default_group) const;
				
				// For range-based (for) looping:
				/*
					Next:		++
					Previous:	--
				*/
				
				//void begin (void);
				//void end (void);
			//	const iterator begin (void) const;
			//	const iterator end (void) const;
				//const const_iterator & begin (void) const;
				//const const_iterator & end (void) const;
				// Allow external modifications:
				const iterator begin (void);
				const iterator end (void);
				
				//friend std::ostream & operator << (std::ostream &, const entity_2 &);
				//std::ostream & operator << (std::ostream &) const;
				
				// Prefix:
				//NAME_A <value, key> & operator ++ (void);
				//NAME_A <value, key> & operator -- (void);
				
				// Postfix / Suffix:
				//NAME_A <value, key> operator ++ (signed int);
				//NAME_A <value, key> operator -- (signed int);
				
				//signed int		operator	*	(void);
				//key & operator * (void) const;
				
				const std::string serialize (void) const;
				const bool deserialize (const std::string &);
				
				//// Serialize.
				//operator const std::string (void) const;
				//// Deserialize.
				//const memory & operator = (const std::string &);
				
				bool tolerant;
				
				// Get the container.
				LIB::containers::memory & memory (void);
			protected:
				const bool initialize (const entity_2 * = NULL, const memory::key & = default_name, const memory::key &/* previous_group*/ = memory::default_group, const std::string &/* database*/ = memory::default_database_name);
				const bool finalize (void);
				//initialize (const std::string &/* database*/);
				
				//const bool prepare_group (const memory::key & _name, const bool &/* grouped*/ = false, const bool &/* overwrite*/ = false);
				
				// The group in the table which is represented by the current instance of this object.
				memory::key group, name;
				// The group and the name from the previous entity which were used to get to this entity.
				//key previous_name;
				//key previous_group;
				
				// Returned if the value is not literal if boolean == false.
				static const memory::value backup;
				
				static LIB::containers::NAME_A <LIB::mathematics::numbers::natural, LIB::containers::memory *> instances;
				
				LIB::containers::NAME_A <LIB::containers::entity_2 *, LIB::containers::memory::key> _list;
				//const bool clear_literal (void);
				//const bool clear_group (void);
				const bool _add (const memory::value &, memory::key &, const memory::key &);
			//private:
				// The container.
				LIB::containers::memory * _memory;
		};
	}
	
	//typedef containers::entity_2 entity_2;
}
