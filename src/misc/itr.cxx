#pragma once

/*
template <typename val_t>
noware::misc::itr <val_t> (itr <val_t> const & other)
{
	content = other.content;
}
*/

/*
template <typename val_t>
const itr <val_t> noware::misc::itr <val_t>::begin (void) const
{
	return *this;
}

template <typename val_t>
const itr <val_t> noware::misc::itr <val_t>::end (void) const
{
	return *this;
}
*/

/*
template <typename val_t>
const val_t noware::misc::itr <val_t>::operator * (void) const
{
	val_t temp;
	return temp;
}
*/

template <typename val_t>
bool const noware::misc::itr <val_t>::operator != (itr <val_t> const & other) const
{
	return !(*this == other);
}

template <typename val_t>
itr <val_t> const noware::misc::itr <val_t>::operator ++ (void)
{
	return *this;
}

template <typename val_t>
bool const noware::misc::itr <val_t>::operator == (itr <val_t> const & other) const
{
	return false;
}

template <typename val_t>
itr <val_t> const noware::misc::itr <val_t>::operator -- (void)
{
	return *this;
}
