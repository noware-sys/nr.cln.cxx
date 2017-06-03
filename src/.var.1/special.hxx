// Complement.
const var operator ~ (void) const;
// Modulus.
//const var operator | (void) const;
// Logical NOT
const bool operator ! (void) const;

// Logical AND
const bool operator && (const var &) const;
const bool operator && (const bool &) const;
friend const bool operator && (const bool &, const var &);
// Logical OR
const bool operator || (const var &) const;
const bool operator || (const bool &) const;
friend const bool operator || (const bool &, const var &);

// Incrementation
// Decrementation
//
// Prefix:
const var & operator ++ (void);
const var & operator -- (void);
//
// Postfix / Suffix:
const var operator ++ (signed int);
const var operator -- (signed int);

friend std::ostream & operator << (std::ostream &, const var &)/* const*/;
friend std::istream & operator >> (std::istream &, var &);

