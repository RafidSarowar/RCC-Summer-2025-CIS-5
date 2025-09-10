/*
 * File:   Ludo_V6.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 27, 2025 1:30 PM
 * Purpose: This program is a complete, console‑based implementation of the classic board game Ludo for two to four players. 
 *          It begins by printing a friendly welcome and detailed rules, then prompts the user to select how many players will participate.
 *          Each turn, it simulates rolling a six‑sided die (with three‑six penalty logic), lets the current player choose which of their 
 *          two tokens to move (applying a “safe‑stop” at the finish if a roll would overshoot), and checks for and handles any “cuts” 
 *          when one token lands on another. After every move it logs the action to a file, prints out a progress report showing each token’s 
 *          percentage toward home, and tests for a winning condition (both tokens home). The game loop continues until a player wins or 
 *          a turn limit is reached, at which point it prints a victory message and exits.
 */

#include <iostream> // std::cout, std::cin
#include <fstream>  // std::ofstream
#include <iomanip>  // std::setprecision, std::fixed
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <cmath>    // pow()
#include <string>   // std::string

using namespace std;

int main()
{
    // --------------------------------------
    // Welcome & Game Instructions
    // --------------------------------------
    cout << "\n=== Welcome to Ludo (Version 6) ===" << endl;
    cout << "Ludo is a classic board game for 2 to 4 players." << endl;
    cout << "Each player controls two tokens, aiming to move them from the start (tile 0) to the finish (tile 50)." << endl;
    cout << "On your turn, you roll a six-sided dice and then choose which token to advance." << endl;
    cout << "Rules:" << endl;
    cout << " - Rolling three consecutive sixes makes you lose your turn." << endl;
    cout << " - If your token lands on an opponent's token, that token is cut and sent back to start." << endl;
    cout << " - Tokens cannot move past the finish; if a roll would overshoot, you are safe-stopped at the finish tile." << endl;
    cout << "First player to get both tokens home wins the game. Good luck!\n"
         << endl;

    ////////////////////////////////
    // Section 0: Pseudocode       //
    ////////////////////////////////
    /*
     * 1. Initialize constants and vars
     * 2. Prompt for player count (2–4)
     * 3. Seed RNG, open log file
     * 4. Loop until someone wins or turn limit
     *    a) Player roll, check triple six
     *    b) Choose token, apply safe-stop
     *    c) Check for cut, log events
     *    d) Show progress, check victory
     *    e) Advance player
     * 5. Close log and exit
     */
    // Local named constants (<=7 chars)
    static const int ST_POS = 0;     // start tile
    static const int FN_POS = 50;    // finish tile
    static const int D_S = 6;        // dice sides
    static const int M_PL = 4;       // max players
    static const int T_P = 2;        // tokens each
    static const int M_TN = 1000;    // max turns
    static const float PBS = 1.234f; // dummy pow base

    // Token positions (explicit, no arrays)
    int p1_1 = ST_POS, p1_2 = ST_POS;
    int p2_1 = ST_POS, p2_2 = ST_POS;
    int p3_1 = ST_POS, p3_2 = ST_POS;
    int p4_1 = ST_POS, p4_2 = ST_POS;

    // Control and state variables
    bool gOver = false; // game over flag
    int curPl = 1;      // current player index
    int plCnt = 0;      // number of players
    int dRoll = 0;      // result of dice roll
    int cons6 = 0;      // consecutive six counter
    int tkCh = 0;       // token choice (1 or 2)
    int turnCt = 0;     // turn counter
    float prPct = 0.0f; // progress percentage
    float dmVal = 0.0f; // dummy math value
    char inBuf = '\n';  // for pausing on Enter

    //////////////////////////////////////////
    // Section 1: Prompt for # of Players
    //////////////////////////////////////////
    do
    {
        cout << "Enter players (2-" << M_PL << "): ";
        cin >> plCnt;
    } while (plCnt < 2 || plCnt > M_PL);
    cin.get(inBuf); // clear newline

    //////////////////////////////////////////
    // Section 2: Seed RNG & Open Log File
    //////////////////////////////////////////
    srand(static_cast<unsigned int>(time(nullptr)));
    ofstream logF("game_log_v6.txt");
    if (!logF)
    {
        cerr << "Error: cannot open log file";
        return EXIT_FAILURE;
    }

    //////////////////////////////////////////
    // Section 3: Main Game Loop
    //////////////////////////////////////////
    while (!gOver && turnCt < M_TN)
    {
        ++turnCt; // increment turn count

        // --- Roll Phase ---
        cout << "-- Turn " << turnCt << " --" << endl;
        cout << "Player " << curPl << ", press Enter to roll...";
        cin.get(inBuf);
        dRoll = (rand() % D_S) + 1;
        cout << "Rolled: " << dRoll << endl;
        logF << "Turn " << turnCt << ": P" << curPl << " rolled " << dRoll << " ";

        // --- Pip Description ---
        switch (dRoll)
        {
        case 1:
            cout << "One pip." << endl;
            break;
        case 2:
            cout << "Two pips." << endl;
            break;
        case 3:
            cout << "Three pips." << endl;
            break;
        case 4:
            cout << "Four pips." << endl;
            break;
        case 5:
            cout << "Five pips." << endl;
            break;
        case 6:
            cout << "Six pips." << endl;
            break;
        }

        // --- Triple-Six Skip ---
        if (dRoll == 6)
        {
            ++cons6;
            if (cons6 >= 3)
            {
                cout << "Three sixes! Turn lost." << endl;
                logF << "P" << curPl << " lost turn (3 sixes)";
                cons6 = 0;
                curPl = (curPl % plCnt) + 1;
                continue; // skip movement
            }
        }
        else
        {
            cons6 = 0;
        }

        /////////////////////////////////////////////////////
        // Section 4: Token Selection & Safe-Stop
        /////////////////////////////////////////////////////
        do
        {
            cout << "Select token (1-" << T_P << "): ";
            cin >> tkCh;
        } while (tkCh < 1 || tkCh > T_P);
        cin.get(inBuf); // clear newline

        int *tokPtr = nullptr;
        if (curPl == 1)
            tokPtr = (tkCh == 1 ? &p1_1 : &p1_2);
        else if (curPl == 2)
            tokPtr = (tkCh == 1 ? &p2_1 : &p2_2);
        else if (curPl == 3)
            tokPtr = (tkCh == 1 ? &p3_1 : &p3_2);
        else
            tokPtr = (tkCh == 1 ? &p4_1 : &p4_2);

        int newPos = *tokPtr + dRoll;
        if (newPos > FN_POS)
        {
            *tokPtr = FN_POS;
            cout << "Safe-stop: token set to finish (" << FN_POS << ")" << endl;
            logF << "P" << curPl << "T" << tkCh << " safe-stopped at " << FN_POS << " ";
        }
        else
        {
            *tokPtr = newPos;
            logF << "P" << curPl << "T" << tkCh << " -> " << newPos << " ";
        }

        //////////////////////////////////////
        // Section 5: Cutting Opponents
        //////////////////////////////////////
        int movedPos = *tokPtr;
        if (curPl == 1)
        {
            if (movedPos == p2_1)
            {
                p2_1 = ST_POS;
                cout << "Cut P2_1!" << endl;
                logF << "Cut P2_1";
            }
            if (movedPos == p2_2)
            {
                p2_2 = ST_POS;
                cout << "Cut P2_2!" << endl;
                logF << "Cut P2_2";
            }
            if (plCnt >= 3)
            {
                if (movedPos == p3_1)
                {
                    p3_1 = ST_POS;
                    cout << "Cut P3_1!" << endl;
                    logF << "Cut P3_1";
                }
                if (movedPos == p3_2)
                {
                    p3_2 = ST_POS;
                    cout << "Cut P3_2!" << endl;
                    logF << "Cut P3_2";
                }
            }
            if (plCnt == 4)
            {
                if (movedPos == p4_1)
                {
                    p4_1 = ST_POS;
                    cout << "Cut P4_1!" << endl;
                    logF << "Cut P4_1";
                }
                if (movedPos == p4_2)
                {
                    p4_2 = ST_POS;
                    cout << "Cut P4_2!" << endl;
                    logF << "Cut P4_2";
                }
            }
        }
        else if (curPl == 2)
        {
            if (movedPos == p1_1)
            {
                p1_1 = ST_POS;
                cout << "Cut P1_1!" << endl;
                logF << "Cut P1_1";
            }
            if (movedPos == p1_2)
            {
                p1_2 = ST_POS;
                cout << "Cut P1_2!" << endl;
                logF << "Cut P1_2";
            }
            if (plCnt >= 3)
            {
                if (movedPos == p3_1)
                {
                    p3_1 = ST_POS;
                    cout << "Cut P3_1!" << endl;
                    logF << "Cut P3_1";
                }
                if (movedPos == p3_2)
                {
                    p3_2 = ST_POS;
                    cout << "Cut P3_2!" << endl;
                    logF << "Cut P3_2";
                }
            }
            if (plCnt == 4)
            {
                if (movedPos == p4_1)
                {
                    p4_1 = ST_POS;
                    cout << "Cut P4_1!" << endl;
                    logF << "Cut P4_1";
                }
                if (movedPos == p4_2)
                {
                    p4_2 = ST_POS;
                    cout << "Cut P4_2!" << endl;
                    logF << "Cut P4_2";
                }
            }
        }
        else if (curPl == 3)
        {
            if (movedPos == p1_1)
            {
                p1_1 = ST_POS;
                cout << "Cut P1_1!" << endl;
                logF << "Cut P1_1";
            }
            if (movedPos == p1_2)
            {
                p1_2 = ST_POS;
                cout << "Cut P1_2!" << endl;
                logF << "Cut P1_2";
            }
            if (plCnt >= 2)
            {
                if (movedPos == p2_1)
                {
                    p2_1 = ST_POS;
                    cout << "Cut P2_1!" << endl;
                    logF << "Cut P2_1";
                }
                if (movedPos == p2_2)
                {
                    p2_2 = ST_POS;
                    cout << "Cut P2_2!" << endl;
                    logF << "Cut P2_2";
                }
            }
            if (plCnt == 4)
            {
                if (movedPos == p4_1)
                {
                    p4_1 = ST_POS;
                    cout << "Cut P4_1!" << endl;
                    logF << "Cut P4_1";
                }
                if (movedPos == p4_2)
                {
                    p4_2 = ST_POS;
                    cout << "Cut P4_2!" << endl;
                    logF << "Cut P4_2";
                }
            }
        }
        else
        {
            if (movedPos == p1_1)
            {
                p1_1 = ST_POS;
                cout << "Cut P1_1!" << endl;
                logF << "Cut P1_1";
            }
            if (movedPos == p1_2)
            {
                p1_2 = ST_POS;
                cout << "Cut P1_2!" << endl;
                logF << "Cut P1_2";
            }
            if (plCnt >= 2)
            {
                if (movedPos == p2_1)
                {
                    p2_1 = ST_POS;
                    cout << "Cut P2_1!" << endl;
                    logF << "Cut P2_1";
                }
                if (movedPos == p2_2)
                {
                    p2_2 = ST_POS;
                    cout << "Cut P2_2!" << endl;
                    logF << "Cut P2_2";
                }
            }
            if (plCnt >= 3)
            {
                if (movedPos == p3_1)
                {
                    p3_1 = ST_POS;
                    cout << "Cut P3_1!" << endl;
                    logF << "Cut P3_1";
                }
                if (movedPos == p3_2)
                {
                    p3_2 = ST_POS;
                    cout << "Cut P3_2!" << endl;
                    logF << "Cut P3_2";
                }
            }
        }

        //////////////////////////////////////
        // Section 6: Progress Report
        //////////////////////////////////////
        cout << "-- Progress Report --" << endl;
        cout << fixed << setprecision(1);
        // Iterate through each player using a for loop
        for (int p = 1; p <= plCnt; ++p)
        {
            if (p == 1)
            {
                prPct = p1_1 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P1_1:" << prPct << "%  ";
                prPct = p1_2 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P1_2:" << prPct << "%";
            }
            else if (p == 2)
            {
                prPct = p2_1 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P2_1:" << prPct << "%  ";
                prPct = p2_2 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P2_2:" << prPct << "%";
            }
            else if (p == 3)
            {
                prPct = p3_1 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P3_1:" << prPct << "%  ";
                prPct = p3_2 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P3_2:" << prPct << "%";
            }
            else if (p == 4)
            {
                prPct = p4_1 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P4_1:" << prPct << "%  ";
                prPct = p4_2 * 100.0f / FN_POS;
                dmVal = pow(prPct, PBS);
                cout << "P4_2:" << prPct << "%";
            }
        }

        //////////////////////////////////////
        // Section 7: Victory Check
        //////////////////////////////////////
        bool win = false;
        if ((p1_1 >= FN_POS && p1_2 >= FN_POS) ||
            (p2_1 >= FN_POS && p2_2 >= FN_POS) ||
            (plCnt >= 3 && p3_1 >= FN_POS && p3_2 >= FN_POS) ||
            (plCnt == 4 && p4_1 >= FN_POS && p4_2 >= FN_POS))
        {
            win = true;
        }
        if (win)
        {
            cout << "=== GAME OVER ===" << endl;
            if (p1_1 >= FN_POS && p1_2 >= FN_POS)
                cout << "Player 1 WINS!" << endl;
            if (p2_1 >= FN_POS && p2_2 >= FN_POS)
                cout << "Player 2 WINS!" << endl;
            if (plCnt >= 3 && p3_1 >= FN_POS && p3_2 >= FN_POS)
                cout << "Player 3 WINS!" << endl;
            if (plCnt == 4 && p4_1 >= FN_POS && p4_2 >= FN_POS)
                cout << "Player 4 WINS!" << endl;
            gOver = true;
        }

        // Advance to next player if game not over
        if (!gOver)
        {
            curPl = (curPl % plCnt) + 1;
            cout << "Next: Player " << curPl << endl;
            cout << string(50, '=') << endl;
        }
    }

    // Close log and exit
    logF.close();
    return EXIT_SUCCESS;
}