/* 
 * File:   M5_paycheck.cpp
 * Author: Rafid Sarowar
 * Created july 18th, 2025
 * Purpose:  Overtime
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
    float payRate, grossPay = 0;
    unsigned short hrsWrkd;
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    if (hrsWrkd <= 20) {                                                                 // less then 20 hour pay 
        grossPay = hrsWrkd * payRate;
    } else if (hrsWrkd <= 40) {                                                          // less them 40 hour pay
        grossPay = 20 * payRate + (hrsWrkd - 20) * payRate * 1.5;
    } else {                                                                              // anything more then 40
        grossPay = 20 * payRate + 20 * payRate * 1.5 + (hrsWrkd - 40) * payRate * 2;
    }

    // Output the check
    cout << fixed << setprecision(2);
    cout << "$" << grossPay << endl;
    return 0;
}