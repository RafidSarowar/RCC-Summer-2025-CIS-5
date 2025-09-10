
#include <iostream>

#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int num, calorie;

    cout << "Calorie Counter" << endl;
    cout << "How many cookies did you eat?" << endl;

    cin >> num;
    calorie = num*75;
    cout << "You consumed " << calorie << " calories." ;

    return 0;
}