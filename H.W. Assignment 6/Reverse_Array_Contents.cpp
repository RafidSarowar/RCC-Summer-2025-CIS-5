/* 
 * File:   Reverse_Array_Contents.cpp
 * Author: Rafid Sarowar
 * Created: July 30, 2025
 * Purpose:  Reverse the Array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Display the outputs
    //print(test,SIZE,10);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}
// Read exactly n integers from stdin into a[]
void init(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// Print a[] with perLine values per row, each followed by '·'
void print(int a[], int n, int perLine) {
    for (int i = 0; i < n; i++) {
        cout << setw(2) << a[i];        // two-wide field
        if ((i + 1) % perLine == 0)
            cout << " \n";
        else
            cout << ' ';               // simple space separator
    }
    // ensure newline at end if n%perLine != 0
    if (n % perLine) cout << '\n';
}

// Reverse a[] in place
void revrse(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}
