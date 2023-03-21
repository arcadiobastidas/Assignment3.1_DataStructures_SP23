#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    Term myTerm(1,5);

    Term myTerm2(-2,5);

    Polynomial myPoly;
    myPoly.addTerm(myTerm);
    myPoly.addTerm(myTerm2);

  cout << myPoly;
   


   
    //myPolynomial.addTerm(myTerm);

    //cout << myPolynomial.degree();

  // cout << myPolynomial.coefficient(2);
    return 0;
}
