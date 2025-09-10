/*
 * File:   Standard_Deviation.cpp
 * Author: Rafid Sarowar
 * Created on: July 30, 2025
 * Purpose: Calculate the Standard Deviation
 */

// System Libraries
#include <iostream> //Input/Output Library
#include <cstdlib>  //Srand
#include <ctime>    //Time to set random number seed
#include <cmath>    //Math Library
#include <iomanip>  //Format Library
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float MAXRAND = pow(2, 31) - 1;

// Function Prototypes
void init(float[], int);       // Initialize the array
void print(float[], int, int); // Print the array
float avgX(float[], int);      // Calculate the Average
float stdX(float[], int);      // Calculate the standard deviation

// Execution Begins Here!
int main()
{
    // Declare Variables
    const int SIZE = 20;
    float test[SIZE];

    // Initialize array with user input
    init(test, SIZE);

    // Display the outputs
    print(test, SIZE, 5);
    cout << fixed << setprecision(7);
    cout << "The average            = " << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;

    return 0;
}

// Initialize array
void init(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

// Print array
void print(float arr[], int size, int perLine)
{
    for (int i = 0; i < size; i++)
    {
        //   cout << setw(12) << arr[i];
        if ((i + 1) % perLine == 0)
            ;
    }
}

// Calculate average
float avgX(float arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

// Calculate standard deviation
float stdX(float arr[], int size)
{
    float mean = avgX(arr, size);
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / (size - 1));
}