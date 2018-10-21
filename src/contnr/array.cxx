#pragma once

//#include ".array/.cxx"
//#include <type_traits>

//#include "../serial.cxx"
#include <cln/nr.cxx>
#include "../var.cxx"

// #include <typeinfo>
//#include <iostream>
// Array.CPP:
// Standard library:
//#include <utility>	// For "std::swap ()".

/*
// Static constants.
template <typename val_t, typename key_t>
value noware::array <val_t, key_t>::value;

template <typename val_t, typename key_t>
key noware::array <val_t, key_t>::key;
*/

//
// For array functionality
//
/*
template <typename val_t, typename key_t>
template <typename archive>
void noware::contnr::array <val_t, key_t>::serialize (archive &, const unsigned int & version)
{
}
*/

//const std::string noware::array::group_default = "array";
/*
template <typename val_t, typename key_t>
noware::array <val_t, key_t>::array (void)
{
}

template <typename val_t, typename key_t>
noware::array <val_t, key_t>::~array (void)
{
}
*/
template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::get (key_t const &/* key*/, val_t const * &/* value*/) const
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::get (key_t const &/* key*/, val_t &/* value*/) const
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::set (key_t const &/* key*/, val_t const &/* value*/)
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
val_t &/* value*/ noware::contnr::array <val_t, key_t/*, alloc_t*/>::operator [] (key_t const & key)
{
	val_t const * val_ptr;
	if (get (key, val_ptr))
		return *(const_cast <val_t *> (val_ptr));
	
	// presumption: "set()" makes an internal copy of the value (operator=)
	if (!set (key, val_dft))
		// we must return something
		return val_dft;
	
	// presumption: "get()" returns the internal copy
	get (key, val_ptr);
	return *(const_cast <val_t *> (val_ptr));
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::clear (void)
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
const cln::nr noware::contnr::array <val_t, key_t/*, alloc_t*/>::size (void) const
{
	return 0;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::exist (key_t const & key) const
{
	//val_t const * val;
	val_t val;
	return get (key, val);
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::del (key_t const &/* key*/)
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::rename (key_t const &/* old_k*/, key_t const &/* new_k*/)
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::full (void) const
{
	return false;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::empty (void) const
{
	return size () <= 0;
}

/*
template <typename val_t, typename key_t>
val_t & noware::contnr::array <val_t, key_t>::operator [] (key_t const & key)
{
	// A basic implementation
	// Get the value by this key, adding it if needed
	
	val_t const * val;
	
	if (!get (key, val))
	{
		val = new val_t const ();
		//if (val == nullptr)
		//	;
		if (!set (key, *val))
		{
			delete val;
			// return a reference to a local
			//return val_t ();
		}
	}
	
	return *val;
}
*/

/*
template <typename val_t, typename key_t>
val_t & noware::contnr::array <val_t, key_t>::operator [] (std::nullptr_t const &)
{
	// Add a new value
	val_t val;
	//set (value);
	return val;
}
*/
