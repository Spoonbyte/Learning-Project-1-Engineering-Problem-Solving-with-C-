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
    //Decalare and Init objects:
    double Accel(9.8), Vel, t(0);
    const int Vel_int(0);

    //Table of Values
    cout << "Time (s)\tVelocity (m/s)" << endl;

    //Show decimal point
    cout.setf(ios::showpoint);

    //Set precision
    cout.precision(3);
    
    //Calculate the Velocity due to gravity for 10 seconds of freefall
    while (t <= 10)
    {
        Vel = (Accel * t) + Vel_int;
        cout << t << "\t\t" << Vel << endl;
        t++;
    }
    

}