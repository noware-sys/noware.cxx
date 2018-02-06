//const bool is (const type &) const;
type const & t (void) const;

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
var const & operator ++ (void);
var const & operator -- (void);
//
// Postfix / Suffix:
/*
const nr operator ++ (const int);
const nr operator -- (const int);
*/

friend std::ostream & operator << (std::ostream &, var const &)/* const*/;
friend std::istream & operator >> (std::istream &, var &);
