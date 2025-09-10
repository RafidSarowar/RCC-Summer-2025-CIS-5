#include <iostream>  

#include <iomanip>

using namespace std;


int main(int argc, char** argv) {
    float F, C;

    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;

    cin >> F;

    C = ( (F-32.01) * (5.0 / 9.0));

    cout << showpoint << fixed << setprecision(1) << F << " Degrees Fahrenheit = " << C <<" Degrees Centigrade";

    return 0;
}