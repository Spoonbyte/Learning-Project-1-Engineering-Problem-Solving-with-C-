/*
File: WeatherB_3.cpp
Desc: To create a program per the problem Modify! #3
Author: spoonais
Date: 06/20/24 @3:20pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double alt(0), vel(0), t(0), str_alt(0);
    short end_t(0), start_t(0), counter(0), store_t(0);  //Learned that I need to INITIALIZE variables because the "end_t" was init with 32758 so it was triggering the "if (end_t > 48) condition"
    
    //User provided start and end time with Error Checking:
    //Needed to find a way to KEEP prompting the user about the error (Answer: USE A LOOP!)
    //This do-while will KEEP prompting the user to correct the error as long as (start_t > end_t) is true
    do 
    {
        //Display the error message
        if (start_t > end_t)
        {
            cout << "ERROR: START time >>> END time! Please re-enter time." << endl;
        }

        if (end_t > 48)
        {
            cout << "ERROR: END time >>> 48 HRS! Please re-enter time range with and END time that is less than 48 hrs." << endl;
        }

        cout << "Please provide the desired START time" << endl;
        cin >> start_t;
        cout << "Please provide the desired END time" << endl;
        cin >> end_t;

    } while (start_t > end_t || end_t > 48);

    //Create the table
    cout << "------------------------------" << endl;
    cout << "Altitude (m)" << "\t" << "Velocity (m/s)" << endl;
    cout << "------------------------------" << endl;

    //Create the logic
    for (t = start_t; t <= end_t; ++t) //figure out how to create table for 10 minute increments
    {
        //Compute altitude and velocity 
        alt = -0.12*pow(t,4) + 12*pow(t,3) - 380*pow(t,2) + 4100*t + 220;
        vel = -0.48*pow(t,3) + 36*pow(t,2) - 760*t + 4100;

        cout << alt << "\t\t" << vel << endl;

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