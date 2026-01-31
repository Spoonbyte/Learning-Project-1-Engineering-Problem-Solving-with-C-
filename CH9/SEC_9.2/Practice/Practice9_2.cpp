/*
File: Practice9_2.cpp
Desc: To see how pointers to arrays work
Author: spoonais
Date: 01/21/25 @11:00am
*/

#include<iostream>
using namespace std;

int main()
{
    //Decalre and init
    int g[] = {2,4,5,8,10,32,78};
    int *ptr1(g), *ptr2(&g[3]);

    //Typical way to add 1D array                       //My answers
    cout << "*g = "<< *g << endl;                       // 2
    cout << "*(g+1) = "<< *(g+1) << endl;               // 4
    cout << "*g+1 = " << *g+1 << endl;                  // 3    
    cout << "*(g+5) = " << *(g+5) << endl;              // 32
    cout << "*ptr1 = "  << *ptr1  << endl;              // 2
    cout << "*(ptr1 + 1) = "  << *(ptr1 + 1)  << endl;  // 4
    cout << "*(ptr2 + 2) = "  << *(ptr2 + 2)  << endl;  // 32

    //Exit
    return 0;
}