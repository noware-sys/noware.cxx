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
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::set (key_t const &/* key*/, val_t const &/* value*/)
{
	return false;
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
	val_t const * val;
	return get (key, val);
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
bool const noware::contnr::array <val_t, key_t/*, alloc_t*/>::remove (key_t const &/* key*/)
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

template <typename val_t, typename key_t/*, typename alloc_t*/>
val_t & noware::contnr::array <val_t, key_t/*, alloc_t*/>::operator [] (key_t const & key)
{
	// A basic implementation
	// Add, if needed, and get the value by this key
	
	val_t const * val;
	
	if (!get (key, val))
	{
		val = new val_t const ();
		//if (val == nullptr)
		//	;
		set (key, *val);
	}
	
	return *val;
}

template <typename val_t, typename key_t/*, typename alloc_t*/>
val_t & noware::contnr::array <val_t, key_t/*, alloc_t*/>::operator [] (std::nullptr_t const &/* null*/)
{
	// Add a new value
	val_t val;
	//set (value);
	return val;
}
