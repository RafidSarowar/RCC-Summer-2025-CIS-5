/* 
 * File:   Savitch_9Ed_Chap4_Prob2_FuelEff.cpp
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program that will read in the number of liters of gasoline consumed by the user’s car and 
 *            the number of miles traveled by the car and will then output the number of miles per gallon the car delivered.
 *            And takes the same input for another car and compares to give a argument of which car is more efficient. 
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
#include <cmath>                //mathmathitical function library
using namespace std;    

const float convers = 0.264179f;                 // globally defined constant to transfar the gallon to liter

// Function to compute miles per gallon
float computeMPG(float lit, float mile) {                       // this is the function that does the calculation of the mpg
    float gal = lit * convers;
    return mile / gal;
}

int main() {
    float lit, gal, mile, mpg, lit2, mile2, mpg2;
    char repeat;                                                    // this is the input that you take after the lit and mile which is the made off of character like Y and anything else it doesn't run the loop

    do {
        cout << "Car 1" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> lit;

        cout << "Enter number of miles traveled:" << endl;
        cin >> mile;

        mpg = computeMPG(lit, mile);
        cout << "miles per gallon: " << fixed << setprecision(2) << computeMPG(lit, mile) << endl;           // in this line it calls back the function from before and runs the mpg
        cout << endl;

        cout << "Car 2" << endl;                                                     // it's for 2nd car
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> lit2;

        cout << "Enter number of miles traveled:" << endl;
        cin >> mile2;

        mpg2 = computeMPG(lit2, mile2);

        cout << "miles per gallon: " << fixed << setprecision(2) << mpg2 << endl;
        cout << endl;

        if (mpg > mpg2)                                                              // compares the both of them and gives the out put of which one have better mpg
            cout << "Car 1 is more fuel efficient" << endl;
        else
            cout << "Car 2 is more fuel efficient" << endl;

        cout << endl;

        cout << "Again:" << endl;
        cin >> repeat;
        
        if (repeat == 'y' || repeat == 'Y') {                                  // this checks weather if it the input want it tale another go of mpg or not bassed on that it prints another newline
            cout << endl;
        }

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}