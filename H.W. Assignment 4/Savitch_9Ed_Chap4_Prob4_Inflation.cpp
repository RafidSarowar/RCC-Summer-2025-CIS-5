/* 
 * File:   Savitch_9Ed_Chap4_Prob4_Inflation.cpp
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program to gauge the rate of inflation for the past year.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
#include <cmath>                //mathmathitical function library
using namespace std;    

float inflation(float cur, float prev) {
    return ((cur - prev) / prev) * 100;
}

int main(int argc, char** argv) {
    float inf1, inf2, cur1, cur2, prev1, prev2;
    char repreat;

    do {
        cout << "Enter current price:" << endl;
        cin >> cur1;
        cout << "Enter year-ago price:" << endl;
        cin >> prev1;
        inf1 = inflation(cur1, prev1);
        cout << "Inflation rate: " << fixed << setprecision(2) << inf1 << "%" << endl;
        cout << endl;

        cout << "Again:" << endl;

        cin >> repreat;

        if (repreat == 'Y' || repreat == 'y')
        cout << endl;

    } while (repreat == 'Y' || repreat == 'y');

    return 0;
}