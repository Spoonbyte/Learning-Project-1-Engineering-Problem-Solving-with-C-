/*
File: WhileVsDoW.cpp
Desc: To compare the output of a while loop vs a do-while loop.
Author: spoonais
Date: 05/30/24 @3:32am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double t(11), x(0);

    //Show decimal point
    cout.setf(ios::showpoint);

    //Set precision
    cout.precision(3);
    
    //Calculate the Velocity due to gravity for 10 seconds of freefall
    while (t <= 10)
    {
        x = x + 1;
        cout << x << endl;
        t++;
    }

    cout << "----------------------------------------" << endl;

    //reset t and x and now run do-while 
    x = 0;
    t = 11;

    do 
    {
        x = x + 1;
        cout << x << endl;
        t++;
    } 
    while (t <= 10);
    

}