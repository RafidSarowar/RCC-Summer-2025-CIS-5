/* 
 * File:   Gaddis_9thEd_Chap4_Prob8_SortNames.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:  A program that asks the user to enter three names, and then displays the names sorted in alphabetical order. Assume that none of the names are the same.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    string nam1, nam2, nam3;                          // all of the variables with string type because we are takeing characters. 

    cout << "Sorting Names" << endl;                  // input instruction
    cout << "Input 3 names" << endl;

    cin >> nam1 >> nam2 >> nam3;
    
    if (nam1 < nam2 && nam1 < nam3) {
        cout << nam1 << endl;
        if (nam2 < nam3) {
            cout << nam2 << endl;
            cout << nam3;
        } else {
            cout << nam2 << endl;
            cout << nam3;
        }

    } else if (nam2 < nam1 && nam2 < nam3) {
        if (nam1 < nam3) {
            cout << nam1 << endl;
            cout << nam3;
        } else {
            cout << nam3 << endl;
            cout << nam1;
        }

    } else {
        cout << nam3 << endl;
        if (nam1 < nam2) {
            cout << nam1 << endl;
            cout << nam2;
        } else {
            cout << nam2 << endl;
            cout << nam1;
        }
    }

    return 0;
}