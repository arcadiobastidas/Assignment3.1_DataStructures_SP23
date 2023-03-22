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
        int maxExp = 0;
        for (int i = 0; i < this->poly.getCurrentSize(); i++) {
              if (this->poly.getElement(i).getExp()> maxExp) {
                maxExp = this->poly.getElement(i).getExp();
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

/*                         Helper Method                                     */
void Polynomial::changeCoefficient(int newCoefficient, int power)
{
    Term temp;
    // Check if the power already exists in the polynomial
    for(int i = 0; i < poly.getCurrentSize(); i++)
    {
        poly.remove(poly.getElement(i));
        temp.setCoef(newCoefficient);
        temp.setExp(power);
        poly.add(temp);
    }
        
    
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
    Term temp1;
    Term temp2;

    int thatExp;
    int thatCoef;
    int thisExp;

    int thisCoef;
    int finalCoef;
    int size = obj.poly.getCurrentSize();
    
    for(int i = 0; i < size; i++)
    {
        
        thatExp = obj.poly.getElement(i).getExp();
        thisExp = poly.getElement(i).getExp();
        thatCoef = obj.poly.getElement(i).getCoef();
        thisCoef = poly.getElement(i).getCoef();
        if(thisExp == thatExp)
        {
            finalCoef = thisCoef + thatCoef;
            Term temp(finalCoef,thatExp);
            result.addTerm(temp);
        } else
        {
            cout<< "Objects can't be added!" << endl;
            Term temp2(thatCoef, thatExp);
            result.addTerm(temp2);
        }
            
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



