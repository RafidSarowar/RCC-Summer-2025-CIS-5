/*
 * File:   Binary_Search_and_Selection_Sort.cpp
 * Author: Rafid Sarowar
 * Created on:  july 30th, 2025
 * Purpose:  Binary Search and Selection Sort
 */

// System Libraries
#include <iostream> //Input/Output Library
#include <cstdlib>  //Random Functions
#include <ctime>    //Time Library
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

// Function Prototypes
#include <iostream> //Input/Output Library
#include <cstdlib>  //Random Functions
#include <ctime>    //Time Library
using namespace std;

// Function Prototypes
void readAry(int[], int);
void prntAry(int[], int, int);
void selSrt(int[], int);
bool binSrch(int[], int, int, int &);

// Execution Begins Here
int main(int argc, char **argv)
{
    const int SIZE = 100;
    int array[SIZE], indx, val;

    // Read 100 integers
    readAry(array, SIZE);

    // Sort the array
    selSrt(array, SIZE);

    // Display sorted array
    prntAry(array, SIZE, 10);

    // Input value to search
    cout << "Input the value to find in the array" << endl;
    cin >> val;

    // Binary search
    if (binSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
    else
        cout << val << " was not found in the array" << endl;

    return 0;
}

// Reads 'n' integers from input
void readAry(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// Prints array, 'perLine' numbers per line
void prntAry(int arr[], int n, int perLine)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % perLine == 0)
            cout << endl;
    }
    cout << endl;
}

// Selection sort
void selSrt(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Binary search
bool binSrch(int arr[], int n, int val, int &indx)
{
    int first = 0, last = n - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == val)
        {
            indx = mid;
            return true;
        }
        else if (arr[mid] > val)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return false;
}
