/*
 * Author: Rafid Sarowar
 * Created on: 23rd july, 2025
 * Purpose:  Count from the start of the sequence to the end and output its length.
 *           When even divide by 2, when odd multiply by 3 and add 1;
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants - Math/Physics Constants, Conversions,
//                    2-D Array Dimensions

// Function Prototypes
int collatz(int); // 3n+1 sequence

// Execution Begins Here
int main(int argc, char **argv)
{
    // Declare Variables
    int n;

    // Initialize Variables
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin >> n;

    // Process/Map inputs to outputs
    cout << "Sequence start of " << n << " cycles to 1 in " << collatz(n) << " steps";

    // Output data

    // Exit stage right!
    return 0;
}
int collatz(int num) 
{
    int length = 1;        // count the starting term
    long long value = num; // use a larger type in case it grows

    while (value != 1) {
        if (value % 2 == 0) {
            value /= 2;
        } else {
            value = value * 3 + 1;
        }
        ++length;
    }
    return length;
}