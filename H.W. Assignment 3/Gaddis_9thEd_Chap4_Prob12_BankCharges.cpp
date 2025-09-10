/* 
 * File:   Gaddis_9thEd_Chap4_Prob12_BankCharges.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:  A program that asks for the beginning balance and the number of checks written.
 *           Compute and display the bank’s service fees for the month.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    float balance, check, monthly = 10.00, low = 15.00;                          // all of the variables with string type because we are takeing characters. 

    cout << "Monthly Bank Fees" << endl;                  // input instruction
    cout << "Input Current Bank Balance and Number of Checks" << endl;

    cin >> balance >> check;

    cout << "Balance     $" << fixed << setprecision(2) << setw(9) << balance << endl;

    if (check < 20) {
        check = check * 0.10;
    } else if (check < 40) {
        check = check * 0.08;
    } else if (check < 60) {
        check = check * 0.06;
    } else {
        check = check * 0.04;
    }

    balance -= check;
    cout << "Check Fee   $" << fixed << setprecision(2) << setw(9) << check << endl;

    balance -= monthly;
    cout << "Monthly Fee $" << fixed << setprecision(2) << setw(9) << monthly << endl;


    if (balance + check + monthly <= 400 ){
        balance-=low;
        cout << "Low Balance $" << fixed << setprecision(2) << setw(9) << low << endl;
    }

    cout << "New Balance $" << fixed << setprecision(2) << setw(9) << balance;

    return 0;
}