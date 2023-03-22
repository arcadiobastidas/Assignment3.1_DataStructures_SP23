#ifndef POLYNOMIAL
#define POLYNOMIAL

#include "ArrayBag.cpp"
#include "Term.h"

using namespace std;
class Polynomial 
{
private:
    ArrayBag<Term> poly;

public:
    //constructors
   Polynomial(); //default constructor
   Polynomial(const Polynomial& obj); //copy constructor
   ~Polynomial(); //destructor
  
    //member functions
    
    int degree() const; // Returns the degree of a polynomial.
    int coefficient(int power) const; // Returns the coefficient of the x^power term
    void changeCoefficient(int newCoefficient, int power); //changes coeficient or creates a new one if doesn't exists


    //helper methods
    void addTerm(const Term& obj); // add a term to the list
    
    //Operator Overloads
    Polynomial operator+(const Polynomial& other) const; //add terms
    bool operator==(const Polynomial& other) const; //validate terms
    friend ostream& operator <<(ostream& out, const Polynomial& obj);


};
#endif
