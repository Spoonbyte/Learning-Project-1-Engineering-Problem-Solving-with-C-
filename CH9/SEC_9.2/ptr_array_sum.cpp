/*
File: ptr_array_sum.cpp
Desc: To test memory addresses
Author: spoonais
Date: 01/21/25 @10:33am
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalre and init
    int x[6] = {1,2,3,4,5,6};
    int sum(0);

    //Typical way to add 1D array 
    for(int i=0; i < 6; ++i)
    {
        sum += sum + x[i];
    }

    cout << "Regular sum = " << sum << endl;

    //Pointer way
    sum = 0;
    int *ptr(&x[0]);

    for(int i=0; i < 6; ++i)
    {
        sum += sum + *(ptr + i);
    }

    cout << "Pointer sum = " << sum << endl;

    
    //OR just using the name of the array 
    cout << "Address of x = " << x << endl; //Printing out the name of the array yields the address of the first element
    sum = 0;

    for(int i=0; i < 6; ++i)
    {
        sum += sum + *(x + i);
    }

    cout << "Pointer sum = " << sum << endl;

    //Exit
    return 0;
}