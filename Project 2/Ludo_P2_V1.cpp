/*
 * File:    Ludo_P2_V1.cpp
 * Author:  Rafid Sarowar
 * Purpose: Modular Ludo (2P, 2 tokens each, base version)
 * 1. Initialize player tokens to 0 (start position)
2. Seed the random number generator
3. Set Player 1 as current player
4. While no one has won:
    a. Roll the die (call rollDie())
    b. Ask current player to pick which token to move (1 or 2)
    c. Move selected token by the die roll (call moveToken())
    d. Print both players’ token positions (call printStatus())
    e. Check if current player has both tokens at or past finish (call checkWin())
        - If yes, announce winner and exit loop
    f. Switch to the next player
 */

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

// --- Function prototypes ---
int rollDie();
void moveToken(int &token, int roll);
bool checkWin(int t1, int t2);
void printStatus(int p1_1, int p1_2, int p2_1, int p2_2);

int main()
{
    // ---- Local variables ----
    const int START = 0, FINISH = 50;
    int p1_1 = START, p1_2 = START;
    int p2_1 = START, p2_2 = START;
    int curP = 1; // 1 or 2
    int tok, roll;
    bool win = false;
    char buf;

    srand(static_cast<unsigned int>(time(0)));

    cout << "== Ludo Project 2: Version 1 ==" << endl;
    cout << "Each player has two tokens. First to finish both wins!" << endl
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

        // 3. Move token
        if (curP == 1)
        {
            moveToken((tok == 1 ? p1_1 : p1_2), roll);
        }
        else
        {
            moveToken((tok == 1 ? p2_1 : p2_2), roll);
        }

        // 4. Print status
        printStatus(p1_1, p1_2, p2_1, p2_2);

        // 5. Check for win
        if (curP == 1 && checkWin(p1_1, p1_2))
        {
            cout << "*** Player 1 WINS! ***" << endl;
            win = true;
        }
        else if (curP == 2 && checkWin(p2_1, p2_2))
        {
            cout << "*** Player 2 WINS! ***" << endl;
            win = true;
        }
        else
        {
            // 6. Switch turn
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

// Moves a token by the rolled value
void moveToken(int &token, int roll)
{
    const int FINISH = 50;
    token += roll;
    if (token > FINISH)
        token = FINISH; // optional safe-stop
}

// Checks if both tokens are at/past finish
bool checkWin(int t1, int t2)
{
    const int FINISH = 50;
    return (t1 >= FINISH && t2 >= FINISH);
}

// Prints current positions
void printStatus(int p1_1, int p1_2, int p2_1, int p2_2)
{
    cout << "P1: (" << p1_1 << ", " << p1_2 << ")  ";
    cout << "P2: (" << p2_1 << ", " << p2_2 << ")" << endl
         << endl;
}
