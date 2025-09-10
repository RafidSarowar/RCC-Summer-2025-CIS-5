/*
 * File: Rafid Sarowar
 * Author: Rafid Sarowar
 * Created on: 23rd July, 2025
 * Purpose:  A program that requests the current time and a waiting time as two integers for the number of hours and the number of minutes to wait.
 *           A Program then outputs what the time will be after the waiting period.
 */

// System Libraries
#include <iostream> //Input/Output Library]
#include <iomanip>  //Input/output manipulator
#include <cctype>
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

// Function Prototypes

// Execution Begins Here!

int main()
{
    int hour, minutes, waitMin;
    char ampm, again;
    do
    {
        // Prompt for current time
        cout << "Enter hour:\n\n";
        cin >> hour;

        cout << "Enter minutes:\n\n";
        cin >> minutes;

        cout << "Enter A for AM, P for PM:\n\n";
        cin >> ampm;

        cout << "Enter waiting time:\n\n";
        cin >> waitMin;

        // Convert input to minutes since midnight
        int h24 = hour % 12;
        if (toupper(ampm) == 'P')                         // toupper() is from the cctype library it's job is to make sure that it convert the even the small case as same as upper case
            h24 += 12;
        int totalMin = h24 * 60 + minutes + waitMin;
        totalMin %= (24 * 60);

        // Convert back to 12-hour
        int newH24 = totalMin / 60;
        int newM = totalMin % 60;
        char newAmpm = (newH24 < 12 ? 'A' : 'P');
        int newH = newH24 % 12;
        if (newH == 0)
            newH = 12;

        // Display results
        cout << "Current time = "
             << setfill('0') << setw(2) << hour << ":"
             << setw(2) << minutes << " "
             << (toupper(ampm) == 'A' ? "AM" : "PM") << "\n";

        cout << "Time after waiting period = "
             << setfill('0') << setw(2) << newH << ":"
             << setw(2) << newM << " "
             << (newAmpm == 'A' ? "AM" : "PM") << "\n\n";

        // Loop
        cout << "Again:" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y') {
            cout << endl;
    }
    } while (again == 'y' || again == 'Y');
    return 0;
}