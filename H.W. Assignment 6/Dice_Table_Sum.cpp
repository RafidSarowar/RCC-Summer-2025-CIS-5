/*
 * File:   Dice_Table_Sum.cpp
 * Author: Rafid Sarowar
 * Created: july 29, 2025
 * Purpose: Display a 6×6 table showing the sums of two dice (1–6),
 *
 */

// System Libraries
#include <iostream> //Input/Output Library
#include <iomanip>  //Format Library
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS = 6;

// Function Prototypes
void fillTbl(int[][COLS], int);
void prntTbl(const int[][COLS], int);

// Execution Begins Here!
int main(int argc, char **argv)
{
    // Declare Variables
    const int ROWS = 6;
    int tablSum[ROWS][COLS];

    cout << "Think of this as the Sum of Dice Table\n";

    // Initialize or input i.e. set variable values
    fillTbl(tablSum, ROWS);

    // Display the outputs
    prntTbl(tablSum, ROWS);

    // Exit stage right or left!
    return 0;
}
void fillTbl(int table[][COLS], int rows)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            table[r][c] = (r + 1) + (c + 1);
        }
    }
}

void prntTbl(const int table[][COLS], int rows)
{
    // Print "C o l u m n s" header
    cout << "           C o l u m n s\n";

    // Print column numbers 1–6
    cout << "     |";
    for (int c = 1; c <= COLS; ++c)
    {
        cout << setw(4) << c;
    }
    cout << "\n";

    // Separator line
    cout << "----------------------------------\n";

    // Vertical "ROWS" label
    const string rowsLabel = "ROWS";

    // Print each row: letter (or space), row number, then the sums
    for (int r = 1; r <= rows; ++r)
    {
        char letter = (r >= 2 && r <= 5) ? rowsLabel[r - 2] : ' ';
        cout << letter << setw(3) << r << " |";
        for (int c = 0; c < COLS; ++c)
        {
            cout << setw(4) << table[r - 1][c];
        }
        cout << "\n";
    }
}