/* 
 * File:   Gaddis_9thEd_Chap5_Prob7_PayInPennies.cpp
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program that calculates how much a person would earn over a period of time
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    int days;
    double salary = 0.01, saler = 0.0;

    cin >> days;

    while (days < 1) {
        cin >> days;  // No prompt text
    }

    for (int i = 1; i <= days; ++i) {
        saler += salary;
        salary *= 2;
    }

    cout << "Pay = $" << fixed << setprecision(2) << saler;

    return 0;
}