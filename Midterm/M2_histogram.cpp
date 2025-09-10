/* 
 * File:   M1_histogram.cpp
 * Author: Rafid Sarowar
 * Created: 18th july 2025 
 * Purpose:  Histogram
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char ch1, ch2, ch3, ch4;                              // four variables from the input

    
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl;
    cout<<"Input 4 digits as characters."<<endl;
    cin >> ch1 >> ch2 >> ch3 >> ch4;

    //Histogram Output
    char input[4] = {ch1, ch2, ch3, ch4};                      // making a array that holds of the inputs
    
    for (int i = 3; i >= 0; --i) {                             // Print in reverse order
        cout << input[i] << " ";                               // outputting by excessing the char from the arrey
        if (input[i] >= '0' && input[i] <= '9') {
            int num = input[i] - '0';
            for (int j = 0; j < num; ++j) {
                cout << "*";
            }
        } else {
            cout << "?";
        }
        cout << endl;
    }
    
    //Exit
    return 0;
}