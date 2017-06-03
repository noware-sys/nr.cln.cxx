//const bool is (const type &) const;
const type kind (void) const;

/*
const nr operator ~ (void) const;	// Complement.
//const nr operator | (void) const;	// Modulus.
/*
const bool operator ! (void) const;

// Logical AND
const bool operator && (const nr &) const;
const bool operator && (const bool &) const;
friend const bool operator && (const bool &, const nr &);
// Logical OR
const bool operator || (const nr &) const;
const bool operator || (const bool &) const;
friend const bool operator || (const bool &, const nr &);
*/

/*
// Incrementation
// Decrementation
//
*/
// Prefix:
const var & operator ++ (void);
const var & operator -- (void);
//
// Postfix / Suffix:
/*
const nr operator ++ (const int);
const nr operator -- (const int);
*/

friend std::ostream & operator << (std::ostream &, const var &)/* const*/;
friend std::istream & operator >> (std::istream &, var &);
