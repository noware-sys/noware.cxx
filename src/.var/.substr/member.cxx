// operator -

noware::var const noware::var::operator - (void) const
{
	if (_type == type::nr)
		return -_nr;
	
	return *this;
}
