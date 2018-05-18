// operator =

noware::var const & noware::var::operator = (var const & other)
{
	_type = other._type;
	_string = other._string;
	_nr = other._nr;
	
	return *this;
}
/*
noware::var const & noware::var::operator = (text const & other)
{
	contnt.text = other;
	contnt.nr = 0;
	
	contnt.t = container::type::generic;
	
	return *this;
}
*/
noware::var const & noware::var::operator = (std::string const & other)
{
	if (cln::nr::valid (other))
	{
		_type = type::nr;
		_string = "";
		_nr = other;
	}
	else
	{
		_type = type::string;
		_string = other;
		_nr = 0;
	}
	
	return *this;
}

noware::var const & noware::var::operator = (char const * const other)
{
	*this = std::string (other);
	
	return *this;
}
/*
noware::var const & noware::var::operator = (unsigned char const other [])
{
	val = cln::cl_N (other);
	
	return *this;
}

noware::var const & noware::var::operator = (signed char const other [])
{
	val = cln::cl_N (other);
	
	return *this;
}
*/
/*
noware::var const & noware::var::operator = (signed char const other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned char const other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
noware::var const & noware::var::operator = ( char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}

noware::var const & noware::var::operator = (signed char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned char const * const & other)
{
	*this = std::string (other);
	
	return *this;
}
*/

noware::var const & noware::var::operator = (char const & other)
{
	*this = noware::string (other);
	
	return *this;
}
/*
noware::var const & noware::var::operator = (signed char const & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned char const & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}
*/
noware::var const & noware::var::operator = (cln::nr const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::complex const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::real const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::rational const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::integer const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::_float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::short_float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::single_float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::double_float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (cln::nr::long_float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (long double const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (double const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (float const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (signed long long int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned long long int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (signed long int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned long int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (signed int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (signed short int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}

noware::var const & noware::var::operator = (unsigned short int const & other)
{
	_type = type::nr;
	_string = "";
	_nr = other;
	
	return *this;
}
