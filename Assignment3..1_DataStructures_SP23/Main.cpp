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
    Term myTerm2 (4,4); // 5x^5
    Term myterm3 (4,7); //4x^7
    Term myTerm4 (9, 9); //9x^7
    Term myTerm5 (10, 2); //10x^2
    
    //cout << (myTerm2+=myTerm);// result must be 6x^5 since degree is equal
    cout << endl;

    
    //testing Polynomial operation
     Term  myTermArray[5] = {myTerm, myTerm2, myterm3, myTerm4, myTerm5}; //creating an array of terms
     Polynomial poly;

    for (int i = 0; i < 5; i++)
    {
        poly.addTerm(myTermArray[i]);
    }

    cout << poly;

    return 0;
}
