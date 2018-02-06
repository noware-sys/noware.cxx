// constructors

noware::var::var (void)
{
	//_exact = true;
}

noware::var::var (noware::var const & other)
{
	*this = other;
}
/*
noware::var::var (noware::container::text const & other)
{
	*this = other;
}
*/
noware::var::var (std::string const & other)
{
	*this = other;
}

noware::var::var (char const other [])
{
	//*this = std::string (other);
	*this = other;
}
/*
noware::var::var (unsigned char other [])
{
	*this = other;
}

noware::var::var (signed char other [])
{
	*this = other;
}
*/

/*
noware::var::var (signed char other [])
{
	*this = std::string (other);
}

noware::var::var (unsigned char other [])
{
	*this = std::string (other);
}
*/
//noware::var::var (char *const & other)
//{
//	*this = noware::tool::string (other);
//}
/*
noware::var::var (signed char *const & other)
{
	*this = std::string (other);
}

noware::var::var (unsigned char *const & other)
{
	*this = std::string (other);
}
*/
noware::var::var (char const & other)
{
	//*this = noware::tool::string (other);
	*this = other;
}
/*
noware::var::var (signed char const & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}

noware::var::var (unsigned char const & other)
{
	//*this = noware::tool::string (char (other));
	*this = other;
}
*/
noware::var::var (cln::nr const & other)
{
	*this = other;
}

noware::var::var (cln::nr::complex const & other)
{
	*this = other;
}

noware::var::var (cln::nr::real const & other)
{
	*this = other;
}

noware::var::var (cln::nr::rational const & other)
{
	*this = other;
}

noware::var::var (cln::nr::integer const & other)
{
	*this = other;
}

noware::var::var (cln::nr::_float const & other)
{
	*this = other;
}

noware::var::var (cln::nr::short_float const & other)
{
	*this = other;
}

noware::var::var (cln::nr::single_float const & other)
{
	*this = other;
}

noware::var::var (cln::nr::double_float const & other)
{
	*this = other;
}

noware::var::var (cln::nr::long_float const & other)
{
	*this = other;
}

noware::var::var (long double const & other)
{
	*this = other;
}

noware::var::var (double const & other)
{
	*this = other;
}

noware::var::var (float const & other)
{
	*this = other;
}

noware::var::var (unsigned long long int const & other)
{
	*this = other;
}

noware::var::var (unsigned long int const & other)
{
	*this = other;
}

noware::var::var (unsigned int const & other)
{
	*this = other;
}

noware::var::var (unsigned short int const & other)
{
	*this = other;
}

noware::var::var (signed long long int const & other)
{
	*this = other;
}

noware::var::var (signed long int const & other)
{
	*this = other;
}

noware::var::var (signed int const & other)
{
	*this = other;
}

noware::var::var (signed short int const & other)
{
	*this = other;
}
