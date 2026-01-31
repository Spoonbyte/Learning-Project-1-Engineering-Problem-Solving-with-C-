/*
File: SEC5_5_sandbox.cpp
Desc: Messing with stream states
Author: spoonais
Date: 08/06/24 @11:40am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int v1(0), v2(0);

    //Get user input
    cin >> v1 >> v2;

    //Print to user
    cout << v1 << " " << v2 << endl;

    //
    cout << "State of the standard input : " << cin.fail() << endl;
    cout << cin.failbit << endl;
    

}