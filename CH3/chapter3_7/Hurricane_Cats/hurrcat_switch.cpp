/*
File: Switch.cpp
Desc: To develop a switch case to give hurricane category based on winds speed.
Author: spoonais
Date: 05/24/24 @2:01pm
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int wind;

    //Get user value:
    cout << "Please provide the estimated wind speed measured" << endl;
    cin >> wind;

    //Switch Statements
    switch (wind)
    {
        case 74 ... 94:
            cout << "Category 1" << endl;
            break;
        case 95 ... 110:
            cout << "Category 2" << endl;
            break;
        case 111 ... 129:
            cout << "Category 3" << endl;
            break;
        case 130 ... 156:
            cout << "Category 4" << endl;
            break;
        case 157 ... 250:
            cout << "Category 5" << endl;
            break;
        default:
            cout << "This is either a tropical storm or depression" << endl;
            break;
    }


}