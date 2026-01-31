/*
File: CH3PRB6.cpp
Desc: To solve the problem
Author: spoonais
Date: 05/21/24
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Declare and init objects
    short x, code;

    //User value for x
    cout << "Provide the value for x: " << endl;
    cin >> x;

    //Calculate the switch code
    code =  sqrt(x);

    //Create logic
    switch (code)
    {
        case 1:
            cout << "Too low.  \n";
            break;
        case 2:
            cout << "Correct range. \n";
            break;
        case 3:
            cout << "Too high.\n";
            break;
        default:
            cout << "Value not accetable" << endl;
            break;

    }
}