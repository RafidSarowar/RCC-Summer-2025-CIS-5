/*
 * File:   Ludo_V4.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 23, 2025 2:30 PM
 * Purpose: This Version have the three consecutive sixes → lose turn rule.
 */

#include <iostream>   // std::cout, std::cin
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()
using namespace std;

int main() {
    // --------------------------------------
    // 1) Declare Game Constants
    // --------------------------------------
    const int ST_POS = 0;  // start tile
    const int FN_POS = 50; // finish tile
    const int D_S = 6;     // dice sides

    // Explicit token positions for up to 4 players
    int p1_1 = ST_POS, p1_2 = ST_POS;
    int p2_1 = ST_POS, p2_2 = ST_POS;
    int p3_1 = ST_POS, p3_2 = ST_POS;
    int p4_1 = ST_POS, p4_2 = ST_POS;

    bool gOver = false; // game-over flag
    int curPl = 1;      // current player index
    int plCnt;          // number of players (2–4)
    int cons6 = 0;      // consecutive-six counter
    char inBuf;         // to pause for Enter

    srand(static_cast<unsigned int>(time(nullptr)));

    // Prompt for player count
    do
    {
        cout << "Enter number of players (2–4): ";
        cin >> plCnt;
    } while (plCnt < 2 || plCnt > 4);
    cin.get(inBuf); // clear newline

    cout << "\n*** Ludo V4: Triple-Six Skip Rule ***\n";

    // Main game loop
    while (!gOver)
    {
        // Roll phase
        cout << "Player " << curPl << ", press Enter to roll...";
        cin.get(inBuf);
        int dRoll = (rand() % D_S) + 1;
        cout << "Rolled: " << dRoll << "\n";

        // Triple-six penalty
        if (dRoll == 6)
        {
            cons6++;
            if (cons6 == 3)
            {
                cout << "Three sixes! You lose your turn.\n";
                cons6 = 0;
                curPl = (curPl % plCnt) + 1;
                continue; // skip movement
            }
        }
        else
        {
            cons6 = 0;
        }

        // Token selection
        int tkCh;
        do
        {
            cout << "Select token (1 or 2): ";
            cin >> tkCh;
        } while (tkCh < 1 || tkCh > 2);
        cin.get(inBuf);

        // Move the chosen token
        if (curPl == 1)
            (tkCh == 1 ? p1_1 : p1_2) += dRoll;
        else if (curPl == 2)
            (tkCh == 1 ? p2_1 : p2_2) += dRoll;
        else if (curPl == 3)
            (tkCh == 1 ? p3_1 : p3_2) += dRoll;
        else
            (tkCh == 1 ? p4_1 : p4_2) += dRoll;

        // Victory check
        bool win = false;
        if ((curPl == 1 && p1_1 >= FN_POS && p1_2 >= FN_POS) ||
            (curPl == 2 && p2_1 >= FN_POS && p2_2 >= FN_POS) ||
            (plCnt >= 3 && curPl == 3 && p3_1 >= FN_POS && p3_2 >= FN_POS) ||
            (plCnt == 4 && curPl == 4 && p4_1 >= FN_POS && p4_2 >= FN_POS))
        {
            win = true;
        }
        if (win)
        {
            cout << "Player " << curPl << " WINS!\n";
            gOver = true;
        }
        else
        {
            // Advance to next player
            curPl = (curPl % plCnt) + 1;
        }
    }

    return 0;
}