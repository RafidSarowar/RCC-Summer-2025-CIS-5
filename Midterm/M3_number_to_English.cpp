/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Convert a number to English check amount
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    unsigned short number;
    cout << "Input an integer [1-3000] convert to an English Check value." << endl;
    cin >> number;

    if (number < 1 || number > 3000) {
        cout << "Invalid input." << endl;
        return 1;
    }

    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tens_digit = (number % 100) / 10;
    int ones_digit = number % 10;

    // Thousands
    if (thousands == 1) cout << "One Thousand ";
    else if (thousands == 2) cout << "Two Thousand ";
    else if (thousands == 3) cout << "Three Thousand ";

    // Hundreds
    if (hundreds == 1) cout << "One Hundred ";
    else if (hundreds == 2) cout << "Two Hundred ";
    else if (hundreds == 3) cout << "Three Hundred ";
    else if (hundreds == 4) cout << "Four Hundred ";
    else if (hundreds == 5) cout << "Five Hundred ";
    else if (hundreds == 6) cout << "Six Hundred ";
    else if (hundreds == 7) cout << "Seven Hundred ";
    else if (hundreds == 8) cout << "Eight Hundred ";
    else if (hundreds == 9) cout << "Nine Hundred ";

    // Tens & Ones
    if (tens_digit == 1) {
        if (ones_digit == 0) cout << "Ten ";
        else if (ones_digit == 1) cout << "Eleven ";
        else if (ones_digit == 2) cout << "Twelve ";
        else if (ones_digit == 3) cout << "Thirteen ";
        else if (ones_digit == 4) cout << "Fourteen ";
        else if (ones_digit == 5) cout << "Fifteen ";
        else if (ones_digit == 6) cout << "Sixteen ";
        else if (ones_digit == 7) cout << "Seventeen ";
        else if (ones_digit == 8) cout << "Eighteen ";
        else if (ones_digit == 9) cout << "Nineteen ";
    } else {
        if (tens_digit == 2) cout << "Twenty ";
        else if (tens_digit == 3) cout << "Thirty ";
        else if (tens_digit == 4) cout << "Forty ";
        else if (tens_digit == 5) cout << "Fifty ";
        else if (tens_digit == 6) cout << "Sixty ";
        else if (tens_digit == 7) cout << "Seventy ";
        else if (tens_digit == 8) cout << "Eighty ";
        else if (tens_digit == 9) cout << "Ninety ";

        // Ones only if tens_digit != 1
        if (ones_digit > 0) {
            if (ones_digit == 1) cout << "One ";
            else if (ones_digit == 2) cout << "Two ";
            else if (ones_digit == 3) cout << "Three ";
            else if (ones_digit == 4) cout << "Four ";
            else if (ones_digit == 5) cout << "Five ";
            else if (ones_digit == 6) cout << "Six ";
            else if (ones_digit == 7) cout << "Seven ";
            else if (ones_digit == 8) cout << "Eight ";
            else if (ones_digit == 9) cout << "Nine ";
        }
    }

    // Final Output
    cout << "and no/100's Dollars" << endl;

    return 0;
}