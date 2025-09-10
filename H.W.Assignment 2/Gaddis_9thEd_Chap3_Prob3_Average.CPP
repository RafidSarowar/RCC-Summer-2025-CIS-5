#include <iostream>

#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    float a, b, c, d, e, avg ;
    
    cout << "Input 5 numbers to average." << endl;

    cin >> a >> b >> c >> d >> e ;

    avg = ((a+b+c+d+e)/5.0f);

    cout << fixed << setprecision(1) << "The average = " << avg;

    return 0;
}