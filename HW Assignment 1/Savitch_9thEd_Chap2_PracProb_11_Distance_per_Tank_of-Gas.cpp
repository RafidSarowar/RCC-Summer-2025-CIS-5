/*
 * File:  Savitch_9thEd_Chap2_PracProb_11_Distance_per_Tank_of-Gas 
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025
 * Purpose: This program determine the MPG. 
 */

#include <iostream>   // Input/Output Library
#include <iomanip>    // Input/Output Manipulators
using namespace std;

int main(int argc, char** argv) {
    float gallon = 20, town = 23.5, highway = 28.9;

    cout << "Highway millage = " << gallon*highway << endl;
    cout << "Town millage    = " << gallon*town;

    return 0;
}