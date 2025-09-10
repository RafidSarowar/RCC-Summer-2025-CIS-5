/*
 * File: Rafid Sarowar
 * Author: Rafid Sarowar
 * Created on: 23rd July, 2025
 * Purpose:  A program that requests the current time and a waiting time as two integers for the number of hours and the number of minutes to wait.
 *           A Program then outputs what the time will be after the waiting period.
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// Function prototypes
void inputTime(int &milHour, int &milMin);
bool convertTime(int milHour, int milMin, int &stdHour, char &ampm);
void outputTime(int milHour, int milMin, int stdHour, char ampm, bool valid);

int main() {
    int milHour, milMin, stdHour;
    char ampm, choice;

    cout << "Military Time Converter to Standard Time\n";
    cout << "Input Military Time hh:mm\n";
    do {
        inputTime(milHour, milMin);

        bool valid = convertTime(milHour, milMin, stdHour, ampm);

        outputTime(milHour, milMin, stdHour, ampm, valid);

        cout << "Would you like to convert another time (y/n)\n";
        cin  >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}

// Reads hours and minutes from the user in hh:mm format
void inputTime(int &milHour, int &milMin) {
    char colon;
    cin  >> milHour >> colon >> milMin;
}

// Converts milHour/milMin into stdHour and sets ampm to 'A' or 'P'
// Returns false if the input time is out of range
bool convertTime(int milHour, int milMin, int &stdHour, char &ampm) {
    if (milHour < 0 || milHour > 23 || milMin < 0 || milMin > 59) {
        return false;
    }

    if (milHour < 12) {
        ampm    = 'A';
        stdHour = (milHour == 0) ? 12 : milHour;
    } else {
        ampm    = 'P';
        stdHour = (milHour > 12) ? (milHour - 12) : milHour;
    }

    return true;
}

// Prints either the converted time or an error message
void outputTime(int milHour, int milMin, int stdHour, char ampm, bool valid) {
    if (!valid) {
        cout << setw(2) << setfill('0') << milHour << ":"
             << setw(2) << setfill('0') << milMin
             << " is not a valid time\n";
    } else {
        cout << setw(2) << setfill('0') << milHour << ":"
             << setw(2) << setfill('0') << milMin
             << " = " << stdHour << ":"
             << setw(2) << setfill('0') << milMin << " "
             << (ampm == 'A' ? "AM\n" : "PM\n");
    }
}
