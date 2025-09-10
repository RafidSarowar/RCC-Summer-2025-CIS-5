#include <iostream>         // standard input and output library

#include <iomanip>          // input and output manupulator library

#include <cmath>            // Math trig Library

using namespace std;        // standard Name-space where library is compiled, basically user library

const float PI =  4*atan(1);                       // Creating a constant where the pi value is always consistant and it's a floating number, it has 7 significant digits
const float CNVDGRD =  PI/180;                      // pi = 180,  the math library has it as double and when I am making it float it is actually getting a demotion in terms of significant numbers.

int main(int argc, char** argv) {                  // function with the parameters 
    float angleDeg, angleRad;       // Variables where we have Degree and Radians, I also did the trig varables

    cout << "Calculate trig functions" << endl;              //input commands
    cout << "Input the angle in degrees." << endl;

    cin >> angleDeg;                               // takeing the input in the Degrees
    angleRad =angleDeg *CNVDGRD;                   // making it Radian forom the degree b/c of the cmath trig library calculation, basically converting

    cout << "sin(" << static_cast<int>(angleDeg) << ") = " << fixed << setprecision(4) << sin(angleRad) << endl;                // output for sin

    cout << "cos(" << static_cast<int>(angleDeg) << ") = " << fixed << setprecision(4) << cos(angleRad) << endl;                // output for cos

    cout << "tan(" << static_cast<int>(angleDeg) << ") = " << fixed << setprecision(4) << tan(angleRad);                        // output for tan90

 
    return 0;
}