// operator >

const noware::any noware::any::operator > (const any & other) const
{
	switch (_t)
	{
		case t::nr:
			switch (other._t)
			{
				case t::nr:
					//std::cout << "noware::var::operator>()::content.number > other.content.number==[" << (content.number > other.content.number) << ']' << std::endl;
					
					return nr > other.nr;
				//case container::type::generic:
				default:
					return false;
					//return text ().length () > other.content.text.length ();
			}
		//case container::type::generic:
		default:
			return false;
			//return content.text.length () > other.text ().length ();
	}
}
/*
const noware::any noware::any::operator > (const text & other) const
{
	return *this > any (other);
}
*/
const noware::any noware::any::operator > (const std::string & other) const
{
	return *this > any (other);
}

const noware::any noware::any::operator > (const char other []) const
{
	return *this > any (other);
}

const noware::any noware::any::operator > (const char *& other) const
{
	return *this > any (other);
}

const noware::any noware::any::operator > (const char & other) const
{
	return *this > any (other);
}

const noware::any noware::any::operator > (const signed char & other) const
{
	return *this > any (char (other));
}

const noware::any noware::any::operator > (const unsigned char & other) const
{
	return *this > any (char (other));
}

const noware::any noware::any::operator > (const noware::nr & other) const
{
	return *this > any (other);
}

const noware::any noware::any::operator > (const long double & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const double & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const float & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const signed long long int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const unsigned long long int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const signed long int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const unsigned long int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const signed int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const unsigned int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const signed short int & other) const
{
	return *this > any (noware::tool::string (other));
}

const noware::any noware::any::operator > (const unsigned short int & other) const
{
	return *this > any (noware::tool::string (other));
}

//const noware::any noware::any::operator > (const bool & other) const
//{
//	return *this > any (other);
//}

