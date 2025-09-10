/*
 * Author: Rafid Sarowar
 * Created on: 23rd July, 2025
 * Purpose: Same as the Collatz Sequence but output the Sequence as well.
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
    int n, ns;

    // Initialize Variables
    cout << "Collatz Conjecture Test" << endl;
    cout << "Input a sequence start" << endl;
    cin >> n;

    // Process/Map inputs to outputs
    ns = collatz(n);

    // Output data
    cout << "Sequence start of " << n << " cycles to 1 in " << ns << " steps";

    // Exit stage right!
    return 0;
}
int collatz(int num)
{
    int count = 1;         // include the starting term
    long long value = num; // use long long for intermediate growth

    // Print the first term
    cout << value;

    // Generate and print subsequent terms
    while (value != 1)
    {
        if (value % 2 == 0)
        {
            value /= 2;
        }
        else
        {
            value = value * 3 + 1;
        }
        cout << ", " << value;
        ++count;
    }

    cout << endl; // end the sequence line
    return count;
}