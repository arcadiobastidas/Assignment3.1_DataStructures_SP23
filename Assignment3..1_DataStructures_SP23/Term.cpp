#include "Term.h"

Term::Term()
{
    coef = 0;
    exp = 0;
}

Term::Term(int aCoef, int anExp)
{
    this->coef = aCoef;
    this->exp = anExp;
}

Term::Term(const Term& obj)
{
 //test
    this-> coef = obj.getCoef();
    this->exp = obj.getExp();
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

Term& Term::operator+=(const Term& obj)
{
    if (exp == obj.exp)
    {
        coef += obj.coef;
    }
    else
    {
        // Handle error or throw exception
        cerr << "Error: Exponents do not match" << endl;
    }
    return *this;
}

bool Term::operator==(const Term& obj) const
{  
        return coef == obj.coef && exp == obj.exp;
  
}

Term Term::operator+(const Term& obj) const
{
    if(getExp()!= obj.getExp())
    {
        cout << " Terms Must be equal!! ";
    }
    return Term(coef + obj.coef, exp);
}




istream& operator>>(istream& in, Term& obj)
{
    cout << "Enter coefficient: ";
    in >> obj.coef;
    cout << "Enter exponent: ";
    in >> obj.exp;

    return in;
}

ostream& operator<<(ostream& out, const Term& obj)
    {
    
      out << obj.getCoef() << "x^" << obj.getExp() << " ";
   return out;
}
