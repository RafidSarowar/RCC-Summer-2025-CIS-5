#include <iostream>
using namespace std;

//Global Constants
const float PERC = 0.001f;      // 1/10th of 1% sweetener per can
const float MLETH = 5.0f;       // Mouse lethal dose in grams
const float MMASS = 35.0f;      // Mouse mass in grams
const float CMASS = 350.0f;     // Can mass in grams
const float GRAMSPERLB = 453.592f; // Conversion from pounds to grams

//Execution Begins Here!
int main() {
    //Declare variables
    float goalW, hLeth, swtCan;
    int maxCan;

    //Display Program Purpose
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;

    //Input user's goal weight in pounds
    cin >> goalW;

    //Convert weight to grams
    goalW *= GRAMSPERLB;

    //Calculate lethal dose for human
    hLeth = (MLETH / MMASS) * goalW;

    //Sweetener per can
    swtCan = CMASS * PERC;

    //Max cans before reaching lethal dose
    maxCan = hLeth / swtCan;

    //Output the result as expected
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << maxCan << " cans";

    return 0;
}