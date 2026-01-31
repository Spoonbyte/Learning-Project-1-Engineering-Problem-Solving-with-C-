/*
File: chapter3_1_P!8.cpp
Desc: To test some of the CH3 Practice 1 problems
Author:spoonais
Date: 05/03/24
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
    //Declare and init objects
    float a = 5.5, b = 1.5;
    short k = 3;
    bool A(false);

    //The logic to solve
    A = fabs(k) >= 3 || k < b - a;

    //Print A
    cout << A;

}