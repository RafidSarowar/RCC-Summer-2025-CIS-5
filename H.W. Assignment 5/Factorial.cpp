/*
 * Author: Rafid Sarowar
 * Created on: 23rd July, 2025
 * Purpose:  Calculate the factorial using a function.
 */

// System Libraries
#include <iostream>
#include <cmath>

using namespace std;

// User Libraries

// Global Constants - Math/Physics Constants, Conversions,
//                    2-D Array Dimensions

// Function Prototypes
int fctrl(int); // Function to write for this problem

// Execution Begins Here
int main(int argc, char **argv)
{
    int inp;

    cout << "This program calculates the factorial using a function prototype found in the template for this problem." << endl;
    cout << "Input the number for the function." << endl;

    cin >> inp;

    cout << inp << "! = " << fctrl(inp); // function call

    return 0;
}

int fctrl(int F)
{ // Function to write for this problem
    int factorial = 1;
    for (int i = 2; i <= F; ++i)
    {
        factorial *= i;
    }
    return factorial;
}