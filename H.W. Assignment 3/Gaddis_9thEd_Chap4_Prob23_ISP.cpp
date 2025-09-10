/* 
 * File:   Gaddis_9thEd_Chap4_Prob23_ISP.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:   A program that calculates a customer’s monthly bill. It should ask which package
 *            the customer has purchased and how many hours were used. It should then display
 *            the total amount due.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {                        // all of the variables with string type because we are takeing characters. 
    float cost, hr;
    char package;

    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;

    cin >> package >> hr;

    switch (package)
    {
        case 'A': 
        if (hr <= 10){
            cost = 9.95;
        } else {
            cost = 9.95 + (2.00*(hr-10));
        }
        cout << "Bill = $" << fixed << setprecision(2) << setw(6) << cost;
        break;

        case 'B': 
        if (hr <= 20){
            cost = 14.95;
        } else {
            cost = 14.95 + (1.00*(hr-20));
        }
        cout << "Bill = $" << fixed << setprecision(2) << setw(6) << cost;
        break;

        case 'C': cout << "Bill = $" << fixed << setprecision(2) << setw(6) << 19.95;
        break;

        default: cout << "You did not enter A, B, or C";

    }
    return 0;
}