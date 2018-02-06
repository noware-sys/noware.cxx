// operator -=

const noware::var noware::var::operator -= (const var & other)
{
	_nr -= other._nr;
	return _nr;
}

const noware::var noware::var::operator -= (const noware::nr & other)
{
	_nr -= other;
	return _nr;
}
