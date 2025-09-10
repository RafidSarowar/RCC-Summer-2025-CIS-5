/* 
 * File:   main.cpp
 * Author: Rafid Sarowar
 * Created on July 18, 2025
 * Purpose:  Menu to be used in the Midterm, future homework and the Final
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;

//Function Prototypes
void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Execution Begins Here
int main(int argc, char** argv) {
    int inN;
    do{
        Menu();
        inN = getN();
        switch(inN){
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
            default: def(inN);
        }
    } while(inN >= 1 && inN <= 6);
    return 0;
}

void Menu(){
    cout << endl;
    cout << "Type 1 to execute Problem 1" << endl;
    cout << "Type 2 to execute Problem 2" << endl;
    cout << "Type 3 to execute Problem 3" << endl;
    cout << "Type 4 to execute Problem 4" << endl;
    cout << "Type 5 to execute Problem 5" << endl;
    cout << "Type 6 to execute Problem 6" << endl;
    cout << "Type anything else to exit." << endl << endl;
}

int getN(){
    int inN;
    cin >> inN;
    return inN;
}

void def(int inN){
    cout << endl << "Typing " << inN << " exits the program." << endl;
}

void problem1(){
    unsigned short size;
    char shape;
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> size >> shape;
    for (int row = 1; row <= size; ++row) {
        for (int col = 1; col <= size; ++col) {
            if (shape == 'x') {
                if (col == row)
                    cout << size - row + 1;
                else if (col == size - row + 1)
                    cout << row;
                else
                    cout << " ";
            }
            else if (shape == 'b') {
                if (col == row)
                    cout << size - row + 1;
                else
                    cout << " ";
            }
            else if (shape == 'f') {
                if (col == size - row + 1)
                    cout << size - row + 1;
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

void problem2(){
    char ch1, ch2, ch3, ch4;
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> ch1 >> ch2 >> ch3 >> ch4;
    char input[4] = {ch1, ch2, ch3, ch4};
    for (int i = 3; i >= 0; --i) {
        cout << input[i] << " ";
        if (isdigit(input[i])) {
            int num = input[i] - '0';
            for (int j = 0; j < num; ++j) cout << "*";
        } else {
            cout << "?";
        }
        cout << endl;
    }
}

void problem3(){
    unsigned short number;
    cout << "Input an integer [1-3000] convert to an English Check value." << endl;
    cin >> number;
    if (number < 1 || number > 3000) {
        cout << "Invalid input." << endl;
        return;
    }
    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;
    if (thousands == 1) cout << "One Thousand ";
    else if (thousands == 2) cout << "Two Thousand ";
    else if (thousands == 3) cout << "Three Thousand ";
    if (hundreds > 0) {
        string hundredsArray[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        cout << hundredsArray[hundreds] << " Hundred ";
    }
    if (tens == 1) {
        string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        cout << teens[ones] << " ";
    } else {
        string tensArray[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if (tens > 1) cout << tensArray[tens] << " ";
        string onesArray[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        if (ones > 0) cout << onesArray[ones] << " ";
    }
    cout << "and no/100's Dollars" << endl;
}

void problem4(){
    char package;
    unsigned short hours;
    float chargeA, chargeB, chargeC = 36.99, currentCharge, cheapestCharge, savings;
    char cheapestPackage;
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package >> hours;
    package = toupper(package);
    if (hours <= 10) chargeA = 16.99;
    else if (hours <= 20) chargeA = 16.99 + (hours - 10) * 0.95;
    else chargeA = 16.99 + 10 * 0.95 + (hours - 20) * 0.85;
    if (hours <= 20) chargeB = 26.99;
    else if (hours <= 30) chargeB = 26.99 + (hours - 20) * 0.74;
    else chargeB = 26.99 + 10 * 0.74 + (hours - 30) * 0.64;
    switch (package) {
        case 'A': currentCharge = chargeA; break;
        case 'B': currentCharge = chargeB; break;
        case 'C': currentCharge = chargeC; break;
        default:
            cout << "Invalid package input!" << endl;
            return;
    }
    cheapestCharge = chargeA;
    cheapestPackage = 'A';
    if (chargeB < cheapestCharge) {
        cheapestCharge = chargeB;
        cheapestPackage = 'B';
    }
    if (chargeC < cheapestCharge) {
        cheapestCharge = chargeC;
        cheapestPackage = 'C';
    }
    savings = currentCharge - cheapestCharge;
    if (savings < 0) savings = 0;
    cout << fixed << setprecision(2);
    cout << "$" << currentCharge << " " << cheapestPackage << " $" << savings << endl;
}

void problem5(){
    float payRate, grossPay = 0;
    unsigned short hrsWrkd;
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    cin >> payRate >> hrsWrkd;
    if (hrsWrkd <= 20)
        grossPay = hrsWrkd * payRate;
    else if (hrsWrkd <= 40)
        grossPay = 20 * payRate + (hrsWrkd - 20) * payRate * 1.5;
    else
        grossPay = 20 * payRate + 20 * payRate * 1.5 + (hrsWrkd - 40) * payRate * 2;
    cout << fixed << setprecision(2);
    cout << "$" << grossPay << endl;
}

void problem6(){
    float x, fx = 0, term;
    int nterms;
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!..." << endl;
    cout << "Input x and the number of terms, output f(x)" << endl;
    cin >> x >> nterms;
    for (int i = 0; i < nterms; i++) {
        int power = 2 * i + 1;
        float numerator = 1.0, denominator = 1.0;
        for (int j = 0; j < power; j++) numerator *= x;
        for (int j = 1; j <= power; j++) denominator *= j;
        term = numerator / denominator;
        fx += (i % 2 == 0) ? term : -term;
    }
    cout << fixed << setprecision(6) << fx << endl;
}
