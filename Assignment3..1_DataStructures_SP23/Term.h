#ifndef TERM
#define TERM
#include <iostream>

using namespace std;

class Term
{
private:
    int coef; //Hold the coefficient int data type of the term.
    int exp; // Hold the exponent int data type of the term.

public:
    //constructors

    Term(); //Default Constructor
    Term(int aCoef, int anExp); //parameter constructor
    Term(const Term& obj); //copy constructor

    //setters
    void setCoef(int aCoef); //set coeficient
    void setExp(int anExp); //set an exponent

    //getters

    int getCoef() const;
    int getExp() const;

    //overloading stream operators
    friend istream& operator >>(istream& in, Term& obj);
    friend ostream& operator <<(ostream& out, const Term& obj);

    //overloading binary operators

    Term& operator+=(const Term& obj);
    bool operator==(const Term& other) const;

    Term operator+(const Term& obj) const;
};
#endif

