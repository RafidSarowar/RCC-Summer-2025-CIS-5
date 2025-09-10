/*
 * File:   Linear_Search.cpp
 * Author: Rafid Sarowar
 * Created on: July 30, 2025
 * Purpose:  Find a value in an array
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
void inputArray(int[], int);
void printArray(int[], int, int);
bool linearSearch(int[], int, int, int&);

// Execution Begins Here!
int main() {
    const int SIZE = 100;
    int array[SIZE];
    int value, indx;

    // Initialize or input i.e. set variable values
    inputArray(array, SIZE);

    // Value to search for
    value = 50;

    // Display the array
    printArray(array, SIZE, 10);

    // Perform linear search
    if (linearSearch(array, SIZE, value, indx)) {
        cout << value << " was found at indx = " << indx << endl;
    } else {
        cout << value << " was not found." << endl;
    }

    return 0;
}

// Input the array
void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Print the array
void printArray(int arr[], int size, int perLine) {
    for (int i = 0; i < size; i++) {
        if ((i + 1) % perLine == 0);
    }
}

// Linear search implementation
bool linearSearch(int arr[], int size, int val, int &indx) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            indx = i;
            return true;
        }
    }
    return false;
}
