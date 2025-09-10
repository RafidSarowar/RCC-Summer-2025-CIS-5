/* 
 * File:   F5.cpp
 * Author: Rafid Sarowar
 * Created on 31st July, 2025
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd) {                            // Reads integers from the user and separates them into even and odd vectors
    int n, val;
    cout << "Input the number of integers to input." << endl;
    cin >> n;
    cout << "Input each number." << endl;                                   // <-- match required wording!
    for(int i = 0; i < n; ++i) {                                            // Read n numbers and classify each as even or odd                                
        cin >> val;
        if(val % 2 == 0)
            even.push_back(val);                                           // Even
        else
            odd.push_back(val);                                            // odd
    }
}

void copy(vector<int> even, vector<int> odd, int arr[][COLMAX]) {        // Copies the values from even and odd vectors into a 2D array. The first column gets even values, the second gets odd values. If one vector is shorter, zeros are used as placeholders.
    int maxSize = max(even.size(), odd.size());
    for(int i = 0; i < maxSize; ++i) {
        arr[i][0] = (i < even.size()) ? even[i] : 0;                    // Even
        arr[i][1] = (i < odd.size())  ? odd[i]  : 0;                    // odd
    }
}

void prntVec(vector<int> even, vector<int> odd, int width) {
    cout << "    Vector" << setw(width) << "Even" << setw(width) << "Odd" << endl;                 // Four spaces before "Vector"
    int maxSize = max(even.size(), odd.size());
    for(int i = 0; i < maxSize; ++i) {
        cout << "          ";                                                                      //10 spaces                                               
        if(i < even.size())                               // Even
            cout << setw(width) << even[i];
        else                                              // Empty
            cout << setw(width) << "";
        if(i < odd.size())                                // Odd
            cout << setw(width) << odd[i];
        else                                              // Empty
            cout << setw(width) << "";
        cout << endl;
    }
}

void prntAry(const int arr[][COLMAX], int eSize, int oSize, int width) {
    cout << "     Array" << setw(width) << "Even" << setw(width) << "Odd" << endl;                  // Five spaces before "Array"
    int maxSize = max(eSize, oSize);
    for(int i = 0; i < maxSize; ++i) {
        cout << "          ";                                                                       // ten spaces
        if(i < eSize)                                             // Even
            cout << setw(width) << arr[i][0];
        else                                                      // Empty
            cout << setw(width) << "";
        if(i < oSize)                                             // Odd
            cout << setw(width) << arr[i][1]; 
        else                                                      // Empty 
            cout << setw(width) << "";
        cout << endl;
    }
}