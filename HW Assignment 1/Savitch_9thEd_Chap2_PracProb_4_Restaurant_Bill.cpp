/* 
 * File:   Savitch_9thEd_Chap2_PracProb_4_Restaurant_Bill
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: Computes the meal cost, tax amount, tip amount, and the total bill from the meal charge. 
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main(int argc, char** argv) {
    float mealCost, tax, taxcost, tip, total;              // All of the varaibles for the 
    
    cout << "Program to Computes the meal cost, tax amount, tip amount, and the total bill from the meal charge." << endl;

    cout << "Input the meal charge." << endl;

    cin >> mealCost;                                         // takes the cost of the meal

    tax = mealCost*0.0675;                                    // Calculates the Tax, 6.75% tip of the meal cost

    taxcost = mealCost + tax;                                // adds up the tax with the meal coat for calculating the tip of 20%

    tip = taxcost*0.20;                                      // Calculates the tip, which is the 20% of the total cost of meal with the tax

    total = taxcost + tip;                                   // total cost where it sums up the meal cost, tips and tax.

    cout << "Meal Cost = " << fixed << setprecision(2) << setw(8) << mealCost << endl;

    cout << "Tax Amount = " << fixed << setprecision(2) << setw(7) << tax << endl;

    cout << "Tip Amount = " << fixed << setprecision(2) << setw(7) << tip << endl;

    cout << "Total Bill = " << fixed << setprecision(2) << setw(7) << total;

    return 0;
}