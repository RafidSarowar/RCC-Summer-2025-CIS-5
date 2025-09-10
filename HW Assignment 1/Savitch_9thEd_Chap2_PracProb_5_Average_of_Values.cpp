/* 
 * File:   Savitch_9thEd_Chap2_PracProb_5_Average_of_Values
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: Computes the meal cost, tax amount, tip amount, and the total bill from the meal charge. 
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main(int argc, char** argv) {
    double val1, val2, val3, val4, val5, sum, avg;                             // took the variables in double type, b/c the book instructed so.
    
    cout << "Program Computes the average of 5 values" << endl;                // telling the purpose of the program

    cout << "Input five values one by one." << endl;                           // the input instruction 

    cin >> val1 >> val2 >> val3 >> val4 >> val5;                                   
    
    sum = val1 + val2 + val3 + val4 + val5;                                    // sum of all of the five values.

    avg = sum/5;

    cout << "The Average of the five values is = " << fixed << setprecision(2) << avg;

    return 0;
}