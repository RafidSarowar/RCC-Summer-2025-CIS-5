#include <iostream>  //Input/Output Library
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int cap, ppl, diff;

    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> cap >> ppl;

    //Map inputs -> outputs and Display the outputs
    if (ppl <= cap) {
        diff = cap - ppl;
        cout << "Meeting can be held." << endl;
        cout << "Increase number of people by " << diff << " will be allowed.";
    } else {
        diff = ppl - cap;
        cout << "Meeting cannot be held." << endl;
        cout << "Reduce number of people by " << diff << " to avoid fire violation.";
    }

    //Exit stage right or left!
    return 0;
}