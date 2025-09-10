#include <iostream>

#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    float actual, pref;

    cout << "Insurance Calculator" << endl;
    cout << "How much is your house worth?" << endl;

    cin >> actual;

    cout << "You need $" << (actual*0.80) << " of insurance.";
    
    return 0;
}