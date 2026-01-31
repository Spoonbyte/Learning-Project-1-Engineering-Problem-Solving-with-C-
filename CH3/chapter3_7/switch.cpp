/*
File: Switch.cpp
Desc: The original CH3.7 example using the switch statement
Author: spoonais            
Date: 05/13/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Declare and init objects:
    short code;

    //Get code value from user:
    cout << "Provide the operation code value" << endl;
    cin >> code;

    //Main logic
    switch (code)
    {
        case 10:
            cout << "Too hot - turn equipment off." << endl;
            break;
        case 11:
            cout << "Caution - recheck in 5 minutes." << endl;
            break;
        case 13:
            cout << "Turn on circulation fan." << endl;
            break;
        default:
            cout << "Normal temperature range." << endl;
            break;
            
    }
}