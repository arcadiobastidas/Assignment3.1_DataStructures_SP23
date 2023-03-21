#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    Term myTerm(1,5);

    //Term myTerm2(-2,5);

   // cout << myTerm << myTerm2;

   
    Polynomial poly;

    poly.addTerm(myTerm);

    cout << poly.degree();

  cout<< poly.coefficient(5);
    return 0;
}
