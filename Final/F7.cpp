/* 
 * File:   F7.cpp
 * Author: Rafid Sarowar
 * Created on 31st July, 2025
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int srch1(const char str[], const char pattern[], int start) {                                    // Searches for the first occurrence of pattern[] in str[] starting from position start
    int slen = strlen(str);
    int plen = strlen(pattern);
    for(int i = start; i <= slen - plen; ++i) {
        int j = 0;
        while(j < plen && str[i+j] == pattern[j]) ++j;
        if(j == plen) return i;                                                                   // pattern matched at position i
    }
    return -1;                                                                                    // Returns the index where found, or -1 if not found
}

void srchAll(const char str[], const char pattern[], int pos[]) {                                 // Finds all occurrences of pattern[] in str[] and stores their positions in pos[]. The list of positions is terminated with -1 as a sentinel value
    int found = 0;
    int start = 0;
    int idx;
    while((idx = srch1(str, pattern, start)) != -1) {
        pos[found++] = idx;                                                                       // store position
        start = idx + 1;                                                                          // look for next match after this index
    }
    pos[found] = -1;                                                                              // sentinel for end
}

void print(const char arr[]) {                                                                    // Prints a null-terminated character array (string)
    cout << arr << endl;
}

void print(const int arr[]) {                                                                     // Prints each match index on a separate line, or "None" if no matches
    if(arr[0] == -1) {
        cout << "None" << endl;
        return;
    }
    int i = 0;
    while(arr[i] != -1) {
        cout << arr[i] << endl;
        ++i;
    }
}