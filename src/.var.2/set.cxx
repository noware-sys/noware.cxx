// operator =

const noware::var & noware::var::operator = (const var & other)
{
	_txt = other._txt;
	_nr = other._nr;
	_t = other._t;
	
	return *this;
}

const noware::var & noware::var::operator = (const noware::nr & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

/*
const noware::nr & noware::nr::operator = (const text & other)
{
	contnt.text = other;
	contnt.nr = 0;
	
	contnt.t = container::type::generic;
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const std::string & other)
{
	if (nr::is (other))
	{
		_txt = "";
		_nr = other;
		_t = type::nr;
	}
	else
	{
		_txt = other;
		_nr = 0;
		_t = type::txt;
	}
	
	return *this;
}

const noware::var & noware::var::operator = (const char * other)
{
	*this = std::string (other);
	
	return *this;
}
/*
const noware::nr & noware::nr::operator = (const unsigned char other [])
{
	contnt = cln::cl_N (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed char other [])
{
	contnt = cln::cl_N (other);
	
	return *this;
}
*/
/*
const noware::nr & noware::nr::operator = (const signed char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned char other [])
{
	*this = noware::tool::string (other);
	
	return *this;
}
*//*
const noware::nr & noware::nr::operator = (const char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const signed char *& other)
{
	*this = std::string (other);
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned char *& other)
{
	*this = std::string (other);
	
	return *this;
}
*/

const noware::var & noware::var::operator = (const char & other)
{
	*this = noware::string (other);
	
	return *this;
}
/*
const noware::nr & noware::nr::operator = (const signed char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}

const noware::nr & noware::nr::operator = (const unsigned char & other)
{
	//if (noware::tool::is_numeric (other))
	try
	{
		contnt = noware::tool::string (other).c_str ();
	}
	catch (...)
	{
	}
	
	return *this;
}
*/
const noware::var & noware::var::operator = (const complex & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const real & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const rational & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const integer & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const _float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const short_float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const single_float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const double_float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const long_float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const long double & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const double & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const float & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const signed long long int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned long long int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const signed long int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned long int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const signed int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const signed short int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}

const noware::var & noware::var::operator = (const unsigned short int & other)
{
	_txt = "";
	_nr = other;
	_t = type::nr;
	
	return *this;
}
