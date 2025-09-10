/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Infinite Series
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float x,fx,term;
    int nterms;
    
    //Input or initialize values Here
    cout<<"Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+......."<<endl;
    cout<<"Input x and the number of terms, output f(x)"<<endl;
    cin>>x>>nterms;
    
    //Calculate Sequence sum here

    for (int i = 0; i < nterms; i++) {
        int power = 2 * i + 1;  // 1, 3, 5, 7, ...
        float numerator = 1.0;
        float denominator = 1.0;

        // Calculate x^power
        for (int j = 0; j < power; j++) {
            numerator *= x;
        }

        // Calculate power!
        for (int j = 1; j <= power; j++) {
            denominator *= j;
        }

        term = numerator / denominator;

        // Alternating sign: add if even term, subtract if odd term
        if (i % 2 == 0)
            fx += term;
        else
            fx -= term;
    }

    //Output the result here
    cout << fixed << setprecision(6) << fx << endl;

    //Exit
    return 0;
}