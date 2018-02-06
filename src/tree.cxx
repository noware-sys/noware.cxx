#pragma once

//#include "entity.h++"
#include <iostream>
//#include "../math.h++"

#include "serial.cxx"
//#include "misc/itr.cxx"
#include "var.cxx"


template <typename val_t, typename key_t_t>
template <typename archive>
void noware::tree <val_t, key_t_t>::serialize (archive & arch, unsigned int const &/* version*/)
{
	arch & _lit;
	arch & lit;
	arch & grp;
}

template <typename val_t, typename key_t_t>
std::string const noware::tree <val_t, key_t_t>::serialize (void) const
{
	return noware::serialize <noware::tree <val_t, key_t_t>> (*this);
}

template <typename val_t, typename key_t_t>
bool const noware::tree <val_t, key_t_t>::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::tree <val_t, key_t_t>> (serial, *this);
}

template <typename val_t, typename key_t_t>
bool const noware::tree <val_t, key_t_t>::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::tree <val_t, key_t_t>> (serial, *this);
}

std::map <key_t, val_t>::iterator & noware::tree <val_t, key_t_t>::begin (void) const
{
	return grp.begin ();
}

std::map <key_t, val_t>::iterator & noware::tree <val_t, key_t_t>::end (void) const
{
	return grp.end ();
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t>::tree <val_t, key_t> (void)
{
	_lit = true;
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t>::tree <val_t, key_t> (val_t const & other)
{
	*this = other;
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t>::tree <val_t, key_t> (tree <val_t, key_t> const & other)
{
	*this = other;
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t> const & noware::tree <val_t, key_t>::operator = (val_t const & other)
{
	_lit = true;
	grp.clear ();
	lit = other;
	return *this;
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t> const & noware::tree <val_t, key_t>::operator = (tree <val_t, key_t> const & other)
{
	_lit = false;
	grp = other;
	return *this;
}

template <typename val_t, typename key_t>
val_t & noware::tree <val_t, key_t>::operator * (void)
{
	return lit;
}

template <typename val_t, typename key_t>
noware::tree <val_t, key_t> & noware::tree <val_t, key_t>::operator [] (key_t const & _k)
{
	_lit = false;
	return grp [k];
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::unset (const key_t & k)
{
	grp.erase (k);
	return true;
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::exist (const key_t & _k, const bool & recursive) const
{
	if (_lit)
		return false;
	/*
	if (recursive)
	{
		for (auto & element : * this)
		{
			if (element.exist (_k, recursive))
			{
				return true;
			}
		}
		
		return false;
	}
	*/
	//else
	//{
		return grp.count (k) > 0;
	//}
}

template <typename val_t, typename key_t>
noware::nr const noware::tree <val_t, key_t>::size (bool const & recursive, bool const & grouped) const
{
	if (_lit)
			return 1;
	
	/*
	if (recursive)
	{
		unsigned short int additional = grouped ? 1 : 0;
		//math::numbers::natural count = 0;
		nr::natural count = 0;
		
		for (auto & element : * this)
		{
			count += element.size (recursive, grouped) + additional;
		}
		
		return count;
	}
	*/
	//else
	//{
		return grp.size ();
	//}
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::clear (void)
{
	grp.clear ();
	return true;
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::rename (key_t const & old_, key_t const & new_)
{
	if (_lit)
		return false;
	
	if (new_ == old_)
		return true;
	
	if (grp.count (old_) == 0)
		return false;
	
	grp [new_] = grp.at (old_);
	grp.erase (old_);
	
	return true;
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::operator == (tree <val_t, key_t> const & other) const
{
	if (_lit && other._lit)
		return lit == other.lit;
	
	if (grp.size () != other.grp.size ())
		return false;
	
	for (val_t const & item : grp)
	{
		// no corresponding element in other
		if (other.count (item.first) == 0)
			return false;
		// the element is not the same
		if (other.at (item.first) != item.second)
			return false;
	}
	
	return true;
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::operator != (tree <val_t, key_t> & const other) const
{
	return !(*this == other);
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::operator == (val_t const & other) const
{
	if (!_lit)
		return false;
	
	return lit == other;
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::operator != (val_t const & other) const
{
	return !(*this == other);
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::empty (void) const
{
	return grp.empty ();
}

template <typename val_t, typename key_t>
bool const noware::tree <val_t, key_t>::full (void) const
{
	return false;
}

template <typename val_t, typename key_t>
bool const & noware::tree <val_t, key_t>::literal (void) const
{
	return _lit;
}
