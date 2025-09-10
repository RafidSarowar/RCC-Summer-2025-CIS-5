/* 
 * File:   menu6.cpp
 * Author: Rafid Sarowar
 * Created on: July 31, 2025
 * Purpose:  A menu program to run 8 different problems
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Global Constants
const int COLS = 6;
const int SIZE = 100;
const int SIZE2 = 50;
const int SIZE3 = 20;

// Function Prototypes for each problem
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();

//Helper Functions reused
void fillTbl(int[][COLS], int);
void prntTbl(const int[][COLS], int);
void initRev(int[], int);
void printRev(int[], int, int);
void revrse(int[], int);
void initStd(float[], int);
float avgX(float[], int);
float stdX(float[], int);
void printStd(float[], int, int);
void readAry(int[], int);
void prntAry(int[], int, int);
void selSrt(int[], int);
bool binSrch(int[], int, int, int&);
void bublSrt(int[], int);
bool linSrch(int[], int, int, int&);

// Execution Begins Here
int main() {
    int choice;
    do {
        cout << "\n*** MENU ***\n";
        cout << "1. Dice Table Sum\n";
        cout << "2. Product Table\n";
        cout << "3. Reverse Array Contents\n";
        cout << "4. Standard Deviation\n";
        cout << "5. Scantron Grading Program\n";
        cout << "6. Linear Search\n";
        cout << "7. Binary Search\n";
        cout << "8. Binary Search with Bubble Sort\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";
        switch(choice){
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
            case 7: problem7(); break;
            case 8: problem8(); break;
            case 9: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while(choice != 9);
    return 0;
}

// ----------------------------
// PROBLEM 1: Dice Table Sum
void problem1(){
    cout << "Think of this as a Sum of Dice Table\n";
    int tablSum[6][COLS];
    for (int r=0;r<6;r++){
        for(int c=0;c<COLS;c++){
            tablSum[r][c]=(r+1)+(c+1);
        }
    }
    prntTbl(tablSum,6);
}

// PROBLEM 2: Product Table
void problem2(){
    cout << "Think of this as a Product Table\n";
    int tablSum[6][COLS];
    fillTbl(tablSum,6);
    prntTbl(tablSum,6);
}

// PROBLEM 3: Reverse Array Contents
void problem3(){
    int test[SIZE2];
    initRev(test,SIZE2);
    revrse(test,SIZE2);
    printRev(test,SIZE2,10);
}

// PROBLEM 4: Standard Deviation
void problem4(){
    float test[SIZE3];
    initStd(test,SIZE3);
    cout<<fixed<<setprecision(7);
    cout<<"The average = "<<avgX(test,SIZE3)<<endl;
    cout<<"The standard deviation = "<<stdX(test,SIZE3)<<endl;
}

// PROBLEM 5: Scantron Grading Program
void problem5(){
    string key = "ABCDABCDABCCABCDABCD";
    string ans = "AACABCDABCDABBABDABCD";
    string score="";
    int correct=0;
    for(size_t i=0;i<key.size();i++){
        if(key[i]==ans[i]){score+='C';correct++;}
        else score+='W';
    }
    for(char ch:score) cout<<ch<<' ';
    cout<<"\nPercentage Correct = "<<(correct*100.0/score.size())<<"%\n";
}

// PROBLEM 6: Linear Search
void problem6(){
    int arr[SIZE];
    readAry(arr,SIZE);
    int val=50,indx;
    if(linSrch(arr,SIZE,val,indx)) cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found\n";
}

// PROBLEM 7: Binary Search with Selection Sort
void problem7(){
    int arr[SIZE];readAry(arr,SIZE);
    selSrt(arr,SIZE);
    prntAry(arr,SIZE,10);
    int val;cout<<"Input the value to find in the array\n";cin>>val;
    int indx;
    if(binSrch(arr,SIZE,val,indx)) cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found\n";
}

// PROBLEM 8: Binary Search with Bubble Sort
void problem8(){
    int arr[SIZE];readAry(arr,SIZE);
    bublSrt(arr,SIZE);
    prntAry(arr,SIZE,10);
    int val;cout<<"Input the value to find in the array\n";cin>>val;
    int indx;
    if(binSrch(arr,SIZE,val,indx)) cout<<val<<" was found at indx = "<<indx<<endl;
    else cout<<val<<" was not found\n";
}

// ----------------------------
// Helper functions
void fillTbl(int table[][COLS], int rows){for(int r=0;r<rows;r++)for(int c=0;c<COLS;c++)table[r][c]=(r+1)*(c+1);} 
void prntTbl(const int table[][COLS], int rows){cout<<"    |";for(int c=1;c<=COLS;c++)cout<<setw(4)<<c;cout<<"\n----------------------------------\n";for(int r=1;r<=rows;r++){cout<<setw(2)<<r<<" |";for(int c=0;c<COLS;c++)cout<<setw(4)<<table[r-1][c];cout<<"\n";}}
void initRev(int a[], int n){for(int i=0;i<n;i++)cin>>a[i];}
void printRev(int a[], int n,int perLine){for(int i=0;i<n;i++){cout<<setw(2)<<a[i];if((i+1)%perLine==0)cout<<" \n";else cout<<' ';}if(n%perLine)cout<<'\n';}
void revrse(int a[], int n){for(int i=0;i<n/2;i++){int tmp=a[i];a[i]=a[n-1-i];a[n-1-i]=tmp;}}
void initStd(float a[], int n){for(int i=0;i<n;i++)cin>>a[i];}
float avgX(float a[], int n){float s=0;for(int i=0;i<n;i++)s+=a[i];return s/n;}
float stdX(float a[], int n){float m=avgX(a,n),s=0;for(int i=0;i<n;i++)s+=pow(a[i]-m,2);return sqrt(s/(n-1));}
void readAry(int a[], int n){for(int i=0;i<n;i++)cin>>a[i];}
void prntAry(int a[], int n,int perLine){for(int i=0;i<n;i++){cout<<a[i]<<" ";if((i+1)%perLine==0)cout<<endl;}cout<<endl;}
void selSrt(int a[], int n){for(int i=0;i<n-1;i++){int min=i;for(int j=i+1;j<n;j++)if(a[j]<a[min])min=j;int t=a[i];a[i]=a[min];a[min]=t;}}
bool binSrch(int a[], int n,int val,int &indx){int f=0,l=n-1;while(f<=l){int m=(f+l)/2;if(a[m]==val){indx=m;return true;}else if(a[m]>val)l=m-1;else f=m+1;}return false;}
void bublSrt(int a[], int n){bool sw;do{sw=false;for(int i=0;i<n-1;i++){if(a[i]>a[i+1]){int t=a[i];a[i]=a[i+1];a[i+1]=t;sw=true;}}}while(sw);}
bool linSrch(int a[], int n,int val,int &indx){for(int i=0;i<n;i++){if(a[i]==val){indx=i;return true;}}return false;}