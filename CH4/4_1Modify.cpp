/*
File: 4_1Modify.cpp
Desc:
Author: spoonais
Date: 06/3/24 @4:30pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects
    double vel, t_i, t_f, A, V_0;

    //Ask user for accel and initial vel values
    cout << "Please provide the constant of acceleration" << endl;
    cin >> A;
    cout << "Please provide the initial velocity" << endl;
    cin >> V_0;

    //Ask the user for the time span to calculate
    cout << "Please provide the starting time" << endl;
    cin >> t_i;
    cout << "Please provide the final time" << endl;
    cin >> t_f;

    //Print heading
    cout << "Time (s)\tVelocity (m/s)" << endl;

    //Set decimal and precision
    cout.setf(ios::showpoint);
    cout.precision(5);

    //Create logic using while loop 
    while (t_i <= t_f) //This can be very useful where the size of the while loop can be dependent on the data size (which can change)
    {
        vel = A*t_i + V_0;
        cout << t_i << "\t\t" << vel << endl;
        t_i++;

    }

    cout << "---------------------------------------------------------------" << endl;

    // //Reinit variables
    // t = t - t;

    // //Create logic using a do-while loop
    // do 
    // {
    //     vel = A*t + V_0;
    //     cout << t << "\t\t" << vel << endl;
    //     t++;
    // } 
    // while (t <= 10);



}