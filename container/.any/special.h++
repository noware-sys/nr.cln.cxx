const any operator ~ (void) const;	// Complement.
//const any operator | (void) const;	// Modulus.
const bool operator ! (void) const;

// Logical AND
const bool operator && (const any &) const;
const bool operator && (const bool &) const;
friend const bool operator && (const bool &, const any &);
// Logical OR
const bool operator || (const any &) const;
const bool operator || (const bool &) const;
friend const bool operator || (const bool &, const any &);

// Incrementation
// Decrementation
//
// Prefix:
const any & operator ++ (void);
const any & operator -- (void);
//
// Suffix / Postfix:
const any operator ++ (signed int);
const any operator -- (signed int);

friend std::ostream & operator << (std::ostream &, const any &)/* const*/;
friend std::istream & operator >> (std::istream &, any &);

