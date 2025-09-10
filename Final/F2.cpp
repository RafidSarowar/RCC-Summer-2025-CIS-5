/* 
 * File:   F2.cpp
 * Author: Rafid Sarowar
 * Created on: 31st July, 2025
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
int read(char arr[]) {                                                // Reads a string of characters into arr[] and returns its actual length
    cin >> arr;                                                       // Reads input as a C-string (no whitespace)
    return strlen(arr);                                               // Returns the number of characters read
}
void sort(char arr[], int n) {                                        // Sorts the first n elements of arr[] in ascending order
    for(int i = 0; i < n - 1; ++i) {                                  // Simple selection sort
        int minIdx = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        if(minIdx != i) {                                              // Swap if a smaller value is found
            char temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
void print(const char arr[], int n) {                                  // Prints the first n characters of arr[] on a single line, no spaces
    for(int i = 0; i < n; ++i)
        cout << arr[i];
    cout << endl;
}