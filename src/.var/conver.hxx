// Conversion functions:

//virtual operator const noware::container::text (void) const;
virtual operator std::string const (void) const;
//virtual operator  char const [] const (void) const;
virtual operator char const * const (void) const;

virtual operator char const (void) const;
//virtual operator const unsigned char (void) const;
//virtual operator const signed char (void) const;

virtual operator cln::nr const (void) const;
virtual operator cln::nr::complex const (void) const;
virtual operator cln::nr::real const (void) const;
virtual operator cln::nr::rational const (void) const;
virtual operator cln::nr::integer const (void) const;
virtual operator cln::nr::_float const (void) const;
virtual operator cln::nr::short_float const (void) const;
virtual operator cln::nr::single_float const (void) const;
virtual operator cln::nr::double_float const (void) const;
virtual operator cln::nr::long_float const (void) const;

//virtual operator long double const (void) const;
virtual operator double const (void) const;
virtual operator float const (void) const;

//virtual operator unsigned long long int const (void) const;
virtual operator unsigned long int const (void) const;
virtual operator unsigned int const (void) const;
//virtual operator const unsigned short int (void) const;

//virtual operator signed long long int const (void) const;
virtual operator signed long int const (void) const;
virtual operator signed int const (void) const;
//virtual operator signed short int const (void) const;
