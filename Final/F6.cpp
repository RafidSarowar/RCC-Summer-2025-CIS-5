/* 
 * File:   F6.cpp
 * Author: Rafid Sarowar
 * Created on 31st July, 2025
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}
 
void read(int arr[][COLMAX], int &row, int &col) {                                             // Reads in the dimensions and values for the table
    cout << "Input a table and output the Augment row,col and total sums." << endl;            // Basic instruction prompts
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> row >> col;
    cout << "Now input the table." << endl;
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            cin >> arr[i][j];
}

void sum(const int arr[][COLMAX], int row, int col, int augArr[][COLMAX]) {                    // Fills augArr with the original data, row sums, column sums, and the grand sum
    for(int i = 0; i < row; ++i) {                                                             // Copy original values and compute row sums
        int rowSum = 0;                                                                        // Accumalator for the sunms 
        for(int j = 0; j < col; ++j) {
            augArr[i][j] = arr[i][j];                                                          // Copy og value
            rowSum += arr[i][j];                                                               // Adds to the row
        }
        augArr[i][col] = rowSum;                                                               // Last column is row sum
    }

    for(int j = 0; j < col; ++j) {                                                             // Compute column sums
        int colSum = 0;
        for(int i = 0; i < row; ++i)
            colSum += arr[i][j];
        augArr[row][j] = colSum;                                                               // Last row is column sum
    }
    int grandSum = 0;                                                                          // Grand sum (sum of all values, or sum of last row or column)
    for(int i = 0; i < row; ++i)
        grandSum += augArr[i][col];                                                            // Add all row sums
    augArr[row][col] = grandSum;                                                               // Store in bottom-right corner
}

void print(const int arr[][COLMAX], int row, int col, int width) {                              // Prints the table with the given dimensions, using setw(width)
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j)
            cout << setw(width) << arr[i][j];
        cout << endl;
    }
}