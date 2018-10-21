#pragma once

#include "serial.hxx"

#include "../serial.cxx"

template <typename archive>
void noware::serial::save (archive &/* arch*/, int unsigned const/* version*/) const
{
}

template <typename archive>
void noware::serial::load (archive &/* arch*/, int unsigned const/* version*/)
{
}

// template <typename archive>
// void noware::serial::serialize (archive &/* arch*/, unsigned int const &/* version* /)
// {
// }

std::string const noware::serial::serialize (void) const
{
	std::string serial;
	noware::serialize <noware::serial> (serial, *this);
	return serial;
}

bool const noware::serial::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::serial> (*this, serial);
}
