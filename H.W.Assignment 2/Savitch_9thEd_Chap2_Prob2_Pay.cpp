#include <iostream>  //Input/Output Library
#include <iomanip>   //For formatting
using namespace std;

//Global Constants
const float RAISE = 0.076f;  // 7.6% raise

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float oldSal, retro, newSal, newMon;

    //Input the value (no prompt)
    cin >> oldSal;

    //Map inputs -> outputs
    retro = oldSal * RAISE / 2.0f;        // Retroactive pay for 6 months
    newSal = oldSal * (1 + RAISE);        // New annual salary
    newMon = newSal / 12.0f;              // New monthly salary

    cout << "Input previous annual salary." << endl;

    cout << fixed << setprecision(2);

    cout << "Retroactive pay    = $" << setw(7) << retro << endl;
    cout << "New annual salary  = $" << setw(7) << newSal << endl;
    cout << "New monthly salary = $" << setw(7) << newMon;

    return 0;
}