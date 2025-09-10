/*
 * File:   Savitch_9thEd_Chap2_PracProb_9_Cyborg_Data_Type_Sizes
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025
 * Purpose: This program determines the number of bytes used by the char, int, float, and double data types.
 */

#include <iostream>   // Input/Output Library
#include <iomanip>    // Input/Output Manipulators
using namespace std;

int main(int argc, char** argv) {
    // Print a header
    cout << left << setw(15) << "Data Type" << setw(10) << "Size (bytes)" << endl;
    cout << "-----------------------------" << endl;

    // Display sizes using setw for formatting
    cout << left << setw(15) << "char"   << setw(10) << sizeof(char)   << endl;
    cout << left << setw(15) << "int"    << setw(10) << sizeof(int)    << endl;
    cout << left << setw(15) << "float"  << setw(10) << sizeof(float)  << endl;
    cout << left << setw(15) << "double" << setw(10) << sizeof(double) << endl;

    return 0;
}