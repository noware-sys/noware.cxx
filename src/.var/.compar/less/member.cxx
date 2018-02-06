// operator <

bool const noware::var::operator < (var const & other) const
{
	if (_type == type::nr && other._type == type::nr)
	{
		return _nr < other._nr;
	}
	
	return false;
}
/*
const bool noware::var::operator < (const text & other) const
{
	return *this < nr (other);
}
*/
const bool noware::var::operator < (const std::string & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (char const * const other) const
{
	return *this < var (other);
}
/*
const bool noware::var::operator < (const char *& other) const
{
	return *this < var (other);
}
*/
const bool noware::var::operator < (const char & other) const
{
	return *this < var (other);
}
/*
const bool noware::var::operator < (const signed char & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const unsigned char & other) const
{
	return *this < var (other);
}
*/
const bool noware::var::operator < (const cln::nr & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::complex & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::real & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::rational & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::integer & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::_float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::short_float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::single_float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::double_float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const cln::nr::long_float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const long double & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const double & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const float & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const signed long long int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const unsigned long long int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const signed long int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const unsigned long int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const signed int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const unsigned int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const signed short int & other) const
{
	return *this < var (other);
}

const bool noware::var::operator < (const unsigned short int & other) const
{
	return *this < var (other);
}
