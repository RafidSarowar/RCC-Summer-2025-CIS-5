/* 
 * File:   M4_charges.cpp
 * Author: Rafid Sarwoar
 * Created on july 18th, 2025
 * Purpose: ISP charges
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()
using namespace std;

int main(int argc, char** argv) {
    // Declare all Variables
    char package;
    unsigned short hours;
    float chargeA = 0, chargeB = 0, chargeC = 36.99, currentCharge = 0;
    float cheapestCharge;
    char cheapestPackage;
    float savings;

    // Input Prompt
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package >> hours;

    // Convert to uppercase if lowercase
    package = toupper(package);

    // Calculate charge for Package A
    if (hours <= 10)
        chargeA = 16.99;
    else if (hours <= 20)
        chargeA = 16.99 + (hours - 10) * 0.95;
    else
        chargeA = 16.99 + 10 * 0.95 + (hours - 20) * 0.85;

    // Calculate charge for Package B
    if (hours <= 20)
        chargeB = 26.99;
    else if (hours <= 30)
        chargeB = 26.99 + (hours - 20) * 0.74;
    else
        chargeB = 26.99 + 10 * 0.74 + (hours - 30) * 0.64;

    // Package C has fixed cost
    chargeC = 36.99;

    // Determine current charge based on selected package
    switch (package) {
        case 'A':
            currentCharge = chargeA;
            break;
        case 'B':
            currentCharge = chargeB;
            break;
        case 'C':
            currentCharge = chargeC;
            break;
        default:
            cout << "Invalid package input!" << endl;
            return 1;
    }

    // Determine the cheapest package
    cheapestCharge = chargeA;
    cheapestPackage = 'A';

    if (chargeB < cheapestCharge) {
        cheapestCharge = chargeB;
        cheapestPackage = 'B';
    }

    if (chargeC < cheapestCharge) {
        cheapestCharge = chargeC;
        cheapestPackage = 'C';
    }

    // Calculate savings
    savings = currentCharge - cheapestCharge;
    if (savings < 0) savings = 0;

    // Output the result
    cout << fixed << setprecision(2);
    cout << "$" << currentCharge << " " << cheapestPackage << " $" << savings << endl;

    return 0;
}