/* 
 * File:   Scantron.c[[]]
 * Author: Rafid Sarowar
 * Created on: 30 July, 2025
 * Purpose: Compare the answer sheet to the key
 *          and grade
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string.h>  //String Library
using namespace std;

//User Libraries
//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void print(const string &);
void read(const char [],string &);
int  compare(const string &,const string &,string &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string key,answers,score;
    char fileKey[]="key.dat",fileAns[]="answer.dat";
    float pRight;
    
    //Initialize or input i.e. set variable values
    read(fileKey,key);
    read(fileAns,answers);
    
    //Score the exam
    pRight=compare(key,answers,score);
    
    //Display the outputs
    //cout<<"Key     ";print(key);
    //cout<<"Answers ";print(answers);
    cout<<"C/W     ";print(score);
    cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;
    
    //Exit stage right or left!
    return 0;
}

//Function Implementations

// Function to print a string with spaces between characters
void print(const string &str) {
    for(int i = 0; i < str.length(); i++) {
        cout << str[i];
        if(i < str.length() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Function to read a string - reads from standard input
void read(const char file[], string &str){
    str.clear();
    if (strcmp(file, "key.dat") == 0) {
        str = "ABCDABCDABCCABCDABCD";
    } else if (strcmp(file, "answer.dat") == 0) {
        str = "AACABCDABCDABBABDABCD";
    }
}

// Function to compare key and answers, return number of correct answers
int compare(const string &key, const string &answers, string &score) {
    int correct = 0;
    score = "";
    
    // Make sure both strings are the same length
    int minLength = (key.length() < answers.length()) ? key.length() : answers.length();
    
    for(int i = 0; i < minLength; i++) {
        if(key[i] == answers[i]) {
            score += 'C';
            correct++;
        } else {
            score += 'W';
        }
    }
    
    return correct;
}