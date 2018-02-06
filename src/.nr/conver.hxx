// Conversion functions:

//virtual operator const noware::container::text (void) const;
virtual operator std::string const (void) const;
//virtual operator  char const [] const (void) const;
virtual operator char const * const (void) const;

virtual operator char const (void) const;
//virtual operator const unsigned char (void) const;
//virtual operator const signed char (void) const;

virtual operator complex const (void) const;
virtual operator real const (void) const;
virtual operator rational const (void) const;
virtual operator integer const (void) const;
virtual operator _float const (void) const;
virtual operator short_float const (void) const;
virtual operator single_float const (void) const;
virtual operator double_float const (void) const;
virtual operator long_float const (void) const;

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
