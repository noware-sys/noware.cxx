// operator ==

const bool noware::var::operator == (const var & other) const
{
	if (_t != other._t)
		return false;
	
	if (_t == type::nr)
		return _nr == other._nr;
	
	return _txt == other._txt;
}

const bool noware::var::operator == (const noware::nr & other) const
{
	if (_t != type::nr)
		return false;
	
	return _nr == other;
}
