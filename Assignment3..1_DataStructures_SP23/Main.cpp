#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    //Testing Term Operation
    Term myTerm (2,5); // 1x^5
    Term  myTerm2 (4,5); // 5x^5
    Term myterm3  (4,7); //4x^7
    //cout << (myTerm2+=myTerm);// result must be 6x^5 since degree is equal
    cout << endl;

    
    //testing Polynomial operation
     Term  myTermArray[2] = {myTerm, myTerm2}; //creating an array of terms
     Polynomial poly1;
     Polynomial poly2;
     Polynomial poly3;
    
     poly3.addTerm(myTerm);
     poly3.addTerm(myTerm2);
    poly3.addTerm(myterm3);

    //cout << poly1 + poly3;

    cout << poly3;

    return 0;
}
