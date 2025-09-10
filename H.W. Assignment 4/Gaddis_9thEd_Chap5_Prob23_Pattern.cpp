/* 
 * File:   Gaddis_9thEd_Chap5_Prob22_Rectangle.CPP
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program that asks the user for a positive integer no greater than 15. The program 
 *            should then display a rectangle on the screen using the character ‘X’.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    int num;

    cin >> num;  // Get size of the square

    // Validate input
    for (int i = 1; i <= num; ++i) {        // outer loop and increses in the one row at for the input
        for (int j = 1; j <= i; ++j) {      // the inner loop of the symbols incrising by one as it is as much as the row number
            cout << "+";
        } 
    cout << endl;
    }

    for (int i = num; i >= 1; --i) {         // Outer loop: start from num down to 1
        for (int j = 1; j <= i; ++j) {       // Inner loop: prints i symbols
            cout << "+";
        }          // Avoid extra newline at the end if desired
        

    if (i != 1) cout << endl;
    }
    return 0;
}