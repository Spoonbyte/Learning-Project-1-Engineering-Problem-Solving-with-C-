/*
File:
Desc:
Author: spoonais
Date: 05/22/24 @10:51am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    short a, b, c;
    bool outcome;

    //Get user input:
    cout << "Provide value for a " << endl;
    cin >> a;
    cout << "Provide value for b " << endl;
    cin >> b;
    cout << "Provide value for c " << endl;
    cin >> c;

    //Check for errors in input data
    if (a != 1 && a != 0)
    {
        cout << "Invalid value for a" << endl; // Add on idea: if there is an invalid entry allow the user to put in a valid entry(how to do this??)
    }
    if (b != 1 && b != 0)
    {
        cout << "Invalid value for b" << endl;
    }
    if (c != 1 && c != 0)
    {
        cout << "Invalid value for c" << endl;
    }

    //Logic
    outcome = !(a || b) && c;

    //Print outcome
    if (outcome == 1)
    {
        cout << "!(a||b) && c is true" <<  endl;
    }
    else 
    {
        if (outcome == 0)
        {
            cout << "!(a||b) && c is false" <<  endl;
        }
        else 
        {
            cout << "Invalid Outcome" << endl;
        }

    }
    

}