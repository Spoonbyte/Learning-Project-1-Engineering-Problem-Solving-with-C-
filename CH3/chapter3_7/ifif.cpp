/*
File: ifif.cpp
Desc: To try the 1st example in CH 3.7 with just if statements instead of if-else to see how it affects the code.
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

    //Create code logic
    if (code == 10) 
    {
        cout << "Too hot - turn equipment off." << endl;
    }

    if (code == 11)
    {
        cout << "Caution - recheck in 5 minutes." << endl;
    }

    if (code == 13)
    {
        cout << "Turn on circulating fan" << endl;
    } 
    
    else {
        cout << "Normal state of operation" << endl;
    }


    
}