/*
File: Practice3_7.cpp
Desc: The original CH3.7 example to compare to
Author: spoonais            
Date: 05/13/24
*/

#include<iostream>
using namespace std;

int main()
{
    //Declare and Init objects
    short rank;

    //Take user input
    cout << "Please provide the rank value" << endl;
    cin >> rank;

    //Switch statements
    switch (rank)
    {
        case 1:
        case 2:
            cout << "Lower division" << endl;
            break;
        case 3:
        case 4:
            cout << "Upper division" << endl;
            break;
        case 5:
            cout << "Graduate student" << endl;
            break;
        default:
            cout << "Invalid rank" << endl;
            break;
        
    }
}