/* 
 * File:   Savitch_9Ed_Chap4_Prob5_EstCost.cpp
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

float inflation(float cur, float prev) {
    return ((cur - prev) / prev) * 100;
}

int main(int argc, char** argv) {
    float inf1, inf2, cur1, cur2, prev1, prev2, yr1, yr2;
    char repreat;

    do {
        cout << "Enter current price:" << endl;
        cin >> cur1;
        cout << "Enter year-ago price:" << endl;
        cin >> prev1;
        inf1 = inflation(cur1, prev1);
        cout << "Inflation rate: " << fixed << setprecision(2) << inf1 << "%" << endl;
        cout << endl;

        yr1 = cur1 + (cur1 * (inf1/100));
        cout << "Price in one year: $" << fixed << setprecision(2) << yr1 << endl;              // yr1 price
        yr2 = yr1 + (yr1 * (inf1 / 100));
        cout << "Price in two year: $" << fixed << setprecision(2) << yr2 << endl;              // yr2 price
        cout << endl;

        cout << "Again:" << endl;

        cin >> repreat;

        if (repreat == 'Y' || repreat == 'y')
        cout << endl;

    } while (repreat == 'Y' || repreat == 'y');

    return 0;
}