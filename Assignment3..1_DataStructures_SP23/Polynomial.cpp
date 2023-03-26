#include "Polynomial.h"

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
    

    for (int i = 0; i < obj.poly.getCurrentSize(); i++)
        {
        bool hasElement = result.poly.contains(obj.poly.getElement(i)); 
        for (int j = 0; j < obj.poly.getCurrentSize(); j++)  
            {
            if (result.poly.getElement(j).getExp() == obj.poly.getElement(i).getExp())  
                {
                result.addTerm(result.poly.getElement(j) += obj.poly.getElement(i));
                result.poly.remove(result.poly.getElement(j));
                hasElement = true;
               
                }
				
            }
        if (!hasElement) // si no se encontro un termino con la misma potencia los añadimos al final
            result.addTerm(obj.poly.getElement(i));
        }
    return result; //retornar resultado
}


ostream& operator<<(ostream& out, const Polynomial& obj)
{
    for (int i = 0; i < obj.poly.getCurrentSize(); i++){

        if(i >= 0 && i < ( obj.poly.getCurrentSize()-1))
        {
            out << obj.poly.getElement(i);
            out << " + "; 
        } else 
            out << obj.poly.getElement(i);
        }
        
       
    return out;
    
   
}





