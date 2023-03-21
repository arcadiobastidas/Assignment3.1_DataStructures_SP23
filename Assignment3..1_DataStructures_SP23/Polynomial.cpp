﻿#include "Polynomial.h"

Polynomial::Polynomial()
{
    
}

Polynomial::Polynomial(ArrayBag<Term> aPoly)
{
    
    for(int i = 0; i < poly.getCurrentSize(); i++)
    poly.add(addTerm(temp));
}

Polynomial::~Polynomial()
{
    //destructor
    
}

int Polynomial::degree() const
{
        int maxExp = 0;
        for (int i = 0; i < poly.getCurrentSize(); i++) {
            if (poly.getElement(i).getExp() > maxExp) {
                maxExp = poly.getElement(i).getExp();
            }
        }
        return maxExp;
    
}

int Polynomial::coefficient(int power) const
{  
        for (int i = 0; i < poly.getCurrentSize(); i++) {
            if (poly.getElement(i).getExp() == power) {
                return poly.getElement(i).getCoef();
            }
        }
        return 0; // return 0 if the power is not found
}

void Polynomial::changeCoefficient(int newCoefficient, int power)
{
      for (int i = 0; i < poly.getCurrentSize(); i++) {
            if (poly.getElement(i).getExp() == power) {
                poly.getElement(i).setCoef(newCoefficient);
                return;
            }
        }
        // If the power is not found, add a new term to the polynomial with the specified coefficient and power
        Term newTerm(newCoefficient, power);
        poly.add(newTerm);
    
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
        // Create a new polynomial to store the result
        Polynomial result;

        // Loop over the terms in the first polynomial and add them to the result
        for (int i = 0; i < poly.getCurrentSize(); i++) {
            result.poly.add(poly.getElement(i));
        }

        // Loop over the terms in the second polynomial and add them to the result
        for (int i = 0; i < other.poly.getCurrentSize(); i++) {
            result.poly.add(other.poly.getElement(i));
        }

        // Return the new polynomial
        return result;
    

}

bool Polynomial::operator==(const Polynomial& obj) const {
    if (poly.getCurrentSize() != obj.poly.getCurrentSize()) {
        return false;
    }
    
    return true;
}

ArrayBag<Term> Polynomial::getPoly()
{
   
        return poly;
    
}

void Polynomial::addTerm(const Term& term) {
    if (term.getCoef() == 0) {
        // don't add terms with zero coefficients
        return;
    }
    if (poly.contains(term))
    {
        // if the term already exists, add the coefficients
        for(int i = 0; poly.getCurrentSize(); i++){
            Term temp = poly.getElement(i);
            int newCoef = temp.getCoef() + term.getCoef();
            if (newCoef == 0) {
                // if the sum of coefficients is zero, remove the old term
                poly.remove(temp);
            } else {
                // otherwise, replace the old term with the new term
                Term newTerm(newCoef, term.getExp());
                poly.remove(temp);
                poly.add(temp);
            }
        }
    }
        else
            
                       
            // otherwise, just add the new term
            poly.add(term);
        
    
  
}

ostream& operator<<(ostream& out, const Polynomial& obj)
{
    cout << "Test Printing term class" << endl;
    //cout << 
    return out;
}



