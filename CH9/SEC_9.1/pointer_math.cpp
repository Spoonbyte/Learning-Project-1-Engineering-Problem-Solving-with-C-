/*
File: pointer_math.cpp
Desc: To test memory addresses
Author: spoonais
Date: 01/20/25 @4:40pm
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int a(1);
    int *ptr_1, *ptr_2;

    //Assign 
    ptr_1 = &a;

    //Different pointers to same mem address
    ptr_2 = ptr_1;

    //Print 
    cout << "*ptr_1 = " << *ptr_1 << endl;
    cout << "*ptr_2 = " << *ptr_2 << endl;

    //Exit
    return 0;
}