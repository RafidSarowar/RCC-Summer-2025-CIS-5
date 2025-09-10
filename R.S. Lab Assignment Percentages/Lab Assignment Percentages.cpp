#include <iostream>
using namespace std;

int main() {
    float milBdgt, fedBdgt, mlPrcnt;

    milBdgt = 8.42e11f;   // Military Budget = 842 Billion
    fedBdgt = 6.5e12f;    // Federal Budget = 6.5 Trillion

    mlPrcnt = (milBdgt / fedBdgt) * 100;

    cout << "Military Budget = $" << milBdgt << endl;
    cout << "Federal Budget = $" << fedBdgt << endl;
    cout << "Military as % of Federal Budget = " << mlPrcnt << "%" << endl;

    return 0;
}
