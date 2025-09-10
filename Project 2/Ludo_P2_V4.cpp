/*
 * File:    Ludo_P2_V4.cpp
 * Author:  Rafid Sarowar
 * Purpose: Ludo Project 2, Version 4 – Cut Rule & File Logging
 *   1. Initialize 2D array for tokens, open output file.
 * 2. Main game loop:
     a. Player rolls (log to file).
     b. Player selects token.
     c. Move token (log to file).
     d. Check for and perform cuts (log to file).
     e. Print all positions.
     f. Check for win.
     g. Advance to next player.
 * 3. Close log file on exit.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// --- Function prototypes ---
int rollDie();
void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish, ofstream &logF);
void cutTokens(int tokens[][2], int plCnt, int plIdx, int tokIdx, int start, ofstream &logF);
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

    ofstream logF("ludo_v4_log.txt");
    if (!logF)
    {
        cerr << "Error: Cannot open log file." << endl;
        return 1;
    }

    cout << "\n== Ludo Project 2: Version 4 ==" << endl;
    cout << "Cut rule & file logging enabled!\n"
         << endl;

    while (!win)
    {
        // 1. Roll phase
        cout << "Player " << (curP + 1) << ", press Enter to roll...";
        cin.get(buf);
        roll = rollDie();
        cout << "Rolled: " << roll << endl;
        logF << "P" << (curP + 1) << " rolled " << roll << ". ";

        // 2. Token choice
        do
        {
            cout << "Choose token to move (1 or 2): ";
            cin >> tok;
        } while (tok != 1 && tok != 2);
        cin.get(buf);

        // 3. Move token (array)
        moveToken(tokens, curP, tok - 1, roll, FINISH, logF);

        // 4. Cutting (all other players)
        cutTokens(tokens, plCnt, curP, tok - 1, START, logF);

        // 5. Print status
        printStatus(tokens, plCnt);

        // 6. Check for win
        if (checkWin(tokens, curP, FINISH))
        {
            cout << "*** Player " << (curP + 1) << " WINS! ***" << endl;
            logF << "Player " << (curP + 1) << " wins.\n";
            win = true;
        }
        else
        {
            // 7. Advance player (cycle)
            curP = (curP + 1) % plCnt;
            logF << endl;
        }
    }

    logF.close();
    return 0;
}

// --- Function definitions ---

// Returns a random die roll (1–6)
int rollDie()
{
    return (rand() % 6) + 1;
}

// Move a token, with safe-stop at finish, log result
void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish, ofstream &logF)
{
    int oldVal = tokens[plIdx][tokIdx];
    tokens[plIdx][tokIdx] += roll;
    if (tokens[plIdx][tokIdx] > finish)
        tokens[plIdx][tokIdx] = finish;
    logF << "Moved token " << (tokIdx + 1) << " from " << oldVal << " to " << tokens[plIdx][tokIdx] << ". ";
}

// Cut any opponent tokens on this tile, log cuts
void cutTokens(int tokens[][2], int plCnt, int plIdx, int tokIdx, int start, ofstream &logF)
{
    int movedPos = tokens[plIdx][tokIdx];
    for (int op = 0; op < plCnt; ++op)
    {
        if (op == plIdx)
            continue; // don't check own tokens
        for (int t = 0; t < 2; ++t)
        {
            if (tokens[op][t] == movedPos && movedPos != start)
            {
                tokens[op][t] = start;
                cout << "Cut! Sent Player " << (op + 1) << " Token " << (t + 1) << " to start." << endl;
                logF << "Cut P" << (op + 1) << "T" << (t + 1) << ". ";
            }
        }
    }
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
