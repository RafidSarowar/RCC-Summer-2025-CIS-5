/*
 * File:    Ludo_P2_V5.cpp
 * Author:  Rafid Sarowar
 * Purpose: Ludo Project 2, Version 5 – Statistics, Sorting, Leaderboard
 * 
 * 1. Declare 2D arrays for tokens and moves, 1D arrays for stats (turns, cuts).
 * 2. Input player names.
 * 3. Game loop:
     a. Player rolls.
     b. Select token.
     c. Move token (record moves).
     d. Perform cuts (update cuts stat).
     e. Print status.
     f. Check for win (record turns, time, etc.).
     g. Advance player.
 * 4. When game ends:
     a. Sort all players by performance (moves/cuts).
     b. Search for player with most cuts.
     c. Print stats/leaderboard.
     d. Write stats to leaderboard file.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// --- Function prototypes ---
int rollDie();
void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish, ofstream &logF);
int cutTokens(int tokens[][2], int plCnt, int plIdx, int tokIdx, int start, ofstream &logF);
bool checkWin(const int tokens[][2], int plIdx, int finish);
void printStatus(const int tokens[][2], const string names[], int plCnt);
int findMax(const int arr[], int sz);                     // search
void sortPlayers(string names[], int moves[], int plCnt); // sort by moves

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
    cin.get(buf);

    string names[MAXP];
    for (int i = 0; i < plCnt; ++i)
    {
        cout << "Enter name for Player " << (i + 1) << ": ";
        getline(cin, names[i]);
    }

    int turns[MAXP] = {0}, cuts[MAXP] = {0}, moves[MAXP] = {0};
    bool win = false;
    int curP = 0, tok, roll;

    srand(static_cast<unsigned int>(time(0)));

    ofstream logF("ludo_v5_log.txt");
    if (!logF)
    {
        cerr << "Error: Cannot open log file." << endl;
        return 1;
    }

    cout << "\n== Ludo Project 2: Version 5 ==" << endl;
    cout << "Stats, sorting, leaderboard enabled!\n"
         << endl;

    while (!win)
    {
        // 1. Roll phase
        cout << names[curP] << "'s turn, press Enter to roll...";
        cin.get(buf);
        roll = rollDie();
        cout << "Rolled: " << roll << endl;
        logF << names[curP] << " rolled " << roll << ". ";

        // 2. Token choice
        do
        {
            cout << "Choose token to move (1 or 2): ";
            cin >> tok;
        } while (tok != 1 && tok != 2);
        cin.get(buf);

        // 3. Move token (array)
        moveToken(tokens, curP, tok - 1, roll, FINISH, logF);
        moves[curP]++;

        // 4. Cutting (all other players)
        int cutCount = cutTokens(tokens, plCnt, curP, tok - 1, START, logF);
        cuts[curP] += cutCount;

        // 5. Print status
        printStatus(tokens, names, plCnt);

        // 6. Check for win
        if (checkWin(tokens, curP, FINISH))
        {
            cout << "*** " << names[curP] << " WINS! ***" << endl;
            logF << names[curP] << " wins.\n";
            win = true;
        }
        else
        {
            // 7. Advance player (cycle)
            curP = (curP + 1) % plCnt;
            logF << endl;
        }
        turns[curP]++;
    }
    logF.close();

    // --- Post-game: Sort, search, stats, leaderboard ---
    cout << "\n-- Final Stats --\n";
    for (int i = 0; i < plCnt; ++i)
    {
        cout << setw(12) << left << names[i]
             << "  Moves: " << moves[i]
             << "  Cuts: " << cuts[i]
             << "  Turns: " << turns[i] << endl;
    }

    int maxCutter = findMax(cuts, plCnt);
    cout << "\nMost cuts: " << names[maxCutter] << " (" << cuts[maxCutter] << ")\n";

    // Sort players by moves (ascending)
    sortPlayers(names, moves, plCnt);
    cout << "\nLeaderboard (fewest moves to win):\n";
    for (int i = 0; i < plCnt; ++i)
    {
        cout << setw(12) << left << names[i] << "  Moves: " << moves[i] << endl;
    }

    // Write leaderboard to file
    ofstream boardF("ludo_leaderboard.txt", ios::app);
    if (boardF)
    {
        boardF << "Game Results: ";
        for (int i = 0; i < plCnt; ++i)
        {
            boardF << names[i] << "(" << moves[i] << " moves, " << cuts[i] << " cuts)  ";
        }
        boardF << endl;
        boardF.close();
    }

    return 0;
}

// --- Function definitions ---

int rollDie() { return (rand() % 6) + 1; }

void moveToken(int tokens[][2], int plIdx, int tokIdx, int roll, int finish, ofstream &logF)
{
    int oldVal = tokens[plIdx][tokIdx];
    tokens[plIdx][tokIdx] += roll;
    if (tokens[plIdx][tokIdx] > finish)
        tokens[plIdx][tokIdx] = finish;
    logF << "Moved token " << (tokIdx + 1) << " from " << oldVal << " to " << tokens[plIdx][tokIdx] << ". ";
}

// Returns # of cuts made
int cutTokens(int tokens[][2], int plCnt, int plIdx, int tokIdx, int start, ofstream &logF)
{
    int movedPos = tokens[plIdx][tokIdx], cuts = 0;
    for (int op = 0; op < plCnt; ++op)
    {
        if (op == plIdx)
            continue;
        for (int t = 0; t < 2; ++t)
        {
            if (tokens[op][t] == movedPos && movedPos != start)
            {
                tokens[op][t] = start;
                cuts++;
                cout << "Cut! Sent " << "P" << (op + 1) << " Token " << (t + 1) << " to start." << endl;
                logF << "Cut P" << (op + 1) << "T" << (t + 1) << ". ";
            }
        }
    }
    return cuts;
}

bool checkWin(const int tokens[][2], int plIdx, int finish)
{
    return (tokens[plIdx][0] >= finish && tokens[plIdx][1] >= finish);
}

void printStatus(const int tokens[][2], const string names[], int plCnt)
{
    for (int i = 0; i < plCnt; ++i)
    {
        cout << names[i] << ": (" << tokens[i][0] << ", " << tokens[i][1] << ")  ";
    }
    cout << endl
         << endl;
}

// Find the index of the max value in array (search)
int findMax(const int arr[], int sz)
{
    int maxIdx = 0;
    for (int i = 1; i < sz; ++i)
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    return maxIdx;
}

// Sort players by moves (ascending, parallel array/string)
void sortPlayers(string names[], int moves[], int plCnt)
{
    for (int i = 0; i < plCnt - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < plCnt; ++j)
            if (moves[j] < moves[minIdx])
                minIdx = j;
        // Swap both arrays
        swap(moves[i], moves[minIdx]);
        swap(names[i], names[minIdx]);
    }
}
