/*
 * File:   F1.cpp
 * Author: Rafid Sarowar
 * Created: 31st July, 2025
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

// System Libraries Here
#include <iostream> //cin,cout,endl
#include <cstring>  //strlen()
using namespace std;
// User Libraries Here

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here
bool inRange(const char[], unsigned short &); // Output true,unsigned or false
bool reverse(unsigned short, signed short &); // Output true,short or false
short subtrct(signed short, int);

// Program Execution Begins Here
int main(int argc, char **argv)
{
    // Declare all Variables Here
    const int SIZE = 80;    // More than enough
    char digits[SIZE];      // Character digits or not
    unsigned short unShort; // Unsigned short
    short snShort;          // Signed short

    // Input or initialize values Here
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> digits;

    // Test if it is in the Range of an unsigned short
    if (!inRange(digits, unShort))
    {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    // Reverse and see if it falls in the range of an signed short
    if (!reverse(unShort, snShort))
    {
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    // Now subtract if the result is not negative else don't subtract
    snShort = subtrct(snShort, 999);

    // Output the result
    cout << snShort << endl;

    // Exit
    return 0;
}
// Checks if the input string is a valid non-negative integer within the range of unsigned short.
// If so, converts the string to an unsigned short and assigns it via reference.
// Returns true if valid, false otherwise.
bool inRange(const char digits[], unsigned short &unShort)
{
    int len = strlen(digits);
    if (len == 0)
        return false;             // No input at allt
    for (int i = 0; i < len; i++) // Make sure every character is a numeric digi
    {
        if (digits[i] < '0' || digits[i] > '9')
            return false; // Found a non-digit character
    }
    unsigned int val = 0; // Convert the valid digit string to an integer (still check if it's in range)
    for (int i = 0; i < len; i++)
    {
        val = val * 10 + (digits[i] - '0');
        if (val > 65535)
            return false; // Too big for unsigned short
    }

    unShort = static_cast<unsigned short>(val); // Store valid result
    return true;
}
// Takes an unsigned short value, reverses its digits (padding to 5 digits), and checks if
// the result can fit in a signed short. If so, stores the result by reference and returns true.
bool reverse(unsigned short unShort, signed short &snShort)
{
    char temp[6];
    sprintf(temp, "%05u", unShort);
    char rev[6]; // Reverse the digits of the padded string
    for (int i = 0; i < 5; ++i)
    {
        rev[i] = temp[4 - i];
    }
    rev[5] = '\0';                                   // Null-terminate the string
    int reversedVal = atoi(rev);                     // Convert the reversed string to an integer value
    if (reversedVal > 32767 || reversedVal < -32768) // Make sure the reversed value fits inside a signed short data type
        return false;

    snShort = static_cast<short>(reversedVal);
    return true;
}
// Subtracts 999 from the given value, but only if the result is not negative.
// If the subtraction would make it negative, just return the original value.
short subtrct(signed short snShort, int subtract = 999)
{
    if (snShort - subtract >= 0)
        return snShort - subtract; // OK to subtract
    return snShort;                // Don't subtract if result would be negative
}