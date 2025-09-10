/* 
 * File:   F8.cpp
 * Author: Rafid Sarowar
 * Created on 31st July, 2025
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

int read(char array[][COLMAX], int &rows) {                         // Reads each row of a 2D character array, returns the maximum row length detected
    int maxCols = 0;
    cin.ignore();                                                   // Clear any leftover newline in the input buffer
    for(int i = 0; i < rows; i++) {
        cin.getline(array[i], COLMAX);                              // Read each row as a string
        int currentLen = strlen(array[i]);
        if(currentLen > maxCols) {
            maxCols = currentLen;                                   // Track the longest row length found
        }
    }
    return maxCols;
}
// Custom strcmp: replaces chars in a and b per the mapping arrays, then compares
int strcmp(char a[], char b[], const char replace[], const char with[]) {              // Compares two strings after swapping chars using replace/with mapping
    char ca[COLMAX], cb[COLMAX];
    strcpy(ca, a);
    strcpy(cb, b);
    int rlen = strlen(replace);
    for(int i = 0; ca[i] != '\0'; i++) {                                 // Apply mapping to ca: for each char, if it's in 'replace', substitute with corresponding 'with'
        for(int j = 0; j < rlen; j++) {
            if(ca[i] == replace[j]) {
                ca[i] = with[j];
                break;
            }
        }
    }
    for(int i = 0; cb[i] != '\0'; i++) {                                    // Apply mapping to cb
        for(int j = 0; j < rlen; j++) { 
            if(cb[i] == replace[j]) {
                cb[i] = with[j];
                break;
            }
        }
    }
    return strcmp(ca, cb);                                          // Standard string comparison on the mapped results
}

// Sorts the rows of the 2D array using the custom strcmp
void sort(char array[][COLMAX], int rows, int cols, const char replace[], const char with[]) {              // Bubble sort with custom mapping strcmp
    for(int i = 0; i < rows-1; i++) {
        for(int j = 0; j < rows-1-i; j++) {
            if(strcmp(array[j], array[j+1], replace, with) > 0) {                                           // Use custom strcmp for sort order
                char temp[COLMAX];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
}

void print(const char array[][COLMAX], int rows, int cols) {                                              // Prints each row of the 2D char array (one row per line)
    for(int i = 0; i < rows; i++) {
        cout << array[i] << endl;
    }
}
