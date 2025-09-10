/*
 * Author: Rafid Sarowar
 * Created on: July 24th, 2025
 * Purpose:  Create a function that inputs 3 integers and returns both the min and maximua.
 *           Use the prototype function supplied.
 *           Like the other problems complete the function and use in the solution.
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants - Math/Physics Constants, Conversions,
//                    2-D Array Dimensions

// Function Prototypes
void minmax(int a, int b, int c, int &minimum, int &maximum); // Function to find the min and max, dunction protype

// Execution Begins Here
int main(int argc, char **argv)
{
    int num1, num2, num3; // Declare Variables
    int minVal, maxVal;

    cout << "Input 3 numbers" << endl; // input prompt]
    cin >> num1 >> num2 >> num3;

    minmax(num1, num2, num3, minVal, maxVal); // function unction call

    cout << "Min = " << minVal << endl;
    cout << "Max = " << maxVal;

    return 0;
}
void minmax(int a, int b, int c, int &minimum, int &maximum)
{
    // Start by assuming a is both smallest and largest
    minimum = maximum = a;

    // Compare b
    if (b < minimum)
        minimum = b;
    if (b > maximum)
        maximum = b;

    // Compare c
    if (c < minimum)
        minimum = c;
    if (c > maximum)
        maximum = c;
}