/*
File: chapter9_3.cpp
Desc: To test memory addresses
Author: spoonais
Date: 01/20/25 @11:28am
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int a(1);
    int b(2);
    int c(5);
    int *ptr;

    ptr = &c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    //Assign
    c = b;
    a = *ptr;

    //Print 
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    //Exit
    return 0;
}