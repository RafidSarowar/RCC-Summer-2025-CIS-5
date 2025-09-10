/* 
 * File:   Savitch_9Ed_Chap4_Prob9_2or3Max.cpp
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program to gauge the rate of inflation for the past year.
 *            And gives the price which is going to be there for the item next two years. 
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
#include <cmath>                //mathmathitical function library
using namespace std;    


int main(int argc, char** argv) {
    float num1, num2, num3;

    cout << "Enter first number:" << endl;
    cin >> num1;
    cout << endl;

    cout << "Enter Second number:" << endl;
    cin >> num2;
    cout << endl;

    cout << "Enter third number:" << endl;
    cin >> num3;
    cout << endl;

    cout << "Largest number from two parameter function:" << endl;                  // compare of 1st two perameter
    if (num1 > num2) {
        cout << num1 << endl;
    } else {
        cout << num2 << endl;
    }
    cout << endl;

    cout << "Largest number from three parameter function:" << endl;                  // compare of all three poarameter
    if (num1 > num2 && num1 > num3) {
        cout << num1 << endl;
    } else if (num2 > num1 && num2 > num3) { 
        cout << num2 << endl;
    } else {
        cout << num3 << endl;
    }

    return 0;
}