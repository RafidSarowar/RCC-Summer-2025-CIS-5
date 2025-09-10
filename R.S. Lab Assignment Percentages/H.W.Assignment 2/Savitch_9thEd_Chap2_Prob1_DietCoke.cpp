#include <iostream>
using namespace std;

const float mk = 5.0f;                         // Amt. of sweetner that killas the mouse, which is 7g
const float mm = 35.0f;                        // mass fo the mouse
const float CNV = 453.592f;                    // conversion of the weight to the mass
const float ms = 350.0f;                       // mass of a soda can 
const float cc = 0.001f;                       // Sweetner concentration in a can of soda

int main() {
    float wd, md, mkd, mpc;                         // weight if the dieater, Mass of Dieater, Mass to kill the dieter, mass of sweetner in Each can, number of soda can he can drink before dying
    int nCans;                                      // number of cans not to excide and it should be interger form.
    
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;                     // input command

    cin >> wd;                                // weight of the dieter input

    md = wd*CNV;                              // converting the weight to the mass 

    mkd = (md/mm)*mk;                         // basicall finding the 1/7th mass of the human, which the amout that could kill him. 
    
    mpc = ms*cc;                              // mass of sweetner per can of diat coke, which is basically 10%

    nCans = mkd/mpc;                          // number of cans that will kill after reaches the 1/7 th mass of the human equal the amount sweetner mass that comes form the diet soda cans.

    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << nCans << " cans";                  // output of the number of cans 

    return 0;
}