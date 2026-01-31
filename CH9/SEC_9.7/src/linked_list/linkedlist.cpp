/*
File: stack_main_linkedlist.cpp
Desc: To try and create a stack structure using the linked list
Author: spoonais
Date: 01/31/25 @ 11:41pm
Finished @ 

*/

/*--------- 
Self Feedback:


----------*/

#include<iostream>
#include<iomanip>
using namespace std;

/*--------- PROGRAMMER DEFINED FUNCTIONS ----------*/

//Linked list
/*
how does a linked list work?
head pointer --> [10][ptr] --> [20][ptr] --> [30][null]
                elem 1          elem 2         elem 3 (top)

How do I create a linked list in the first place?

*/

//Create a linked list:









/*-------------------------------------------------*/

int main()
{
    //Declare and init objects
    int *h_ptr, *ptr2, *ptr3;
    int a(1897), b(20), c(30);
    h_ptr = &a;
    ptr2 = &b;
    ptr3 = &c;

    int *ptr4;
    int d(34);
    ptr4 = &d;

    //Print the addresss to ensure they are not continous memory
    cout << "&a = " << h_ptr << " value = " << *h_ptr << endl;
    cout << "&b = " << ptr2 <<  " value = " << *ptr2 << endl;
    cout << "&c = " << ptr3 <<  " value = " << *ptr3 << endl;
    cout << "&c = " << ptr4 <<  " value = " << *ptr4 << endl;
    
    /*
    Note: Im not sure why when I assign the variables above all of them are continuous in memeory?
    I thought unless it was an array it would be continuous...not if I assigned individual variables

    Maybe the compiler is doing some kind of memory management? Or the operating sys is?
    */

    //------------------------------------------------------------------------------------------//

    // stack s;

    // s.push(10);
    // s.push(20);
    // s.push(30);

    // cout << s.top() << endl; //Returns the top of the stack...should show 30.
    // s.pop();
    // cout << s.top() << endl; //Returns the top of stack after the pop...should show 20.

    //EXIT 
    return 0;
}