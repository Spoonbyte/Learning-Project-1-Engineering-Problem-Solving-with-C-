/*
File: chapter7_1.cpp
Desc: To try to assign values to a array 
Author: spoonais
Date: 12/03/24 @8:10am
*/

/*-------- SELF FEEDBACK -----------*/
/*

Was able to go outside the bounds of the array because I used k<=21 instead of k<21...
using the equals sign allowed the loop to go ahead and print a value outside of the 21 elements
since i starts at zero, then 20 would be the stopping point for 21 elements....

*/
/*-----------------------------------*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //Decalare and Init objects:
    double g[21] = {0};
    double value(0);
    int k(0);

    //Print BEFORE loop 
    for (k; k<21; k++)   
    {
        cout << "g" << "[" << k << "]" << " = " << g[k] << endl;
        
    }

    cout << "----------" << endl;

    //Use for loop to assign values
    for (int i=0; i<21; ++i)
    {
        g[i] = value;

        value = value + 0.5;
    }

    //Reinit K 
    k = 0;

    //Print AFTER loop 
    for (k; k<21; k++)
    {
        cout << g[k] << endl;
    }

    //Exit
    return 0;

}