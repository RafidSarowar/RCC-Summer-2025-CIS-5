/* 
 * File:  Savitch_9thEd_Chap2_PracProb_7_Ocean_Levels.cpp
 * Folder: HW Assignment 1
 * Author: Rafid Sarowar
 * Created on 7/7/2025 
 * Purpose: Calculates and display's the ocean level's in 5, 7 and 10 years bassed on the current ocean level.  
 */

#include <iostream>  //Input/Output Library
#include <iomanip>   //Imput/output manipulator

using namespace std;

int main() {
    // Declare and initialize the rate of ocean level rise
    float riseRate = 1.5; // millimeters per year

    // Calculate future ocean levels
    float levelIn5Years = riseRate * 5;
    float levelIn7Years = riseRate * 7;
    float levelIn10Years = riseRate * 10;

    // Display the results
    cout << "Ocean level rise predictions:" << endl;
    cout << "In 5 years:  " << setw(6) <<levelIn5Years << " mm higher" << endl;
    cout << "In 7 years:  " << setw(6) << levelIn7Years << " mm higher" << endl;
    cout << "In 10 years: " << setw(6) << levelIn10Years << " mm higher" << endl;

    return 0;
}