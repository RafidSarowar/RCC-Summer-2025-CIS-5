/* 
 * File:   Binary_Search_with_Bubble_Sort.cpp
 * Author: Rafid Sarowar
 * Created on: 30th July, 2025
 * Purpose:  Binary Search with Bubble Sort
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
void fillAry(int [], int);
void prntAry(int [], int, int);
void bublSrt(int [], int);
bool binSrch(int [], int, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    const int SIZE = 100;
    int array[SIZE];
    int indx, val;
    
    // Read input array
    fillAry(array, SIZE);

    // Sort array using Bubble Sort
    bublSrt(array, SIZE);
    
    // Display sorted array
    prntAry(array, SIZE, 10);
    
    // Ask user for value to find
    cout << "Input the value to find in the array" << endl;
    cin >> val;

    // Perform Binary Search
    if (binSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
    else
        cout << val << " was not found in the array" << endl;

    return 0;
}

//Fill Array from Input
void fillAry(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

//Print Array with 'perLine' numbers per row
void prntAry(int a[], int n, int perLine) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if ((i + 1) % perLine == 0) cout <<" " << endl;
        else cout << " ";
    }
    cout << endl;
}

//Bubble Sort
void bublSrt(int a[], int n) {
    bool swap;
    do {
        swap = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

//Binary Search
bool binSrch(int a[], int n, int val, int &indx) {
    int first = 0, last = n - 1;
    while (first <= last) {
        int middle = (first + last) / 2;
        if (a[middle] == val) {
            indx = middle;
            return true;
        } else if (a[middle] > val) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return false;
}