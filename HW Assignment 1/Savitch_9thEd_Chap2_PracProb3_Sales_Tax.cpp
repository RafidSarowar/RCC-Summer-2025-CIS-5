/* 
 * File:   Savitch_9thEd_Chap2_PracProb3_Sales_Tax
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: Computes the sales tax from the 4 percent state tax and 2 percent county tax. 
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main(int argc, char** argv) {
    float PurCost, StateTax, CountyTax, TotalTax;

    cout << "Program to compute the state, couty and total sales tax purchase." << endl;         // Input Command
    cout << "Input the purchase cost." << endl;

    cin >> PurCost;

    StateTax = PurCost*0.04;                                     // 4 % state tax

    CountyTax = PurCost*0.02;                                    // 2 % county tax

    TotalTax = StateTax + CountyTax;                             // Total tax which is sum of State Tax and County Tax or 6$% tax. 

    cout << "State Tax = " << fixed << setprecision(2) << setw(6) << StateTax << endl;

    cout << "County Tax = " << fixed << setprecision(2) << setw(5) << CountyTax << endl;

    cout << "Total Tax = " << fixed << setprecision(2) << setw(6) << TotalTax << endl;

    return 0;
}