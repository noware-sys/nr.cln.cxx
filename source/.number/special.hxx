/*
const number operator ~ (void) const;	// Complement.
//const number operator | (void) const;	// Modulus.
/*
const bool operator ! (void) const;

// Logical AND
const bool operator && (const number &) const;
const bool operator && (const bool &) const;
friend const bool operator && (const bool &, const number &);
// Logical OR
const bool operator || (const number &) const;
const bool operator || (const bool &) const;
friend const bool operator || (const bool &, const number &);
*/
// Incrementation
// Decrementation
//
// Prefix:
const number & operator ++ (void);
const number & operator -- (void);
//
// Postfix / Suffix:
const number operator ++ (const int);
const number operator -- (const int);

friend std::ostream & operator << (std::ostream &, const number &)/* const*/;
friend std::istream & operator >> (std::istream &, number &);

