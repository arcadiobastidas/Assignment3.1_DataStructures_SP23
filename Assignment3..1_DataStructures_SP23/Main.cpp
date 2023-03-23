#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    //testing Polynomial operation
    Polynomial poly;

    
    //Testing Term Operation
    Term myTerm (2,5); // 1x^5
    Term myTerm2 (4,4); // 5x^5
    Term myterm3 (4,2); //4x^7
    Term myTerm4 (9, 9); //9x^7
    Term myTerm5 (10, 2); //10x^2

    Term  myTermArray[5] = {myTerm, myTerm2, myterm3, myTerm4, myTerm5}; //creating an array of terms

    //testing outputs
    cout << (myTerm2+=myTerm);// result must be 6x^5 since degree is equal
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        poly.addTerm(myTermArray[i]);
    }

    cout << poly.degree();

    cout << endl;


    poly.changeCoefficient(9,9);

    cout << poly;

    cout << endl;

    Term terminus(4,2);
    Term Termiiii(9,2);
    Polynomial other;
    Polynomial other2;

    other.addTerm(terminus);
    other2.addTerm(Termiiii);

    cout << other + other2;



    
    return 0;
}
