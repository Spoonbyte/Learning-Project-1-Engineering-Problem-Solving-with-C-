/*
File: Prac_simple_pointers.cpp
Desc: To complete the practive problems on pg 444
Author: spoonais
Date: 01/20/25 @4:46pm
*/

#include<iostream>
using namespace std;

int main()
{
    // //#1
    // //Decalare and Init objects:
    // double x(15.6), y(10.2), *ptr_1(&y), *ptr_2(&x);
    // //Assign 
    // *ptr_1 = *ptr_2 + x;
    // //Print 
    // cout << "x = " << x << endl;
    // cout << "y = " << y << endl;
    // cout << "*ptr_1 = " << *ptr_1 << endl;
    // cout << "*ptr_2 = " << *ptr_2 << endl;

    // //#2
    // //Decalare and Init objects:
    // double w(10), x(2), *ptr_2(&x);
    // //Assign 
    // *ptr_2 -= w;
    // //Print 
    // cout << "x = " << x << endl;
    // cout << "w = " << w << endl;
    // cout << "*ptr_2 = " << *ptr_2 << endl;

    // //#3
    // //Decalare and Init objects:
    // int x[5] = {2,4,7,8,3};
    // int *ptr_1 = NULL;
    // int *ptr_2 = NULL;
    // int *ptr_3 = NULL;
    // //Assign 
    // ptr_3 = &x[0];
    // ptr_1 = ptr_2 = ptr_3 + 2;
    // //Print the dereferenced pointers (actual value)
    // cout << "*ptr_1 = " << *ptr_1 << endl;
    // cout << "*ptr_2 = " << *ptr_2 << endl;
    // cout << "*ptr_3 = " << *ptr_3 << endl;

    //#4
    //Declare and init objects
    int w[4] = {1,2,3,4}, *first_ptr(NULL), *last_ptr(NULL);
    //Assign
    first_ptr = w;                                         //Assigned the address of w[0]
    last_ptr = first_ptr + 3;
    //Print the dereferenced pointers (actual value)
    cout << "*first_ptr = " << *first_ptr << endl;
    cout << "*last_ptr = " << *last_ptr << endl;

    //Exit
    return 0;
}