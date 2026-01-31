/*
File: While.cpp
Desc: To test the while loop in C++
Author: spoonais
Date: 05/30/24 @8:41am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Define PI 
    const double PI = acos(-1.0);

    //Decalare and Init objects:
    double rad, deg(0);

    //Table of Values
    cout << "Degrees (deg)\tRadians (rad)" << endl;

    //Show decimal point on the output.
    cout.setf(ios::showpoint);

    //Set precision
    cout.precision(4);
    
    //Convert deg to rad
    while (deg <= 360)
    {
        if (deg <= 30) //monitor 1st 3 iterations (memory snapshot)
        {
            cout << "========" << endl;
            cout << deg << endl;
            cout << rad << endl;
            cout << "========" << endl;

        }
        rad = deg * (PI/180);
        cout << deg << "\t\t" << rad << endl;
        deg += 10;
    }
    

}