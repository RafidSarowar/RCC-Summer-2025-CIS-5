/* 
 * File:   Gaddis_9thEd_Chap5_Prob7_PayInPennies.cpp
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program that calculates the minimum and maximum
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    int num, maxNum, minNum;
    bool first = true;

    while (cin >> num && num != -99) {
        if (first) {
            maxNum = minNum = num;
            first = false;
        } else {
            maxNum = max(maxNum, num);  // Using std::max
            minNum = min(minNum, num);  // Using std::min
        }
    }

    cout << "Smallest number in the series is " << fixed << setprecision(2) << minNum << endl;
    cout << "Largest  number in the series is " << fixed << setprecision(2) << maxNum;

    return 0;
}