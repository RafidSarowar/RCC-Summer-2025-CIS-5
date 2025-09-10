/*
 * File:   Ludo_V5.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 25, 2025 1:00 PM
 * Purpose: Version 5 adds dual tokens per player and choice of which token to move.
 *          Utilizes only static constants.
 *          Demonstrates RNG, loops, branching, and formatted I/O.
 *          Supports exactly 2 players
 *          Retains cut rule, triple-six skip, safe‑stop, file logging
 *          Simplifies progress display (manual for 2 players)
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    // Named constants
    const int START = 0, FINISH = 50, SIDES = 6, MAXT = 800;

    // Token positions for 2 players
    int p1a = START, p1b = START;
    int p2a = START, p2b = START;

    bool gameOver = false;
    int player = 1, roll, skipsix = 0, choice;
    int turnCount = 0;
    char dummy;

    // Open log file
    srand((unsigned)time(nullptr));
    ofstream logFile("game_log_v5c.txt");
    if (!logFile)
        return 1;

    cout << "*** Ludo V5c: Two-Player Pre-V6 ***\n";
    while (!gameOver && turnCount < MAXT)
    {
        turnCount++;
        cout << "-- Turn " << turnCount << " (P" << player << ") --" << endl;
        cout << "Press Enter to roll...";
        cin.get(dummy);

        roll = (rand() % SIDES) + 1;
        cout << "Rolled: " << roll << endl;
        logFile << "T" << turnCount << ":P" << player << "=" << roll << "\n";

        // Triple-six skip
        if (roll == 6)
        {
            skipsix++;
            if (skipsix == 3)
            {
                cout << "Three sixes! Skipped turn.\n";
                logFile << "P" << player << " skipped (3 sixes)\n";
                skipsix = 0;
                player = 3 - player;
                continue;
            }
        }
        else
            skipsix = 0;

        // Choose token
        do
        {
            cout << "Move token 1 or 2? ";
            cin >> choice;
        } while (choice < 1 || choice > 2);
        cin.get(dummy);

        // Determine pointer for chosen token
        int *tokenPtr = (player == 1)
                            ? (choice == 1 ? &p1a : &p1b)
                            : (choice == 1 ? &p2a : &p2b);

        // Safe-stop
        int newPos = *tokenPtr + roll;
        if (newPos > FINISH)
        {
            *tokenPtr = FINISH;
            cout << "Safe-stop at finish!\n";
            logFile << "P" << player << "T" << choice << " safe at " << FINISH << "\n";
        }
        else
        {
            *tokenPtr = newPos;
            logFile << "P" << player << "T" << choice << "->" << newPos << "\n";
        }

        // Cutting opponent's token
        int moved = *tokenPtr;
        if (player == 1)
        {
            if (moved == (choice == 1 ? p2a : p2b))
            {
                (choice == 1 ? p2a : p2b) = START;
                cout << "P1 cut P2!\n";
                logFile << "Cut P2\n";
            }
        }
        else
        {
            if (moved == (choice == 1 ? p1a : p1b))
            {
                (choice == 1 ? p1a : p1b) = START;
                cout << "P2 cut P1!\n";
                logFile << "Cut P1\n";
            }
        }

        // Progress display
        cout << fixed << setprecision(0);
        cout << "Progress P1: " << (p1a * 100 / FINISH) << "%, "
             << (p1b * 100 / FINISH) << "%  ";
        cout << "P2: " << (p2a * 100 / FINISH) << "%, "
             << (p2b * 100 / FINISH) << "%\n";

        // Check win
        if ((p1a >= FINISH && p1b >= FINISH) ||
            (p2a >= FINISH && p2b >= FINISH))
        {
            cout << "*** Player " << player << " WINS! ***\n";
            gameOver = true;
        }

        // Next player
        if (!gameOver)
            player = 3 - player;
    }

    logFile.close();
    return 0;
}