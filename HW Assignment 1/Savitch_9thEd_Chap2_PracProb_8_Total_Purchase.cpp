/* 
 * File:   Savitch_9thEd_Chap2_PracProb_8_Total_Purchase
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: This program calculates the total cost of a sale including a 7% sales tax for five items. It displays the individual item prices, subtotal, sales tax, and final total.
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main(int argc, char** argv) {
    float item1 = 15.95, item2 = 25.95, item3 = 6.95, item4 = 12.95, item5 = 3.95, sum, tax, total;

    sum = item1 + item2 + item3 + item4 + item5;
    tax = sum*0.07;
    total = sum + tax;

    cout << "Price of item 1 = " << setw(4) << "$" << item1 << endl; 
    cout << "Price of item 2 = " << setw(4) << "$" << item2 << endl; 
    cout << "Price of item 3 = " << setw(4) << "$" << item3 << endl; 
    cout << "Price of item 4 = " << setw(4) << "$" << item4 << endl; 
    cout << "Price of item 5 = " << setw(4) << "$" << item5 << endl;
    cout << "Subtotal = " << setw(11) << "$" << fixed << setprecision(2) << sum << endl; 
    cout << "Sales Tax = " << setw(10) << "$" << fixed << setprecision(2) << tax << endl; 
    cout << "Total = " << setw(1) << "$" << fixed << setprecision(2) << total;

    return 0;
}