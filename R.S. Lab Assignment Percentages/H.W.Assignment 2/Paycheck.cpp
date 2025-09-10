#include <iostream>         // standard input and output library

#include <iomanip>          // input and output manupulator library

#include <cmath>            // Math trig Library

using namespace std;        // standard Name-space where library is compiled, basically user library  

int main(int argc, char** argv) {
    float payrate,                     // $ per hr
          numHr,                       // num of hr
          dblTime,                     // When double time occures after 40 hr mark 
          paychk;                      // Basically the amount of money that you are going to get paid
    
    dblTime = 40;                       // after the 40 hr mark double time kicks in

    cout << "This program calculates the gross paycheck." << endl;                    //input comands
    cout << "Input the pay rate in $'s/hr and the number of hours." << endl;

    cin >> payrate >> numHr;                                // takes the input for the payrate and number of hours worksed

    if (numHr > dblTime) {
        paychk = payrate * dblTime + 2 * payrate * (numHr - dblTime);  // overtime at double pay
    } else {
        paychk = payrate * numHr;  // straight time
    }
    
    cout << "Paycheck = $" << fixed << setprecision(2) << setw(7) << paychk;      // output payment

    return 0;
}