/*
File: stack.h
Desc: Describes the stack class
Author: spoonais
Date: 1/30/25 @ 2:30pm
Finished:
------------------------------------------------------------------
We use the following compiler directives to avoid including
the stack.h file multiple times

It is a good idea to always use these directives in the custom header file.

*/

#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;


class stack
{
    //Are these private by default?
    int *a;
    int sizeofstack();

    public:
    //Constructor
    stack();

    //Methods
    void push(int);
    int pop();
    int top();

    int isempty();

};

#endif
