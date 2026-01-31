/*
File: Ceil.cpp  
Desc: To see how the "ceil" function works
Author: spoonais
Date: 07/01/24 @3:47am
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    int x, t;
    double y(2.5), z(3.6);

    //
    x = ceil(y || z);
    // t = ceil(z);

    //
    cout << x << "or" << t << endl;

    //Exit 
    return 0;

}