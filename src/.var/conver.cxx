/*
	operator *type*
	
	conversion operator functions
*/
/*
noware::var::operator const text (void) const
{
	if (content.t == container::type::numeric)
		//return noware::tool::complement (content.number);
		return "";
	else
		return content.text;
}
*/
noware::var::operator std::string const (void) const
{
	if (_type == type::nr)
		return _nr.operator std::string const ();
	else
		return _string;
}

//noware::var::operator const char [] (void) const
//{
//	return std::string (*this).c_str ();
//}

noware::var::operator char const (void) const
{
	//std::string str = std::string (*this);
	std::string const str = operator std::string const ();
	
	if (str.size () == 1)
		return str [0];
	else
		return '\0';
}

noware::var::operator char const * const (void) const
{
	return operator std::string const ().data ();
}

//noware::var::operator const nrs::natural (void) const
//{
//	if (content.t == container::type::numeric)
//		return floor1 (content.number);
//	else
//		return 0;	// A default value.
//}

noware::var::operator cln::nr const (void) const
{
	return _nr;
}

noware::var::operator cln::nr::complex const (void) const
{
	return _nr.operator cln::nr::complex const ();
}

noware::var::operator cln::nr::real const (void) const
{
	return _nr.operator cln::nr::real const ();
}

noware::var::operator cln::nr::rational const (void) const
{
	return _nr.operator cln::nr::rational const ();
}

noware::var::operator cln::nr::integer const (void) const
{
	return _nr.operator cln::nr::integer const ();
}

noware::var::operator cln::nr::_float const (void) const
{
	return _nr.operator cln::nr::_float const ();
}

noware::var::operator cln::nr::short_float const (void) const
{
	return _nr.operator cln::nr::short_float const ();
}

noware::var::operator cln::nr::single_float const (void) const
{
	return _nr.operator cln::nr::single_float const ();
}

noware::var::operator cln::nr::double_float const (void) const
{
	return _nr.operator cln::nr::double_float const ();
}

noware::var::operator cln::nr::long_float const (void) const
{
	return _nr.operator cln::nr::long_float const ();
}

/*
noware::var::operator long double const (void) const
{
	return double (*this);
}
*/

noware::var::operator double const (void) const
{
	return _nr.operator double const ();
}

noware::var::operator float const (void) const
{
	return _nr.operator float const ();
}

/*
noware::var::operator signed long long int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::var::operator unsigned long long int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/

noware::var::operator signed long int const (void) const
{
	return _nr.operator signed long int const ();
}

noware::var::operator unsigned long int const (void) const
{
	return _nr.operator unsigned long int const ();
}

noware::var::operator signed int const (void) const
{
	return _nr.operator signed int const ();
}

noware::var::operator unsigned int const (void) const
{
	return _nr.operator unsigned int const ();
}

/*
noware::var::operator signed short int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}

noware::var::operator unsigned short int const (void) const
{
	//if (content.t == container::type::numeric)
	//	return double_approx (content);
	//else
		return 0;	// A default value.
}
*/
/*
noware::var::operator bool const (void) const
{
	if (content.t == container::type::numeric)
	{
		return content.number != 0;
	}
	else
	{
		return content.text.length () != 0;
	}
}
*/
