/* 
 * File:   F4.cpp
 * Author: Rafid Sarowar
 * Created on 31st July, 2025
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}
void read(int arr[], int n) {                                            // Reads 'n' integers into arr[] from user input and prints as specified
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
}
int stat(const int arr[], int n, int &max, int &min) {                   // Calculates sum, finds max and min values in arr[] of length n
    if (n <= 0) return 0;                                                // Safety check
    int sum = arr[0];
    max = arr[0];
    min = arr[0];

    for (int i = 1; i < n; ++i) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    return sum;                                                          // Returns the sum, and assigns max and min by reference
}
void print(const int arr[], int n, int sum, int max, int min) {          // Print min, max, and sum in the required format (with two spaces before '=')
    cout << "Min  = " << min << endl;
    cout << "Max  = " << max << endl;
    cout << "Sum  = " << sum << endl;
}