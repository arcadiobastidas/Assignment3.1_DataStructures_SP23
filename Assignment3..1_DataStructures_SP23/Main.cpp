#include "Term.h"
//#include "Polynomial.h"
#include "ArrayBag.h"
#include <iostream>

#include "Polynomial.h"

using namespace std;


int main()
{
    //option variable
    int option;
    
    //testing Polynomial operation
    Polynomial poly,poly2, poly3, result;

    
    //Testing Term Operation
    Term myTerm (2,5); // 1x^5
    Term myTerm2 (4,5); // 5x^5
    Term myterm3 (4,2); //4x^7
    Term myTerm4 (9, 9); //9x^7
    Term myTerm5 (10, 2); //10x^2

    Term  myTermArray[5] = {myTerm, myTerm2, myterm3, myTerm4, myTerm5}; //creating an array of terms

    for (int i = 0; i < 5; i++)
    {
        poly.addTerm(myTermArray[i]);
        poly2.addTerm(myTermArray[i]);
        poly3.addTerm(myTermArray[i]);
    }
    //testing outputs
   // cout << (myTerm2+=myTerm);// result must be 6x^5 since degree is equal
    //cout << endl;

    do
    {
        cout << "Enter an option for the polynomials: \n";
        cout << "1.Print Polynomials\n"
                "2.Print degree of a polynomial\n"
                "3.Print coefficient with n power\n"
                "4.Change a coefficient\n"
                "5.Add Polynomials\n"
                "6.Exit";
        cout << endl;
        cin >> option;

        switch (option)
        {
        case 1: 
            cout << "Printing Polynomial 1: \n";
            cout << poly << "\n";
            cout << "Printing Polynomial 2: \n";
            cout << poly2 << "\n";
            cout << "Printing Polynomial 3: \n";
            cout << poly2 << "\n";
            break;
        case 2:
            cout << "Printing Degree of Polynomial: ";
            cout << poly.degree();
            cout << endl;
            break;
        case 3:
            cout << "Printing coefficient with a power of 2: ";
            cout << poly.coefficient(2) << endl;
            break;
        case 4:
            cout << "Changing coefficient of the power of 9 to 3";
            poly.changeCoefficient(3,9);
            cout << "\nPrinting Polynomial: \n";
            cout << poly;
            cout << endl;
            break;
        case 5:
                  
            cout << "Adding polynomials....\n";
            result = poly3 + poly3;
            cout << "\nPrinting result...\n";
            cout << result;
            break;
        case 6:
            exit(0);
            break;

            default:
                cout << "Enter a valid option!!";

            
        }
    } while (option<=6);
    

    //adding terms to first Poly Object
   
   
   
    return 0;
}
