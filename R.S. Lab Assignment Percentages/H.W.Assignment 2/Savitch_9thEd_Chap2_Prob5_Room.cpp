#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int cap, ppl, diff;

    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> cap >> ppl;

    diff = (ppl <= cap) ? (cap - ppl) : (ppl - cap);

        cout << ((ppl <= cap)
        ? "Meeting can be held.\nIncrease number of people by " + to_string(cap - ppl) + " will be allowed without violation."
        : "Meeting cannot be held.\nReduce number of people by " + to_string(ppl - cap) + " to avoid fire violation.");

    //Exit stage right or left!
    return 0;
}