/*
File: Swap_P.cpp  
Desc: This is my attempt to do the pass by reference example in the book before I read how its done.
      The goal is to take 2 variables with unique values, then the programmer defined function swaps them.
      This is the practice questions.
Author: spoonais
Date: 10/08/24 @9:55am
*/

#include<iostream>
#include<cmath>
using namespace std;

/*---------------- PROGRAMMER DEFINED FUNCTIONS ---------------------*/

void swapInteger(double& a, double& b) //Make sure that the function name you use is not a pre existing function in the standard C++ library..."swap" was already one so there was an issue.
{
    double store_a;
    store_a = a;
    a = b;
    b = store_a;
}

/*-------------------------------------------------------------------*/

int main()
{
    // //Decalare and Init objects:
    // int x(1), y(3);

    //#4
    double x(1.5), y(3.2);

    //Before swap:
    cout << "Before swap" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //Call the function
    //Practice #1
    // swapInteger(x,y);

    //Practice #2
    //RESULT: "error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'"
    // swapInteger(10,5);

    //Practice #3
    //RESULT: error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // swapInteger(x, y+5);

    //Practice #4
    //RESULT: Because the reference types were int& and not double&, it triggered a compiler error. 
    //All that needs to be done is to change int& a to double& a and same for b. ALSO, make sure to change the int store_a to double store_a.
    swapInteger(x,y);

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