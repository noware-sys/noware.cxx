//static bool const is (std::string const &);
//const bool is (const type &) const;
//const bool is (const category &) const;
type const & t (void) const;

/*
const type kind (void) const;
const category cat (void) const;
*/

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

//std::string const format (void) const;

/*
// Incrementation
// Decrementation
//
*/
// Prefix:
virtual var const & operator ++ (void);
virtual var const & operator -- (void);
//
// Postfix / Suffix:
/*
const nr operator ++ (const int);
const nr operator -- (const int);
*/

/*virtual */friend std::ostream & operator << (std::ostream &, var const &)/* const*/;
/*virtual */friend std::istream & operator >> (std::istream &, var &);
