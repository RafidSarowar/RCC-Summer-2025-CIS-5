/*
 * Author: Rafid Sarowar
 * Created on: 23rd July, 2025
 * Purpose: Determine if the input integer is prime or not.
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Constants - Math/Physics Constants, Conversions,
//                    2-D Array Dimensions

// Function Prototypes
bool isPrime(int); // Determine if the input number is prime.

// Execution Begins Here
int main(int argc, char **argv)
{
    int inp;
    bool prime; // true value of the bool

    cout << "Input a number to test if Prime." << endl;
    cin >> inp;

    prime = isPrime(inp); // functuion calls process and map's inputs and outputs

    if (prime)
    {
        cout << inp << " is prime.";
    }
    else
    {
        cout << inp << " is not prime.";
    }

    return 0;
}
bool isPrime(int Pr)
{
    if (Pr <= 1)
    {
        return false; // 0 and 1 is not prime
    }
    for (int i = 2; i * i <= Pr; ++i)
    {
        if (Pr % i == 0)
        {
            return false; // false if there's a divisor
        }
    }
    return true; // no devisor found so it's a prime number
}