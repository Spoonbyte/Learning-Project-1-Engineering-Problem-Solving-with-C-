/*
File: WeatherBalloon.cpp
Desc: To create a program per the problem statement
Author: spoonais
Date: 06/17/24 @1:25pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double alt(0), vel(0), t(0), str_alt(0), inc(0), str_inc(0);
    short start_t(0), end_t(0), counter(0), store_t(0);

    //User provided start time
    cout << "Please provide the desired start time and end time to create the table" << endl;
    cin >> start_t;
    cin >> end_t;
    cout << "Provide the increment of time required (Enter 1 if increments not needed)" << endl;
    cin >> inc;

    //Calculate the increment time:
    str_inc = (end_t - start_t) / inc;
    cout << str_inc << endl;

    //Create the table
    cout << "------------------------------" << endl;
    cout << "Time(HR:MIN)" << "\t" << "Altitude (m)" << "\t" << "Velocity (m/s)" << endl;
    cout << "------------------------------" << endl;

    //Create the logic
    for (t = start_t; t <= end_t+0.01; t+=str_inc) //figure out how to create table for 10 minute increments
    {
        //Compute altitude and velocity 
        alt = -0.12*pow(t,4) + 12*pow(t,3) - 380*pow(t,2) + 4100*t + 220;
        vel = (-0.48*pow(t,3) + 36*pow(t,2) - 760*t + 4100)/3600;


        cout << t << "\t\t" << alt << "\t\t" << vel << endl;
        

        //Only runs on the FIRST iteration
        if (t == 0)
        {
            str_alt = alt;
        }
          
        //Runs for the remaining iterations
        if (t > 0)
        {
            //Checks to see if either the newly calcualted alt is larger and if it is store the new alt and store the time at which that occured
            if (alt > str_alt) 
            {
                str_alt = alt;
                store_t = t;
            }
        }
    }

    cout << "The maximum altitude recorded was " << str_alt << " meters, occuring at hour " << store_t  << endl;


}