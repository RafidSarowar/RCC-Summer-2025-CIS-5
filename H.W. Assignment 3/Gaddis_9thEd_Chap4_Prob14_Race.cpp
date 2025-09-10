/* 
 * File:   Gaddis_9thEd_Chap4_Prob14_Race.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:   A program that asks for the names of three runners and the time it took each of
              them to finish a race. The program should display who came in first, second, and third place.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {                        // all of the variables with string type because we are takeing characters. 
    string nam1, nam2, nam3;
    float t1, t2, t3;

    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;      // input instructuion         

    cin >> nam1 >> t1;
    cin >> nam2 >> t2;
    cin >> nam3 >> t3;

    if (t1 <= t2 && t1 <= t3) {
        cout << nam1 << "\t" << setw(3) << t1 << endl;
        if (t2 <= t3) {
            cout << nam2 << "\t" << setw(3) << t2 << endl;
            cout << nam3 << "\t" << setw(3) << t3;
        } else {
            cout << nam3 << "\t" << setw(3) << t3 << endl;
            cout << nam2 << "\t" << setw(3) << t2;
        }

    } else if (t2 <= t3 && t2 <= t1) {
        cout << nam2 << "\t" << setw(3) << t2 << endl;
        if (t1 <= t3) {
            cout << nam1 << "\t" << setw(3) << t1 << endl;
            cout << nam3 << "\t" << setw(3) << t3;
        } else {
            cout << nam3 << "\t" << setw(3) << t3 << endl;
            cout << nam1 << "\t" << setw(3) << t1;
        }
    } else {
        cout << nam3 << "\t" << setw(3) << t3 << endl;
        if (t1 <= t2) {
            cout << nam1 << "\t" << setw(3) << t1 << endl;
            cout << nam2 << "\t" << setw(3) << t2;
        } else {
            cout << nam2 << "\t" << setw(3) << t2 << endl;
            cout << nam1 << "\t" << setw(3) << t1;
        }
    }    
    return 0;
}