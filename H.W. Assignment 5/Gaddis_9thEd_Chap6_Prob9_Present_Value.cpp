// Author: Rafid Sarowar
// Created on: July 30, 2025
// Purpose: Calculate the present value needed today to reach a desired future value
//          after a given number of years at a specified annual interest rate.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float psntVal(float futureValue, float interestRate, int years) {
    float r = interestRate / 100.0f;            // convert percent to fraction
    return futureValue / pow(1.0f + r, years);
}

int main() {
    float futureValue, interestRate;
    int years;

    cout << "This is a Present Value Computation\n";
    cout << "Input the Future Value in Dollars\n";
    cin  >> futureValue;

    cout << "Input the Number of Years\n";
    cin  >> years;

    cout << "Input the Interest Rate %/yr\n";
    cin  >> interestRate;

    float presentValue = psntVal(futureValue, interestRate, years);

    cout << fixed << setprecision(2);
    cout << "The Present Value = $" << presentValue;

    return 0;
}