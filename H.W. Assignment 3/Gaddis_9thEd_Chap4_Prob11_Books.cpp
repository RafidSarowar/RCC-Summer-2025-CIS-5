/* 
 * File:   Gaddis_9thEd_Chap4_Prob11_Books.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:  a program that asks the user to enter the number of books that he or she has
 *           purchased this month and then displays the number of points awarded.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {
    int books, points;                          // all of the variables with string type because we are takeing characters. 

    cout << "Book Worm Points" << endl;                  // input instruction
    cout << "Input the number of books purchased this month." << endl;

    cin >> books;

    cout << "Books purchased =  " << books << endl;
    
    if (books == 0) points = 0;
    else if (books == 1) points = 5;
    else if (books == 2) points = 15;
    else if (books == 3) points = 30;
    else points = 60;

    cout << "Points earned   = " << points;


    return 0;
}