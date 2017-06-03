static const bool is (const std::string &);
//const bool is (const type &) const;
//const bool is (const category &) const;

const type kind (void) const;
const category cat (void) const;

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
const nr & operator ++ (void);
const nr & operator -- (void);
//
// Postfix / Suffix:
/*
const nr operator ++ (const int);
const nr operator -- (const int);
*/

friend std::ostream & operator << (std::ostream &, const nr &)/* const*/;
friend std::istream & operator >> (std::istream &, nr &);
