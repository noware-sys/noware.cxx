// #include <typeinfo>
//#include <iostream>
// Array.CPP:
// Standard library:
//#include <utility>	// For "std::swap ()".


template <typename value, typename key>
value LIB::NAME_A <value, key>::_value;

template <typename value, typename key>
key LIB::NAME_A <value, key>::_k;

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::container::operator == (const container & other) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	if (this == & other)
		return true;
	
	// The type of value may not have the operator == defined, so comparing them may fail:
	try
	{
		//return (k == other.k && * v == * (other.v));
		return (k == other.k && v == other.v);
	}
	catch (...)
	{
		// Should the pointers be compared instead?
		return false;
	}
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::container::operator == (const value & other) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	return v == other;
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::container & LIB::NAME_A <value, key>::container::operator = (const container & other)
{
	
	// The type of value may not have the operator = defined, so comparing them may fail:
	try
	{
		k = other.k;
		//* v = * (other.v);
		v = other.v;
	}
	catch (...)
	{
		// Should the pointers be used instead?
	}
	
	return * this;
}


template <typename value, typename key>
template <typename archive>
void LIB::NAME_A <value, key>::container::serialize (archive & arch, const unsigned int & version)
//LIB::NAME_A<value, key>::NAME_A (void)
{
	//value temp_value;
	
	arch & k;
	//archive & (* v);
	arch & v;
	
	//if (Archive::is_loading::value)
	//{
		//if (v != NULL)
		//{
			/*
			try
			{
				//value * v2 = new value ();
				
				v ->;
			}
			catch (...)
			{
				v = new value ();
//			}
			*/
		//}
	//}
	
	/*
	try
	{
		//value * v2 = new value ();

		v ->;
	}
	catch (...)
	{
		v = new value ();
	}
	archive & (* v);
	*/
	//archive & v;
	//archive & v;
	//boost::serialization::split_member (archive, * this, version);
}

/*
template <typename value, typename key>
template <typename archive>
void LIB::NAME_A <value, key>::container::save (archive & arch, const unsigned int & version) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	archive << k;
	archive << v;
	//archive & v;
	//archive & v;
}

template <typename value, typename key>
template <typename archive>
void LIB::NAME_A <value, key>::container::load (archive & arch, const unsigned int & version)
//LIB::NAME_A<value, key>::NAME_A (void)
{
	value temp_value;
	
	archive >> k;
	archive >> temp_value;
	//* v;
	
	try
	{
		(* v) = temp_value;
	}
	catch (...)
	{
		v = new value ();
	}
	
	archive >> (* val);
	
	//(* val) = value_temp;
	//* val = value_temp;
	//std::swap (* val, value_temp);
	/*
	try
	{
		delete val;
	}
	catch (...)
	{
	}
	
	val = new value (value_temp);
	* /
	//archive & val;
	//archive & v;
}
*/
template <typename value, typename key>
const std::string LIB::NAME_A <value, key>::container::serialize (void) const
{
	return LIB::serialize <LIB::NAME_A <value, key>::container> (* this);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::container::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NAME_A <value, key>::container> (serial, * this);
}
/*
template <typename value, typename key>
const typename LIB::NAME_A <value, key>::container & LIB::NAME_A <value, key>::container::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return * this;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::operator const std::string (void) const
{
	return serialize ();
}
*/
template <typename value, typename key>
const value & LIB::NAME_A <value, key>::container::operator = (const value & val)
{
	v = val;
	
	return val;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::operator const value (void) const
{
	return v;
}

template <typename value, typename key>
const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const std::string & serial)
{
	deserialize (serial);
	
	return * this;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::operator const std::string (void) const
{
	return serialize ();
}

template <typename value, typename key>
template <typename archive>
void LIB::NAME_A <value, key>::serialize (archive & arch, const unsigned int & version)
//LIB::NAME_A<value, key>::NAME_A (void)
{
	arch & tolerant;
	arch & content;
	
	//boost::serialization::split_member (archive, * this, version);
}

/*
template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::save (Archive & archive, const unsigned int & version) const
//LIB::NAME_A<value, key>::NAME_A (void)
{
	//archive << content;
	//archive << tolerant;
	try
	{
		for (auto element : *this)
		{
			archive << element;
		}
		
		archive << tolerant;
		
		/*
		reset ();
		LIB::math::numbers::natural size = this -> size ();
		
		for (LIB::math::numbers::natural i = 0; i < size; ++ i)
		{
			//archive << current_key ();
			//archive << current_value ();
			archive << current_package ();
			
			next ();
		}
		
		archive << tolerant;
		//return true;
		* /
	}
	catch (...)
	{
		//return false;
	}
}

template <typename value, typename key>
template <typename Archive>
void LIB::NAME_A <value, key>::load (Archive & archive, const unsigned int & version)
//LIB::NAME_A <value, key>::NAME_A (void)
{
	//archive >> content;
	//archive >> tolerant;
	try
	{
		LIB::NAME_A <value, key> temp;
		//reset ();
		//temp.clear ();
		//LIB::math::numbers::natural size = size ();
		// Input archive:
		//boost::archive::text_iarchive iarchive (archive);
		
		//for (LIB::math::numbers::natural i = 0; i < size; ++ i)
		//{
			//archive & current_key ();
			//archive & current_value ();
			//archive & operator[] ();
			//archive & current_value ();
			
		//	next ();
		//}
		
		//key k;
		//value v;
		container pack;
		
		//archive >> k;
		//archive >> v;
		
		if (archive >> temp.tolerant)
		{
			// !(archive >> temp.tolerant) does not work.
		}
		else
		{
			return/* false* /;
		}
		
		//while (! /*i* /archive.eof ())
		while (archive >> pack)
		{
			///*i* /archive >> k;
			///*i* /archive >> v;
			
			if (! temp.set (pack.k, * (pack.v)))
				return/* false* /;
		}
		
		*this = temp;
		
		//return true;
	}
	catch (...)
	{
		//return false;
	}
}
*/

template <typename value, typename key>
const std::string LIB::NAME_A <value, key>::serialize (void) const
{
	return LIB::serialize <LIB::NAME_A <value, key>> (* this);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::NAME_A <value, key>> (serial, * this);
}

template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (/*const bool _tolerant*/void)
{
	//_size = 0;
	//tolerant = _tolerant;
	tolerant = true;

	// Add a default value to be returned when one is searched by a key which does not exist.
	//std::pair <key, value> _pair;
	//content.insert (_pair);
}

/*
// One element.
template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (const value & lmn/* eLeMeNt * /)
{
	// Call the default constructor.
	LIB::NAME_A ();
	
	enqueue (lmn);
}
*/
// Copy constructor.
template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (const LIB::NAME_A <value, key> & other)
{
	* this = other;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::container (void)
{
	//v = NULL;
	//v = new value ();
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::container (const NAME_A <value, key>::container & other)
{
	k = other.k;
	v = other.v;
	//std::swap (k, const_cast <key> (other.k));
	//std::swap (v, const_cast <value> (other.v));
	// std::swap (this, const_cast <LIB::NAME_A <value, key>::container *> (& other));
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::container (const key & key_, const value & value_)
{
	k = key_;
	//v = new value ();
	//* v = value_;
	v = value_;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::container::~ container (void)
{
	/*
	if (v != NULL)
	{
		try
		{
			delete v;
		}
		catch (...)
		{
		}
	}
	*/
}


// Default destructor:

template <typename value, typename key>
LIB::NAME_A <value, key>::~ NAME_A (void)
{
	//Link * current;
	//tempSize = size ();
	//LIB::NAME_A<value, key>::Clear ();
	//clear ();
	//_size = 0;
}

template <typename value, typename key>
LIB::NAME_A <value, key>::NAME_A (const std::string & serial)
{
	deserialize (serial);
}

// Setter
//template <typename value, typename key>
//value & LIB::NAME_A<value, key>::operator [] (const key key)
//{
//	//return values;
//}

template <typename value, typename key>
const LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator + (const value & other) const
{
	LIB::NAME_A <value, key> temp;
	
	temp = *this;
	temp.add (other);
	
	return temp;
}

template <typename value, typename key>
const LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator + (const NAME_A <value, key> & other) const
{
	LIB::NAME_A <value, key> temp;
	
	temp = *this;
	temp.add (other);
	
	return temp;
}

/*
template <typename value, typename key>
const LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator - (const value & other) const
{
}
*/
template <typename value, typename key>
const LIB::NAME_A <value, key> LIB::NAME_A <value, key>::operator - (const LIB::NAME_A <value, key> & other) const
{
	LIB::NAME_A <value, key> temp = *this;
	
	for (const auto & element : other)
	{
		temp.unset (element.k);
	}
	
	return temp;
}

// Setter.

template <typename value, typename key>
/*value &*/ const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::/*operator []*/operator +=/*enqueue*//*add*//*append*/ (const value & value_/*, key & _key_*/)
{
	add (value_);
	
	/*
	switch (typeid (key))
	{
		case typeid (signed short int):
		case typeid (unsigned short int):
		case typeid (signed int):
		case typeid (unsigned int):
		case typeid (signed long int):
		case typeid (unsigned long int):
		case typeid (signed long long int):
		case typeid (LIB::math::numbers::integer):
		case typeid (unsigned long long int):
		case typeid (LIB::math::numbers::natural):
			//ULLONG_MAX
			for ( key i = 0; i < size () && i < ULLONG_MAX; ++ i)
			{
				if (! exist (i))
				{
					if (_key_ != NULL)
						_key_ = i;
					
					return add (i, _value_);
					//return add (i, _value_) == _value_;
				}
			}
	}
	 */
/*
	if
		(
			/*
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed int)
			||
			typeid (key) == typeid (unsigned int)
			||
			typeid (key) == typeid (signed long int)
			||
			typeid (key) == typeid (unsigned long int)
			||
			typeid (key) == typeid (signed long long int)
			||
			typeid (key) == typeid (LIB::math::numbers::integer)
			||
			typeid (key) == typeid (unsigned long long int)
			||
			* /
			typeid (key) == typeid (LIB::math::numbers::natural)
			||
			typeid (key) == typeid (LIB::variable)
		)
	{
		//ULLONG_MAX
		for (key i = 1; i <= this -> size ()/* && i < ULLONG_MAX* /; ++ i)
		{
			if (! exist (i))
			{
				//if (_key_ != NULL)
				//	_key_ = i;

				//return add (i, & _value_);
				///*return * /set (i, value_);
				insert (i, value_);
				
				break;
				//return add (i, _value_) == _value_;
			}
		}
	}

	//return _value;
	//return false;
*/
	return * this;
}

template <typename value, typename key>
const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator += (const LIB::NAME_A <value, key> & other)
{
	add (other);
	
	return * this;
}

/*
template <typename value, typename key>
const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator -= (const value & other)
{
	return *this = *this - other;
}
*/
template <typename value, typename key>
const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator -= (const LIB::NAME_A <value, key> & other)
{
	return *this = *this - other;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::add (const value & other)
{
	if (!key_numeric ())
		return false;
	
	operator [] (sequence_next_available ()) = other;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::add (const value & other, key & used_key)
{
	if (!key_numeric ())
		return false;
	
	used_key = sequence_next_available ();
	operator [] (used_key) = other;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::add (const NAME_A <value, key> & other)
{
	for (auto & element : other)
	{
		operator [] (element.k) = element.v;
	}
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::append (const value & other)
{
	if (!key_numeric ())
		return false;
	
	operator [] (sequence_next ()) = other;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::append (const value & other, key & used_key)
{
	if (!key_numeric ())
		return false;
	
	used_key = sequence_next ();
	operator [] (used_key) = other;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::append (const NAME_A <value, key> & other)
{
	if (!key_numeric ())
		return false;
	
	for (auto & element : other)
	{
		if (exists (element.k))
		{
			append (element.v);
		}
		else
		{
			operator [] (element.k) = element.v;
		}
	}
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::key_numeric (void) const
{
	return
		(
			
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed short int)
			||
			typeid (key) == typeid (unsigned short int)
			||
			typeid (key) == typeid (signed int)
			||
			typeid (key) == typeid (unsigned int)
			||
			typeid (key) == typeid (signed long int)
			||
			typeid (key) == typeid (unsigned long int)
			||
			typeid (key) == typeid (signed long long int)
			||
			typeid (key) == typeid (unsigned long long int)
			||
			typeid (key) == typeid (float)
			||
			typeid (key) == typeid (double)
			||
			typeid (key) == typeid (long double)
			/*
			||
			typeid (key) == typeid (LIB::math::numbers::natural)
			||
			typeid (key) == typeid (LIB::math::numbers::integer)
			||
			typeid (key) == typeid (LIB::math::numbers::f)
			||
			typeid (key) == typeid (LIB::math::numbers::d)
			||
			typeid (key) == typeid (LIB::math::numbers::rational)
			||
			typeid (key) == typeid (LIB::math::number)
			*/
			||
			typeid (key) == typeid (LIB::number)
			||
			typeid (key) == typeid (LIB::var)
		)
	;
}

template <typename value, typename key>
const key LIB::NAME_A <value, key>::sequence_next_available (void) const
{
	if
		(
			key_numeric ()
		)
	{
		key i = 1;
		//ULLONG_MAX
		//for (key i = 1; i <= size ()/* && i < ULLONG_MAX*/; ++ i)
		while (exists (i))
		{
			++ i;
		}
		
		return i;
	}
	else
	{
		return _k;
	}
}

template <typename value, typename key>
const key LIB::NAME_A <value, key>::sequence_next (void) const
{
	if
		(
			key_numeric ()
		)
	{
		//ULLONG_MAX
		return key_numeric_max () + 1;
		
	}
	else
	{
		// The default, backup value.
		return _k;
	}
}

template <typename value, typename key>
const key LIB::NAME_A <value, key>::key_numeric_max (void) const
{
	if (!key_numeric ())
		return _k;
	
	key i = 0;
	
	for (auto & element : *this)
	{
		if (element.k > i)
		{
			i = element.k;
		}
	}
	
	return i;
}

template <typename value, typename key>
const key LIB::NAME_A <value, key>::key_numeric_min (void) const
{
	key i = key_numeric_max ();
	
	for (auto & element: *this)
	{
		if (element.k < i)
		{
			i = element.k;
		}
	}
	
	return i;
}

// Getter and Setter.

template <typename value, typename key>
value & LIB::NAME_A <value, key>::operator [] (const key & key_)
//value & LIB::NAME_A <value, key>::operator [] (const value & v)
{
	//std::unordered_map <key, value>::const_iterator found = content.find (_key);
	//std::unordered_map <key, value>::iterator found = content.find (_key);

	//return get (_key/*, tolerant*/);	// Not necessarily a setter in all cases.
	value * value_/* = NULL*/;
	
	if (search (key_, value_))
	{
		return * value_;
	}
	else if (tolerant)
	{
		//value * _value_ = new value ();
		//value * value_;
		//const value * _value_ = new value ();
		
		//if (add (_key, & _value_))
		//if (add (key_, value_))
		if (insert (key_, value_))
		//if (add (_key, const_cast <const value * &> (_value_)))
		{
			// add () should create a new value; so, it can be dereferenced.
			return * value_;
			//return get (_key);
			//return const_cast <value> (* _value_);
		}
		else
		{
			//delete _value_;

			return _value;
		}
	}
	else
	{
		return _value;
	}

	/*
	value * temp;

	if (search (_key, temp))
	{
		return * temp;
	}
	else if (tolerant)
	{
		return & _value;
	}
	else
	{
		return add (_key);
	}
	 */

	/*
	value * temp;

	//
	//tolerant = tolerant;
	//

	if (search (_key, temp))
	{
		return temp;
	}
	else if (tolerant)
	{
		// Do not add when in tolerant mode; just return any value.
		value v;
		return v;
		//return NULL;
	}
	else
		return create (v);
	 */
}

// Getter:
template <typename value, typename key>
const value & LIB::NAME_A <value, key>::operator [] (const key & _key) const
//value & LIB::NAME_A <value, key>::operator [] (const value & v)
{
	value * temp/* = NULL*/;
	
	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
	}
}

//template <typename value, typename key>
//value & LIB::NAME_A <value, key>::operator [] (const key & _key, const bool tolerant)
////value & LIB::NAME_A <value, key>::operator [] (const value & v)
//{
//	bool strict_local = tolerant;
//	tolerant = ! tolerant;
//
//	value v = operator [] (_key);
//
//	tolerant = strict_local;
//	
//	return v;
//}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::search (const key & key_, value *& value_) const
{
	//for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
	//	std::cout << ' ' << *it;
	//{
	//	typename std::list <container>::const_iterator element = content.cbegin ();
	//	typename std::list <container>::const_iterator ending = content.cend ();
	//	++ element;
	//}
	for (const LIB::NAME_A <value, key>::container & element : *this)
	//for (const LIB::NAME_A <value, key>::container & element : * this)
	//for (const_iterator element = begin (), ending = end (); element != ending; ++ element)
	{
		//std::cout << "Element " << '[' << element.k << "] = " << element.v << std::endl;
		//std::cout << "Element " << '[' << element.k << "] = " << std::endl;
		if (element.k == key_)
		{
			//value_ = element.v;
			value_ = &(element.v);
		//	value_ = const_cast <value *> (& (element.v));
			//value_ = & element.v;
			
			return true;
		}
	}
	
	return false;
//	reset ();
//
//	for (LIB::math::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == _key)
//		{
//			_value_ = & current_value ();
//
//			return true;
//		}
//
//		next ();
//	}
//
//	return false;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::search_key (const key & key_, key *& k) const
{
	//for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
	//	std::cout << ' ' << *it;
	
	for (auto & element : * this)
	{
		if (element.k == key_)
		{
			//value_ = element.v;
			// value_ = & (element.v);
			k = const_cast <key *> (& (element.k));
			//value_ = & element.v;
			
			return true;
		}
	}
	
	return false;
//	reset ();
//
//	for (LIB::math::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == _key)
//		{
//			_value_ = & current_value ();
//
//			return true;
//		}
//
//		next ();
//	}
//
//	return false;
}

template <typename value, typename key>
/*value &*/ const bool LIB::NAME_A <value, key>::insert (const key & key_, /*const */value *& value_)
{
	//(* _value_) = "TEMP";
	
	container * temp = new container ();
	//container temp;
	
	temp -> k = key_;
	//temp -> v = /** */value_;
	// temp.k = key_;
	//* (temp.v) = * value_;
	// value_ = temp.v;
	//  temp.v = new value ();
	//temp.v = NULL;	// Prevent the destructor of the class "container" to delete "temp" when "temp" reaches the end of its scope.
	
	//value_ = & (temp -> v);
	//value_ = const_cast <value *> (& ((* temp).v));
	
	//value_ = get (key_);
	
	content.push_back (* temp);
	//content.push_back (* (new container (key, )));
	//content.push_back (temp);
	
	search (key_, value_);
	
	//return temp -> v;
	return true;
	//return content.back ().v;
}

//template <typename value, typename key>
///*value &*/ bool LIB::NAME_A <value, key>::add (const key & _key)
//{
//	//value * _value_ = new value ();
//
//	//return add (_key, _value_);
//	return add (_key, _value_);
//}

//template <typename value, typename key>
///*value & */bool LIB::NAME_A <value, key>::set (const key & _key, const value *& _value_/*, const bool _tolerant*/)
//{
///*
//	value * temp;
//	
//	if (search (_key, temp))	// This condition (also) works as a getter (it considers only the first parameter).
//	{
//		return * temp;
//	}
//	else if (! _tolerant)
//	{
//		return _value;
//	}
//	else
//	{
//		return add (_key, _value_);
//	}
//*/
//	value * temp;
//	
//	//std::cout << "search ()" << std::endl;
//	if (search (_key, temp))	// This condition (also) works as a getter (it considers only the first parameter).
//	{
//		//std::cout << "\"temp = & value\"" << std::endl;
//		//* temp = _value_;
//		temp = const_cast <value *&> (/*& */_value_);
//		
//		return true;
//	}
//	else //if (_tolerant)
//	{
//		//std::cout << "add ()" << std::endl;
//		return add (_key, _value_);
//	}
//	/*else
//	{
//		return false;
//	}*/
//}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::set (const key & _key, const value & value_)
{
	value * temp;
	
	//std::cout << "search ()" << std::endl;
	if (search (_key, temp) || insert (_key, temp))
	{
		* temp = value_;
		
		return true;
	}
	else
	{
		return false;
	}
}

template <typename value, typename key>
value & LIB::NAME_A <value, key>::get (const key & _key/*, const bool _tolerant*/)
{
	value * temp/* = NULL*/;

	/*
	std::cout << "set (...)" << std::endl;
	set (_key, temp, _tolerant);
	
	std::cout << "return temp" << std::endl;
	return temp;*/


	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
		//return temp;
	}

	//value _value_;
	//
	//return set (_key, _value_, tolerant);

}

template <typename value, typename key>
const value & LIB::NAME_A <value, key>::get (const key & _key) const
{
	value * temp/* = NULL*/;
	
	if (search (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _value;
		//return temp;
	}
}

template <typename value, typename key>
const key & LIB::NAME_A <value, key>::get_key (const key & _key) const
{
	key * temp/* = NULL*/;
	
	if (search_key (_key, temp))
	{
		return * temp;
	}
	else
	{
		return _k;
		//return temp;
	}
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::clear (void)
{
	content.clear ();

	return true;
}
/*
template <typename value, typename key>
const LIB::math::numbers::natural LIB::NAME_A <value, key>::cardinality (void) const
{
	return size ();
}

template <typename value, typename key>
const LIB::math::numbers::natural LIB::NAME_A <value, key>::count (void) const
{
	return size ();
}

template <typename value, typename key>
const LIB::math::numbers::natural LIB::NAME_A <value, key>::magnitude (void) const
{
	return size ();
}

template <typename value, typename key>
const LIB::math::numbers::natural LIB::NAME_A <value, key>::quantity (void) const
{
	return size ();
}
*/
template <typename value, typename key>
//const LIB::math::numbers::natural LIB::NAME_A <value, key>::size (void) const
const LIB::number LIB::NAME_A <value, key>::size (void) const
{
	return content.size ();
}

/*
template <typename value, typename key>
bool LIB::NAME_A <value, key>::search (const key & _key, container::_value & v) const
{
	//container current;

	LIB::math::numbers::natural n = size ();
	std::list <key>::iterator it;

	//for (LIB::math::numbers::natural index = 0; index < n; ++ index, current = current -> next)
	for (it = content.begin(); it != contaienr.end (); ++it)
	{
		if ((*it) -> _key == _key)
		{
			v = (* it) -> _value;;

			return true;
		}
	}

	return false;
}
 */

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::exists (const key & _key) const
{
	//std::unordered_map <key, value>::const_iterator found = content.find (_key);

	//return found != content.end ();
	//return content.count (_key) > 0;
	// return false;
	return exist (_key);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::exist (const key & _key) const
{
	//std::unordered_map <key, value>::const_iterator found = content.find (_key);

	//return found != content.end ();
	//return content.count (_key) > 0;
	// return false;
	value * temp;

	return search (_key, temp);
}

//template <typename value, typename key>
//bool LIB::NAME_A<value, key>::New (const key, const value)
//{
//	if (Exists (key))
//	{
//		return false;
//	}
//	else
//	{
//		// Add it:
//		return true;
//	}
//}
//

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::unset (const key & key_)
{
	auto it = begin ();
	
	for (auto & element : * this)
	{
		if (element.k == key_)
		{
			//_value = & current_value ();
			content.erase (it);
			//content.erase (&& element);
			
			return true;
		}
		
		++ it;
	}
	
	//content.remove (_key);
	return false;
	
//	reset ();
//	
//	for (LIB::math::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == _key)
//		{
//			//_value = & current_value ();
//			content.erase (list_iterator);
//
//			return true;
//		}
//
//		next ();
//	}
//
//	//content.remove (_key);
//	return false;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::rename (const key & old, const key & val /* New name. */, const bool _tolerant)
{
	if (/*! exist (current) || */(! _tolerant /* If not permitted to overwrite the new value... */ && exist (val) /* ...and if the new value exists. */))
		return false;
	
	// Clear the position.
	unset (val);
	
	for (auto & element : * this)
	{
		if (element.k == old)
		{
			element.k = val;
			
			return true;
		}
	}

	return false;
	
//	reset ();
//
//	for (LIB::math::numbers::natural i = 0; i < size (); ++ i)
//	{
//		if (current_key () == current)
//		{
//			current_key_internal () = val;
//			//_value = & current_value ();
//			//content.erase (list_iterator);
//
//			return true;
//		}
//
//		next ();
//	}
//
//	return false;
	/*
		link * target;

		if (search (current, target))
		{
			if (search (val, target))
				return false;
			else
				target -> _key = val;

			return true;
		}
		else
		{
			return false;
		}
	 */
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::rename (const key & current, const key & new_val /* New name. */)
{
	return rename (current, new_val, tolerant /* Use the externally-settable variable. */);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::full (void) const
{
	//return size () <= 0;
	return false;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::empty (void) const
{
	//return size () <= 0;
	return content.empty ();
}

template <typename value, typename key>
const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const LIB::NAME_A <value, key> & other)
{
	//return content = val.content;
	if (this != &other)
		content = other.content;
	
	return *this;
}

//template <typename value, typename key>
//const LIB::NAME_A <value, key> & LIB::NAME_A <value, key>::operator = (const LIB::NAME_A <value, key> & left, const LIB::NAME_A <value, key> & right)
//const LIB::NAME_A & LIB::NAME_A::operator = (const LIB::NAME_A & left, const LIB::NAME_A & right)
//{
//	return left = right;
//}

/*
template <typename value, typename key>
key & LIB::NAME_A <value, key>::current_key_internal (void)
{
	return list_iterator -> k;
}

template <typename value, typename key>
key LIB::NAME_A <value, key>::current_key (void)
{
	return current_key_internal ();
}

template <typename value, typename key>
value & LIB::NAME_A <value, key>::current_value (void)
{
	return * (list_iterator -> v);
}

template <typename value, typename key>
typename LIB::NAME_A <value, key>::iterator & LIB::NAME_A <value, key>::current_package (void)
{
	return list_iterator;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::next (void)
{
	if (list_iterator == content.end ())
	{
		reset ();
	}
	else
	{
		++ list_iterator;
	}

	return true;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::previous (void)
{
	if (list_iterator == content.begin ())
	{
		list_iterator = content.end ();
	}
	else
	{
		-- list_iterator;
	}

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::previous (const iterator & it)
{
	if (it == content.begin ())
	{
		it = content.end ();
	}
	else
	{
		-- it;
	}

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::previous (const iterator & it) const
{
	if (it == content.begin ())
	{
		it = content.end ();
	}
	else
	{
		-- it;
	}

	return it;
}

template <typename value, typename key>
bool LIB::NAME_A <value, key>::reset (void)
{
	list_iterator = content.begin ();

	return true;
}

template <typename value, typename key>
LIB::NAME_A::iterator LIB::NAME_A <value, key>::reset (void/*const iterator & it* /) const
{
	return content.begin ();
}
*/
/*
template <typename value, typename key>
void LIB::NAME_A <value, key>::start (void)
{
	list_iterator = content.begin ();
}

template <typename value, typename key>
void LIB::NAME_A <value, key>::end (void)
{
	list_iterator = content.end ();
}
 */
/*
template <typename value, typename key>
const typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::begin (void)
{
	return content.begin ();
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::end (void)
{
	return content.end ();
}
*/
template <typename value, typename key>
const typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::begin (void)
{
	return content.begin ();
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::iterator LIB::NAME_A <value, key>::end (void)
{
	return content.end ();
}
/*
template <typename value, typename key>
const typename LIB::NAME_A <value, key>::const_iterator LIB::NAME_A <value, key>::cbegin (void) const
{
	return content.cbegin ();
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::const_iterator LIB::NAME_A <value, key>::cend (void) const
{
	return content.cend ();
}
*/
template <typename value, typename key>
const bool LIB::NAME_A <value, key>::operator == (const NAME_A <value, key> & other) const
{
	if (this == & other)
		return true;
	else if (size () != other.size ())
		return false;
	
	// std::begin is a free function in C++11.
	//auto iterator_this = begin ();	//std::begin (* this);
	// auto iterator_other = other.begin ();	//std::begin (other);
	
	for (auto & element : * this)
	{
		//if (* element != * iterator_other)
		if (! other.exist (element.k) || element.v != other [element.k])
		{
			return false;
		}
		
		// ++ iterator_other;
		//++ iterator_this;
	}
	
	return true;
	
//	math::numbers::natural n = other.size ();
//
//	if (size () != n)
//		return false;
//
//	reset ();
//	other.reset ();
//
//	for (math::numbers::natural i = 0; i < n; ++ i)
//	{
//		if (current_key () != other.current_key () || current_value () != other.current_value ())
//		{
//			return false;
//		}
//
//		next ();
//		other.next ();
//	}
//
//	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::operator != (const NAME_A <value, key> & other) const
{
	return ! operator == (other);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::enqueue (const value & other)
{
	key _k;
	
	return enqueue (other, _k);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::enqueue (const value & other, key & k)
{
	if (! key_numeric ())
		return false;
	
	k = sequence_next ();
	
	operator [] (k) = other;
	
	return true;
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::dequeue (void)
{
	if (empty () || !key_numeric ())
		return false;
	
	return unset (key_numeric_min ());
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::push (const value & other)
{
	key _k;
	
	return push (other, _k);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::push (const value & other, key & k)
{
	return enqueue (other, k);
}

template <typename value, typename key>
const bool LIB::NAME_A <value, key>::pop (void)
{
	if (empty () || !key_numeric ())
		return false;
	
	return unset (key_numeric_max ());
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::container & LIB::NAME_A <value, key>::beginning (void)
{
	if (empty () || !key_numeric ())
		return NULL;
	
	return operator [] (key_numeric_min ());
}

template <typename value, typename key>
const typename LIB::NAME_A <value, key>::container & LIB::NAME_A <value, key>::ending (void)
{
	if (empty () || !key_numeric ())
		return NULL;
	
	return operator [] (key_numeric_max ());
}

//template <typename value, typename key>
//std::ostream & /*LIB::container::*/NAME_A <value, key>::operator << (std::ostream & stream, const LIB::NAME_A <value, key> & val/*, const std::string & indentation*/)
//{
//	for (const typename LIB::NAME_A <value, key>::container & element : val)
//	{
//		//os << indentation << element.k;
//		
//		//operator << (os, val, indenation + "\t");
//		stream/* << indentation*/ << '[' << element.k << "] => [" << element.v << ']' << std::endl;
//	}
//	
//	return stream;
//}
//
template <typename value, typename key>
std::ostream & LIB::NAME_A <value, key>::operator << (std::ostream & stream) const
{
	for (const typename /*LIB::container::*/NAME_A <value, key>::container & element : * this)
	{
		//os << indentation << element.k;
		
		//operator << (os, val, indenation + "\t");
		stream/* << indentation*/ << '[' << element.k << "] => [" << element.v << ']' << std::endl;
	}
	
	return stream;
}

//template <typename value, typename key>
//std::ostream & /*LIB::NAME_A <value, key>::*/operator << (std::ostream & os, const LIB::NAME_A <LIB::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any> & val/*, const std::string & indentation*/)
//{
//	for (const typename LIB::NAME_A <LIB::NAME_A <LIB::container::any, LIB::container::any>, LIB::container::any>::container & element : val)
//	{
//		//os << indentation << element.k;
//		
//		//operator << (os, val, indenation + "\t");
//		os/* << indentation*/ << '[' << element.k << "] => [" << element.v << ']' << std::endl;
//	}
//}