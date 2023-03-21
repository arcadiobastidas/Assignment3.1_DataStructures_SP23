#ifndef POLYNOMIAL
#define POLYNOMIAL

#include "ArrayBag.cpp"
#include "Term.h"

using namespace std;
class Polynomial : public Term
{
private:
    ArrayBag<Term> poly;

public:
    //constructors
   Polynomial(); //default constructor
   Polynomial(ArrayBag<Term> aPoly); // parameter constructor
   ~Polynomial(); //destructor

void addTerm(const Term& term);

    
    //member functions
    int degree() const;

    // Returns the coefficient of the x^power term
    int coefficient(int power) const;

    //changes coeficient or creates a new one if doesn't exists
    void changeCoefficient(int newCoefficient, int power);

    //adds two terms
    Polynomial operator+(const Polynomial& other) const ;
    bool operator==(const Polynomial& other) const;

    ArrayBag<Term> getPoly();

    friend ostream& operator <<(ostream& out, const Polynomial& obj);


};
#endif
