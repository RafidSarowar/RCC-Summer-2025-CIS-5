// Author: Rafid Sarowar
// Created on: July 30, 2025
// Purpose: Calculate the average of five test scores after dropping the lowest.

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScre(int &s1, int &s2, int &s3, int &s4, int &s5);
float calcAvg(int s1, int s2, int s3, int s4, int s5);
int  fndLwst(int s1, int s2, int s3, int s4, int s5);

int main() {
    int score1, score2, score3, score4, score5;
    
    cout << "Find the Average of Test Scores\n";
    cout << "by removing the lowest value.\n";
    cout << "Input the 5 test scores.\n";
    
    getScre(score1, score2, score3, score4, score5);
    
    float average = calcAvg(score1, score2, score3, score4, score5);
    
    cout << fixed << setprecision(1);
    cout << "The average test score = " << average;
    
    return 0;
}

//--------------------------------------------------------------
// getScre
//   Prompts for and reads five test scores (1–100), re‑asking
//   any that fall outside the valid range.
//--------------------------------------------------------------
void getScre(int &s1, int &s2, int &s3, int &s4, int &s5) {
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    
    while (s1 < 1 || s1 > 100) {
        cout << "Invalid score; re‑enter a value between 1 and 100: ";
        cin >> s1;
    }
    while (s2 < 1 || s2 > 100) {
        cout << "Invalid score; re‑enter a value between 1 and 100: ";
        cin >> s2;
    }
    while (s3 < 1 || s3 > 100) {
        cout << "Invalid score; re‑enter a value between 1 and 100: ";
        cin >> s3;
    }
    while (s4 < 1 || s4 > 100) {
        cout << "Invalid score; re‑enter a value between 1 and 100: ";
        cin >> s4;
    }
    while (s5 < 1 || s5 > 100) {
        cout << "Invalid score; re‑enter a value between 1 and 100: ";
        cin >> s5;
    }
}

//--------------------------------------------------------------
// fndLwst
//   Returns the lowest of five integer scores.
//--------------------------------------------------------------
int fndLwst(int s1, int s2, int s3, int s4, int s5) {
    int low = s1;
    if (s2 < low) low = s2;
    if (s3 < low) low = s3;
    if (s4 < low) low = s4;
    if (s5 < low) low = s5;
    return low;
}

//--------------------------------------------------------------
// calcAvg
//   Drops the lowest of the five scores, then averages the
//   remaining four and returns the result.
//--------------------------------------------------------------
float calcAvg(int s1, int s2, int s3, int s4, int s5) {
    int lowest = fndLwst(s1, s2, s3, s4, s5);
    int total  = s1 + s2 + s3 + s4 + s5 - lowest;
    return static_cast<float>(total) / 4.0f;
}