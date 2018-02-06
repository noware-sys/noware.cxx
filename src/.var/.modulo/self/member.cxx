// operator %=

noware::var const noware::var::operator %= (var const & other)
{
	if (_type == type::nr && other._type == type::nr)
	{
	}
	
	return *this;
}
/*
noware::var const noware::var::operator %= (text const & other)
{
	return *this %= var (other);
}
*/
noware::var const noware::var::operator %= (std::string const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (char const * const other)
{
	*this %= var (other);
	return *this;
}
/*
noware::var const noware::var::operator %= (char const * const & other)
{
	return *this %= var (other);
}
*/
noware::var const noware::var::operator %= (char const & other)
{
	*this %= var (other);
	return *this;
}
/*
noware::var const noware::var::operator %= (signed char const & other)
{
	return *this %= var (other);
}

noware::var const noware::var::operator %= (unsigned char const & other)
{
	return *this %= var (other);
}
*/
//noware::var const noware::var::operator %= (math::var const & other)
//{
//	return *this %= var (other);
//}

noware::var const noware::var::operator %= (cln::nr const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::complex const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::real const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::rational const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::integer const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::_float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::short_float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::single_float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::double_float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (cln::nr::long_float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (long double const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (double const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (float const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (signed long long int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (unsigned long long int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (signed long int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (unsigned long int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (signed int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (unsigned int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (signed short int const & other)
{
	*this %= var (other);
	return *this;
}

noware::var const noware::var::operator %= (unsigned short int const & other)
{
	*this %= var (other);
	return *this;
}
