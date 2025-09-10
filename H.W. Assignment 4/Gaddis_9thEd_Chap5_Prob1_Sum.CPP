/* 
 * File:   Gaddis_9thEd_Chap5_Prob1_Sum.CPP
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A  program that asks the user for a positive integer value. The program should
 *            use a loop to get the sum of all the integers from 1 up to the number entered.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) { 
    int i=1, out=0, inp=0;

    cin >> inp;

    while (i <= inp) {                             // the loop where it keeps going untill it reaches the limil theat given by the inpiut of the user
        out = out + i ;                         // it keeps on adding
        ++i;                                       // this is the incrising iteration
    }
    cout << "Sum = " <<  out;

    return 0;
}