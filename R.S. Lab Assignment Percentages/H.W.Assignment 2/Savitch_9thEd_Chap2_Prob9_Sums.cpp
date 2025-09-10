#include <iostream>  //Input/Output Library
#include <iomanip>   // Required for setw
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int num, posSum = 0, negSum = 0;

    //Prompt user
    cout << "Input 10 numbers, any order, positive or negative" << endl;

    //Loop to input 10 numbers
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;
    cin >> num;
    num > 0 ? posSum+=num : negSum+=num;

    //Display output exactly matching expected formatting
    cout << "Negative sum =" << setw(4) << negSum << endl;
    cout << "Positive sum =" << setw(4) << posSum << endl;
    cout << "Total sum    =" << setw(4) << posSum + negSum;

    return 0;
}