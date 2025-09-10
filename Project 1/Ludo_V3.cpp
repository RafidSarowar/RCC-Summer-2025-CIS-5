/*
 * File:   Ludo_V3.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 22, 2025
 * Purpose: Supports up to 4 players (2–4), explicit tokens for each.
 */

#include <iostream> // std::cout, std::cin
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

int main()
{
    // --------------------------------------
    // 1) Declare Game Constants
    // --------------------------------------
    const int ST_POS = 0;  // Starting position for every token
    const int FN_POS = 50; // Finish line position; reaching this wins
    const int D_S = 6;     // Number of sides on the die

    // --------------------------------------
    // 2) Token Positions 
    // --------------------------------------
    // Player 1 tokens
    int p1_1 = ST_POS;
    int p1_2 = ST_POS;
    // Player 2 tokens
    int p2_1 = ST_POS;
    int p2_2 = ST_POS;
    // Player 3 tokens
    int p3_1 = ST_POS;
    int p3_2 = ST_POS;
    // Player 4 tokens
    int p4_1 = ST_POS;
    int p4_2 = ST_POS;

    // --------------------------------------
    // 3) Game State Variables
    // --------------------------------------
    bool gOver = false; // Flag to end the game loop
    int curPl;          // Tracks whose turn (1–plCnt)
    int plCnt;          // How many players (2–4)
    char inBuf;         // Used to pause for Enter

    // Seed the random number generator once
    srand(static_cast<unsigned int>(time(nullptr)));

    // --------------------------------------
    // 4) Prompt for Number of Players
    // --------------------------------------
    do
    {
        cout << "Enter number of players (2–4): ";
        cin >> plCnt;
    } while (plCnt < 2 || plCnt > 4);
    cin.get(inBuf); // consume trailing newline

    cout << "\n*** Ludo V3: " << plCnt << " Players ***\n\n";

    // --------------------------------------
    // 5) Main Game Loop
    // --------------------------------------
    curPl = 1; // Player 1 always starts
    while (!gOver)
    {
        // --- A) Roll Phase ---
        cout << "Player " << curPl << ", press Enter to roll...";
        cin.get(inBuf);
        int dRoll = (rand() % D_S) + 1; // 1–6
        cout << "You rolled a " << dRoll << ".\n";

        // --- B) Choose Token to Move ---
        int tkCh;
        do
        {
            cout << "Select token to move (1 or 2): ";
            cin >> tkCh;
        } while (tkCh < 1 || tkCh > 2);
        cin.get(inBuf); // consume newline

        // --- C) Move the Token ---
        // We use a cascade of ternaries to pick the right variable
        if (curPl == 1)
            (tkCh == 1 ? p1_1 : p1_2) += dRoll;
        else if (curPl == 2)
            (tkCh == 1 ? p2_1 : p2_2) += dRoll;
        else if (curPl == 3)
            (tkCh == 1 ? p3_1 : p3_2) += dRoll;
        else
            (tkCh == 1 ? p4_1 : p4_2) += dRoll;

        // Print new position for clarity
        int newPos;
        if (curPl == 1)
            newPos = (tkCh == 1 ? p1_1 : p1_2);
        else if (curPl == 2)
            newPos = (tkCh == 1 ? p2_1 : p2_2);
        else if (curPl == 3)
            newPos = (tkCh == 1 ? p3_1 : p3_2);
        else
            newPos = (tkCh == 1 ? p4_1 : p4_2);
        cout << "Token " << tkCh << " is now on tile " << newPos << ".\n";

        // --- D) Victory Check ---
        bool win = false;
        // Check each player’s two tokens
        if ((p1_1 >= FN_POS && p1_2 >= FN_POS && curPl == 1) ||
            (p2_1 >= FN_POS && p2_2 >= FN_POS && curPl == 2) ||
            (plCnt >= 3 && p3_1 >= FN_POS && p3_2 >= FN_POS && curPl == 3) ||
            (plCnt == 4 && p4_1 >= FN_POS && p4_2 >= FN_POS && curPl == 4))
        {
            win = true;
        }

        if (win)
        {
            // Announce and break out of loop
            cout << "\n=== Player " << curPl << " WINS! ===\n";
            gOver = true;
        }
        else
        {
            // --- E) Advance to Next Player ---
            curPl = (curPl % plCnt) + 1;
            cout << "Next turn: Player " << curPl << "\n\n";
        }
    }

    // --------------------------------------
    // 6) Game End
    // --------------------------------------
    cout << "Thanks for playing!\n";
    return 0;
}