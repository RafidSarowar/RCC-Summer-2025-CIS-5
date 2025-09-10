/* 
 * File:   Menu5.cpp
 * Author: Rafid Sarowar
 * Created on: July 30, 2025
 * Purpose: Midterm Menu Program to run 9 individual problems
 */

// System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;

// Function Prototypes
int fctrl(int);                                      // Problem 1 - Factorial
bool isPrime(int);                                   // Problem 2 - Prime number
int collatzLen(int);                                 // Problem 3 - Collatz length
int collatzSeq(int);                                 // Problem 4 - Collatz with sequence
void timeWait();                                     // Problem 5 - Time after waiting
void milToStd();                                     // Problem 6 - Military to Standard time
float psntVal(float, float, int);                    // Problem 7 - Present Value
void avgScores();                                    // Problem 8 - Average test scores
int fndLwst(int,int,int,int,int);                    // Helper for Problem 8
void getScre(int&,int&,int&,int&,int&);              // Helper for Problem 8

// Execution Begins Here
int main(int argc, char** argv){
    int choice;
    do{
        cout << "\n----------------------------\n";
        cout << "      Midterm Menu Program\n";
        cout << "----------------------------\n";
        cout << "1. Factorial Calculation\n";
        cout << "2. Prime Number Test\n";
        cout << "3. Collatz Length\n";
        cout << "4. Collatz Sequence\n";
        cout << "5. Time After Waiting Period\n";
        cout << "6. Military to Standard Time Conversion\n";
        cout << "7. Present Value Computation\n";
        cout << "8. Average of Test Scores (Drop Lowest)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                int n;
                cout << "This program calculates factorial.\n";
                cout << "Input a number: ";
                cin >> n;
                cout << n << "! = " << fctrl(n) << endl;
                break;
            }
            case 2:{
                int n;
                cout << "Input a number to test if Prime: ";
                cin >> n;
                cout << n << (isPrime(n) ? " is prime.\n" : " is not prime.\n");
                break;
            }
            case 3:{
                int n;
                cout << "Collatz Conjecture Test\n";
                cout << "Input a sequence start: ";
                cin >> n;
                cout << "Sequence start of " << n 
                     << " cycles to 1 in " << collatzLen(n) << " steps\n";
                break;
            }
            case 4:{
                int n;
                cout << "Collatz Conjecture Test\n";
                cout << "Input a sequence start: ";
                cin >> n;
                int steps = collatzSeq(n);
                cout << "Sequence start of " << n 
                     << " cycles to 1 in " << steps << " steps\n";
                break;
            }
            case 5:{
                timeWait();
                break;
            }
            case 6:{
                milToStd();
                break;
            }
            case 7:{
                float fVal, rate;
                int yrs;
                cout << "This is a Present Value Computation\n";
                cout << "Input the Future Value in Dollars:\n";
                cin >> fVal;
                cout << "Input the Number of Years:\n";
                cin >> yrs;
                cout << "Input the Interest Rate %/yr:\n";
                cin >> rate;
                cout << fixed << setprecision(2);
                cout << "The Present Value = $" << psntVal(fVal,rate,yrs) << endl;
                break;
            }
            case 8:{
                avgScores();
                break;
            }
            case 9:{
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            default: cout << "Invalid choice. Try again.\n";
        }
    }while(choice!=9);

    return 0;
}

// ---------- Problem 1 ----------
int fctrl(int n){
    int fact=1;
    for(int i=2;i<=n;i++) fact*=i;
    return fact;
}

// ---------- Problem 2 ----------
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

// ---------- Problem 3 ----------
int collatzLen(int n){
    int count=1;
    long long val=n;
    while(val!=1){
        if(val%2==0) val/=2;
        else val=val*3+1;
        count++;
    }
    return count;
}

// ---------- Problem 4 ----------
int collatzSeq(int n){
    int count=1;
    long long val=n;
    cout << val;
    while(val!=1){
        if(val%2==0) val/=2;
        else val=val*3+1;
        cout << ", " << val;
        count++;
    }
    cout << endl;
    return count;
}

// ---------- Problem 5 ----------
void timeWait(){
    int hour,min,waitMin;
    char ampm,again;
    cout << "Enter hour:\n";
    cin >> hour;
    cout << "Enter minutes:\n";
    cin >> min;
    cout << "Enter A for AM, P for PM:\n";
    cin >> ampm;
    cout << "Enter waiting time in minutes:\n";
    cin >> waitMin;

    int h24 = hour % 12;
    if(toupper(ampm)=='P') h24+=12;
    int totalMin = h24*60+min+waitMin;
    totalMin %= 24*60;
    int newH24=totalMin/60;
    int newM=totalMin%60;
    char newAmpm=(newH24<12?'A':'P');
    int newH=newH24%12;
    if(newH==0)newH=12;

    cout << "Current time = " << setw(2) << setfill('0') << hour << ":"
         << setw(2) << min << " " << (toupper(ampm)=='A'?"AM":"PM") << endl;
    cout << "Time after waiting period = " << setw(2) << newH << ":"
         << setw(2) << newM << " " << (newAmpm=='A'?"AM":"PM") << endl;
}

// ---------- Problem 6 ----------
void inputTime(int &milHour,int &milMin){
    char colon;
    cin>>milHour>>colon>>milMin;
}
bool convertTime(int milHour,int milMin,int &stdHour,char &ampm){
    if(milHour<0||milHour>23||milMin<0||milMin>59)return false;
    if(milHour<12){
        ampm='A'; stdHour=(milHour==0)?12:milHour;
    }else{
        ampm='P'; stdHour=(milHour>12)?milHour-12:milHour;
    }
    return true;
}
void outputTime(int milHour,int milMin,int stdHour,char ampm,bool valid){
    if(!valid){
        cout<<setw(2)<<setfill('0')<<milHour<<":"<<setw(2)<<milMin<<" is not a valid time\n";
    }else{
        cout<<setw(2)<<setfill('0')<<milHour<<":"<<setw(2)<<milMin
            <<" = "<<stdHour<<":"<<setw(2)<<milMin<<" "
            <<(ampm=='A'?"AM":"PM")<<endl;
    }
}
void milToStd(){
    int milHour,milMin,stdHour;
    char ampm;
    cout<<"Input Military Time hh:mm\n";
    inputTime(milHour,milMin);
    bool valid=convertTime(milHour,milMin,stdHour,ampm);
    outputTime(milHour,milMin,stdHour,ampm,valid);
}

// ---------- Problem 7 ----------
float psntVal(float futureValue,float interestRate,int years){
    float r=interestRate/100.0f;
    return futureValue/pow(1.0f+r,years);
}

// ---------- Problem 8 ----------
void getScre(int &s1,int &s2,int &s3,int &s4,int &s5){
    cin>>s1>>s2>>s3>>s4>>s5;
    while(s1<1||s1>100){cout<<"Invalid score; re-enter (1-100): ";cin>>s1;}
    while(s2<1||s2>100){cout<<"Invalid score; re-enter (1-100): ";cin>>s2;}
    while(s3<1||s3>100){cout<<"Invalid score; re-enter (1-100): ";cin>>s3;}
    while(s4<1||s4>100){cout<<"Invalid score; re-enter (1-100): ";cin>>s4;}
    while(s5<1||s5>100){cout<<"Invalid score; re-enter (1-100): ";cin>>s5;}
}
int fndLwst(int s1,int s2,int s3,int s4,int s5){
    int low=s1;
    if(s2<low)low=s2;
    if(s3<low)low=s3;
    if(s4<low)low=s4;
    if(s5<low)low=s5;
    return low;
}
float calcAvg(int s1,int s2,int s3,int s4,int s5){
    int lowest=fndLwst(s1,s2,s3,s4,s5);
    int total=s1+s2+s3+s4+s5-lowest;
    return static_cast<float>(total)/4.0f;
}
void avgScores(){
    int s1,s2,s3,s4,s5;
    cout<<"Find the Average of Test Scores\n";
    cout<<"by removing the lowest value.\n";
    cout<<"Input the 5 test scores.\n";
    getScre(s1,s2,s3,s4,s5);
    cout<<fixed<<setprecision(1);
    cout<<"The average test score = "<<calcAvg(s1,s2,s3,s4,s5)<<endl;
}
