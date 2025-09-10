/*
 * File:    Ludo_P2_V2.cpp
 * Author:  Rafid Sarowar
 * Purpose: Ludo Project 2, Version 2 – Arrays & Functions
 * 1. Declare int arrays for player tokens: p1[2], p2[2]
 * 2. Functions for roll, move, print, win now take arrays (by value/ref)
 * 3. Main loop: roll, pick token, move (using function), print, check win
 * 4. No global variables/constants
 */

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

// --- Function prototypes ---
int rollDie();
void moveToken(int tokens[], int idx, int roll); // pass by reference for array
bool checkWin(const int tokens[]);               // pass by value (const, not modifying)
void printStatus(const int p1[], const int p2[]);

int main()
{
    // --- Local variables ---
    const int START = 0, FINISH = 50;
    int p1[2] = {START, START};
    int p2[2] = {START, START};
    int curP = 1;
    int tok, roll;
    bool win = false;
    char buf;

    srand(static_cast<unsigned int>(time(0)));

    cout << "== Ludo Project 2: Version 2 ==" << endl;
    cout << "Now using arrays for token storage and functions!" << endl
         << endl;

    while (!win)
    {
        // 1. Roll phase
        cout << "Player " << curP << ", press Enter to roll...";
        cin.get(buf);
        roll = rollDie();
        cout << "Rolled: " << roll << endl;

        // 2. Token choice
        do
        {
            cout << "Choose token to move (1 or 2): ";
            cin >> tok;
        } while (tok != 1 && tok != 2);
        cin.get(buf);

        // 3. Move token (using array + function)
        if (curP == 1)
            moveToken(p1, tok - 1, roll); // pass array by reference
        else
            moveToken(p2, tok - 1, roll);

        // 4. Print status
        printStatus(p1, p2);

        // 5. Check for win (pass array by value/const)
        if (curP == 1 && checkWin(p1))
        {
            cout << "*** Player 1 WINS! ***" << endl;
            win = true;
        }
        else if (curP == 2 && checkWin(p2))
        {
            cout << "*** Player 2 WINS! ***" << endl;
            win = true;
        }
        else
        {
            curP = (curP == 1) ? 2 : 1;
        }
    }
    return 0;
}

// --- Function definitions ---

// Returns a random die roll (1–6)
int rollDie()
{
    return (rand() % 6) + 1;
}

// Moves a specific token (array by ref, index, roll)
void moveToken(int tokens[], int idx, int roll)
{
    const int FINISH = 50;
    tokens[idx] += roll;
    if (tokens[idx] > FINISH)
        tokens[idx] = FINISH; // optional safe-stop
}

// Checks if both tokens are at/past finish
bool checkWin(const int tokens[])
{
    const int FINISH = 50;
    return (tokens[0] >= FINISH && tokens[1] >= FINISH);
}

// Prints both players' arrays
void printStatus(const int p1[], const int p2[])
{
    cout << "P1: (" << p1[0] << ", " << p1[1] << ")  ";
    cout << "P2: (" << p2[0] << ", " << p2[1] << ")" << endl
         << endl;
}
