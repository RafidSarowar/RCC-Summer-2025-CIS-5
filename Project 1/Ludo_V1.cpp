/*
 * File:   Ludo_V1.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 18, 2025
 * Purpose: Two-player Ludo: roll a die, move one of two tokens, first to finish wins.
 */

#include <iostream>   // std::cout, std::cin
#include <cstdlib>    // rand(), srand()
#include <ctime>      // std::time()
using namespace std;


int main() {
    // ---- Named constants ----
    const int ST    = 0;    // start tile index
    const int FN    = 50;   // finish tile index
    const int DS    = 6;    // die faces (1–6)
    const int MAXT  = 500;  // safety cap on number of turns

    // ---- Token positions (explicit, no arrays) ----
    int p1_1 = ST;  // player 1, token 1
    int p1_2 = ST;  // player 1, token 2
    int p2_1 = ST;  // player 2, token 1
    int p2_2 = ST;  // player 2, token 2

    // ---- Game state variables ----
    bool over   = false;  // flag to end game loop
    int  cur    = 1;      // current player (1 or 2)
    int  roll   = 0;      // result of the die roll
    int  tok    = 0;      // selected token (1 or 2)
    int  turns  = 0;      // turn counter
    char buf;             // buffer for pausing on Enter

    // ---- Seed RNG ----
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=== Ludo V1 Lite ===\n\n";

    // ---- Main game loop ----
    while (!over && turns < MAXT) {
        ++turns;  // increment turn count

        // --- Roll phase ---
        cout << "Turn " << turns
             << " | Player " << cur
             << ", press Enter to roll...";
        cin.get(buf);                      // wait for Enter
        roll = (rand() % DS) + 1;          // random 1–6
        cout << "Rolled " << roll << "\n\n";

        // --- Token selection ---
        do {
            cout << "Choose token to move (1 or 2): ";
            cin >> tok;
        } while (tok < 1 || tok > 2);      // validate input
        cin.get(buf);                      // consume newline

        // --- Move the chosen token ---
        if (cur == 1) {
            (tok == 1 ? p1_1 : p1_2) += roll;
        } else {
            (tok == 1 ? p2_1 : p2_2) += roll;
        }

        // --- Display positions ---
        cout << "Positions:\n"
             << "  P1: (" << p1_1 << ", " << p1_2 << ")\n"
             << "  P2: (" << p2_1 << ", " << p2_2 << ")\n\n";

        // --- Victory check ---
        bool win = false;
        if (cur == 1) {
            // player 1 wins if both tokens at or past finish
            if (p1_1 >= FN && p1_2 >= FN) win = true;
        } else {
            // player 2 wins if both tokens at or past finish
            if (p2_1 >= FN && p2_2 >= FN) win = true;
        }

        if (win) {
            cout << "*** Player " << cur << " WINS! ***\n";
            over = true;  // end game
        } else {
            // switch to the other player
            cur = (cur == 1 ? 2 : 1);
            cout << "Next: Player " << cur << "\n\n";
        }
    }

    return 0;
}