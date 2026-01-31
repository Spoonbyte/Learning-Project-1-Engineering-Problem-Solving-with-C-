/*
File: chapter9_1.cpp
Desc: To test memory addresses
Author: spoonais
Date: 01/20/25 @11:28am
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int a(5);
    int b(9);
    int *ptr(&a);


    //Print 
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "*ptr = " << ptr << endl;

    //B = ptr
    *ptr = b;   // become "a" = b since *ptr = is deref
    
    //Print 
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "*ptr = " << ptr << endl;

    a = 5;
    b = *ptr;   // become b = "a" since = *ptr is deref

    //Print 
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "*ptr = " << ptr << endl;

    //Exit
    return 0;
}