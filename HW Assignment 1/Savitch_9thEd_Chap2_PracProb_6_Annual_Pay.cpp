/* 
 * File:   Savitch_9thEd_Chap2_PracProb_6_Annual_Pay
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: Calculate the employee’s total annual pay by multiplying the employee’s pay amount with the annual pay periods. 
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main() {
    // Declare and initialize variables
    float payAmount = 2200.0;     // Pay per period
    int payPeriods = 26;          // Number of pay periods per year
    float annualPay;              // Total annual pay

    // Calculate annual pay
    annualPay = payAmount * payPeriods;

    // Display the result
    cout << "The total annual pay is: $" << annualPay << endl;

    return 0;
}