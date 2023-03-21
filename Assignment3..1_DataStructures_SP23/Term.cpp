#include "Term.h"

Term::Term()
{
    coef = 0;
    exp = 0;
}

Term::Term(int aCoef, int anExp)
{
    setCoef(aCoef);
    setExp(anExp);
}

Term::Term(const Term& obj)
{
    coef = obj.coef;
    exp = obj.exp;
}

void Term::setCoef(int aCoef)
{
    this->coef = aCoef;
}

void Term::setExp(int anExp)
{
    this->exp = exp;
}

int Term::getCoef() const
{
    return coef;
}

int Term::getExp() const
{
    return exp;
}

istream& operator>>(istream& in, Term& obj)
{
   cout << "Enter coeficient: ";
    in >> obj.coef;
    cout << "Enter exponent: ";
    in >> obj.exp;

    return in;
}

ostream& operator<<(ostream& out, const Term& obj)
{
    cout<<"Test Printing term class" << endl;
    out << obj.exp << endl;
    out << obj.coef << endl;
    return out;
}
