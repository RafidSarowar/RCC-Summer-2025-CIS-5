/* 
 * File:   Gaddis_9thEd_Chap5_Prob22_Rectangle.CPP
 * Folder: H.W. Assignment 4
 * Author: Rafid Sarowar
 * Created on July 15, 2025 12:36 PM
 * Purpose:   A program that asks the user for a positive integer no greater than 15. The program 
 *            should then display a rectangle on the screen using the character ‘X’.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    int num;
    char inp;

    cin >> num;  // Get size of the square
    cin >> inp;  // Get the character to use

    // Validate input
    if (num >= 1 && num <= 15) {
        for (int i = 1; i <= num; ++i) {
            for (int j = 1; j <= num; ++j) {
                cout << inp;
            }
        if (i != num) cout << endl;
        }
    }

    return 0;
}