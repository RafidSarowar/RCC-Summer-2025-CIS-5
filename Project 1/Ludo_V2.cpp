/*
 * File:   Ludo_V2.cpp
 * Folder: C:\Users\Rafid\OneDrive\Desktop\CIS-5\Project 1
 * Author: Rafid Sarowar
 * Created on July 20, 2025 1:00 PM
 * Purpose: Adds cutting rule—landing on an opponent's token sends it back to start.
 */

#include <iostream> // std::cout, std::cin
#include <cstdlib>  // rand(), srand()
#include <ctime>    // std::time()
using namespace std;

int main()
{
    // 1) Game constants
    const int ST_POS = 0;     // starting tile index
    const int FN_POS = 50;    // finish tile index (winning)
    const int DICE_SIDES = 6; // faces on the die

    // 2) Token positions (explicit, no arrays)
    //    Player 1
    int p1_t1 = ST_POS;
    int p1_t2 = ST_POS;
    //    Player 2
    int p2_t1 = ST_POS;
    int p2_t2 = ST_POS;

    // 3) Game‐state variables
    bool gameOver = false; // main loop flag
    int currentPlayer = 1; // whose turn (1 or 2)
    int diceRoll = 0;      // result of die roll (1–6)
    int tokenChoice = 0;   // which token to move (1 or 2)
    char inputBuf;         // for pausing on Enter

    // 4) Seed RNG once at startup
    srand(static_cast<unsigned int>(time(nullptr)));

    // 5) Header
    cout << "*** Ludo V2: Cutting Rule ***\n\n";

    // 6) Main game loop
    while (!gameOver)
    {
        // A) Roll phase
        cout << "Player " << currentPlayer << ", press Enter to roll...";
        cin.get(inputBuf);
        diceRoll = (rand() % DICE_SIDES) + 1; // 1–6
        cout << "Rolled: " << diceRoll << "\n";

        // B) Token selection
        do
        {
            cout << "Select token to move (1 or 2): ";
            cin >> tokenChoice;
        } while (tokenChoice < 1 || tokenChoice > 2);
        cin.get(inputBuf); // consume newline

        // C) Move chosen token
        int &activeToken = (currentPlayer == 1)
                               ? (tokenChoice == 1 ? p1_t1 : p1_t2)
                               : (tokenChoice == 1 ? p2_t1 : p2_t2);
        activeToken += diceRoll;
        cout << "Token " << tokenChoice << " is now on tile " << activeToken << "\n";

        // D) Cutting rule: if you land on opponent, send them back
        int &opponentToken = (currentPlayer == 1)
                                 ? (tokenChoice == 1 ? p2_t1 : p2_t2)
                                 : (tokenChoice == 1 ? p1_t1 : p1_t2);
        if (activeToken == opponentToken)
        {
            opponentToken = ST_POS;
            cout << "Cut! Opponent's token returns to start.\n";
        }

        // E) Victory check: both tokens home?
        bool won = false;
        if (currentPlayer == 1)
        {
            if (p1_t1 >= FN_POS && p1_t2 >= FN_POS)
                won = true;
        }
        else
        {
            if (p2_t1 >= FN_POS && p2_t2 >= FN_POS)
                won = true;
        }
        if (won)
        {
            cout << "\n=== Player " << currentPlayer << " WINS! ===\n";
            gameOver = true;
            break;
        }

        // F) Switch turns (1 ↔ 2)
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    // 7) Exit message
    cout << "\nThank you for playing Ludo V2!\n";
    return 0;
}
