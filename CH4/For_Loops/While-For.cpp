/*
File: While-For.cpp
Desc: To convert the while loop for computing velocity made yesterday into a for loop
Author: spoonais
Date: 06/04/24 @4:41am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double vel, time;
    const double accel(9.8), V0(0);

    //Create the header 
    cout << "Time (s)" << "\t" << "Velocity (m/s)" << endl;

    //Set decimal and precision
    cout.setf(ios::showpoint);
    cout.precision(4);

    //Create the loop to calculate the velocity 10 seconds after freefall
    for (time; time <= 10; time++ )
    {
        vel = (accel * time) +V0;
        cout << time << "\t\t" << vel << endl;

    }

}