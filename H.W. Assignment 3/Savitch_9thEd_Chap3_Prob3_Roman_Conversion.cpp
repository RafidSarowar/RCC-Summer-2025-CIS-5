/* 
 * File:   Savitch_9thEd_Chap3_Prob3_Roman_Conversion.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:   A program that accepts a year written as a four-digit Arabic (ordinary) numeral and outputs the year written in Roman numerals. 
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {                        // all of the variables with string type because we are takeing characters. 
    int arabic;                                          // we are taking arabic as the input
    string roman;                                        // roman is what it's going to be on the output
    int n1s, n10s, n100s, n1000s;                        // variables to extract the numbers for the conversion
     
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;                        // input instruction
 
    cin >> arabic;                                                 

    n1000s = arabic/1000;                                    // 1000th number 
    n100s = (arabic/100)%10;                                 // 100th number 
    n10s = (arabic% 100) / 10;                     // 10th number
    n1s = (arabic%10);                                       // the number in the ones
 
    if (arabic<1000 || arabic>3000)  {                                 // checks ou the wrong inputs and gives the reinstruction and the return 0 stops the code right there and that was the rest of the codes rum off to. 
        cout << arabic << " is Out of Range!";
        return 0;
    }

    switch(n1000s) {                                        // it only create the cases for the 1000s
        case 3: roman += "M";
        case 2: roman += "M";
        case 1: roman += "M";
    }

    roman +=n100s==9?"CM":                                  // Roman numerals for the 100s
            n100s==8?"DCCC":
            n100s==7?"DCC":
            n100s==6?"DC":
            n100s==5?"D":
            n100s==4?"CD":
            n100s==3?"CCC":
            n100s==2?"CC":
            n100s==1?"C":"";

    // Roman numerals for the 10s place
    if (n10s == 9) roman += "XC";
    else if (n10s == 8) roman += "LXXX";
    else if (n10s == 7) roman += "LXX";
    else if (n10s == 6) roman += "LX";
    else if (n10s == 5) roman += "L";
    else if (n10s == 4) roman += "XL";
    else if (n10s == 3) roman += "XXX";
    else if (n10s == 2) roman += "XX";
    else if (n10s == 1) roman += "X";

    // Roman numerals for the 1s place
    if (n1s == 9) roman += "IX";
    else if (n1s == 8) roman += "VIII";
    else if (n1s == 7) roman += "VII";
    else if (n1s == 6) roman += "VI";
    else if (n1s == 5) roman += "V";
    else if (n1s == 4) roman += "IV";
    else if (n1s == 3) roman += "III";
    else if (n1s == 2) roman += "II";
    else if (n1s == 1) roman += "I";


    cout << arabic << " is equal to " << roman;

    return 0;
}