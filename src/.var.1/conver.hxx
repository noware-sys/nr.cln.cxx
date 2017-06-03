// Conversion functions:

//operator any (void) const;
//operator const noware::container::text (void) const;
/*
// Explicit
const std::string to_text (void) const;
const nr to_nr (void) const;
const long double to_long_double (void) const;
const double to_double (void) const;
const float to_float (void) const;
const signed long long int to_signed_long_long_int (void) const;
const unsigned long long int to_unsigned_long_long_int (void) const;
const signed long int to_signed_long_int (void) const;
const unsigned long int to_unsigned_long_int (void) const;
const signed int to_signed_int (void) const;
const unsigned int to_unsigned_int (void) const;
const signed short int to_signed_short_int (void) const;
const unsigned short int to_unsigned_short_int (void) const;
const bool to_bool (void) const;
*/
// Implicit
operator const std::string (void) const;
//operator const char [] (void) const;
//operator const char * (void) const;
//operator const signed char * (void) const;
//operator const unsigned char * (void) const;

operator const nr (void) const;
//operator const math::numbers::natural (void) const;

operator const long double (void) const;
operator const double (void) const;
operator const float (void) const;

operator const signed long long int (void) const;
operator const signed long int (void) const;
operator const signed int (void) const;
operator const signed short int (void) const;

operator const unsigned long long int (void) const;
operator const unsigned long int (void) const;
operator const unsigned int (void) const;
operator const unsigned short int (void) const;

operator const bool (void) const;
