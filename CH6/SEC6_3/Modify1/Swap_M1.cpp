/*
File: Swap_M2.cpp  
Desc: This is my attempt to do the pass by reference example in the book before I read how its done.
      The goal is to take 2 variables with unique values, then the programmer defined function swaps them.
      This is the modify 2 version.
Author: spoonais
Date: 10/07/24 @2:55pm
*/

#include<iostream>
#include<cmath>
using namespace std;

/*---------------- PROGRAMMER DEFINED FUNCTIONS ---------------------*/

void swapInteger(int& a, int& b) //Make sure that the function name you use is not a pre existing function in the standard C++ library..."swap" was already one so there was an issue.
{
    int store_a;
    store_a = a;
    a = b;
    b = store_a;
}

/*-------------------------------------------------------------------*/

int main()
{
    //Decalare and Init objects:
    int x(0), y( 0);

    // //Get the user values
    // cout << "Enter two integer values" << endl;
    // cin >> x >> y;

    //Before swap:
    cout << "Before swap" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //Call the function
    swapInteger(x, x * y);

    //After swap:
    cout << "After swap" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //Pause program
    cout << "Press enter to exit...";
    cin.ignore();
    cin.get();

    //Exit
    return 0;

}