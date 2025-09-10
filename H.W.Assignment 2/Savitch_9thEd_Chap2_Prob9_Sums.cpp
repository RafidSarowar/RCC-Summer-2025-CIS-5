#include <iostream>  //Input/Output Library
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int num, posSum = 0, negSum = 0, allSum = 0;

    //Prompt user
    cout << "Input 10 numbers, any order, positive or negative" << endl;

    //Loop to input 10 numbers
    for (int i = 0; i < 10; i++) {
        cin >> num;
        allSum += num;
        if (num > 0) posSum += num;
        else if (num < 0) negSum += num;
    }

    //Display output exactly matching expected formatting
    cout << "Negative sum = " << (negSum < 0 ? "" : " ") << negSum << endl;
    cout << "Positive sum =  " << posSum << endl;
    cout << "Total sum    =   " << allSum;

    return 0;
}