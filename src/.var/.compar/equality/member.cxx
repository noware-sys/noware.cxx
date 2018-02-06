// operator ==

bool const noware::var::operator == (var const & other) const
{
	if (_type != other._type)
		return false;
	else
	{
		if (_type == type::nr)
		{
			if (other._type != type::nr)
				return false;
			else
				return _nr == other._nr;
		}
		else //if (_type == type::string)
		{
			if (other._type != type::string)
				return false;
			else
				return _string == other._string;
		}
	}
	
	// to satisfy the compiler
	return false;
}
/*
bool const noware::var::operator == (text const & other) const
{
	return *this == nr (other);
}
*/
bool const noware::var::operator == (std::string const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (char const * const other) const
{
	return *this == var (other);
}
/*
bool const noware::var::operator == (unsigned char other []) const
{
	//return *this == nr (other);
	return val == nr (other);
}

bool const noware::var::operator == (signed char other []) const
{
	//return *this == nr (other);
	return val == nr (other);
}
*/
//bool const noware::var::operator == (char const * const other) const
//{
//	return *this == nr (other);
//}

bool const noware::var::operator == (char const & other) const
{
	return *this == var (other);
}
/*
bool const noware::var::operator == (signed char const & other) const
{
	return *this == nr (other);
}

bool const noware::var::operator == (unsigned char const & other) const
{
	return *this == nr (other);
}
*/

bool const noware::var::operator == (cln::nr const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::complex const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::real const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::rational const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::integer const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::_float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::short_float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::single_float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::double_float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (cln::nr::long_float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (long double const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (double const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (float const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (signed long long int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (unsigned long long int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (signed long int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (unsigned long int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (signed int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (unsigned int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (signed short int const & other) const
{
	return *this == var (other);
}

bool const noware::var::operator == (unsigned short int const & other) const
{
	return *this == var (other);
}
