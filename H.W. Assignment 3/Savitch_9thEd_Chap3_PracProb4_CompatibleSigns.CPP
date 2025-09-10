/* 
 * File:   Savitch_9thEd_Chap3_PracProb4_CompatibleSigns.CPP
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:   A program that will give the compitable astrogoes signes for the couples who are in the same kind. 
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) { 
    string in1, in2;

    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;

    cin >> in1 >> in2;

    if ((in1 == "Aries" || in1 == "Leo" || in1 == "Sagittarius") && (in2 == "Aries" || in2 == "Leo" || in2 == "Sagittarius")) {
        cout << in1 << " and " << in2 << " are compatible Fire signs.";

    } else if ((in1 == "Taurus" || in1 == "Virgo" || in1 == "Capricorn") && (in2 == "Taurus" || in2 == "Virgo" || in2 == "Capricorn")) {
        cout << in1 << " and " << in2 << " are compatible Earth signs.";
    
    } else if ((in1 == "Gemini" || in1 == "Libra" || in1 == "Aquarius") && (in2 == "Gemini" || in2 == "Libra" || in2 == "Aquarius")) {
        cout << in1 << " and " << in2 << " are compatible Air signs.";
    
    } else if ((in1 == "Cancer" || in1 == "Scorpio" || in1 == "Pisces") && (in2 == "Cancer" || in2 == "Scorpio" || in2 == "Pisces")) {
        cout << in1 << " and " << in2 << " are compatible Water signs.";

    } else { 
        cout << in1 << " and " << in2 << " are not compatible signs.";
    }

    return 0;
}