#include "Polynomial.h"

#include <ppltasks.h>

/*                   Constructors                                     */
Polynomial::Polynomial()
{
    //initializes array to 0
}


Polynomial::~Polynomial()
{
    //destructor
}

Polynomial::Polynomial(const Polynomial& obj)
{
    this->poly = obj.poly;
}


/*                   MemberFunctions                                     */

int Polynomial::degree() const
{
    int max = 0;
    for(int i = 0;i < poly.getCurrentSize(); i++){
        if(poly.getElement(i).getExp() > max)
            max = poly.getElement(i).getExp();
    }
    return max;
    
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

/*                         Helper Method                                     */
void Polynomial::changeCoefficient(int newCoefficient, int power)
{
    
    for(int i = 0; i < poly.getCurrentSize(); i++){
        if(poly.getElement(i).getExp() == power){
            poly.remove(poly.getElement(i));
            Term temp(newCoefficient, power);
            poly.add(temp);
            return;
        }
    }
    Term newterm(newCoefficient,power);
    poly.add(newterm);
        
    
}

void Polynomial::addTerm(const Term& obj) {

    // if (obj.poly.getElement(i). == 0) {
    //     // don't add terms with zero coefficients
    //     return;
    // }
    Term term = obj;
        if (poly.contains(term))
        {
            // if the term already exists, add the coefficients
            for(int i = 0; i < poly.getCurrentSize(); i++)
            {
                Term temp = poly.getElement(i);
                if (temp.getExp() == term.getExp())
                {
                    int newCoef = temp.getCoef() + term.getCoef();
                    if (newCoef == 0)
                    {
                        // if the sum of coefficients is zero, remove the old term
                        poly.remove(temp);
                    } else {
                        // otherwise, replace the old term with the new term
                        Term newTerm(newCoef, term.getExp());
                        poly.remove(temp);
                        poly.add(newTerm);
                    }
                    // we found the matching term, so we can exit the loop
                    return;
                }
            }
        }
        // if we reach here, the term was not found in the polynomial
        poly.add(term);
    }

    

    
  


/*                   OperatorOverload                                     */
Polynomial Polynomial::operator+(const Polynomial& obj) const
{

    Polynomial result;

    for (int i = 0; i < poly.getCurrentSize(); i++) { 
        result.poly.add(poly.getElement(i));
    }

    for (int i = 0; i < obj.poly.getCurrentSize(); i++) 
        {
        bool found = false; 
        for (int j = 0; j < result.poly.getCurrentSize(); j++) 
            {
            if (result.poly.getElement(j).getExp() == obj.poly.getElement(i).getExp()) 
                {
                result.poly.add(result.poly.getElement(j) += obj.poly.getElement(i));
                result.poly.remove(result.poly.getElement(j));
                found = true;
                break;
                }
				
            }
        if (!found) 
            result.poly.add(obj.poly.getElement(i));
        }
    return result;
}




bool Polynomial::operator==(const Polynomial& obj) const {
    if (poly.getCurrentSize() != obj.poly.getCurrentSize()) {
        return false;
    }
    
    return true;
}

ostream& operator<<(ostream& out, const Polynomial& obj)
{
    

       obj.poly.display();
    
    return out;
}



