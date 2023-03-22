#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    //Testing Term Operation
    Term myTerm(2,5); // 1x^5
    Term myTerm2(3,5); // 5x^5
    cout << (myTerm2+=myTerm);// result must be 6x^5 since degree is equal
    cout << endl;

    
    //testing Polynomial operation
    Term  myTermArray[2] = {myTerm, myTerm2}; //creating an array of terms
    Polynomial poly1;
    Polynomial poly2;
    
    poly1.addTerm(myTerm);
    poly1.addTerm(myTerm2);

    cout << poly1;

    return 0;
}
