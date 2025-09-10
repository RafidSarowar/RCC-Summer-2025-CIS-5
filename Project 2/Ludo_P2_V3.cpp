/*
 * File:    Ludo_P2_V3.cpp
 * Author:  Rafid Sarowar
 * Purpose: Ludo Project 2, Version 3 – 2–4 Players, 2D Arrays, Modular
 * 1. Prompt user for number of players (2–4).
 * 2. Declare 2D array: tokens[4][2].
 * 3. Game loop:
    a. Current player rolls.
    b. Select token.
    c. Move token (with safe-stop at finish).
    d. Print all players’ positions.
    e. Check for win (both tokens finished).
    f. Advance to next player.
 */

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

// --- Function prototypes ---
int rollDie();
void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish);
bool checkWin(const int tokens[][2], int plIdx, int finish);
void printStatus(const int tokens[][2], int plCnt);

int main()
{
    // --- Local constants ---
    const int START = 0, FINISH = 50, MAXP = 4, TOKS = 2;
    int tokens[MAXP][TOKS] = {{START, START}, {START, START}, {START, START}, {START, START}};

    int plCnt;
    do
    {
        cout << "Enter number of players (2–4): ";
        cin >> plCnt;
    } while (plCnt < 2 || plCnt > 4);
    char buf;
    cin.get(buf); // clear newline

    int curP = 0; // player index (0 to plCnt-1)
    int tok, roll;
    bool win = false;

    srand(static_cast<unsigned int>(time(0)));

    cout << "\n== Ludo Project 2: Version 3 ==" << endl;
    cout << "Now supports up to 4 players using 2D arrays!\n"
         << endl;

    while (!win)
    {
        // 1. Roll phase
        cout << "Player " << (curP + 1) << ", press Enter to roll...";
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

        // 3. Move token (array)
        moveToken(tokens, curP, tok - 1, roll, FINISH);

        // 4. Print status
        printStatus(tokens, plCnt);

        // 5. Check for win
        if (checkWin(tokens, curP, FINISH))
        {
            cout << "*** Player " << (curP + 1) << " WINS! ***" << endl;
            win = true;
        }
        else
        {
            // 6. Advance player (cycle)
            curP = (curP + 1) % plCnt;
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

// Move a token, with safe-stop at finish
void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish)
{
    tokens[plIdx][tokIdx] += roll;
    if (tokens[plIdx][tokIdx] > finish)
        tokens[plIdx][tokIdx] = finish;
}

// Check if both tokens for player are at finish
bool checkWin(const int tokens[][2], int plIdx, int finish)
{
    return (tokens[plIdx][0] >= finish && tokens[plIdx][1] >= finish);
}

// Print all players' tokens
void printStatus(const int tokens[][2], int plCnt)
{
    for (int i = 0; i < plCnt; ++i)
    {
        cout << "P" << (i + 1) << ": (" << tokens[i][0] << ", " << tokens[i][1] << ")  ";
    }
    cout << endl
         << endl;
}
