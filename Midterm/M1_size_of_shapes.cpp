/* 
 * File:   M1_size_of_shapes.cpp
 * Author: YOUR NAME HERE
 * Created: 18th july 2025 
 * Purpose:  create the shapes of the cross, backslasgh and the front slash 
 *           with the given input of the number where the number is the both 
 *           represents the rows and the characters int he line
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>x>>shape;
    
    //Draw the shape
    for (int i = 1; i <= x; ++i) {                        // for the outer loop for the row and the it's represented by the J
        for (int j = 1; j <= x; ++j) {                    // for the inner loop for the each row and it's each place holder is represented by the i
            if (shape == 'x') {
                if (j == i) {
                    cout << x - i + 1;
                } else if (j == x - i + 1) {
                    cout << i;
                } else {
                    cout << " ";
                }
            }
            else if (shape == 'b') {  // Backward slash ( \ )
                if (j == i)
                    cout << x - i + 1;
                else
                    cout << " ";
            }
            else if (shape == 'f') {  // Forward slash ( / )
                if (j == x - i + 1)
                    cout << x - i + 1;
                else
                    cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}