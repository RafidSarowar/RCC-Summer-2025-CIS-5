/* 
 * File:   Savitch_9thEd_Chap3_PracProb1_RockPaperScissors.cpp
 * Folder: H.W. Assignment 3
 * Author: Rafid Sarowar
 * Created on July 14, 2025 12:36 PM
 * Purpose:   A program to score the paper-rock-scissor game. Each of two users types in either P, R, or S.
 */

//System Libraries
#include <iostream>             //Input/Output Library
#include <iomanip>              //Input and Output Manipulator
using namespace std;    

int main(int argc, char** argv) {                        // all of the variables with string type because we are takeing characters. 
    char p1, p2;

    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;              // input instruction

    cin >> p1 >> p2;

    if(p1 >= 97)p1-=32;                    // Turns the  lover cass p1 to uppercase
    if(p2 >= 97)p2-=32;                    // Turns the  lover cass p2 to uppercase

    if (p1 == 'R') {
        if (p2 == 'P')cout << "Paper covers rock.";
        else if (p2 == 'S')cout << "Rock breaks scissors.";
        else cout << "Nobody Wins";
    } else if (p1 == 'P') {
        if (p2 == 'S') cout << "Scissors cuts paper.";
        else if (p2 == 'R') cout << "Paper covers rock.";
        else cout << "Nobody Wins";
    } else if (p1 == 'S') {
        if (p2 == 'R') cout << "Rock breaks scissors.";
        else if (p2 == 'P') cout << "Scissors cuts paper.";
        else cout << "Nobody Wins";
    } else cout << "Nobody Wins";

    return 0;
}